#pragma once

#include <types/types.hpp>

#include <vulkan/mvk_render_data.hpp>

class CommandBuffer
{
    public:
        static bool init(MVkRenderData& renderData, VkCommandBuffer& commandBuffer);
        static void cleanup(MVkRenderData& renderData, VkCommandBuffer& commandBuffer);
};