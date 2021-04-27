#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;

#include <string>
using namespace std;

NumberWithUnits test1 {3, "km"};
NumberWithUnits test2 {3000, "m"};
NumberWithUnits test3 {300, "cm"};
NumberWithUnits test4 {3, "m"};
NumberWithUnits test5 {-300, "cm"};
NumberWithUnits kyg {1, "kg"};
NumberWithUnits kyg2 {1000, "g"};

 // atleast 20
TEST_CASE(" Errors in operator functions tests! ") {
  CHECK_THROWS_AS(test1+kyg,exception);// cant submit diffrent types.
  CHECK_THROWS_AS(test4+kyg,exception);// cant submit diffrent types.
  CHECK_THROWS_AS(test2-kyg,exception);// cant subtract diffrent types.
  CHECK_THROWS_AS(test1-kyg,exception);// cant subtract diffrent types.
  CHECK_THROWS_AS(test1-=kyg,exception);
  CHECK_THROWS_AS(test1-=kyg2,exception);
  CHECK_THROWS_AS(test2+=kyg,exception);
  CHECK_THROWS_AS(test2+=kyg2,exception);
  
  //Comparation - 5 tests
  CHECK_THROWS_AS(if(test1==test2),exception);// compare km - m
  CHECK_THROWS_AS(if(kyg2==kyg),exception);// compare kg - g
  CHECK_THROWS_AS(if(test1==kyg),exception);// cant compare to diffrent types. 
  CHECK_THROWS_AS(if(test3==kyg),exception);
  CHECK_THROWS_AS(if(test3!=kyg2),exception);
  CHECK_THROWS_AS(if(test3!=kyg),exception);
  CHECK_THROWS_AS(if(test4==kyg2),exception);// cant compare to diffrent types.

  //5 tests
  CHECK_THROWS_AS(if(test4>kyg2),exception);// cant compare to diffrent types.
  CHECK_THROWS_AS(if(test4<kyg2),exception);// cant compare to diffrent types.
  CHECK_THROWS_AS(if(test4>=kyg2),exception);// cant compare to diffrent types.
  CHECK_THROWS_AS(if(test4<=kyg2),exception);// cant compare to diffrent types.
  CHECK_THROWS_AS(if(kyg!=kyg2),exception);// cant compare to diffrent types.
    
}
