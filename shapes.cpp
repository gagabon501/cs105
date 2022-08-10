#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Shapes
{
    float base, height, radius, result;

public:
    // Define getters
    float getBase()
    {
        return base;
    }
    float getHeight()
    {
        return height;
    }
    float getRadius()
    {
        return radius;
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
    void setRadius(float r)
    {
        radius = r;
    }

    void setResult(float res)
    {
        result = res;
    }

    // Default function - based on a rectangle
    float calculateArea(float b, float h)
    {
        result = b * h;
        return result;
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

    void drawShape(int b, int h)
    {
        // base shape is a rectangle
        cout << endl;
        for (int y = 1; y <= h / 2; y++)
        {

            cout << repl('.', b) << endl;
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

    void drawShape(int b, int h)
    {

        cout << endl;
        for (int y = 1; y <= h; y++)
        {

            cout << repl('.', b * 2) << endl;
        }
        cout << endl;
    }
};

class Triangle : public Shapes
{

public:
    float calculateArea(float b, float h) // overloading this function - area of the triangle
    {
        float result;
        result = 0.5 * b * h; // A = 1/2 * base * height
        setBase(b);           // update base
        setHeight(h);         // update height
        setResult(result);    // update result based on this formula for the triangle
        return result;
    }
    void drawShape(int b, int h)
    {

        int multiplier = 0;
        multiplier = b / h;
        cout << "\n." << endl;
        for (int y = 1; y <= h; y++)
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

    float calculateArea(float r) // overloading this function - area of a circle
    {
        float result;
        result = 3.14159 * r * r; // A = pi * radius * radius
        setResult(result);        // update result based on this formula for the circle
        return result;
    }

    void drawShape(int r)
    {
        const int SIZE = 2 * r;

        char canvas[SIZE][SIZE];

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                canvas[i][j] = ' ';
            }
        }

        for (int row = 0; row < SIZE; row++)
        {

            for (int col = 0; col < SIZE; col++)
            {

                int x = col - SIZE / 2;
                int y = SIZE / 2 - row;

                int r2 = x * x + y * y;

                if (r2 < (r * r))
                {

                    canvas[row][col] = '.';
                }
            }
        }

        // print
        for (int row = 0; row < SIZE; row++)
        {

            for (int col = 0; col < SIZE; col++)
            {

                cout << canvas[row][col] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Shapes r;
    cout << "\n\n*** RECTANGLE *** ";
    r.getData();
    r.calculateArea(r.getBase(), r.getHeight());
    cout << "Area of rectangle. ";
    r.giveResult();
    cout << " sq.cm.\n";

    r.drawShape(r.getBase(), r.getHeight());

    Square s;
    cout << "\n\n*** SQUARE *** ";
    s.getData();
    s.calculateArea(s.getBase(), s.getHeight());
    cout << "Area of square. ";
    s.giveResult();
    cout << " sq.cm.\n";
    s.drawShape(s.getBase(), s.getHeight());

    Triangle t;
    cout << "\n\n*** TRIANGLE *** ";
    t.getData();
    t.calculateArea(t.getBase(), t.getHeight());
    cout << "Area of rectangle. ";
    t.giveResult();
    cout << " sq.cm.\n";
    t.drawShape(t.getBase(), t.getHeight());

    Circle c;
    cout << "\n\n*** CIRCLE *** ";
    c.getData();
    c.calculateArea(c.getRadius());
    cout << "Area of circle. ";
    c.giveResult();
    cout << " sq.cm.\n";
    c.drawShape(c.getRadius());

    return 0;
}