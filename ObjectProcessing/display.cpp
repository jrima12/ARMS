/*
 * OGL02Animation.cpp: 3D Shapes with animation
 */
// #include <windows.h>  // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <Python.h>
#include <iostream>

/* Global variables */
// char title[] = "3D Shapes with animation";
char title[] = " ";
GLfloat anglePyramid = 0.5f; // Rotational angle for pyramid [NEW]
int refreshMills = 10;       // refresh interval in milliseconds [NEW]
GLfloat transx1 = -2.5f;
GLfloat transx2 = 2.5f;
GLfloat transy = 0.0f;
GLfloat scale = -20.0f;
GLfloat persp = 10.0f;
GLfloat rotx = 1.0f;
GLfloat roty = 1.0f;
GLfloat rotz = 1.0f;
int count;
int mode;

PyObject *module;
PyObject *method;

void initialize(){
   // Initialize the Python interpreter
   Py_Initialize();

   PyObject *rand_module = PyImport_ImportModule("serial");
   // if (rand_module == NULL)
   // {
   //    PyErr_Print();
   // }

   const char *narrowStr = "./";
   size_t len = strlen(narrowStr) + 1;
   wchar_t *wideStr = (wchar_t *)malloc(len * sizeof(wchar_t));
   mbstowcs(wideStr, narrowStr, len);
   PySys_SetPath(wideStr);
   free(wideStr);

   PySys_GetObject("path");

   module = PyImport_ImportModule("getdata");
   method = PyObject_GetAttrString(module, "returnMode");
}

int getMode()
{
   // // Initialize the Python interpreter
   // Py_Initialize();

   // PyObject *rand_module = PyImport_ImportModule("serial");
   // // if (rand_module == NULL)
   // // {
   // //    PyErr_Print();
   // // }

   // const char *narrowStr = "./";
   // size_t len = strlen(narrowStr) + 1;
   // wchar_t *wideStr = (wchar_t *)malloc(len * sizeof(wchar_t));
   // mbstowcs(wideStr, narrowStr, len);
   // PySys_SetPath(wideStr);
   // free(wideStr);

   // PySys_GetObject("path");
   // Import the module containing the method you want to call
   // PyObject *module = PyImport_ImportModule("getdata");
   // // if (module == NULL)
   // // {
   // //    PyErr_Print();
   // //    printf("error 1");
   // // }
   // // Get a reference to the method you want to call
   // PyObject *method = PyObject_GetAttrString(module, "returnMode");
   // if (method == nullptr)
   // {
   //    // printf("ERROR getting returnmode method");
   //    PyErr_Print();
   //    printf("error 2");
   // }
   // Call the method with arguments and get the return value
   PyObject *result = PyObject_CallObject(method, NULL);
   // std::cout << "result is " << result << std::endl;
   // if (result == NULL)
   // {
   //    printf("error 3");
   // }

   // Convert the return value to a C++ type
   int value = PyLong_AsLong(result);
   // if(value == 0){
   //       printf("ERROR with value");
   //       exit(-1);
   // }
   // Print the return value
   std::cout << count << "     " << value << "     " << mode << std::endl;

   // Clean up
   //  Py_DECREF(rand_module);
   //  Py_DECREF(module);
   //  Py_DECREF(method);
   //  Py_DECREF(result);
   //  Py_Finalize();

   return value;
}

void rotatetri(int count)
{
   if (count < 200)
   {
      anglePyramid += 0.5;
      rotx = 0.0f;
      roty = 1.0f;
      rotz = 0.0f;
   }
   else if (count < 400)
   {
      anglePyramid -= 0.5;
      rotx = 0.0f;
      roty = 1.0f;
      rotz = 0.0f;
   }
   else if (count < 1000)
   {
      anglePyramid -= 0.5;
      rotx = 1.0f;
      roty = 1.0f;
      rotz = 0.0f;
   }
   else if (count < 1600)
   {
      anglePyramid += 0.5;
      rotx = 1.0f;
      roty = 1.0f;
      rotz = 0.0f;
   }
   else if (count < 2000)
   {
      anglePyramid -= 0.5;
      rotx = -1.0f;
      roty = 0.0f;
      rotz = 0.0f;
   }
   else if (count < 2400)
   {
      anglePyramid -= 0.5;
      rotx = 0.0f;
      roty = 1.0f;
      rotz = 0.0f;
   }
   else if (count < 2800)
   {
      anglePyramid -= 0.5;
      rotx = 0.0f;
      roty = -1.0f;
      rotz = 0.0f;
   }
   else
   {
      count = 0;
   }
}

