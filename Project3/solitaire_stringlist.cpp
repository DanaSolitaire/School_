#include"stringlist.h"
#include <cctype>

namespace DS
{
	
	stringlist::stringlist()
	{	
		node* tail = new node('\0');
		tail->setPrev(nullptr);
		tail->setNext(nullptr);
		node* head = new node(' ');
		charCount = 0;
	}
	
	stringlist::stringlist(const value_type str[])
	{
		size_t size = strlen(str);							// gets length of the char array and sets it to charCount
		charCount = size;
		node* cursor;										// creates a cursor node to track current node
		node* newNode = new node (' ');
		node* tail = new node('\0');						// creates a doubly linked list 
		tail->setNext(nullptr);		
		if (charCount == 0)
			node* head = new node(' ');
															//		head -> first letter of array
		node* head = new node(str[0]);						//		tail -> '\0'
		head->setPrev(nullptr);							    //		cursor -> head
		head->setNext(tail);								//
		tail->setPrev(head);								//
		cursor = head;										//
		
		if (charCount != 1)
		{
			for (size_t i = 1; i <= size; ++i) {			// for loop adds the char from specific index to			
				newNode->setData(str[i]);					//		NewNode -> char at index
				newNode->setNext(tail);						//		cursor -> current node in list
				newNode->setPrev(cursor);					//		tail -> '\0'
				cursor->setNext(newNode);					//		head -> first letter of array
				tail->setPrev(newNode);						//
				cursor = cursor->next();					// updates cursor to point to next node (newNode)
			}
		}
	}

	stringlist::stringlist(const stringlist & source)
	{
															// creates a cursor node to track current node
		node* newNode = new node(' ');						//
		node* tail = new node('\0');						// creates a doubly linked list 
		tail->setNext(nullptr);		
		node* head = new node(' ');							//
															//
		if (source.charCount > 1 || source.head != nullptr)												
		{													//		head -> first letter of array
			head = source.head;								//
		}				
															//		tail -> '\0'
		head->setPrev(nullptr);							    //		cursor -> head
		head->setNext(tail);								//
		tail->setPrev(head);								//

		if (source.charCount > 1)
		{													// sets head to source stringlist head
			node* cursor;									// creates cursor and newNode for this stringlist and source stringlist
			node* newNode = new node(' ');					//	
			node* sourceCursor = new node(' ');				//
			cursor = sourceCursor = head;					// sets cursor and sourceCursor to head
			charCount = source.charCount;					// set charCount to source charCount
			while (sourceCursor->getData() != '\0') {		// while loop only loops when sourceCursor is not at tail ('\0')
				newNode->setData(sourceCursor->getData());	//		newNode -> char from source stringlist
				newNode->setNext(nullptr);					//		cursor -> current node from this stringlist
				newNode->setPrev(cursor);					//		sourceCursor -> current corresponding node from source stringlist
				cursor->setNext(newNode);					//
				cursor = cursor->next();					//
				sourceCursor = sourceCursor->next();		//
			}												//
			tail->setPrev(newNode);							//
		}
	}

	stringlist::~stringlist()
	{
	}

	void stringlist::clear()
	{	
		if (head != NULL)
		{
			node* cursor;									
			while (head->getData() != '\0')					
			{												
				cursor = head;								
				head = head->next();						
				head->setPrev(nullptr);						
				delete cursor;								
			}
		
		}
		node* head = new node(' ');
		node* tail = new node('\0');
		head->setPrev(nullptr);										
		charCount = 0;										
	}

	void stringlist::operator+=(const stringlist & addend)
	{
		node* newNode;
		node* cursor = tail->prev();
		node* sourceCursor = addend.head;
		while (sourceCursor->getData() != '\0')
		{
			newNode = sourceCursor;
			newNode->setPrev(cursor);
			newNode->setNext(tail);
			cursor->setNext(newNode);
			tail->setPrev(newNode);
			cursor = cursor->next();
			sourceCursor = sourceCursor->next();
		}
	}

