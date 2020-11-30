#include "linkedlist.h"

//Programmer: Dana Solitaire
namespace DS {

	void linkedList::insertItem(node::value_type entry) {
	//3 Local node pointers
	// a current cursor and previous cursor
		node* currentCursor;
		node* previousCursor;
		node* addressNewNode;
		
	// as well as one to store the address to the new node

	//Set the previous cursor to null
	//Set the current cursor to head
		currentCursor = head;
		previousCursor = nullptr;
	//While the cursor is not null and new entry > cursor value
		while (currentCursor != nullptr && entry > currentCursor->getData()) {
			//Set previous cursor to current cursor
			previousCursor = currentCursor;
			//Set current cursor to cursor next
			currentCursor = currentCursor->next();
		}
	
	//NOW WE are at the location to ADD the new node
	//Create a new and save the address to the 3rd local variable
	// The next pointer should be set to the cursor
	addressNewNode = new node(entry, currentCursor);
	//If previous cursor is null, we have an empty list, so 
	//set head to point to the new node. Otherwise, set previous cursors 
	if (previousCursor == nullptr)
		head = addressNewNode;
	else
		previousCursor->setNext(addressNewNode);
	//next to point to the new node.
	}

	
	void linkedList::makeList(const node::value_type entry[], const size_t& count) {
		//2 Local variables, node pointers, one to keep track of current position (cursor)
		// and one to contain a new node
		node *cursor;
		node *newNode;
		cursor = nullptr;
		newNode = nullptr;
		//Delete the entire current list
		
		//if count is zero, do nothing
		if (count != 0) {
			deleteList();
		}

		//Create a new node with the first entry in items pointed to by head
		head = new node(entry[0]);
		cursor = head;
		//While more nodes to add
			//Create a new node and store the pointer to a variable for now
			//with the value of the next entry. The next field should be null
		for (size_t i = 0; i < count -1; ++i) {
			newNode = new node(entry[i+1]);
			cursor->setNext(newNode);
			cursor = newNode;
		}
			//Set the next field of the cursor to point to the new node
			//Move the cursor to point to the new node

	}

	void linkedList::deleteList(){
		//While head is not null
		node *temp;
		temp = nullptr;
		while (head != nullptr)
		{
			//Set a temporary pointer to head
			temp = head;
			//Set head to node AFTER the node pointed to by head
			head = head->next();
			//Delete the node pointed to by the temporary pointer
			delete temp;
		//Set head to null
		}
		head = nullptr;
	}

} //end of namespace