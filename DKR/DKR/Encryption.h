#pragma once
#include <string>
#include "Customer.h"

class Encryption {
public:
    static std::string encryptCustomer(const Customer& customer, int key);
    static Customer decryptCustomer(const std::string& encryptedData, int key);

private:
    static std::string caesarEncrypt(const std::string& text, int key);
    static std::string caesarDecrypt(const std::string& text, int key);
};
