#pragma once
#include "address.h"

class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
    std::string classification;
    bool is_favorite;
    Address address;

public:
    Person()
    {
        /*firstName = "Nadine";
        lastName = "Hosny";
        phoneNumber = "00541";
        email = "nadine@gmail.com";
        classification = "family";
        is_favorite = true;
        address.setFlat_NUM(15);
        address.set_Bulding_NUM(12);
        address.set_Street("elshona");
        address.set_City("zagazig");
        address.set_Govern("sharkia");
        address.set_country("Egypt");*/

    }
    Person& operator=(const Person& other) {
        if (this != &other) {
            firstName = other.firstName;
            lastName = other.lastName;
            phoneNumber = other.phoneNumber;
            email = other.email;
            classification = other.classification;
            is_favorite = other.is_favorite;
            address = other.address;
        }
        return *this;
    }
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
    void display()
    {
        std::cout << "Name:" << firstName << " " << lastName << "\n";
        std::cout << "Phone Number: " << phoneNumber << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "classification: " << classification << "\n";
        std::cout << "Favorite:" << is_favorite << "\n";
        std::cout << "Addrss: Flat Number" << address.getFlat_NUM() << " - "
            << "Building " << address.get_Bulding_NUM() << " - "
            << "Street " << address.get_Street() << " - "
            << address.get_City() << " - "
            << address.get_Govern() << " - "
            << address.get_country() << "\n";
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

