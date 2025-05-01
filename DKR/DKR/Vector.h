#pragma once
#include <vector>
#include <string>
#include "Customer.h"

class Vector {
private:
    std::vector<std::string> encryptedCustomers;
    int outputOption = 0;
    int minCard = 0;
    int maxCard = 9999;

public:
    void addCustomer(const Customer& customer);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void setOption(int opt);
    void setCardRange(int minC, int maxC);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};