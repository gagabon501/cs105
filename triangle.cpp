#include <iostream>
#include <string>

using namespace std;

string repl(char charToDisplay, int dispQty)
{
    string returnedString = "";
    for (int i = 0; i < dispQty; i++)
    {
        returnedString.push_back(charToDisplay);
    }
    return returnedString;
}

int main()
{
    int b = 10, h = 3, multiplier = 0;
    multiplier = b / h;
    cout << "*" << endl;
    for (int y = 1; y <= h; y++)
    {

        cout << repl('*', multiplier * y) << endl;
    }
    cout << endl;

    return 0;
}