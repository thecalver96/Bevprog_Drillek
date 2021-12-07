/*     Chapter 2 Drill
        7    */


#include    "../std_lib_facilities.h"



double convert_to_meters (double x, char unit)
{
    switch(unit)
    {
        case 'f':
                    x=x*12;
        case 'i':
                    x=x*2.54;
        case 'c':
                    x=x/100;
        case 'm':
                    break;

    }

return x;
}

void kiiras(vector<double>numbers)
{
        double sum=0;
    for(int i=0; i< numbers.size(); i++)
        sum += numbers[i];

    sort(numbers);

    cout << "the smallest number entered in [m]: " << numbers[0] << endl
        << "the largest number entered in [m]: " << numbers[numbers.size()-1] << endl
        << "the sum of the entered values is in [m]: " << sum << endl;

    cout << "Entered values in increasing order: \n";
    for(int i=0; i < numbers.size() ; i++)
        cout << numbers[i] << " m" << endl;

}

bool wrong_input (char ch)
{
    string dump;

    cin.putback(ch);
    cin >> dump;
    if(dump == "quit")
        return false;
    cout << "wrong input \n";
    return true;
}

int main ()
{
    double value;
    string unit;
    vector<double>numbers ;
    char ch = ' ';

    while(cin >> ch)
    {
        if(ch >= '0' && ch <= '9')
            {
            cin.putback(ch);
            cin >> value >> unit;

            if (unit == "cm" || unit == "ft" || unit == "m" || unit == "in")
                {
                    numbers.push_back(convert_to_meters(value, unit[0]));
                }

            else
                {
                    cout << "wrong unit\n";
                }
            }

        else
        {
          if(wrong_input(ch) == false)
            break;
        }


    }

    kiiras(numbers);

    return 0;
}

