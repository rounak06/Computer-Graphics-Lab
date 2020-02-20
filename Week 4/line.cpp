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


void line_bresenham(int X1, int Y1, int X2, int Y2)
{
    int incx, incy, inc1, inc2;
    int x, y;
    int dx, dy;
    dx = X2 - X1;
    dy = Y2 - Y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (X2 < X1)
        incx = -1;
    incy = 1;
    if (Y2 < Y1)
        incy = -1;
    x = X1;
    y = Y1;

    int fraction, i;
    int fractionIncrement1;
    int fractionIncrement2;
    if (dx > dy)
    {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        fraction = 2 * dy - dx;
        fractionIncrement1 = 2 * (dy - dx);
        fractionIncrement2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (fraction >= 1)
            {
                y += incy;
                fraction += fractionIncrement1;
            }
            else
                fraction += fractionIncrement2;
            x += incx;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }

    else
    {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        fraction = 2 * dx - dy;
        fractionIncrement1 = 2 * (dx - dy);
        fractionIncrement2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (fraction >= 1)
            {
                x += incx;
                fraction += fractionIncrement1;
            }
            else
                fraction += fractionIncrement2;
            y += incy;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }
}

void draw_line()
{
    vector<pair<float,float>> v;

    int x1,y1,x2,y2;
    printf("Please enter the co ordinates of the first point:\n");
    scanf("%d %d",&x1,&y1);
    v.push_back(make_pair(x1,y1));
    printf("Please enter the co ordinates of the second point:\n");
    scanf("%d %d",&x2,&y2);
    v.push_back(make_pair(x2,y2));

    line_bresenham(v[0].first, v[0].second,v[1].first, v[1].second);
 
    glFlush();
    printf("Please take one of the following choices:\n1. Translation\n2. Rotation\n3. Scaling\n");
    int choice;
    scanf("%d",&choice);
    
    if(choice==1)
    {
                int direction,fx,fy;
                pair<int,int> translate;
                printf("Enter the translation factor in x and y direction\n");
                scanf("%d %d",&fx,&fy);
                translate = (make_pair(fx,fy));


                for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first + translate.first;
                   v[size].second=v[size].second + translate.second;
                }

                printf("point 1 after translation %d  %d\npoint 2 after translation%d    %d\n",v[0].first, v[0].second,v[1].first, v[1].second);
            line_bresenham(v[0].first, v[0].second,v[1].first, v[1].second);


    }else if(choice==2)
    {
        //Rotation
        printf("How many degrees do you want to rotate:\n");
                    float degree;
                    vector<pair<float,float>> rotationmatrix;
                    scanf("%f",&degree);
                    rotationmatrix.push_back(make_pair(cos(3.14*degree/180),-sin(3.14*degree/180)));
                    rotationmatrix.push_back(make_pair(sin(3.14*degree/180),cos(3.14*degree/180)));
                    
                    float x;

                    printf("%f   %f\n", rotationmatrix[0].first,rotationmatrix[0].second);

                    printf("%f   %f\n", rotationmatrix[1].first,rotationmatrix[1].second);
                    for(int size=0;size<v.size();size++)
	                {  
                        x=v[size].first;
                        v[size].first = v[size].first*rotationmatrix[0].first + v[size].second*rotationmatrix[0].second;
                        v[size].second = x*rotationmatrix[1].first + v[size].second*rotationmatrix[1].second;
                    }
line_bresenham(v[0].first, v[0].second,v[1].first, v[1].second);

        // glBegin(GL_LINES);
        //     glVertex2i(v[0].first, v[0].second);
        //     glVertex2i(v[1].first, v[1].second);
        // glEnd();
        
    }else if(choice==3)
    {
        //Scaling
        printf("Enter the scaling factor:\n");
        float s;
        scanf("%f",&s);
        for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first*s;
                   v[size].second=v[size].second*s;
                }
                line_bresenham(v[0].first, v[0].second,v[1].first, v[1].second);

        //  glBegin(GL_LINES);
        //             glVertex2i(v[0].first, v[0].second);
        //             glVertex2i(v[1].first, v[1].second);
        // glEnd();
    }
}





void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);

   
   draw_line();


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