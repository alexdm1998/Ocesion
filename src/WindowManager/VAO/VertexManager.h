#pragma once
#include "VAO.h"

class VertexManager {

private:
  VAO vertexArray[10];

public:
  VAO getVAObySignature(std::string signature);
};
