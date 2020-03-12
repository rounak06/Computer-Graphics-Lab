#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   gluOrtho2D(-250,250,-250,250);
}

void draw_triangle(float x1,float y1,float x2,float y2,float x3,float y3)
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    glEnd();
    glFlush();
}



void recurse_triangle(float x1,float y1,float x2,float y2,float x3,float y3,int recurse)
{

    if(recurse==0)
    {
        return;
    }

    recurse--;
    

    draw_triangle((x1+x2)/2,(y1+y2)/2,(x2+x3)/2,(y2+y3)/2,(x1+x3)/2,(y1+y3)/2);

    recurse_triangle(x1,y1,(x1+x2)/2,(y1+y2)/2,(x1+x3)/2,(y1+y3)/2,recurse);
    recurse_triangle((x1+x2)/2,(y1+y2)/2,x2,y2,(x2+x3)/2,(y2+y3)/2,recurse);
    recurse_triangle((x1+x3)/2,(y1+y3)/2,(x2+x3)/2,(y2+y3)/2,x3,y3,recurse);

    return;
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    printf(" length of the triangle:\n");
    int length;
    scanf("%d",&length);
    float x1,y1,x2,y2,x3,y3;
    
    x1=0;
    y1=0;
    x2=length;
    y2=0;
    x3=length/2;
    y3=(sqrt(3)*length)/2;

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
    glEnd();
    glFlush();

    printf("No of times you want the recursion to go ahead:\n");
    int recurse;
    scanf("%d",&recurse);

    recurse_triangle(x1,y1,x2,y2,x3,y3,recurse);

    glColor3f( 0.0, 1.0, 0.0 );

    glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitWindowSize(500, 500);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("recursive triangle"); // Create a window with the given title
   initGL();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}