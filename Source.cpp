#include <iostream>
#include "Vector.h"
#include <ctime>

int main(void)
{
	double start = clock();
	Vector<int> object(1);
	object.insert(1, 2, 5);
	object.show();
	std::cout << "\n";
	std::cout << "Result of swap: ";
	object.swap();
	object.show();
	std::cout << std::endl;
	printf("Seconds = %.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}