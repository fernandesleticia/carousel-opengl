# Star Wars 
A Star Wars scene built using the OpenGL

## Intalling the dependencies:

* SDL2
> provide a hardware abstraction layer for computer multimedia hardware components
```bash
$ sudo apt-get install libsdl2-dev 
$ sudo apt-get install libsdl2-2.0 
```
* glm
> OpenGL Mathematics is a C ++ mathematical library for graphics software.
```bash
$ sudo apt-get install libglm-dev
```

* OpenGL
```bash
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

* glew
>  provides efficient runtime mechanisms
```bash
$ sudo apt-get install libglew-dev
```

* glfw
```bash
$ sudo apt-get install libglfw3-dev
```

## Using

* Compiling
```bash
$ g++ -o main main_carousel.cpp -lGL -lGLU -lglut mesh.cpp display.cpp shader.cpp texture.cpp stb_image.c obj_loader.cpp -lSDL2 -lGLEW -lGL -lglfw
```

* Running
```bash
$ ./main
```
