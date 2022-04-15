#include "../include/Company.h"

Company::Company(const std::string & companyName): companyName(companyName){
    auto deliveryLines = utils::file::readFile("../input/encomendas.txt"), truckLines = utils::file::readFile("../input/carrinhas.txt");

    storeDeliveries(deliveryLines);
    storeTrucks(truckLines);
}

Company::~Company(){
    // update as needed
    for (int i = 0; i < availableTrucks.size(); i++){
        delete availableTrucks.at(i);
    }

    for (int i = 0; i < warehouse.size(); i++){
        delete warehouse.at(i);
    }

    for (int i = 0; i < warehouseExpress.size(); i++){
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
        this->warehouseExpress.push_back(new Delivery(vol, weight, profit, duration));
    }
}

void Company::deliveriesMinTrucks(){
    unsigned int currentVolume = 0, currentWeight = 0;
    std::sort(warehouse.begin(), warehouse.end(),[](const Delivery* lhs, const Delivery* rhs) {
        if ((lhs->get_weight() + lhs->get_volume()) == (rhs->get_weight() + rhs->get_volume())) return lhs->get_volume() < rhs->get_volume();
        return lhs->get_weight() + lhs->get_volume() < rhs->get_weight() + rhs->get_volume();
    });
    std::sort(availableTrucks.begin(), availableTrucks.end(),[](const Truck* lhs, const Truck* rhs) {
        return lhs->get_weight() + lhs->get_volume() > rhs->get_weight() + rhs->get_volume();
    });
    while (!warehouse.empty() && !availableTrucks.empty()){
        if ((currentVolume + warehouse[0]->get_volume() <= availableTrucks[0]->get_volume()) &&
        (currentWeight + warehouse[0]->get_weight() <= availableTrucks[0]->get_weight())) {
            currentVolume += warehouse[0]->get_volume(), currentWeight += warehouse[0]->get_weight();
            delete warehouse[0];
            warehouse.erase(warehouse.begin());
            std::cout << currentVolume << " " << currentWeight << std::endl;
        }
        else {
            unavailableTrucks.push_back(availableTrucks[0]);
            availableTrucks.erase(availableTrucks.begin());
            currentWeight = 0;
            currentVolume = 0;
        }
    }
    std::cout << unavailableTrucks.size() << " " << warehouse.size() << std::endl;
};
void Company::deliveriesMaxProfit(){
    std::cout << "Not Implemented" << std::endl;
};
void Company::deliveriesExpress(){
    const unsigned int time_limit = 28800; // 8 horas em segundos, das 9 às 5
    unsigned int current_time = 0, completion_time = 0, previous_size = warehouseExpress.size();
//    int i = 0;
    std::sort(warehouseExpress.begin(), warehouseExpress.end(),[](const Delivery* lhs, const Delivery* rhs){
        return lhs->get_duration() < rhs->get_duration();
    });
//    std::vector<Delivery *> test = warehouse_dup;
    while (!warehouseExpress.empty()){
        if (current_time + warehouseExpress[0]->get_duration() > time_limit) break;
//        std::cout << current_time << " " << warehouse_dup[0]->get_duration() << " " << test[i]->get_duration() << std::endl;
//        i++;
        current_time += warehouseExpress[0]->get_duration();
        completion_time = (warehouseExpress[0]->get_duration() + completion_time);
        warehouseExpress.erase(warehouseExpress.begin());
    }
    std::cout << "Delivery time: " << current_time << '\n';
    std::cout << "Packages delivered: " << previous_size - warehouseExpress.size() << " out of " << previous_size << '\n';
    std::cout << "Average delivery duration: " << current_time / (previous_size - warehouseExpress.size()) << '\n';
    std::cout << "Average completion time: " << completion_time / (previous_size - warehouseExpress.size()) << std::endl;
};

