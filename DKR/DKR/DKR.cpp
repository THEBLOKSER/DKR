#include "Vector.h"
#include "Customer.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Customer inputCustomer() {
    int id, card, bank;
    std::string lastName, firstName;

    std::cout << "Enter ID: ";
    std::cin >> id;

    std::cout << "Enter last name: ";
    clearInputBuffer();
    std::getline(std::cin, lastName);

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter credit card number: ";
    std::cin >> card;

    std::cout << "Enter bank account number: ";
    std::cin >> bank;

    return Customer(id, lastName, firstName, card, bank);
}

int main() {
    Vector customerVector;
    std::string filename = "customers.txt";
    customerVector.loadFromFile(filename);

    int choice;
    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Add a new customer\n";
        std::cout << "2. Display customers alphabetically\n";
        std::cout << "3. Display customers by credit card range\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Customer newCustomer = inputCustomer();
            customerVector.addCustomer(newCustomer);
            customerVector.saveToFile(filename);
            break;
        }
        case 2: {
            customerVector.setOption(1);
            std::cout << customerVector;
            break;
        }
        case 3: {
            int minC, maxC;
            std::cout << "Enter minimum credit card number: ";
            std::cin >> minC;
            std::cout << "Enter maximum credit card number: ";
            std::cin >> maxC;
            customerVector.setCardRange(minC, maxC);
            customerVector.setOption(2);
            std::cout << customerVector;
            break;
        }
        case 4:
            std::cout << "Exiting program...\n";
            return 0;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
