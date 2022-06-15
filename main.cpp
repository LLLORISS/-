#include <iostream>
#include "Tree.h"

int main() {
	setlocale(LC_ALL, "Ukrainian");
	char symb[5] = { 'a','b','c','d','e' };
	int prob[5] = { 3,25,15,6,24};

	std::string line;
	TREE obj(symb, prob, 5);
	obj.PRINT();
	std::cout << "\nКодування: ";
	std::cin >> line;
	std::cout << obj.CODING(line) << std::endl;
	std::cout << "\nДекодування: ";
	std::cin >> line;
	std::cout << obj.DECODING(line) << std::endl;
	return 0;
}