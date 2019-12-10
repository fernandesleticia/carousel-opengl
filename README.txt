#To install:

SDL2:
sudo apt-get install libsdl2-dev #to development
sudo apt-get install libsdl2-2.0 #just the libraries

glm:
sudo apt-get install libglm-dev

OpenGL:
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

glew:
sudo apt-get install libglew-dev

glfw:
sudo apt-get install libglfw3-dev

#To compile:

g++ -o main main_carousel.cpp -lGL -lGLU -lglut mesh.cpp display.cpp shader.cpp texture.cpp stb_image.c obj_loader.cpp -lSDL2 -lGLEW -lGL -lglfw
