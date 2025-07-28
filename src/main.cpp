#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <print>

//Prototypes
void errorCallback(int code, const char* description);


//Entry point
int main() {

  // GLFW
  if (!glfwInit()) {
    std::print("GLFW failed to initialize.");
  }
  // GL context for GLFW window creation
  glfwSetErrorCallback(errorCallback);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  // GLFW window creation
  GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  // GLEW Initialization
  GLenum err = glewInit();
  if (GLEW_OK != err) {
    fprintf(stderr, "Error %s\n", glewGetErrorString(err));
  }
  // Verifying GL Version
  fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
  fprintf(stdout, "Status: Using OpenGL %s\n", glGetString(GL_VERSION));
  // Verifying GL Profile
  GLint value;
  glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &value);
  if(value & GL_CONTEXT_CORE_PROFILE_BIT){
	  std::println("GL PROFILE: CORE");
  }
  if(value & GL_CONTEXT_COMPATIBILITY_PROFILE_BIT){
	std::println("GL PROFILE: COMPATIBILITY");
  }


 glGetString(GL_VERSION);


  //Application loop
  while (!glfwWindowShouldClose(window)) {

    glfwPollEvents();
  }

  glfwTerminate();
  glfwSetErrorCallback(NULL);
  return 0;
}

void errorCallback(int code, const char* description) {
  std::cout << "GLFW::ERROR{0x" << std::hex << code << "}" << std::endl;
  std::cout << description << std::endl;
}
