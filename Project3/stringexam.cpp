//Program Name: Project x
//Programmer Name: Prof. Miller
//Date Submitted: Not submitted
//File Purpose: doubly linked node
//Date Updated: n/a
//Purpose for Update: n/a
//Global Variable List: n/a (avoid these)

// A program that runs random (but not thorough) tests on string list objects.
// The tests involve only the constructors, assignment operator, length
// function, and the += operators.

#include <iostream>    // Provides cin and cout
#include <cstring>
#include <string>
#include "stringlist.h"  // Provides stringlist class
using namespace std;
using namespace DS;

enum comparison { EQUAL, NOTEQUAL, LE, GE, LESS, GREATER };
const string COMPARISON_NAMES[] = { "==", "!=", "<=", ">=", "<", ">" };
const int MANY = 6;
const string WORDS[] = {
		"t",
		"quick",
		"brown",
		"fox",
		"",
		"01234567890012345678900123456789001234567890012345678900123456789"
};

bool samelist(const string& s1, const stringlist& s2)
{
	if (s1.length() != s2.length())
		return false;

	size_t i = 0;
	for (auto i2 = s2.cbegin(); i2 != s2.cend(); ++i2, ++i)
	{
		if (s1[i] != *i2)
			return false;

	}

	return true;
}

bool same(const string& s1, const stringlist& s2)
{
	size_t i;

	if (s1.length() != s2.length())
		return false;

	for (i = 0; i < s1.length(); ++i)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;
}

bool sameitr(std::string::const_iterator s1b, std::string::const_iterator s1e,
	stringlist::const_iterator s2b, stringlist::const_iterator s2e)
{
	for (; s1b != s1e && s2b != s2e; ++s1b, ++s2b)
	{
		if (*s1b != *s2b)
			return false;
	}
	return true;
}

bool test_comparisons(string a1, string a2, comparison which)
{
	stringlist s1(a1.c_str());
	stringlist s2(a2.c_str());

	switch (which)
	{
	case EQUAL:    return ((a1 == a2) == (s1 == s2));
	case NOTEQUAL: return ((a1 != a2) == (s1 != s2));
	case LE:       return ((a1 <= a2) == (s1 <= s2));
	case GE:       return ((a1 >= a2) == (s1 >= s2));
	case LESS:     return ((a1 < a2) == (s1 < s2));
	case GREATER:  return ((a1 > a2) == (s1 > s2));
	}
	return false;
}

int test_value_semantics(string s)
{
	stringlist s1(s.c_str());
	stringlist s2(s1);
	stringlist s3;
	stringlist s4;

	s3 = s2;
	s4 = s2;
	s4 = s2;

	return samelist(s, s1) + samelist(s, s2) +
		samelist(s, s3) + samelist(s, s4);
}

