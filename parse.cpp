#include <algorithm>
#include <memory>
/* helper routines to read out csv data */
#include "parse.h"

/*
1    "County",
2    "State",
3    "Age.Percent 65 and Older",
4    "Age.Percent Under 18 Years",
5    "Age.Percent Under 5 Years",
    "Education.Bachelor's Degree or Higher",
    "Education.High School or Higher",
    "Employment.Nonemployer Establishments",
    "Employment.Private Non-farm Employment",
10    "Employment.Private Non-farm Employment Percent Change",
    "Employment.Private Non-farm Establishments",
    "Ethnicities.American Indian and Alaska Native Alone",
    "Ethnicities.Asian Alone","Ethnicities.Black Alone",
    "Ethnicities.Hispanic or Latino",
15    "Ethnicities.Native Hawaiian and Other Pacific Islander Alone",
    "Ethnicities.Two or More Races",
    "Ethnicities.White Alone",
    "Ethnicities.White Alone, not Hispanic or Latino",
    "Housing.Homeownership Rate",
20    "Housing.Households",
    "Housing.Housing Units",
    "Housing.Median Value of Owner-Occupied Units",
    "Housing.Persons per Household",
    "Housing.Units in Multi-Unit Structures",
25    "Income.Median Houseold Income",
    "Income.Per Capita Income",
27  "Income.Persons Below Poverty Level",
    "Miscellaneous.Building Permits",
    "Miscellaneous.Foreign Born",
30    "Miscellaneous.Land Area",
    "Miscellaneous.Language Other than English at Home",
    "Miscellaneous.Living in Same House +1 Years",
    "Miscellaneous.Manufacturers Shipments",
    "Miscellaneous.Mean Travel Time to Work",
35    "Miscellaneous.Percent Female",
36    "Miscellaneous.Veterans",
37    "Population.2010 Population",
38    "Population.2014 Population",
39    "Population.Population Percent Change",
40    "Population.Population per Square Mile",
    "Sales.Accommodation and Food Services Sales",
    "Sales.Merchant Wholesaler Sales",
    "Sales.Retail Sales",
    "Sales.Retail Sales per Capita",
45    "Employment.Firms.American Indian-Owned",
    "Employment.Firms.Asian-Owned",
    "Employment.Firms.Black-Owned",
    "Employment.Firms.Hispanic-Owned",
    "Employment.Firms.Native Hawaiian and Other Pacific Islander-Owned",
50    "Employment.Firms.Total",
    "Employment.Firms.Women-Owned"
*/

/* helper to strip out quotes from a string */
string stripQuotes(std::string temp) {
    temp.erase(
        remove(temp.begin(), temp.end(), '\"' ),
        temp.end());
    return temp;
}

/* helper: get field from string stream */
/* assume field has quotes for CORGIS */
string getField(std::stringstream &ss) {
    string data, junk;
    //ignore the first quotes
    std::getline(ss, junk, '\"');
    //read the data (not to comma as some data includes comma (Hospital names))
    std::getline(ss, data, '\"');
    //read to comma final comma (to consume and prep for next)
    std::getline(ss, junk, ',');
    //data includes final quote (see note line 18)
    return stripQuotes(data);
}

/* helper: read out column names for CSV file */
void consumeColumnNames(std::ifstream &myFile) {
    std::string line;
    std::string colname;

    // Extract the first line in the file
    std::getline(myFile, line);

    // Create a stringstream from line
    std::stringstream ss(line);

    // Read the column names (for debugging)
    // Extract each column name for debugging
    while(std::getline(ss, colname, ',')) {
        //std::cout << colname << std::endl;
    }
}

/* Read one line from a CSV file for county demographic data specifically
   TODO: for lab01 you will be asked to add fields here - think about type */
shared_ptr<demogData> readCSVLineDemog(std::string theLine) {
    std::stringstream ss(theLine);
    
    string name = getField(ss);
    string state = getField(ss);
    double popOver65 = stod(getField(ss));
    double popUnder18 = stod(getField(ss));
    double popUnder5 = stod(getField(ss)); // first 5 fields
    double popBachelorEduPlus = stod(getField(ss));
    double popHighSchoolEduPlus = stod(getField(ss)); //first 7 fields

    //skipping to the total 2014 population (which is in field 38) LMAOOOO AHHAAHHAA
    //now skip over some data
    for (int i=0; i < 31; i++)
    {
        getField(ss);
    }

    int totalPop2014 = stoi(getField(ss));

    return make_shared<demogData>(name, state, popOver65, popUnder18,
            popUnder5, popBachelorEduPlus, popHighSchoolEduPlus, totalPop2014);
}

shared_ptr<demogData> readCSVLineDemogCounty(std::string theLine) {
    std::stringstream ss(theLine);
    
    string countyName = getField(ss);
    string state = getField(ss);
    double percentOver65 = stod(getField(ss));
    double percentUnder18 = stod(getField(ss));
    double percentUnder5 = stod(getField(ss)); // first 5 fields
    double percentBachelorEduPlus = stod(getField(ss));
    double percentHighSchoolEduPlus = stod(getField(ss)); //first 7 fields

    //skip to to (field 27) in order to get poverty percentage
    for (int i=0; i<20; i++)
    {
        getField(ss);
    }

    double percentInPoverty = stod(getField(ss)); // field 27

    //skipping to the total 2014 population (which is in field 38) LMAOOOO AHHAAHHAA
    //now skip over some data
    for (int i=0; i < 10; i++)
    {
        getField(ss);
    }

    int totalPop2014 = stoi(getField(ss)); // field 38

    int countOver65 = (percentOver65 / 100) * totalPop2014;
    int countUnder18 = (percentUnder18 / 100) * totalPop2014;
    int countUnder5 = (percentUnder5 / 100) * totalPop2014;
    int countBachelorEduPlus = (percentBachelorEduPlus / 100) * totalPop2014;
    int countHighSchoolEduPlus = (percentHighSchoolEduPlus / 100) * totalPop2014;
    int countPoverty = (percentInPoverty / 100) * totalPop2014;

    return make_shared<demogData>(countyName, state, percentOver65, percentUnder18,
            percentUnder5, percentBachelorEduPlus, percentHighSchoolEduPlus, percentInPoverty, totalPop2014);
}

//read from a CSV file (for a given data type) return a vector of the data
// DO NOT modify for lab01
std::vector<shared_ptr<demogData> > read_csv(std::string filename, typeFlag fileType) {
    //the actual data
    std::vector<shared_ptr<demogData> > theData;

    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()) {
        consumeColumnNames(myFile);

        // Helper vars
        std::string line;

        // Now read data, line by line and create demographic dataobject
        while(std::getline(myFile, line)) {
            if (fileType == DEMOG) {
                theData.push_back(readCSVLineDemog(line));
            } else {
                cout << "ERROR - unknown file type" << endl;
                exit(0);
            }
        }

        // Close file
        myFile.close();
    }

    return theData;
}
