#pragma once
#include <string>
#include "Customer.h"

class Encryption {
public:
    static std::string encryptCustomer(const Customer& customer);
    static Customer decryptCustomer(const std::string& encryptedData);
    static std::string caesarEncrypt(const std::string& text);
    static std::string caesarDecrypt(const std::string& text);
};
