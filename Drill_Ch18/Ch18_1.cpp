#include "../std_lib_facilities.h"


int ga[10] = {1, 2, 4, 8 , 16, 32, 64, 128, 256, 512};

int factorial(int f)
{
    int sum=1;
    while (f > 0)
    {
        sum *= f;
        f--;
    }
    return sum;
}

void print_array(int a[], int sz)
{
    for (int i = 0; i < sz; ++i )
        cout << a[i] << " ";
    cout << '\n';
}

void f(int a[], int sz)
{
    int la[10];
    for (int i = 0; i < 10; ++i)
        la[i] = ga[i];

    cout << "la: \n";
    print_array(la, 10);

    int* p = new int[sz];
    for(int i = 0; i < sz ; ++i)
        p[i] = a[i];

    cout << "p: \n";
    print_array(p, sz);
    delete[] p;
}

int main ()
{
    cout << "ga: \n";
    print_array(ga, 10);

    f(ga,10);

    int aa[10];
    for (int i = 0; i < 10; ++i )
        aa[i] = factorial(1+i);

    f(aa,10);


    return 0;
}
