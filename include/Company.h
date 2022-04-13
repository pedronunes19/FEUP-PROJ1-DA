#ifndef DA_PROJ_1_COMPANY_H
#define DA_PROJ_1_COMPANY_H

#include <vector>
#include <iostream>
#include <sstream>
#include "utils.h"
#include "delivery.h"
#include "truck.h"

class Company {
public:

    Company(const std::string& companyName);
    ~Company();

    std::string getName(){
        return companyName;
    }

    std::vector<Truck *> get_trucks() const {return availableTrucks;}
    std::vector<Delivery *> get_deliveries() const {return warehouse;}

    void deliveriesMinTrucks();
    void deliveriesMaxProfit();
    void deliveriesExpress();

private:

    std::string companyName;

    std::vector<Delivery *> warehouse;
    std::vector<Truck *> availableTrucks;
    std::vector<Truck *> unavailableTrucks;
    // no need to store the express delivery truck as it is singular, and maxVolume and maxWeight are irrelevant

    void storeTrucks(std::vector<std::string> trucks);
    void storeDeliveries(std::vector<std::string> deliveries);

};

#endif //DA_PROJ_1_COMPANY_H