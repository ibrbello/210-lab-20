// COMSC-210 | Lab 20 | Ibrahim Bello
// This program modifies the original program to 
// introduce more complex constructors.


#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices; // pointer to dynamic array
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        const int MIN_LEGS = 3, MAX_LEGS = 4;
        const int MIN = 10000, MAX = 99999;
        // basically rand() % 2 which produces int from 0 to 1, and then add 3
        legs = (rand() % (MAX_LEGS-MIN_LEGS+1) + MIN_LEGS); 
        for (int i = 0; i < SIZE; i++) {
            double price = (rand() % (MAX-MIN+1) + MIN) / 100.0;
            prices[i] = price; // creates array then populates with 0's
        }
    }
    Chair(int l, double * p) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
            prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    cout << "Using getters & setters to create chair object...";
    cout << endl << endl;
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    // creating chair object using parameter constructor
    cout << "Using parameter constructor to create chair object...";
    cout << endl << endl;
    double tempPrices[SIZE] = {100.0,34.5,334.7};
    Chair *livingChair = new Chair(6, tempPrices);
    livingChair->print();

    //creating dynamic array of chair objects
    cout << "Using default constructor to create chair objects...";
    cout << endl << endl;
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i] = Chair();
        collection[i].print();
    }

    
    return 0;
}