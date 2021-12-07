#include    "../std_lib_facilities.h"




int main()
try {

// 1
cout << "Success!\n";
/*
C was capital in cout

*/



cout << "Success!\n";
/*2
missing " at the end of string
*/


/*3

cout << "Success" << '\n';

missing ; at the end
wrongly implemented '\n'
*/


/*4

cout << "Success" << '\n';

missing quatation mark around string

*/


/*5
int res = 7;
vector<int> v(10);
v[5] = res;
cout << "Success!\n";

res must be declared as an int variable


*/


/*6


vector<int> v(10);
v[5] = 7;
if (v[5]==7)
    cout << "Success!\n";

refering to an item in a vector [] is used instead of ()
logical error: cout will only be run if v[5]== 7

*/


/*7

bool cond = true;
if (cond)
    cout << "Success!\n";
else
    cout << "Fail!\n";

cond variable not declared, it will only print success if true.

*/


/*8

bool c = false;
if (!c)
    cout << "Success!\n";
else
    cout << "Fail!\n";

logical error, prints success if c is not false (true)

*/


/*9

string s = "ape";
bool c = "fool" > s;
if (c)
    cout << "Success!\n";

bool type wrongly written (boo)
operation > is correct instead of <

*/


/*10


string s = "ape";
if (s=="ape")
    cout << "Success!\n";

s must equal to "ape" to be true
*/


/*11

string s = "ape";
if (s=="ape")
    cout << "Success!\n";

same logical error as in 10
syntax error using cout << is needed
*/


/*12

bool s = "ape";
if (s+"fool")
    cout << "Success!\n";

if statement need logical inputs, a string is not capable of that, changed s to bool
syntax << must be used in cout



*/


/*13

vector<char> v(5);
for (int i=0; i<v.size(); ++i) ;
cout << "Success!\n";

0 is always less than v.size(), changed to i variant, exits the cycle after completing it, prints success
*/


/*14



vector<char> v(5);
for (int i=0; i<=v.size(); ++i) ;
cout << "Success!\n";

it works, prints out success,
if needs to be printed out every cycle then the ; at the and of for line should be removed.

*/


/*15

string s = "Success!\n";
for (int i=0; i<s.size(); ++i)
    cout << s[i];

the for cycle must run until the end of string, changed the condition .
*/


/*16
if (true)
    cout << "Success!\n";
else
    cout << "Fail!\n";

"then" is not needed in c++
*/


/*17
int x = 2000;
int c = x;
if (c==2000)
    cout << "Success!\n";

typesafety,
2000 in an int is 2000 as number,
2000 in a char is something different


*/


/*18
string s = "Success!\n";
for (int i=0; i<s.length(); ++i)
    cout << s[i];

in this case success prints out well but for correctness it should be s.length()
*/


/*19


vector<int> v(5);
for (int i=0; i<=v.size(); ++i) ;
cout << "Success!\n";

a vectors type must be declared

*/


/*20

int i=0;
int j = 9;
while (i<10)
    ++i;
if (j<i)
    cout << "Success!\n";

++j changed to ++i so it will end the while cycle when conditions met

*/


/*21


int x = 2;
double d = 5/(x-1);

if (d==2*(x+0.5))
    cout << "Success!\n";


(x-2), x cant be 2, cahnged to x-1
in the if statement a () was missing
*/


/*22

string s = "Success!\n";
for (int i=0; i<s.length(); ++i)
    cout << s[i];

changed s' type to string
for cycle changed to run until i<s.length()

*/


/*23


int i=0;
int j=4;
while (i<10)
    ++i;
if (j<i)
    cout << "Success!\n";


j must be declared
in while i must be increased

*/


/*24
int x = 3;
double d = 5/(x-2);
if (d == 2*x-1)
    cout << "Success!\n";


if statement needs == insted of =
math problem solved.

*/


/*25

cout << "Success!\n";

cin is for input
changed to cout

*/


 return 0;
}
catch (exception& e) {
 cerr << "error: " << e.what() << '\n';
 keep_window_open();
 return 1;
}
catch (...) {
 cerr << "Oops: unknown exception!\n";
 keep_window_open();
 return 2;
}
