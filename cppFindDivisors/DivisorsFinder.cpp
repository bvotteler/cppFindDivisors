//
//  DivisorsFinder.cpp
//  cppFindDivisors
//
//  Created by Brendon Votteler on 25/08/2016.
//  Copyright © 2016 Brendon. All rights reserved.
//

#include "DivisorsFinder.hpp"
using std::vector;

// returns vector of divisors for positive number passed in, ordered from smallest to largest
// returns empty vector if passed in number is zero or negative
vector<int> DivisorsFinder::findDivisorsFor(const int number) {
  vector<int> results;
  
  // number must be positive
  if(number < 1)
    return results;
  
  // classic brute force: try all numbers and see if they are a divisor
  for(int i = 1; i <= number; i++) {
    if(number % i ==0)
      results.push_back(i);
  }
  
  return results;
};
