#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <iostream>
#include <vector>
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

    //constructor with two arguments: the abbreviation of the state and a vector 
    demogState(string state, vector<shared_ptr<demogData>> countyData);

    friend std::ostream& operator<<(std::ostream &out, const demogState &SD);


	private:
    // state information
    string stateName = "TOUPDATE"; // name of the state
    int totalPopulation = -1; // the population of the state
    int numCounties = -1; // number of counties imn the state

    // percentage data
    double percentOver65 = -1; // age above 65
    double percentUnder18 = -1; // age under 18
    double percentUnder5 = -1; // age under 5
    double percentBachelorPlus = -1; // bachelor degree or more
    double percentHSPlus = -1; // high school educated or more
    double percentPoverty = -1; // below poverty

    // count data
    int countOver65 = -1; // age above 65
    int countUnder18 = -1; // age under 18
    int countUnder5 = -1; // age under 5
    int countBachelorPlus = -1; // bachelor degree or more
    int countHSPlus = -1; // high school educated or more
    int countPoverty = -1; // below poverty

	//DATA here
};
#endif
