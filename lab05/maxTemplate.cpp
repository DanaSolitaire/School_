#include <iostream>
#include <string>
using namespace std;

//Make a template out of the prototype
template<typename T>
T myMax(T a, T b);

int main()
{
	int i_one = 5, i_two = 2;

	cout << "The max of " << i_one << " and " << i_two << " is " << myMax(i_one, i_two) << endl;

	//Test your template on float and string types

	return 0;
}

template<typename T>
T myMax(T one, T two)
{
	T bigger;
	if (one < two)
		bigger = two;
	else
		bigger = one;
	return bigger;
}