	void stringlist::operator+=(const value_type addend[])
	{
		node* newNode = nullptr;
		node* cursor = tail->prev();
		size_t size = strlen(addend);					// gets length of the char array and sets it to charCount
		charCount += size;
		for (size_t i = 1; i <= size; ++i) {			// for loop adds the char from specific index to			
			newNode->setData(addend[i]);				//		NewNode -> char at index
			newNode->setNext(tail);						//		cursor -> current node in list
			newNode->setPrev(cursor);					//		tail -> '\0'
			cursor->setNext(newNode);					//		head -> first letter of array
			tail->setPrev(newNode);						//
			cursor = cursor->next();					// updates cursor to point to next node (newNode)
		}

	}

	void stringlist::operator+=(value_type addend)
	{
		node* newNode = new node(addend);				 
		node* cursor = tail->prev();
		++charCount;
		newNode->setPrev(cursor);
		newNode->setNext(tail);
		tail->setPrev(newNode);
		cursor->setNext(newNode);
	}

	//above not optimized for empty string

	stringlist & stringlist::operator=(const stringlist & source)
	{
		clear();
		head = source.head;								
		node* cursor;									
		node* newNode = nullptr;									
		node* sourceCursor;								
		cursor = sourceCursor = head;					
		charCount = source.charCount;					
		if (sourceCursor != NULL)
		{
			while (sourceCursor->getData() != '\0') {		// while loop only loops when sourceCursor is not at tail ('\0')
				newNode->setData(sourceCursor->getData());	//		newNode -> char from source stringlist
				newNode->setNext(nullptr);					//		cursor -> current node from this stringlist
				newNode->setPrev(cursor);					//		sourceCursor -> current corresponding node from source stringlist
				cursor->setNext(newNode);					//
				tail->setPrev(newNode);						//
				cursor = cursor->next();					//
				sourceCursor = sourceCursor->next();		//
			}
		}
		return *this;
	}

	stringlist & stringlist::insert(size_t pos, const value_type * s)
	{
		stringlist temp(s);
		node* cursor = head;
		node* nextCursor = nullptr;
		node* tempCursor = temp.head;

		for (size_t i = 0; i < pos; ++i)
		{
			cursor = cursor->next();								
		}
		nextCursor = cursor;
		cursor = cursor->prev();
		cursor->setNext(temp.head);
		temp.head->setPrev(cursor);
		nextCursor->setPrev(temp.tail->prev());
		temp.tail->prev()->setNext(nextCursor);

		return *this;
	}

	stringlist & stringlist::insert(size_t pos, const value_type * s, size_t n)
	{
		value_type *tempS;
		tempS = new value_type[n];
		for (size_t i = 0; i < n; ++i)
			tempS[i] = s[i];

		stringlist temp(tempS);
		node* cursor = head;
		node* nextCursor = nullptr;
		node* tempCursor = temp.head;

		for (size_t i = 0; i < pos; ++i)
		{
			cursor = cursor->next();										
		}
		nextCursor = cursor;
		cursor = cursor->prev();
		cursor->setNext(temp.head);
		temp.head->setPrev(cursor);
		nextCursor->setPrev(temp.tail->prev());
		temp.tail->prev()->setNext(nextCursor);

		return *this;
	}

	DS::stringlist::iterator stringlist::insert(const_iterator p, const value_type & c)
	{

		return iterator();
	}

