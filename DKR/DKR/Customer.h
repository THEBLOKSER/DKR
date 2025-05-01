#pragma once
#include <string>

using namespace std;

class Customer
{
	int m_Id;
	string m_LastName;
	string m_FirstName;
	int m_CardNum;
	int m_BankAccNum;

public:
	Customer(int Id, string LastName, string FirstName, int CardNum, int BankAccNum);
	Customer();
	void ExitOfNames();
	void IntervalOfCards();
	void setId(int newId);
	void setLastName(const std::string& newLastName);
	void setFirstName(const std::string& newFirstName);
	void setCreditCardNumber(int newCardNumber);
	void setBankAccountNumber(int newAccountNumber);
	int getId() const;
	std::string getLastName() const;
	std::string getFirstName() const;
	int getCreditCardNumber() const;
	int getBankAccountNumber() const;
};

