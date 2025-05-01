#include "Customer.h"
#include <iostream>
#include <algorithm>

using namespace std;

Customer::Customer(int Id, string LastName, string FirstName, int CardNum, int BankAccNum)
	:m_Id(Id), m_LastName(LastName), m_FirstName(FirstName), m_CardNum(CardNum), m_BankAccNum(BankAccNum){}

Customer::Customer()
	:m_Id(0000), m_LastName("NoName"), m_FirstName("NoName"), m_CardNum(0000), m_BankAccNum(00000){}

void Customer::setId(int newId) {
    m_Id = newId;
}

void Customer::setLastName(const std::string& newLastName) {
    m_LastName = newLastName;
}

void Customer::setFirstName(const std::string& newFirstName) {
    m_FirstName = newFirstName;
}

void Customer::setCreditCardNumber(int newCardNumber) {
    m_CardNum = newCardNumber;
}

void Customer::setBankAccountNumber(int newAccountNumber) {
    m_BankAccNum = newAccountNumber;
}

int Customer::getId() const {
    return m_Id;
}

string Customer::getLastName() const {
    return m_LastName;
}

string Customer::getFirstName() const {
    return m_FirstName;
}

int Customer::getCreditCardNumber() const {
    return m_CardNum;
}

int Customer::getBankAccountNumber() const {
    return m_BankAccNum;
}

ostream& operator<<(ostream& os, const Customer cust) {
    
    os << endl;
    return os;
}