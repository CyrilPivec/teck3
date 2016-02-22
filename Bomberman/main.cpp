

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
