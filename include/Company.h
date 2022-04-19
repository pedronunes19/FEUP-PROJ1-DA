#ifndef DA_PROJ_1_COMPANY_H
#define DA_PROJ_1_COMPANY_H

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "utils.h"
#include "Delivery.h"
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
    void restoreWarehouse();

private:

    std::string companyName;

    // separated "warehouses" so we can more easily deal with context
    std::vector<Delivery *> warehouse;
    std::vector<Delivery *> warehouseExpress;
    
    std::vector<Truck *> availableTrucks;
    std::vector<Truck *> unavailableTrucks;
    // no need to store the express delivery truck as it is singular, and maxVolume and maxWeight are irrelevant

    void storeTrucks(std::vector<std::string> trucks);
    void storeDeliveries(std::vector<std::string> deliveries);

};

#endif //DA_PROJ_1_COMPANY_H