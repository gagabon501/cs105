#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int gender = 0;
    srand(time(NULL));
    cout << (rand() % 2 + 1);
    return 0;
}