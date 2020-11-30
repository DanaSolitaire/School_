/*
 * dictionary.h
 *
 *  Created on: Apr 23, 2016
 *      Author: steve
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <string>
#include "table.h"

#define TABLESIZE 811

namespace LABHASH
{

	struct dictionary_t {
		std::string key;
		std::string definition;

		bool operator==(const dictionary_t& rhs) const { return key == rhs.key; }
		bool operator!=(const dictionary_t& rhs) const { return key != rhs.key; }
	};


	dictionary_t getflag(short flag);

	//!!!! Needs implemenation !!!!!
	//Precondition: s is a word
	//Postcondition: An unsigned index from 0 to TABLESIZE is returned
	int hashkey(const  std::string& s);


} //End namespace

#endif /* DICTIONARY_H_ */
