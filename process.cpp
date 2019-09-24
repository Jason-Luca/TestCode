#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Process {
private:    
    int priority;
    string name;

    Process( int _priority, int _name ) {
        priority = _priority;
        name = _name;
    }
};

class Queue {
    Process ps;
    string name;
    Queue(){}
    Queue( string _name ) {
        name = _name;
    }
    
};

int main(void) {
    func();
}