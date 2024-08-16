#ifndef _VKTDGCCOMPUTESMOKETESTS_HPP
#define _VKTDGCCOMPUTESMOKETESTS_HPP
/*------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2024 The Khronos Group Inc.
 * Copyright (c) 2024 Valve Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief Device Generated Commands Compute "Smoke" Tests
 *//*--------------------------------------------------------------------*/

#include "tcuTestCase.hpp"

namespace vkt
{
namespace DGC
{
tcu::TestCaseGroup *createDGCComputeSmokeTests(tcu::TestContext &testCtx);
} // namespace DGC
} // namespace vkt

#endif // _VKTDGCCOMPUTESMOKETESTS_HPP
