#include<iostream>
#include<stdio.h>
#include<fstream>
#include <vector>
using namespace std;

int main(void) {
    char buf[100];
    ifstream to_read("ex7_1.cpp", ios::in);
    ofstream to_write("to_write.txt", ios::app);

    if(to_read.fail() && to_write.fail()) {
        cout << "error" << endl;
        abort();
    }
    while(!to_read.eof()) {
        to_read.getline(buf, 100);
        to_write << buf << endl;
    }

    to_read.close();
    to_write.close();
}
