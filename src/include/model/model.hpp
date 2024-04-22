#pragma once

#include <types/types.hpp>
#include <vulkan/mvk_render_data.hpp>

class Model
{
    public:
        void init();

        MVkMesh getVertexData();

    private:
        MVkMesh mVertexData;
};