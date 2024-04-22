#pragma once

#define GLFW_INCLUDE_VULKAN
// GLFW is included next
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <vector>
#include <fstream>
#include <array>
#include <memory>
#include <cerrno>  // errno
#include <cstring> // strerror()

#define SHADER_PATH "/home/nbaskey/Desktop/nirmal/projects/vulkan-engine/shader/SPIRV/"
#define TEXTURE_PATH "/home/nbaskey/Desktop/nirmal/projects/vulkan-engine/texture/"

