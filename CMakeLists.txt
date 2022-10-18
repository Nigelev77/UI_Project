cmake_minimum_required(VERSION 3.10)

#set project name
project(TerrainEditor VERSION 1.0)

include_directories("${PROJECT_SOURCE_DIR}/libs/GLAD")
include_directories("${PROJECT_SOURCE_DIR}/libs")
#add the exectuable
add_executable(TerrainEditor ${PROJECT_SOURCE_DIR}/libs/GLAD/glad.c ${PROJECT_SOURCE_DIR}/main.cpp )

configure_file(editor_config.h.in ../editor_config.h)



target_include_directories(TerrainEditor PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/libs/GLAD"
  )



target_link_libraries(TerrainEditor ${PROJECT_SOURCE_DIR}/libs/GLFW/glfw3.lib)
