//
//  DivisorsFinder.hpp
//  cppFindDivisors
//
//  Created by Brendon Votteler on 25/08/2016.
//  Copyright © 2016 Brendon. All rights reserved.
//

#ifndef DivisorsFinder_hpp
#define DivisorsFinder_hpp

#include <vector>

class DivisorsFinder {
public:
  // the "main" version
  std::vector<int> findDivisorsFor(const int);

  // different versions go here, kept public so I can test them independently
  std::vector<int> findDivisorsForV1(const int);
  std::vector<int> findDivisorsForV2(const int);
  std::vector<int> findDivisorsForV3(const int);
  std::vector<int> findDivisorsForV4(const int);
  
private:
  bool isNumberPositive(const int number) {return (number > 0);}
  
};

#endif /* DivisorsFinder_hpp */
