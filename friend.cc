/*
 * Josh Mencsik
 * 13 February 2020
 * The implementation of the friend class
 */

#include "friend.h"
#include<iostream>

using namespace std;

Friend::Friend() {
    name = "";
}

void Friend::input(istream& ins) {
    if (ins.peek() == '\n') {
        ins.ignore();
    }
    getline(ins, name);
    ins >> bday;
}

void Friend::output(ostream& outs) const {
    outs << name << endl;
    outs << bday;
}

bool Friend::operator == (const Friend& other) const {
    return name == other.name && bday == other.bday;
}

bool Friend::operator != (const Friend& other) const {
    return !(name == other.name && bday == other.bday);
}

istream& operator >>(istream& ins, Friend& f) {
    f.input(ins);
    return ins;
}

ostream& operator <<(ostream& outs, const Friend& f) {
    f.output(outs);
    return outs;
}