//
// Shader.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Fri May  1 21:04:31 2015 Nawin Kim
// Last update Fri May  1 21:12:08 2015 Nawin Kim
//

#ifndef	SHADER_HPP_
#define	SHADER_HPP_

#include <GL/glew.h>
#include <string>
#include <fstream>

class Shader
{
public:
  Shader(const std::string& filename)
  {
  }
  virtual ~Shader()
  {
  }
  void bind();

  static std::string load(const std::string& filename)
  {
    std::ifstream file;
    file.open(filename.c_str());
    std::string output;
    std::string line;
    if (file.is_open())
      {
      }
  }
  
private:
  GLuint _program;
  GLuint _shaders[2];
};

#endif
