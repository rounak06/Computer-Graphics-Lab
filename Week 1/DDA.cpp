#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<stdlib.h>
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */

float abs(float a)
{
    if(a>0)
    {
        return a;
    }else
    {
        return a*(float)(-1);
    }
}

float compare(float a,float b)
{
    if(abs(a)>abs(b))
    {
        return abs(a);
    }else
    {
        return  abs(b);
    }

}

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   gluOrtho2D(0,100,0,100);
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
   float x0,y0,x1,y1,dx,dy,steps,xinc,yinc,px,py;
   printf("Enter the First point:\n");
   scanf("%f%f",&x0,&y0);
   printf("Enter the Second point:\n");
   scanf("%f%f",&x1,&y1);

   dx = x1-x0;
   dy = y1-y0;

   steps = compare(dx,dy);

    xinc = dx/(float)steps;
    yinc = dy/(float)steps;
    printf("%f %f",xinc,yinc);

    px = x0;
    py = y0;

    glPointSize(2.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(px, py);
    for (float i = 0; i < steps; i++)
    {
        px+=xinc;
        py+=yinc;
        glVertex2f(px,py);
    }
    glEnd();  
    
    

   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitWindowSize(1300, 1300);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("DDA algorithm"); // Create a window with the given title
   initGL();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}