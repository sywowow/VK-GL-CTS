/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 * This file was generated by /scripts/gen_framework.py
 */

#include "vkDeviceFeatures.hpp"

namespace vk
{
#define DECL_VARIABLE_POINTERS_EXTENSION_NAME "core_feature"
#define DECL_MULTIVIEW_EXTENSION_NAME "core_feature"
#define DECL_16BIT_STORAGE_EXTENSION_NAME "core_feature"
#define DECL_SHADER_SUBGROUP_EXTENDED_TYPES_EXTENSION_NAME "core_feature"
#define DECL_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME "core_feature"
#define DECL_PROTECTED_MEMORY_EXTENSION_NAME "core_feature"
#define DECL_SHADER_DRAW_PARAMETERS_EXTENSION_NAME "core_feature"
#define DECL_SHADER_FLOAT16_INT8_EXTENSION_NAME "core_feature"
#define DECL_HOST_QUERY_RESET_EXTENSION_NAME "core_feature"
#define DECL_DESCRIPTOR_INDEXING_EXTENSION_NAME "core_feature"
#define DECL_TIMELINE_SEMAPHORE_EXTENSION_NAME "core_feature"
#define DECL_8BIT_STORAGE_EXTENSION_NAME "core_feature"
#define DECL_VULKAN_MEMORY_MODEL_EXTENSION_NAME "core_feature"
#define DECL_SHADER_ATOMIC_INT64_EXTENSION_NAME "core_feature"
#define DECL_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME "core_feature"
#define DECL_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME "core_feature"
#define DECL_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME "core_feature"
#define DECL_IMAGELESS_FRAMEBUFFER_EXTENSION_NAME "core_feature"
#define DECL_SEPARATE_DEPTH_STENCIL_LAYOUTS_EXTENSION_NAME "core_feature"
#define DECL_VULKAN_SC_1_0_EXTENSION_NAME "core_feature"


template<> void initFeatureFromBlob<VkPhysicalDeviceVariablePointersFeatures>(VkPhysicalDeviceVariablePointersFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.variablePointersStorageBuffer = allFeaturesBlobs.vk11.variablePointersStorageBuffer;
	featureType.variablePointers = allFeaturesBlobs.vk11.variablePointers;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceMultiviewFeatures>(VkPhysicalDeviceMultiviewFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.multiview = allFeaturesBlobs.vk11.multiview;
	featureType.multiviewGeometryShader = allFeaturesBlobs.vk11.multiviewGeometryShader;
	featureType.multiviewTessellationShader = allFeaturesBlobs.vk11.multiviewTessellationShader;
}
template<> void initFeatureFromBlob<VkPhysicalDevice16BitStorageFeatures>(VkPhysicalDevice16BitStorageFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.storageBuffer16BitAccess = allFeaturesBlobs.vk11.storageBuffer16BitAccess;
	featureType.uniformAndStorageBuffer16BitAccess = allFeaturesBlobs.vk11.uniformAndStorageBuffer16BitAccess;
	featureType.storagePushConstant16 = allFeaturesBlobs.vk11.storagePushConstant16;
	featureType.storageInputOutput16 = allFeaturesBlobs.vk11.storageInputOutput16;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.shaderSubgroupExtendedTypes = allFeaturesBlobs.vk12.shaderSubgroupExtendedTypes;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceSamplerYcbcrConversionFeatures>(VkPhysicalDeviceSamplerYcbcrConversionFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.samplerYcbcrConversion = allFeaturesBlobs.vk11.samplerYcbcrConversion;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceProtectedMemoryFeatures>(VkPhysicalDeviceProtectedMemoryFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.protectedMemory = allFeaturesBlobs.vk11.protectedMemory;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderDrawParametersFeatures>(VkPhysicalDeviceShaderDrawParametersFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.shaderDrawParameters = allFeaturesBlobs.vk11.shaderDrawParameters;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderFloat16Int8Features>(VkPhysicalDeviceShaderFloat16Int8Features& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.shaderFloat16 = allFeaturesBlobs.vk12.shaderFloat16;
	featureType.shaderInt8 = allFeaturesBlobs.vk12.shaderInt8;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceHostQueryResetFeatures>(VkPhysicalDeviceHostQueryResetFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.hostQueryReset = allFeaturesBlobs.vk12.hostQueryReset;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceDescriptorIndexingFeatures>(VkPhysicalDeviceDescriptorIndexingFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.shaderInputAttachmentArrayDynamicIndexing = allFeaturesBlobs.vk12.shaderInputAttachmentArrayDynamicIndexing;
	featureType.shaderUniformTexelBufferArrayDynamicIndexing = allFeaturesBlobs.vk12.shaderUniformTexelBufferArrayDynamicIndexing;
	featureType.shaderStorageTexelBufferArrayDynamicIndexing = allFeaturesBlobs.vk12.shaderStorageTexelBufferArrayDynamicIndexing;
	featureType.shaderUniformBufferArrayNonUniformIndexing = allFeaturesBlobs.vk12.shaderUniformBufferArrayNonUniformIndexing;
	featureType.shaderSampledImageArrayNonUniformIndexing = allFeaturesBlobs.vk12.shaderSampledImageArrayNonUniformIndexing;
	featureType.shaderStorageBufferArrayNonUniformIndexing = allFeaturesBlobs.vk12.shaderStorageBufferArrayNonUniformIndexing;
	featureType.shaderStorageImageArrayNonUniformIndexing = allFeaturesBlobs.vk12.shaderStorageImageArrayNonUniformIndexing;
	featureType.shaderInputAttachmentArrayNonUniformIndexing = allFeaturesBlobs.vk12.shaderInputAttachmentArrayNonUniformIndexing;
	featureType.shaderUniformTexelBufferArrayNonUniformIndexing = allFeaturesBlobs.vk12.shaderUniformTexelBufferArrayNonUniformIndexing;
	featureType.shaderStorageTexelBufferArrayNonUniformIndexing = allFeaturesBlobs.vk12.shaderStorageTexelBufferArrayNonUniformIndexing;
	featureType.descriptorBindingUniformBufferUpdateAfterBind = allFeaturesBlobs.vk12.descriptorBindingUniformBufferUpdateAfterBind;
	featureType.descriptorBindingSampledImageUpdateAfterBind = allFeaturesBlobs.vk12.descriptorBindingSampledImageUpdateAfterBind;
	featureType.descriptorBindingStorageImageUpdateAfterBind = allFeaturesBlobs.vk12.descriptorBindingStorageImageUpdateAfterBind;
	featureType.descriptorBindingStorageBufferUpdateAfterBind = allFeaturesBlobs.vk12.descriptorBindingStorageBufferUpdateAfterBind;
	featureType.descriptorBindingUniformTexelBufferUpdateAfterBind = allFeaturesBlobs.vk12.descriptorBindingUniformTexelBufferUpdateAfterBind;
	featureType.descriptorBindingStorageTexelBufferUpdateAfterBind = allFeaturesBlobs.vk12.descriptorBindingStorageTexelBufferUpdateAfterBind;
	featureType.descriptorBindingUpdateUnusedWhilePending = allFeaturesBlobs.vk12.descriptorBindingUpdateUnusedWhilePending;
	featureType.descriptorBindingPartiallyBound = allFeaturesBlobs.vk12.descriptorBindingPartiallyBound;
	featureType.descriptorBindingVariableDescriptorCount = allFeaturesBlobs.vk12.descriptorBindingVariableDescriptorCount;
	featureType.runtimeDescriptorArray = allFeaturesBlobs.vk12.runtimeDescriptorArray;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceTimelineSemaphoreFeatures>(VkPhysicalDeviceTimelineSemaphoreFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.timelineSemaphore = allFeaturesBlobs.vk12.timelineSemaphore;
}
template<> void initFeatureFromBlob<VkPhysicalDevice8BitStorageFeatures>(VkPhysicalDevice8BitStorageFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.storageBuffer8BitAccess = allFeaturesBlobs.vk12.storageBuffer8BitAccess;
	featureType.uniformAndStorageBuffer8BitAccess = allFeaturesBlobs.vk12.uniformAndStorageBuffer8BitAccess;
	featureType.storagePushConstant8 = allFeaturesBlobs.vk12.storagePushConstant8;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceVulkanMemoryModelFeatures>(VkPhysicalDeviceVulkanMemoryModelFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.vulkanMemoryModel = allFeaturesBlobs.vk12.vulkanMemoryModel;
	featureType.vulkanMemoryModelDeviceScope = allFeaturesBlobs.vk12.vulkanMemoryModelDeviceScope;
	featureType.vulkanMemoryModelAvailabilityVisibilityChains = allFeaturesBlobs.vk12.vulkanMemoryModelAvailabilityVisibilityChains;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderAtomicInt64Features>(VkPhysicalDeviceShaderAtomicInt64Features& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.shaderBufferInt64Atomics = allFeaturesBlobs.vk12.shaderBufferInt64Atomics;
	featureType.shaderSharedInt64Atomics = allFeaturesBlobs.vk12.shaderSharedInt64Atomics;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceScalarBlockLayoutFeatures>(VkPhysicalDeviceScalarBlockLayoutFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.scalarBlockLayout = allFeaturesBlobs.vk12.scalarBlockLayout;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceUniformBufferStandardLayoutFeatures>(VkPhysicalDeviceUniformBufferStandardLayoutFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.uniformBufferStandardLayout = allFeaturesBlobs.vk12.uniformBufferStandardLayout;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceBufferDeviceAddressFeatures>(VkPhysicalDeviceBufferDeviceAddressFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.bufferDeviceAddress = allFeaturesBlobs.vk12.bufferDeviceAddress;
	featureType.bufferDeviceAddressCaptureReplay = allFeaturesBlobs.vk12.bufferDeviceAddressCaptureReplay;
	featureType.bufferDeviceAddressMultiDevice = allFeaturesBlobs.vk12.bufferDeviceAddressMultiDevice;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceImagelessFramebufferFeatures>(VkPhysicalDeviceImagelessFramebufferFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.imagelessFramebuffer = allFeaturesBlobs.vk12.imagelessFramebuffer;
}
template<> void initFeatureFromBlob<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures& featureType, const AllFeaturesBlobs& allFeaturesBlobs)
{
	featureType.separateDepthStencilLayouts = allFeaturesBlobs.vk12.separateDepthStencilLayouts;
}

// generic template is not enough for some compilers
template<> void initFeatureFromBlob<VkPhysicalDeviceExternalMemorySciBufFeaturesNV>(VkPhysicalDeviceExternalMemorySciBufFeaturesNV&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceExternalSciSyncFeaturesNV>(VkPhysicalDeviceExternalSciSyncFeaturesNV&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceExternalSciSync2FeaturesNV>(VkPhysicalDeviceExternalSciSync2FeaturesNV&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR>(VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceASTCDecodeFeaturesEXT>(VkPhysicalDeviceASTCDecodeFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceDepthClipEnableFeaturesEXT>(VkPhysicalDeviceDepthClipEnableFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT>(VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDevicePerformanceQueryFeaturesKHR>(VkPhysicalDevicePerformanceQueryFeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderClockFeaturesKHR>(VkPhysicalDeviceShaderClockFeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceIndexTypeUint8FeaturesKHR>(VkPhysicalDeviceIndexTypeUint8FeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT>(VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT>(VkPhysicalDeviceSubgroupSizeControlFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceLineRasterizationFeaturesKHR>(VkPhysicalDeviceLineRasterizationFeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceCustomBorderColorFeaturesEXT>(VkPhysicalDeviceCustomBorderColorFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceRobustness2FeaturesEXT>(VkPhysicalDeviceRobustness2FeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceImageRobustnessFeaturesEXT>(VkPhysicalDeviceImageRobustnessFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDevice4444FormatsFeaturesEXT>(VkPhysicalDevice4444FormatsFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceFragmentShadingRateFeaturesKHR>(VkPhysicalDeviceFragmentShadingRateFeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR>(VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceColorWriteEnableFeaturesEXT>(VkPhysicalDeviceColorWriteEnableFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceSynchronization2FeaturesKHR>(VkPhysicalDeviceSynchronization2FeaturesKHR&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceVulkanSC10Features>(VkPhysicalDeviceVulkanSC10Features&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT&, const AllFeaturesBlobs&) {}
template<> void initFeatureFromBlob<VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>(VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX&, const AllFeaturesBlobs&) {}


template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_SPEC_VERSION, 52}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceASTCDecodeFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT, VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME, VK_EXT_ASTC_DECODE_MODE_SPEC_VERSION, 51}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceDepthClipEnableFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT, VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME, VK_EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION, 50}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDevicePerformanceQueryFeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR, VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME, VK_KHR_PERFORMANCE_QUERY_SPEC_VERSION, 49}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME, VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION, 48}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderClockFeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR, VK_KHR_SHADER_CLOCK_EXTENSION_NAME, VK_KHR_SHADER_CLOCK_SPEC_VERSION, 47}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION, 46}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR, VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME, VK_KHR_SHADER_TERMINATE_INVOCATION_SPEC_VERSION, 45}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME, VK_EXT_SUBGROUP_SIZE_CONTROL_SPEC_VERSION, 44}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceFragmentShadingRateFeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR, VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME, VK_KHR_FRAGMENT_SHADING_RATE_SPEC_VERSION, 43}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT, VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME, VK_EXT_SHADER_IMAGE_ATOMIC_INT64_SPEC_VERSION, 42}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT, VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME, VK_EXT_FRAGMENT_SHADER_INTERLOCK_SPEC_VERSION, 41}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT, VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME, VK_EXT_YCBCR_IMAGE_ARRAYS_SPEC_VERSION, 40}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceLineRasterizationFeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT, VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME, VK_EXT_LINE_RASTERIZATION_SPEC_VERSION, 39}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT, VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME, VK_EXT_SHADER_ATOMIC_FLOAT_SPEC_VERSION, 38}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceIndexTypeUint8FeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT, VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME, VK_EXT_INDEX_TYPE_UINT8_SPEC_VERSION, 37}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT, VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME, VK_EXT_EXTENDED_DYNAMIC_STATE_SPEC_VERSION, 36}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_SPEC_VERSION, 35}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT, VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME, VK_EXT_TEXEL_BUFFER_ALIGNMENT_SPEC_VERSION, 34}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceRobustness2FeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT, VK_EXT_ROBUSTNESS_2_EXTENSION_NAME, VK_EXT_ROBUSTNESS_2_SPEC_VERSION, 33}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceCustomBorderColorFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT, VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME, VK_EXT_CUSTOM_BORDER_COLOR_SPEC_VERSION, 32}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceSynchronization2FeaturesKHR>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME, VK_KHR_SYNCHRONIZATION_2_SPEC_VERSION, 31}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT, VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME, VK_EXT_YCBCR_2PLANE_444_FORMATS_SPEC_VERSION, 30}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceImageRobustnessFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT, VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME, VK_EXT_IMAGE_ROBUSTNESS_SPEC_VERSION, 29}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDevice4444FormatsFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT, VK_EXT_4444_FORMATS_EXTENSION_NAME, VK_EXT_4444_FORMATS_SPEC_VERSION, 28}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT, VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME, VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_SPEC_VERSION, 27}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceExternalSciSyncFeaturesNV>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV, VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME, VK_NV_EXTERNAL_SCI_SYNC_SPEC_VERSION, 26}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceExternalMemorySciBufFeaturesNV>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV, VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME, VK_NV_EXTERNAL_MEMORY_SCI_BUF_SPEC_VERSION, 25}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT, VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME, VK_EXT_EXTENDED_DYNAMIC_STATE_2_SPEC_VERSION, 24}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceColorWriteEnableFeaturesEXT>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT, VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME, VK_EXT_COLOR_WRITE_ENABLE_SPEC_VERSION, 23}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceExternalSciSync2FeaturesNV>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV, VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME, VK_NV_EXTERNAL_SCI_SYNC_2_SPEC_VERSION, 22}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX, VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME, VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_SPEC_VERSION, 21}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVariablePointersFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES, DECL_VARIABLE_POINTERS_EXTENSION_NAME, 0, 20}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceMultiviewFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES, DECL_MULTIVIEW_EXTENSION_NAME, 0, 19}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDevice16BitStorageFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES, DECL_16BIT_STORAGE_EXTENSION_NAME, 0, 18}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES, DECL_SHADER_SUBGROUP_EXTENDED_TYPES_EXTENSION_NAME, 0, 17}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceSamplerYcbcrConversionFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES, DECL_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME, 0, 16}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceProtectedMemoryFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES, DECL_PROTECTED_MEMORY_EXTENSION_NAME, 0, 15}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderDrawParametersFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES, DECL_SHADER_DRAW_PARAMETERS_EXTENSION_NAME, 0, 14}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderFloat16Int8Features>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES, DECL_SHADER_FLOAT16_INT8_EXTENSION_NAME, 0, 13}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceHostQueryResetFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES, DECL_HOST_QUERY_RESET_EXTENSION_NAME, 0, 12}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceDescriptorIndexingFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES, DECL_DESCRIPTOR_INDEXING_EXTENSION_NAME, 0, 11}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceTimelineSemaphoreFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES, DECL_TIMELINE_SEMAPHORE_EXTENSION_NAME, 0, 10}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDevice8BitStorageFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES, DECL_8BIT_STORAGE_EXTENSION_NAME, 0, 9}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVulkanMemoryModelFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES, DECL_VULKAN_MEMORY_MODEL_EXTENSION_NAME, 0, 8}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderAtomicInt64Features>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES, DECL_SHADER_ATOMIC_INT64_EXTENSION_NAME, 0, 7}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceScalarBlockLayoutFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES, DECL_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME, 0, 6}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceUniformBufferStandardLayoutFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES, DECL_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME, 0, 5}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceBufferDeviceAddressFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES, DECL_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME, 0, 4}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceImagelessFramebufferFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES, DECL_IMAGELESS_FRAMEBUFFER_EXTENSION_NAME, 0, 3}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES, DECL_SEPARATE_DEPTH_STENCIL_LAYOUTS_EXTENSION_NAME, 0, 2}; }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVulkanSC10Features>(void) { return FeatureDesc{VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_SC_1_0_FEATURES, DECL_VULKAN_SC_1_0_EXTENSION_NAME, 0, 1}; }


