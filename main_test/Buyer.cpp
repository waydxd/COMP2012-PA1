#include "Buyer.h"

// Task 1.1
Buyer::Buyer(int id, const string& name) : buyerID(id), buyerName(name) {}
// Task 1.2
void Buyer::setBuyerId(int newId) { 
    this->buyerID = newId;
}

// Task 1.3
int Buyer::getBuyerId() const {
    return this->buyerID;
}

// Task 1.4
void Buyer::setBuyerName(const string& newName) { 
    this->buyerName = newName;
}

// Task 1.5
string Buyer::getBuyerName() const { 
    return this->buyerName;
}
