
#include "Map.hpp"

Map::Map(const std::string& filename):
  _filename(filename)
{
}

Map::~Map()
{
  for (size_t i = 0; i < _map.size(); ++i)
    {
      for (size_t j = 0; j < _map[i].size(); ++j)
	delete _map[i][j];
    }
}

bool		Map::load()
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

int	Map::getMaxX() const
{
  return _x;
}

int	Map::getMaxZ() const
{
  return _z;
}

std::vector<std::vector<AObject*> >*	Map::getMap()
{
  return &_map;
}

