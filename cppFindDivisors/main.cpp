//
//  main.cpp
//  cppFindDivisors
//
//  Created by Brendon Votteler on 25/08/2016.
//  Copyright © 2016 Brendon. All rights reserved.
//

#include <iostream>
#include "DivisorsFinder.hpp"
#include "ConverterUtil.hpp"

int main(int argc, const char * argv[]) {
  if(argc < 2) {
    std::cout << "Please provide one number as argument to find its divisors" << std::endl;
    std::cout << "Example: cppFindDivisors 42" << std::endl;
    exit(0);
  }
  
  int in = atoi(argv[1]);
  std::cout << "Divisors for " << in << " are: ";
  std::cout << ConverterUtil::intVectorToStr( DivisorsFinder::findDivisorsFor(in) ) << std::endl;
  
  
  return 0;
}
