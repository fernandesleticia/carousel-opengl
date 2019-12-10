//
// Created by leticia.
//

#ifndef CG_2018_2_OPENGL_CAMERA_H
#define CG_2018_2_OPENGL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const GLfloat YAW        = -90.0f;
const GLfloat PITCH      =  0.0f;
const GLfloat SPEED      =  6.0f;
const GLfloat SENSITIVTY =  0.25f;
const GLfloat ZOOM       =  45.0f;

struct Camera
{
public:
    Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar, GLfloat yaw = YAW, GLfloat pitch = PITCH)
    {
        this->pos = pos;
        this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
        this->up = glm::vec3(1.0f, 2.0f, 0.0f);
        this->projection = glm::perspective(fov, aspect, zNear, zFar);
        this->yaw = yaw;
        this->pitch = pitch;
        this->updateCameraVectors( );
    }

    inline glm::mat4 GetViewProjection() const
    {
        return projection * glm::lookAt(pos, pos + forward, up);
    }

    inline glm::mat4 GetProjection() const
    {
        return projection;
    }

    void MoveForward(float amt)
    {
    	pos += forward * amt;
    }

    void MoveRight(float amt)
    {
    	pos += glm::cross(up, forward) * amt;
    }

    void Pitch(float angle)
    {
    	glm::vec3 right = glm::normalize(glm::cross(up, forward));

    	forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
    	up = glm::normalize(glm::cross(forward, right));
    }

    void RotateY(float angle)
    {
    	static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

    	glm::mat4 rotation = glm::rotate(angle, UP);

    	forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
    	up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
    }

     // Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard( Camera_Movement direction, GLfloat deltaTime )
    {
        GLfloat velocity = SPEED * deltaTime;
        
        if ( direction == FORWARD )
        {
            pos += forward * velocity;
        }
        
        if ( direction == BACKWARD )
        {
            pos -= forward * velocity;
        }
        
        if ( direction == LEFT )
        {
            pos -= glm::cross(up, forward) * velocity;
        }
        
        if ( direction == RIGHT )
        {
            pos += glm::cross(up, forward) * velocity;
        }
    }

      // Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement( GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = true )
    {
        xOffset *= SENSITIVTY;
        yOffset *= SENSITIVTY;

        this->yaw   += xOffset;
        this->pitch += yOffset;
        
        // Make sure that when pitch is out of bounds, screen doesn't get flipped
        if ( constrainPitch )
        {
            if ( this->pitch > 89.0f )
            {
                this->pitch = 89.0f;
            }
            
            if ( this->pitch < -89.0f )
            {
                this->pitch = -89.0f;
            }
        }
        
        // Update Front, Right and Up Vectors using the updated Eular angles
        this->updateCameraVectors( );
    }



protected:
private:
    glm::mat4 projection;
    glm::vec3 pos;
    glm::vec3 forward;
    glm::vec3 up;

    glm::vec3 right;

    // Eular Angles
    GLfloat yaw;
    GLfloat pitch;

     // Calculates the front vector from the Camera's (updated) Eular Angles
    void updateCameraVectors( )
    {
        // Calculate the new Front vector
        glm::vec3 front;
        front.x = cos( glm::radians( this->yaw ) ) * cos( glm::radians( this->pitch ) );
        front.y = sin( glm::radians( this->pitch ) );
        front.z = sin( glm::radians( this->yaw ) ) * cos( glm::radians( this->pitch ) );
        this->forward = glm::normalize( forward );
        // Also re-calculate the Right and Up vector
        this->right =  glm::normalize(glm::cross(up, forward));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        this->up = glm::normalize( glm::cross( this->right, this->forward ) );
    }
};


#endif //CG_2018_2_OPENGL_CAMERA_H
