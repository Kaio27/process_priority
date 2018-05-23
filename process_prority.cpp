#include <iostream>
using namespace std;
#include <list>

#define LOW 11
#define MEDIUM  12
#define HIGH  13

struct Process{
    int pid;
    bool active;
    int priority;
};

list<Process> pool;

void Next(){

    int testPriority = HIGH;

    while(true){


        for(int i =0;i <pool.size();i++){
    	    list<Process>::iterator it = pool.begin();
            advance(it, i);
            if((*it).priority==testPriority){
                (*it).active=true;
                cout << "processando: " << (*it).pid << endl;
                (*it).active=false;
                pool.erase(it);
                return;
            }
        }
        testPriority--;


    }
}
int main() {

    Process p1, p2,p3,p4,p5,p6;
    p1.pid=10;
    p1.priority = MEDIUM;
    p1.active=false;

    p2.pid=11;
    p2.priority = HIGH;
    p2.active=false;

    p3.pid=12;
    p3.priority = LOW;
    p3.active=false;

    p4.pid=13;
    p4.priority = MEDIUM;
    p4.active=false;

    p5.pid=14;
    p5.priority = LOW;
    p5.active=false;

    p6.pid=15;
    p6.priority = HIGH;
    p6.active=false;




    pool.push_back(p1);
    pool.push_back(p2);
    pool.push_back(p3);
    pool.push_back(p4);
    pool.push_back(p5);
    pool.push_back(p6);


    while(pool.size()>1){
    // cout<<pool.size();
        Next();
// cout<<pool.size();
    }
    cout<<"terminou"<<endl;
}