	DS::stringlist::value_type stringlist::operator[](std::size_t position) const
	{
		if (position == 0)
			return head->getData();
		if (position == charCount)
			return tail->prev()->getData();
		node* cursor = head;
		for (size_t i = 1; i < charCount - 1; ++i) {
			if (i == position)
				return cursor->getData();
			else
				cursor = cursor->next();
		}
	}
	void stringlist::c_str(value_type * s) const
	{
		node* cursor;
		cursor = head;
		size_t i = 0;
		while (cursor->getData() != '\0')
		{
			s[i] = cursor->getData();
			cursor = cursor->next();
			++i;
		}
	}
	int stringlist::strcmp(const stringlist & right) const
	{
		node* newNode;														// created newNode and newRightNode to compare the data
		node* newRightNode;													// created cursor and rightCursor
		node* cursor = head;												//
		node* rightCursor = right.head;										//
		while (rightCursor->getData() != '\0')								// loops until rightCursor reaches the end of the right string
		{																	//
			while (cursor->getData() != '\0')								// loops until cursor reaches the end of the string
			{																// 
				newNode = cursor;											//		newNode -> cursor -> char
				newRightNode = rightCursor;									//		newRightNode -> rightCursor -> right char
				if (newNode->getData() < newRightNode->getData())			// if newNode char is less than newRightNode char returns -1
					return -1;												// 
				else if (newNode->getData() > newRightNode->getData())		// if newNode char is greater than newRightNode char return 1
					return 1;												//
				cursor = cursor->next();									// if the nodes' char match then cursor moves to the next this node
			}																// 
			cursor = head;													// reset the cursor to the head so this stringlist char can be compared
			rightCursor = rightCursor->next();								// to the next char in right
		}
		return 0;
	}

	DS::stringlist::iterator stringlist::find(const stringlist & target)
	{
		const_iterator targetItr = target.cbegin();
		iterator returned;
		const_iterator i;
		for (i = this->cbegin(); i != this->cend(); ++i)								// loops until rightCursor reaches the end of the right string
		{
			if (i == targetItr)
				return returned;
			++returned;
		}
	}
	DS::stringlist::iterator stringlist::find(const stringlist & target, const_iterator targetItr)
	{
		const_iterator i;
		iterator returned;
		for (i = this->cbegin(); i != this->cend(); ++i)
		{
			if (i == targetItr)
				return returned;
			++returned;
		}
	}


	bool operator==(const stringlist& s1, const stringlist& s2)
	{
		size_t outCome = s1.strcmp(s2);
		if (outCome == 0)
			return true;
		else
			return false;
	}

	bool operator !=(const stringlist& s1, const stringlist& s2)
	{
		size_t outCome = s1.strcmp(s2);
		if (outCome != 0)
			return true;
		else
			return false;
	}

	bool operator >=(const stringlist& s1, const stringlist& s2)
	{
		size_t outCome = s1.strcmp(s2);
		if (outCome == 1)
			return true;
		else
			return false;
	}

	bool operator <=(const stringlist& s1, const stringlist& s2)
	{
		size_t outCome = s1.strcmp(s2);
		if (outCome == -1)
			return true;
		else
			return false;
	}

	bool operator > (const stringlist& s1, const stringlist& s2)
	{
		size_t outCome = s1.strcmp(s2);
		if (outCome == 1)
			return true;
		else
			return false;
	}

	bool operator < (const stringlist& s1, const stringlist& s2)
	{
		size_t outCome = s1.strcmp(s2);
		if (outCome == -1)
			return true;
		else
			return false;
	}

	stringlist operator +(const stringlist& s1, const stringlist& s2)
	{
		/*
		char temp;
		for (size_t i = 0; i < s2.length(); ++i)
		{
			temp = s2[i];
			s1 += temp;
		}
		stringlist returned =  s1 += s2;
		
		*/
		return s1;
	}

	std::ostream& operator <<(std::ostream& outs, const stringlist& source)
	{
		for (size_t i = 0; i < source.length(); ++i)
		{
			outs << source[i];
		}
		return outs;
	}
	std::istream & getline(std::istream & ins, stringlist & target)
	{
		char read;
		while (ins && isspace(ins.peek()))									//Skips any whitespace before first char 
			ins.ignore();		
		read = ins.get();
		while (ins && !ins.eof())											//checks if we are at end of the file
		{
			target += read;													//adds char to end of stringlist target
			read = ins.get();
		}
		return ins;
	}

	std::istream& operator >>(std::istream& ins, stringlist& target)
	{
		char read;
		while (ins && isspace(ins.peek()))									//Skips any whitespace before first char 
			ins.ignore();
		read = ins.get();
		while (ins)															//checks if we are at end of the file
		{
			target += read;													//adds char to end of stringlist target
			read = ins.get();												//loads next char and assigns it to read char
		}
		return ins;

	}
}