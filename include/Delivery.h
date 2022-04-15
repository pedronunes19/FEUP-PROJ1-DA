#ifndef DA_PROJ_1_DELIVERY_H
#define DA_PROJ_1_DELIVERY_H


class Delivery {
public:
    Delivery( unsigned volume, unsigned weight, unsigned profit, unsigned duration):
    volume(volume), weight(weight), profit(profit), duration(duration){};
    
    unsigned get_volume() const { return volume; };
    unsigned get_weight() const { return weight; };
    unsigned get_profit() const { return profit; };
    unsigned get_duration() const { return duration; };

private:

    unsigned volume;
    unsigned weight;
    unsigned profit;
    unsigned duration;  // relevant for express delivery
    unsigned daysBehind;
};


#endif //DA_PROJ_1_DELIVERY_H
