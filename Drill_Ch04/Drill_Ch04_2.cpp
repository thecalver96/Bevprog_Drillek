/*     Chapter 4 Drill
        Computation 6      */


#include    "../std_lib_facilities.h"

int main ()
{
    double number = 0;
    double minimum = 100000000000000;
    double maximum = -100000000000000;

    while (cin >> number)
    {
        if (number == '|')
            break;

        cout << "Entered number: " << number << '\n' ;

        if (number < minimum )
        {
            minimum = number;
            cout << "The smallest number so far\n";
        }
        else if (number > maximum)
        {
            maximum = number;
            cout << "The largest number so far\n";
        }


    }


    return 0;
}
