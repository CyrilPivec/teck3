//
// Ground.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Sat May  2 14:59:35 2015 Nawin Kim
// Last update Sat May  2 21:10:53 2015 Nawin Kim
//

#ifndef		GROUND_HPP_
#define		GROUND_HPP_

#include <iostream>
#include <Geometry.hh>
#include <Texture.hh>
#include <Clock.hh>
#include <Input.hh>

#include "AObject.hpp"

class Ground : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  glm::vec3	_pos;
  
public:
  Ground(const glm::vec3& pos):
    _pos(pos)
  {
    _type = AObject::GROUND;
  }

  virtual ~Ground()
  {
  }

  virtual bool initialize()
  {
    if (_texture.load("./assets/herbe.tga") == false)
      {
	std::cerr << "Cannot load the map texture" << std::endl;
	return (false);
      }
    _geometry.pushVertex(glm::vec3(_pos.x, 0, 0));
    _geometry.pushVertex(glm::vec3(_pos.x, 0, _pos.z));
    _geometry.pushVertex(glm::vec3(0, 0, _pos.z));
    _geometry.pushVertex(glm::vec3(0, 0, 0));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return true;
  }

  virtual void update(const gdl::Clock& clock, gdl::Input& input)
  {
    (void) clock;
    (void) input;
  }

  virtual void draw(gdl::AShader& shader, const gdl::Clock& clock)
  {
    (void) clock;
    _texture.bind();
    _geometry.draw(shader, getTransformation(), GL_QUADS);
  }
};

#endif
