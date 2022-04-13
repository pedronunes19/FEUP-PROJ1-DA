#include "../include/company.h"

Company::Company(const std::string & companyName): companyName(companyName){
    auto deliveryLines = utils::file::readFile("../input/encomendas.txt"), truckLines = utils::file::readFile("../input/carrinhas.txt");

    storeDeliveries(deliveryLines);
    storeTrucks(truckLines);
}

Company::~Company(){
    // update later
    for (int i = 0; i < availableTrucks.size(); i++){
        delete availableTrucks.at(i);
    }

    for (int i = 0; i < warehouse.size(); i++){
        delete warehouse.at(i);
    }
    
}

void Company::storeTrucks(std::vector<std::string> trucks){
    for (auto t: trucks){
        unsigned vol, weight, cost;
        std::stringstream ss{t};
        ss >> vol >> weight >> cost;
        this->availableTrucks.push_back(new Truck(vol, weight, cost));
    }
}

void Company::storeDeliveries(std::vector<std::string> deliveries){
    for (auto d: deliveries){
        unsigned vol, weight, profit, duration;
        std::stringstream ss{d};
        ss >> vol >> weight >> profit >> duration;
        this->warehouse.push_back(new Delivery(vol, weight, profit, duration));
    }
}

void Company::deliveriesMinTrucks(){
    std::cout << "Not Implemented" << std::endl;
};
void Company::deliveriesMaxProfit(){
    std::cout << "Not Implemented" << std::endl;
};
void Company::deliveriesExpress(){
    std::cout << "Not Implemented" << std::endl;
};

