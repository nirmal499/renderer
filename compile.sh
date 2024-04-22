#! /usr/bin/bash

glslc_PATH="/home/nbaskey/my_opt/glslc/install/bin"

${glslc_PATH}/glslc shader/basic.vert -o shader/SPIRV/basic.vert.spv
${glslc_PATH}/glslc shader/basic.frag -o shader/SPIRV/basic.frag.spv