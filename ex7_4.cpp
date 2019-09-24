#include<iostream>
#include<stdio.h>
#include<fstream>
#include <vector>
using namespace std;

ofstream splice(const ifstream& file1, const ifstream& file2) {
    ofstream to_write("write.txt", ios::app);
    char buf[100];
    if(file1.fail() && file2.fail()) {
        cout << "error" << endl;
        abort();

    }

    while(!file1.eof()) {
        file1.getline(buf, 100);
        file2 << buf << endl;
    }

    file1.close();
    file2.close();
    to_write.close();
    return to_write;
}
ofstream capital(ifstream file) {

    return file;
}
void display() {

}
int main(void) {
    ifstream file1("ex7_1.cpp", ios::in);
    ifstream file2("ex7_3.cpp", ios::in);
    ofstream file("to_write", ios::app);
    file = splice(file1, file2);

    file = capital(file);
    display();
}