#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<iostream>
#include <math.h> 

using namespace std; 

#define PI 3.14159265
vector<vector<pair<int,int>>> objectmatrix;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(-200,200,-200,200);
}

void draw_circle_sub(int xc,int yc,int r)
{
     int x,y,d;
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
   glFlush();
   return;
}

void draw_circle()
{
    int xc,yc,r;
    printf("Please enter the co ordinates of the center:\n");
    scanf("%d %d",&xc,&yc);
    printf("Please enter the radius:\n");
    scanf("%d",&r);
    draw_circle_sub(xc,yc,r);

    printf("Pick one of the following options:\n1. Translation\n2. Scaling\n");
    int choice;
    scanf("%d",&choice);
    
    if(choice==1)
    {
                int fx,fy;
                pair<int,int> translate;
                printf("Enter the translation factor in x and y direction\n");
                scanf("%d %d",&fx,&fy);
                translate = (make_pair(fx,fy));
                xc = xc+translate.first;
                yc = yc + translate.second;

                draw_circle_sub(xc,yc,r);
    }else if(choice ==2)
    {
                float sr;
                printf("Enter the scaling factor of the radius:\n");
                scanf("%f",&sr);
                printf("%f\n",sr);
                r = r*sr;

                printf("%d\n",r);
                draw_circle_sub(xc,yc,r);
    }

    return ;
}



void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);

   draw_circle();
   glFlush();  
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("2d translation");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 