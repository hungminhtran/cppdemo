#include "hello_b.h"
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<A2dd> a2dd = std::shared_ptr<A2dd>(new A2dd(3, 4));

  std::cout << a2dd->getSum();
  return 0;
}