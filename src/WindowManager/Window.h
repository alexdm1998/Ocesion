#pragma once
#include <GLAD/gl.h>
#include <GLFW/glfw3.h>
#include <print>
class Window {
private:
  GLFWwindow* window;

public:
  const char* title;
  int width;
  int height;
  void (*func)();

public:
  Window(int width = 640, int height = 480, const char* = "New Window", GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
  ~Window();

  GLFWwindow* getGLFW();
  bool shouldClose();
  void setCurrent();
  void swapBuffers();
  void addFunction(void (*function)());
  void refresh();
};
