/***********************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * File         : rpg.cpp
 * Purpose      : Scenario 2: A program to create a role-playing game (RPG).This program showcases Object Oriented Programming (OOP) in C++.
 *                This program also shows the creation of foundational to represent characters, that is, the entity within the game that the user
 *                of the game can control.
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 ************************************************************************************/
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "player.h"

using namespace std;

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Player
 * Purpose      : This is a foundational class for which all characters of the game inherits. This class has the following:
 *                Properties    : private  string name, Race race, int hitPoints, int magicPoints;
 *                Methods       : public string getName() --> getter function to get name of the character
 *                              : public Race getRace() --> getter function of type Race (an ENUM defined inside player.h) to get the race of the character
 *                              : public int getHitPoints() --> getter function to get the hitPoints of the character
 *                              : public int getMagicPoints() --> getter function to get the magicPoints of the character
 *                              : public string whatRace() --> a function to display the string equivalent of the Race enum values
 *                              : public void setName(string n) --> setter function to set the name of the character
 *                              : public void setRace(Race r) --> setter function to set the race of the character
 *                              : public  void setHitPoints(int h) --> setter function to set the hitPoints of the character
 *                              : public string attack() --> method to define the attack of the character. This method is overridden in the various classes that inherits this base class
 *
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
class Player
{
    string name;
    Race race;
    int hitPoints;
    int magicPoints;

public:
    string getName()
    {
        transform(name.begin(), name.end(), name.begin(), ::toupper); // return the name in uppercase
        return name;
    };

    Race getRace()
    {
        return race;
    };

    int getHitPoints()
    {
        return hitPoints;
    };

    int getMagicPoints()
    {
        return magicPoints;
    };

    string whatRace()
    {
        string raceText = "";
        switch (race)
        {
        case HUMAN:
            raceText = "HUMAN";
            break;
        case ELF:
            raceText = "ELF";
            break;
        case DWARF:
            raceText = "DWARF";
            break;
        case ORC:
            raceText = "ORC";
            break;
        case TROLL:
            raceText = "TROLL";
            break;
        };
        return raceText;
    };

    void setName(string n)
    {
        name = n;
    };

    void setRace(Race r)
    {
        race = r;
    };

    void setHitPoints(int h)
    {
        hitPoints = h;
    };

    void setMagicPoints(int m)
    {
        magicPoints = m;
    };

    string attack()
    {
        return "No attack method defined yet";
    };
};

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Warrior. This class inherits the base class Player
 * Purpose      : This class defines the Warrior. This inherits the Player class. This class has the following:
 *                Properties    : the ones inherited from Player class
 *                Methods       : the ones inherited from Player class
 *                              : public string attack() --> method to define the attack of the character. This overrides the attack() method of the Player class
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
class Warrior : public Player
{
public:
    string attack()
    {
        return "I will destroy you with my sword, foul demon!";
    };
};

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Priest. This class inherits the base class Player
 * Purpose      : This class defines the Warrior. This inherits the Player class. This class has the following:
 *                Properties    : the ones inherited from Player class
 *                Methods       : the ones inherited from Player class
 *                              : public string attack() --> method to define the attack of the character. This overrides the attack() method of the Player class
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
class Priest : public Player
{

public:
    string attack()
    {
        return "I will assault you with my Holy Wrath!";
    };
};

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Mage. This class inherits the base class Player
 * Purpose      : This class defines the Warrior. This inherits the Player class. This class has the following:
 *                Properties    : the ones inherited from Player class
 *                Methods       : the ones inherited from Player class
 *                              : public string attack() --> method to define the attack of the character. This overrides the attack() method of the Player class
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
class Mage : public Player
{
public:
    string attack()
    {
        return "I will crush you with my arcane missiles!";
    };
};

int main()
{
    // Define the vectors for the different classes (warrior, priest, mage)
    vector<Warrior> warrior;
    vector<Priest> priest;
    vector<Mage> mage;

    // Ask the user to create the character. The program loops until the user decides to finish the character creation by selecting '4' in the menu
    int ch = 0;
    int raceType;
    string charName;
    while (ch != 4)
    {
        cout << "\nCHARACTER CREATION" << endl;
        cout << "1. Create a Warrior" << endl;
        cout << "2. Create a Priest" << endl;
        cout << "3. Create a Mage" << endl;
        cout << "4. Finish creating player characters" << endl;
        cout << "Choice: ";
        cin >> ch;
        if (ch != 4)
        {
            cout << "\nWhat race do you want?\n";
            cout << "1. Human\n";
            cout << "2. Elf\n";
            cout << "3. Dwarf\n";
            cout << "4. Orc\n";
            cout << "5. Troll\n";
            cout << "Choice: ";
            cin >> raceType;

            cout << "\nWhat would you like to name your character? ";
            cin >> charName;

            // Depending on the choice, each character is added to its own vector of characters (e.g. warrior, priest, mage)
            switch (ch)
            {
            case 1:
            {
                Warrior w;
                w.setName(charName);
                w.setRace((Race)raceType);
                w.setHitPoints(200);
                w.setMagicPoints(0);

                warrior.push_back(w); // add new warrior to the list of warrior characters

                break;
            }

            case 2:
            {
                Priest p;
                p.setName(charName);
                p.setRace((Race)raceType);
                p.setHitPoints(100);
                p.setMagicPoints(200);

                priest.push_back(p); // add new priest to the list of priest characters

                break;
            }

            case 3:
            {
                Mage m;
                m.setName(charName);
                m.setRace((Race)raceType);
                m.setHitPoints(200);
                m.setMagicPoints(0);

                mage.push_back(m); // add new mage to the list of mage characters

                break;
            }

            default:
                break;
            }
        }
    }

    // Display the characters according to their classes
    cout << "\n\n---------------";
    cout << "\nWARRIORS LIST: ";
    cout << "\n---------------";
    for (int i = 0; i < (int)warrior.size(); i++)
    {
        cout << "\nI am a WARRIOR with name " << warrior[i].getName() << " and with race " << warrior[i].whatRace() << " and my attack is: " << warrior[i].attack();
    }
    cout << "\n\n---------------";
    cout << "\nPRIESTS LIST: ";
    cout << "\n---------------";
    for (int i = 0; i < (int)priest.size(); i++)
    {
        cout << "\nI am a PRIEST with name " << priest[i].getName() << " and with race " << priest[i].whatRace() << " and my attack is: " << priest[i].attack();
    }
    cout << "\n\n---------------";
    cout << "\nMAGE LIST: ";
    cout << "\n---------------";
    for (int i = 0; i < (int)mage.size(); i++)
    {
        cout << "\nI am a MAGE with name " << mage[i].getName() << " and with race " << mage[i].whatRace() << " and my attack is: " << mage[i].attack();
    }
    cout << endl;
    return 0;
}