#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

double x1,y1,x2,y2;

void setpixel(GLint xCoordinate, GLint yCoordinate) {
  glBegin(GL_POINTS);
  glVertex2i(xCoordinate, yCoordinate);
  glEnd();
  glFlush();
}



void Init() {
  
    glClearColor(0.0,0.0,0.0,0);
    gluOrtho2D(-100.0 , 100.0 , -100.0 , 100.0);
}

void simpleLine(void)
{
    double dx = x2-x1;
    double dy = y2-y1;


    double x = x1,y = y1;

    setpixel((x+0.5),(y+0.5));

    if(dx==0.0)
    {

        while(y<y2){
            y+=1.0;
            setpixel((x+0.5),(y+0.5));
        }
    }
    else if(dy==0.0)
    {
        while(x<x2){
            x+=1.0;
            setpixel((x+0.5),(y+0.5));
        }
    }
    else{

        double slope = dy/dx;
        double b = y - slope*x;

        if(abs(slope)>=1.0) {
            
            while(x<x2)
            {
                x = x + (1.0)/slope;
                y = y + 1.0;
                setpixel((x+0.5),(y+0.5));
            }

        }else{

            while(x<x2)
            {
                x = x + 1.0;
                y = y + slope;
                setpixel((x+0.5),(y+0.5));

            }


        }
    }

}


int main(int argc, char **argv)
{
   


   
    cin>>x1>>y1;

   
    cin>>x2>>y2;



    glutInit(&argc,argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowPosition(0,0);
    glutInitWindowSize(300,300);
   
    glutCreateWindow("DDA Algorithm");
  
    Init();
 
    glutDisplayFunc(simpleLine);
    
    glutMainLoop();

    return 0;
}
