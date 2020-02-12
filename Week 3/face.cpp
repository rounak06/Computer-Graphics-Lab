#include <GL/glut.h> 
#include<stdio.h>
#include<stdlib.h>

int direction=1;
float angle=0;
int scale=0;
int scalepos=0;

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   gluOrtho2D(0,400,400,0);
}

void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   
   if(direction)
   {
       angle+=5;
   }else
    {
        angle-=5;
    }

   glutTimerFunc(30, Timer, 0); // next Timer call milliseconds later
}

void draw_circle(int xc,int yc,int r)
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
   

    return ;

}

void draw_semi_circle(int xc,int yc,int r)
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
        
        
        glVertex2i(xc+y, yc+x); 
        glVertex2i(xc-y, yc+x); 
       
     

    }
   
   glEnd();
   

    return ;

}

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);         

   draw_circle(200+scalepos,200,80+scale);

   draw_circle(170+scalepos,180,20+scale);

   draw_circle(230+scalepos,180,20+scale);
   
   glPushMatrix();
   glTranslatef(170.0f+scalepos,190.0f,0.0f);
   glRotatef(angle,0.0f,0.0f,1.0f);
   draw_circle(0,0,10+scale);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(230.0f+scalepos,190.0f,0.0f);
   glRotatef(angle,0.0f,0.0f,1.0f);
   draw_circle(0,0,10+scale);
   glPopMatrix();

   draw_circle(200+scalepos,200,5+scale);

   draw_semi_circle(200+scalepos,240,20+scale);

   glFlush();  
}
 
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:   
            direction=1;
            break;

        case GLUT_KEY_F2:
            direction=0;
            break;

        case GLUT_KEY_F3:
            scale+=5;
            break;

        case GLUT_KEY_F4:
            scale-=5;
            break;

        case GLUT_KEY_F5:
            scalepos+=5;
            break;

        case GLUT_KEY_F6:
            scalepos-=5;
            break;

        case GLUT_KEY_F7:
            scalepos=0;
            scale=0;
            break;              
   }
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                   // Initialize GLUT
   glutInitWindowSize(400, 400);          // Set the window's initial width & height
   glutInitWindowPosition(0, 200);          // Position the window's initial top-left corner
   glutCreateWindow("Face");       // Create a window with the given title
   glutDisplayFunc(display);                // Register display callback handler for window re-paint
   glutSpecialFunc(specialKeys);
   glutTimerFunc(0, Timer, 0);  
   initGL();                     // Our own OpenGL initialization
   glutMainLoop();               // Enter event-processing loop
   return 0;
}

// glTranslatef(0.2f, -0.3f, 0.0f);     
// glRotatef(180.0f, 0.0f, 0.0f, 1.0f); 