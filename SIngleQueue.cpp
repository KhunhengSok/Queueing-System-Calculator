#include "SingleQueue.h"
#include <math.h>
#include <iostream>
#include <limits>

float SingleQueue::meanWaitingTime(){
    float waitingTime = this->meanQueueLength() / this->queue->getArrivalRate();
    return waitingTime ;
}

float SingleQueue::meanQueueLength(){
    if(this->getOccupateRate() >= 1 ){
        return std::numeric_limits<float>::infinity();
    }
    float length =( this->queue->getOccupationRate() * this->queue->getOccupationRate()) / (1 - this->queue->getOccupationRate());
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

float SingleQueue::probability_waitLongerThan(float time){
    return ( this->queue->getOccupationRate() * exp(-1 *   this->queue->getServiceRate()* time *  ( 1-this->queue->getOccupationRate() )) ) ;
}
