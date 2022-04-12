#ifndef DA_PROJ_1_TRUCK_H
#define DA_PROJ_1_TRUCK_H


class Truck {
public:
    Truck(unsigned volume, unsigned weight, std::string plate): maxVolume(volume), maxWeight(weight), plate(plate){};
    
    unsigned get_volume() const { return maxVolume; };
    unsigned get_weight() const { return maxWeight; };
    std::string get_plate() const{ return plate; }

private:
    std::string plate;
    unsigned maxVolume;
    unsigned maxWeight;
};


#endif //DA_PROJ_1_TRUCK_H