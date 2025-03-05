#include "WindowManager.h"

WindowManager::WindowManager(int nWindows) {
  nWindows = nWindows;
  windowArray = new Window*[nWindows];
  for (int i = 0; i < nWindows; i++) {
    windowArray[i] = nullptr;
  }
}

WindowManager::~WindowManager() {
  for (int i = 0; i < nWindows; i++) {
    if (windowArray[i] != nullptr) {
      delete windowArray[i];
    }
  }
}

bool WindowManager::createWindow(int width, int height, const char* title, GLFWmonitor* monitor, Window* share) {
  for (int i = 0; i < nWindows; i++) {
    if (windowArray[i] == nullptr) {
      if (share == NULL) {
        windowArray[i] = new Window(width, height, title, monitor);
      } else {
        windowArray[i] = new Window(width, height, title, monitor, share->getGLFW());
      }
      return true;
    }
  }
  return false;
}

bool WindowManager::setMainWindow(int index) {
  if (index >= nWindows)
    return false;
  if (windowArray[index] == nullptr)
    return false;
  indexMain = index;
  windowArray[index]->setCurrent();
  return true;
}

bool WindowManager::setMainWindow(const char* title) {
  for (int i = 0; i < nWindows; i++) {
    if (windowArray[i] != nullptr && windowArray[i]->title == title) {
      indexMain = i;
      windowArray[i]->setCurrent();
      return true;
    }
  }
  return false;
}

Window* WindowManager::getWindow(int index) {
  if (index >= nWindows)
    throw std::runtime_error("Invalid Window index");
  if (windowArray[index] == nullptr)
    throw std::runtime_error("Null Window index");
  return windowArray[index];
}

Window* WindowManager::getWindow(const char* title) {
  for (int i = 0; i < nWindows; i++) {
    if (windowArray[i] != nullptr && windowArray[i]->title == title) {
      return windowArray[i];
    }
  }
  throw std::runtime_error("Name not found");
}

void WindowManager::run() {
  while (!windowArray[indexMain]->shouldClose()) {
    for (int i = 0; i < nWindows; i++) {
      if (windowArray[i] != nullptr) {
        windowArray[i]->refresh();
      }
    }
  }
}

// Private Implementations
bool WindowManager::shouldClose() {
  if (windowArray[indexMain] == nullptr)
    return true;
  return windowArray[indexMain]->shouldClose();
}
