
#include <bits/stdc++.h>
#include <GL/glut.h>

const double pi = acos(-1.0);

using namespace std;

vector< pair<double,double> > v;

double theta;

void Init() {

    glClearColor(0.0, 0.0, 0.0, 0);
    glColor3f(0.14, 0.98, 0.81);
    gluOrtho2D(-150.0, 150.0, -150.0, 150.0);
}

void axis()
{
    glBegin(GL_LINES);

    /*x axis*/

    glVertex2d(-150,0);
    glVertex2d(150,0);
    /*y axis*/
    glVertex2d(0,150);
    glVertex2d(0,-150);

    glEnd();
    glFlush();
}

void setPixel(double x,double y) {

    double X = x*cos(theta) - y*sin(theta);
    double Y = x*sin(theta) + y*cos(theta);

    glVertex2d(X,Y);
   
}

void rotate(void) {

    axis();

    glBegin(GL_LINE_LOOP);

    for(auto pt: v) {
        setPixel(pt.first,pt.second);
    }

    glEnd();
    glFlush();


}

void scanInput() {

    cout<<"Enter number of points : ";
    int n;
    cin>>n;
    cout<<endl;

    cout<<"Enter All points (x,y) : \n";

    for(int i=0;i<n;i++) {
       double x,y;
       cin>>x>>y;
       v.push_back({x,y});
    }

    cout<<"Enter theta in degree for rotation : ";
    cin>>theta;
    theta = (theta*pi)/180.0;
}

int main(int argc, char** argv)
{
    scanInput();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Translation");
    Init();
    glutDisplayFunc(rotate);
    glutMainLoop();

    return 0;
}
