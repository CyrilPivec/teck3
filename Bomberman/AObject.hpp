//
// AObject.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Tue Apr 28 15:37:13 2015 Nawin Kim
// Last update Sat May  9 12:40:09 2015 Nawin Kim
//

#ifndef		AOBJECT_HPP_
#define		AOBJECT_HPP_

#include <SdlContext.hh>
#include <BasicShader.hh>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class AObject
{
public:
  enum ObjectType
    {
      WALL,
      BOX,
      BOMB,
      FIRE,
      GROUND,
      PLAYER,
      IA
    };
  
public:
  AObject():
    _position(0, 0, 0),
    _rotation(0, 0, 0),
    _scale(1, 1, 1)
  {
  }
  virtual ~AObject()
  {
  }
  virtual bool	initialize()
  {
    return true;
  }
  virtual void	update(const gdl::Clock& clock, gdl::Input& input)
  {
  }
  virtual void	draw(gdl::AShader& shader, const gdl::Clock& clock) = 0;

  void		translate(const glm::vec3& v)
  {
    _position += v;
  }

  void		rotate(const glm::vec3& axis, float angle)
  {
    _rotation += axis*angle;
  }

  void		scale(const glm::vec3& scale)
  {
    _scale *= scale;
  }

  glm::mat4	getTransformation()
  {
    glm::mat4 trans(1);

    trans = glm::translate(trans, _position);
    trans = glm::rotate(trans, _rotation.x, glm::vec3(1, 0, 0));
    trans = glm::rotate(trans, _rotation.y, glm::vec3(0, 1, 0));
    trans = glm::rotate(trans, _rotation.z, glm::vec3(0, 0, 1));    
    trans = glm::scale(trans, _scale);
    return trans;
  }

  ObjectType	getType() const
  {
    return _type;
  }

protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  ObjectType	_type;
};

#endif
