#ifndef DA_PROJ_1_COMPANY_H
#define DA_PROJ_1_COMPANY_H

#include <vector>
#include <iostream>
#include "delivery.h"
#include "truck.h"

class Company {
public:

    Company(const std::string& companyName): companyName(companyName){};
    ~Company(){};

    std::string getName(){
        return companyName;
    }

    std::vector<Truck *> get_trucks() const {return trucks;}
    std::vector<Delivery *> get_deliveries() const {return warehouse;}

    void deliveriesMinTrucks();
    void deliveriesMaxProfit();
    void deliveriesExpress();

private:

    std::string companyName;

    std::vector<Delivery *> warehouse;
    std::vector<Truck *> availableTrucks;
    std::vector<Truck *> unavailableTrucks;
};

#endif //DA_PROJ_1_COMPANY_H