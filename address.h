#pragma once

class Address {
private:
    int flatNumber;
    int BuldingNumber;
    std::string street;
    std::string city;
    std::string government;
    std::string country;
    //friend class person;
public:
    Address()
    {}
    Address(int flatNumber, int BuldingNumber, std::string street, std::string city, std::string government, std::string country)
    {
        this->flatNumber = flatNumber;
        this->BuldingNumber = BuldingNumber;
        this->street = street;
        this->city = city;
        this->government = government;
        this->country = country;
    }
    Address(const Address& cop)
    {
        flatNumber = cop.flatNumber;
        BuldingNumber = cop.BuldingNumber;
        street = cop.street;
        city = cop.city;
        government = cop.government;
        country = cop.country;
    }
    void setFlat_NUM(int flatNumber)
    {
        this->flatNumber = flatNumber;
    }
    void set_Bulding_NUM(int BuldingNumber)
    {
        this->BuldingNumber = BuldingNumber;
    }
    void set_Street(std::string street)
    {
        this->street = street;
    }
    void set_City(std::string city)
    {
        this->city = city;
    }
    void set_Govern(std::string government)
    {
        this->government = government;
    }
    void set_country(std::string country)
    {
        this->country = country;
    }

    int getFlat_NUM()
    {
        return flatNumber;
    }
    int get_Bulding_NUM()
    {
        return BuldingNumber;
    }
    std::string get_Street()
    {
        return street;
    }
    std::string get_City()
    {
        return city;
    }
    std::string get_Govern()
    {
        return government;
    }
    std::string get_country()
    {
        return country;
    }
};
 