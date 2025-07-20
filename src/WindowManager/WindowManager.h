#pragma once
#include "Window.h"

// Ensure that the WindowManager doesn't add duplicates
// WindowManager must have a main at all times
class WindowManager {
private:
  Window** windowArray;
  int nWindows;
  int indexMain;

public:
  WindowManager(int nWindows);
  ~WindowManager();

  bool createWindow(int width, int height, const char* title = "New Window", GLFWmonitor* monitor = NULL, Window* share = NULL);
  bool setMainWindow(int index);
  bool setMainWindow(const char* title);
  Window* getWindow(int index);
  Window* getWindow(const char* title);

  void run();

private:
  bool shouldClose();
  void forEach(void (*func)()); //For each window
};
