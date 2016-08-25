//
//  testVectorToString.cpp
//  cppFindDivisors
//
//  Created by Brendon Votteler on 25/08/2016.
//  Copyright © 2016 Brendon. All rights reserved.
//

#include "catch.hpp"
#include "ConverterUtil.hpp"
#include <vector>
using std::vector;

TEST_CASE("Testing ConverterUtil class") {
  
  SECTION("Check if vector to string conversion makes sense"){
    INFO("using intVectorToStr")
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(5);
    
    CHECK(ConverterUtil::intVectorToStr(test) == "1, 2, 5");
  }
}