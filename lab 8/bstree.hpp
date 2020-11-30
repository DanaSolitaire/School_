//Precondition: root_ptr points to a binary tree with at least one node
//Postcondition: Height of the tree is returned recursively, recall that a tree 
//  with one node is height of 0 and an empty tree has a height of -1
template < typename Item>    //long bstree<Item>::bst_height(const  binary_tree_node<Item>* root_ptr) const
long bstree<Item>::bst_height(const  binary_tree_node<Item>* root_ptr) const
{
	if (root_ptr->is_leaf())
		return 0.0;

	else if (root_ptr == nullptr)
		return -1.0;

	return 1 + bst_height(root_ptr->left()) + bst_height(root_ptr->right());
}


//Precondition: Tree has at least one node, ie height >= 0
//Precondition: Inserts newDataItem into the binary search tree in the correct spot.
template <typename Item>
void bstree<Item>::bst_insert(const Item& target, binary_tree_node<Item>* node_ptr)
{
	if (node_ptr->is_leaf() && node_ptr->data() <= target)
	{	
		binary_tree_node<Item>* insert;
		insert->set_data(target);
		node_ptr->set_left(insert);
	}

	else if (node_ptr->is_leaf() && node_ptr->data() > target)
	{
		binary_tree_node<Item>* insert;
		insert->set_data(target);
		node_ptr->set_right(insert);
	}
	bst_insert(node_ptr->right());
	bst_insert(node_ptr->left());
}

//Precondition: root_ptr is a root pointer of a binary search tree
//Postcondition: Returns true if target is in the BST, false otherwise
template <typename Item>
bool bstree<Item>::in_bst(const Item& target, binary_tree_node<Item>* root_ptr)
{
	if (root_ptr->data() == target)
		return true;
	else if (root_ptr->is_leaf())
		return false;

	in_bst(root_ptr->left());
	in_bst(root_ptr->right());
}

//Precondition: root_ptr is a root pointer of a binary search tree or may be
//  NULL for an empty tree).
//Postcondition: If target was in the tree, then one copy of target has been 
//  removed, and root_ptr now points to the root of the new 
//  (smaller) binary search tree. In this case the function returns true.
//  If target was not in the tree, then the tree is unchanged (and the
//  function returns false).
template <typename Item>
bool bstree<Item>::bst_remove(const Item& target, binary_tree_node<Item>*& root_ptr)
{
	if (root_ptr == nullptr)
		return false;
	else if (root_ptr->data() < target)
	{

	}
	else if (root_ptr->data() > target)
	{

	}
	if (root_ptr->data() == target)
	{
		if (root_ptr->left()->is_leaf() == false)
			root_ptr->left()->set_left(nullptr);
		return true;
	}
}
//1 : tree is emtpy
//2 : Tree not empty, target < than root
//3 : tree not empty, target > than root
//4 target == root node, do not need to check, if not < or >, than it is ==
//4a The root node has no left child
//4bThe root does have a left child

//Precondtion: root_ptr is a root pointer of a non-empty binary search tree
//Postcondition: The largest item in the BST bas been removed, and the root_ptr
//  now points to the root of the new (smaller) BST. The reference parameter,
//  removed, has been set to a copy of the removed item.
template <typename Item>
void bstree<Item>::bst_remove_max(binary_tree_node<Item>*& root_ptr, Item& removed)
{
	if (root_ptr->data() > removed)
		removed = root_ptr->data();
	bst_remove_max(root_ptr->left());
	bst_remove_max(root_ptr->right());
}