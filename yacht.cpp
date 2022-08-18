#include <iostream>
#include <string>
#include <math.h>

using namespace std;

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
            latitude = to_string(degrees) + '\xF8' + to_string((int)minutes) + "\'" + " " + direction + " Latitude";
        }
        else
        {
            longitude = to_string(degrees) + '\xF8' + to_string((int)minutes) + "\'" + " " + direction + " Longitude";
        }
    }
};

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

    Yacht yacht1(1, 1);
    cout << "**************************************" << endl;
    cout << "Enter the Location of the first ship:" << endl;
    yacht1.get_pos();
    yacht1.get_pos();

    Yacht yacht2(2, 2);
    cout << "**************************************" << endl;
    cout << "Enter the Location of the second ship:" << endl;
    yacht2.get_pos();
    yacht2.get_pos();

    Yacht yacht3(3, 3);
    cout << "**************************************" << endl;
    cout << "Enter the Location of the third ship:" << endl;
    yacht3.get_pos();
    yacht3.get_pos();

    cout << "\n\n************************Welcome to Ocean Race 2021-22************************" << endl;
    yacht1.display();
    yacht2.display();
    yacht3.display();

    return 0;
}