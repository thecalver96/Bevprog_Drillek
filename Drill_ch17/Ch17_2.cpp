#include "../std_lib_facilities.h"


int main ()
try{
    //1-2

    int* p1 = new int;
    *p1 = 7;
    cout << "p1: " << p1 << '\n' << "p1 value: " << *p1;
    cout << '\n';

    //3-4
    int* p2 = new int [7];

    for(int i = 0 ; i < 7 ; i++)
        p2[i] = pow(2,i);

    cout << "p2: " << p2 << '\n';
    cout << "p2  values: ";
    for(int i=0 ; i< 7 ; i++)
        cout <<  p2[i] << " ";
    cout << '\n';

    //5-6-7-8

    int* p3 = p2;
    p1 = p2;
    p3 = p2;

    cout << "p1: " << p1 << "*p1: " << *p1 << '\n'
         << "p2: " << p2 << "*p2: " << *p2 << '\n'
         << "p3: " << p3 << "*p3: " << *p3 << '\n';

    // 9

    delete[] p1;
    delete[] p2;
    delete[] p3;

    //10-11-12


    p1 = new int[10];

    for(int i = 0 ; i < 10 ; i++)
        p1[i] = pow(2,i);

    p2 = new int[10];

    for(int i = 0 ; i < 10 ; i++)
        p2[i] = pow(2,i);

    for(int i = 0 ; i < 10 ; i++)
        p2[i] = p1[i];

    cout << "p1 " << "\t" << "p2\n";
    for(int i = 0 ; i < 10 ; i++)
        cout <<  p1[i] << "\t" << p2[i] << '\n';

    delete[] p1;
    delete[] p2;

    //13

    vector<int> num1;
    for(int i = 0 ; i < 10 ; i++)
        num1.push_back(pow(2,i));

    for(int i = 0 ; i < 10 ; i++)
        cout << num1[i] << " ";
    cout << '\n';

    vector<int> num2;
    for(int i = 0 ; i < 10 ; i++)
        num2.push_back(num1[i]);

    for(int i = 0 ; i < 10 ; i++)
        cout << num2[i] << " ";
    cout << '\n';

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
}
