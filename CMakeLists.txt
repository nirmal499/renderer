cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

find_package(Vulkan REQUIRED)

add_executable(main 
    dependency/vkb/VkBootstrap.cpp

    main.cpp

    src/window.cpp
    src/logger.cpp
    src/command_buffer.cpp
    src/command_pool.cpp
    src/frame_buffer.cpp
    src/model.cpp
    src/mvk_renderer.cpp
    src/pipeline.cpp
    src/render_pass.cpp
    src/shader.cpp
    src/sync_objects.cpp
    src/texture.cpp

)

target_include_directories(main
    
    # PRIVATE external/glfw/include # No need cause it is getting included automatically when we are linking to it
    PRIVATE external/glm

    PRIVATE src/include
    PRIVATE dependency
)

target_link_libraries(main
    PRIVATE glfw
    PRIVATE Vulkan::Vulkan
)