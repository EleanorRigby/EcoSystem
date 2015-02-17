#pragma once

//Linked List is a collection of Nodes.

struct Node
{
	void * object;					//object that Node will hold
	Node * next;					//Pointer to next Node.
	
};

class LinkedList
{

private:

		Node	*	vHead;
	//	Node	*   vPrevious;		//previous pointer used in getNext
		int			vListLength;	//stores length of the list
		bool		InsertNode		(Node * pNewnode);
		Node	*	CreateNode		(void	* pObject);

public:
					LinkedList		(void);
					~LinkedList		(void);
  
	  bool			AddElement		(void * pObject);
	   void *			DeleteElement	(void * pOject);		//return 0 - object not found, 1-Object Deleted, -1-List empty.
	   int			GetLength		();
   
	   /*	getNext will get the next Element after the already got element.
		*	hasNext looks if there are any elements after the current element.
		*	They goes back to get the first Element when it is used after insert or delete. 
		*	
		*/

	   void		*   GetNext			(void * pObject);
	   void		*   GetFirst		() { return vHead->object; }
	 //  bool			HasNext			();
	   bool			IsEmpty			();
	//   void			displayList		();
	
};

