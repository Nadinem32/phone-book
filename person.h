#pragma once
#include<iostream>
#include<iomanip>
#include "address.h"
void display_line()
{
	for (int i = 0; i < 120; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}

class Person
{
private:
	std::string firstName;
	std::string lastName;
	std::string phoneNumber;
	std::string email;
	std::string classification;
	bool is_favorite;
	Address address;

public:
	Person() {}

	Person(std::string firstName, std::string lastName, std::string phoneNumber, std::string email, std::string classification, bool is_favorite, Address add)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->phoneNumber = phoneNumber;
		this->email = email;
		this->classification = classification;
		this->is_favorite = is_favorite;
		address = add;
	}

	Person(const Person& cop)
	{
		address = cop.address;
		firstName = cop.firstName;
		lastName = cop.lastName;
		phoneNumber = cop.phoneNumber;
		email = cop.email;
		classification = cop.classification;
		is_favorite = cop.is_favorite;
	}
	Person& operator=(const Person& m) {
		if (this != &m) {
			address = m.address;
			firstName = m.firstName;
			lastName = m.lastName;
			phoneNumber = m.phoneNumber;
			email = m.email;
			classification = m.classification;
			is_favorite = m.is_favorite;
		}
		return *this;
	}

	void display()
	{

		std::cout << std::setw(15) << firstName << std::setw(15) << lastName;

		std::cout << std::setw(18) << email;
		std::cout << std::setw(15) << classification;
		std::cout << std::setw(15) << ((is_favorite) ? "Yes" : "No");
		std::cout << std::setw(20) << phoneNumber;
		std::cout << "   ";
		std::cout << address.getFlat_NUM() << "-"
			<< address.get_Bulding_NUM() << "-"
			<< address.get_Street() << "-"
			<< address.get_City() << "-"
			<< address.get_Govern() << "-"
			<< address.get_country() << "\n";
		display_line();
	}

	void set_FName(std::string firstName)
	{
		this->firstName = firstName;
	}

	void set_LName(std::string lastName)
	{
		this->lastName = lastName;
	}

	void setPhoneNumber(std::string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}

	void setEmail(std::string email) {
		this->email = email;
	}

	void setClassi(std::string classification)
	{
		this->classification = classification;
	}

	void setFavorite(bool is_favorite)
	{
		this->is_favorite = is_favorite;
	}

	void setAddress(Address& address)
	{
		this->address = address;
	}

	std::string get_FName()
	{
		return firstName;
	}

	std::string get_LName()
	{
		return lastName;
	}

	std::string getPhoneNumber() {
		return phoneNumber;
	}

	std::string getEmail() {
		return email;
	}

	std::string getClassi()
	{
		return classification;
	}

	bool isFavoriteContact()
	{
		return is_favorite;
	}

	Address getAddress()
	{
		return address;

	}
};
