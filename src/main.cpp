#include <GLAD/gl.h>
#include <GLFW/glfw3.h>
#include <print>

int main() {
  int glfw_init_flag = glfwInit();

  if (glfw_init_flag == GLFW_FALSE) {
    std::println("GLFW didn't initialize successfully");
    return -1;
  }

  // OpenGL Specifications
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  GLFWwindow* mainWindow = glfwCreateWindow(600, 400, "Ocesion ad Infinitum", NULL, NULL);
  if (!mainWindow) {
    std::print("Failed to create window (GLFW)");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(mainWindow);

  int glad_version = gladLoadGL(glfwGetProcAddress);
  if (glad_version == 0) {
    std::println("GLAD didn't initialize successfully");
    return -1;
  } else {
    std::println("GLAD initialized successfully");
  }

  glClearColor(0.2, 0.1,  0.4,1.0);

  while (!glfwWindowShouldClose(mainWindow)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(mainWindow);

    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
