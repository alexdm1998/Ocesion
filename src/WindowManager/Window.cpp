#include "Window.h"

Window::Window(int w, int h, const char* name, GLFWmonitor* monitor, GLFWwindow* share) : func(nullptr) {
  title = name;
  width = w;
  height = h;
  window = glfwCreateWindow(width, height, name, monitor, share);
}

Window::~Window() { glfwDestroyWindow(window); }

GLFWwindow* Window::getGLFW() { return window; }

bool Window::shouldClose() { return glfwWindowShouldClose(window); }

void Window::setCurrent() { glfwMakeContextCurrent(window); }

void Window::swapBuffers() { glfwSwapBuffers(window); }

void Window::addFunction(void (*function)()) { func = function; }

void Window::refresh() {
  setCurrent();

  glfwPollEvents();

  glClearColor(0.1, 0.1, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  if (func != nullptr) {
    func();
  }

  swapBuffers();
}
