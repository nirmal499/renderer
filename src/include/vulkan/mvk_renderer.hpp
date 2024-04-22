/* Vulkan renderer */
#pragma once

#include <types/types.hpp>

#include <vma/vk_mem_alloc.h>

#include <vulkan/mvk_render_data.hpp>
#include <vulkan/render_pass.hpp>
#include <vulkan/pipeline.hpp>
#include <vulkan/frame_buffer.hpp>
#include <vulkan/command_pool.hpp>
#include <vulkan/command_buffer.hpp>
#include <vulkan/sync_objects.hpp>
#include <vulkan/texture.hpp>


class MVkRenderer
{
  public:
    MVkRenderer(GLFWwindow *window);

    bool init(unsigned int width, unsigned int height);
    void setSize(unsigned int width, unsigned int height);
    bool uploadData(MVkMesh vertexData);
    bool draw();
    void cleanup();

  private:
    MVkRenderData mRenderData{};

    int mTriangleCount = 0;

    GLFWwindow *mWindow = nullptr;

    VkSurfaceKHR mSurface = VK_NULL_HANDLE;
    vkb::PhysicalDevice mPhysDevice;

    VkBuffer mVertexBuffer;
    VmaAllocation mVertexBufferAlloc;

    bool deviceInit();
    bool getQueue();
    bool createDepthBuffer();
    bool createSwapchain();
    bool createRenderPass();
    bool createPipeline();
    bool createFramebuffer();
    bool createCommandPool();
    bool createCommandBuffer();
    bool createSyncObjects();
    bool loadTexture();

    bool initVma();

    bool recreateSwapchain();
};
