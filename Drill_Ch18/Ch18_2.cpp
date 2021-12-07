#include "../std_lib_facilities.h"

vector<int> gv {1, 2, 4, 8 , 16, 32, 64, 128, 256, 512};


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

void print_vector(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << '\n';
}

void f(vector<int> v)
{
    vector<int> lv (v.size());

    for(int i = 0; i < gv.size(); ++i)
        lv[i] = gv[i];

    cout << "lv in f(): \n";
    print_vector(lv);

    vector<int> lv2 = v;
    cout << "lv2 in f(): \n";
    print_vector(lv2);
}


int main()
{
    cout << "f(gv):  \n";
    f(gv);

    vector<int> vv;
    for (int i = 0; i < 10; ++i )
        vv.push_back(factorial(1+i));

    cout << "f(vv):  \n";
    f(vv);


    return 0;
}
