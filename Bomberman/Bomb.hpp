//
// Bomb.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Thu May  7 20:41:02 2015 Nawin Kim
// Last update Sun May 10 20:38:26 2015 Nawin Kim
//

#ifndef	BOMB_HPP_
#define	BOMB_HPP_

#include <iostream>

#include "AObject.hpp"

class Bomb : public AObject
{
private:
  gdl::Model	_model;
  float		_timeout;
  float		_posX;
  float		_posZ;
  bool		_exploded;
    
public:
  Bomb(float x, float z):
    _timeout(0.0f), _posX(x), _posZ(z), _exploded(false)
  {
    _type = AObject::BOMB;
    float v = 0.0025;
    scale(glm::vec3(v, v, v)); //0.0025
    translate(glm::vec3(x + 0.5, 0.5, z + 0.5));
  }
  
  virtual ~Bomb()
  {
    std::cout << "Bomb is destroyed" << std::endl;
  }

  virtual bool initialize()
  {
    if (!_model.load("./assets/bomb.fbx"))
      {
	std::cout << "Cannot load the bomb model" << std::endl;
	return false;
      }
    return true;
  }
  
  virtual void update(const gdl::Clock& clock, const gdl::Input& input)
  {
    _timeout += static_cast<float>(clock.getElapsed());
    if (_timeout > 3.0f)
      {
	_exploded = true;
	_timeout = 0.0f;
      }
  }
  
  virtual void draw(gdl::AShader& shader, const gdl::Clock& clock)
  {
    _model.draw(shader, getTransformation(), clock.getElapsed());
  }
  
  bool getExploded() const
  {
    return _exploded;
  }

  float getPosX() const
  {
    return _posX;
  }

  float getPosZ() const
  {
    return _posZ;
  }
};

#endif
