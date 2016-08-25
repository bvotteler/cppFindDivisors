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
  return findDivisorsForV2(number);
};


// first attempt: brute force
vector<int> DivisorsFinder::findDivisorsForV1(const int number) {
  // must be positive non-zero
  if(number < 1)
    return vector<int>();
  
  vector<int> results;

  // classic brute force: try all numbers and see if they are a divisor
  for(int i = 1; i <= number; i++) {
    if(number % i == 0)
      results.push_back(i);
  }
  
  return results;
};

// second attempt: be more smart about odd numbers and upper limits
vector<int> DivisorsFinder::findDivisorsForV2(const int number) {
  // must be positive non-zero
  if(number < 1)
    return vector<int>();

  vector<int> results;
  
  // 1 is always part
  results.push_back(1);
  
  // if the number is even, start from 2 and keep going in single increments
  // if the number is odd, start from 3 and skip even numbers; increment by 2
  // in all cases, the upper limit to check is the given number divided by 2 (incuded)
  int start;
  int increment;
  if(number % 2 == 0) { // even
    start = 2;
    increment = 1;
  } else { // odd
    start = 3;
    increment = 2;
  }
  
  int upper = number / 2;
  
  for(int i = start; i <= upper; i += increment) {
    if(number % i == 0)
      results.push_back(i);
  }
  
  // the number itself is also always part of it
  // note: can be 1, so check
  if(number > 1)
    results.push_back(number);
  
  return results;
};
