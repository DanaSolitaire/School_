#include "BoggleBoard.hxx"

//currentBoardPtr& = new bogglecubens::BoggleCube[6];
namespace bogglens
{
	BoggleBoard::BoggleBoard(unsigned passed_version_number)
	{
		currentBoardPtr = nullptr;
		switch (passed_version_number)
		{
		case 0: 
			newGame(passed_version_number); board_version = "Boggle 4x4 (1973)"; user_passed_index = 0;
			break;
		case 1: 
			newGame(passed_version_number); board_version = "Boggle 4x4 (1987)"; user_passed_index = 1;
			break;
		case 2: newGame(passed_version_number); board_version = "Big Boogle 5x5"; user_passed_index = 2;
			break;
		case 3: newGame(passed_version_number); board_version = "Boggle Deluxe/Master 5x5"; user_passed_index = 3;
			break;
		}
	}

	void BoggleBoard::newGame(unsigned passed_version)
	{
		std::string board_str = Board_Version[passed_version];
		if (passed_version == 0 || passed_version == 1)
		{
			currentBoardSize = 16;
			currentBoardPtr = new bogglecubens::BoggleCube[currentBoardSize];
		}
		else
		{
			currentBoardSize = 25;
			currentBoardPtr = new bogglecubens::BoggleCube[25];
		}
		for (unsigned i = 0; i < (board_str.length() / 6); ++i)
		{
			char temp_char_array[7];
			std::string cube_str = board_str.substr(6 * i, 6);
			strcpy_s(temp_char_array, cube_str.c_str());
			bogglecubens::BoggleCube temp_cube(temp_char_array);
			currentBoardPtr[i] = temp_cube;
		}
	}

	BoggleBoard::~BoggleBoard()
	{
	}
	unsigned BoggleBoard::size() const
	{
		return currentBoardSize;
	}

	const std::string& BoggleBoard::version() const
	{
		return board_version;
	}
	void BoggleBoard::display()
	{
		std::cout << std::endl;
		for (unsigned i = 0; i < sqrt(currentBoardSize * 2) + 1; i++)
		{
			for (unsigned j = 0; j < sqrt(currentBoardSize * 2) + 1; j++)
			{
				if (i % 2 == 0)
				{
					if (j % 2 == 0)
						std::cout << "+";
					else
						std::cout << "---";
				}
				else {
					if (j % 2 == 0)
						std::cout << "|";
					else
					{
						//bogglecubens::BoggleCube* iter = currentBoardPtr;
						bogglecubens::BoggleCube* end = currentBoardPtr + j;
						char boardLetter = end->letter();
						//char boardLetter = currentBoard.at(j).letter();
						if (boardLetter == ' Q ')
							std::cout << ' Qu ';
						else
							std::cout << " " << boardLetter <<" ";
					}
				}
			}
			std::cout << std::endl;
		}
	}

	void BoggleBoard::mix()
	{
		std::random_shuffle(currentBoardPtr, currentBoardPtr + currentBoardSize);
		for (unsigned i = 0; i < currentBoardSize; ++i)
		{
			currentBoardPtr->randomize();
		}
	}
	
	bogglecubens::BoggleCube BoggleBoard::at(unsigned passed_index)
	{
		bogglecubens::BoggleCube* end = currentBoardPtr + passed_index;
		return *end;
	}

	std::string& BoggleBoard::toString()
	{
		//bogglecubens::BoggleCube* end = currentBoardPtr[0] + currentBoardSize;
		bogglecubens::BoggleCube* end = currentBoardPtr + currentBoardSize;
		std::string return_str;
		for (bogglecubens::BoggleCube* i = currentBoardPtr; i != end; ++i)
		{
			return_str += i->letter();
		}
		return return_str;
	}

}