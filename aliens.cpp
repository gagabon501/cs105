#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Alien
{
    int weight, height;
    char gender;

public:
    // Constructor
    Alien(int w, int h, char g)
    {
        weight = w;
        height = h;
        gender = g;
    }

    // Getterfunctions
    int getWeight()
    {
        return weight;
    }

    int getHeight()
    {
        return height;
    }

    int setGenderPoints()
    {

        if (toupper(gender) == 'M')
        {
            return 2;
        }
        else
        {

            return 3;
        }
    }

    char getGender()
    {
        return gender;
    }

    int getPrestige()
    {
        return height * weight * setGenderPoints();
    }

    Alien operator+(Alien const &obj)
    {
        srand(time(NULL)); // seed the randomizer

        Alien alienObj = Alien(obj.weight, obj.height, obj.gender); // the result of the addition operation of two aliens

        alienObj.weight = (weight + obj.weight) / 2;
        alienObj.height = (height + obj.height) / 2;
        alienObj.gender = ((rand() % 2 + 1) == 1 ? 'M' : 'F'); // Randomize a number between 1 and 2 to represent Male or Female where Male = 1; Female = 2;

        return alienObj;
    }

    bool operator==(Alien &obj)
    {
        Alien alienObj = Alien(obj.weight, obj.height, obj.gender); // the other operand
        if (getPrestige() == alienObj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(Alien &obj)
    {
        Alien alienObj = Alien(obj.weight, obj.height, obj.gender); // the other operand

        if (getPrestige() != alienObj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(Alien &obj)
    {
        Alien alienObj = Alien(obj.weight, obj.height, obj.gender); // the other operand

        if (getPrestige() > alienObj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>=(Alien &obj)
    {
        Alien alienObj = Alien(obj.weight, obj.height, obj.gender); // the other operand

        if (getPrestige() >= alienObj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(Alien &obj)
    {
        Alien alienObj = Alien(obj.weight, obj.height, obj.gender); // the other operand

        if (getPrestige() < alienObj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<=(Alien &obj)
    {
        Alien alienObj = Alien(obj.weight, obj.height, obj.gender); // the other operand

        if (getPrestige() <= alienObj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Alien Alien1(3, 5, 'M'), Alien2(4, 7, 'F'), Alien3(6, 8, 'M'), Alien4(7, 9, 'F');

    Alien Alien5 = Alien1 + Alien2; // Offspring from Alien1 & Alien2
    Alien Alien6 = Alien3 + Alien4; // Offspring from Alien3 & Alien4

    // cout << "Alien5 (w/h/g/p): " << Alien5.getWeight() << "/" << Alien5.getHeight() << "/" << Alien5.getGender() << "/" << Alien5.getPrestige() << endl;
    // cout << "Alien6 (w/h/g/p): " << Alien6.getWeight() << "/" << Alien6.getHeight() << "/" << Alien6.getGender() << "/" << Alien6.getPrestige() << endl;

    if (Alien5 == Alien6)
    {
        cout << "Alien5 == Alien6 ? true" << endl;
    }
    else
    {
        cout << "Alien5 == Alien6 ? false" << endl;
    };

    if (Alien5 != Alien6)
    {
        cout << "Alien5 != Alien6 ? true" << endl;
    }
    else
    {
        cout << "Alien5 != Alien6 ? false" << endl;
    };

    if (Alien5 > Alien6)
    {
        cout << "Alien5 >  Alien6 ? true" << endl;
    }
    else
    {
        cout << "Alien5 >  Alien6 ? false" << endl;
    };

    if (Alien5 >= Alien6)
    {
        cout << "Alien5 >= Alien6 ? true" << endl;
    }
    else
    {
        cout << "Alien5 >= Alien6 ? false" << endl;
    };

    if (Alien5 < Alien6)
    {
        cout << "Alien5 <  Alien6 ? true" << endl;
    }
    else
    {
        cout << "Alien5 <  Alien6 ? false" << endl;
    };

    if (Alien5 <= Alien6)
    {
        cout << "Alien5 <= Alien6 ? true" << endl;
    }
    else
    {
        cout << "Alien5 <= Alien6 ? false" << endl;
    };

    return 0;
}