int main()
{
	int passed;       // Number of tests passed in one part of the program
	int score = 0;    // Number of tests passed overall
	int total = 0;    // Number of tests run
	int i, j, which;  // Index counters
	string s, sABC("abc");         // A string to test the += operator
	stringlist mys; // A string to test the += operator
	stringlist abc; // A string to test the += operator

	// Introductory message.
	cout << "This program runs a few tests on your string class.\n";
	cout << "Please note that most of these tests require\n";
	cout << "valid list at headptr.\n" << endl;

	// Test the constructors and assignment operator:
	cout << "Testing constructors and assignments..." << endl;
	passed = 0;
	for (i = 0; i < MANY; ++i)
	{
		if (test_value_semantics(WORDS[i]) >= 3) ++passed;
	}
	if (test_value_semantics(WORDS[0]) == 4) ++passed;
	cout << "Passed " << passed << " out of " << (MANY + 1) << "." << endl;
	score += passed;
	total += MANY + 1;

	// Test the += operator
	cout << "Testing the += operators..." << endl;
	passed = 0;
	s += 'x';
	mys += 'x';
	if (samelist(s, mys)) ++passed;
	for (i = 0; i < MANY; ++i)
	{
		s += WORDS[i]; mys += WORDS[i].c_str();
		if (samelist(s, mys)) ++passed;
	}
	s += "abc";
	abc = "abc";
	mys += abc;
	if (samelist(s, mys)) ++passed;
	cout << "Passed " << passed << " out of " << MANY + 2 << "." << endl;
	score += passed;
	total += MANY + 2;

	// Test the [] operator and length
	cout << "Testing the []operator and length..." << endl;
	passed = 0;
	if (same(sABC, abc)) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	++total;

	// Test a self-assignment:
	cout << "Testing a self-assignment..." << endl;
	passed = 0;
	s = s;
	mys = mys;
	if (samelist(s, mys)) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	++total;

	// Test a self +=:
	cout << "Testing a self application of the += operator..." << endl;
	passed = 0;
	s += s;
	mys += mys;
	if (samelist(s, mys)) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	++total;
	
	// Test the Boolean operators
	for (which = EQUAL; which <= GREATER; ++which)
	{
		cout << "Testing the Boolean operator "
			<< COMPARISON_NAMES[which] << "..." << endl;
		passed = 0;
		for (i = 0; i < MANY; ++i)
			for (j = 0; j < MANY; ++j)
				if (test_comparisons(WORDS[i], WORDS[j], comparison(which)))
					++passed;
		if (passed == MANY * MANY)
		{
			cout << "Passed 1 out of 1." << endl;
			++score;
		}
		else
			cout << "Passed 0 out of 1." << endl;
		++total;
	}
	
	// Testing clear
	cout << "Testing clear..." << endl;
	passed = 0;
	s.clear();
	mys.clear();
	if (samelist(s, mys)) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	++total;


	// Testing c_str;
	char cstr[255];
	cout << "Testing c_str..." << endl;
	passed = 0;
	mys = "abc";
	mys.c_str(cstr);
	if (strcmp(cstr, "abc") == 0) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	++total;

	/*
	// Testing insert
	cout << "Testing insert..." << endl;
	passed = 0;
	s = "abc";
	mys = "abc";
	s.insert(2, sABC.c_str());
	mys.insert(2, sABC.c_str());
	if (samelist(s, mys)) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	total += 1;

	// Testing insert
	cout << "Testing insert iva iterator..." << endl;
	passed = 0;
	s = "abcdef";
	mys = "abcdef";
	auto it1 = s.begin();
	auto it2 = mys.cbegin();
	for (size_t i = 0; i < 3; ++i) { ++it1; ++it2; }
	s.insert(it1, 'Z');
	mys.insert(it2, 'Z');
	if (samelist(s, mys)) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	total += 1;

	// Testing reverse iterator
	cout << "Testing reverse iterator..." << endl;
	passed = 0;
	abc = "abc";
	s = "";
	for (auto it = abc.crbegin(); it != abc.crend(); --it) {
		s += *it;
	}
	if (s.compare("cba") == 0) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	++total;

	// Testing find
	cout << "Testing find iterator..." << endl;
	passed = 0;
	s = "apples can be green and round and green beans";
	abc = "apples can be green and round and green beans";
	mys = "green";
	auto fs = abc.find(mys);
	if (sameitr(s.substr(14).begin(), s.end(), fs, mys.end())) ++passed;
	fs = abc.find(mys, ++fs);
	if (sameitr(s.substr(34).begin(), s.end(), fs, mys.end())) ++passed;
	cout << "Passed " << passed << " out of 2." << endl;
	score += passed;
	total += 2;

	cout << "Testing find fail..." << endl;
	passed = 0;
	abc = "apples can be green and round";
	mys = "purple";
	auto ffs = abc.find(mys);
	if (ffs == mys.end()) ++passed;
	cout << "Passed " << passed << " out of 1." << endl;
	score += passed;
	++total;
	*/
	// Print results
	cout << "Total for these little tests: "
		<< score << " out of " << total << "." << endl;

	return 0;
}