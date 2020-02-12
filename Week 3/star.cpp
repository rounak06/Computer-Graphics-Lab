#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>

int side_length=20;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(0,400,400,0);
}

void draw(int xpos,int ypos)
{
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(xpos,ypos);
        glVertex2i(xpos+side_length,ypos);
        glVertex2i((xpos+side_length+xpos)/2,ypos+side_length);
   glEnd();
   
   glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(xpos,(ypos+ypos+side_length)/2);
        glVertex2i(xpos+side_length,(ypos+ypos+side_length)/2);
        glVertex2i((xpos+side_length+xpos)/2,(ypos+ypos+side_length)/2-side_length);
   glEnd();
   
   glFlush();  

}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
   
   
   glFlush();  
}
 
// void specialKeys(int key, int x, int y) {
//     switch (key) {
//         case GLUT_KEY_F1:   
//             side_length+=2;
//             break;

//         case GLUT_KEY_F2:
//             side_length-=2;
//             break;  
//    }
// }

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        exit(0);
        return;
    }
   
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        printf("%d %d\n",x,y);
        draw(x,y);
    }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("Transformation");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   // glutSpecialFunc(specialKeys);
   glutMouseFunc(mouse);
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 


// GLUT_KEY_F1
// F1 function key.
// GLUT_KEY_F2
// F2 function key.
// GLUT_KEY_F3
// F3 function key.
// GLUT_KEY_F4
// F4 function key.
// GLUT_KEY_F5
// F5 function key.
// GLUT_KEY_F6
// F6 function key.
// GLUT_KEY_F7
// F7 function key.
// GLUT_KEY_F8
// F8 function key.
// GLUT_KEY_F9
// F9 function key.
// GLUT_KEY_F10
// F10 function key.
// GLUT_KEY_F11
// F11 function key.
// GLUT_KEY_F12
// F12 function key.
// GLUT_KEY_LEFT
// Left directional key.
// GLUT_KEY_UP
// Up directional key.
// GLUT_KEY_RIGHT
// Right directional key.
// GLUT_KEY_DOWN
// Down directional key.
// GLUT_KEY_PAGE_UP
// Page up directional key.
// GLUT_KEY_PAGE_DOWN
// Page down directional key.
// GLUT_KEY_HOME
// Home directional key.
// GLUT_KEY_END
// End directional key.
// GLUT_KEY_INSERT
// Inset directional key.