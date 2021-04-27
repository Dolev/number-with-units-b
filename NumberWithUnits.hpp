#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <map>
using namespace std;

namespace ariel{

    class NumberWithUnits{
        double parameter;
        string type;
        typedef pair<int,string> Key;
        static map<pair<int,string>,pair<int,string>> theMap;

        public:
             // Constructors:
            NumberWithUnits(double num , string s):parameter(num),type(s){
                
            };
            ~NumberWithUnits(){};
            // Functions: 
            static void read_units(ifstream& file);
            bool CompareTypes(NumberWithUnits& a, NumberWithUnits& b);
            //Math Operator
            NumberWithUnits operator-();//unary
             NumberWithUnits& operator+(){return *this;};//unary
            friend NumberWithUnits operator+(NumberWithUnits& a,NumberWithUnits& b);
            friend NumberWithUnits operator-(NumberWithUnits& a,NumberWithUnits& b);

            
            NumberWithUnits& operator+=(const NumberWithUnits& other);
            NumberWithUnits& operator-=(NumberWithUnits& other);
            //multi - function 
            friend NumberWithUnits& operator*(NumberWithUnits& a, double x);    //like i watched in Kern Kalif videos
            friend NumberWithUnits& operator*(double x, NumberWithUnits& a);
            //Comparation functions -(bool functions)-
            friend bool operator>(NumberWithUnits& a, NumberWithUnits& b);
            friend bool operator<(NumberWithUnits& a, NumberWithUnits& b);
            friend bool operator>=(NumberWithUnits& a, NumberWithUnits& b);
            friend bool operator<=(NumberWithUnits& a, NumberWithUnits& b);
            friend bool operator!=(NumberWithUnits& a, NumberWithUnits& b);
            friend bool operator==(const NumberWithUnits& a, const NumberWithUnits& b);

            NumberWithUnits& operator++();
            NumberWithUnits operator++(int temp);
            NumberWithUnits& operator--();
            NumberWithUnits operator--(int temp);

            friend ostream& operator<<(ostream& output, const NumberWithUnits& other);

            friend void operator>>(istringstream& input, NumberWithUnits& a);

    };
}