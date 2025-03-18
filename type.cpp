#include "type.h"

//overloaded < operator for flightRec
//this function compares the destinations between two flightRec
bool flightRec::operator<(const flightRec& rhs) const{
    if(origin == rhs.origin)
        return origin < rhs.origin;

    return origin < rhs.origin;
}

//overloaded == operator for flightRec
//this function compares the origins and destinations between two flightRec
bool flightRec::operator == (const flightRec& rhs) const{return (origin == rhs.origin && destination == rhs.destination);}

//overloaded output operator for flightRec struct
ostream& operator<<(ostream& os, const flightRec& f){
    os << setw(15) << left << f.flightNum << setw(15) << left << f.origin << setw(15) << left << f.destination << "$" << f.price;
    return os;
}