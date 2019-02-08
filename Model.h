#include <iostream>

class Model{
    private:
        const float arrivalRate  ;
        const float serviceRate ; 
        float occupationRate;
    public:
        Model(float arrivalRate, float serviceRate):arrivalRate(arrivalRate),serviceRate(serviceRate){
            setOccupationRate();
        }

        void setOccupationRate();

        const float getServiceRate(){
            return this->serviceRate;
        }
        
        const float getArrivalRate(){
            return this->arrivalRate;
        }
    
        const float getOccupationRate(){
            return this->occupationRate;
        }

};