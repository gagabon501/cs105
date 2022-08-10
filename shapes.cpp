#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

// Class definitions

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles Assessment 1
 * Class Name   : Shapes
 * Purpose      : Base class for all shapes
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon
 *************************************************************************************************************************************************/
class Shapes

{
private:
    float base = 0.0, height = 0.0, side = 0.0, radius = 0.0, result = 0.0;

public:
    /***********************************************************************************************************************************************
     * Title        : CS-105 Development Principles Assessment 1
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

    // Define getters
    float getBase()
    {
        return base;
    }
    float getHeight()
    {
        return height;
    }
    float getSide()
    {
        return side;
    }

    float getRadius()
    {
        return radius;
    }
    float getResult()
    {
        return result;
    }

    // Define setters
    void setBase(float b)
    {
        base = b;
    }
    void setHeight(float h)
    {
        height = h;
    }
    void setSide(float s)
    {
        side = s;
    }
    void setRadius(float r)
    {
        radius = r;
    }

    void setResult(float res)
    {
        result = res;
    }

    // Default function - based on a rectangle
    // float calculateArea(float b, float h)
    void calculateArea()
    {
        // result = b * h;
        result = base * height;
        // return result;
    }

    // float calculatePerimeter(float b, float h)
    void calculatePerimeter()
    {
        result = 2 * (base + height);
        // return result;
    }

    void getData()
    {
        cout << "  \nEnter base (cm): ";
        cin >> base;
        cout << "Enter height (cm): ";
        cin >> height;
    }

    void giveResult()
    {
        cout << "The result is: " << result;
    }

    // void drawShape(int b, int h)
    void drawShape()
    {
        // base shape is a rectangle
        cout << endl;
        // for (int y = 1; y <= h / 2; y++)
        for (int y = 1; y <= height / 2; y++)
        {

            // cout << repl('.', b) << endl;
            cout << repl('.', base) << endl;
        }
        cout << endl;
    }
};

class Square : public Shapes
{

public:
    void getData()
    {
        float side;
        cout << "  \nEnter side (cm): ";
        cin >> side;
        setBase(side);   // update the base
        setHeight(side); // update the height
    }

    // void drawShape(int b, int h)
    void drawShape()
    {

        cout << endl;
        for (int y = 1; y <= getHeight(); y++)
        {

            cout << repl('.', getBase() * 2) << endl;
        }
        cout << endl;
    }
};

class Triangle : public Shapes
{

public:
    void getData()
    {
        float base, height, side;
        cout << "  \nEnter base (cm): ";
        cin >> base;
        cout << "Enter height (cm): ";
        cin >> height;
        cout << "Enter side (cm): ";
        cin >> side;
        setBase(base);     // update base
        setHeight(height); // update height
        setSide(side);     // update side
    }

    // float calculateArea(float b, float h) // overloading this function - area of the triangle
    void calculateArea() // overloading this function - area of the triangle
    {
        float result;
        float b = getBase();
        float h = getHeight();
        float s = getSide();
        result = 0.5 * b * h; // A = 1/2 * base * height
        setResult(result);    // update result based on this formula for the triangle
    }

    void calculatePerimeter() // overloading this function - area of the triangle
    {
        float result;
        float b = getBase();
        float h = getHeight();
        float s = getSide();
        result = b + h + s; // P =  base + height + side
        setResult(result);  // update result based on this formula for the triangle
    }

    void drawShape()
    {

        int multiplier = 0;
        multiplier = getBase() / getHeight();
        cout << "\n." << endl;
        for (int y = 1; y <= getHeight(); y++)
        {

            cout << repl('.', multiplier * y) << endl;
        }
        cout << endl;
    }
};

class Circle : public Shapes
{

public:
    void getData()
    {
        float r;
        cout << "\nEnter radius (cm): ";
        cin >> r;
        setRadius(r);
    }

    void calculateArea() // overloading this function - area of a circle
    {
        float result;
        float r = getRadius();
        result = 3.14159 * r * r; // A = pi * radius * radius
        setResult(result);        // update result based on this formula for the circle
    }

    void calculatePerimeter() // overloading this function - area of a circle
    {
        float result;
        float r = getRadius();
        result = 2 * 3.14159 * r; // C = 2 * pi * radius
        setResult(result);        // update result based on this formula for the circle
    }
    void drawShape()
    {
        float r = getRadius();
        const int SIZE = 2 * r; // diameter of the circle

        char canvas[SIZE][SIZE]; // size of the drawing canvass = diameter of the circle

        // Initialize contents of the array with blanks
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                canvas[i][j] = ' '; // initialize with SPACE character (blank)
            }
        }

        for (int row = 0; row < SIZE; row++)
        {

            for (int col = 0; col < SIZE; col++)
            {

                int x = col - SIZE / 2;
                int y = SIZE / 2 - row;

                int r2 = x * x + y * y; // plotting equation of circle r^2 = x^2 + y^2

                if (r2 < (r * r))
                {

                    canvas[row][col] = '.'; // any value that is within the square of the radius, save a dot (.)
                }
            }
        }

        // print contents of the array to draw the circle
        for (int row = 0; row < SIZE; row++)
        {

            for (int col = 0; col < SIZE; col++)
            {

                cout << canvas[row][col] << " ";
            }

            cout << endl;
        }
        cout << endl;
    }
};

// Functions declarations
string repl(char charToDisplay, int dispQty);
int showMenu(vector<string> menu);
void showSquare();
void showRectangle();
void showTriangle();
void showCircle();
void showMainMenu();

int main()
{
    showMainMenu();
    return 0;
}

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles Assessment 1
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
 * Title        : CS-105 Development Principles Assessment 1
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

void showSquare()
{

    Square s;
    int choice = 0;
    vector<string> menu = {
        "\n============================================",
        "            Square Calculator",
        "============================================",
        "1. Area (Area = base * base sq. units)",
        "2. Perimeter (Perimeter = 4 * base units)",
        "3. Go back to main menu (Shapes Calculator)",
        "============================================",
        ""};

    while (choice != 3)
    {
        choice = showMenu(menu);
        if (choice != 3)
        {
            s.getData();
            s.drawShape();
        }

        switch (choice)
        {
        case 1:
        {
            s.calculateArea();
            cout << "Area of square. ";
            s.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2:
        {
            s.calculatePerimeter();
            cout << "Perimeter of square. ";
            s.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}

void showRectangle()
{
    Shapes r;

    int choice = 0;
    vector<string> menu = {
        "\n============================================",
        "            Rectangle Calculator",
        "============================================",
        "1. Area (Area = base * height sq. units)",
        "2. Perimeter (Perimeter = 2 * (base + height) units)",
        "3. Go back to main menu (Shapes Calculator)",
        "============================================",
        ""};

    while (choice != 3)
    {
        choice = showMenu(menu);
        if (choice != 3)
        {
            r.getData();
            r.drawShape();
        }

        switch (choice)
        {
        case 1:
        {
            r.calculateArea();
            cout << "Area of rectangle. ";
            r.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2:
        {
            r.calculatePerimeter();
            cout << "Perimeter of rectangle. ";
            r.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}

void showTriangle()
{
    Triangle t;

    int choice = 0;
    vector<string> menu = {
        "\n============================================",
        "            Triangle Calculator",
        "============================================",
        "1. Area (Area = 1/2 * base * height sq. units)",
        "2. Perimeter (Perimeter = 2 * (base + height) units)",
        "3. Go back to main menu (Shapes Calculator)",
        "============================================",
        ""};

    while (choice != 3)
    {
        choice = showMenu(menu);
        if (choice != 3)
        {
            t.getData();
            t.drawShape();
        }

        switch (choice)
        {
        case 1:
        {
            t.calculateArea();
            cout << "Area of triangle. ";
            t.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2:
        {
            t.calculatePerimeter();
            cout << "Perimeter of triangle. ";
            t.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}

void showCircle()
{

    Circle c;

    // cout << "\n\n*** CIRCLE *** ";
    // c.getData();
    // c.calculateArea();
    // cout << "Area of circle. ";
    // c.giveResult();
    // cout << " sq.cm.\n";
    // c.drawShape();

    int choice = 0;
    vector<string> menu = {
        "\n============================================",
        "            Circle Calculator",
        "============================================",
        "1. Area (A = pi * radius * radius sq. units)",
        "2. Circumference (C = 2 * pi * radius units)",
        "3. Go back to main menu (Shapes Calculator)",
        "============================================",
        ""};

    while (choice != 3)
    {
        choice = showMenu(menu);
        if (choice != 3)
        {
            c.getData();
            c.drawShape();
        }

        switch (choice)
        {
        case 1:
        {
            c.calculateArea();
            cout << "Area of circle. ";
            c.giveResult();
            cout << " sq.cm.\n";
        }
        break;
        case 2:
        {
            c.calculatePerimeter();
            cout << "Circumference of circle. ";
            c.giveResult();
            cout << " cm.\n";
        }
        break;

        default:
            break;
        }
    }
}

/***********************************************************************************************************************************************
 * Title        :
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
        "==================",
        " Shapes Calculator",
        "==================",
        "1. Square",
        "2. Rectangle",
        "3. Triangle",
        "4. Circle",
        "5. Exit",
        "==================",
        ""};

    while (choice != 5)
    {
        choice = showMenu(menu);

        switch (choice)
        {
        case 1:
            showSquare();
            break;
        case 2:
            showRectangle();
            break;
        case 3:
            showTriangle();
            break;
        case 4:
            showCircle();
            break;

        default:
            break;
        }
    }
}
