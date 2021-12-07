#include "../std_lib_facilities.h"

void swap_v(int a, int b);
void swap_r(int& a, int& b);
void swap_cr(const int& a, const int& b);

int main ()
{
    int x = 7;
    int y =9;
    cout << "x & y: " << x << ',' << y << '\n';
    swap_r(x,y); // replace ? by v, r, or cr
//    swap_r(7,9);
    cout << "x & y: " << x << ',' << y << '\n';

    const int cx = 7;
    const int cy = 9;
    cout << "cx & cy: " << cx << ',' << cy << '\n';
//    swap_r(cx,cy);
//    swap_r(7.7,9.9);
    cout << "cx & cy: " << cx << ',' << cy << '\n';

    double dx = 7.7;
    double dy = 9.9;
    cout << "dx & dy: " << dx << ',' << dy << '\n';
//    swap_r(dx,dy);
 //   swap_r(7.7,9.9);
    cout << "dx & dy: " << dx << ',' << dy << '\n';


    cout <<"legyen"<<'\n';
    return 0;
}

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/*
void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/

/*
    magyarázós válasz.
    compile:
    a v és az r lefordul viszont a cr nem mert const esetén nem lehet értéket változtatni. Kikommenteltem a továbbiak miatt.
    run:
    a swap_v nem cseréli meg az x,y értékeket, mert csak a függvény belsejében lévõ "a és b" értékét cseréli fel, ami nem hat ki az x és y-okra.
    a swap_r csak az elsõ esetben mûködik, ott is csak akkor amikor változó értékét adjuk át és nem konstanst. a cx , dx ek nem futnak le mert vagy konstanst akarunk átadni vagy double-t.


*/
