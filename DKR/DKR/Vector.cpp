#include "Vector.h"
#include "Encryption.h"
#include <fstream>
#include <iostream>
#include <algorithm>

void Vector::addCustomer(const Customer& customer) {
    std::string encrypted = Encryption::encryptCustomer(customer);
    encryptedCustomers.push_back(encrypted);
}

void Vector::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    for (const auto& enc : encryptedCustomers) {
        file << enc << std::endl;
    }

    file.close();
}

void Vector::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    encryptedCustomers.clear();
    std::string line;
    while (std::getline(file, line)) {
        encryptedCustomers.push_back(line);
    }

    file.close();
}

void Vector::setOption(int opt) {
    outputOption = opt;
}

void Vector::setCardRange(int minC, int maxC) {
    minCard = minC;
    maxCard = maxC;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    std::vector<Customer> decrypted;

    for (const std::string& enc : vec.encryptedCustomers) {
        decrypted.push_back(Encryption::decryptCustomer(enc));
    }

    switch (vec.outputOption) {
    case 1: {
        std::sort(decrypted.begin(), decrypted.end(), [](const Customer& a, const Customer& b) {
            return a.getLastName() < b.getLastName();
            });

        os << "List of buyers in alphabetical order:\n";
        for (const Customer& c : decrypted) {
            os << c << "\n";
        }
        break;
    }
    case 2: {
        os << "Shoppers with cards in range [" << vec.minCard << ", " << vec.maxCard << "]:\n";
        for (const Customer& c : decrypted) {
            if (c.getCreditCardNumber() >= vec.minCard && c.getCreditCardNumber() <= vec.maxCard) {
                os << c << "\n";
            }
        }
        break;
    }
    default:
        os << "Unknown output option.\n";
    }

    return os;
}

