#include <iostream>
#include "menu.h"
using namespace std;

int main()
{
	
	
	chooseFunction();
	
	deleteFlightList(head_flist);
	deleteAirplaneList(airplane_list);
	deleteTree(ps_root);

	return 0;
}
