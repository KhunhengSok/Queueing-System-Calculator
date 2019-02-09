#include "SingleQueue.h"
#include <math.h>

float SingleQueue::meanWaitingTime(){
    float waitingTime = this->meanQueueLength() * this->queue->getOccupationRate();
    return waitingTime ;
}

float SingleQueue::meanQueueLength(){
    float length = this->queue->getOccupationRate() / (1 - this->queue->getOccupationRate());
    return length; 
}

double SingleQueue::probability_queueEqual(int length){
    if( length == 0 ) return(1 - this->queue->getOccupationRate()); 
    return ( ( 1- this->queue->getOccupationRate() ) * std::pow(this->queue->getOccupationRate(), length) );
}

float SingleQueue::probability_queueLongerThan(int length){
    double probab = 0 ; //probab of queue shorter than length 
    for(short i = 0 ; i<= length ; i++){
        probab += this->probability_queueEqual(i);
    }

    return 1 - probab ;
}




float SingleQueue::probability_waitLongerThan(long time){
    return ( this->queue->getOccupationRate() * exp(-  this->queue->getOccupationRate()* time *  (1-this->queue->getOccupationRate() )) ) ;
}
