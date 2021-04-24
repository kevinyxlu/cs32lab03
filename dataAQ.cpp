/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include <iostream>
#include <algorithm>

dataAQ::dataAQ() {}

/* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
void dataAQ::createStateData(std::vector<shared_ptr<demogData>> theData) {
    demogState AL();
    stateData["AL"] = nullptr;
    stateData["AK"] = nullptr;
    stateData["AZ"] = nullptr;
    stateData["AR"] = nullptr;
    stateData["CA"] = nullptr;
    stateData["CO"] = nullptr;
    stateData["CT"] = nullptr;
    stateData["DE"] = nullptr;
    stateData["FL"] = nullptr;
    stateData["GA"] = nullptr;
    stateData["HI"] = nullptr;
    stateData["ID"] = nullptr;
    stateData["IL"] = nullptr;
    stateData["IN"] = nullptr;
    stateData["IA"] = nullptr;
    stateData["KS"] = nullptr;
    stateData["KY"] = nullptr;
    stateData["LA"] = nullptr;
    stateData["ME"] = nullptr;
    stateData["MD"] = nullptr;
    stateData["MA"] = nullptr;
    stateData["MI"] = nullptr;
    stateData["MN"] = nullptr;
    stateData["MS"] = nullptr;
    stateData["MO"] = nullptr;
    stateData["MT"] = nullptr;
    stateData["NE"] = nullptr;
    stateData["NV"] = nullptr;
    stateData["NH"] = nullptr;
    stateData["NJ"] = nullptr;
    stateData["NM"] = nullptr;
    stateData["NY"] = nullptr;
    stateData["NC"] = nullptr;
    stateData["ND"] = nullptr;
    stateData["OH"] = nullptr;
    stateData["OK"] = nullptr;
    stateData["OR"] = nullptr;
    stateData["PA"] = nullptr;
    stateData["RI"] = nullptr;
    stateData["SC"] = nullptr;
    stateData["SD"] = nullptr;
    stateData["TN"] = nullptr;
    stateData["TX"] = nullptr;
    stateData["UT"] = nullptr;
    stateData["VT"] = nullptr;
    stateData["VA"] = nullptr;
    stateData["WA"] = nullptr;
    stateData["WV"] = nullptr;
    stateData["WI"] = nullptr;
    stateData["WY"] = nullptr;

//FILL in
}

//return the name of the state with the largest population under age 5
string dataAQ::youngestPop() {
	//FILL in
  return "fix me"; 
} 

//return the name of the state with the largest population under age 18
string dataAQ::teenPop()  {
	//FILL in
  return "fix me"; 
}

//return the name of the state with the largest population over age 65
string dataAQ::wisePop()  {
	//FILL in
  return "fix me"; 
}

//return the name of the state with the largest population who did not receive high school diploma
string dataAQ::underServeHS() {
	//FILL in
  return "fix me"; 
} 

//return the name of the state with the largest population who did receive bachelors degree and up
string dataAQ::collegeGrads() {
	//FILL in
  return "fix me"; 
}

//return the name of the state with the largest population below the poverty line
string dataAQ::belowPoverty() {
	//FILL in
  return "fix me"; 
} 
