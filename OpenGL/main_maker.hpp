#include <iostream>
#include <math.h>

#include <unistd.h>

#include <vector>
#include <utility>
#include <set>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define ESCAPE 27

using namespace std;

#include "openGL.base.hpp"
#include "point.hpp"
float sleep_sec;
#include "print.hpp"

void (*my_func)();

int main (int argc, char** args)
{
	cout << "How long each triangulation stay on screen? (in seconds): ";
	cin >> sleep_sec;
	int n;
	cout << "How many vertexes have your polygon?: ";
	cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		float x, y;
		cout << "Input coordinates of point " << ((char)(i + 'A')) << "(first x): ";
		cin >> x >> y;
		polygon.push_back (point (x * 4, y * 4));
	}

	gen_LN ();
	
	#include "my_func.hpp"

	glutInit(&argc, args);  

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

	glutInitWindowSize(640, 600);  

	glutInitWindowPosition(0, 0);  

	window = glutCreateWindow("Triangulation of Polygon");  

	glutDisplayFunc(*my_func);  

	glutFullScreen();

	glutIdleFunc(*my_func);

	glutReshapeFunc(&ReSizeGLScene);

	glutKeyboardFunc(&keyPressed);

	InitGL(640, 480);

	glutMainLoop();  
}
