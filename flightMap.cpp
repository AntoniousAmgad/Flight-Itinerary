#include "flightMap.h"



FlightMapClass::FlightMapClass() : size(0) {
    // Constructor implementation
    cities.clear();
    map.clear();
    visited.clear();
}



FlightMapClass::FlightMapClass(const FlightMapClass &f){
    // Copy constructor implementation
    size = f.size;
    visited = f.visited;
    cities = f.cities;
    map = f.map;
}



FlightMapClass::~FlightMapClass(){
     // Destructor implementation
    size = 0;
    cities.clear();
    map.clear();
    visited.clear();
}



void FlightMapClass::ReadCities(ifstream &myCities){
    // intialize variable to hold each city
    string city;

    // check if file is opened
    if(!myCities.is_open()){
        cout << "Error opening city file" << endl;
        return;
    }

    // this gets the first line in the file and set the numer of cities with value 
    myCities >> size;
    myCities.ignore();

    // reads every line and pushes back to cities vector
    while(myCities >> city){
        cities.push_back(city);
    }

    // sort cites in alphabet order 
    sort(cities.begin(), cities.end());

    // close file 
    myCities.close();
}


void FlightMapClass::BuildMap(ifstream& flightsFile){
    // Build the flight map from flight information

    // check if file is valid
    if(!flightsFile.is_open()){
        cout << "Error opening city file" << endl;
        return;
    }

    // reads every data in the file 
    while(!flightsFile.eof()){
        // variavle of type flight
        flightRec flight;
        flightsFile >> flight.flightNum >> flight.origin >> flight.destination >> flight.price;
        map[flight.origin].push_back(flight);
    }
}



bool FlightMapClass::CheckCity(string cityName) const{
    // Check whether a city is served by the airline
    return map.find(cityName) != map.end();
}


void FlightMapClass::DisplayAllCities() const{
    // Display all of the cities
    for(auto& city : cities){
        cout << city << endl;
    }
}


int FlightMapClass::GetCityNumber(string cityName)const{
    // Get the integer index for a city name
    for(int i = 0; i < size; i++){
        if(cityName == cities[i])
            return i;
    }
    return -1;
}


string FlightMapClass::GetCityName(int cityNumber) const{
    // Get the city name for an integer index
    if(cityNumber >= 0 && cityNumber < cities.size()){
        return cities[cityNumber];
    }
    return "";
}

void FlightMapClass::MarkVisited(int city){
    // Mark a city as visited
    if(city>= 0 && city < cities.size()){
        visited[city] = true;
    }
}

void FlightMapClass::UnvisitAll(){
    // assigning all values for vector to false
    visited.assign(size, false);
} 

bool FlightMapClass::IsVisited(int city) const{
    // Determine whether a city was visited
    if(city>= 0 && city < cities.size()){
        return visited[city];
    }
    return true;
}

bool FlightMapClass::GetNextCity(string fromCity, string &nextCity){
    // Determine the next unvisited city, if any, that is adjacent to a given city
    for(const auto& flight : map.at(fromCity)){
        int cityNum = GetCityNumber(flight.destination);
        if(!IsVisited(cityNum)){
            nextCity = flight.destination;
            return true;
        }

    }
    return false;
}

bool FlightMapClass::isPath(int fromCity, int toCity, stack<flightRec> & flightStack){

    // check if they reached the destination
    if(fromCity == toCity){
        return true;
    }

    // mark the origin city as visited
    MarkVisited(fromCity);

    string cityName = GetCityName(fromCity);

    // looping through list of destinations for an origin city
    for(auto& flight : map[cityName]){
        int nextcity = GetCityNumber(flight.destination);

        // check if the next city is visited
        if(!IsVisited(nextcity)){
            flightStack.push(flight);

            // another recursive call for is path till reach destination
            if(isPath(nextcity, toCity, flightStack))
                return true;
            flightStack.pop();
        }

    }
    return false;
}

void FlightMapClass::FindPath(string originCity, string destinationCity){

    // mark all cities as unvisited
    UnvisitAll();
    stack<flightRec> flightStack;
    int origin = GetCityNumber(originCity);
    int destination = GetCityNumber(destinationCity);

    // check if the destination city is served by the company
    if(CheckCity(destinationCity)){

        // check for a path
        if(isPath(origin, destination, flightStack)){

            // display the Itinerary 
            displayItinerary(flightStack, originCity, destinationCity);
        } else{
            cout << "Sorry, BlueSky airline does not fly from " + originCity + " to " + destinationCity << endl;
        }
    }else{
        cout << "Sorry, BlueSky airline does not serve " + destinationCity << endl;
    }
}

void FlightMapClass::DisplayMap(){
    // display map of flights
    for(auto& flights : map){
        cout << "From " << flights.first << ":\n";
        for(auto& flight : flights.second){
            cout << "\tFlight " << flight.flightNum << " to " << flight.destination << " price: $" << flight.price << "\n";
        }
    }
}



void FlightMapClass::displayItinerary(stack<flightRec>& flightStack, string originCity, string destinationCity){
    // display the Itinerary from the origin city all the way to destination 
    cout << "BlueSky airline serves between these two cities. " << endl;
    cout << "The flight itinerary is: " << endl;
    cout << setw(15) << left << "Flight#" << setw(15) << left << "From" << setw(15) << left << "To" << setw(15) << left << "Cost" << "\n";

    stack<flightRec> temp; // temp stack to store the flights stack in the righ order
    int total = 0;         // variable where to store the total

    while(!flightStack.empty()){
        temp.push(flightStack.top());
        flightStack.pop();
    }

    while(!temp.empty()){
        cout << temp.top();
        total += temp.top().price;
        cout << "\n";
        temp.pop();
    }

    cout << "\t\t\t\t\tTotal: " << total;

}
