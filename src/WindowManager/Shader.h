#pragma once

class Shader {
private:
  unsigned int id;

public:
  Shader(const char* vertexPath, const char* fragmentPath);
  void use();
  unsigned int getID();
};
