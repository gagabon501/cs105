/***********************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * File         : gglib.cpp
 * Purpose      : Own library of functions available for other modules.
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon
 ************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: string repl(char charToDisplay, int dispQty)
 * Purpose      : General purpose function to display a series of characters - sort of replicating the display. This is useful for displaying lines.
 * Parameters   : char charToDisplay --> the character to display repeatedly, int dispQty --> number of times to display the character.
 * Returns      : Returns a 'string' which contains the replicated characters.
 * Author       : Gilberto Gabon
 *************************************************************************************************************************************************/
string repl(char charToDisplay, int dispQty)
{
    string returnedString = "";
    for (int i = 0; i < dispQty; i++)
    {
        returnedString.push_back(charToDisplay);
    }
    return returnedString;
}

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: char showMenu(vector<string> menu)
 * Purpose      : General purpose function to display a menu list based on the passed parameter
 * Parameters   : vector<string> menu --> an array of strings to display as a menu
 * Returns      : Returns the character pressed by the user
 * Author       : Gilberto Gabon
 *************************************************************************************************************************************************/
int showMenu(vector<string> menu)
{
    int ch = 0;

    for (int i = 0; i < (int)menu.size(); i++)
    {
        cout << menu[i] << endl;
    }

    cout << "Choice: ";
    cin >> ch;

    return ch;
}