void translatetri(int count)
{
   if (count < 400)
   {
      transx1 += 0.003f;
      transx2 += 0.003f;
   }
   else if (count < 1200)
   {
      transx1 -= 0.003f;
      transx2 -= 0.003f;
   }
   else if (count < 1600)
   {
      transx1 += 0.003f;
      transx2 += 0.003f;
   }
   else if (count < 1800)
   {
      transy += 0.003f;
   }
   else if (count < 2200)
   {
      transy -= 0.003f;
   }
   else if (count < 2400)
   {
      transy += 0.003f;
   }
   else if (count < 2600)
   {
      transy += 0.003f;
      transx1 += 0.003f;
      transx2 += 0.003f;
   }
   else if (count < 2800)
   {
      transy -= 0.003f;
      transx1 -= 0.003f;
      transx2 -= 0.003f;
   }
   else
   {
      count = 0;
   }
}

void scaletri(int count)
{
   if (count < 200)
   {
      scale += 0.1f;
      transx1 += 0.01f;
      transx2 -= 0.01f;
   }
   else if (count < 600)
   {
      scale -= 0.1f;
      transx1 -= 0.02f;
      transx2 += 0.02f;
   }
   else if (count < 800)
   {
      scale += 0.1f;
      transx1 += 0.03f;
      transx2 -= 0.03f;
   }
   else
   {
      count = 0;
   }
}

void changeMode(){

}

void updateValues()
{
   int x = getMode();
   if (x == 0)
   {
      mode = mode;
   }
   else if (x != mode)
   {
      transx1 = -1.5f;
      transx2 = 1.5f;
      transy = 0.0f;
      scale = -20.0f;
      persp = 10.0f;
      anglePyramid = 0.5;
      count = 0;
      mode = x;
   }
   else
   {
      mode = mode;
   }

   if (mode == 1)
   {
      rotatetri(count);
   }
   else if (mode == 2)
   {
      translatetri(count);
   }
   else
   {
      scaletri(count);
   }

   if (count > 2800)
   {
      count = 0;
   }
   else
   {
      count += 1;
   }
}

/* Initialize OpenGL Graphics */
void initGL()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);              // Set background color to black and opaque
   glClearDepth(1.0f);                                // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);                           // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);                            // Set the type of depth-test
   glShadeModel(GL_SMOOTH);                           // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);                         // To operate on model-view matrix

   // Render a pyramid consists of 4 triangles
   glLoadIdentity();                          // Reset the model-view matrix
   glTranslatef(transx1, transy, scale);      // Move left and into the screen
   glRotatef(anglePyramid, rotx, roty, rotz); // Rotate about the (1,1,0)-axis [NEW]

   glBegin(GL_TRIANGLES); // Begin drawing the pyramid with 4 triangles
   // Front
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(1.0f, -1.0f, 1.0f);

   // Right
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(1.0f, -1.0f, 1.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(1.0f, -1.0f, -1.0f);

   // Back
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(-1.0f, -1.0f, -1.0f);

   // Left
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glEnd(); // Done drawing the pyramid

   // Render a pyramid consists of 4 triangles
   glLoadIdentity();                          // Reset the model-view matrix
   glTranslatef(transx2, transy, scale);      // Move left and into the screen
   glRotatef(anglePyramid, rotx, roty, rotz); // Rotate about the (1,1,0)-axis [NEW]

   glBegin(GL_TRIANGLES); // Begin drawing the pyramid with 4 triangles
   // Front
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(1.0f, -1.0f, 1.0f);

   // Right
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(1.0f, -1.0f, 1.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(1.0f, -1.0f, -1.0f);

   // Back
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(-1.0f, -1.0f, -1.0f);

   // Left
   glColor3f(1.0f, 0.0f, 0.0f); // Red
   glVertex3f(0.0f, 1.0f, 0.0f);
   glColor3f(0.0f, 0.0f, 1.0f); // Blue
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glColor3f(0.0f, 1.0f, 0.0f); // Green
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glEnd(); // Done drawing the pyramid

   glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)

   // Update the rotational angle after each refresh [NEW]
   // anglePyramid += 0.2f;
   updateValues();
}

/* Called back when timer expired [NEW] */
void timer(int value)
{
   glutPostRedisplay();                   // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height)
{ // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0)
      height = 1; // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
   glLoadIdentity();            // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(persp, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv)
{
   initialize();
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(1920, 1080);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);         // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);         // Register callback handler for window re-size event
   initGL();                         // Our own OpenGL initialization
   glutTimerFunc(0, timer, 0);       // First timer call immediately [NEW]
   glutMainLoop();                   // Enter the infinite event-processing loop
   return 0;
}

// USE THIS TO COMPILE CODE IN TERMINAL, NOT VSCODE
// g++ -o display display.cpp -I/usr/include/python3.10 -lpython3.10 -lGL -lGLU -lglut
// g++ -o display display.cpp -I/usr/include/python3.10 -lpython3.10 -lGL -lGLU -lglut