#pragma once

#include <types/types.hpp>
#include <vulkan/mvk_render_data.hpp>

class Renderpass
{
    public:
        static bool init(MVkRenderData& renderData);
        static void cleanup(MVkRenderData& renderData);
};