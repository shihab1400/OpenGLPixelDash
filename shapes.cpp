#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void bresenhamCircle(int a, int b, int r, float rColor, float gColor, float bColor) {
   int x = 0;
   int y = r;
   int d = 3 - 2 * r;

   glBegin(GL_POLYGON);
   glColor3f(rColor, gColor, bColor);
   while (x <= y) {
      glVertex2d(x+a, y+b);
      glVertex2d(-x+a, -y+b);
      glVertex2d(x+a, -y+b);
      glVertex2d(-x+a, y+b);
      glVertex2d(y+a, x+b);
      glVertex2d(-y+a, -x+b);
      glVertex2d(-y+a, x+b);
      glVertex2d(y+a, -x+b);

      if (d < 0) {
         d = d + 4 * x + 6;
      }
      else {
         d = d + 4 * (x - y) + 10;
         y--;
      }
      x++;
   }
   glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2, float rColor, float gColor, float bColor) {
   int dx = abs(x2 - x1);
   int dy = abs(y2 - y1);
   int d = 2 * dy - dx;
   int x = x1;
   int y = y1;

   glBegin(GL_POLYGON);
   glColor3f(rColor, gColor, bColor);
   glVertex2d(x, y);
   while (x < x2) {
      if (d < 0) {
         d = d + 2 * dy;
      } else {
         y++;
         d = d + 2 * (dy - dx);
      }
      x++;
      glVertex2d(x, y);
   }
   glEnd();
}

void Ellipse(float centerX, float centerY, float w, float h, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3f(r,g,b);

    for (float theta = 0; theta < 2 * M_PI; theta += 0.1) {
        float x = w * cos(theta);
        float y = h * sin(theta);
        glVertex2f(centerX + x, centerY + y);
    }

    glEnd();
}

void Rectangle0(int x, int y, int width, int height, float r, float g, float b) {
   glBegin(GL_POLYGON);
   glColor3f(r, g, b);
   glVertex2d(x, y);
   glVertex2d(x + width, y);
   glVertex2d(x + width, y + height);
   glVertex2d(x, y + height);
   glEnd();
}

void RectangleM(int x, int y, int width, int height, float r, float g, float b) {
   glColor3f(r, g, b);
   glBegin(GL_POLYGON);
   glColor3f(r, g, b);
   glVertex2d(x - width / 2, y - height / 2);
   glVertex2d(x + width / 2, y - height / 2);
   glVertex2d(x + width / 2, y + height / 2);
   glVertex2d(x - width / 2, y + height / 2);
   glEnd();
}

void Coordinates(float xc, float yc, float xl, float yl, float xinc, float yinc, float sx, float sy)
// xc = x center, yc = y center, xl = x length, yl = y length, xinc = x increment, yinc = y increment, sx = small x tick size, sy = small y tick size
{
   
   glBegin(GL_LINES);
   // X-axis
   glColor3f(1, 0, 0);  // x axis color (red)
   glVertex2f(xc - xl, yc);
   glVertex2f(xc + xl, yc);

   // Y-axis
   glColor3f(0, 1, 0);  // x axis color (green)
   glVertex2f(xc, yc - yl);
   glVertex2f(xc, yc + yl);
   glEnd();

   glColor3f(1, 1, 1);  // step color (white)
   // draw tick marks along X-axis
   for (float x = -xl; x <= xl; x += xinc) {
      if (fabs(x) < 1e-6) continue;  // skip origin

      // every 5th tick is longer
      float tickSize = (fmod(fabs(x / xinc), 5) == 0) ? sy * 1.8f : sy;

      glBegin(GL_LINES);
      glVertex2f(xc + x, yc - tickSize);
      glVertex2f(xc + x, yc + tickSize);
      glEnd();
   }

   // draw tick marks along Y-axis
   for (float y = -yl; y <= yl; y += yinc) {
      if (fabs(y) < 1e-6) continue;  // skip origin

      float tickSize = (fmod(fabs(y / yinc), 5) == 0) ? sx * 1.8f : sx;

      glBegin(GL_LINES);
      glVertex2f(xc - tickSize, yc + y);
      glVertex2f(xc + tickSize, yc + y);
      glEnd();
   }
}


