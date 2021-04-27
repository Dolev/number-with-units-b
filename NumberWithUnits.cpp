#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel{
void NumberWithUnits::read_units(ifstream& file){
       stringstream getDataFromFile;
        getDataFromFile = stringstream();
        int in,in1;
		string line;
		getline(file, line);
        string left;
        string right;
        //string delimiter = "=";
       // left = line.substr(0, line.find(delimiter)); 
        //right = line.substr(line.find(delimiter)+2,line.length());
		getDataFromFile = stringstream(line);
		getDataFromFile>>in>>left>>in1>>right;
        Key p1(in,left);
        Key p2(in1,right);
        theMap.insert(p1,p2);   
            
}
//function to compare type of two elements.
bool NumberWithUnits::CompareTypes(NumberWithUnits& a, NumberWithUnits& b){
       for (const auto &entry: theMap)
    {   auto key_pair = entry.first;
        auto key_pair1 = entry.second;

        //theMap.con
        std::cout << "{" << key_pair.first << "," << key_pair.second << "}, "
                  << key_pair1.first << "," << key_pair1.second << std::endl;
    }
        // ton -> kg -> g , km -> m -> cm , usd -> ils , hour -> min -> sec.
        
   return false;
}

ostream& operator<<(ostream& output, const NumberWithUnits& other){
    return output << other.parameter << " [" << other.type << "] " << endl;
}
void operator>>(istringstream&input, NumberWithUnits& a){
    double val;
    input >> val; 
    char c;
    input >> c; //trash the "["
    string str;
    input>> str;
    a.parameter=val;// get my paramter
    a.type=str;//get my type
}

NumberWithUnits operator+(NumberWithUnits& a, NumberWithUnits& b){
    NumberWithUnits temp {0, "km"};
   if(a.type==b.type){
      temp.parameter=a.parameter+b.parameter;
      temp.type=a.type;
   }
   else{
        if(){

        }
        else{
        //throw out_of_range("You cant Subb diffrent types: "+a.type+" , "+b.type);  
        }
   }
   return temp;
}

NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other){
       this->parameter+=other.parameter;
    return *this;
}
NumberWithUnits& NumberWithUnits::operator-=(NumberWithUnits& other){
       this->parameter-=other.parameter;
    return *this;
}

NumberWithUnits NumberWithUnits:: operator-(){
        NumberWithUnits temp = *this;
        temp.parameter = -temp.parameter;
        
    return temp;
}
 
NumberWithUnits operator-(NumberWithUnits& a, NumberWithUnits& b){
       NumberWithUnits temp {0, "km"};
       temp.parameter=a.parameter-b.parameter;
       temp.type=a.type;
    return temp;
}

NumberWithUnits& operator*(NumberWithUnits& a, double x){
     a.parameter*= x;
    return a;
}

NumberWithUnits& operator*(double x, NumberWithUnits& a){
    a.parameter*= x;
    return a;
}

bool operator==(const NumberWithUnits& a, const NumberWithUnits& b){
     if(a.type==b.type&&a.parameter==b.parameter){
         return true;
     }
     else{
         //throw out_of_range("You cant compare diffrent types: "+a.type+" , "+b.type);
         return false;
     }
}

bool operator!=(NumberWithUnits& a, NumberWithUnits& b){
     if(a.type!=b.type){
         return true;
     }
     else{
         return false;
     }
}

bool operator<(NumberWithUnits& a, NumberWithUnits& b){
    if(b.parameter>a.parameter){
        return true;
    }

    else{
        return false;
    }
}
bool operator>(NumberWithUnits& a, NumberWithUnits& b){
    if(b.parameter>a.parameter){
        return true;
    }
    else{
        return false;
    }
}
bool operator<=(NumberWithUnits& a, NumberWithUnits& b){
    if(b.parameter<=a.parameter){
        return true;
    }
    else{
        return false;
    }
}
bool operator>=(NumberWithUnits& a, NumberWithUnits& b){
    if(b.parameter>=a.parameter){
        return true;
    }
    else{
        return false;
    }
}

// Postfix operator
NumberWithUnits& NumberWithUnits::operator++(){
    return *this;
}
NumberWithUnits& NumberWithUnits::operator--(){
    return *this;
}

// Prefix operator
NumberWithUnits NumberWithUnits::operator++(int temp){
    NumberWithUnits a {0, "km"};
         return a;
}          
NumberWithUnits NumberWithUnits::operator--(int temp){
    NumberWithUnits a {0, "km"};
         return a;
}


}