#include <GLAD/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <print>

#include "PrimaryWindow.h"
#include "WindowManager.h"

// Export for nvidia to preferably use the dedicated gpu
extern "C" {
__declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;
}

// Signature
int initializeGLAD();

unsigned int* G_VAO;
unsigned int* G_VBO;

// Defintion
void ocesion_render() {
  glBindVertexArray(*G_VAO);

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

  glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
  if (!glfwInit())
    std::print("GLFW failed to initialize.");

  // Assumptions: GLFW already has been initialized
  WindowManager WinManager = WindowManager(2);
  WinManager.createWindow(640, 480, "Ocesion");
  WinManager.setMainWindow("Ocesion");
  WinManager.getWindow("Ocesion")->addFunction(ocesion_render);

  WinManager.createWindow(320, 200, "Ocesion Extra", NULL, WinManager.getWindow("Ocesion"));
  WinManager.getWindow("Ocesion Extra")->addFunction(ocesion_render);

  //WinManager.getWindow("Heb");

  if (!initializeGLAD()) {
    return -1;
  }

  PrimaryWindow Meh = PrimaryWindow();

  G_VAO = Meh.getVAO();
  G_VBO = Meh.getVBO();
  // Execute loop
  WinManager.run();

  glfwTerminate();
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
