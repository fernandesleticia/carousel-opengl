//
// Created by leticia on 10/12/18.
//

#ifndef CG_2018_2_OPENGL_DISPLAY_H
#define CG_2018_2_OPENGL_DISPLAY_H

#include <string>
#include <SDL2/SDL.h>

class Display
{
public:
    Display(int width, int height, const std::string& title);

    void Clear(float r, float g, float b, float a);
    void SwapBuffers();

    virtual ~Display();
protected:
private:
    void operator=(const Display& display) {}
    Display(const Display& display) {}

    SDL_Window* m_window;
    SDL_GLContext m_glContext;
};

#endif //CG_2018_2_OPENGL_DISPLAY_H
