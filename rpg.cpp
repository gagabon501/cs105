#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "player.h"

using namespace std;

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

class Warrior : public Player
{
public:
    string attack()
    {
        return "I will destroy you with my sword, foul demon!";
    };
};

class Priest : public Player
{

public:
    string attack()
    {
        return "I will assault you with my holy wrath!";
    };
};

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
    vector<Warrior> warrior;
    vector<Priest> priest;
    vector<Mage> mage;

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

    return 0;
}