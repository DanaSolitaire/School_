#include <string>
#include <iostream>
#include "dictionary.h"
#include "table.h"

//Programmer: Dana Solitaire
namespace LABHASH
{

	int hashkey(const  std::string& s) {
		if (s.length() == 0)
			return 1; 
		return s.length() * 20;
	}

} // End of namespace
