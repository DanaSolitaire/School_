
#include <algorithm> //You may ONLY use copy from this library
#include "darray.h"
//Programmer: Dana Solitaire
namespace DS {

	//Copy Constructor (does a deep copy)
	darray::darray(const darray& source) {

		//TO DO	
		numberOfItems = source.numberOfItems;
		size_t i;
		data = new value_type[numberOfItems];
		for (i = 0; i < source.numberOfItems; ++i)
		{
			data[i] = source[i];
		}
	}

	//Assignment (does a deep copy, watch for self assignment)
	darray& darray::operator=(const darray& source) {
		//TO DO	
		if (this == &source)
			return *this;
		numberOfItems = source.numberOfItems;
		size_t i;
		data = new value_type[numberOfItems];
		for (i = 0; i < source.numberOfItems; ++i)
		{
			data[i] = source[i];
		}
		return *this;
	}

	//Precondition: None
	//Postcondition: Physical arrays size is increased by one.
	//  the entry is is added to the array in the position that maintains increasing order.
	//  No memory leaks.
	//  Linear search may be used.
	void darray::insert(value_type entry)
	{
		if (numberOfItems == 0)
		{
			data = new value_type[1];
			data[0] = entry;
		}
		else
		{
			size_t i = 0;
			value_type *temp = new value_type[numberOfItems+1];
			size_t entryIndex = 0;

			for (i = 0; i < numberOfItems; ++i)
			{
				if (data[i] > entry)
					entryIndex = i;
			}

			for (i = 0; i < numberOfItems + 1; ++i)
			{
				if (entryIndex == 0)
				{
					temp[0] = entry;
				}
				/*
				//places original items before insert index in original order
				if (i < numberOfItems - i)
					temp[i] = data[i];
					//inserts entry into the index they are being placed in
				if (i == entryIndex)
					temp[i + 1] = entry;*/

					//copies other elements after insert index in original order
					
				temp[i + 1] = data[i];
				
			}
			data = temp;
		}
		++numberOfItems;
	//To do
	}

	//Precondition: Array is at least size index+1
	//Postcondition: Array size is reduced by one with no memory leaks and claiming the least amount of memory.
	//  The new array has the same sequence as before minus the entry at index.
	//  The value of the item removed is returned.
	darray::value_type darray::remove(size_t index) 
	{
		size_t i = 0;
		value_type *temp = new value_type[numberOfItems - 1];
		size_t entryIndex = 0; 
		value_type removed = data[index];

		for (i = 0; i < numberOfItems; ++i)
		{
			//inserts entry into the index they are being placed in
			if (data[i] == data[index])
			{
				temp[i] = data[i + 1];
			}
			else
				temp[i] = data[i];
		}

		--numberOfItems;
		return removed;
	}

	size_t darray::size() const
	{
		return numberOfItems;
	}

	//Precondition: param is new size, which is one more than current size OR one less than current size
	//Postcondition: array is resized without any memory leaks
	void darray::resize(size_t) {
		//TO DO (OPTIONAL helper function)
	}

} /* namespace DS */
