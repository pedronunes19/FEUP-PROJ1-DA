#ifndef DA_PROJ_1_TRUCK_H
#define DA_PROJ_1_TRUCK_H

/**
 * @brief Represents a truck that is (initially) able to deliver packages.
 */
class Truck {
public:
    /**
     * @brief Creates a new truck with the specified attributes.
     * @param volume The truck's supported volume.
     * @param weight The truck's supported weight.
     * @param cost The truck's cost.
     */
    Truck(unsigned volume, unsigned weight, unsigned cost): maxVolume(volume), maxWeight(weight), cost(cost){};

    /**
     * @return The truck's supported volume.
     */
    unsigned get_volume() const { return maxVolume; };
    /**
     * @return The truck's supported weight.
     */
    unsigned get_weight() const { return maxWeight; };
    /**
     * @return The truck's cost.
     */
    unsigned get_cost() const{ return cost; }

private:
    /**
     * @brief The truck's supported volume.
     */
    unsigned maxVolume;
    /**
     * @brief The truck's supported weight.
     */
    unsigned maxWeight;
    /**
     * @brief The truck's cost.
     */
    unsigned cost;
};


#endif //DA_PROJ_1_TRUCK_H