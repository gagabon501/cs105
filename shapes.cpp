/***********************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * File         : shapes.cpp
 * Purpose      : Scenario 3: A program to create shapes and display their areas and perimeter values.This program showcases Object Oriented Programming (OOP) in C++.
 *                This program showcases classes creation, inheritance, encapsulation, and polymorphism through function overriding
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 ************************************************************************************/

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "gglib.cpp" //own library of functions

using namespace std;

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Shapes
 * Purpose      : This is a foundational (base) class for which all types of shapes inherits. This class has the following:
 *                Properties    : private  float base = 0.0, height = 0.0, side = 0.0, radius = 0.0, result = 0.0;
 *                Methods       : public string repl(char charToDisplay, int dispQty) --> general purpose function to display a series of characters - sort of replicating the display. This is useful for displaying lines.
 *                              : public float getBase() --> getter function to get the base of the shape
 *                              : public float getHeight() --> getter function to the height of the shape
 *                              : public float getSide() --> getter function to get side of the shape
 *                              : public float getRadius() --> getter function to get the radius of the circle
 *                              : public float getResult() --> getter function to return the value of the 'result' property
 *                              : public void setBase(float b) --> setter function to set the value of the base of the shape
 *                              : public void setHeight(float h) --> setter function to set the value of the height of the shape
 *                              : public void setSide(float s) --> setter function to set the value of the height of the shape
 *                              : public void setRadius(float r) --> setter function to set the value of the radius of the circle
 *                              : public void calculateArea() --> method to calculate the area of the shape. Initial computation is based on the shape of a rectangle
 *                              : public void calculatePerimeter() --> method to calculate the perimeter of the shape. Initial computation is based on the shape of a rectangle
 *                              : public void getData() --> method to get the dimension of the shape. Initial computation is based on the shape of a rectangle
 *                              : public void giveResult() --> method to display the value of the 'result' property. This property is updated during the computation of either area or perimeter
 *                              : public void drawShape() --> method to draw the shape. Initial drawing is based on the shape of a rectangle
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
class Shapes

{
private:
    float base = 0.0, height = 0.0, side = 0.0, radius = 0.0, result = 0.0;

public:
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

    void calculateArea()
    {

        result = base * height;
    }

    void calculatePerimeter()
    {
        result = 2 * (base + height);
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

    void drawShape()
    {
        // base shape is a rectangle
        cout << endl;
        for (int y = 1; y <= height / 2; y++)
        {
            cout << repl('.', base) << endl;
        }
        cout << endl;
    }
};

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Square. This inherits the Shapes class
 * Purpose      : This is a derived class that inherits the Shapes class
 *                Properties    : as inherited from Shapes class
 *                Methods       : as inherited from Shapes class plus
 *                              : public void getData() --> overrides the getData() method from the Shapes class. This method now only asks for the side of the shape.
 *                              : public void drawShape() --> overrides the drawShape() method from the Shapes class. This draws the square shape.
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
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

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Triangle. This inherits the Shapes class
 * Purpose      : This is a derived class that inherits the Shapes class
 *                Properties    : as inherited from Shapes class
 *                Methods       : as inherited from Shapes class plus
 *                              : public void getData() --> overrides the getData() method from the Shapes class. This method asks for an additional input of the side of the triangle.
 *                              : public void calculateArea() --> overrides the calculateArea() method from the Shapes class. This calculates the area of a triangle
 *                              : public void calculatePerimeter() --> overrides the calculatePerimeter() method from the Shapes class. This calculates the perimeter of a triangle
 *                              : public void drawShape() --> overrides the drawShape() method from the Shapes class. This draws the triangle shape.
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
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

    void calculateArea() // overloading this function - area of the triangle
    {
        float result;
        float b = getBase();
        float h = getHeight();
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

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Class Name   : Circle. This inherits the Shapes class
 * Purpose      : This is a derived class that inherits the Shapes class
 *                Properties    : as inherited from Shapes class
 *                Methods       : as inherited from Shapes class plus
 *                              : public void getData() --> overrides the getData() method from the Shapes class. This method asks the radius of the circle.
 *                              : public void calculateArea() --> overrides the calculateArea() method from the Shapes class. This calculates the area of the circle
 *                              : public void calculatePerimeter() --> overrides the calculatePerimeter() method from the Shapes class. This calculates the perimeter of the circle
 *                              : public void drawShape() --> overrides the drawShape() method from the Shapes class. This draws the circle shape.
 * Constructor  : None
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
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
void showSquare();
void showRectangle();
void showTriangle();
void showCircle();
void showMainMenu();

// main function
int main()
{
    showMainMenu();
    return 0;
}

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: showSquare()
 * Purpose      : Function to compute the area and perimeter of a square. This also draws the square shape based on the inputted dimensions.
 * Parameters   : None
 * Returns      : None
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
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

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: showRectangle()
 * Purpose      : Function to compute the area and perimeter of a rectangle. This also draws the rectangle shape based on the inputted dimensions.
 * Parameters   : None
 * Returns      : None
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/

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

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: showTriangle()
 * Purpose      : Function to compute the area and perimeter of a triangle. This also draws the triangle shape based on the inputted dimensions.
 * Parameters   : None
 * Returns      : None
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
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

/***********************************************************************************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: showCircle()
 * Purpose      : Function to compute the area and perimeter of a circle. This also draws the circle shape based on the inputted dimensions.
 * Parameters   : None
 * Returns      : None
 * Author       : Gilberto Gabon - Student No.: 270204759
 *************************************************************************************************************************************************/
void showCircle()
{

    Circle c;

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
 * Title        : CS-105 Development Principles-2 Assessment 1
 * Function Name: showMainMenu()
 * Purpose      : Function to show the Main Menu of the program
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
