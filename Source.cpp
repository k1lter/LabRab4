#include <iostream>
#include "Vector.h"

int main(void)
{
	Vector<int> object;
	object.insert(1.1f);
	object.insert(2);
	object.insert(3.2f);
	object.insert(4);
	object.insert(1, 2, 5);
	object.show();
	std::cout << "\n";
	object.swap();
	object.show();
	std::cout << std::endl;
	system("pause");
	return 0;
}