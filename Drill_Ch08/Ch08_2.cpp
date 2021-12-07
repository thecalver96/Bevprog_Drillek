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
    magyar�z�s v�lasz.
    compile:
    a v �s az r lefordul viszont a cr nem mert const eset�n nem lehet �rt�ket v�ltoztatni. Kikommenteltem a tov�bbiak miatt.
    run:
    a swap_v nem cser�li meg az x,y �rt�keket, mert csak a f�ggv�ny belsej�ben l�v� "a �s b" �rt�k�t cser�li fel, ami nem hat ki az x �s y-okra.
    a swap_r csak az els� esetben m�k�dik, ott is csak akkor amikor v�ltoz� �rt�k�t adjuk �t �s nem konstanst. a cx , dx ek nem futnak le mert vagy konstanst akarunk �tadni vagy double-t.


*/
