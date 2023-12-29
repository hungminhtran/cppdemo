#include <iostream>
#include <memory>
#include <./hello_b.h>

int main() {
	std::shared_ptr<A2dd> a2dd = new A2dd(3, 4);

	std::cout<< a2dd->getSum();
	return 0;
}