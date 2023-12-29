#include "hello_b.h"

A2dd::A2dd(int x,int y)
{
  gx = x;
  gy = y;
}

int A2dd::getSum()
{
  this.print_dummy_data();
  return gx + gy;
}

void A2dd::print_dummy_data(){
  std::cout<< "hello" << std::endl;
  std::cout<< "hello" << std::endl;
  std::cout<< "hello" << std::endl;
  std::cout<< "hello" << std::endl;
  std::cout<< "hello" << std::endl;
  std::cout<< "hello" << std::endl;
  std::cout<< "hello" << std::endl;
  int a = 0;
  int b = 1/a;
  std::cout<< "hello" << std::endl;
  std::cout<< "hello" << std::endl;
}