/***********************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * File         : yacht.cpp
 * Purpose      : Scenario 1: A program to display the Ocean Race 2021-22 information. This program showcases Object Oriented Programming (OOP) in C++.
 *                This program also shows the creation of classes with constructor, encapsulation and inheritance.
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 ************************************************************************************/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Location
 * Purpose      : A class to define a Location object that consists of the following:
 *                Properties    : private int degrees, float minutes, char direction
 *                              : public string latitude = "", longitude = ""
 *                Methods       : public void getpos() --> gets position of the boat and store these into its properties
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
class Location
{
    int degrees;
    float minutes;
    char direction;

public:
    string latitude = "", longitude = "";

    void getpos()
    {

        char dir;
        cout << "Input the degrees between 0 and 180: ";
        cin >> degrees;
        cout << "Input minutes between 0 and 60: ";
        cin >> minutes;
        cout << "Input direction (E/W/N/S): ";
        cin >> dir;
        direction = toupper(dir); // to convert the direction to uppercase

        if (toupper(direction) == 'N' || toupper(direction) == 'S')
        {
            latitude = to_string(degrees) + "°" + to_string((int)minutes) + "\'" + " " + direction + " Latitude";
        }
        else
        {
            longitude = to_string(degrees) + "°" + to_string((int)minutes) + "\'" + " " + direction + " Longitude";
        }
    }
};

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Yacht
 * Purpose      : A class to define a Yacht object. This class inherits from the 'Location' class. This class of the following:
 *                Properties    : private int serialNum, objectNum
 *                Methods       : public void get_pos() --> calls the getpos() method from the Location class which this class inherits
 *                              : public void display() --> displays the yacht's information such as the serial number and its location
 * Constructor  : public Yacht(int sn, int objnum) --> this receives the serial number of the yacht and the object count of how many objects (yachts)
 *                have been created so far
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/

class Yacht : public Location
{

    int serialNum, objectNum;

public:
    Yacht(int sn, int objnum)
    {
        serialNum = sn;
        objectNum = objnum;
    }
    void get_pos()
    {
        getpos();
    }

    void display()
    {
        cout << "\nThe ship serial number is: " << serialNum << endl;
        cout << "and it's position is: " << latitude << "  " << longitude << endl; // the latitude and longitude variables here were inherited from Location class
    }
};

int main()
{

    cout << "\n************************Ocean Race 2021-22************************\n\n";

    // Define first yacht object
    Yacht yacht1(1, 1);

    // Get information from user for the first yacht object
    cout << "**************************************" << endl;
    cout << "Enter the Location of the first ship:" << endl;
    yacht1.get_pos();
    yacht1.get_pos();

    // Define second yacht object
    Yacht yacht2(2, 2);

    // Get information from user for the second yacht object
    cout << "**************************************" << endl;
    cout << "Enter the Location of the second ship:" << endl;
    yacht2.get_pos();
    yacht2.get_pos();

    // Define third yacht object
    Yacht yacht3(3, 3);

    // Get information from user for the third yacht object
    cout << "**************************************" << endl;
    cout << "Enter the Location of the third ship:" << endl;
    yacht3.get_pos();
    yacht3.get_pos();

    // Display yacht objects information
    cout << "\n\n************************Welcome to Ocean Race 2021-22************************" << endl;
    yacht1.display();
    yacht2.display();
    yacht3.display();

    return 0;
}