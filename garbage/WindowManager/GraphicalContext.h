#pragma once
#include <GLAD/gl.h>

class GraphicalContext {

private:
  unsigned int vbo;
  unsigned int vao;

public:
  virtual void init() = 0;

  unsigned int* getVBO() {return &vbo;}
  unsigned int* getVAO() {return &vao;}
};
