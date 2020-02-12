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
   gluOrtho2D(-50,50,-50,50);
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
   float x0,y0,steps,xinc,yinc,px,py;
   printf("Enter the First point:\n");
    scanf("%f %f",&x0,&y0);
    px = x0;
    py = y0;

    for(int i=0;i<=8;i++)
    {
        glPointSize(2.0f);
        glBegin(GL_POINTS);
        glColor3f(0.0, 0.0, 1.0);

        steps = 64;

        xinc = 0.375;
        yinc = 0;

        glVertex2f(px, py);
        for (float j = 0; j < steps; j++)
        {
            px+=xinc;
            py+=yinc;
            glVertex2f(px,py);
        }
        glEnd();
        py+=3;
        px=x0;
    }

    px=x0;
    py=y0;
    for(int i=0;i<=8;i++)
    {
        glPointSize(2.0f);
        glBegin(GL_POINTS);
        glColor3f(1.0, 0.0, 0.0);

        steps = 64;

        xinc = 0;
        yinc = 0.375;

        glVertex2f(px, py);
        for (float j = 0; j < steps; j++)
        {
            px+=xinc;
            py+=yinc;
            glVertex2f(px,py);
        }
        glEnd();
        py=y0;
        px+=3;
    }

    // for()
    // {
    //     glPointSize(2.0f);
    //     glBegin(GL_POINTS);
    //     glColor3f(0.0, 0.0, 1.0);
    //     dx = x1-x0;
    //     dy = y1-y0;

    //     steps = compare(dx,dy);

    //     xinc = dx/(float)steps;
    //     yinc = dy/(float)steps;

    //     px = x0;
    //     py = y0;
    //     glVertex2f(px, py);
    //     for (float i = 0; i < steps; i++)
    //     {
    //         px+=xinc;
    //         py+=yinc;
    //         glVertex2f(px,py);
    //     }   
    //     glEnd();  
    // }
    
    
    

   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitWindowSize(200, 200);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("DDA algorithm"); // Create a window with the given title
   initGL();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}