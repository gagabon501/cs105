#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "gglib.cpp" //own library of functions

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

    // Overload the '+' operator for "breeding"
    Alien operator+(Alien const &theOtherAlien)
    {
        srand(time(NULL)); // seed the randomizer

        Alien offSpringAlien = Alien(theOtherAlien.weight, theOtherAlien.height, theOtherAlien.gender); // initialize the offSpringAlien with values from theOtherAlien

        offSpringAlien.weight = (this->weight + theOtherAlien.weight) / 2; // this->weight is the weight of the Alien of the other 'operand' (left side), theOtherAlien.weight is the weight of the other Alien of the other 'operand; (right side)
        offSpringAlien.height = (this->height + theOtherAlien.height) / 2; // this->height is the height of the Alien of the other 'operand' (left side), theOtherAlien.height is the height of the other Alien of the other 'operand; (right side)
        offSpringAlien.gender = ((rand() % 2 + 1) == 1 ? 'M' : 'F');       // Randomize a number between 1 and 2 to represent Male or Female where Male = 1; Female = 2;

        return offSpringAlien;
    }

    // Overload the '==' operator to compare two Aliens
    bool operator==(Alien &obj)
    {

        if (this->getPrestige() == obj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Overload the '!=' operator to compare two Aliens
    bool operator!=(Alien &obj)
    {

        if (this->getPrestige() != obj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Overload the '>' operator to compare two Aliens
    bool operator>(Alien &obj)
    {

        if (this->getPrestige() > obj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Overload the '>=' operator to compare two Aliens
    bool operator>=(Alien &obj)
    {

        if (this->getPrestige() >= obj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Overload the '<' operator to compare two Aliens
    bool operator<(Alien &obj)
    {

        if (this->getPrestige() < obj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Overload the '<=' operator to compare two Aliens
    bool operator<=(Alien &obj)
    {

        if (this->getPrestige() <= obj.getPrestige())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Function to create the Aliens and save those Aliens in a vector variable to be returned to a calling function/routine
vector<Alien> createAliens()
{
    vector<Alien> Aliens; // variable to contain the created aliens

    // Create the aliens and save to the vector variable Aliens
    Aliens.push_back(Alien(3, 5, 'M')); // aka Alien1
    Aliens.push_back(Alien(4, 7, 'F')); // aka Alien2
    Aliens.push_back(Alien(6, 8, 'M')); // aka Alien3
    Aliens.push_back(Alien(7, 9, 'F')); // aka Alien4

    cout << "\nPairs created" << endl;
    cout << "===============" << endl;
    cout << "Alien1 (w/h/g): " << Aliens[0].getWeight() << "/" << Aliens[0].getHeight() << "/" << Aliens[0].getGender() << endl;
    cout << "Alien2 (w/h/g): " << Aliens[1].getWeight() << "/" << Aliens[1].getHeight() << "/" << Aliens[1].getGender() << endl;
    cout << "Alien3 (w/h/g): " << Aliens[2].getWeight() << "/" << Aliens[2].getHeight() << "/" << Aliens[2].getGender() << endl;
    cout << "Alien4 (w/h/g): " << Aliens[3].getWeight() << "/" << Aliens[3].getHeight() << "/" << Aliens[3].getGender() << endl;
    return Aliens;
}

// This function calls createAliens() to create the Aliens and Offsprings are then created by using the overloaded operator '+'
vector<Alien> createOffsprings()
{
    vector<Alien> Aliens = createAliens();
    vector<Alien> AlienOffsprings; // to hold the offsprings

    AlienOffsprings.push_back(Aliens[0] + Aliens[1]); // Offspring from Aliens[0] & Aliens[1]. The '+' operator here has been overloaded
    AlienOffsprings.push_back(Aliens[2] + Aliens[3]); // Offspring from Aliens[2] & Aliens[3]. The '+' operator here has been overloaded

    cout << "\nOffsprings created...Alien5 and Alien6";
    cout << "\n======================================\n";
    cout << "Alien5 (w/h/g/p): " << AlienOffsprings[0].getWeight() << "/" << AlienOffsprings[0].getHeight() << "/" << AlienOffsprings[0].getGender() << "/" << AlienOffsprings[0].getPrestige() << endl;
    cout << "Alien6 (w/h/g/p): " << AlienOffsprings[1].getWeight() << "/" << AlienOffsprings[1].getHeight() << "/" << AlienOffsprings[1].getGender() << "/" << AlienOffsprings[1].getPrestige() << endl;

    return AlienOffsprings;
}

// This function calls createOffsprings(). createOffsprings() calls createAliens()
void comparePrestige()
{

    vector<Alien> AlienOffsprings = createOffsprings();

    Alien Alien5 = AlienOffsprings[0];
    Alien Alien6 = AlienOffsprings[1];

    cout << "\nOffspring Prestige Comparison" << endl;
    cout << "==============================" << endl;
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
}

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: showMainMenu()
 * Purpose      : Function to show the Menu for the Administrator of the system.
 * Parameters   : None
 * Returns      : None
 * Author       : Gilberto Gabon
 *************************************************************************************************************************************************/
void showMainMenu()
{

    int choice = 0;
    vector<string> menu = {
        "\n=============================",
        "          Main Menu",
        "=============================",
        "1. Create Alien Pairs        ",
        "2. Create Offsprings         ",
        "3. Compare Offspring Prestige",
        "4. Exit",
        "=============================",
        ""};

    while (choice != 4)
    {
        choice = showMenu(menu);

        switch (choice)
        {
        case 1:
            createAliens();
            break;
        case 2:
            createOffsprings();
            break;
        case 3:
            comparePrestige();
            break;

        default:
            break;
        }
    }
}

int main()
{
    showMainMenu();
    return 0;
}