//Precondition: Arg1 points to a complete binary tree which is also a valid 
//  MAX HEAP except for the root node
//Postcondition: The tree pointed to by p is a valid MAX HEAP


#include "treeheap.h"
#include <algorithm>
namespace LABTREEHEAP {
	template <class T>
	void treeheap<T>::heapify_downward(binary_tree_node<T>* root_ptr)
	{
		if (root_ptr->is_leaf())
		{
			if (root_ptr->left()->data() < root_ptr->right()->data())
			{
				std::swap(root_ptr->left()->data(), root_ptr->right()->data());
			}
			heapify_downward(root_ptr);
		}
	}
}