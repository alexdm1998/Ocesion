#include "PrimaryWindow.h"
#include <stddef.h>

PrimaryWindow::PrimaryWindow() {

  unsigned int *vbo = getVBO();
  glGenBuffers(1, vbo);

  unsigned int *vao = getVAO();
  glGenVertexArrays(1, vao);

  init();
}

void PrimaryWindow::init() {
  // Vertex Attributes
  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

  glBindBuffer(GL_ARRAY_BUFFER, (*getVBO()));
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(*getVAO());
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
}
