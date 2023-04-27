#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <Python.h>
#include <iostream>

/* Global variables */
// char title[] = "3D Shapes with animation";
char title[] = " ";
GLfloat anglePyramid = 0.5f; // Rotational angle for pyramid [NEW]
int refreshMills = 10;       // refresh interval in milliseconds [NEW]
GLfloat transx1 = -1.8f;
GLfloat transx2 = 1.8f;
GLfloat transy = 0.0f;
GLfloat scale = -20.0f;
GLfloat persp = 45.0f;
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

int main(){
    while (true)
    {
        getMode();
    }
    
}