static const FeatureStructCreationData featureStructCreationArray[]
{
	{ createFeatureStructWrapper<VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT>, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME, VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceASTCDecodeFeaturesEXT>, VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME, VK_EXT_ASTC_DECODE_MODE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceDepthClipEnableFeaturesEXT>, VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME, VK_EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDevicePerformanceQueryFeaturesKHR>, VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME, VK_KHR_PERFORMANCE_QUERY_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME, VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderClockFeaturesKHR>, VK_KHR_SHADER_CLOCK_EXTENSION_NAME, VK_KHR_SHADER_CLOCK_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR>, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR>, VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME, VK_KHR_SHADER_TERMINATE_INVOCATION_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceSubgroupSizeControlFeaturesEXT>, VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME, VK_EXT_SUBGROUP_SIZE_CONTROL_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceFragmentShadingRateFeaturesKHR>, VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME, VK_KHR_FRAGMENT_SHADING_RATE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>, VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME, VK_EXT_SHADER_IMAGE_ATOMIC_INT64_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>, VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME, VK_EXT_FRAGMENT_SHADER_INTERLOCK_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>, VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME, VK_EXT_YCBCR_IMAGE_ARRAYS_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceLineRasterizationFeaturesKHR>, VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME, VK_EXT_LINE_RASTERIZATION_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>, VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME, VK_EXT_SHADER_ATOMIC_FLOAT_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceIndexTypeUint8FeaturesKHR>, VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME, VK_EXT_INDEX_TYPE_UINT8_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>, VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME, VK_EXT_EXTENDED_DYNAMIC_STATE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT>, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME, VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>, VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME, VK_EXT_TEXEL_BUFFER_ALIGNMENT_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceRobustness2FeaturesEXT>, VK_EXT_ROBUSTNESS_2_EXTENSION_NAME, VK_EXT_ROBUSTNESS_2_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceCustomBorderColorFeaturesEXT>, VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME, VK_EXT_CUSTOM_BORDER_COLOR_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceSynchronization2FeaturesKHR>, VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME, VK_KHR_SYNCHRONIZATION_2_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>, VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME, VK_EXT_YCBCR_2PLANE_444_FORMATS_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceImageRobustnessFeaturesEXT>, VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME, VK_EXT_IMAGE_ROBUSTNESS_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDevice4444FormatsFeaturesEXT>, VK_EXT_4444_FORMATS_EXTENSION_NAME, VK_EXT_4444_FORMATS_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>, VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME, VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceExternalSciSyncFeaturesNV>, VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME, VK_NV_EXTERNAL_SCI_SYNC_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceExternalMemorySciBufFeaturesNV>, VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME, VK_NV_EXTERNAL_MEMORY_SCI_BUF_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>, VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME, VK_EXT_EXTENDED_DYNAMIC_STATE_2_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceColorWriteEnableFeaturesEXT>, VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME, VK_EXT_COLOR_WRITE_ENABLE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceExternalSciSync2FeaturesNV>, VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME, VK_NV_EXTERNAL_SCI_SYNC_2_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX>, VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME, VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceVariablePointersFeatures>, DECL_VARIABLE_POINTERS_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceMultiviewFeatures>, DECL_MULTIVIEW_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDevice16BitStorageFeatures>, DECL_16BIT_STORAGE_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>, DECL_SHADER_SUBGROUP_EXTENDED_TYPES_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceSamplerYcbcrConversionFeatures>, DECL_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceProtectedMemoryFeatures>, DECL_PROTECTED_MEMORY_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderDrawParametersFeatures>, DECL_SHADER_DRAW_PARAMETERS_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderFloat16Int8Features>, DECL_SHADER_FLOAT16_INT8_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceHostQueryResetFeatures>, DECL_HOST_QUERY_RESET_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceDescriptorIndexingFeatures>, DECL_DESCRIPTOR_INDEXING_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceTimelineSemaphoreFeatures>, DECL_TIMELINE_SEMAPHORE_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDevice8BitStorageFeatures>, DECL_8BIT_STORAGE_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceVulkanMemoryModelFeatures>, DECL_VULKAN_MEMORY_MODEL_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderAtomicInt64Features>, DECL_SHADER_ATOMIC_INT64_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceScalarBlockLayoutFeatures>, DECL_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceUniformBufferStandardLayoutFeatures>, DECL_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceBufferDeviceAddressFeatures>, DECL_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceImagelessFramebufferFeatures>, DECL_IMAGELESS_FRAMEBUFFER_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>, DECL_SEPARATE_DEPTH_STENCIL_LAYOUTS_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceVulkanSC10Features>, DECL_VULKAN_SC_1_0_EXTENSION_NAME, 0 },
};

deUint32 getBlobFeaturesVersion (VkStructureType sType)
{
	const std::map<VkStructureType, deUint32> sTypeBlobMap
	{
		// Vulkan11
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES,								VK_API_VERSION_1_1 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES,									VK_API_VERSION_1_1 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES,							VK_API_VERSION_1_1 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES,					VK_API_VERSION_1_1 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES,					VK_API_VERSION_1_1 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES,							VK_API_VERSION_1_1 },
		// Vulkan12
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES,								VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES,						VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES,						VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES,							VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES,						VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES,						VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES,			VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES,						VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES,						VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES,			VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES,						VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES,			VK_API_VERSION_1_2 },
		{ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES,						VK_API_VERSION_1_2 },
		// Vulkan13
	};

	auto it = sTypeBlobMap.find(sType);
	if(it == sTypeBlobMap.end())
		return 0;
	return it->second;
}

} // vk

