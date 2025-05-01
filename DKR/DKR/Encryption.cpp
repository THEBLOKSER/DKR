#include "Encryption.h"
#include <sstream>

std::string Encryption::caesarEncrypt(const std::string& text) {
    std::string result = text;
    for (char& ch : result) {
        ch = ch + 3;
    }
    return result;
}

std::string Encryption::caesarDecrypt(const std::string& text) {
    std::string result = text;
    for (char& ch : result) {
        ch = ch - 3;
    }
    return result;
}

std::string Encryption::encryptCustomer(const Customer& customer) {
    std::ostringstream oss;
    oss << customer.getId() << ","
        << customer.getLastName() << ","
        << customer.getFirstName() << ","
        << customer.getCreditCardNumber() << ","
        << customer.getBankAccountNumber();

    return caesarEncrypt(oss.str());
}

Customer Encryption::decryptCustomer(const std::string& encryptedData) {
    std::string decrypted = caesarDecrypt(encryptedData);
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
