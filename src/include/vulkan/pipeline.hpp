#pragma once

#include <types/types.hpp>
#include <vulkan/mvk_render_data.hpp>

class Pipeline
{
    public:
        static bool init(MVkRenderData &renderData, std::string vertexShaderFilename, std::string fragmentShaderFilename);
        static void cleanup(MVkRenderData &renderData);
};