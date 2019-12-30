# Star Wars 
A Star Wars scene built using the OpenGL

## Intalling the dependencies:

* SDL2
> fornecer uma camada de abstração de hardware para componentes de hardware de multimídia de computadores
```bash
$ sudo apt-get install libsdl2-dev 
$ sudo apt-get install libsdl2-2.0 
```
* glm
> OpenGL Mathematics é uma biblioteca matemática feita em C ++ para softwares gráficos
```bash
$ sudo apt-get install libglm-dev
```

* OpenGL
```bash
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

* glew
>  fornece mecanismos eficientes de tempo de execução
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
