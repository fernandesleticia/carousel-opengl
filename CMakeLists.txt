cmake_minimum_required(VERSION 3.12)
project(CG_2018_2_OpenGL)

set(CMAKE_CXX_STANDARD 14)

add_executable(CG_2018_2_OpenGL main_test.cpp main_carousel.cpp mesh.h mesh.cpp camera.h display.h display.cpp transform.h texture.h texture.cpp shader.h shader.cpp debugTimer.h util.h obj_loader.h obj_loader.cpp stb_image.h stb_image.c)