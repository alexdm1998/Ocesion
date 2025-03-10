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
  // Shader Program
  const char *vertexShaderSource =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
  }

  const char *fragmentShaderSource =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "	  FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
      "}\0";

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  mShaderProgram = glCreateProgram();

  glAttachShader(mShaderProgram, vertexShader);
  glAttachShader(mShaderProgram, fragmentShader);
  glLinkProgram(mShaderProgram);

  glUseProgram(mShaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // Vertex Attributes
  float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

  glBindVertexArray(*getVAO());
  glBindBuffer(GL_ARRAY_BUFFER, (*getVBO()));
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glUseProgram(mShaderProgram);
}
