#include "../std_lib_facilities.h"




void print_array10(ostream& os, int* a)
{
    for (int i = 0; i < 10; ++i)
        os << a[i] << " ";
    os << '\n';
}

void print_array(ostream& os, int* a, int sz)
{
    for (int i = 0; i < sz; ++i)
        os << a[i] << " ";
    os << '\n';
}

void init_value (int* a, int val)
{
     for( int i = 0; i < 10; ++i)
        a[i] = val+i;
}
void init_value(int* a, int val, int sz)
{
    for( int i = 0; i < sz; ++i)
        a[i] = val+i;
}

void init_vector( vector<int>& a, int val, int sz)
{

    for(int i = 0; i < sz; ++i)
        a.push_back(val+i);

}
void print_vector(ostream& os, vector<int>& a)
{
    for (const auto& elem : a)
    {
        os << elem << '\n';
    }
    os << '\n';
}

int main()
{
// 1-2-3
    int* ptr = new int [10] ;

    for( int i = 0; i < 10; ++i)
        cout << ptr[i] << " ";
    cout << '\n';

    delete[] ptr;

// 4
    print_array10(cout, ptr);

// 5
    int* num = new int [10];
    init_value(num,100);
    print_array10(cout, num);

// 6-7

    int* eleven = new int [11];
    init_value(eleven,100,11);
    print_array(cout, eleven, 11);

// 8
    int* twenty = new int [20];
    init_value(twenty, 100, 20);
    print_array(cout, twenty, 20);


    delete[] num;
    delete[] eleven;
    delete[] twenty;

// 10
// vektor -> heap

    // 5 vektorral
    vector<int> vec1;
    init_vector(vec1, 100, 10);
    print_vector(cout, vec1);
    ;

    // 6 vektorral

    vector<int> vec2;
    init_vector(vec2, 100, 11);
    print_vector(cout, vec2);


    vector<int> vec3;
    init_vector(vec3,100, 20);
    print_vector(cout, vec3);


    return 0;
}
