#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <map>
using namespace std;

namespace ariel{

    class NumberWithUnits{
        double parameter; string type;
        
        //static map<string,map<string, double>> theMap;
        //void inMyMap(const string &left, const string &right);
        public:
             // Constructors:
         NumberWithUnits(double num , const string &s);
            //~NumberWithUnits(){};
        double getPa() const{
            return parameter;
        }
        string getType() const{
            return type;
        }
            // Functions: 
            static void read_units(ifstream& file);
            //double CompareTypes(NumberWithUnits& a, NumberWithUnits& b);
            
            //Math Operator
            friend NumberWithUnits operator+(const NumberWithUnits& sub);//unary
            friend NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits& b);
            
            friend NumberWithUnits operator-(const NumberWithUnits &min);
            friend NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b);

            NumberWithUnits& operator+=(const NumberWithUnits& other);
            NumberWithUnits& operator-=(const NumberWithUnits &temp);
            //multi - function 
            friend NumberWithUnits operator*(const NumberWithUnits &a, const double n);   //like i watched in Kern Kalif videos
            friend NumberWithUnits operator*(double x, const NumberWithUnits& a);
            //Comparation functions -(bool functions)-true/false
            bool operator>(const NumberWithUnits &temp) const;
            bool operator>=(const NumberWithUnits &temp) const;
            bool operator<(const NumberWithUnits &temp) const;
            bool operator<=(const NumberWithUnits &temp) const;
            bool operator==(const NumberWithUnits &temp) const;
            bool operator!=(const NumberWithUnits &temp) const;
            NumberWithUnits& operator++();
            NumberWithUnits operator++(int temp);
            NumberWithUnits& operator--();
            NumberWithUnits operator--(int temp);

            friend ostream& operator<<(ostream& output, const NumberWithUnits& other);

            friend istream& operator>>(istream &input, NumberWithUnits &co);

    };  
    // map<string,map<string, double>> NumberWithUnits::theMap;
}
