/*------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2015 The Khronos Group Inc.
 * Copyright (c) 2015 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice(s) and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * The Materials are Confidential Information as defined by the
 * Khronos Membership Agreement until designated non-confidential by Khronos,
 * at which point this condition clause shall be removed.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 *
 *//*!
 * \file
 * \brief Image Object Util
 *//*--------------------------------------------------------------------*/

#include "vktDynamicStateImageObjectUtil.hpp"

#include "tcuSurface.hpp"
#include "tcuVectorUtil.hpp"

#include "vkRefUtil.hpp"
#include "vkQueryUtil.hpp"
#include "vkImageUtil.hpp"
#include "vktDynamicStateCreateInfoUtil.hpp"
#include "vktDynamicStateBufferObjectUtil.hpp"

#include "tcuTextureUtil.hpp"

namespace vkt
{
namespace DynamicState
{

void MemoryOp::pack (int				pixelSize,
					 int				width,
					 int				height,
					 int				depth,
					 vk::VkDeviceSize	rowPitchOrZero,
					 vk::VkDeviceSize	depthPitchOrZero,
					 const void *		srcBuffer,
					 void *				destBuffer)
{
	vk::VkDeviceSize rowPitch	= rowPitchOrZero;
	vk::VkDeviceSize depthPitch	= depthPitchOrZero;

	if (rowPitch == 0)
		rowPitch = width * pixelSize;

	if (depthPitch == 0)
		depthPitch = rowPitch * height;

	const vk::VkDeviceSize size = depthPitch * depth;

	const char *srcRow = reinterpret_cast<const char *>(srcBuffer);
	const char *srcStart;
	srcStart = srcRow;
	char *dstRow = reinterpret_cast<char *>(destBuffer);
	char *dstStart;
	dstStart = dstRow;

	if (rowPitch == static_cast<vk::VkDeviceSize>(width * pixelSize) &&
		depthPitch == static_cast<vk::VkDeviceSize>(rowPitch * height))
	{
		// fast path
		deMemcpy(dstRow, srcRow, static_cast<size_t>(size));
	}
	else
	{
		// slower, per row path
		for (int d = 0; d < depth; d++)
		{
			vk::VkDeviceSize offsetDepthDst = d * depthPitch;
			vk::VkDeviceSize offsetDepthSrc = d * (pixelSize * width * height);
			srcRow = srcStart + offsetDepthSrc;
			dstRow = dstStart + offsetDepthDst;
			for (int r = 0; r < height; ++r)
			{
				deMemcpy(dstRow, srcRow, static_cast<size_t>(rowPitch));
				srcRow += pixelSize * width;
				dstRow += rowPitch;
			}
		}
	}
}

void MemoryOp::unpack (int					pixelSize,
					   int					width,
					   int					height,
					   int					depth,
					   vk::VkDeviceSize		rowPitchOrZero,
					   vk::VkDeviceSize		depthPitchOrZero,
					   const void *			srcBuffer,
					   void *				destBuffer)
{
	vk::VkDeviceSize rowPitch	= rowPitchOrZero;
	vk::VkDeviceSize depthPitch = depthPitchOrZero;

	if (rowPitch == 0)
		rowPitch = width * pixelSize;

	if (depthPitch == 0)
		depthPitch = rowPitch * height;

	const vk::VkDeviceSize size = depthPitch * depth;

	const char *srcRow = reinterpret_cast<const char *>(srcBuffer);
	const char *srcStart;
	srcStart = srcRow;
	char *dstRow = reinterpret_cast<char *>(destBuffer);
	char *dstStart;
	dstStart = dstRow;

	if (rowPitch == static_cast<vk::VkDeviceSize>(width * pixelSize) &&
		depthPitch == static_cast<vk::VkDeviceSize>(rowPitch * height))
	{
		// fast path
		deMemcpy(dstRow, srcRow, static_cast<size_t>(size));
	}
	else {
		// slower, per row path
		for (size_t d = 0; d < (size_t)depth; d++)
		{
			vk::VkDeviceSize offsetDepthDst = d * (pixelSize * width * height);
			vk::VkDeviceSize offsetDepthSrc = d * depthPitch;
			srcRow = srcStart + offsetDepthSrc;
			dstRow = dstStart + offsetDepthDst;
			for (int r = 0; r < height; ++r)
			{
				deMemcpy(dstRow, srcRow, static_cast<size_t>(pixelSize * width));
				srcRow += rowPitch;
				dstRow += pixelSize * width;
			}
		}
	}
}

Image::Image (const vk::DeviceInterface& vk,
			  vk::VkDevice				device,
			  vk::VkFormat				format,
			  const vk::VkExtent3D&		extend,
			  deUint32					levelCount,
			  deUint32					layerCount,
			  vk::Move<vk::VkImage>		object_)
	: m_allocation		(DE_NULL)
	, m_object			(object_)
	, m_format			(format)
	, m_extent			(extend)
	, m_levelCount		(levelCount)
	, m_layerCount		(layerCount)
	, m_vk(vk)
	, m_device(device)
{
}

tcu::ConstPixelBufferAccess Image::readSurface (vk::VkQueue					queue,
												vk::Allocator&				allocator,
												vk::VkImageLayout			layout,
												vk::VkOffset3D				offset,
												int							width,
												int							height,
												vk::VkImageAspectFlagBits	aspect,
												unsigned int				mipLevel,
												unsigned int				arrayElement)
{
	m_pixelAccessData.resize(width * height * vk::mapVkFormat(m_format).getPixelSize());
	deMemset(m_pixelAccessData.data(), 0, m_pixelAccessData.size());
	if (aspect == vk::VK_IMAGE_ASPECT_COLOR_BIT)
	{
		read(queue, allocator, layout, offset, width, height, 1, mipLevel, arrayElement, aspect, vk::VK_IMAGE_TYPE_2D,
		m_pixelAccessData.data());
	}
	if (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT || aspect == vk::VK_IMAGE_ASPECT_STENCIL_BIT)
	{
		readUsingBuffer(queue, allocator, layout, offset, width, height, 1, mipLevel, arrayElement, aspect, m_pixelAccessData.data());
	}
	return tcu::ConstPixelBufferAccess(vk::mapVkFormat(m_format), width, height, 1, m_pixelAccessData.data());
}

tcu::ConstPixelBufferAccess Image::readVolume (vk::VkQueue					queue,
											   vk::Allocator&				allocator,
											   vk::VkImageLayout			layout,
											   vk::VkOffset3D				offset,
											   int							width,
											   int							height,
											   int							depth,
											   vk::VkImageAspectFlagBits	aspect,
											   unsigned int					mipLevel,
											   unsigned int					arrayElement)
{
	m_pixelAccessData.resize(width * height * depth * vk::mapVkFormat(m_format).getPixelSize());
	deMemset(m_pixelAccessData.data(), 0, m_pixelAccessData.size());
	if (aspect == vk::VK_IMAGE_ASPECT_COLOR_BIT)
	{
		read(queue, allocator, layout, offset, width, height, depth, mipLevel, arrayElement, aspect, vk::VK_IMAGE_TYPE_3D,
		m_pixelAccessData.data());
	}
	if (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT || aspect == vk::VK_IMAGE_ASPECT_STENCIL_BIT)
	{
		readUsingBuffer(queue, allocator, layout, offset, width, height, depth, mipLevel, arrayElement, aspect, m_pixelAccessData.data());
	}
	return tcu::ConstPixelBufferAccess(vk::mapVkFormat(m_format), width, height, depth, m_pixelAccessData.data());
}

tcu::ConstPixelBufferAccess Image::readSurface1D(vk::VkQueue				queue,
												 vk::Allocator&				allocator,
												 vk::VkImageLayout			layout,
												 vk::VkOffset3D				offset,
												 int						width,
												 vk::VkImageAspectFlagBits	aspect,
												 unsigned int				mipLevel,
												 unsigned int				arrayElement)
{
	m_pixelAccessData.resize(width * vk::mapVkFormat(m_format).getPixelSize());
	deMemset(m_pixelAccessData.data(), 0, m_pixelAccessData.size());
	if (aspect == vk::VK_IMAGE_ASPECT_COLOR_BIT)
	{
		read(queue, allocator, layout, offset, width, 1, 1, mipLevel, arrayElement, aspect, vk::VK_IMAGE_TYPE_1D,
		m_pixelAccessData.data());
	}
	if (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT || aspect == vk::VK_IMAGE_ASPECT_STENCIL_BIT)
	{
		readUsingBuffer(queue, allocator, layout, offset, width, 1, 1, mipLevel, arrayElement, aspect,
		m_pixelAccessData.data());
	}
	return tcu::ConstPixelBufferAccess(vk::mapVkFormat(m_format), width, 1, 1, m_pixelAccessData.data());
}

void Image::read (vk::VkQueue					queue,
				  vk::Allocator&				allocator,
				  vk::VkImageLayout				layout,
				  vk::VkOffset3D				offset,
				  int							width,
				  int							height,
				  int							depth,
				  unsigned int					mipLevel,
				  unsigned int					arrayElement,
				  vk::VkImageAspectFlagBits		aspect,
				  vk::VkImageType				type,
				  void *						data)
{
	DE_ASSERT(layout == vk::VK_IMAGE_LAYOUT_GENERAL || layout == vk::VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

	de::SharedPtr<Image> stagingResource = copyToLinearImage(queue, allocator, layout, offset, width,
															 height, depth, mipLevel, arrayElement, aspect, type);
	const vk::VkOffset3D zeroOffset = {0, 0, 0};
	stagingResource->readLinear(zeroOffset, width, height, depth, 0, 0, aspect, data);
}

void Image::readUsingBuffer (vk::VkQueue				queue,
							 vk::Allocator&				allocator,
							 vk::VkImageLayout			layout,
							 vk::VkOffset3D				offset,
							 int						width,
							 int						height,
							 int						depth,
							 unsigned int				mipLevel,
							 unsigned int				arrayElement,
							 vk::VkImageAspectFlagBits	aspect,
							 void *						data)
{
	DE_ASSERT(layout == vk::VK_IMAGE_LAYOUT_GENERAL || layout == vk::VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);;

	de::SharedPtr<Buffer> stagingResource;

	bool isCombinedType = isCombinedDepthStencilType(vk::mapVkFormat(m_format).type);
	vk::VkDeviceSize bufferSize = 0;

	if (!isCombinedType)
		bufferSize = vk::mapVkFormat(m_format).getPixelSize() * width * height * depth;

	if (isCombinedType)
	{
		int pixelSize = 0;
		switch (m_format)
		{
			case vk::VK_FORMAT_D16_UNORM_S8_UINT:
				pixelSize = (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT) ? 2 : 1;
				break;
			case  vk::VK_FORMAT_D32_SFLOAT_S8_UINT:
				pixelSize = (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT) ? 4 : 1;
				break;
			case vk::VK_FORMAT_X8_D24_UNORM_PACK32:
			case vk::VK_FORMAT_D24_UNORM_S8_UINT:
				pixelSize = (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT) ? 3 : 1;
				break;

			default:
				DE_FATAL("Not implemented");
		}
		bufferSize = pixelSize*width*height*depth;
	}

	BufferCreateInfo stagingBufferResourceCreateInfo(bufferSize, vk::VK_BUFFER_USAGE_TRANSFER_DST_BIT | vk::VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
	stagingResource = Buffer::createAndAlloc(m_vk, m_device, stagingBufferResourceCreateInfo, allocator, vk::MemoryRequirement::HostVisible);

	{
		//todo [scygan] get proper queueFamilyIndex
		CmdPoolCreateInfo copyCmdPoolCreateInfo(0);
		vk::Unique<vk::VkCommandPool> copyCmdPool(vk::createCommandPool(m_vk, m_device, &copyCmdPoolCreateInfo));

		const vk::VkCommandBufferAllocateInfo cmdBufferAllocateInfo =
		{
			vk::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,	// VkStructureType			sType;
			DE_NULL,											// const void*				pNext;
			*copyCmdPool,										// VkCommandPool			commandPool;
			vk::VK_COMMAND_BUFFER_LEVEL_PRIMARY,				// VkCommandBufferLevel		level;
			1u,													// deUint32					bufferCount;
		};
		vk::Unique<vk::VkCommandBuffer> copyCmdBuffer(vk::allocateCommandBuffer(m_vk, m_device, &cmdBufferAllocateInfo));

		CmdBufferBeginInfo beginInfo;
		VK_CHECK(m_vk.beginCommandBuffer(*copyCmdBuffer, &beginInfo));

		if (layout == vk::VK_IMAGE_LAYOUT_UNDEFINED)
		{
			layout = vk::VK_IMAGE_LAYOUT_GENERAL;

			vk::VkImageMemoryBarrier barrier;
			barrier.sType = vk::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
			barrier.pNext = DE_NULL;
			barrier.srcAccessMask = 0;
			barrier.dstAccessMask = 0;
			barrier.oldLayout = vk::VK_IMAGE_LAYOUT_UNDEFINED;
			barrier.newLayout = vk::VK_IMAGE_LAYOUT_GENERAL;
			barrier.srcQueueFamilyIndex = vk::VK_QUEUE_FAMILY_IGNORED;
			barrier.dstQueueFamilyIndex = vk::VK_QUEUE_FAMILY_IGNORED;
			barrier.image = object();

			barrier.subresourceRange.aspectMask = aspect;
			barrier.subresourceRange.baseMipLevel = 0;
			barrier.subresourceRange.levelCount = m_levelCount;
			barrier.subresourceRange.baseArrayLayer = 0;
			barrier.subresourceRange.layerCount = m_layerCount;

			void* barriers[] = { &barrier };

			m_vk.cmdPipelineBarrier(*copyCmdBuffer, vk::VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT, vk::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
				false, DE_LENGTH_OF_ARRAY(barriers), barriers);
		}

		vk::VkBufferImageCopy region =
		{
			0, 0, 0,
			{ aspect, mipLevel, arrayElement, 1 },
			offset,
			{ width, height, depth }
		};

		m_vk.cmdCopyImageToBuffer(*copyCmdBuffer, object(), layout, stagingResource->object(), 1, &region);
		VK_CHECK(m_vk.endCommandBuffer(*copyCmdBuffer));

		vk::VkSubmitInfo submitInfo =
		{
			vk::VK_STRUCTURE_TYPE_SUBMIT_INFO,	// VkStructureType			sType;
			DE_NULL,							// const void*				pNext;
			0,									// deUint32					waitSemaphoreCount;
			DE_NULL,							// const VkSemaphore*		pWaitSemaphores;
			1,									// deUint32					commandBufferCount;
			&copyCmdBuffer.get(),				// const VkCommandBuffer*	pCommandBuffers;
			0,									// deUint32					signalSemaphoreCount;
			DE_NULL								// const VkSemaphore*		pSignalSemaphores;
		};
		m_vk.queueSubmit(queue, 1, &submitInfo, DE_NULL);

		// TODO: make this less intrusive
		VK_CHECK(m_vk.queueWaitIdle(queue));
	}

	char* destPtr = reinterpret_cast<char*>(stagingResource->getBoundMemory().getHostPtr());
	deMemcpy(data, destPtr, bufferSize);
}

tcu::ConstPixelBufferAccess Image::readSurfaceLinear (vk::VkOffset3D				offset,
													  int							width,
													  int							height,
													  int							depth,
													  vk::VkImageAspectFlagBits		aspect,
													  unsigned int					mipLevel,
													  unsigned int					arrayElement)
{
	m_pixelAccessData.resize(width * height * vk::mapVkFormat(m_format).getPixelSize());
	readLinear(offset, width, height, depth, mipLevel, arrayElement, aspect, m_pixelAccessData.data());
	return tcu::ConstPixelBufferAccess(vk::mapVkFormat(m_format), width, height, 1, m_pixelAccessData.data());
}

void Image::readLinear (vk::VkOffset3D				offset,
						int							width,
						int							height,
						int							depth,
						unsigned int				mipLevel,
						unsigned int				arrayElement,
						vk::VkImageAspectFlagBits	aspect,
						void *						data)
{
	vk::VkImageSubresource imageSubResource = { aspect, mipLevel, arrayElement };

	vk::VkSubresourceLayout imageLayout;
	deMemset(&imageLayout, 0, sizeof(imageLayout));

	m_vk.getImageSubresourceLayout(m_device, object(), &imageSubResource, &imageLayout);

	const char* srcPtr = reinterpret_cast<const char*>(getBoundMemory().getHostPtr());
	srcPtr += imageLayout.offset + getPixelOffset(offset, imageLayout.rowPitch, imageLayout.depthPitch, mipLevel, arrayElement);

	MemoryOp::unpack(vk::mapVkFormat(m_format).getPixelSize(), width, height, depth,
		imageLayout.rowPitch, imageLayout.depthPitch, srcPtr, data);
}

de::SharedPtr<Image> Image::copyToLinearImage (vk::VkQueue					queue,
											   vk::Allocator&				allocator,
											   vk::VkImageLayout			layout,
											   vk::VkOffset3D				offset,
											   int							width,
											   int							height,
											   int							depth,
											   unsigned int					mipLevel,
											   unsigned int					arrayElement,
											   vk::VkImageAspectFlagBits	aspect,
											   vk::VkImageType				type)
{
	de::SharedPtr<Image> stagingResource;
	{
		vk::VkExtent3D stagingExtent = {width, height, depth};
		ImageCreateInfo stagingResourceCreateInfo(type, m_format, stagingExtent, 1, 1, vk::VK_SAMPLE_COUNT_1_BIT,
												  vk::VK_IMAGE_TILING_LINEAR, vk::VK_IMAGE_USAGE_TRANSFER_DST_BIT);

		stagingResource = Image::createAndAlloc(m_vk, m_device, stagingResourceCreateInfo, allocator,
												vk::MemoryRequirement::HostVisible);

		//todo [scygan] get proper queueFamilyIndex
		CmdPoolCreateInfo copyCmdPoolCreateInfo(0);
		vk::Unique<vk::VkCommandPool> copyCmdPool(vk::createCommandPool(m_vk, m_device, &copyCmdPoolCreateInfo));

		const vk::VkCommandBufferAllocateInfo cmdBufferAllocateInfo =
		{
			vk::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,	// VkStructureType			sType;
			DE_NULL,											// const void*				pNext;
			*copyCmdPool,										// VkCommandPool			commandPool;
			vk::VK_COMMAND_BUFFER_LEVEL_PRIMARY,				// VkCommandBufferLevel		level;
			1u,													// deUint32					bufferCount;
		};
		vk::Unique<vk::VkCommandBuffer> copyCmdBuffer(vk::allocateCommandBuffer(m_vk, m_device, &cmdBufferAllocateInfo));

		CmdBufferBeginInfo beginInfo;
		VK_CHECK(m_vk.beginCommandBuffer(*copyCmdBuffer, &beginInfo));

		transition2DImage(m_vk, *copyCmdBuffer, stagingResource->object(), aspect, vk::VK_IMAGE_LAYOUT_UNDEFINED, vk::VK_IMAGE_LAYOUT_GENERAL);

		const vk::VkOffset3D zeroOffset = { 0, 0, 0 };
		vk::VkImageCopy region = { {aspect, mipLevel, arrayElement, 1}, offset, {aspect, 0, 0, 1}, zeroOffset, {width, height, depth} };

		m_vk.cmdCopyImage(*copyCmdBuffer, object(), layout, stagingResource->object(), vk::VK_IMAGE_LAYOUT_GENERAL, 1, &region);
		VK_CHECK(m_vk.endCommandBuffer(*copyCmdBuffer));

		vk::VkSubmitInfo submitInfo =
		{
			vk::VK_STRUCTURE_TYPE_SUBMIT_INFO,	// VkStructureType			sType;
			DE_NULL,							// const void*				pNext;
			0,									// deUint32					waitSemaphoreCount;
			DE_NULL,							// const VkSemaphore*		pWaitSemaphores;
			1,									// deUint32					commandBufferCount;
			&copyCmdBuffer.get(),				// const VkCommandBuffer*	pCommandBuffers;
			0,									// deUint32					signalSemaphoreCount;
			DE_NULL								// const VkSemaphore*		pSignalSemaphores;
		};
		m_vk.queueSubmit(queue, 1, &submitInfo, DE_NULL);

		// TODO: make this less intrusive
		VK_CHECK(m_vk.queueWaitIdle(queue));
	}
	return stagingResource;
}

void Image::uploadVolume(const tcu::ConstPixelBufferAccess&	access,
						 vk::VkQueue						queue,
						 vk::Allocator&						allocator,
						 vk::VkImageLayout					layout,
						 vk::VkOffset3D						offset,
						 vk::VkImageAspectFlagBits			aspect,
						 unsigned int						mipLevel,
						 unsigned int						arrayElement)
{
	if (aspect == vk::VK_IMAGE_ASPECT_COLOR_BIT)
	{
		upload(queue, allocator, layout, offset, access.getWidth(),
		access.getHeight(), access.getDepth(), mipLevel, arrayElement, aspect, vk::VK_IMAGE_TYPE_3D,
		access.getDataPtr());
	}
	if (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT || aspect == vk::VK_IMAGE_ASPECT_STENCIL_BIT)
	{
		uploadUsingBuffer(queue, allocator, layout, offset, access.getWidth(),
		access.getHeight(), access.getDepth(), mipLevel, arrayElement, aspect, access.getDataPtr());
	}
}

void Image::uploadSurface (const tcu::ConstPixelBufferAccess&	access,
						   vk::VkQueue							queue,
						   vk::Allocator&						allocator,
						   vk::VkImageLayout					layout,
						   vk::VkOffset3D						offset,
						   vk::VkImageAspectFlagBits			aspect,
						   unsigned int							mipLevel,
						   unsigned int							arrayElement)
{
	if (aspect == vk::VK_IMAGE_ASPECT_COLOR_BIT)
	{
		upload(queue, allocator, layout, offset, access.getWidth(),
			access.getHeight(), access.getDepth(), mipLevel, arrayElement, aspect, vk::VK_IMAGE_TYPE_2D,
			access.getDataPtr());
	}
	if (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT || aspect == vk::VK_IMAGE_ASPECT_STENCIL_BIT)
	{
		uploadUsingBuffer(queue, allocator, layout, offset, access.getWidth(),
			access.getHeight(), access.getDepth(), mipLevel, arrayElement, aspect, access.getDataPtr());
	}
}

void Image::uploadSurface1D (const tcu::ConstPixelBufferAccess&	access,
							 vk::VkQueue						queue,
							 vk::Allocator&						allocator,
							 vk::VkImageLayout					layout,
							 vk::VkOffset3D						offset,
							 vk::VkImageAspectFlagBits			aspect,
							 unsigned int						mipLevel,
							 unsigned int						arrayElement)
{
	if (aspect == vk::VK_IMAGE_ASPECT_COLOR_BIT)
	{
		upload(queue, allocator, layout, offset, access.getWidth(),
			access.getHeight(), access.getDepth(), mipLevel, arrayElement, aspect, vk::VK_IMAGE_TYPE_1D,
			access.getDataPtr());
	}
	if (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT || aspect == vk::VK_IMAGE_ASPECT_STENCIL_BIT)
	{
		uploadUsingBuffer(queue, allocator, layout, offset, access.getWidth(),
			access.getHeight(), access.getDepth(), mipLevel, arrayElement, aspect, access.getDataPtr());
	}
}

void Image::uploadSurfaceLinear (const tcu::ConstPixelBufferAccess&	access,
								 vk::VkOffset3D						offset,
								 int								width,
								 int								height,
								 int								depth,
								 vk::VkImageAspectFlagBits			aspect,
								 unsigned int						mipLevel,
								 unsigned int						arrayElement)
{
	uploadLinear(offset, width, height, depth, mipLevel, arrayElement, aspect, access.getDataPtr());
}

void Image::upload (vk::VkQueue					queue,
					vk::Allocator&				allocator,
					vk::VkImageLayout			layout,
					vk::VkOffset3D				offset,
					int							width,
					int							height,
					int							depth,
					unsigned int				mipLevel,
					unsigned int				arrayElement,
					vk::VkImageAspectFlagBits	aspect,
					vk::VkImageType				type,
					const void *				data)
{
	DE_ASSERT(layout == vk::VK_IMAGE_LAYOUT_GENERAL || layout == vk::VK_IMAGE_LAYOUT_UNDEFINED || layout == vk::VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

	de::SharedPtr<Image> stagingResource;
	vk::VkExtent3D extent = {width, height, depth};
	ImageCreateInfo stagingResourceCreateInfo(
		type, m_format, extent, 1, 1, vk::VK_SAMPLE_COUNT_1_BIT,
		vk::VK_IMAGE_TILING_LINEAR, vk::VK_IMAGE_USAGE_TRANSFER_SRC_BIT);

	stagingResource = Image::createAndAlloc(m_vk, m_device, stagingResourceCreateInfo, allocator,
								vk::MemoryRequirement::HostVisible);

	const vk::VkOffset3D zeroOffset = { 0, 0, 0 };
	stagingResource->uploadLinear(zeroOffset, width, height, depth, 0, 0, aspect, data);

	{
		//todo [scygan] get proper queueFamilyIndex
		CmdPoolCreateInfo copyCmdPoolCreateInfo(0);
		vk::Unique<vk::VkCommandPool> copyCmdPool(vk::createCommandPool(m_vk, m_device, &copyCmdPoolCreateInfo));

		const vk::VkCommandBufferAllocateInfo cmdBufferAllocateInfo =
		{
			vk::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,	// VkStructureType			sType;
			DE_NULL,											// const void*				pNext;
			*copyCmdPool,										// VkCommandPool			commandPool;
			vk::VK_COMMAND_BUFFER_LEVEL_PRIMARY,				// VkCommandBufferLevel		level;
			1u,													// deUint32					bufferCount;
		};

		vk::Unique<vk::VkCommandBuffer> copyCmdBuffer(vk::allocateCommandBuffer(m_vk, m_device, &cmdBufferAllocateInfo));

		CmdBufferBeginInfo beginInfo;
		VK_CHECK(m_vk.beginCommandBuffer(*copyCmdBuffer, &beginInfo));

		if (layout == vk::VK_IMAGE_LAYOUT_UNDEFINED)
		{
			layout = vk::VK_IMAGE_LAYOUT_GENERAL;

			vk::VkImageMemoryBarrier barrier;
			barrier.sType = vk::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
			barrier.pNext = DE_NULL;
			barrier.srcAccessMask = 0;
			barrier.dstAccessMask = 0;
			barrier.oldLayout = vk::VK_IMAGE_LAYOUT_UNDEFINED;
			barrier.newLayout = vk::VK_IMAGE_LAYOUT_GENERAL;
			barrier.srcQueueFamilyIndex = vk::VK_QUEUE_FAMILY_IGNORED;
			barrier.dstQueueFamilyIndex = vk::VK_QUEUE_FAMILY_IGNORED;
			barrier.image = object();

			barrier.subresourceRange.aspectMask = aspect;
			barrier.subresourceRange.baseMipLevel = 0;
			barrier.subresourceRange.levelCount = m_levelCount;
			barrier.subresourceRange.baseArrayLayer = 0;
			barrier.subresourceRange.layerCount = m_layerCount;

			void* barriers[] = { &barrier };

			m_vk.cmdPipelineBarrier(*copyCmdBuffer, vk::VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT, vk::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, false, DE_LENGTH_OF_ARRAY(barriers), barriers);
		}

		transition2DImage(m_vk, *copyCmdBuffer, stagingResource->object(), aspect, vk::VK_IMAGE_LAYOUT_UNDEFINED, vk::VK_IMAGE_LAYOUT_GENERAL);

		vk::VkImageCopy region = {{aspect, 0, 0, 1},
									zeroOffset,
									{aspect, mipLevel, arrayElement, 1},
									offset,
									{width, height, depth}};

		m_vk.cmdCopyImage(*copyCmdBuffer, stagingResource->object(),
								vk::VK_IMAGE_LAYOUT_GENERAL, object(), layout, 1, &region);
		VK_CHECK(m_vk.endCommandBuffer(*copyCmdBuffer));

		vk::VkSubmitInfo submitInfo =
		{
			vk::VK_STRUCTURE_TYPE_SUBMIT_INFO,	// VkStructureType			sType;
			DE_NULL,							// const void*				pNext;
			0,									// deUint32					waitSemaphoreCount;
			DE_NULL,							// const VkSemaphore*		pWaitSemaphores;
			1,									// deUint32					commandBufferCount;
			&copyCmdBuffer.get(),				// const VkCommandBuffer*	pCommandBuffers;
			0,									// deUint32					signalSemaphoreCount;
			DE_NULL								// const VkSemaphore*		pSignalSemaphores;
		};
		m_vk.queueSubmit(queue, 1, &submitInfo, DE_NULL);

		// TODO: make this less intrusive
		VK_CHECK(m_vk.queueWaitIdle(queue));
	}
}

void Image::uploadUsingBuffer (vk::VkQueue					queue,
							   vk::Allocator&				allocator,
							   vk::VkImageLayout			layout,
							   vk::VkOffset3D				offset,
							   int							width,
							   int							height,
							   int							depth,
							   unsigned int					mipLevel,
							   unsigned int					arrayElement,
							   vk::VkImageAspectFlagBits	aspect,
							   const void *					data)
{
	DE_ASSERT(layout == vk::VK_IMAGE_LAYOUT_GENERAL || layout == vk::VK_IMAGE_LAYOUT_UNDEFINED || layout == vk::VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

	de::SharedPtr<Buffer> stagingResource;
	bool isCombinedType = isCombinedDepthStencilType(vk::mapVkFormat(m_format).type);
	vk::VkDeviceSize bufferSize = 0;
	if (!isCombinedType)
		bufferSize = vk::mapVkFormat(m_format).getPixelSize() *width*height*depth;
	if (isCombinedType)
	{
		int pixelSize = 0;
		switch (m_format)
		{
			case vk::VK_FORMAT_D16_UNORM_S8_UINT:
				pixelSize = (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT) ? 2 : 1;
				break;
			case  vk::VK_FORMAT_D32_SFLOAT_S8_UINT:
				pixelSize = (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT) ? 4 : 1;
				break;
			case vk::VK_FORMAT_X8_D24_UNORM_PACK32:
			case vk::VK_FORMAT_D24_UNORM_S8_UINT:
				pixelSize = (aspect == vk::VK_IMAGE_ASPECT_DEPTH_BIT) ? 3 : 1;
				break;

			default:
				DE_FATAL("Not implemented");
		}
		bufferSize = pixelSize*width*height*depth;
	}
	BufferCreateInfo stagingBufferResourceCreateInfo(bufferSize, vk::VK_BUFFER_USAGE_TRANSFER_DST_BIT | vk::VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
	stagingResource = Buffer::createAndAlloc(m_vk, m_device, stagingBufferResourceCreateInfo, allocator, vk::MemoryRequirement::HostVisible);
	char* destPtr = reinterpret_cast<char*>(stagingResource->getBoundMemory().getHostPtr());
	deMemcpy(destPtr, data, bufferSize);
	vk::flushMappedMemoryRange(m_vk, m_device, stagingResource->getBoundMemory().getMemory(), stagingResource->getBoundMemory().getOffset(), bufferSize);
	{
		//todo [scygan] get proper queueFamilyIndex
		CmdPoolCreateInfo copyCmdPoolCreateInfo(0);
		vk::Unique<vk::VkCommandPool> copyCmdPool(vk::createCommandPool(m_vk, m_device, &copyCmdPoolCreateInfo));

		const vk::VkCommandBufferAllocateInfo cmdBufferAllocateInfo =
		{
			vk::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,	// VkStructureType			sType;
			DE_NULL,											// const void*				pNext;
			*copyCmdPool,										// VkCommandPool			commandPool;
			vk::VK_COMMAND_BUFFER_LEVEL_PRIMARY,				// VkCommandBufferLevel		level;
			1u,													// deUint32					bufferCount;
		};
		vk::Unique<vk::VkCommandBuffer> copyCmdBuffer(vk::allocateCommandBuffer(m_vk, m_device, &cmdBufferAllocateInfo));

		CmdBufferBeginInfo beginInfo;
		VK_CHECK(m_vk.beginCommandBuffer(*copyCmdBuffer, &beginInfo));

		if (layout == vk::VK_IMAGE_LAYOUT_UNDEFINED)
		{
			layout = vk::VK_IMAGE_LAYOUT_GENERAL;

			vk::VkImageMemoryBarrier barrier;
			barrier.sType = vk::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
			barrier.pNext = DE_NULL;
			barrier.srcAccessMask = 0;
			barrier.dstAccessMask = 0;
			barrier.oldLayout = vk::VK_IMAGE_LAYOUT_UNDEFINED;
			barrier.newLayout = vk::VK_IMAGE_LAYOUT_GENERAL;
			barrier.srcQueueFamilyIndex = vk::VK_QUEUE_FAMILY_IGNORED;
			barrier.dstQueueFamilyIndex = vk::VK_QUEUE_FAMILY_IGNORED;
			barrier.image = object();

			barrier.subresourceRange.aspectMask = aspect;
			barrier.subresourceRange.baseMipLevel = 0;
			barrier.subresourceRange.levelCount = m_levelCount;
			barrier.subresourceRange.baseArrayLayer = 0;
			barrier.subresourceRange.layerCount = m_layerCount;

			void* barriers[] = { &barrier };

			m_vk.cmdPipelineBarrier(*copyCmdBuffer, vk::VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT, vk::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, false, DE_LENGTH_OF_ARRAY(barriers), barriers);
		}

		vk::VkBufferImageCopy region = {
			0, 0, 0,
			{ aspect, mipLevel, arrayElement, 1 },
			offset,
			{ width, height, depth }
		};

		m_vk.cmdCopyBufferToImage(*copyCmdBuffer, stagingResource->object(),
			object(), layout, 1, &region);
		VK_CHECK(m_vk.endCommandBuffer(*copyCmdBuffer));

		vk::VkSubmitInfo submitInfo =
		{
			vk::VK_STRUCTURE_TYPE_SUBMIT_INFO,	// VkStructureType			sType;
			DE_NULL,							// const void*				pNext;
			0,									// deUint32					waitSemaphoreCount;
			DE_NULL,							// const VkSemaphore*		pWaitSemaphores;
			1,									// deUint32					commandBufferCount;
			&copyCmdBuffer.get(),				// const VkCommandBuffer*	pCommandBuffers;
			0,									// deUint32					signalSemaphoreCount;
			DE_NULL								// const VkSemaphore*		pSignalSemaphores;
		};
		m_vk.queueSubmit(queue, 1, &submitInfo, DE_NULL);

		// TODO: make this less intrusive
		VK_CHECK(m_vk.queueWaitIdle(queue));
	}
}

void Image::uploadLinear (vk::VkOffset3D			offset,
						  int						width,
						  int						height,
						  int						depth,
						  unsigned int				mipLevel,
						  unsigned int				arrayElement,
						  vk::VkImageAspectFlagBits	aspect,
						  const void *				data)
{
	vk::VkSubresourceLayout imageLayout;

	vk::VkImageSubresource imageSubResource = {aspect, mipLevel, arrayElement};

	m_vk.getImageSubresourceLayout(m_device, object(), &imageSubResource,
													&imageLayout);

	char* destPtr = reinterpret_cast<char*>(getBoundMemory().getHostPtr());

	destPtr += imageLayout.offset + getPixelOffset(offset, imageLayout.rowPitch, imageLayout.depthPitch, mipLevel, arrayElement);

	MemoryOp::pack(vk::mapVkFormat(m_format).getPixelSize(), width, height, depth,
		imageLayout.rowPitch, imageLayout.depthPitch, data, destPtr);
}

vk::VkDeviceSize Image::getPixelOffset (vk::VkOffset3D		offset,
										vk::VkDeviceSize	rowPitch,
										vk::VkDeviceSize	depthPitch,
										unsigned int		level,
										unsigned int		layer)
{
	DE_ASSERT(level < m_levelCount);
	DE_ASSERT(layer < m_layerCount);

	vk::VkDeviceSize mipLevelSizes[32];
	vk::VkDeviceSize mipLevelRectSizes[32];
	tcu::IVec3 mipExtend
	= tcu::IVec3(m_extent.width, m_extent.height, m_extent.depth);

	vk::VkDeviceSize arrayElemSize = 0;
	for (unsigned int i = 0; i < m_levelCount && (mipExtend[0] > 1 || mipExtend[1] > 1 || mipExtend[2] > 1); ++i)
	{
		// Rect size is just a 3D image size;
		mipLevelSizes[i] = mipExtend[2] * depthPitch;

		arrayElemSize += mipLevelSizes[0];

		mipExtend = tcu::max(mipExtend / 2, tcu::IVec3(1));
	}

	vk::VkDeviceSize pixelOffset = layer * arrayElemSize;
	for (size_t i = 0; i < level; ++i) {
		pixelOffset += mipLevelSizes[i];
	}
	pixelOffset += offset.z * mipLevelRectSizes[level];
	pixelOffset += offset.y * rowPitch;
	pixelOffset += offset.x;

	return pixelOffset;
}

void Image::bindMemory (de::MovePtr<vk::Allocation> allocation)
{
	DE_ASSERT(allocation);
	VK_CHECK(m_vk.bindImageMemory(m_device, *m_object, allocation->getMemory(), allocation->getOffset()));

	DE_ASSERT(!m_allocation);
	m_allocation = allocation;
}

de::SharedPtr<Image> Image::createAndAlloc(const vk::DeviceInterface&	vk,
										   vk::VkDevice					device,
										   const vk::VkImageCreateInfo& createInfo,
										   vk::Allocator&				allocator,
										   vk::MemoryRequirement		memoryRequirement)
{
	de::SharedPtr<Image> ret = create(vk, device, createInfo);

	vk::VkMemoryRequirements imageRequirements = vk::getImageMemoryRequirements(vk, device, ret->object());
	ret->bindMemory(allocator.allocate(imageRequirements, memoryRequirement));
	return ret;
}

de::SharedPtr<Image> Image::create(const vk::DeviceInterface&	vk,
								   vk::VkDevice					device,
								   const vk::VkImageCreateInfo	&createInfo)
{
	return de::SharedPtr<Image>(new Image(vk, device, createInfo.format, createInfo.extent,
								createInfo.mipLevels, createInfo.arrayLayers,
								vk::createImage(vk, device, &createInfo)));
}

void transition2DImage (const vk::DeviceInterface&	vk,
						vk::VkCommandBuffer				cmdBuffer,
						vk::VkImage					image,
						vk::VkImageAspectFlags		aspectMask,
						vk::VkImageLayout			oldLayout,
						vk::VkImageLayout			newLayout)
{
	vk::VkImageMemoryBarrier barrier;
	barrier.sType					= vk::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	barrier.pNext					= DE_NULL;
	barrier.srcAccessMask				= 0;
	barrier.dstAccessMask				= 0;
	barrier.oldLayout				= oldLayout;
	barrier.newLayout				= newLayout;
	barrier.srcQueueFamilyIndex		= vk::VK_QUEUE_FAMILY_IGNORED;
	barrier.dstQueueFamilyIndex	= vk::VK_QUEUE_FAMILY_IGNORED;
	barrier.image					= image;
	barrier.subresourceRange.aspectMask		= aspectMask;
	barrier.subresourceRange.baseMipLevel	= 0;
	barrier.subresourceRange.levelCount		= 1;
	barrier.subresourceRange.baseArrayLayer = 0;
	barrier.subresourceRange.layerCount		= 1;

	void* barriers[] = { &barrier };

	vk.cmdPipelineBarrier(cmdBuffer, vk::VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT, vk::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, false, DE_LENGTH_OF_ARRAY(barriers), barriers);
}

void initialTransitionColor2DImage (const vk::DeviceInterface &vk, vk::VkCommandBuffer cmdBuffer, vk::VkImage image, vk::VkImageLayout layout)
{
	transition2DImage(vk, cmdBuffer, image, vk::VK_IMAGE_ASPECT_COLOR_BIT, vk::VK_IMAGE_LAYOUT_UNDEFINED, layout);
}

void initialTransitionDepth2DImage (const vk::DeviceInterface &vk, vk::VkCommandBuffer cmdBuffer, vk::VkImage image, vk::VkImageLayout layout)
{
	transition2DImage(vk, cmdBuffer, image, vk::VK_IMAGE_ASPECT_DEPTH_BIT, vk::VK_IMAGE_LAYOUT_UNDEFINED, layout);
}

void initialTransitionStencil2DImage (const vk::DeviceInterface &vk, vk::VkCommandBuffer cmdBuffer, vk::VkImage image, vk::VkImageLayout layout)
{
	transition2DImage(vk, cmdBuffer, image, vk::VK_IMAGE_ASPECT_STENCIL_BIT, vk::VK_IMAGE_LAYOUT_UNDEFINED, layout);
}

void initialTransitionDepthStencil2DImage (const vk::DeviceInterface &vk, vk::VkCommandBuffer cmdBuffer, vk::VkImage image, vk::VkImageLayout layout)
{
	transition2DImage(vk, cmdBuffer, image, vk::VK_IMAGE_ASPECT_DEPTH_BIT | vk::VK_IMAGE_ASPECT_STENCIL_BIT, vk::VK_IMAGE_LAYOUT_UNDEFINED, layout);
}

} // DynamicState
} // vkt
