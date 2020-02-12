//g++ bresenham_line.cpp -lGL -lGLU -lglut
#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>

int x1, y1, x2, y2;

void myInit() {
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-10, 500, -10, 500);
}

void draw_pixel(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(x, y);
  glEnd();
}

void draw_line(int x1, int y1, int x2, int y2) {
  int dx, dy, i, e;
  int incx=1, incy=1, inc1, inc2;
  int x,y;

  dx = x2-x1;
  dy = y2-y1;

  if (dx < 0){
    incx=-1;
   dx = -dx;
  }
  if (dy < 0){
    incy=-1;
   dy = -dy;
  }

  x = x1; y = y1;
  if (dx > dy) {
    draw_pixel(x, y);
    e = 2 * dy-dx;
    inc1 = 2*(dy-dx);
    inc2 = 2*dy;
    for (i=0; i<dx; i++) {
      if (e >= 0) {
        y += incy;
        e += inc1;
      }
      else
        e += inc2;
      x += incx;
      draw_pixel(x, y);
    }

  } else {
    draw_pixel(x, y);
    e = 2*dx-dy;
    inc1 = 2*(dx-dy);
    inc2 = 2*dx;
    for (i=0; i<dy; i++) {
      if (e >= 0) {
        x += incx;
        e += inc1;
      }
      else
        e += inc2;
      y += incy;
      draw_pixel(x, y);
    }
  }
}

void myDisplay() {
  draw_line(0,0,0,400);
  draw_line(0,0,400,0);
  draw_line(400,0,400,400);
  draw_line(0,400,400,400);
  draw_line(0,200,200,400);
  draw_line(200,400,400,200);
  draw_line(400,200,200,10);
  draw_line(200,0,0,200);
  draw_line(100,100,100,300);
  draw_line(100,100,300,100);
  draw_line(300,100,300,300);
  draw_line(100,300,300,300);
  glFlush();
}

int main(int argc, char **argv) {

  // printf( "Enter (x1, y1, x2, y2)\n");
  // scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Bresenham's Line Drawing");
  myInit();
  glutDisplayFunc(myDisplay);
  glutMainLoop();
}