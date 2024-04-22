/* Vulkan shader */
#pragma once

#include <types/types.hpp>

class Shader
{
  public:
    static VkShaderModule loadShader(VkDevice device, std::string shaderFileName);

  private:
    static std::string loadFileToString(std::string fileName);
};
