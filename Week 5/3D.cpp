#include<GL/glut.h>
#include<string.h>
#include<cmath>
#include<stdio.h>
#include<iostream>
#define PI 3.14159265

using namespace std;
float orignal_cube[8][4]={{-40,40,40,1},{40,40,40,1},{40,40,-40,1},{-40,40,-40,1},{-40,-40,40,1},{40,-40,40,1},{40,-40,-40,1},{-40,-40,-40,1}};
float tx=0, ty=0, tz=0;
float Sx = 0, Sy=0, Sz;
float qx,qy,qz;
float orignal_cube1[8][4]={{-40,40,40,1},{40,40,40,1},{40,40,-40,1},{-40,40,-40,1},{-40,-40,40,1},{40,-40,40,1},{40,-40,-40,1},{-40,-40,-40,1}};

void Draw(float Cube[8][4])
{
  glClear(GL_COLOR_BUFFER_BIT);//clearing Screen

  glBegin(GL_QUADS);

  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);//back surface
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);

  glColor3f(0, 1.0, 0);
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);//bottom surface
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);

  glColor3f(0, 0, 1.0);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//left surface
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);
  glVertex3f(Cube[7][0],Cube[7][1],Cube[7][2]);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);

  glColor3f(1.0, 1.0, 0);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//front surface
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[4][0],Cube[4][1],Cube[4][2]);

  glColor3f(1.0, 0.0, 0);
  glVertex3f(Cube[0][0],Cube[0][1],Cube[0][2]);//top surface
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);
  glVertex3f(Cube[3][0],Cube[3][1],Cube[3][2]);

  glColor3f(0.0, 0.980, 0.604);
  glVertex3f(Cube[1][0],Cube[1][1],Cube[1][2]);//right surface
  glVertex3f(Cube[5][0],Cube[5][1],Cube[5][2]);
  glVertex3f(Cube[6][0],Cube[6][1],Cube[6][2]);
  glVertex3f(Cube[2][0],Cube[2][1],Cube[2][2]);

  glEnd();
  glFlush();
}



void showOption()
{
    cout<<"Choose the transformation:";
    cout<<"\t\n1. Translation: l(left) r(right) u(up) d(down)";
    cout<<"\t\n2. Rotation: x y z";
    cout<<"\t\n3. Scaling: s(scale up)  t(scale down)";
    cout<<"\t\n4. Orignal: o";
}

void mul(float a[][4], float b[][4], float c[][4])
{
  int i,j,k;
  float sum;
  for (i = 0; i <1; i++) {
      for (j = 0; j < 4; j++) {
         sum = 0;
         for (k = 0; k < 4; k++) {
            sum = sum + a[i][k] * b[k][j];
         }
         c[i][j] = sum;
      }
   }
}

void modify(float mul_matrix[][4])
{
  float resultant_matrix[][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
  for(int i = 0; i< 8; i++)
    mul(orignal_cube+i,mul_matrix,resultant_matrix+i);
    Draw(resultant_matrix);
    for(int i = 0; i< 8; i++){
    for(int j=0;j<4;j++){
      orignal_cube[i][j] = resultant_matrix[i][j];
    }
  }
}

void display()
{
  glColor3f( 0.9, 0.5, 1.0 );
  glRasterPos2f(-280, 280 );
  Draw(orignal_cube);
  showOption();
    int choice;
    scanf("%d",&choice);
    if(choice==1){
      printf("enter Translation points");
      scanf("%f %f %f",&tx,&ty,&tz);

      float mulmatrix[][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{tx,ty,tz,1}};
      modify(mulmatrix);
      tx =ty=tz= 0;
    }
    else if(choice==2){
      printf("enter rotation axis for x=1, y=2, z=3");
      int c;
      scanf("%d",&c);
      if(c==1){

      printf("enter rotation angle");
      scanf("%f",&qx);
        qx = qx*3.14/180;
      float mulmatrix[][4] = {{1,0,0,0},{0,cos(qx),-sin(qx),0},{0,sin(qx),cos(qx),0},{0,0,0,1}};
      modify(mulmatrix);
      qx =0;
      }
      if(c==2){
        printf("enter rotation angle");
        scanf("%f",&qy);
        qy = qy*3.14/180;
        float mulmatrix[][4] = {{cos(qy),0,sin(qy),0},{0,1,0,0},{-sin(qy),0,cos(qy),0},{0,0,0,1}};
        modify(mulmatrix);
        qy=0;
      }
      if(c==3){
        printf("enter rotation angle");
        scanf("%f",&qz);
        qz = qz*3.14/180;
        float mulmatrix[][4] = {{cos(qz),-sin(qz),0,0},{sin(qz),cos(qz),0,0},{0,0,1,0},{0,0,0,1}};
        modify(mulmatrix);
        qz=0;
      }
      
    }
    else if(choice==3){
      printf("enter scaling factor");
      scanf("%f %f %f",&Sx,&Sy,&Sz);
      float mulmatrix[][4] = {{Sx,0,0,0},{0,Sy,0,0},{0,0,Sz,0},{0,0,0,1}};
      modify(mulmatrix);
      Sx = 0; Sy = 0; Sz = 0;
    }
    else if(choice==4){
      Draw(orignal_cube1);
    }
  glFlush();

}




void myKey(unsigned char key, int x, int y)
{
  
  if(key == 'x')
  {
    qx = 30*3.14/180;
    float mulmatrix[][4] = {{1,0,0,0},{0,cos(qx),-sin(qx),0},{0,sin(qx),cos(qx),0},{0,0,0,1}};
    modify(mulmatrix);
    qx =0;
  }
  else
  if(key == 'y')
  {
    qy = 30*3.14/180;
    float mulmatrix[][4] = {{cos(qy),0,sin(qy),0},{0,1,0,0},{-sin(qy),0,cos(qy),0},{0,0,0,1}};
    modify(mulmatrix);
    qy=0;
  }
  else
  if(key == 'z')
  {
    qz = 30*3.14/180;
    float mulmatrix[][4] = {{cos(qz),-sin(qz),0,0},{sin(qz),cos(qz),0,0},{0,0,1,0},{0,0,0,1}};
    modify(mulmatrix);
    qz=0;
  }
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(600, 600);
  glutCreateWindow("3D");
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-300,300,-300,300,-300,300);
  gluLookAt(3.0, 4.0, 5.0,0.0, 0.0, 0.0,0.0, 1.0, 0.);
  glutDisplayFunc(display);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}