//
// main.cpp for bomberman in /home/nawin/rendu/cpp_bomberman
// 
// Made by Nawin Kim
// Login: kim_n <kim_n@epitech.net>
// 
// Started on  Mon Apr 27 13:22:58 2015 Nawin Kim
// Last update Fri May  1 22:06:54 2015 Nawin Kim
//


#include "GameEngine.hpp"

int	main(int ac, char **av)
{

  
 
  // create the engine
  GameEngine engine;
  if (engine.initialize() == false)
    return 1;
  while (engine.update() == true)
    engine.draw();
  
  return 0;
}
