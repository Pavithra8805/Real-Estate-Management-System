#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Property {
protected:
    string location;
    double price;
    bool availability;

public:
    virtual void display() = 0;

    void setLocation(string loc) {
        location = loc;
    }
    string getLocation() {
        return location;
    }

    void setPrice(double pr) {
        price = pr;
    }
    double getPrice() {
        return price;
    }

    void setAvailability(bool avail) {
        availability = avail;
    }
    bool getAvailability() {
        return availability;
    }
};

// Derived Class: Apartment
class Apartment : public Property {
private:
    int floorNumber;

public:
    void setFloorNumber(int floor) {
        floorNumber = floor;
    }

    int getFloorNumber() {
        return floorNumber;
    }

    void display() override {
        cout << "Apartment Details: " << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Availability: " << (getAvailability() ? "Available" : "Not Available") << endl;
        cout << "Floor Number: " << floorNumber << endl;
    }
};

// Derived Class: House
class House : public Property {
private:
    int numOfRooms;

public:
    void setNumOfRooms(int rooms) {
        numOfRooms = rooms;
    }

    int getNumOfRooms() {
        return numOfRooms;
    }

    void display() override {
        cout << "House Details: " << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Availability: " << (getAvailability() ? "Available" : "Not Available") << endl;
        cout << "Number of Rooms: " << numOfRooms << endl;
    }
};

// Derived Class: Commercial Property
class CommercialProperty : public Property {
private:
    int officeSpaces;

public:
    void setOfficeSpaces(int spaces) {
        officeSpaces = spaces;
    }

    int getOfficeSpaces() {
        return officeSpaces;
    }

    void display() override {
        cout << "Commercial Property Details: " << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Availability: " << (getAvailability() ? "Available" : "Not Available") << endl;
        cout << "Office Spaces: " << officeSpaces << endl;
    }
};

int main() {
    int propertyType;
    string location;
    double price;
    bool availability;

    // Dynamic input 
    cout << "Enter property type (1 - Apartment, 2 - House, 3 - Commercial Property): ";
    cin >> propertyType;
    cin.ignore(); 

    cout << "Enter location: ";
    getline(cin, location);

    cout << "Enter price: ";
    cin >> price;

    cout << "Enter availability (1 - Available, 0 - Not Available): ";
    cin >> availability;

    Property* property = nullptr;

    if (propertyType == 1) {
        Apartment* apartment = new Apartment();
        apartment->setLocation(location);
        apartment->setPrice(price);
        apartment->setAvailability(availability);

        int floorNumber;
        cout << "Enter floor number: ";
        cin >> floorNumber;
        apartment->setFloorNumber(floorNumber);

        property = apartment;
    } else if (propertyType == 2) {
        House* house = new House();
        house->setLocation(location);
        house->setPrice(price);
        house->setAvailability(availability);

        int numOfRooms;
        cout << "Enter number of rooms: ";
        cin >> numOfRooms;
        house->setNumOfRooms(numOfRooms);

        property = house;
    } else if (propertyType == 3) {
        CommercialProperty* commercial = new CommercialProperty();
        commercial->setLocation(location);
        commercial->setPrice(price);
        commercial->setAvailability(availability);

        int officeSpaces;
        cout << "Enter number of office spaces: ";
        cin >> officeSpaces;
        commercial->setOfficeSpaces(officeSpaces);

        property = commercial;
    } else {
        cout << "Invalid property type!" << endl;
        return 1;
    }

    property->display();


    delete property;

    return 0;
}