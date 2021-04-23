#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"

/*
  class to represent state data - fairly redundent at this point but will use
  inheritence later - FILL IN
*/
class demogState {
  public:
   //FILL IN

    // constructor with no arguments puts -1 for all values as stud values
    demogState() {}


    friend std::ostream& operator<<(std::ostream &out, const demogState &SD);


	private:
    // state information
    const string state = "TOUPDATE"; // name of the state
    const int totalPopulation = -1; // the population of the state
    const int numCounties = -1; // number of counties imn the state

    // percentage data
    const double percentOver65 = -1; // age above 65
    const double percentUnder18 = -1; // age under 18
    const double percentUnder5 = -1; // age under 5
    const double percentBachelorPlus = -1; // bachelor degree or more
    const double percentHSPlus = -1; // high school educated or more
    const double percentPoverty = -1; // below poverty

    // count data
    const int countOver65 = -1; // age above 65
    const int countUnder18 = -1; // age under 18
    const int countUnder5 = -1; // age under 5
    const int countBachelorPlus = -1; // bachelor degree or more
    const int countHSPlus = -1; // high school educated or more
    const int countPoverty = -1; // below poverty

	//DATA here
};
#endif
