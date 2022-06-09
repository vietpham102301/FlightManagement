#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Person{
	private:
		string id;
		int skin;
	public:
		void set_id(string id)
		{
			this->id = id;
		}
		string get_id()
		{
			return id;
		}
};

int main()
{
	unsigned int smt;
	while(1)
	{
		if(kbhit())
		{
			smt = getch();
			cout<<"code: "<<smt<<endl;
		}
	}
	system("pause");
	return 0;
}
