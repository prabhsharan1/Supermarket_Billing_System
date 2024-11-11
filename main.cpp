#include "SupermarketBillingSystem.hpp"
#include <iostream>

int main() {
    SupermarketBillingSystem system("Shop.dat");
    int choice;

    do {
        system.displayMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        system.handleUserChoice(choice);
    } while (choice != 7);

    return 0;
}
