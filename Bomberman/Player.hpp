//
// Player.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Wed Apr 29 17:03:58 2015 Nawin Kim
// Last update Sun May 10 21:37:51 2015 Nawin Kim
//

#ifndef		PLAYER_HPP_
#define		PLAYER_HPP_

#include "AObject.hpp"
#include "Bomb.hpp"

class Player : public AObject
{
public:
  enum Direction
    {
      DOWN,
      RIGHT,
      UP,
      LEFT
    };

private:
  gdl::Model				_model;
  std::vector<std::vector<AObject*> >*	_map;
  std::vector<Bomb*>*			_bombs;
  float					_speed;
  float					_timer;
  float					_posX;
  float					_posZ;
  Direction				_dir;
  Bomb*					_bomb;
  
  unsigned int				_score;
  unsigned int				_life;  
  
  int					_id;
  int					_kUp;
  int					_kDown;
  int					_kLeft;
  int					_kRight;
  int					_kBomb;

public:
  Player(int id, std::vector<std::vector<AObject*> >* map, std::vector<Bomb*>* bombs):
    _id(id), _map(map), _bombs(bombs), _score(0)
  {
    _posX = (_id == 0 ? 1.0 : _map->size());
    _posZ = 1.0;
    _type = AObject::PLAYER;
    _dir = DOWN;
    _kUp = (_id == 0 ? SDLK_z : SDLK_UP);
    _kDown = (_id == 0 ? SDLK_s : SDLK_DOWN);
    _kLeft = (_id == 0 ? SDLK_q : SDLK_LEFT);
    _kRight = (_id == 0 ? SDLK_d : SDLK_RIGHT);
    _kBomb = (_id == 0 ? SDLK_SPACE : SDLK_KP_0);

    scale(glm::vec3(0.015, 0.015, 0.015)); // 0.0025
    translate(glm::vec3(_posX + 0.5, 0, _posZ + 0.5));
  }
  
  virtual ~Player()
  {
    delete _bomb;
    std::cout << "Player is dead" << std::endl;
  }

  virtual bool initialize()
  {
    _speed = 5.0f;
    bool m = (_id == 0 ?
	      _model.load("./assets/bomberman_pink.fbx") :
	      _model.load("./assets/bomberman_black.fbx"));
    if (!m)
      {
	std::cout << "Failed to load player character" << std::endl;
	return false;
      }
    _model.setCurrentAnim(0);
    _bomb = new Bomb(_posX, _posZ); //need a bomb initialized to avoid a bug when first load
    if (!_bomb->initialize())
      return false;
    return true;
  }

  virtual void update(const gdl::Clock& clock, gdl::Input& input)
  {
    bool test = false;
    float elapsed = static_cast<float>(clock.getElapsed()) * _speed;
    if (input.getKey(_kUp))
      {
      	if (_dir != UP)
	  rotate(glm::vec3(0, 1, 0), this->getAngle(UP));
	if (!this->move(elapsed * -_speed, 0, -1))
	  return;
	_posZ -= elapsed;
	test = true;
	translate(glm::vec3(0, 0, -1) * elapsed);
      }
    if (input.getKey(_kDown))
      {
	if (_dir != DOWN)
	  rotate(glm::vec3(0, 1, 0), this->getAngle(DOWN));
	if (!this->move(elapsed * _speed, 0, 1))
	  return;
	_posZ += elapsed;
	test = true;
	translate(glm::vec3(0, 0, 1) * elapsed);
      }
    if (input.getKey(_kLeft))
      {
	if (_dir != LEFT)
	  rotate(glm::vec3(0, 1, 0), this->getAngle(LEFT));
	if (!this->move(elapsed * -_speed, -1, 0))
	  return;
	_posX -= elapsed;
	test = true;
	translate(glm::vec3(-1, 0, 0) * elapsed);
      }
    if (input.getKey(_kRight))
      {
	if (_dir != RIGHT)
	  rotate(glm::vec3(0, 1, 0), this->getAngle(RIGHT));
	if (!this->move(elapsed * _speed, 1, 0))
	  return;
	_posX += elapsed;
	test = true;
	translate(glm::vec3(1, 0, 0) * elapsed);
      }
    if (input.getKey(_kBomb))
      {
	this->setBomb();
      }

    _model.pause(!test);
  }

  virtual void draw(gdl::AShader& shader, const gdl::Clock& clock)
  {
    _model.draw(shader, getTransformation(), clock.getElapsed());
  }

  bool	isBurned(float x, float z) const
  {
    return (x - _posX >= -0.8 && x - _posX <= 0.8 &&
	    z - _posZ >= -0.8 && z - _posZ <= 0.8);       
  }
  
private:
  bool	move(float elapsed, int dir_x, int dir_z)
  {
    float xp = _posX;
    float zp = _posZ;
    if (dir_x != 0)
      xp += elapsed;
    else if (dir_z != 0)
      zp += elapsed;
    size_t x = round(xp);
    size_t z = round(zp);
    if (x - xp >= -0.8 && x - xp <= 0.8 &&
	z - zp >= -0.8 && z - zp <= 0.8)
      return (*_map)[z][x] == NULL;
    return true;
  }

  bool	setBomb()
  {
    Bomb* b = new Bomb(_posX, _posZ);

    if (!b->initialize())
      return false;
    _bombs->push_back(b);
    return true;
  }
  
  int		getAngle(const Direction next_dir)
  {
    Direction d = _dir;
    _dir = next_dir;
    switch (d)
      {
      case UP:
	return (90 * (static_cast<int>(_dir) + 2)) % 360;
      case DOWN:
	return (90 * static_cast<int>(_dir)) % 360;
      case LEFT:
	return (90 * (static_cast<int>(_dir) + 1)) % 360;
      case RIGHT:
	return (90 * (static_cast<int>(_dir) + 3)) % 360;
      }
    return 0;
  }
};

#endif
