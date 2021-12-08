#include "../std_lib_facilities.h"
/*
9.4.1       x
9.4.2       x
9.4.3       x
9.7.1       x
9.7.4

*/
enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
vector <string> name_of_months
{
    "nulladik elem",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

Month operator++(Month& m)
{
    if(m == Month::dec)
        m = Month::jan;
    else
        m = Month(int (m) + 1);

    return m;
}

ostream& operator<<(ostream& os,Month m)
{
    return os << name_of_months[int(m)];
}


class Date
{
    int y;
    Month m;
    int d;
public:
    Date(int y, Month m, int d)
    {
        set_year(y);
        set_month(m);
        set_day(d);
    }

    Date() : y(1990), m(Month::jan), d(1) {}

    int year() const {return y;}
    Month month() const {return m;}
    int day() const {return d;}

    void set_year( int yr)
    {
        if(yr > 0)
            y = yr;
        else
            error("Invalid year in set_year()");
    }

    void set_month( Month mnt)
    {
        if (mnt > Month::jan || mnt <= Month::dec)
            m = mnt;
        else
            error("Invalid year in set_month()");
    }

    void set_day( int dy)
    {
        if(d > 1 || d < 32)
          {
            if ( m == Month::feb  && d > 29 )
                error("Invalid day in february in set_day()");
            else if(m == Month::feb && d <29)
                d = dy;
            else if (m == Month::feb && d == 29 && (y % 4 != 0))
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
        Month honap = m;
        int ev = y;

        nap = nap + n;

        if(honap == Month::jan || honap == Month::mar || honap == Month::may || honap == Month::jul
            || honap == Month::aug || honap == Month::oct || honap == Month::dec) // 31 napos
            {
                if ( nap > 31)
                {
                    nap -= 31;
                    ++honap;
                    if(honap > Month::dec)
                    {
                        honap = Month::jan;
                        ev ++;
                    }
                }


            }
        else if(honap == Month::apr || honap == Month::jun || honap == Month::sep || honap == Month::nov) //30napos
            {
                  if ( nap > 30)
                {
                    nap -= 30;
                    ++honap;
                    if(honap > Month::dec)
                    {
                        honap = Month::jan;
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
                    ++honap;

                }
            }

            else
                {
                    if ( nap > 28)
                    {
                        nap -= 28;
                        ++honap;

                    }
                }
        }

        y = ev;
        m = honap;
        d = nap;
    }

};







void init_day(Date& dd, int y, Month m, int d)
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

    cout << "Default const: \n";
    Date def_day;
    print_date(def_day);
    cout << '\n';

    cout << "date with init value: \n";
    Date tomorrow{1975,Month::apr,23} ;
    print_date(tomorrow);
    cout << '\n';


    cout << "Date with init_day(): \n";
    Date today;
    init_day(today,2004,Month::feb,28);
    print_date(today);
    cout << '\n';

    cout << "add_day(): \n";
    today.add_day(1);
    print_date(today);

}
catch(exception& e)
{
    cerr << e.what() << '\n';
}
