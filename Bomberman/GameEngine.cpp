//
// GameEngine.cpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Sat May  2 14:31:31 2015 Nawin Kim
// Last update Sun May 10 21:38:43 2015 Nawin Kim
//

#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
  for (size_t i = 0; i < _objects.size(); ++i)
    delete _objects[i];

  delete _ground;
  delete _mapLoader;
}

bool	GameEngine::initialize()
{
  if (!_context.start(1000, 800, "My bomberman!"))
    return false;

  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;

  _mapLoader = new Map("./maps/map2");
  if (!_mapLoader->load())
    return false;
  _map = _mapLoader->getMap();
  _ground = new Ground(glm::vec3(_mapLoader->getMaxX(), 0, _mapLoader->getMaxZ()));
  if (!_ground->initialize())
    return false;
  
  glm::mat4 projection;
  glm::mat4 transformation;
     
  AObject* p = new Player(0, _map, &_bombs);
  if (p->initialize() == false)
    return false;
  _objects.push_back(p);

  AObject* p2 = new Player(1, _map, &_bombs);
  if (p2->initialize() == false)
    return false;
  _objects.push_back(p2);
  
  projection = glm::perspective(60.0f, 1000.0f / 800.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(7.0f, 10.0f, 15.0f),
			       glm::vec3(7.0f, 0.0f, 5.0f),
			       glm::vec3(0.0f, 1.0f, 0.0f));
    
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  return true;
}

bool	GameEngine::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);

  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);

  for (std::vector<Bomb*>::iterator it = _bombs.begin();
	 it != _bombs.end();)
    {
      if ((*it)->getExploded())
	{
	  this->explosion(*it);
	  delete *it;
	  it = _bombs.erase(it);
	}
      else
	{
	  (*it)->update(_clock, _input);
	  ++it;
	}
    }

  for (std::vector<Fire*>::iterator it = _fires.begin();
	 it != _fires.end();)
    {
      if ((*it)->getStatus())
	{
	  delete *it;
	  it = _fires.erase(it);
	}
      else
	{
	  (*it)->update(_clock, _input);
	  ++it;
	}
    }
  return true;
}

void	GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _shader.bind();

  _ground->draw(_shader, _clock);
  for (size_t i = 0; i < _map->size(); ++i)
    {
      for (size_t j = 0; j < (*_map)[i].size(); ++j)
	if ((*_map)[i][j])
	  (*_map)[i][j]->draw(_shader, _clock);
    }
  
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);

  for (size_t i = 0; i < _bombs.size(); ++i)
    _bombs[i]->draw(_shader, _clock);

  for (size_t i = 0; i < _fires.size(); ++i)
    _fires[i]->draw(_shader, _clock);

  _context.flush();
}

void	GameEngine::explosion(Bomb* b)
{
  float x = b->getPosX();
  float z = b->getPosZ();

  Fire* f;
  f = new Fire(x, z, _map, &_objects);
  if (!f->initialize())
    return;
  _fires.push_back(f);
  f = new Fire(x - 1.0, z, _map, &_objects);
  if (!f->initialize())
    return;
  _fires.push_back(f);
  f = new Fire(x + 1.0, z, _map, &_objects);
  if (!f->initialize())
    return;
  _fires.push_back(f);
  f = new Fire(x, z - 1.0, _map, &_objects);
  if (!f->initialize())
    return;
  _fires.push_back(f);
  f = new Fire(x, z + 1.0, _map, &_objects);
  if (!f->initialize())
    return;
  _fires.push_back(f);
}
