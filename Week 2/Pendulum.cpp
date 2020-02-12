#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   gluOrtho2D(0,400,0,400);
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
   
   int xc,yc,r;
   printf("Enter the co-ordinates of the center:");
   scanf("%d %d",&xc,&yc);
   printf("Enter the radius of the circle");
   scanf("%d",&r);
  
   int d,x,y;
   x=0;
   y=r;
   d = 3-2*r;
   
   glBegin(GL_POINTS);
   glColor3f(1.0, 0.0, 0.0);

   while(y >= x)
    {
        if(d<=0)
        {
            x = x+1;
            d = d + 4*x + 6;
        }else if(d>0)
        {
            x = x+1;
            y = y-1;
            d = d + 4*(x-y) +10;
        }
       
        glVertex2i(xc+x, yc+y); 
        glVertex2i(xc-x, yc+y); 
        glVertex2i(xc+x, yc-y); 
        glVertex2i(xc-x, yc-y); 
        glVertex2i(xc+y, yc+x); 
        glVertex2i(xc-y, yc+x); 
        glVertex2i(xc+y, yc-x); 
        glVertex2i(xc-y, yc-x);

    }
   
   glEnd();
   
   int k=0;
   glBegin(GL_POINTS);
   for(int i=0;i<=r;i++)   
   {
       glColor3f(0.0, 0.0, 1.0);
       glVertex2i(xc,yc+r+k);
       k++;
   }
   glEnd();

   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(50, 50);          // Position the window's initial top-left corner
   glutCreateWindow("Circle using Bresenham");       // Create a window with the given title
   initGL();
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutMainLoop();                          // Enter the event-processing loop
   return 0;
}