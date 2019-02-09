#include <iostream>
#include <iomanip>
#include <cmath>

#include "SingleQueue.h"
#include "Queue.h"

Queue* getInfo();
void printResult(Queue *queue);
void printTable(Queue *inputQueue);
void printTableColumn();

int main(){
    Queue *inputQueue = getInfo();
    printResult(inputQueue);
    printTable(inputQueue);
}

void printResult(Queue *queue){
    using namespace std; 
    cout << "Average Arrival Rate per mn: " << queue->arrivalRate << endl ; 
    cout << "Average Interarrival time(mn): " << 1/queue->arrivalRate << endl;
    cout << "Average Service Rate per mn: " << queue->serviceRate << endl;
    cout << "Average Service time(mn): " << 1/queue->serviceRate << endl ;
    cout << "Service Utilization: " << queue->arrivalRate / (queue->serviceRate * queue->num_server) << endl << endl  ; 
}

void printTable(Queue *inputQueue){
    using namespace std; 
    SingleQueue *queue = new SingleQueue(inputQueue);
    short num_server = inputQueue->num_server;
    float waitingOption[3] = {};
    int lengthOption[3] = {};
    float length = ceil( queue->meanQueueLength());

    for(short i =0 ; i < 3 ; i++){
        float wait = queue->meanWaitingTime();
        waitingOption[i] = wait * (i + 1); //1,2,3
        lengthOption[i] = ceil(length * ( ((i  * 0.1 ) + 1 ))); 
        length = lengthOption[i];
    }
    
    delete queue;
    float waiting = 0 ; 
    short queueLength = 0 ; 
    float prob_wait = 0 ;
    float prob_length = 0 ; 

    //Start Print table
    printTableColumn();
    cout << setfill(' ') << setw(4) <<"";
    for(char i = 0 ; i < 3 ; i++){
        cout << setfill(' ') << setw(11) << waitingOption[i];
    }
    cout << setfill(' ') << setw(10) <<"";
    for(char i = 0 ; i < 3 ; i++){
        cout << setfill(' ') << setw(8) << lengthOption[i];
    }
    //end print table

    cout << endl ;
    for(short i = num_server - 2 ; i<= num_server + 2  ; i ++ ){
        if(i <= 0 ) continue ;
        queue = new SingleQueue(inputQueue->arrivalRate,inputQueue->serviceRate, i);
        
        
        cout << endl<< setfill(' ') << setw(8) << i ;
        cout << setfill(' ') << setw(28) << queue->meanWaitingTime() ;
        cout << setfill(' ') << setw(22) << queue->meanQueueLength() ;
        cout << setfill(' ') << setw(10) << "" ;
        
        for(char i = 0 ;  i< 3 ; i++){
            cout << setfill(' ') << setw(11) << queue->probability_waitLongerThan(waitingOption[i]) ;
        }
        cout << setfill(' ') << setw(8) << "" ;

        for(char i = 0 ;  i< 3 ; i++){
            cout << setfill(' ') << setw(11) << queue->probability_queueLongerThan(lengthOption[i]) ;
        }
        
        cout  << endl;
        delete queue;
    }
}

void printTableColumn(){
    using namespace std;

    cout << setfill(' ') << setw(100) << "Probability of Waiting Time" ;
    cout << setfill(' ') << setw(40) << "Probability of Queue Length" ;
    cout << endl ;
    cout << setfill(' ') << setw(90) << "Longer Than" ;
    cout << setfill(' ') << setw(40) << "Longer Than" ;
    cout << endl ;
    cout << setfill(' ') << setw(15) << "Amount of Server" ;
    cout << setfill(' ') << setw(25) << "Average Waiting time" ;
    cout << setfill(' ') << setw(25) << "Average Queue Length" ;
}
Queue* getInfo(){
    using namespace std; 
    Queue *queue = new Queue();
    float input = 0 ;
    cout << setfill(' ') << setw(75) << " Single-Server Queues " << endl;
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
        queue->num_server = input ;
    }catch(const char *e ){
        cout << e;
        exit(1);

    }
    /*end input service rate */

    cout << endl <<endl;
    return queue;


}