#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;


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


    int x = 0,y = r;
    double decision = 5.0/4.0 - r;



   

    glBegin(GL_POINTS);


    while(y>=x) {

        setPixel(x,y);
        setPixel(y,x);
        setPixel(-y,x);
        setPixel(-x,y);
        setPixel(-x,-y);
        setPixel(-y,-x);
        setPixel(y,-x);
        setPixel(x,-y);
        

        if (decision < 0)
        {
            x++; 
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
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
