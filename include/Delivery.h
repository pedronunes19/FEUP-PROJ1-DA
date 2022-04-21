#ifndef DA_PROJ_1_DELIVERY_H
#define DA_PROJ_1_DELIVERY_H

/**
 * @brief Represents a package to be delivered.
 */
class Delivery {
public:
    /**
     * @brief Creates a new package with the specified attributes.
     * @param volume The package's volume.
     * @param weight The package's weight.
     * @param profit The package's value (money generated upon delivery).
     * @param duration The time taken to deliver the package.
     */
    Delivery( unsigned volume, unsigned weight, unsigned profit, unsigned duration):
    volume(volume), weight(weight), profit(profit), duration(duration){};
    /**
     * @return The package's volume.
     */
    unsigned get_volume() const { return volume; };
    /**
     * @return The package's weight.
     */
    unsigned get_weight() const { return weight; };
    /**
     * @return The package's value (money generated upon delivery).
     */
    unsigned get_profit() const { return profit; };
    /**
     * @return The time taken to deliver the package.
     */
    unsigned get_duration() const { return duration; };

private:
    /**
     * @brief The package's volume.
     */
    unsigned volume;
    /**
     * @brief The package's weight.
     */
    unsigned weight;
    /**
     * @brief The package's value (money generated upon delivery).
     */
    unsigned profit;
    /**
     * @brief The time taken to deliver the package.
     */
    unsigned duration;  // relevant for express delivery
    /**
     * @brief Days since the package's arrival at the warehouse.
     */
    unsigned daysBehind;
};


#endif //DA_PROJ_1_DELIVERY_H
