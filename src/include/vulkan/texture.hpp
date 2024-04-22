#pragma once

#include <types/types.hpp>
#include <vulkan/mvk_render_data.hpp>

class Texture
{
    public:
        static bool loadTexture(MVkRenderData &renderData, std::string textureFilename);
        static void cleanup(MVkRenderData &renderData);
};