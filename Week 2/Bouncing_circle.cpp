#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>

int xc=50,yc=50,r=50;
int movingup=1,movinfdown=0;
int h1=50,h2=200,h3=300,h4=350;
int bouncecount=0;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   gluOrtho2D(0,1400,0,400);
}

void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(30, Timer, 0); // next Timer call milliseconds later
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         
 
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

    if(movingup)
    {
        if(yc<h4)
        {
            if(yc<h4 && yc>h2)
            {
                if(yc>h2 && yc<h3)
                {
                    yc+=2;
                    xc+=1;
                }else
                {
                    yc+=1;
                    xc+=2;
                }
            }else
            {
                yc+=3;
                xc+=1;
            }
            movingup=1;
            movinfdown=0;
        }else
        {
            movinfdown=1;
            movingup=0;
        }
    }else if(movinfdown)
    {
        if(yc>h1)
        {
            if(yc>h1 && yc<h2)
            {
                yc-=3;
                xc+=1;
            }else
            {
                if(yc>h2 && yc<h3)
                {
                    yc-=2;
                    xc+=2;
                }else
                {
                    yc-=1;
                    xc+=3;
                }
            }
            movinfdown=1;
            movingup=0;
        }else
        {
            if(h1>=20)
            {
                h1-=20;
            }
            
            if(h2>=40)
            {
                h2-=40;
            }

            if(h3>=60)
            {
                h3-=60;
            }

            if(h4>=80)
            {
                h4-=80;
            }

            
            movinfdown=0;
            movingup=1;
        }
    }

   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(1400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("Circle using Bresenham");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutTimerFunc(0, Timer, 0);   // First timer call immediately
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}