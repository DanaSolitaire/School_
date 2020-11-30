/*
 * table.h
 *
 *  Created on: Apr 23, 2020
 *      Author: S.Miller
 */

#ifndef TABLE_H_
#define TABLE_H_ 

 // FILE: table.h
 // TEMPLATE CLASS PROVIDED: Table<RecordType>
 //   This class is a container template class for a Table of records.
 //   The template parameter, RecordType, is the data type of the records in the
 //   Table. It may any type with a default constructor, a copy constructor,
 //   an assignment operator, and an integer member variable called key.
 //
 // CONSTRUCTOR for the Table<RecordType> template class:
 //   Table( )
 //     Postcondition: The counters are initialized and a vector is build WITHOUT being initialized
 //
 // MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
 //   void insert(const RecordType& entry)
 //     Precondition: table has at least TWO available slots
 //     Postcondition: If the table is empty, it is INITIALIZED before adding the entry.  If the table already had a record with a key equal to
 //     entry.key, then that record is replaced by entry. Otherwise, entry has
 //     been added as a new record of the Table.
 //
 //   void remove(int key)
 //     Postcondition: If a record was in the Table with the specified key, then
 //     that record has been removed; otherwise the table is unchanged.
 //		Only entry key is compared, the data is ignored.
 //
 // CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
 //   bool is_present(const Item& target) const
 //     Postcondition: The return value is true if there is a record in the
 //     Table with the specified key. Otherwise, the return value is false.
 //
 //   void find(int key, bool& found, RecordType& result) const
 //     Postcondition: If a record is in the Table with the specified key, then
 //     found is true and result is set to a copy of the record with that key.
 //     Otherwise found is false and the result contains garbage.
 //
 //   size_t size( ) const
 //     Postcondition: Return value is the total number of records in the
 //     Table.
 //
 // VALUE SEMANTICS for the Table<RecordType> template class:
 //   Assignments and the copy constructor may be used with Table objects.
 //

#include <cstdlib>    // Provides size_t
#include <cassert>
#include <vector>
#include <iostream>

namespace LABHASH
{

	enum FLAGS { NEVER_USED, PREV_USED };

	template <typename RecordType, typename KeyType, std::size_t TABLE_SIZE, RecordType getflag(short), int hashkey(const KeyType&)>
	class table
	{
	public:
		// CONSTRUCTORS AND DESTRUCTOR
		table();
		// MODIFICATION MEMBER FUNCTIONS
		void insert(const RecordType& entry); //Needs implementation
		void remove(const KeyType& key);
		// CONSTANT MEMBER FUNCTIONS
		void find(const KeyType& key, bool& found, RecordType& result) const;
		bool is_present(const KeyType& key) const;
		std::size_t size() const { return total_records; }
		unsigned long collision_stats() const { return collision_count; }
	private:
		std::vector<RecordType> data;
		std::size_t total_records;
		unsigned long collision_count;
		// HELPER MEMBER FUNCTION
		//std::size_t hash(const KeyType& key) const;
		bool is_never_used(std::size_t index) const { return data[index] == getflag(NEVER_USED); }
		bool is_vacant(std::size_t index) const { return data[index] == getflag(NEVER_USED) || data[index] == getflag(PREV_USED); }
	};

	template <typename RecordType, typename KeyType, std::size_t TABLE_SIZE, RecordType getflag(short), int hashkey(const KeyType&)>
	table<RecordType, KeyType, TABLE_SIZE, getflag, hashkey>::table()
	{
		total_records = 0;
		collision_count = 0;

		data.resize(TABLE_SIZE);

	}

	template <typename RecordType, typename KeyType, std::size_t TABLE_SIZE, RecordType getflag(short), int hashkey(const KeyType&)>
	bool table<RecordType, KeyType, TABLE_SIZE, getflag, hashkey>::is_present(const KeyType& key) const
	{
		std::size_t index = hashkey(key);

		while (data[index] != getflag(NEVER_USED) && data[index].key != key) {
			index = (index + 1) % TABLE_SIZE;
		}

		if (data[index].key == key)
			return true;

		return false;

	}

	template <typename RecordType, typename KeyType, std::size_t TABLE_SIZE, RecordType getflag(short), int hashkey(const KeyType&)>
	void table<RecordType, KeyType, TABLE_SIZE, getflag, hashkey>::remove(const KeyType& key)
	{
		std::size_t index = hashkey(key);

		while (data[index] != getflag(NEVER_USED) && data[index].key != key) {
			index = (index + 1) % TABLE_SIZE;
			std::cout << "done";
		}

		if (data[index].key == key)
			data[index] = getflag(PREV_USED);
	}

	template <typename RecordType, typename KeyType, std::size_t TABLE_SIZE, RecordType getflag(short), int hashkey(const KeyType&)>
	void table<RecordType, KeyType, TABLE_SIZE, getflag, hashkey>::find(const KeyType& key, bool& found, RecordType& result) const
	{
		found = false;
		std::size_t index = hashkey(key);

		while (data[index] != getflag(NEVER_USED) && data[index].key != key) {
			index = (index + 1) % TABLE_SIZE;
		}

		if (data[index].key == key) {
			result = data[index];
			found = true;
		}

	}

} //End namespace

//Hack, table.hpp will include students insert implementation
#include "table.hpp"

#endif /* TABLE_H_ */
