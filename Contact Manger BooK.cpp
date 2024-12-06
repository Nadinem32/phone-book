#include "Array.h"
#include "Person.h"
#include "address.h"
#include "contact.h"

#include <iostream>

using namespace std;

void clearScreen()
{
#ifdef _WIN32 
	system("cls");
#else 
	system("clear");
#endif 
}

void displayLine()
{
	for (int i = 0; i < 120; i++) {
		std::cout << "-";
	}
	std::cout << endl;
}

void displayTitle(string title) {
	displayLine();
	cout << title << endl;
	displayLine();
}

int main() {

	Contact contacts;

	int choice;

	do {
		clearScreen();
		cout << "\t\t\t\tWelcome to Binary Team Contact Book" << endl;
		displayTitle("\t\t\t\t\tContact Book List");
		cout << "\t\t\t\t\t1. Add Contact" << endl;
		cout << "\t\t\t\t\t2. Delete Contact" << endl;
		cout << "\t\t\t\t\t3. Update Contact" << endl;
		cout << "\t\t\t\t\t4. Search Contact by Last Name" << endl;
		cout << "\t\t\t\t\t5. Search Contact by Phone Number" << endl;
		cout << "\t\t\t\t\t6. Display Contacts" << endl;
		cout << "\t\t\t\t\t7. Display Favorite Contacts" << endl;
		cout << "\t\t\t\t\t8. Save to file " << endl;
		cout << "\t\t\t\t\t9. Load from file " << endl;
		cout << "\t\t\t\t\t10. Reverse contact book " << endl;
		cout << "\t\t\t\t\t11. Search Contact by Classification" << endl;
		cout << "\t\t\t\t\t12. Exit" << endl;
		displayLine();
		cout << "What is the operation You want to do \n Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:

		{
			clearScreen();
			cout << "Welcome to Binary Team Contact Book" << endl;
			displayTitle("\t\t\t\tAdd Contact");

			std::cout << "The Contact Data\n";
			displayLine();
			cout << "Enter The Contact First Name: ";

			std::string firstName;
			std::cin >> firstName;

			cout << "Enter The Contact Last Name: ";

			std::string lastName;
			std::cin >> lastName;

			cout << "Is Favorite? (1 for yes, 0 for no): ";

			bool isFavorite;
			std::cin >> isFavorite;

			cout << "Enter classifiction (friend,work,family): ";

			string classi;
			std::cin >> classi;
			//if (classi != "friend" || classi != "work" || classi != "family")
			//{
				//classi = "Other";
			//}

			displayTitle("Cominication Information");
			cout << "Enter The Contact Email: ";

			std::string email;
			std::cin >> email;

			cout << "Enter The Contact Phone Number: ";

			std::string phone;
			std::cin >> phone;
			while (phone.size() != 11)
			{
				std::cout << "Invalid Phone Number!!\nEnter valid Phone Number: ";
				cin >> phone;
			}

			displayTitle("Address Information");
			cout << "Enter Your Country: ";

			std::string country;
			std::cin >> country;

			cout << "Enter Your Government: ";

			std::string government;
			std::cin >> government;

			cout << "Enter Your City: ";

			std::string city;
			std::cin >> city;

			cout << "Enter Your Street: ";

			std::string street;
			std::cin >> street;

			cout << "Enter Your Building Number: ";

			int buildingNumber;
			std::cin >> buildingNumber;

			cout << "Enter Your Flat Number: ";

			int flatNumber;
			std::cin >> flatNumber;

			Address addressInfo(flatNumber, buildingNumber, street, city, government, country);
			Person personalInfo(firstName, lastName, phone, email, classi, isFavorite, addressInfo);

			contacts.addCont(personalInfo);

			cout << "Contact has been added Successfully...." << endl;
			system("pause");

			break;
		}

		case 2:
		{

			clearScreen();

			displayTitle("\t\tDelete Contact");
			cout << "Enter Contact Name that You want to delete: ";
			std::string name;
			std::cin >> name;
			contacts.deleteContact(name);
			//displayTitle("\t\tContact has been deleted successfully.");
			system("pause");

			break;
		}
		case 3:
		{
			clearScreen();
			displayTitle("\t\tUpdate contact information");
			std::cout << "Enter the First Name of the contact you want to update: ";
			std::string n_name;
			std::cin >> n_name;
			contacts.updateContact(n_name);

			system("pause");

			break;

		}

		case 4: 
		{

			clearScreen();
			displayTitle("\t\t\t\tSearch Contact by Name");
			cout << "Enter The Last Name of Contact to search: ";
			std::string name;
			std::cin >> name;
			contacts.searchByLastName(name);
			system("pause");

			break;
		}
		case 5: 
		{

			clearScreen();
			displayTitle("\t\t\tSearch Contact by Phone Number");
			cout << "Enter The Phone Number of Contact to search: ";
			std::string pn;
			std::cin >> pn;
			if (pn.size() == 11)
			{
				contacts.searchByPhoneNumber(pn);
			}
			else
			{
				std::cout << "Wrong Phone Number..\n";
				std::cout << "Enter Right phone Number: ";
				std::cin >> pn;
			}

			system("pause");

			break;
		}
		case 6:
		{

			clearScreen();
			displayTitle("\t\tDisplay Contacts");
			std::cout << setw(3) << "id" << setw(15) << "Fname" << setw(15) << "Lname" << setw(15) << "Email" << setw(15) << "classi" << setw(15) << "Fav" << setw(18) << "phone" << setw(18) << "Address\n";
			displayLine();

			contacts.disply_contacts();
			system("pause");

			break;
		}
		case 7: 
		{
			clearScreen();
			displayTitle("\t\t\tFavorite Contacts");
			contacts.disply_fav_contacts();
			system("pause");

			break;
		}
		case 8: 
		{
			std::string filename;
			std::cout << "Enter the filename to save contacts: ";
			std::cin >> filename;
			contacts.saveToFile(filename);
			std::cout << "The contacts have been saved to file" << "\n";
			system("pause");
			break;
		}

		case 9: 
		{
			std::string filename;
			std::cout << "Enter the filename to load contacts: ";
			std::cin >> filename;
			contacts.loadFromFile(filename);
			std::cout << "The contacts have been loaded from file" << "\n";
			system("pause");
			break;
		}
		case 10:
		{
			clearScreen();
			displayTitle("\t\tReversed Contact Book");
			contacts.reverseContactsBook();
			system("pause");

			break;
		}
		case 11:
		{
			clearScreen();
			displayTitle("\t\tSearch Contact by Classification");
			cout << "Enter The Classification of Contact to search: ";
			std::string Classification;
			std::cin >> Classification;
			contacts.searchByClassification(Classification);
			system("pause");

			break;
		}
		case 12: 
		{
			clearScreen();
			displayTitle("\t\t\t\t\t\t\tExit");
			cout << "\n\t\t\t\t\t\tAu revoir, cher utilisateur....\n";
			return 0;
		}
		}


	} while (choice >= 1 && choice <= 12);

	return 0;
}
