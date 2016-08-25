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
  return findDivisorsForV4(number);
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

// third attempt: tweak upper limit
vector<int> DivisorsFinder::findDivisorsForV3(const int number) {
  // must be positive non-zero
  if(number < 1)
    return vector<int>();
  
  vector<int> results;
  
  // 1 is always part
  results.push_back(1);
  
  // if the number is even, start from 2 and keep going in single increments
  // if the number is odd, start from 3 and skip even numbers; increment by 2
  int start;
  int increment;
  if(number % 2 == 0) { // even
    start = 2;
    increment = 1;
  } else { // odd
    start = 3;
    increment = 2;
  }
  
  // the upper limit is a maximum of half the given number, but could be smaller
  // in fact, the upper limit is the given number divided by the first divisor larger than 1
  int upper = number / 2;
  bool foundFirstDivisor = false;
  
  for(int i = start; i <= upper; i += increment) {
    if(number % i == 0) {
      results.push_back(i);
      
      // adjust upper limit (happens once)
      if(!foundFirstDivisor) { // found it now
        upper = number / i;
        foundFirstDivisor = true;
      }
    }
  }
  
  // the number itself is also always part of it
  // note: can be 1, so check
  if(number > 1)
    results.push_back(number);
  
  return results;
};

// fourth attempt: every time we find a divisor, we actually found two
vector<int> DivisorsFinder::findDivisorsForV4(const int number) {
  // must be positive non-zero
  if(number < 1)
    return vector<int>();
  
  vector<int> results;
  
  // 1 is always part
  results.push_back(1);
  
  // the number itself is also always part of it
  // note: can be 1, so check
  if(number > 1)
    results.push_back(number);
  
  // if the number is even, next candidate is 2 and keep going in single increments.
  // if the number is odd, next candidate is 3 and skip even numbers; increment by 2.
  int next;
  int increment;
  if(number % 2 == 0) { // even
    next = 2;
    increment = 1;
  } else { // odd
    next = 3;
    increment = 2;
  }
  
  // for every divisor that we find we also found another one: the number divded by the divisor.
  // take that into account.
  // the upper limit then is completely variable, initialise with number-1 (number is included already).
  int upper = number-1;
  
  while(next <= upper) {
    if(number % next == 0) {
      
      // add this number to results
      results.push_back(next);
      
      // find corresponding divisor
      int partner = number / next;
      
      // partner can be identical to next, only add if different
      if(partner != next)
        results.push_back(partner);
      
      // adjust upper limit downward
      upper = partner-1;
    }
    
    // increment next
    next += increment;
  }
  
  // the vector is unsorted, sort before returning.
  std::sort(results.begin(), results.end());
  
  return results;
};

