/**
 * Josh Mencsik
 * 14 February 2019
 * The implementation of the fbfriends class
 */

#include"fbfriends.h"
#include<iostream>

using namespace std;

FBFriends::FBFriends() {
    used = 0;
    capacity = 5;
    current_index = 0;
    data = new Friend[capacity];
}

FBFriends::~FBFriends() {
    delete [] data;
    cout << "Deleted" << endl;
}

FBFriends::FBFriends(const FBFriends& other) {
    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;
    data = new Friend[capacity];

    for (int i = 0; i < used; i++) {
        data[i] = other.data[i];
    }

}


void FBFriends::operator = (const FBFriends& other) {
    if (this == &other) {
        return;
    }

    used = other.used;
    capacity = other.capacity;
    current_index = other.current_index;

    Friend* tmp = new Friend[capacity];
    for (int i = 0; i < used; i++) {
        tmp[i] = other.data[i];
    }

    delete [] data;
    data = tmp;
}

void FBFriends::start() { //tested
    current_index = 0;
}

void FBFriends::advance() { //tested
    if (used == 0)
        cout << "No Friends added, kinda sad" << endl;
    else if (current_index == used - 1) 
        cout << "End of list reached" << endl;
    else
        current_index++;
}

bool FBFriends::is_item() {
    return current_index < used;
}

Friend FBFriends::current() { 
    return data[current_index];
}

void FBFriends::remove_current() {
    Friend* tmp = new Friend[capacity];

    //copy data before the removal
    for (int i = 0; i < current_index; i++) {
        tmp[i] = data[i];
    }
    //copy all the data after the removal, just leave it out
    for (int i = current_index; i < used - 1; i++) {
        tmp[i] = data[i+1];
    }
    delete [] data;
    data = tmp;
    used--;
}

void FBFriends::show_all (ostream& outs) const { //tested
    if (used == 0) {
        cout << "No friends" << endl;
    }
    else {
        cout << "Your Friends: " << endl;
        for (int i = 0; i < used; i++) {
            outs << data[i];
            if (i != used -1)
                outs << endl;
        }
    }
}

void FBFriends::insert(const Friend& f) { //tested
    //check to see if we'd need to resize 
    if (used + 1 > capacity)
        resize();

    //if this is the first friend for the list, an exception must be used
    if (used == 0) {
        data[0] = f;
        used++;
    }
    //place the new friend before the current one 
    else {
        Friend* tmp = new Friend[capacity];
        //handle copying all of data before the new addition
        for (int i = 0; i < current_index; i++) {
            tmp[i] = data[i];
        }
        tmp[current_index] = f; //the new addition
        //now copy everything else in
        for (int i = current_index + 1; i < used + 1; i++) {
            tmp[i] = data[i-1];
        }

        delete [] data;
        data = tmp;
        used++;
    }
}

void FBFriends::attach (const Friend& f) { //tested
    //check to see if we'd need to resize 
    if (used + 1 > capacity)
        resize();

    //if this is the first friend for the list, an exception must be used
    if (used == 0) {
        data[0] = f;
        used++;
    }
    //add the new friend after the current one
    else {
        Friend* tmp = new Friend[capacity];
        //handle copying all of data before the new addition
        for (int i = 0; i < current_index + 1; i++) {
            tmp[i] = data[i];
        }
        tmp[current_index + 1] = f; //the new addition
        //now copy everything else in
        for (int i = current_index + 2; i < used + 1; i++) {
            tmp[i] = data[i-1];
        }

        delete [] data;
        data = tmp;
        used++;
    }
}

void FBFriends::bday_sort() {
    Friend tmp;
    //sort the friends from oldest to youngest
    for (int i = 0; i < used; i++) {
        //Date min = data[i].get_bday();
        for (int j = (i+1); j < used; j++) {
            if (data[i].get_bday() > data[j].get_bday()) {
                tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}

Friend FBFriends::find_friend(const string& name) const {
    //search for a friend by name and return it
    Friend garbage;
    for (int i = 0; i < used; i++) {
        if (data[i].get_name() == name) {
            return data[i];
        }
    }
    //we have to return something so return garbage if not found
    //good to pair this with is_friend to make sure a valid friend is found
    return garbage ;
}

bool FBFriends::is_friend(const Friend& f) const {
    //returns true if the friend is in the list
    bool found = false;
    for (int i = 0; i < used; i++) {
        if (data[i] == f) 
            found = true;
    }
    return found;
}

void FBFriends::resize() { //tested
    capacity += 5;
    Friend* tmp = new Friend[capacity];
    for (int i = 0; i < used; i++) {
        tmp[i] = data[i];
    }
    delete [] data;
    data = tmp;
    cout << "Resized" << endl;
}

void FBFriends::load (istream& ins) {
    Friend f;
    ins >> f;
    attach(f);

    while (!ins.eof()) {
        if (ins.peek() == '\n')
            ins.ignore();
        else {
            ins>>f;
            attach(f);
            advance();
        }
    }
}

void FBFriends::save (ostream& outs) {
    for (int i = 0; i < used; i++) {
        outs << data[i];
        if (i != used -1)
            outs << endl;
    }
}




