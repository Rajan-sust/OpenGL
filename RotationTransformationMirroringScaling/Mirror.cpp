
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;


const double pi = acos(-1.0);
vector< pair<double,double> > v;
int mode = -1;


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



void mirror(void) {

    axis();

    glBegin(GL_LINE_LOOP);

    for(auto pt : v) {

        double x = pt.first,y = pt.second;

        if(mode == 1){
           
            glVertex2d(x,-y);
        }else{
           
            glVertex2d(-x,y);
        }
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

    cout<<"Enter 0 for x-axis or 1 for y-axis : ";
    cin>>mode;
}



int main(int argc, char** argv) {
    scanInput();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Translation");
    Init();
    glutDisplayFunc(mirror);
    glutMainLoop();

    return 0;
}
