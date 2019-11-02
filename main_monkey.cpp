//
// Created by leticia on 10/12/18.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

static const int DISPLAY_WIDTH = 800;
static const int DISPLAY_HEIGHT = 600;

int main(int argc, char** argv)
{
    //Contrução da tela
    Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "CG 2018");

    //sombra
    Shader shader("basicShader");

    //mercúrio
    Mesh mercury("./planets/Mercury.obj");
    Texture mercury_texture("./planets/mercury_texture.png");

    //vênus
    Mesh venus("./planets/Venus.obj");
    Texture venus_texture("./planets/venus_texture.png");

    //terra
    Mesh earth("./planets/Earth.obj");
    Texture earth_texture("./planets/earth_texture.png");

    //marte
    Mesh mars("./planets/Mars.obj");
    Texture mars_texture("./planets/mars_texture.png");

/*    //urano
    Mesh uranus("./planets/Uranus.obj");
    Texture uranus_texture("./planets/uranus_texture.jpg");*/

    Transform transform;
    Camera camera(glm::vec3(1.5f, 0.0f, -5.0f), 70.0f, (float)DISPLAY_WIDTH/(float)DISPLAY_HEIGHT, 0.1f, 100.0f);

    SDL_Event e;
    bool isRunning = true;
    float counter = 0.0f;
    int move = 1;
    while(isRunning)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
                isRunning = false;
        }

        display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

        float sinCounter = sinf(counter);
        float absSinCounter = abs(sinCounter);



        transform.GetRot()->y = counter * 1.1;
        //transform.GetRot()->z = counter * 100;
        //transform.GetScale()->x = absSinCounter;
        //transform.GetScale()->y = absSinCounter;

        //mercúrio
        transform.GetPos()->x = -2;
        transform.GetPos()->z = 20;
        mercury_texture.Bind();
        mercury.Draw();
        shader.Bind();
        shader.Update(transform, camera);
        glLoadIdentity();

        //vênus
        transform.GetPos()->x = 2;
        transform.GetPos()->z = 20;
        venus_texture.Bind();
        venus.Draw();
        shader.Bind();
        shader.Update(transform, camera);
        glLoadIdentity();

        //terra
        transform.GetPos()->x = 10;
        transform.GetPos()->z = 25;
        earth_texture.Bind();
        earth.Draw();
        shader.Bind();
        shader.Update(transform, camera);
        glLoadIdentity();

        //marte
        transform.GetPos()->x = -7;
        transform.GetPos()->z = 15;
        mars_texture.Bind();
        mars.Draw();
        shader.Bind();
        shader.Update(transform, camera);
        glLoadIdentity();

       /* //urano
        transform.GetPos()->x = -9;
        transform.GetPos()->z = 15;
        uranus_texture.Bind();
        uranus.Draw();
        shader.Bind();
        shader.Update(transform, camera);
        glLoadIdentity();*/

        display.SwapBuffers();
        SDL_Delay(1);
        counter += 0.01f;
    }

    return 0;
}