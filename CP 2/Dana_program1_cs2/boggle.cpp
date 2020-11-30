#include <cstdlib>
#include <iostream>
#include "BoggleBoard.hxx"

int main(void)
{
  bogglens::BoggleBoard bboard(0);
  unsigned version;

  std::cout << "Welcome to Boggle!" << std::endl;

  std::cout << std::endl;
  
  std::cout << "Boggle Versions:" << std::endl;
  
  for(unsigned i = 0; i < bogglens::VERSIONS; ++i)
  {
    std::cout << i << " : " << bogglens::VERSION[i] << std::endl;
  }

  std::cout << std::endl;
  
  std::cout << "Which version would you like to play? (0-6): " << std::endl;
  do{
    std::cin >> version;
  }while(version > 3);  

  bboard.newGame(version);

  std::cout << std::endl;

  std::cout << "Size: " << bboard.size() << std::endl;
  std::cout << "Version: " << bboard.version() << std::endl;
  std::cout << "The current board:" << std::endl;

  std::cout << std::endl;

  bboard.display();

  std::cout << std::endl;

  std::cout << "The board after being mixed:" << std::endl;

  std::cout << std::endl;

  bboard.mix();
  bboard.display();

  std::cout << std::endl << std::endl;

  bboard.newGame(2);

  std::cout << "Size: " << bboard.size() << std::endl;
  std::cout << "Version: " << bboard.version() << std::endl;
  std::cout << "The board after newGame(2):" << std::endl;

  std::cout << std::endl << std::endl;

  std::cout << "at(10): " << bboard.at(10).letter() << std::endl;

  std::cout << "toString(): " << bboard.toString() << std::endl;

  return EXIT_SUCCESS;
}

