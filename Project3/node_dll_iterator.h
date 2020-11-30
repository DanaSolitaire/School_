//Program Name:			Dana Solitaire
//Programmer Name:		Dana Solitaire 
//Attempt Number:		1
//Purpose:
//Purpose for Update:
//Global Variable List: Not any

#ifndef NODEDLL_ITERATOR_H_
#define NODEDLL_ITERATOR_H_

#include <iterator>
#include <cassert>
#include "node_dll.h"

namespace DS {

	template<typename NT, typename VT>
	class node_iterator : public std::iterator<std::bidirectional_iterator_tag, NT, VT, NT&>
	{
	public:
		friend class stringlist;
		node_iterator(NT* nd = nullptr) : itr(nd) {}

		node_iterator& operator++ () // Pre-increment
		{
			itr = itr->next();
			return *this;
		}

		node_iterator operator++ (int) // Post-increment
		{
			node_iterator returned(itr);
			itr = itr->next();
			return returned;
		}

		node_iterator& operator-- () // Pre-decrement
		{
			itr = itr->prev();
			return *this;
		}

		node_iterator operator-- (int) // Post-decrement
		{
			node_iterator returned(itr);
			itr = itr->prev();
			return returned;
		}

		// two-way comparison: v.begin() == v.cbegin() and vice versa
		template<class TT>
		bool operator == (const node_iterator<TT, VT>& rhs) const
		{
			if (this->itr == rhs.itr)
				return true;
			else
				return false;
		}

		template<class TT>
		bool operator != (const node_iterator<TT, VT>& rhs) const
		{
			if (this->itr != rhs.itr)
				return true;
			else
				return false;
		}

		VT& operator* () const
		{
			return itr->getData();
		}

		VT& operator-> () const
		{
			return this;
		}

		// Hack to allow us to create one iterator for both const and mutator
		//This function should remain as is
		operator node_iterator<NT, const VT>() const
		{
			return node_iterator<NT, const VT>(itr);
		}

	private:
		NT* itr;

	};

} /* namespace DS */

#endif /* NODEDLL_ITERATOR_H_ */