//
// Created by leticia.
//

#ifndef CG_2018_2_OPENGL_TRANSFORM_H
#define CG_2018_2_OPENGL_TRANSFORM_H

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "camera.h"

struct Transform
{
public:
    Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
    {
        this->pos = pos;
        this->rot = rot;
        this->scale = scale;
    }

    inline glm::mat4 GetModel() const
    {
        glm::mat4 posMat = glm::translate(pos);
        glm::mat4 scaleMat = glm::scale(scale);
        glm::mat4 rotX = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
        glm::mat4 rotY = glm::rotate(rot.y, glm::vec3(0.0, 1.0, 0.0));
        glm::mat4 rotZ = glm::rotate(rot.z, glm::vec3(0.0, 0.0, 1.0));
        glm::mat4 rotMat = rotX * rotY * rotZ;

        return posMat * rotMat * scaleMat;
    }
    /*
    The Projection matrix is an orthographic matrix which will encompass everything in the axis-aligned box (-10,10),(-10,10),(-10,20) on the X,Y and Z axes respectively. These values are made so that our entire *visible *scene is always visible ; more on this in the Going Further section.
    The View matrix rotates the world so that in camera space, the light direction is -Z (would you like to re-read Tutorial 3 ?)
    The Model matrix is whatever you want.
    */

    inline glm::mat4 GetMVP(const Camera& camera) const
    {
        glm::mat4 VP = camera.GetViewProjection();
        glm::mat4 M = GetModel();

        return VP * M;//camera.GetViewProjection() * GetModel();
    }

    inline glm::vec3* GetPos() { return &pos; }
    inline glm::vec3* GetRot() { return &rot; }
    inline glm::vec3* GetScale() { return &scale; }

    inline void SetPos(glm::vec3& pos) { this->pos = pos; }
    inline void SetRot(glm::vec3& rot) { this->rot = rot; }
    inline void SetScale(glm::vec3& scale) { this->scale = scale; }


protected:
private:
    glm::vec3 pos;
    glm::vec3 rot;
    glm::vec3 scale;
};

#endif //CG_2018_2_OPENGL_TRANSFORM_H
