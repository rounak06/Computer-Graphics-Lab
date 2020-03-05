#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<stdlib.h>

int INSIDE=0;
int LEFT=1;
int RIGHT=2;
int BOTTOM=4;
int TOP=8;
float x_min,x_max,y_max,y_min;


void draw_line(float x1,float y1,float x2,float y2,float color)
{
   
   glPointSize(2.0f);
    glBegin(GL_LINES);
    if(color==1)
    {
         glColor3f(1.0, 0.0, 0.0);
    }

    if(color==3)
    {
        glColor3f(0.0,0.0,1.0);
    }
 
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);

    glEnd();   
   glFlush();  // Render now
}

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
   glClear(GL_COLOR_BUFFER_BIT); 
   gluOrtho2D(-250,250,-250,250);

}

int compute_code(float x,float y)
{
    int code = INSIDE;

    if(x<x_min)
    {
        code=code|LEFT;
    }

    if(x>x_max)
    {
        code|=RIGHT;
    }

    if(y<y_min)
    {
        code|=BOTTOM;
    }

    if(y>y_max)
    {
        code|=TOP;
    }

    return code;
} 

void cohen(float a1,float a2,float b1,float b2){
  int acode,bcode;
    acode = compute_code(a1,a2);
    bcode = compute_code(b1,b2);

    bool accept = false;
    
    while(true)
    {
       
        if(acode==0 && bcode==0)
        {
            accept=true;
            break;
        }else if(acode & bcode)
        {
            break;
        }else
        {
            double x,y;
            int code_out;
            if(acode!=0)
            {
                code_out=acode;
            }else
            {
                code_out=bcode;
            }

            if(code_out & LEFT)
            {
                x=x_min;
                y=((b2-a2)/(b1-a1))*(x-b1) + b2;
              
            }

            if(code_out & RIGHT)
            {
                x=x_max;
                y=((b2-a2)/(b1-a1))*(x-b1) + b2;
            }

            if(code_out & TOP)
            {
                y=y_max;
                x=((b1-a1)/(b2-a2))*(y-b2) + b1;
            }

            if(code_out & BOTTOM)
            {
                y=y_min;
                x=((b1-a1)/(b2-a2))*(y-b2) + b1;
            }

           
            
            if(code_out==acode)
            {
                a1=x;
                a2=y;
                acode=compute_code(a1,a2);
            }else if(code_out==bcode)
            {
                b1=x;
                b2=y;
                bcode=compute_code(b1,b2);
            }
            
        }
    }
   
   if(accept)
   {
       draw_line(a1,a2,b1,b2,3);
   }

}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);        

   x_min=-100;
   x_max=100;
   y_min=-100;
   y_max=100;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2i(x_min,y_min);
        glVertex2i(x_max,y_min);
        glVertex2i(x_max,y_max);
        glVertex2i(x_min,y_max);
    glEnd();
    glFlush();

   printf("contrained xmin=-100, xmax=100, ymin=-100,ymax=100\n");
   printf("Enter the end points of a triangle:\n");
   float a1,a2,b1,b2,c1,c2;
   scanf("%f %f",&a1,&a2);
    scanf("%f %f",&b1,&b2);
    scanf("%f %f",&c1,&c2);

    // draw_line(a1,a2,b1,b2,1);
    // draw_line(b1,b2,c1,c2,1);
    // draw_line(c1,c2,a1,a2,1);
    glFlush();
    cohen(a1,a2,b1,b2);
    cohen(b1,b2,c1,c2);
    cohen(c1,c2,a1,a2);
    

   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutInitWindowSize(500, 500);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("DDA algorithm"); // Create a window with the given title
   initGL();
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop
   return 0;
}