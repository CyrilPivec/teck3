//
// GameEngine.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Tue Apr 28 16:13:59 2015 Nawin Kim
// Last update Sat May  9 20:56:59 2015 Nawin Kim
//

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <list>
#include <vector>
#include <Game.hh>
#include <SdlContext.hh>
#include <Input.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <Clock.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <OpenGL.hh>

#include "AObject.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Ground.hpp"
#include "Fire.hpp"

class GameEngine : public gdl::Game
{
private:
  static const float SIZE_X = 7.0f;
  
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::vector<AObject*>	_objects;
  std::vector<Bomb*>	_bombs;
  std::vector<Fire*>	_fires;
  AObject*		_ground;
  Map*			_mapLoader;
  std::vector<std::vector<AObject*> >* _map;

  void			explosion(Bomb*);
  
public:
  GameEngine();
  ~GameEngine();

  bool			initialize();
  bool			update();
  void			draw();
};
