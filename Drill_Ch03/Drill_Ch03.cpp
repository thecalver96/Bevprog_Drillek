/*     Chapter 3 Drill
        Simple letter      */


#include    "../std_lib_facilities.h"

int main ()
{
    /* First name + starting a letter     */

    string first_name = "";

    cout << "Enter the first name of the person you want to write to \n";
    cin >> first_name;
    cout << "Dear, " << first_name << ',' << "How are you? I am fine. I miss you.\n";

    /*  Friend name */

    string friend_name = "";
    cout << "Please enter a friend's name\n";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?\n" ;

    /*  Friend sex + if-else statements */

    char friend_sex = '0';

    cout << "Please enter the sex of the friend [Enter m for male, f for female]\n";
    cin >> friend_sex;

    if (friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    else if (friend_sex == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    else
        cout << "Wrong input!\n";

    /*  Age     */

    int age = 0;
    cout << "Please enter the age of the recipient.\n";
    cin >> age;

    if ( age <= 0 || age >= 110)
        simple_error("You are kidding!\n");

    else if (age < 12 )
        cout << "Next year you will be " << age+1 << ".\n";
    else if (age == 17 )
        cout << "Next year you will be able to vote.\n";
    else if (age > 70 )
        cout << "I hope you are enjoying retirement.\n";
    else
        cout << "I hear you just had a birthday and you are " << age << " years old.\n";

    cout << "\nYours sincereley, " << "\n\n" << "Martin\n";

    return 0;
}
