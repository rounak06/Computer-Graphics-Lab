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
   gluOrtho2D(-200,1200,-200,1200);
   glFlush();
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

void draw_polygon()
{
    vector<pair<int,int>> v;
    printf("Enter the number of vertices:\n");
    int vertices;
    scanf("%d",&vertices);

    printf("Please enter the vertices sequentially:\n");
    for(int i=0;i<vertices;i++)
    {
        int a,b;
        pair<int,int> p;
        scanf("%d %d",&a,&b);
        p = make_pair(a,b);
        v.push_back(p);
    }

    // glBegin(GL_POLYGON);
        for(int i=0;i<vertices-1;i++)
        {
            line_bresenham(v[i].first, v[i].second,v[i+1].first, v[i+1].second);
            // glVertex2i(v[i].first,v[i].second);
        }
        line_bresenham(v[vertices-1].first, v[vertices-1].second,v[0].first, v[0].second);
    // glEnd();
    glFlush();
    printf("Please take one of the following choices:\n1. Translation\n2. Rotation\n3. Scaling\n4.Reflection about x and y axis\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: {
            int fx,fy;
                pair<int,int> translate;
                printf("Enter the translation factor in x and y direction\n");
                scanf("%d %d",&fx,&fy);
                translate = (make_pair(fx,fy));

                for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first + translate.first;
                   v[size].second=v[size].second + translate.second;
                }

                // glBegin(GL_POLYGON);
                // for(int i=0;i<vertices;i++)
                // {
                //        glVertex2i(v[i].first,v[i].second);
                // }
                // glEnd();

                for(int i=0;i<vertices-1;i++)
        {
            line_bresenham(v[i].first, v[i].second,v[i+1].first, v[i+1].second);
            // glVertex2i(v[i].first,v[i].second);
        }
        line_bresenham(v[vertices-1].first, v[vertices-1].second,v[0].first, v[0].second);
                glFlush();
                
                break;
        }
        case 2: {
                    printf("How many degrees do you want to rotate:\n");
                    float degree;
                    vector<pair<float,float>> rotationmatrix;
                    scanf("%f",&degree);
                    rotationmatrix.push_back(make_pair(cos(3.14*degree/180),-sin(3.14*degree/180)));
                    rotationmatrix.push_back(make_pair(sin(3.14*degree/180),cos(3.14*degree/180)));
                    float x;
                    for(int size=0;size<v.size();size++)
	                {
                        x=v[size].first;
                        v[size].first = v[size].first*rotationmatrix[0].first + v[size].second*rotationmatrix[0].second;
                        v[size].second = x*rotationmatrix[1].first + v[size].second*rotationmatrix[1].second;
                    }

                    // glBegin(GL_POLYGON);
                    // for(int i=0;i<vertices;i++)
                    // {
                    //    glVertex2i(v[i].first,v[i].second);
                    // }

                    for(int i=0;i<vertices-1;i++)
        {
            line_bresenham(v[i].first, v[i].second,v[i+1].first, v[i+1].second);
            // glVertex2i(v[i].first,v[i].second);
        }
        line_bresenham(v[vertices-1].first, v[vertices-1].second,v[0].first, v[0].second);
                    // glEnd();
                    glFlush();
                    break;
                }
        case 3: {
                printf("Enter the scaling factor in x and y:\n");
                int sx,sy;
                scanf("%d %d",&sx,&sy);

                for(int size=0;size<v.size();size++)
	            {
                   v[size].first=v[size].first*sx;
                   v[size].second=v[size].second*sy;
                }

                // glBegin(GL_POLYGON);
                // for(int i=0;i<vertices;i++)
                // {
                //        glVertex2i(v[i].first,v[i].second);
                // }
                // glEnd();

                for(int i=0;i<vertices-1;i++)
        {
            line_bresenham(v[i].first, v[i].second,v[i+1].first, v[i+1].second);
            // glVertex2i(v[i].first,v[i].second);
        }
        line_bresenham(v[vertices-1].first, v[vertices-1].second,v[0].first, v[0].second);
                glFlush();
                break;        
                }
        case 4:
        {
            vector <pair<int,int>> xreflection,yreflection;

            xreflection.push_back(make_pair(1,0));
            xreflection.push_back(make_pair(0,-1));

            yreflection.push_back(make_pair(-1,0));
            yreflection.push_back(make_pair(0,1));
                    glBegin(GL_POLYGON);
                    for(int i=0;i<vertices;i++)
                    {
                       glVertex2i(v[i].first*xreflection[0].first + v[i].second*xreflection[0].second,
                       v[i].first*xreflection[1].first + v[i].second*xreflection[1].second);
                    }
                    glEnd();
                    glFlush();

                    glBegin(GL_POLYGON);
                    for(int i=0;i<vertices;i++)
                    {
                       glVertex2i(v[i].first*yreflection[0].first + v[i].second*yreflection[0].second,
                       v[i].first*yreflection[1].first + v[i].second*yreflection[1].second);
                    }
                    glEnd();
                    glFlush();
            break;
        }
                
        
    }

    return;
}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
draw_polygon();


   glFlush();  
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("2d translation");       // Create a window with the given title
   initGL();                     // Our own OpenGL initialization
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 