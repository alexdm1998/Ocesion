#include <GLAD/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <print>

#include "PrimaryWindow.h"
#include "Shader.h"
#include "WindowManager.h"

#include "VAO/VAO.h"
// Export for nvidia to preferably use the dedicated gpu
extern "C" {
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}

// Signatures
int initializeGLAD();
void errorCallback(int code, const char* description);

unsigned int* G_VAO;
unsigned int* G_VBO;

// Defintion
void ocesion_render() {
  glBindVertexArray(*G_VAO);
  /*
    if (glIsVertexArray(*G_VAO) == GL_FALSE) {
      std::cerr << "Error: VAO is not bound!" << std::endl;
    } else {
      std::cout << "Success: VAO is bound!" << std::endl;
    }

    if (glIsBuffer(*G_VBO) == GL_FALSE) {
      std::cerr << "Error: VBO" << std::endl;
    } else {
      std::cout << "Success: VBO" << std::endl;
    }




*/

  glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
  VAO example = VAO("3-GL_FLOAT»1-GL_INT»4-GL_DOUBLE");

  if (!glfwInit()) {
    std::print("GLFW failed to initialize.");
  }
  glfwSetErrorCallback(errorCallback);

  // First Window
  WindowManager WinManager = WindowManager(2);
  WinManager.createWindow(640, 480, "Ocesion");
  WinManager.setMainWindow("Ocesion");
  WinManager.getWindow("Ocesion")->addFunction(ocesion_render);

  // Second Window
  WinManager.createWindow(320, 200, "Ocesion Extra", NULL, WinManager.getWindow("Ocesion"));
  WinManager.getWindow("Ocesion Extra")->addFunction(ocesion_render);

  if (!initializeGLAD()) {
    return -1;
  }

  PrimaryWindow Meh = PrimaryWindow();

  Shader plainShader = Shader("../../src/Shaders/normal.vert", "../../src/Shaders/normal.frag");

  plainShader.use();

  G_VAO = Meh.getVAO();
  G_VBO = Meh.getVBO();
  // Execute loop
  WinManager.run();






  
  
  std::cout << "Renderer: " << glGetString(GL_RENDERER) << "\n";
  std::cout << "Vendor: " << glGetString(GL_VENDOR) << "\n";

  
  
  
  GLint inn;

  glGetIntegerv(GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS, &inn);
  std::print("{}", inn);

  glfwTerminate();
  glfwSetErrorCallback(NULL);
  return 0;
}

// Initializations
int initializeGLAD() {
  int version = gladLoadGL(glfwGetProcAddress);
  if (version == 0) {
    std::print("Failed to initialize GLAD!");
    return 0;
  }

  std::cout << "OPENGL VERSION: " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;
  return 1;
}

void errorCallback(int code, const char* description) {
  std::cout << "GLFW::ERROR{0x" << std::hex << code << "}" << std::endl;
  std::cout << description << std::endl;
}
