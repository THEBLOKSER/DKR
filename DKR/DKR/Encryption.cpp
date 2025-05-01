#include "Encryption.h"
#include <sstream>

std::string Encryption::caesarEncrypt(const std::string& text, int key) {
    std::string result = text;
    for (char& ch : result) {
        ch = ch + key;
    }
    return result;
}

std::string Encryption::caesarDecrypt(const std::string& text, int key) {
    std::string result = text;
    for (char& ch : result) {
        ch = ch - key;
    }
    return result;
}

std::string Encryption::encryptCustomer(const Customer& customer, int key) {
    std::ostringstream oss;
    oss << customer.getId() << ","
        << customer.getLastName() << ","
        << customer.getFirstName() << ","
        << customer.getCreditCardNumber() << ","
        << customer.getBankAccountNumber();

    return caesarEncrypt(oss.str(), key);
}

Customer Encryption::decryptCustomer(const std::string& encryptedData, int key) {
    std::string decrypted = caesarDecrypt(encryptedData, key);
    std::istringstream iss(decrypted);

    std::string idStr, lastName, firstName, cardStr, bankStr;
    std::getline(iss, idStr, ',');
    std::getline(iss, lastName, ',');
    std::getline(iss, firstName, ',');
    std::getline(iss, cardStr, ',');
    std::getline(iss, bankStr, ',');

    return Customer(
        std::stoi(idStr),
        lastName,
        firstName,
        std::stoi(cardStr),
        std::stoi(bankStr)
    );
}
