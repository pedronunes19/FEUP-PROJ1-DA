#include "../include/Company.h"

Company::Company(const std::string & companyName): companyName(companyName){
    auto deliveryLines = utils::file::readFile("../input/encomendas.txt"), truckLines = utils::file::readFile("../input/carrinhas.txt");

    storeDeliveries(deliveryLines);
    storeTrucks(truckLines);
}

Company::~Company(){

    for (int i = 0; i < availableTrucks.size(); i++){
        delete availableTrucks.at(i);
    }

    for (int i = 0; i < warehouse.size(); i++){
        delete warehouse.at(i);
    }

    for (int i = 0; i < warehouseExpress.size(); i++){
        delete warehouseExpress.at(i);
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
    auto startTime = std::chrono::high_resolution_clock::now();
    unsigned int currentVolume = 0, currentWeight = 0, previous_size = warehouse.size();
    if (!previous_size){
        std::cout << "\tEverything has been delivered!" << std::endl;
        return;
    }
    std::sort(warehouse.begin(), warehouse.end(),[](const Delivery* lhs, const Delivery* rhs) {
        if ((lhs->get_weight() + lhs->get_volume()) == (rhs->get_weight() + rhs->get_volume())) return lhs->get_volume() > rhs->get_volume();
        return lhs->get_weight() + lhs->get_volume() > rhs->get_weight() + rhs->get_volume();
    });
    std::sort(availableTrucks.begin(), availableTrucks.end(),[](const Truck* lhs, const Truck* rhs) {
        if ((lhs->get_weight() + lhs->get_volume()) == (rhs->get_weight() + rhs->get_volume())) return lhs->get_volume() > rhs->get_volume();
        return lhs->get_weight() + lhs->get_volume() > rhs->get_weight() + rhs->get_volume();
    });
    while (!warehouse.empty() && !availableTrucks.empty()){
        if ((currentVolume + warehouse.at(0)->get_volume() <= availableTrucks.at(0)->get_volume()) &&
        (currentWeight + warehouse.at(0)->get_weight() <= availableTrucks.at(0)->get_weight())) {
            currentVolume += warehouse.at(0)->get_volume(), currentWeight += warehouse.at(0)->get_weight();
            delete warehouse.at(0);
            warehouse.erase(warehouse.begin());
        }
        else {
            unavailableTrucks.push_back(availableTrucks[0]);
            availableTrucks.erase(availableTrucks.begin());
            currentWeight = 0;
            currentVolume = 0;
        }
    }
    if (!availableTrucks.empty()) {
        unavailableTrucks.push_back(availableTrucks[0]);
        availableTrucks.erase(availableTrucks.begin());
    }
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "\tTrucks used: " << unavailableTrucks.size() << '\n';
    std::cout << "\tPackages delivered: " << previous_size - warehouse.size() << " out of " << previous_size << '\n';
    std::cout << "\tPackages per truck (average): " << (double) (previous_size - warehouse.size())/unavailableTrucks.size() << '\n';
    std::cout << "\tAlgorithm Duration: "<< duration.count() << " microseconds" << std::endl;

    // trucks available for next day of deliveries
    while (!unavailableTrucks.empty()){
        availableTrucks.push_back(unavailableTrucks.at(unavailableTrucks.size()-1));
        unavailableTrucks.pop_back();
    }
}

void Company::deliveriesMaxProfit(){
    auto startTime = std::chrono::high_resolution_clock::now();
    unsigned int currentVolume = 0, currentWeight = 0, previous_size = warehouse.size();
    int dailyProfit = 0;
    if (!previous_size){
        std::cout << "\tEverything has been delivered!" << std::endl;
        return;
    }
    std::sort(warehouse.begin(), warehouse.end(),[](const Delivery* lhs, const Delivery* rhs) {
        if (lhs->get_profit() == rhs->get_profit()){
            if ((lhs->get_weight() + lhs->get_volume()) == (rhs->get_weight() + rhs->get_volume())) return lhs->get_volume() > rhs->get_volume();
            return lhs->get_weight() + lhs->get_volume() > rhs->get_weight() + rhs->get_volume();
        }
        return lhs->get_profit() > rhs->get_profit();
    });
    std::sort(availableTrucks.begin(), availableTrucks.end(),[](const Truck* lhs, const Truck* rhs) {
        if (lhs->get_cost() == rhs->get_cost()){
            if ((lhs->get_weight() + lhs->get_volume()) == (rhs->get_weight() + rhs->get_volume())) return lhs->get_volume() > rhs->get_volume();
            return lhs->get_weight() + lhs->get_volume() > rhs->get_weight() + rhs->get_volume();
        }
        return lhs->get_cost() < rhs->get_cost();
    });
    
    while (!warehouse.empty() && !availableTrucks.empty()){
        if ((currentVolume + warehouse.at(0)->get_volume() <= availableTrucks.at(0)->get_volume()) &&
        (currentWeight + warehouse.at(0)->get_weight() <= availableTrucks.at(0)->get_weight())) {
            currentVolume += warehouse.at(0)->get_volume(), currentWeight += warehouse.at(0)->get_weight();
            dailyProfit += warehouse.at(0)->get_profit();
            delete warehouse.at(0);
            warehouse.erase(warehouse.begin());
        }
        else {
            dailyProfit -= availableTrucks.at(0)->get_cost();
            unavailableTrucks.push_back(availableTrucks[0]);
            availableTrucks.erase(availableTrucks.begin());
            currentWeight = 0;
            currentVolume = 0;
        }
    }

    if (!availableTrucks.empty()) {
        dailyProfit -= availableTrucks.at(0)->get_cost();
        unavailableTrucks.push_back(availableTrucks[0]);
        availableTrucks.erase(availableTrucks.begin());
    }

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "\tTrucks used: " << unavailableTrucks.size() << '\n';
    std::cout << "\tProfit: " << dailyProfit << '\n';
    std::cout << "\tPackages delivered: " << previous_size - warehouse.size() << " out of " << previous_size << '\n';
    std::cout << "\tAlgorithm Duration: "<< duration.count() << " microseconds" << std::endl;

    // trucks available for next day of deliveries
    while (!unavailableTrucks.empty()){
        availableTrucks.push_back(unavailableTrucks.at(unavailableTrucks.size()-1));
        unavailableTrucks.pop_back();
    }
}

void Company::deliveriesExpress(){
    auto startTime = std::chrono::high_resolution_clock::now();
    const unsigned int time_limit = 28800; // 8 horas em segundos, das 9 às 5
    unsigned int current_time = 0, previous_size = warehouseExpress.size();
    double completion_time = 0.0;
    if (!previous_size){
        std::cout << "\tEverything has been delivered!" << std::endl;
        return;
    }
    std::sort(warehouseExpress.begin(), warehouseExpress.end(),[](const Delivery* lhs, const Delivery* rhs){
        return lhs->get_duration() < rhs->get_duration();
    });
    while (!warehouseExpress.empty()){
        if (current_time + warehouseExpress[0]->get_duration() > time_limit) break;
        current_time += warehouseExpress[0]->get_duration();
        completion_time += (double) current_time;
        delete warehouseExpress.at(0);
        warehouseExpress.erase(warehouseExpress.begin());
    }

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "\tDelivery time: " << current_time << '\n';
    std::cout << "\tPackages delivered: " << previous_size - warehouseExpress.size() << " out of " << previous_size << '\n';
    std::cout << "\tAverage delivery duration: " << current_time / (previous_size - warehouseExpress.size()) << '\n';
    std::cout << "\tAverage completion time: " << completion_time / (previous_size - warehouseExpress.size()) << std::endl;
    std::cout << "\tAlgoritm Duration: "<< duration.count() << " microseconds" << std::endl;
};

void Company::restoreWarehouse(){
    auto deliveryLines = utils::file::readFile("../input/encomendas.txt");

    for (int i = 0; i < warehouse.size(); i++){
        delete warehouse.at(i);
    }

    for (int i = 0; i < warehouseExpress.size(); i++){
        delete warehouseExpress.at(i);
    }

    warehouse.clear(); warehouseExpress.clear();
    storeDeliveries(deliveryLines);

}


