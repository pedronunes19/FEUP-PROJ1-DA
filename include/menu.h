#ifndef DA_PROJ_1_MENU_H
#define DA_PROJ_1_MENU_H

#include <iostream>
#include "Company.h"
/**
 * @brief The application's menu.
 */
class Menu {
    /**
     * @brief Boolean that becomes true if the user chooses to leave the program.
     */
    static bool exitApplication;

    /**
     * @brief Series of enums that store the options in each menu (Main, Admin and Client).
     */
    enum MainMenuOption {
        CLIENT = 1,
        ADMIN,
        LEAVE
    };

    enum AdminMenuOption {
        ADMIN_RESTORE = 1,
        ADMIN_BACK
    };

    enum ClientMenuOption {
        CLIENT_DELIVER_TRUCKS = 1,
        CLIENT_DELIVER_PROFIT,
        CLIENT_DELIVER_EXPRESS,
        CLIENT_BACK
    };

    /**
     * @brief Waits for user input (new line) to progress
     * @param prompt
     */
    static void waitForPrompt(const std::string& prompt);

public:
    /**
     * @brief Initialize the program
     */
    static void init();

    /**
     * @brief Shows the initial menu on screen
     * @param busCompanyName Name of the bus company we are travelling with (displayed on screen)
     * @return User option (Client/Admin/EXit)
     */
    static int showInitialMenu(const std::string& busCompanyName);
    /**
     * @brief Shows the administrator menu on screen
     * @return User option (from the admin functionalities available)
     */
    static int showAdminMenu();
    /**
     * @brief Shows the administrator menu on screen
     * @return User option (from the client functionalities available)
     */
    static int showClientMenu();
    /**
     * @brief Close the program
     */
    static void endProgram();
    /**
     * @brief Set of functions that call the respective Company methods with the same name.
     * @param deliveryCompany The Company tasked with the deliveries.
     */
    static void deliveriesMinTrucks(Company & deliveryCompany);
    static void deliveriesMaxProfit(Company & deliveryCompany);
    static void deliveriesExpress(Company & deliveryCompany);
    static void restoreWarehouse(Company & deliveryCompany);



};

#endif //DA_PROJ_1_MENU_H