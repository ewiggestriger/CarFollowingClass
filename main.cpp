#include <iostream>
#include <fstream>
#include "Road.h"

using namespace std;

const double deltaT = 0.01;
const double endTime = 40.0;

int main()
{
    Road newRoad(4); // creates a new road with 4 cars

    // results will be written to a file for analysis
    ofstream carFile;
    carFile.open("CarFax.csv"); // CSV format file for easy spreadsheet import
    // streambuffer for cout
    streambuf *stream_buffer_cout = cout.rdbuf();
    // streambuffer for file
    streambuf *stream_buffer_file = carFile.rdbuf();

    cout << "Welcome to the Car Following Simulation! Now improved with OOP!\n";
    cout << "Time, Car 1, Car 2, Car 3, Car 4\n";
    carFile << "Time,Position Car 1, Position Car 2, Position Car 3, Position Car 4" << endl;
    for (double t = 0.0; t <= endTime; t += deltaT)
    {
        newRoad.UpdateRoad(deltaT);
        // redirect cout to file
        cout.rdbuf(stream_buffer_file);
        cout << t << ", ";
        newRoad.PrintRoad();
        //redirect cout back to console
        cout.rdbuf(stream_buffer_cout);
        cout << t << ", ";
        newRoad.PrintRoad();
    }
    carFile.close();

    return 0;
}