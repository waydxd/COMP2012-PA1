#include "Order.h"
#include <iostream>

// Task 4.1
Order::Order(): orderId(0), currentNum(0) {}

// Task 4.2
const Buyer& Order::getBuyer() const {
  return this->buyer;
}

// Task 4.3
int Order::getcurrentNum() const {
  return currentNum;
}

// Task 4.4
void Order::setOrderId(int newId){
  this->orderId = newId;
}

// Task 4.5
int Order::getOrderId() const {
  return orderId;
}

// Task 4.6
void Order::setBuyer(int newBuyerId, string newBuyerName){
  this->buyer.setBuyerId(newBuyerId);
  this->buyer.setBuyerName(newBuyerName);
}

// Task 4.7
bool Order::addItem(const Food& item) {
  if(currentNum<10){
    orderedItems[currentNum++]=item;
    return true;
  }
// ---------------------- provided code: DO NOT MODIFY --------------------------
  else{
    cout << "Order is full, cannot add more items.\n";
    return false; 
  }
}

// Task 4.8
void Order::cloneOrder(const Order& other) {
  copy(other.orderedItems,other.orderedItems+10,this->orderedItems);
  this->currentNum=other.currentNum;
}

// ---------------------- provided functions: DO NOT MODIFY --------------------------

void Order::displayOrder() const {
  double total = 0.0;

  cout << "Order Details:" << endl;
  cout << "Order ID: " << getOrderId() << ", ";

  // Access buyer details from the Buyer object
  const Buyer& buyer = getBuyer();
  cout << "Buyer ID: " << buyer.getBuyerId() << ", Name: " << buyer.getBuyerName() << endl;

  cout << "Items Ordered:" << endl;

  for (int i = 0; i < currentNum; ++i) {
    cout << "  - Item ID: " << orderedItems[i].getFoodId() << ", Name: "
              << orderedItems[i].getFoodName() << ", Price: $"
              << orderedItems[i].getPrice() << endl;
    total += orderedItems[i].getPrice();  // Calculate total price as each item is displayed
  }

  cout << "Total Bill: $" << total <<endl <<endl;
}


