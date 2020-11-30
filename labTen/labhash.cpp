//============================================================================
// Name        : labhash.cpp
// Author      : Dana Solitaire
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "table.h"
#include "dictionary.h"

namespace LABHASH {
	dictionary_t getflag(short flag) {
		dictionary_t dataFlag;
		switch (flag) {

		case PREV_USED:
			dataFlag.key = "foo";
			return dataFlag;
		case NEVER_USED:
			dataFlag.key = "";
			return dataFlag;
		}
		return dataFlag;
	}
}

using namespace std;
using namespace LABHASH;

string awsomeLine(size_t n) {
	string s;
	for (size_t i = 0; i < n; ++i)
		s += '-';
	return s;
}

void printDefinition(table<dictionary_t, string, TABLESIZE, getflag, hashkey>& t, const std::string& word) {
	bool found;
	dictionary_t def;

	t.find(word, found, def);

	if (found) {
		cout << "\nDefinition for \"" << word << "\":" << endl;
		cout << awsomeLine(word.length() + 20) << endl;
		cout << def.definition << endl;
	}
	else {
		cout << "\n" << word << " not found in dictionary." << endl;
	}
	return;
}

int main(int argc, char* argv[]) {

	table<dictionary_t, string, TABLESIZE, getflag, hashkey> dicttable;
	string sBuffer;

	ifstream ins;

	ins.open(argv[1]);
	if (ins.fail()) {
		cerr << "Unable to open dictionary" << endl;
		return 5;
	}

	while (!ins.eof()) {
		dictionary_t newItem;
		do {

			ins >> sBuffer;
			if (sBuffer != "-") {
				if (!newItem.key.empty())
					newItem.key += " ";
				newItem.key += sBuffer;
			}

		} while (sBuffer != "-");
		getline(ins, newItem.definition);

		dicttable.insert(newItem);

	}

	cout << "Welcome to the C++ Dictionary" << endl << endl;
	do {

		cout << endl << "Term to define or enter to quit: ";
		getline(cin, sBuffer);

		if (!sBuffer.empty())
			printDefinition(dicttable, sBuffer);

	} while (!sBuffer.empty() && !cin.eof() && cin.good());

	cout << "\nCollisions Encountered: " << dicttable.collision_stats() << endl;

	return 0;
}
