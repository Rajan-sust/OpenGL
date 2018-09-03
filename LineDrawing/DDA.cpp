#include <iostream>
#include <GL/glut.h>

using namespace std;

double x1, y1, x2, y2;

void Init()
{

    glClearColor(0.0, 0.0, 0.0, 0);
    glColor3f(0.14, 0.98, 0.81);
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
}

void setPixel(GLint x, GLint y)
{

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void doPlot(void)
{

    double dx = x2 - x1;
    double dy = y2 - y1;

    double x = x1, y = y1;

    setPixel((x + 0.5), (y + 0.5));

    if (dx == 0.0) {

        while (y < y2) {
            y += 1.0;
            setPixel((x + 0.5), (y + 0.5));
        }
    }

    else if (dy == 0.0) {
        while (x < x2) {
            x += 1.0;
            setPixel((x + 0.5), (y + 0.5));
        }
    }
    else {

        double m = dy / dx;
        double b = y - m * x;

        if (abs(m) > 1.0) {

            while (x < x2) {

                x = x + (1.0) / m;
                y = y + 1.0;
                setPixel((x + 0.5), (y + 0.5));
            }
        }
        else {
            while (x < x2) {

                x = x + 1.0;
                y = y + m;
                setPixel((x + 0.5), (y + 0.5));
            }
        }
    }
}

void scanInput()
{

    cout << "Enter Point1 (x1,y1) : ";
    cin >> x1 >> y1;
    cout << "\n";
    cout << "Enter Point2 (x2,y2) : ";
    cin >> x2 >> y2;
    cout << "\n";
}

int main(int argc, char** argv)
{
    scanInput();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA LineDrawing");
    Init();
    glutDisplayFunc(doPlot);
    glutMainLoop();

    return 0;
}
