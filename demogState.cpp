#include "demogState.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>

//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogState&SD) {

    // outputs the data in the form:
    // State Info: UT
    // Number of Counties: 29   
    // Population Info:
    // (over 65): 10.03% and total: 295146
    // (under 18): 30.71% and total: 903830
    // (under 5): 8.58% and total: 252378
    // Education info: 
    // (Bachelor or more): 30.54% and total: 898886
    // (high school or more): 91.01% and total: 2678412
    // persons below poverty: 12.67% and total: 372832
    // Total population: 2942902

    out << "State Info: " << SD.state << endl; // State Info: UT
    out << "Number of Counties: " << SD.numCounties << endl; // Number of Counties: 29   
    out << "Population Info:\n"; // Population Info:
    out << "(over 65): " << SD.percentOver65 << "% and total: " << SD.countOver65 << endl; // (over 65): 10.03% and total: 295146
    out << "(under 18): " << SD.percentUnder18 << "% and total: " << SD.countUnder18 << endl; // (under 18): 30.71% and total: 903830
    out << "(under 5): " << SD.percentUnder5 << "% and total: " << SD.countUnder5 << endl; // (under 5): 8.58% and total: 252378
    out << "Education info:\n"; // Education info: 
    out << "(Bachelor or more): " << SD.percentBachelorPlus << "% and total: " << SD.countBachelorPlus << endl; // (Bachelor or more): 30.54% and total: 898886
    out << "(high school or more): " << SD.percentHSPlus << "% and total: " << SD.countHSPlus << endl; // (high school or more): 91.01% and total: 2678412
    out << "persons below poverty: " << SD.percentPoverty << "% and total: " << SD.countPoverty << endl;// persons below poverty: 12.67% and total: 372832
    out << "Total population: " << SD.totalPopulation << endl; // Total population: 2942902
    return out;
}
