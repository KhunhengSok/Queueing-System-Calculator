#ifndef SINGLEQUEUE_H
#define SINGLEQUEUE_H

#include "Queue.h"

class SingleQueue{
    private:
        float meanWait = 0 ; 
        float meanQueue = 0 ; 
        Queue *queue = nullptr  ;

        // float meanSojournTime();  //E(S): sojourn time = waiting time + service time
        
        // float meanServiceTime(); // E(B): service time

        // float meanNumberOfCustomer(); // E(L): number of customer in the server
        
        double probability_queueEqual(int length);



    public:
        float getServerNum(){return queue->num_server;}
        float getArrivalRate(){return queue->getArrivalRate();}
        float getServiceRate(){return queue->getServiceRate();}
        float getOccupateRate(){return queue->getOccupationRate();}

        SingleQueue(float arrivalRate, float serviceRate, short num_server){
            queue = new Queue(arrivalRate, serviceRate,num_server);
            this->meanWait = this->meanWaitingTime();
            this->meanQueue = this->meanQueueLength();

        }
        SingleQueue(Queue *queue):SingleQueue(queue->arrivalRate,queue->serviceRate,queue->num_server){}

        ~SingleQueue(){
            delete queue;
        }

        float meanQueueLength(); // E(Lq) : number of customer in the queuefloat getMeanWait(){return this->meanWait};
        float meanWaitingTime(); //E(W): waiting time in queue

        float getMeanQueueLength();
        float probability_waitLongerThan(float  time);
        float probability_queueLongerThan(int length);


};

#endif //SINGLEQUEUE_H