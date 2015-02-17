#include "LinkedList.h"
#include <iostream>
#include <cassert>

LinkedList::LinkedList (void)
{
	vHead		= NULL;
//	vPrevious	= vHead;
	vListLength = 0;
}

LinkedList::~LinkedList (void)
{
	if (vHead != NULL) {
			free (vHead);
	}
}

bool LinkedList::AddElement (void * pObject)
{
			assert(pObject != NULL);

			// Create Node 
			Node * temp = (Node *) malloc (sizeof (Node)); 
			
			assert (temp != NULL);
			temp->object = pObject;

			// Insert Node
			if(InsertNode (temp) )
				return true;
			else 
				return false;
}


//Insert from rear.

bool LinkedList::InsertNode (Node * pNewNode )
{
	
	assert (pNewNode != NULL);

	if (vHead == NULL)
	{
		vHead		= pNewNode; //If newnode is the first node that is being inserted head=NULL
		//vPrevious	= vHead;
	
	}
	else {

		Node * temp = vHead;

		while (temp->next != NULL)

			temp = temp->next;

		temp->next = pNewNode;

	}

	//vPrevious = vHead; 

	++ vListLength;
	
	pNewNode->next = NULL;
	
	return true;
}

void * LinkedList::DeleteElement (void * pObject)
{
	if (!IsEmpty ()) {

		//std ::cout << "object=" << pObject << "\n" ; 

		Node * prev		= NULL;
		Node * current	= vHead;
		Node * temp;
		while (current != NULL) {
			
			if (current->object == pObject) {
				if(prev == NULL){
					vHead = current->next;
					}
				else 
				prev->next = current->next;
				temp = current->next;
				free (current);
				
			//	vPrevious = vHead; 
				
				-- vListLength;
				if ( !temp)
					return NULL;
				return temp->object;
			}
			prev	= current;
			current = current->next;
		}
		return NULL;
	
	} else
		return NULL; 

}


void * LinkedList::GetNext (void * pObject)
{
	if (!IsEmpty ()) {

		Node * temp ;
		temp = vHead;
		assert ( temp!= NULL);
		while (temp->next != NULL){
			 if(temp->object == pObject)
					 break;
			temp = temp->next;
		}
		if (temp->next != NULL)

			return temp->next->object; //return saved object.
		else 
			return NULL;
		
	}	else {
	
		std::cout << "list is Empty\n";

		return NULL;
	}
}
/*
bool LinkedList::HasNext ()
{
	
	if (vPrevious != NULL && !IsEmpty ())
		return true;
	
	else
		return false;
}
*/
int LinkedList::GetLength ()
{
	return vListLength;
}

bool LinkedList::IsEmpty ()
{
	if(vHead == NULL )
	
		return true;
	
	else 
	
		return false;
	
}

/*
void LinkedList::displayList ()
{
	assert (this != NULL); 

	LinkedList * temp = this->vNext;
	
	if (temp == NULL)
		
		std::cout << "The list is empty\n";
	
	while (temp != NULL) {
	
		std::cout << temp->vObject << "\t";

		temp = temp->vNext;
	}

	std::cout << "\n\n";
}
*/