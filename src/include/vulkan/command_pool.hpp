#pragma once

#include <types/types.hpp>
#include <vulkan/mvk_render_data.hpp>

class CommandPool
{
    public:
        static bool init(MVkRenderData& renderData);
        static void cleanup(MVkRenderData& renderData);
};