#ifndef DA_PROJ_1_MENU_H
#define DA_PROJ_1_MENU_H

#include <iostream>
#include "Company.h"

class Menu {

    static std::string ADMIN_PASSWORD;

    static bool exitApplication;

    enum MainMenuOption {
        CLIENT = 1,
        ADMIN,
        LEAVE
    };

    enum AdminMenuOption {
        ADMIN_BACK = 1
    };

    enum ClientMenuOption {
        CLIENT_DELIVER_TRUCKS = 1,
        CLIENT_DELIVER_PROFIT,
        CLIENT_DELIVER_EXPRESS,
        CLIENT_BACK
    };

    /**
     * Waits for user input (new line) to progress
     * @param prompt
     */
    static void waitForPrompt(const std::string& prompt);

public:
    /**
     * Initialize the program
     */
    static void init();

    /**
     * Shows the initial menu on screen
     * @param busCompanyName Name of the bus company we are travelling with (displayed on screen)
     * @return User option (Client/Admin/EXit)
     */
    static int showInitialMenu(const std::string& busCompanyName);
    /**
     * Shows the administrator menu on screen
     * @return User option (from the admin functionalities available)
     */
    static int showAdminMenu();
    /**
     * Shows the administrator menu on screen
     * @return User option (from the client functionalities available)
     */
    static int showClientMenu();

    /**
     * Close the program
     */
    static void endProgram();

    static void deliveriesMinTrucks(Company & deliveryCompany);
    static void deliveriesMaxProfit(Company & deliveryCompany);
    static void deliveriesExpress(Company & deliveryCompany);


};

#endif //DA_PROJ_1_MENU_H