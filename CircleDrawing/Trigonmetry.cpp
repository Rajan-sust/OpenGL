#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;



const double pi = acos(-1.0);

double h,k,r;


void Init()
{

    glClearColor(0.0, 0.0, 0.0, 0);
    glColor3f(0.14, 0.98, 0.81);
    gluOrtho2D(-150.0, 150.0, -150.0, 150.0);
}

void setPixel(int x, int y) {

   glVertex2i(x+h, y+k);
    
}


void doPlot(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    

    glBegin(GL_POINTS);

   
    for(int d = 0;d<=45;d++) {

        double theta = ((d*pi)/180.0);
        int x = r*cos(theta);
        int y = r*sin(theta);

        setPixel(x,y);
        setPixel(y,x);
        setPixel(-y,x);
        setPixel(-x,y);
        setPixel(-x,-y);
        setPixel(-y,-x);
        setPixel(y,-x);
        setPixel(x,-y);
      
    }

    glEnd();
    glFlush();


}

void scanInput()
{
    cout<<"Enter center (x,y) : ";
    cin>>h>>k;
    cout<<endl;

    cout<<"Enter Radius : ";
    cin>>r;
    cout<<endl;

    
}

int main(int argc, char** argv)
{
    scanInput();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Circle");
    Init();
    glutDisplayFunc(doPlot);
    glutMainLoop();

    return 0;
}
