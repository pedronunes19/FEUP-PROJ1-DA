#ifndef DA_PROJ_1_TRUCK_H
#define DA_PROJ_1_TRUCK_H


class Truck {
public:
    Truck(unsigned volume, unsigned weight, unsigned cost): maxVolume(volume), maxWeight(weight), cost(cost){};
    
    unsigned get_volume() const { return maxVolume; };
    unsigned get_weight() const { return maxWeight; };
    std::string get_plate() const{ return plate; }

private:
    std::string plate;  // not in the dataset so...
    unsigned maxVolume;
    unsigned maxWeight;
    unsigned cost;
};


#endif //DA_PROJ_1_TRUCK_H