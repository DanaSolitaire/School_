#ifndef BOGGLEBOARDCLASS
#define BOGGLEBOARDCLASS

#include <string>
#include <cstring>
#include <cstdlib>
#include "BoggleCube.hxx"
#include <math.h>
#include <iostream>

namespace bogglens
{
	const std::string Boggle4x4_1973 = "AACIOTAHMORSEGKLUYABILTYACDEMPEGINTVGILRUWELPSTUDENOSW"
		"ACELRSABJMOQEEFHIYEHINPSDKNOTUADENVZBIFORX";
	const std::string Boggle4x4_1987 = "AAEEGNELRTTYAOOTTWABBJOOEHRTVWCIMOTUDISTTYEIOSST"
		"DELRVYACHOPSHIMNQUEEINSUEEGHNWAFFKPSHLNNRZDEILRX";
	const std::string Boggle5x5 = "AAAFRSAAEEEEAAFIRSADENNNAEEEEMAEEGMUAEGMNNAFIRSY"
		"BJKQXZCCENSTCEIILTCEILPTCEIPSTDDHNOTDHHLORDHLNORDHLNOREIIITTEMOTTTENSSSUFIPRSY"
		"GORRVWIPRRRYNOOTUWOOOTTU";
	const std::string BoggleMaster5x5 = "AAAFRSAAEEEEAAFIRSADENNNAEEEEMAEEGMUAEGMNNAFIRSY"
		"BJKQXZCCNSTWCEIILTCEILPTCEIPSTDHHNOTDHHLORDHLNORDDLNOREIIITTEMOTTTENSSSUF"
		"IPRSYGORRVWHIPRRYNOOTUWOOOTTU";
	const std::string VERSION[7] = { "Boggle4x4(1973)", "Boggle 4x4(1987)", "Big Boggle 5x5","Boggle Deluxe / Master 5x5",
		"(unavailable)Boggle Challenge 5x5", "(unavailable)Boggle Winning Moves 5x5(2011) a lousy game", 
		"(unavailable)Boggle Winning Moves 6x6(2012) a very lousy game" };
	const std::string Board_Version[4] = { Boggle4x4_1973, Boggle4x4_1987, Boggle5x5, BoggleMaster5x5 };
	const size_t VERSIONS = 7;

	class BoggleBoard
	{
	public:
		BoggleBoard(unsigned);
		~BoggleBoard();
		void mix();
		unsigned size() const;
		const std::string& version() const;
		bogglecubens::BoggleCube at (unsigned);
		std::string& toString();
		void display();
		void newGame(unsigned);
		

	protected:
		std::string board_version;
		unsigned user_passed_index;
		unsigned currentBoardSize;
		bogglecubens::BoggleCube* currentBoardPtr;
	};
}
#endif
 