#include "Headers.h"
//#include "Universe.h"
//#include "Universe_Constructor.h"
//#include "universeOutput.h"


int main ()
{
	try{
	Universe u;
	u.Output ();
	u.BigBang ();
	//u.Output();
	}
	catch (std::runtime_error err)
	{
		cout<<err.what();
	}
	return 0;
	
}