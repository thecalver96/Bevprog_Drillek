/*     Chapter 4 Drill
        Computation   1-5   */


#include    "../std_lib_facilities.h"

int main ()
{
    double a = 0;
    double b = 0;

    while (cin >> a >> b)
    {
        if (a == '|' || b == '|')
            break;


        if (a == b)
            cout << "The numbers are equal\n";
        else if ( abs(a-b) <= 0.01 )
            cout << "The numbers are almost equal\n";

        else if (a < b)
            cout << "The smaller value is: " << a << "\n"
                << "The larger value is: " << b << "\n";
        else if (a > b)
            cout << "The smaller value is: " << b << "\n"
                << "The larger value is: " << a << "\n";
    }


    return 0;
}
