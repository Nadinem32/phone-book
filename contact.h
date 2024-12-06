#pragma once
#include "Person.h"
#include "address.h"
#include "Array.h"
#include<iomanip>
#include<string>

#include<fstream>
void display_Line()
{
    for (int i = 0; i < 120; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

class Contact {
private:
    Array<Person> contacts;

public:
    Contact()
    {
    }

    void addCont(Person contact) {
        contacts.AddContact(contact);
    }
    void saveToFile(const std::string& filename)
    {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < contacts.getSize(); i++) {
                file << contacts[i].get_FName() << "\n";
                file << contacts[i].get_LName() << "\n";
                file << contacts[i].getPhoneNumber() << "\n";
                file << contacts[i].getEmail() << "\n";
                file << contacts[i].getClassi() << "\n";
                file << (contacts[i].isFavoriteContact() ? "1" : "0") << "\n"; // Save as 1 or 0
                Address addr = contacts[i].getAddress();
                file << addr.getFlat_NUM() << "\n";
                file << addr.get_Bulding_NUM() << "\n";
                file << addr.get_Street() << "\n";
                file << addr.get_City() << "\n";
                file << addr.get_Govern() << "\n";
                file << addr.get_country() << "\n";
            }
            file.close();
        }
        else {
            std::cout << "Unable to open file for saving.\n";
        }
    }

    void loadFromFile(const std::string& filename)
    {
        std::ifstream file(filename);
        if (file.is_open()) {
            contacts.clear();
            while (!file.eof()) {
                std::string firstName, lastName, phoneNumber, email, classification;
                bool isFavorite;
                int flatNumber, buildingNumber;
                std::string street, city, government, country;
                
                std::getline(file, firstName);
                std::getline(file, lastName);
                std::getline(file, phoneNumber);
                std::getline(file, email);
                std::getline(file, classification);
                file >> isFavorite;
                file.ignore(); 
                file >> flatNumber;
                file >> buildingNumber;
                file.ignore();
                std::getline(file, street);
                std::getline(file, city);
                std::getline(file, government);
                std::getline(file, country);
                Address addressInfo(flatNumber, buildingNumber, street, city, government, country);
                Person personalInfo(firstName, lastName, phoneNumber, email, classification, isFavorite, addressInfo);
                Contact h;
                contacts.AddContact(personalInfo);
            }
            file.close();
        }
        else {
            std::cout << "Unable to open file for loading.\n";
        }
    }

    void searchByPhoneNumber(std::string phonenum)
    {
        for (int i = 0; i < contacts.getSize(); i++)
        {
            if (contacts[i].getPhoneNumber() == phonenum)
            {
                display_Line();
                std::cout << "Here Is The contact you want\n";
                display_Line();
                contacts[i].display();
                return;
            }
        }
        display_Line();
        std::cout << "Not Found!!\n";
        display_Line();
    }

    void searchByLastName(std::string lname)
    {
        for (int i = 0; i < contacts.getSize(); i++)
        {
            if (contacts[i].get_LName() == lname)
            {
                display_Line();
                std::cout << "Here Is The contact you want\n";
                display_Line();
                contacts[i].display();
                return;
            }
        }
        display_Line();
        std::cout << "Not Found!!\n";
        display_Line();
    }

    void searchByClassification(std::string classification)
    {
        for (int i = 0; i < contacts.getSize(); i++)
        {
            if (contacts[i].getClassi() == classification)
            {
                display_Line();
                std::cout << "Here Is The contact you want\n";
                display_Line();
                contacts[i].display();
                return;
            }
        }
        display_Line();
        std::cout << "Not Found!!\n";
        display_Line();
    }



    void deleteContact(std::string name) {
        for (int i = 0; i < contacts.getSize(); i++) {
            if (contacts[i].get_FName() == name) {
                contacts.Delete_Contact(i);
                display_Line();
                std::cout << "Contact has been deleted successfully\n";
                display_Line();
                return;
            }
        }
        display_Line();
        std::cout << "Not Found\n";
        display_Line();
    }
    Contact& operator=(const Contact& c)
    {

        if (this != &c)
        {
            contacts = c.contacts;

        }

        return *this;

    }
    void updateContact(std::string name)
    {
        bool contactExists = false;
        for (int i = 0; i < contacts.getSize(); i++) {
            if (contacts[i].get_FName() == name) {
                contactExists = true;
                break;
            }
        }

        if (!contactExists) {
            std::cout << "Contact with the first name not found!!\n";
            return;
        }
        std::string firstName, lastName, phoneNumber, email, classification;
        bool isFavorite;
        int flatNumber, buildingNumber;
        std::string street, city, government, country;
        std::cout << "Enter New First Name: ";
        std::cin >> firstName;
        std::cout << "Enter New Last Name: ";
        std::cin >> lastName;
        std::cout << "Enter New Phone Number: ";
        std::cin >> phoneNumber;
        std::cout << "Enter New Email: ";
        std::cin >> email;
        std::cout << "Enter New Classification: ";
        std::cin >> classification;
        std::cout << "Is Favorite? (1 (yes), 0(no)): ";
        std::cin >> isFavorite;
        display_Line();
        std::cout << "Enter New Address Information:\n";
        display_Line();
        std::cout << "Flat Number: ";
        std::cin >> flatNumber;
        std::cout << "Building Number: ";
        std::cin >> buildingNumber;
        std::cout << "Street: ";
        std::cin >> street;
        std::cout << "City: ";
        std::cin >> city;
        std::cout << "Government: ";
        std::cin >> government;
        std::cout << "Country: ";
        std::cin >> country;
        Address newAddress(flatNumber, buildingNumber, street, city, government, country);
        Person newContact(firstName, lastName, phoneNumber, email, classification, isFavorite, newAddress);
        for (int i = 0; i < contacts.getSize(); i++) {
            if (contacts[i].get_FName() == name) {
                contacts[i] = newContact;
                return;
            }
        }
        std::cout << "Contact updated successfully.\n";
    }

    void reverseContactsBook() {
        if (contacts.getSize() == 0)
        {
            std::cout << "There is No contacts to reverse\n";
        }
        Array<Person> reverse;
        for (int i = contacts.getSize() - 1; i >= 0; i--) {
            reverse.AddContact(contacts[i]);
        }
        contacts = reverse;
        disply_contacts();
    }
    void disply_contacts()
    {
        if (contacts.getSize() == 0)
        {
            std::cout << "There is No contacts to display\n";
        }
        for (int i = 0;i < contacts.getSize();i++)

        {
            std::cout << "[" << i+1 << "]";
            contacts[i].display();
        }
        display_Line();
    }
    void disply_fav_contacts()
    {
        if (contacts.getSize() == 0)
        {
            std::cout << "There is No contacts to display\n";
        }
        for (int i = 0;i < contacts.getSize();i++)
        {

            if (contacts[i].isFavoriteContact() == 1)
            {

                contacts[i].display();
            }

        }
        display_Line();
    }
};
