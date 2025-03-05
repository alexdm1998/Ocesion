#pragma once
#include "GraphicalContext.h"
#include <GLAD/gl.h>
class PrimaryWindow : public GraphicalContext {
private:
  unsigned int mShaderProgram;

public:
  PrimaryWindow();
  void init();
};
