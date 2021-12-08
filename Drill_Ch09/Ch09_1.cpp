#include "../std_lib_facilities.h"
/*
9.4.1       x
9.4.2
9.4.3
9.7.1
9.7.4

*/

struct Date
{
    int y;
    int m;
    int d;

};

void init_day(Date& dd, int y, int m, int d)
{
    if( y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
    {
        error("Invalid date!\n");
    }
    else if (m == 2 && d > 28 && (y % 4 != 0  ))
        {
            error("not a leap year! \n");
        }
    else
    {
        dd.y = y;
        dd.m = m;
        dd.d = d;
    }
}

void add_day(Date& dd, int n)
{
    int nap = dd.d;
    int honap = dd.m;
    int ev = dd.y;

    nap = nap + n;

    if(honap == 1 || honap == 3 || honap == 5 || honap == 7
        || honap == 8 || honap == 10 || honap == 12) // 31 napos
        {
            if ( nap > 31)
            {
                nap -= 31;
                honap++;
                if(honap > 12)
                {
                    honap = 1;
                    ev ++;
                }
            }


        }
    else if(honap == 4 || honap == 6 || honap == 9 || honap == 11) //30napos
        {
              if ( nap > 30)
            {
                nap -= 30;
                honap++;
                if(honap > 12)
                {
                    honap = 1;
                    ev ++;
                }
            }
        }
    else    // február
    {
        if ( (ev % 4 == 0) ) // kis kerekítéssel szökõév
        {
              if ( nap > 29)
            {
                nap -= 29;
                honap++;

            }
        }

        else
            {
                if ( nap > 28)
                {
                    nap -= 28;
                    honap++;

                }
            }
    }

    dd.y = ev;
    dd.m = honap;
    dd.d = nap;
}

void print_date(Date& dd)
{
    cout << dd.y << '.' << dd.m << '.' << dd.d << '\n';
}

int main()
try{
    Date today;
    init_day(today,2004,2,28);
    print_date(today);
    add_day(today,1);
    print_date(today);
}
catch(exception& e)
{
    cerr << e.what() << '\n';
}
