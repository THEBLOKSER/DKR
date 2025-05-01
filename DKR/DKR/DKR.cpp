#include <iostream>
#include <vector>
#include "Customer.h"
#include "Encryption.h"
#include "Vector.h"

int main()
{
    Vector vec;
    vec.loadFromFile("customers.txt");

    int option;
    std::cout << "Select mode (1 — alphabet, 2 — spacing): ";
    std::cin >> option;

    vec.setOption(option);

    if (option == 2) {
        int minCard, maxCard;
        std::cout << "Enter the minimum card number: ";
        std::cin >> minCard;
        std::cout << "Enter the maximum card number: ";
        std::cin >> maxCard;
        vec.setCardRange(minCard, maxCard);
    }

    std::cout << vec;

}