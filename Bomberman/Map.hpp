//
// Map.hpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Sat May  2 14:59:35 2015 Nawin Kim
// Last update Sat May  9 22:31:58 2015 Nawin Kim
//

#ifndef		MAP_HPP_
#define		MAP_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

#include "AObject.hpp"
#include "Cube.hpp"

class Map
{
private:
  std::vector<std::vector<AObject*> >	_map;
  std::string				_filename;

  int					_z;
  int					_x;
  
public:
  Map(const std::string& filename):
    _filename(filename)
  {
  }

  ~Map()
  {
    for (size_t i = 0; i < _map.size(); ++i)
      {
	for (size_t j = 0; j < _map[i].size(); ++j)
	  delete _map[i][j];
      }
  }

  bool		load()
  {
    std::ifstream file(_filename.c_str(), std::ios::in);
    std::vector<AObject*> tmp;
    std::string	       	line;
    unsigned int	size_line;

    _z = 0;
    _x = 0;
    if (!file)
      {
	std::cout << "Cannot load map " << _filename << std::endl;
	return false;
      }
    AObject* obj;
    while (getline(file, line))
      {
	if (_x < line.size())
	  _x = line.size();
	for (unsigned int i = 0; i < line.size(); ++i)
	  {
	    switch (line[i])
	      {
	      case 'w':
		{
		  obj = new Cube(glm::vec3(i, 0, _z), "./assets/stone.tga", AObject::WALL);
		  if (!obj->initialize())
		    {
		      std::cout << "Fail to draw wall" << std::endl;
		      return false;
		    }
		  break;
		}
	      case 'c':
		{
		  obj = new Cube(glm::vec3(i, 0, _z), "./assets/box.tga", AObject::BOX);
		  if (!obj->initialize())
		    {
		      std::cout << "Fail to draw box" << std::endl;
		      return false;
		    }
		  break;
		}
	      case '.':
		{
		  obj = NULL;
		  break;
		}
	      default:
		{
		  std::cout << "Wrong element" << std::endl;
		  obj = NULL;
		  break;
		}
	      }
	    tmp.push_back(obj);
	  }
	_map.push_back(tmp);
	tmp.clear();
	line.clear();
	_z++;
      }
    return true;
  }

  int	getMaxX() const
  {
    return _x;
  }
  int	getMaxZ() const
  {
    return _z;
  }
  std::vector<std::vector<AObject*> >*	getMap()
  {
    return &_map;
  }
};

#endif
