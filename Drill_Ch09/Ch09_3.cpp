#include "../std_lib_facilities.h"
/*
9.4.1       x
9.4.2       x
9.4.3       x
9.7.1
9.7.4

*/

class Date
{
    int y;
    int m;
    int d;
public:
    Date(int y, int m, int d)
    {
        set_year(y);
        set_month(m);
        set_day(d);
    }

    Date() : y(1990), m(1), d(1) {}

    int year() {return y;}
    int month() {return m;}
    int day() {return d;}

    void set_year( int yr)
    {
        if(yr > 0)
            y = yr;
        else
            error("Invalid year in set_year()");
    }

    void set_month( int mnt)
    {
        if (mnt > 1 || mnt < 13)
            m = mnt;
        else
            error("Invalid year in set_month()");
    }

    void set_day( int dy)
    {
        if(d > 1 || d < 32)
          {
            if (m == 2 && d > 29 )
                error("Invalid day in february in set_day()");
            else if(m == 2 && d <29)
                d = dy;
            else if (m == 2 && d == 29 && (y % 4 != 0))
                error("Invalid leap year in set_day()");
            else
                 d = dy;
          }
        else
            error("Invalid year in set_day()");
    }

    void add_day(int n)
    {
        int nap = d;
        int honap = m;
        int ev = y;

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

        y = ev;
        m = honap;
        d = nap;
    }

};

void init_day(Date& dd, int y, int m, int d)
{
    dd.set_year(y);
    dd.set_month(m);
    dd.set_day(d);
}


void print_date(Date& dd)
{
    cout << dd.year() << '.' << dd.month() << '.' << dd.day() << '\n';
}

int main()
try{

    Date tomorrow{1975,1,3} ;
    print_date(tomorrow);


    Date today;
    print_date(today);
    init_day(today,2001,2,28);



    print_date(today);
    today.add_day(1);
    print_date(today);

}
catch(exception& e)
{
    cerr << e.what() << '\n';
}
