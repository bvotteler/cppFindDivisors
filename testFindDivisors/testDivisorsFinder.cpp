//
//  testDivisorsFinder.cpp
//  cppFindDivisors
//
//  Created by Brendon Votteler on 25/08/2016.
//  Copyright © 2016 Brendon. All rights reserved.
//

#include "catch.hpp"
#include "DivisorsFinder.hpp"
#include <vector>
using std::vector;

TEST_CASE("Testing DivisorsFinder class") {
  DivisorsFinder df;
  
  SECTION("Finding divisors for 0 returns empty vector"){
    INFO("using findDivisorsFor")
    vector<int> result = df.findDivisorsFor(0);
    
    CHECK(result.empty());
  }
  
  SECTION("Finding divisors for -1 returns empty vector"){
    INFO("using findDivisorsFor")
    vector<int> result = df.findDivisorsFor(-1);
    vector<int> expected; // empty
    
    CHECK(result == expected);
  }
  
  SECTION("Find correct divisors for 1"){
    INFO("using findDivisorsFor")
    vector<int> result = df.findDivisorsFor(1);
    vector<int> expected;
    expected.push_back(1);
    
    //REQUIRE(!(result.empty()));
    //CHECK(result.size() == 1);
    CHECK(result == expected);
  }
  
  SECTION("Find correct divisors for 12 (= 1,2,3,4,6,12)"){
    INFO("using findDivisorsFor")
    vector<int> result = df.findDivisorsFor(12);
    vector<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    expected.push_back(4);
    expected.push_back(6);
    expected.push_back(12);
    
    CHECK(result == expected);
  }
  
  
}