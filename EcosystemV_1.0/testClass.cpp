#include <iostream>
#include "LinkedList.h"

class Test
{
public:
	int x;
	int y;	
};

void main()
{
	LinkedList * list = new LinkedList ();

	for (int i=0; i <= 5; ++i) {
		
		Test * t =	new Test();
		t->x	 =	10+i;
		t->y	 =	20+i;
		list->AddElement(t);
	}
	
	std::cout << "After Adding len=" <<list->GetLength() <<"\n";

	if (!list->IsEmpty())
		std::cout << "element got added......... \n";

	Test *	p;
	int		x;
	int		y;
	
	while (list->HasNext ()) {
		
		p=(Test *) (list->GetNext ());
		x = p->x;
		y = p->y;

		std ::cout << "x=" << x << "\n" ;
		std ::cout << "y=" << y << "\n\n" ;
	}
	
	std::cout << "After deleting len=" <<list->DeleteElement(p) << "\n";

	std::cout << list->GetLength() <<"\n";

	Test * t1 =	new Test();
	t1->x	 =	303;
	t1->y	 =	202;

	list->AddElement(t1);

	while (list->HasNext ()) {

		p = (Test *) (list->GetNext ());
		x = p->x;
		y = p->y;
		std ::cout << "x=" << x << "\n" ;
		std ::cout << "y=" << y << "\n\n" ;
	}

	std::cout << " At last len= "<< list->GetLength() ;

	std::cin.get();
}

