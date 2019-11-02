#include <iostream>
#include <GL/glut.h>


void drawRectangularRock(int left, int top, int size){

    int length;
    GLfloat col = 0.0;
    length = size / 8.0;

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            glColor3f(1.0, col, 0.0);
            glRecti(left+length*j, top-length*i, left+length*j+length ,top-length*i-length);
            if(col == 0.0){
                col = 1.0;
            }
            else{
                col = 0.0;
            }
        }
        if(col == 0.0){
            col = 1.0;
        }
        else{
            col = 0.0;
        }
    }

}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2i(180, 280);
    glVertex2i(200, 280);
    glVertex2i(220, 280);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(100, 250);
    glVertex2i(300, 250);
    glEnd();
    glRecti(350, 250, 550, 100);
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 300);
    glVertex2i(300, 300);
    glVertex2i(200, 500);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 175);
    glVertex2i(150, 100);
    glVertex2i(250, 100);
    glVertex2i(300, 175);
    glVertex2i(200, 250);
    glEnd();
    drawRectangularRock(350, 500, 200);
    glBegin(GL_POLYGON);
    glColor3f(1,0,0); glVertex3i(100, 500, 0.5);
    glColor3f(0,1,0); glVertex3i(300, 500, 0);
    glColor3f(0,0,1); glVertex3i(200, 625, 0);
    glEnd();
    glFlush();

}

void myinit(){
    glClearColor(0.0, 0.0, 0.0, 0.1);
    glColor3f(0.1, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 650.0, 0.0, 650.0);
}

void myKeyboard(unsigned char key, int mouseX, int mouseY){
    switch (key){
        case 27:
            exit(0);
    }
}

int main(int argc, char**argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CG 2018");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    myinit();
    glutMainLoop();
    return 0;
}