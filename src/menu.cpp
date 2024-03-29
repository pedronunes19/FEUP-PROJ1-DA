#include "../include/menu.h"

bool Menu::exitApplication = false;

void Menu::init() {

    Company deliveryCompany{"GDC (Generic Delivery Company)"};

    atexit(Menu::endProgram);

    while (!Menu::exitApplication) {

        std::cout << std::string(100, '\n');

        int option = Menu::showInitialMenu(deliveryCompany.getName());

        switch (option) {
            case CLIENT:
            case ADMIN:

                if (option == CLIENT) {

                    option = Menu::showClientMenu();

                    switch (option) {
                        case CLIENT_DELIVER_TRUCKS:
                            Menu::deliveriesMinTrucks(deliveryCompany);
                            break;
                        case CLIENT_DELIVER_PROFIT:
                            Menu::deliveriesMaxProfit(deliveryCompany);
                            break;
                        case CLIENT_DELIVER_EXPRESS:
                            Menu::deliveriesExpress(deliveryCompany);
                            break;
                        case CLIENT_BACK:
                            break;
                        default:
                            std::cout << "Invalid option, returning to main menu\n\n";
                            break;
                    }

                } else {

                    option = Menu::showAdminMenu();

                    switch (option) {
                        case ADMIN_RESTORE:
                            Menu::restoreWarehouse(deliveryCompany);
                            break;    
                        case ADMIN_BACK:
                            break;
                        default:
                            std::cout << "Invalid option, returning to main menu\n\n";
                            break;
                    }
                }
                break;
            case LEAVE:
                Menu::exitApplication = true;
                break;
            default:
                std::cout << "\tInvalid option chosen!\n\n";
                break;
        }
    }
}

int Menu::showAdminMenu() {

    int option;

    std::cout << "\tHello, what would you like to do?\n\n";
    std::cout << "\t[1] Restore Warehouse\n\t[2] Back\n\n";
    std::cout << "\t> ";
    std::cin >> option;

    if (!std::cin)
        exit(0);

    std::cout.flush();

    return option;
}

int Menu::showClientMenu() {

    int option;

    std::cout << "\tHello, what would you like to do?\n\n";
    std::cout << "\t[1] Deliveries (min trucks)\n\t[2] Deliveries (max profit)\n\t[3] Express Deliveries\n\t[4] Back\n\n";
    std::cout << "\t> ";
    std::cin >> option;

    if (!std::cin)
        exit(0);

    std::cout.flush();

    return option;
}

int Menu::showInitialMenu(const std::string& busCompany) {

    int option;

    std::cout << "\t\tWelcome to " << busCompany << "\n\n";
    std::cout << "\t[1] Deliveries\n\t[2] Admin\n\t[3] Exit\n\n";
    std::cout << "\t> ";
    std::cin >> option;

    if (!std::cin)
        exit(0);

    std::cout.flush();

    return option;
}

void Menu::waitForPrompt(const std::string &prompt) {
    std::cout << prompt << std::endl;
    std::cin.get();
    if (std::cin.peek() == '\n') std::cin.ignore(100, '\n'); // 100 chars should be enough to ignore
}

void Menu::endProgram() {
    Menu::waitForPrompt("\tProgram terminated, see you soon :) [press ENTER to quit]");
}

void Menu::deliveriesMinTrucks(Company & deliveryCompany){
    deliveryCompany.deliveriesMinTrucks();
    Menu::waitForPrompt("\t[press ENTER to continue]");
}

void Menu::deliveriesMaxProfit(Company & deliveryCompany){
    deliveryCompany.deliveriesMaxProfit();
    Menu::waitForPrompt("\t[press ENTER to continue]");
}

void Menu::deliveriesExpress(Company & deliveryCompany){
    deliveryCompany.deliveriesExpress();
    Menu::waitForPrompt("\t[press ENTER to continue]");
}

void Menu::restoreWarehouse(Company & deliveryCompany){
    deliveryCompany.restoreWarehouse();
    Menu::waitForPrompt("\t[press ENTER to continue]");
}
