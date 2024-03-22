#include "OrderList.h"
#include <iostream>
#include <algorithm> // For copy
#include <new>       // For bad_alloc

// Task 5.1
OrderList::OrderList() : head(nullptr) {}

// Task 5.2
OrderList::~OrderList() {
    if(head){
        while(head->next!=nullptr){
            OrderNode* tp = head->next->next;
            delete head->next;
            head->next = tp;
        }
    }
    delete head;
}

// Task 5.3
void OrderList::addOrder(const Order& order) {
    OrderNode *ptr = head;
    if(!ptr){
        head=new OrderNode(order);
        return;
    }
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = new OrderNode(order);
}

// Task 5.4
bool OrderList::removeOrder(int orderId) {
    OrderNode *ptr = head;
    if(!ptr){return false;}
    if(ptr->order.getOrderId()==orderId){
        head = ptr->next;
        delete ptr;
        return true;
    }
    while(ptr->next){
        if(orderId==ptr->next->order.getOrderId()){
            OrderNode *temp = ptr->next->next;
            delete ptr->next;
            ptr->next = temp;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Task 5.5
Order* OrderList::findOrder(int orderId) const {
    OrderNode *ptr = head;
    if(!ptr){return nullptr;}
    while(ptr){
        if(orderId==ptr->order.getOrderId()){
            return (&ptr->order);
        }
        ptr = ptr->next;
    }
    return nullptr;
}

// Task 5.6
bool OrderList::isEmpty() const {
  return head == nullptr;
}

// Task 5.7
void OrderList::displayOrderList() const {
// ---------------------- provided code: DO NOT MODIFY --------------------------
    cout << "Order List:" << endl;
    if (head == nullptr) {
        cout << "The order list is empty." << endl;
        return;
    }

// ------------Write your code here to complete this task-----------------
    OrderNode *ptr = head;
    while(ptr){
        ptr->order.displayOrder();
        ptr = ptr->next;
    }}

// Task 5.8
void OrderList::displayOrdersForBuyer(int buyerId) const {

// ------------Write your code here to complete this task-----------------
    bool found = 0;
    OrderNode *ptr = head;
    while(ptr){
        if(ptr->buyer.getBuyerId()==buyerId){
            ptr->order.displayOrder();
            return;
        }
        ptr=ptr->next;
    }
// ---------------------- provided code: DO NOT MODIFY --------------------------
    if (!found) {
        cout << "No orders found for Buyer ID: " << buyerId << endl;
    }
}


