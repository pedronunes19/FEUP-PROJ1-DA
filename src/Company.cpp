#include "../include/Company.h"

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
    const unsigned int time_limit = 28800; // 8 horas em segundos, das 9 às 5
    unsigned int current_time = 0;
//    int i = 0;
    std::vector<Delivery *> warehouse_dup = warehouse;
    std::sort(warehouse_dup.begin(), warehouse_dup.end(),[](const Delivery* lhs, const Delivery* rhs){
        return lhs->get_duration() < rhs->get_duration();
    });
//    std::vector<Delivery *> test = warehouse_dup;
    while (!warehouse_dup.empty()){
        if (current_time + warehouse_dup[0]->get_duration() > time_limit) break;
//        std::cout << current_time << " " << warehouse_dup[0]->get_duration() << " " << test[i]->get_duration() << std::endl;
//        i++;
        current_time += warehouse_dup[0]->get_duration();
//TODO: corrigir problema dos pointers sem ser ignorá-los
        warehouse_dup.erase(warehouse_dup.begin());
    }
    std::cout << "Delivery time: " << current_time << std::endl;
    std::cout << "Packages delivered: " << warehouse.size() - warehouse_dup.size() << " out of " <<
              warehouse.size() << std::endl;
    std::cout << "Average delivery time: " << current_time / (warehouse.size() - warehouse_dup.size()) << std::endl;
};

