#include <iostream>
#include <iomanip>
#include <cmath>

#include "Queue.h"

Queue* getInfo();

int main(){
    getInfo();
}

Queue* getInfo(){
    using namespace std; 
    Queue *queue = new Queue();
    float input = 0 ;
    cout << setfill(' ') << setw(75) << " Single Queue - Single Server " << endl;
    cout << endl << "Time Unit: minute(mn)" << endl ;

    cout << "Average Arrival Rate: " ;
    try{
        cin >> input ; 
        if(input <=0 ) throw "Invalid Argument.\n";
        queue->arrivalRate = input ; 
    }catch(const char *e ){
        cout << e;
        exit(1);
    }
    /* end input arrival rate */

    cout << "Average Service Rate: " ; 
    try{
        cin >> input ; 
        if(input <=0 ) throw "Invalid Argument.\n";
        queue->serviceRate = input ;
    }catch(const char *e ){
        cout << e;
        exit(1);
    }
    /*end input service rate */

    cout << "Amount of server: " ; 
    try{
        cin >> input ; 
        if(input <=0 || input != floor(input) ) throw "Invalid Argument.\n";
        queue->serviceRate = input ;
    }catch(const char *e ){
        cout << e;
        exit(1);

    }
    /*end input service rate */
    return queue;
}