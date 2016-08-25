//
//  VectorToString.cpp
//  cppFindDivisors
//
//  Created by Brendon Votteler on 25/08/2016.
//  Copyright © 2016 Brendon. All rights reserved.
//

#include "ConverterUtil.hpp"


std::string ConverterUtil::intVectorToStr(const std::vector<int> input) {
  std::ostringstream oss;
  
  for(int i = 0; i < input.size(); i++) {
    if(i > 0)
      oss << ", ";
    
    oss << input[i];
  }
  
  return oss.str();
}
