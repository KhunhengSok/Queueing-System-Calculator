#include "Queue.h"

class SingleQueue{
    private:
        float meanWait = 0 ; 
        float meanQueue = 0 ; 
        Queue *queue = nullptr  ;

        // float meanSojournTime();  //E(S): sojourn time = waiting time + service time
        float meanWaitingTime(); //E(W): waiting time in queue
        // float meanServiceTime(); // E(B): service time

        // float meanNumberOfCustomer(); // E(L): number of customer in the server
        float meanQueueLength(); // E(Lq) : number of customer in the queue
        double probability_queueEqual(int length);

        double power(float base, int n);


    public:
        SingleQueue(float arrivalRate, float serviceRate, short num_server){
            queue = new Queue(arrivalRate, serviceRate,num_server);
            this->meanWait = this->meanWaitingTime();
            this->meanQueue = this->meanQueueLength();

        }
        ~SingleQueue(){
            delete queue;
        }

        float probability_waitLongerThan(long time);
        float probability_queueLongerThan(int length);


};