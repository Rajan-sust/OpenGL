
#include <bits/stdc++.h>

#include <GL/glut.h>

using namespace std;

vector< pair<double,double> > v;

double h,k;

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
    glVertex2d(x + h , y + k);
}

void translate(void) {

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

    cout<<"Enter (h,k) for scaling : ";
    cin>>h>>k;
    cout<<endl;



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
    glutDisplayFunc(translate);
    glutMainLoop();

    return 0;
}
