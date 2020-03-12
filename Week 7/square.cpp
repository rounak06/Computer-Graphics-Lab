#include<iostream>
#include <GL/glut.h>
#include<math.h>
using namespace std;
void display();
int N;
float xt1 , yt1 , xt2 , yt2 , xt3 , yt3 , xt4 ,yt4 ;
void myinit()
{
    glClearColor(0.0,0,0,0);
    gluOrtho2D(-250,250,-250,250);

}

void drawsquare(float x1 , float y1 , float x2 , float y2 , float x3 , float y3 , float x4 , float y4)
{
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();
    glFlush();
}
void recurse_square(float x1 , float y1 , float x2 , float y2 , float x3 , float y3 , float x4 , float y4 ,int n)
{

    if(n<=0)
    {

        drawsquare(x1,y1,x2,y2,x3,y3 , x4 ,y4);
        return ;
    }
     n--;
    
  float d = (x2-x1)/3;
  recurse_square(x1,y1,x1+d,y1,x1+d,y1+d,x1,y1+d,n);
  recurse_square(x1+d,y1,x1+2*d,y1,x1+2*d,y1+d,x1+d,y1+d,n);
  recurse_square(x1+2*d,y1,x2,y2,x2,y1+d,x1+2*d,y1+d,n);

  recurse_square(x1,y1+d,x1+d,y1+d,x1+d,y1+2*d,x1,y1+2*d,n);
  recurse_square(x1+2*d,y1+d,x2,y1+d,x2,y1+2*d,x1+2*d,y1+2*d,n);

  recurse_square(x1,y1+2*d,x1+d,y1+2*d,x1+d,y4,x4,y4,n);
  recurse_square(x1+d,y1+2*d,x1+2*d,y1+2*d,x1+2*d,y4,x1+d,y4,n);
  recurse_square(x1+2*d,y1+2*d,x2,y2+2*d,x3,y3,x1+2*d,y3,n);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    recurse_square(xt1 , yt1 , xt2 , yt2 , xt3 , yt3 , xt4 , yt4, N);

}

int main(int argc , char **argv)
{
    

    printf(" length of the square:\n");
    int length;
    scanf("%d",&length);

    xt1=0;
    yt1=0;
    xt2=length;
    yt2=0;
    xt3=length;
    yt3=length;
    xt4=0;
    yt4=length;

    cout<<"no of times \n";
    cin>>N;
    glutInit(&argc , argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   glutInitWindowSize(1000, 1000); 
   glutInitWindowPosition(0, 0); 
   glutCreateWindow("recurse_square square"); 
glutDisplayFunc(display);   

   myinit();
  
   glutMainLoop(); 


}

