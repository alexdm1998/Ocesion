#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class VAO {

public:
  std::string signature;
  unsigned int id;

  VAO(const std::string& signature) { attribSignature example = attribSignature(signature); }

  struct attribSignature { // nVertex|
    int nVertex;
    attribSignature(const std::string& signature) { verifySignature(signature); }

    // Example signature 3-GL_FLOAT»2-GL_FLOAT
    int verifySignature(const std::string& signature) {
      const std::string delimiter = "»";
      const std::vector<std::string> vertexes;

      std::size_t partitioner = 0;
      std::size_t endpoint = signature.find(delimiter);
      const std::string attribute_signature = signature.substr(0, endpoint);

      while (endpoint != std::string::npos) {
        const std::size_t attribute_length = endpoint - partitioner;
        const std::string attribute = signature.substr(partitioner, attribute_length);

        std::cout << attribute << std::endl;

		if(!verifyAttribute(attribute)){
			std::cout << "It failed" << std::endl;
			return 0;
		}
		
        partitioner = endpoint + 2;
        endpoint = signature.find(delimiter, partitioner);
      }
      const std::string attribute = signature.substr(partitioner);
      std::cout << attribute << std::endl;

      return 0;
    }


	int verifyAttribute(const std::string& attribute){
		const char size = attribute[0];
		bool isNumber = std::isdigit(static_cast<unsigned char>(size));
		if(isNumber == false) return 0;
		std::cout << "Passed " << std::endl;
		return 1;
	}
  };
};
