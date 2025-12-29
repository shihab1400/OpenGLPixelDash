#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "collisionDetection.cpp"
#include "EShoot.cpp"

Rect r1 = { 100,100,100,100 };
Rect r2 = { -200,-200,100,100 };
float r = 1.0, g = 1.0, b = 1.0;

void display() {

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   // Coordinates(0, 0, 300, 300, 5, 5, 2, 2);

   if (collision(r1, r2)) {
      r = 1.0;
      g = 0.0;
      b = 0.0;
   }
   else {
      r = 1.0;
      g = 1.0;
      b = 1.0;
   }

   Rectangle0(r1.x, r1.y, r1.width, r1.height, 1, 1, 1);
   Rectangle0(r2.x, r2.y, r2.width, r2.height, r, g, b);

   
   
   EnemyShooter(100,100);
   

   glutPostRedisplay();

   glutSwapBuffers();

}

void keyboardInput(unsigned char key, int x, int y) {

   if (key == 'd') {
      r2.x += 10;
   }
   else if (key == 'a') {
      r2.x -= 10;
   }
   else if (key == 'w') {
      r2.y += 10;
   }
   else if (key == 's') {
      r2.y -= 10;
   }

   glutPostRedisplay();
}

int winW = 600, winH = 600;
void reshape(int w, int h) {
   glViewport(0, 0, winW, winH);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-winW / 2, winW / 2, -winH / 2, winH / 2);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitWindowSize(600,600);
   glutCreateWindow("Open GL");
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboardInput);

   //Bullet Animation
   glutTimerFunc(16, updateBullet, 0);
   glutTimerFunc(1000, createBullet, 0);

   glutMainLoop();
   return 0;
}