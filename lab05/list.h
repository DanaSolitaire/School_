#ifndef LIST_H_
#define LIST_H_

#include <iterator>
#include <cassert>
#include "node_dll.h"

namespace DS {

	template<typename NT, typename VT>
	class node_iterator : public std::iterator<std::forward_iterator_tag, NT, VT, NT&>
	{
	private:
		NT* itr;

	public:
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

		// two-way comparison: v.begin() == v.cbegin() and vice versa
		template<class TT>
		bool operator == (const node_iterator<TT, VT>& rhs)
		{
			return itr == rhs.itr;
		}

		template<class TT>
		bool operator != (const node_iterator<TT, VT>& rhs)
		{
			return itr != rhs.itr;
		}

		VT& operator* () const
		{
			return itr->data();
		}

		VT& operator-> () const
		{
			return itr->getData();
		}

		// Hack to allow us to create one iterator for both const and mutator
		operator node_iterator<NT, const VT>() const
		{
			return node_iterator<NT, const VT>(itr);
		}
	};

	template<typename T>
	class list {
	public:
		typedef T value_type;
		typedef DSDLL::node<value_type> node;
		typedef node_iterator<node, value_type> iterator;
		typedef node_iterator<node, const value_type> const_iterator;
		iterator begin() { return iterator(head); }
		iterator end() { return iterator(); }
		const_iterator begin() const { return const_iterator(head); }
		const_iterator end() const { return const_iterator(); }
		const_iterator cbegin() const { return const_iterator(head); }
		const_iterator cend() const { return const_iterator(); }
		list() : head(nullptr), tail(nullptr) {}
		virtual ~list();
		void insert(const value_type&, node* = nullptr);
	private:
		node * head;
		node * tail;
	};
} /* namespace DS */
#endif /* LIST_H_ */