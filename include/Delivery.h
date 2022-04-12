#ifndef DA_PROJ_1_DELIVERY_H
#define DA_PROJ_1_DELIVERY_H


class Delivery {
public:
    Delivery( unsigned volume, unsigned weight, unsigned profit, unsigned duration):
    _volume(volume), _weight(weight), _profit(profit), _duration(duration){};
    
    unsigned get_volume() const { return _volume; };
    unsigned get_weight() const { return _weight; };
    unsigned get_profit() const { return _profit; };
    unsigned get_duration() const { return _duration; };

private:
    unsigned _volume;
    unsigned _weight;
    unsigned _profit;
    unsigned _duration;
};


#endif //DA_PROJ_1_DELIVERY_H
