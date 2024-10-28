#pragma  once
#include "Person.h"
#include "Address.h"
#include "Array.h"

class Contact {
private:
    Array<Person> contacts;

public:
    Contact(const Contact& cop) : contacts(cop.contacts) {}
    void addCont(const Person& contact) {
        contacts.AddContact(contact);
    }
    
    /*/void searchByName(std::string& name) const
    {
        for (int i = 0; i < contacts.getSize(); i++)
        {

           
            }
        }
    }*/


    /*void searchByPhoneNumber( std::string& phoneNumber) const {


        for (int i = 0; i < contacts.getSize(); i++)
        {
            if (contacts[i].phoneNumber == phoneNumber) {

            }
        }
    }

        void searchByClassification(const std::string& classification) const {
            for (int i = 0; i < contacts.getSize(); i++) {
                if (contacts[i].classification == classification) {
               }
            }
    }*/



    void deleteContact(const std::string& name) {
        for (int i = 0; i < contacts.getSize(); i++) {
            if (contacts[i].get_LName() == name) {
                // remove the contact from the contacts array
                return;
            }
        }
    }

    /*void updateContactInformation(const std::string& name, const Contact& newContact)
     {
         for (int i = 0; i < contacts.getSize(); i++) {
             if (contacts[i].get_FName() == name) {
                 contacts[i] = newContact;
                 return;
             }
         }
     }*/

    void reverseContactsBook() {
        Array<Person> reverse;
        for (int i = contacts.getSize() - 1; i >= 0; i--) {
            reverse.AddContact(contacts[i]);
        }
        contacts = reverse;
    }



    /*void addCont(Person contact)
    {
        std::string name, lname, n;

        std::cout << "Enter Contact First Name: ";
        contact.set_FName(name);
        std::cout << "Enter Contact Last Name: ";
        contact.set_LName(lname);
        std::cin >> lname;
        std::cout << "Enter Contact pn Name: ";
        std::cin >> n;
        contact.setPhoneNumber(n);
        //Address K(15,2,"ELSHONA","ZAG","");
        //contact.setAddress()
        contacts.AddContact(contact);
    }*/
    /*void disply()
    {
        contacts.display_c();
        //Address a = contacts[0].getAddress();
        std::cout << "Name: " << contacts[0].get_FName() << "\n";
        std::cout << "Phone Number: " << contacts[0].getPhoneNumber() << "\n";
        std::cout << "Address: " << contacts[0].getAddress().getFlat_NUM()
            << ", " << contacts[0].getAddress().get_Bulding_NUM()
            << ", " << contacts[0].getAddress().get_Street()
            << ", " << contacts[0].getAddress().get_City()
            << ", " << contacts[0].getAddress().get_Govern()
            << "," << contacts[0].getAddress().get_country() << "\n";
        std::cout << "Favorite: " << (contacts[0].isFavoriteContact() ? "Yes" : "No") << "\n";
        std::cout << "Classification: " << contacts[0].getClassi() << "\n";
    }*/
};


