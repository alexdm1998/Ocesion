#pragma once
#include <string>

struct VertexSignature {
  VertexSignature(const std::string& signature) { verifySignature(signature); }



  //Example signature || 3-GL_FLOAT»2-GL_FLOAT
  int verifySignature(const std::string& signature) {
	  std::string delimiter = "»";
	  std::size_t pos = 0;


	  //For each
	  //Isolate
	  const std::size_t delimiter_pos = signature.find(delimiter);
	  const std::string vertex_string = signature.substr(pos, pos - delimiter_pos);
	  //
	  //
	  //

	  const char vertex_size = signature[0];

	  const 
	  const std::string vertex_type = signature.substr(2,
	  
  }



};
