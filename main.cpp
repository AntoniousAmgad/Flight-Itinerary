
/* 
 PROGRAMMER:       	Antonious Michael 
 Program Description:    
  The BlueSky airline company wants you to help them develop a program that generates flight itinerary for customer requests to fly from some origin city to some destination city. For each customer request, indicate:
  the input is three different files cities.dat, flights.dat and requests.dat          
  the output should be different itinerary for each request if available 
*/ 
#include "flightMap.h"
using namespace std;

int main() {
  ifstream citiesFile("cities.dat");
  ifstream flightsFile("flights.dat");
  ifstream requestsFile("requests.dat");

  if (!citiesFile.is_open() || !flightsFile.is_open() || !requestsFile.is_open()) {
    cerr << "Error opening data files. Make sure they exist in the current directory." << endl;
    return 1;
  }

  FlightMapClass flightMap;

  flightMap.ReadCities(citiesFile);
  flightMap.BuildMap(flightsFile);

  string originCity, destinationCity;

  while (requestsFile >> originCity >> destinationCity) {
    cout << "Request to fly from " << originCity << " to " << destinationCity << "." << endl;
    flightMap.FindPath(originCity, destinationCity);
    cout << endl;
  }
  return 0;
}