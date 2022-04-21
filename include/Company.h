#ifndef DA_PROJ_1_COMPANY_H
#define DA_PROJ_1_COMPANY_H

#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "utils.h"
#include "Delivery.h"
#include "truck.h"

/**
 * @brief Represents the company in charge of the deliveries.
 */
class Company {
public:
    /**
     * @brief Creates the company that will deliver the packages.
     * @param companyName The company's name.
     */
    Company(const std::string& companyName);
    /**
     * @brief Destructor for the company (Deletes trucks and all packages).
     */
    ~Company();

    /**
     * @return The company's name.
     */
    std::string getName(){ return companyName; }

    /**
     * @return A vector of all available trucks (unused in a delivery at that moment).
     */
    std::vector<Truck *> get_trucks() const {return availableTrucks;}
    /**
     * @return A vector of all packages for regular delivery (Scenarios 1 and 2)
     */
    std::vector<Delivery *> get_deliveries() const {return warehouse;}
    /**
     * @return A vector of all packages for express delivery (Scenario 3)
     */
    std::vector<Delivery *> get_express_deliveries() const {return warehouseExpress;}

    /**
     * @brief Function that invokes the algorithm that uses the least amount of trucks to deliver the biggest amount
     * of packages possible.
     */
    void deliveriesMinTrucks();
    /**
     * @brief Function that invokes the algorithm that maximises the profit from deliveries.
     */
    void deliveriesMaxProfit();
    /**
     * @brief Function that invokes the algorithm that distributes the package delivery order in a way that minimises
     * the average delivery time.
     */
    void deliveriesExpress();
    /**
     * @brief Function that restores the warehouse's original state (as it was generated with the current dataset).
     */
    void restoreWarehouse();

private:
    /**
     * @brief The company's name.
     */
    std::string companyName;

    /**
     * @note Separated "warehouses" so we can more easily deal with context.
     */

    /**
     * @brief A vector of all packages for regular delivery (Scenarios 1 and 2)
     */
    std::vector<Delivery *> warehouse;
    /**
     * @brief A vector of all packages for express delivery (Scenario 3)
     */
    std::vector<Delivery *> warehouseExpress;
    /**
     * @brief A vector of all available trucks (unused in a delivery at that moment).
     */
    std::vector<Truck *> availableTrucks;
    /**
     * @brief A vector of all unavailable trucks (used in a delivery).
     */
    std::vector<Truck *> unavailableTrucks;
    /**
     * @note No need to store the express delivery truck as it is singular, and maxVolume and maxWeight are irrelevant.
     */

    /**
     * @brief Function that reads truck attributes from dataset and creates trucks for the Company accordingly.
     * @param trucks A vector of strings that contain each truck's attributes.
     */
    void storeTrucks(std::vector<std::string> trucks);
    /**
     * @brief Function that reads package attributes from dataset and creates packages for the Company accordingly.
     * @param deliveries A vector of strings that contain each package's attributes.
     */
    void storeDeliveries(std::vector<std::string> deliveries);

};

#endif //DA_PROJ_1_COMPANY_H