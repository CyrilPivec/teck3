//
// Fire.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Sat May  9 16:29:43 2015 Nawin Kim
// Last update Sun May 10 15:06:34 2015 Nawin Kim
//

#ifndef		FIRE_HPP_
#define		FIRE_HPP_

#include <iostream>
#include <vector>
#include "Cube.hpp"
//#include "Player.hpp"

class Fire : public Cube
{
private:
  //gdl::Model	_model;
  float		_timeout;
  float		_posX;
  float		_posZ;
  bool		_status;
  std::vector<std::vector<AObject*> >*	_map;
  std::vector<AObject*>*		_players;

public:
  Fire(float x, float z, std::vector<std::vector<AObject*> >* map, std::vector<AObject*>* players):
    _timeout(0.0f), _posX(x), _posZ(z), _status(false), _map(map), _players(players),
    Cube(glm::vec3(x, 0, z), "./assets/lava.tga", AObject::FIRE)
  {
    //float v = 1.0;
    //scale(glm::vec3(v, v, v)); //1.0
    //translate(glm::vec3(x, 0.5, z));
  }
  
  virtual ~Fire()
  {
    std::cout << "Fire is destroyed" << std::endl;
  }

  virtual bool initialize()
  {
    // if (!_model.load("./assets/fire.fbx"))
    //   {
    // 	std::cout << "Cannot load the fire model" << std::endl;
    // 	return false;
    //   }
    // this->destroyBox();
    // return true;
    this->destroyBox();
    return Cube::initialize();
  }
  
  virtual void update(const gdl::Clock& clock, const gdl::Input& input)
  {
    _timeout += static_cast<float>(clock.getElapsed());
    if (_timeout > 1.5f)
      {
	_status = true;
	_timeout = 0.0f;
      }
    else
      {
	//kill players
	this->killplayer();
      }
  }
  
  virtual void draw(gdl::AShader& shader, const gdl::Clock& clock)
  {
    // if (!_status)
    //   _model.draw(shader, getTransformation(), clock.getElapsed());
    Cube::draw(shader, clock);
  }

  bool getStatus() const
  {
    return _status;
  }

  void destroyBox()
  {
    unsigned int i = static_cast<unsigned int>(round(_posX));    
    unsigned int j = static_cast<unsigned int>(round(_posZ));

    AObject* obj = (*_map)[j][i];
    if (!obj)
      return;
    switch (obj->getType())
      {
      case AObject::BOX:
	delete obj;
	(*_map)[j][i] = NULL;
	break;
      case AObject::WALL:
	_status = true;
	break;
      default:
	break;
      }
  }

  void killplayer()
  {
    for (std::vector<AObject*>::iterator it = _players->begin();
	 it != _players->end();)
      {
	if (dynamic_cast<Player*>(*it)->isBurned(_posX, _posZ))
	  {
	    delete *it;
	    it = _players->erase(it);
	  }
	else
	  {
	    ++it;
	  }
      }
  }
};

#endif
