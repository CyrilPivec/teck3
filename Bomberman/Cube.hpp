//
// Cube.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Tue Apr 28 15:57:50 2015 Nawin Kim
// Last update Sat May  2 17:53:31 2015 Nawin Kim
//

#ifndef		CUBE_HPP_
#define		CUBE_HPP_

#include <iostream>
#include <string>
#include <Geometry.hh>
#include <Texture.hh>
#include <Clock.hh>

#include "AObject.hpp"

class Cube : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  glm::vec3	_pos;
  float		_speed;
  std::string	_textureFile;
  
public:
  Cube(const glm::vec3& pos, const std::string& textureFile, AObject::ObjectType type):
    _pos(pos), _textureFile(textureFile)
  {
    _type = type;
  }

  virtual ~Cube()
  {
  }

  virtual bool initialize()
  {
    _speed = 10.0f;
    if (_texture.load(_textureFile) == false)
      {
	std::cerr << "Cannot load the cube texture" << std::endl;
	return false;
      }
  
    _geometry.pushVertex(glm::vec3(_pos.x, 0.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x, 1.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 0.0, _pos.z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(_pos.x, 0.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x, 1.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 0.0, _pos.z + 1.0));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(_pos.x, 0.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x, 1.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x, 1.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x, 0.0, _pos.z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 0.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 0.0, _pos.z + 1.0));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(_pos.x, 0.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x, 0.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.pushVertex(glm::vec3(_pos.x, 1.0, _pos.z + 1.0));
    _geometry.pushVertex(glm::vec3(_pos.x, 1.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z));
    _geometry.pushVertex(glm::vec3(_pos.x + 1.0, 1.0, _pos.z + 1.0));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));

    _geometry.build();
    return (true);
  }

  virtual void update(gdl::Clock const &clock, gdl::Input &input)
  {
    (void) clock;
    (void) input;
    // if (input.getKey(SDLK_UP))
    // 	translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    // if (input.getKey(SDLK_DOWN))
    //   translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    // if (input.getKey(SDLK_LEFT))
    //   translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    // if (input.getKey(SDLK_RIGHT))
    //   translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  }

  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock)
  {
    (void)clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
  }
};

#endif
