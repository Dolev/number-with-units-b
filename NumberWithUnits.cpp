#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "NumberWithUnits.hpp"
using namespace std;
const double Circel = 0.001;

namespace ariel{
static map<string,map<string, double>> theMap;
 NumberWithUnits:: NumberWithUnits(double number, const string &Type){
        theMap.at(Type);
        this->parameter=number;
        this->type=Type;
    }
void inMyMap(const string &left, const string &right){
        for (auto &map: theMap[right])
        {
            double temp= theMap[left][right] * map.second;
            theMap[left][map.first]=temp;// 
            theMap[map.first][left]=1/temp;// compare the value
        }
}
 void NumberWithUnits::read_units(ifstream& file){
        string left, right;
        string str;
        double in=0, in2=0;
        while (file >> in >> left >> str >> in2 >> right)
        {
            theMap[left][right]= in2;
            theMap[right][left]= in/in2;
            inMyMap(left, right);
            inMyMap(right, left);
        }

}
//function to compare type of two elements.
double CompareTypes(double param, const string &left, const string &right){
  if(left==right){
            return param;
        }
        if(theMap.at(left).at(right)==0){
            throw invalid_argument{"This compare isn't match (:CompareTypes)"};
        }
        return param*theMap.at(left).at(right);
         };

ostream& operator<<(ostream& output, const NumberWithUnits& other){
    return output << other.parameter << "[" << other.type << "]" << endl;
}
istream& operator>>(istream &is, NumberWithUnits &co){
        string str;
        double temp=0; 
        char c=']';
        is >> temp;
        is >> c;
        while (c!=']')
        {
            if(c !='['){
                str.insert(str.end(),c);
            }
            is>>c;
        }
        if(theMap[str].empty()){
            throw invalid_argument{"Doesn't Exist"};
        };
        co.parameter=temp;
        co.type=str;
        return is;
    }

NumberWithUnits operator+(const NumberWithUnits& sub){
    return NumberWithUnits(sub.parameter, sub.type);
}
NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits& b){
    double sub= CompareTypes(b.parameter, b.type, a.type);
        return NumberWithUnits(a.parameter+sub,a.type);
}
NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other){
         this->parameter+= CompareTypes(other.parameter, other.type, this->type);
        return *this;
}

NumberWithUnits operator-(const NumberWithUnits& min){
        return NumberWithUnits(min.parameter*(-1), min.type);
}
 
NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits& b){
         double checkType= CompareTypes(b.parameter, b.type, a.type);
        return NumberWithUnits(a.parameter-checkType,a.type);
}
NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits &temp){
        this->parameter-= CompareTypes(temp.parameter, temp.type, this->type);
        return *this;
}
NumberWithUnits operator*(const NumberWithUnits &a, const double n){
        return NumberWithUnits(a.parameter*n, a.type);
    }

NumberWithUnits operator*(const double n, const NumberWithUnits &a){
        return NumberWithUnits(a.parameter*n, a.type);
    }

bool NumberWithUnits::operator>(const NumberWithUnits &temp) const
    {
        return (this->parameter>CompareTypes(temp.parameter, temp.type, this->type));
    }

    bool NumberWithUnits::operator>=(const NumberWithUnits &temp) const{
        return (this->parameter>=CompareTypes(temp.parameter, temp.type, this->type));
    }

    bool NumberWithUnits::operator<(const NumberWithUnits &temp) const{
        return (this->parameter<CompareTypes(temp.parameter, temp.type, this->type));
    }

    bool NumberWithUnits::operator<=(const NumberWithUnits &temp) const{
        return (this->parameter<=CompareTypes(temp.parameter, temp.type, this->type));
    }

    bool NumberWithUnits::operator==(const NumberWithUnits &temp) const{
        return (abs(this->parameter-CompareTypes(temp.parameter, temp.type, this->type))<= Circel);
    }

    bool NumberWithUnits::operator!=(const NumberWithUnits &temp) const
    {
        return !(*this==temp);
    }   

// Postfix operator
NumberWithUnits& NumberWithUnits::operator++(){
     ++(this->parameter);
    return *this;
}
NumberWithUnits& NumberWithUnits::operator--(){
    --(this->parameter);
    return *this; 
}

// Prefix operator
NumberWithUnits NumberWithUnits::operator++(int){
    return NumberWithUnits(this->parameter++, this->type);
}          
NumberWithUnits NumberWithUnits::operator--(int){
    return NumberWithUnits(this->parameter--, this->type);
}


}
