/*
    Time Unit : minute(mn)
*/
#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>

struct Queue{
        float arrivalRate = 0 ;
        float serviceRate = 1; 
        short num_server = 1 ; 
        float occupationRate;
        void setOccupationRate();

        Queue(float arrivalRate, float serviceRate,short num_server):arrivalRate(arrivalRate),serviceRate(serviceRate),num_server(num_server){
            setOccupationRate();
        }
        Queue(){}

        const float getServiceRate(){
            return this->serviceRate;
        }
        
        const float getArrivalRate(){
            return this->arrivalRate;
        }
    
        const float getOccupationRate(){
            setOccupationRate();
            return this->occupationRate;
        }

};

#endif //QUEUE_H