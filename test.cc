/**
Josh Mencsik
14 February 2020
Test main to test the implementation of the friend class and 
FBFriends class
*/
#include <iostream>
#include<string>
#include<fstream>
#include"friend.h"
#include"fbfriends.h"
using namespace std;

int main() {

    /* Test Friend Class
    Friend f;

    cin >> f;
    cout << f << endl;

    Friend g;
    cin >> g;

    if (f == g)
        cout << "Equal" << endl;
    else if (f != g) 
        cout << "Not Equal" << endl;
    */
    //Works as expected

    //Test pointers 
    /*
    int* ptr = new int;
    cout << ptr << endl;
    *ptr = 9;
    cout << *ptr;
    */

   //Test the FBFriends Class
    FBFriends j;
    j.show_all(cout);
    j.advance();

    Friend f;
    cin >> f;
    
    j.insert(f);
    //j.attach(f);
    j.show_all(cout);
    cout << "FRIEND_CASE 1:";
    cout << endl;
    
    cin >> f;
    //j.attach(f);
    j.insert(f);
    j.show_all(cout);
    cout << "FRIEND_CASE 2:";
    cout << endl;

    cin >> f;
    //j.start();
    //j.advance();
    //j.advance();
    //j.attach(f);
    j.insert(f);
    j.show_all(cout);
    cout << "FRIEND_CASE 3:";
    cout << endl;
    //attach, start, and show all seem to be working as intended
    //resize now functioning as well
    //advance a little weird, but functional 
    //insert looks good

    //remove the middle
    /*j.start();
    j.advance();
    j.remove_current();
    j.show_all(cout);
    cout << "REMOVAL_CASE 1:";
    cout << endl;*/
    //remove_current works 
    j.bday_sort();
    j.show_all(cout);
    cout << "SORT_CASE:";
    cout << endl;
    //bday sort looks good

    //testing find_friend and is_friend
    string name;

    cout << "Enter the name of a friend to find" << endl;
    if (cin.peek() == '\n') 
        cin.ignore();
    getline(cin, name);
    cout << j.find_friend(name) << endl;
    if (j.is_friend(j.find_friend(name))) 
        cout << "The entered friend is in your list" << endl;
    //both work at this time
    
    return 0;
}