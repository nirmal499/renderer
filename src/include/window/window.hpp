#pragma once

#include <types/types.hpp>
#include <vulkan/mvk_renderer.hpp>
#include <model/model.hpp>

class Window
{
    public:
        bool init(unsigned int width, unsigned int height, std::string title);
        void main_loop();
        void clean_up();

    private:
        GLFWwindow* m_window = nullptr;

        std::unique_ptr<MVkRenderer> m_renderer;
        std::unique_ptr<Model> m_model;
};