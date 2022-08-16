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
    string name; // To store the name of the alien

public:
    // Constructor
    Alien(int w, int h, char g, string n)
    {
        weight = w;
        height = h;
        gender = g;
        name = n;
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

    string getAlienName()
    {
        return name;
    }

    // setter for alien name
    void setAlienName(string alienName)
    {
        name = alienName;
    }

    int getPrestige()
    {
        return height * weight * setGenderPoints();
    }

    // Overload the '+' operator for "breeding"
    Alien operator+(Alien const &theOtherAlien)
    {
        srand(time(NULL)); // seed the randomizer

        Alien offSpringAlien = Alien(theOtherAlien.weight, theOtherAlien.height, theOtherAlien.gender, theOtherAlien.name); // initialize the offSpringAlien with values from theOtherAlien

        offSpringAlien.weight = (this->weight + theOtherAlien.weight) / 2; // this->weight is the weight of the Alien of the other 'operand' (left side), theOtherAlien.weight is the weight of the other Alien of the other 'operand; (right side)
        offSpringAlien.height = (this->height + theOtherAlien.height) / 2; // this->height is the height of the Alien of the other 'operand' (left side), theOtherAlien.height is the height of the other Alien of the other 'operand; (right side)
        offSpringAlien.gender = ((rand() % 2 + 1) == 1 ? 'M' : 'F');       // Randomize a number between 1 and 2 to represent Male or Female where Male = 1; Female = 2;
        offSpringAlien.name = " ";
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

void displayAlien(Alien alien)
{
    cout << "\n---------------------------------------------------" << endl;
    cout << "Alien Name: " << alien.getAlienName() << endl;
    cout << "    Weight: " << alien.getWeight() << endl;
    cout << "    Height: " << alien.getHeight() << endl;
    cout << "    Gender: " << alien.getGender() << " (gender point = " << alien.setGenderPoints() << ")" << endl;
    cout << "  Prestige: " << alien.getPrestige() << " (p = weight * height * genderPoints)" << endl;
    cout << "---------------------------------------------------" << endl;
}

// Function to create the Aliens and save those Aliens in a vector variable to be returned to a calling function/routine
vector<Alien> createAliens()
{
    vector<Alien> Aliens; // variable to contain the created aliens

    // Create the aliens and save to the vector variable Aliens
    Aliens.push_back(Alien(3, 5, 'M', "Alien1")); // aka Alien1
    Aliens.push_back(Alien(4, 7, 'F', "Alien2")); // aka Alien2
    Aliens.push_back(Alien(6, 8, 'M', "Alien3")); // aka Alien3
    Aliens.push_back(Alien(7, 9, 'F', "Alien4")); // aka Alien4

    cout << "\nAlien Pairs Created" << endl;
    cout << "=====================" << endl;

    for (int i = 0; i < (int)Aliens.size(); i++)
    {
        displayAlien(Aliens[i]);
    }

    return Aliens;
}

// This function calls createAliens() to create the Aliens and Offsprings are then created by using the overloaded operator '+'
vector<Alien> createOffsprings()
{
    vector<Alien> Aliens = createAliens(); // This creates the Aliens (Aliens1 to Aliens4) and displays the aliens' information

    vector<Alien> AlienOffsprings; // Vectore variable of type 'Alien' to hold the created offsprings

    AlienOffsprings.push_back(Aliens[0] + Aliens[1]); // Offspring from Aliens[0] & Aliens[1]. The '+' operator here has been overloaded
    AlienOffsprings.push_back(Aliens[2] + Aliens[3]); // Offspring from Aliens[2] & Aliens[3]. The '+' operator here has been overloaded

    AlienOffsprings[0].setAlienName("Alien5");
    AlienOffsprings[1].setAlienName("Alien6");

    cout << "\nOffsprings created...Alien5 and Alien6";
    cout << "\n======================================\n";

    for (int i = 0; i < (int)AlienOffsprings.size(); i++)
    {
        displayAlien(AlienOffsprings[i]);
    }

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