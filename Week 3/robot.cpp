#include <stdio.h>
#include <GL/glut.h>
#include <math.h>


float angle=0.0;
float xpos = 0.0;
int direction = 1;
int scale=0;
int scalepos=0;
int seen=0;

static GLfloat spin = 0.0;
static GLfloat spin_speed = 0.0004;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;


void reset()
{
    spin_x = 0;
    spin_y = 1;
    spin_z = 0;
}
//------- custom functions starts -------
void setSpin(float x, float y, float z)
{
    spin_x = x;
    spin_y = y;
    spin_z = z;
}

void spinDisplay(void)
{
    spin=spin+spin_speed;
    if(spin>360.0)
    {
        spin=spin-360.0;
    }
    glutPostRedisplay();
}

int max(int a, int b)
{
    return a >= b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void initialize()
{
    glClearColor(0, 0, 0, 1);
    glVertex3f(0, 1, 0);
    glPointSize(1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-500, 500, -500, 500);
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

void plotPoints(int x,int y,int p,int q){
    glBegin(GL_POINTS);
        glVertex2i(x+p, y+q);
        glVertex2i(x+p, -y+q);
        glVertex2i(-x+p, -y+q);
        glVertex2i(-x+p, y+q);
        glVertex2i(y+p, x+q);
        glVertex2i(-y+p, x+q);
        glVertex2i(y+p, -x+q);
        glVertex2i(-y+p, -x+q);
    glEnd();
}

void plot4Points(int x,int y,int p,int q){
    glBegin(GL_POINTS);
        glVertex2i(x+p, y+q);
        glVertex2i(-x+p, y+q);
        glVertex2i(y+p, x+q);
        glVertex2i(-y+p, x+q);
    glEnd();
}

void circle_bresenham(int X1, int Y1, int R)
{   
    int p,q,x,y,r,d;
    p = X1,q = Y1;
    r = R;
    d = 3 - 2*r;
    x = 0;
    y = r;
    while(x<y){
        plotPoints(x,y,p,q);
        if(d<0){
            d = d+4*x+6;
            x++;
        }else{
            d = d + 4*(x-y) + 10;
            x++;
            y--;
        }
    }
}
void drawBresenhamHalfCircle(int X1, int Y1, int R)
{   
    int p,q,x,y,r,d;
    p = X1,q = Y1;
    r = R;
    d = 3 - 2*r;
    x = 0;
    y = r;
    while(x<y){
        plot4Points(x,y,p,q);
        if(d<0){
            d = d+4*x+6;
            x++;
        }else{
            d = d + 4*(x-y) + 10;
            x++;
            y--;
        }
    }
}



void idle(){
    glutPostRedisplay();
}

void drawBresenhamPattern()
{



    // 

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(xpos,0,0);
  // glRotatef(angle, 0, 0,1.0f);
    glPushMatrix();
    // glTranslatef(translate_x, translate_y, translate_z);
    
  circle_bresenham(-35-scale,100+scale,20+scale);
  glPopMatrix();
  line_bresenham(-120-scale,50+scale,120+scale,50+scale);

  line_bresenham(-120-scale,30+scale,120+scale,30+scale);
  line_bresenham(-120-scale,-100-scale,-90-scale,-100-scale);
  line_bresenham(120+scale,-100-scale,90+scale,-100-scale);
  line_bresenham(-35-scale,-100-scale,35+scale,-100-scale);

  line_bresenham(-120-scale,-100-scale,-120-scale,30+scale);
  line_bresenham(120+scale,-100-scale,120+scale,30+scale);


  line_bresenham(-35-scale,-100-scale,-35-scale,-300-scale);
  line_bresenham(35+scale,-100-scale,35+scale,-300-scale);

  line_bresenham(-90-scale,-300-scale,-35-scale,-300-scale);
  line_bresenham(90+scale,-300-scale,35+scale,-300-scale);

  line_bresenham(-90-scale,-300-scale,-90-scale,-100-scale);
  line_bresenham(90+scale,-300-scale,90+scale,-100-scale);

//hands

  glPushMatrix();

  glRotatef(spin,spin_x,spin_y,spin_z);

  line_bresenham(-130-scale,-100-scale,-130-scale,30+scale);
  line_bresenham(130+scale,-100-scale,130+scale,30+scale);


  line_bresenham(-130-scale,30+scale,-150-scale,30+scale);
  line_bresenham(130+scale,30+scale,150+scale,30+scale);

  line_bresenham(-130-scale,-100-scale,-150-scale,-100-scale);
  line_bresenham(130+scale,-100-scale,150+scale,-100-scale);

  line_bresenham(-150-scale,-100-scale,-150-scale,30+scale);
  line_bresenham(150+scale,-100-scale,150+scale,30+scale);
    glPopMatrix();

  circle_bresenham(35+scale,100+scale,20+scale);
  drawBresenhamHalfCircle(0,50+scale,120+scale);

    glPopMatrix();
    glFlush();
    
    // if(direction){
    //     xpos+=0.1;
    //     angle-=0.04;
    // }else{
    //     xpos-=0.1;
    //     angle+=0.04;
    // }
    // // printf("%f\n",xpos);
    // if(xpos>=300)
    //     direction = 0;
    // else if(xpos<=-300)
    //     direction = 1;
}
void keyboard(unsigned char key, int x, int y)
{
    
   if(key=='i')
    {
        scale++;
        glutPostRedisplay();
    }
    else if(key=='d')
    {
        scale--;
        glutPostRedisplay();
    }
    //-------- zoom --------
    //-------- reset -------
    else if(key=='s')
    {
        spin=0;
        spin_speed=0;
        drawBresenhamPattern();
        glutPostRedisplay();
    }
    else if(key=='t')
    {
        xpos+=2;
        glutPostRedisplay();
    }
    else if(key=='h')
    {
        xpos-=2;
        glutPostRedisplay();
    }
    else if(key=='c')
    {
        seen=1;
        glutPostRedisplay();
    }
    else if(key=='e')
    {
        exit(0);
    }
    else if(key=='r')
    {
        glutIdleFunc(spinDisplay);
        // angle+=.04;
        glutPostRedisplay();
    }
}


void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
   glClear(GL_COLOR_BUFFER_BIT);    

   if(seen==0)     
   drawBresenhamPattern();
    else{
        glFlush();
    }
   
   glFlush();  
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 0);

    glutCreateWindow("Bresenham Circle algorithm");

    initialize();
    glutDisplayFunc(display);
    // glutDisplayFunc(drawBresenhamPattern);
    glutIdleFunc(idle);
   // glutMouseFunc(mouse);

    glutKeyboardFunc(keyboard);
   // glutTimerFunc(0, Timer, 0);
    glutMainLoop();
}