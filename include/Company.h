#ifndef DA_PROJ_1_COMPANY_H
#define DA_PROJ_1_COMPANY_H

class Company {
public:
    std::vector<Truck *> get_trucks() const {return trucks;}
    std::vector<Delivery *> get_deliveries() const {return warehouse;}

private:
    std::vector<Delivery *> warehouse;
    std::vector<Truck *> trucks;
}

#endif //DA_PROJ_1_COMPANY_H