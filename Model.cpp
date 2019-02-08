#include "Model.h"

void Model::setOccupationRate(){
            try{
                this->occupationRate = this->arrivalRate / this->serviceRate ; 
            }
            catch(const std::exception& e ){
                occupationRate = 0 ;
                std::cout << "Service rate = " << this->serviceRate << std::endl ;
            }
        }
}   