#include "Customer.hpp"
#include "Order.hpp"
#include "Cook.hpp"
#include "Cashier.hpp"

#include <iostream>
#include <queue>
#include <stack> 
#include <string>
#include <vector>

using namespace std;

Cashier::Cashier(double money_) {
    uid_count = 0;
    money = money_;
}

double Cashier::get_money() const {
    return money;
}

void Cashier::serve_customer( std::queue<Customer>& line, std::stack<Order>& orders ) {
    
    Customer front = line.front();
    line.pop();

    /* //First Attempt (fail) ... before I found "split" in restaurant-utility...
    string orderString = front.get_order();

    vector<string> orderList;
    vector<string> quantity;

    size_t current = 0;
    size_t space = orderString.find(' ');

    size_t lastSpace = orderString.rfind(' ');

    while(true) { 
        quantity.push_back(orderString.substr(current, space));
        current = space + 1;

        if(space == lastSpace) {
            orderList.push_back(orderString.substr(current));
            break;
        } else {
            space = orderString.find(' ', current);
        }

        orderList.push_back(orderString.substr(current, space));
        current = space + 1;
        space = orderString.find(' ', current);
    }

    for(unsigned i = 0; i < orderList.size(); i++) {
        if( recipes.find(orderList[i]) == recipes.end() ) {
            front.expel();
        }
    }
    */

    vector<string> list = split(front.get_order(), ' ');

    vector<string> orderList;
    vector<string> quantity;

    for(int i = 0; i < list.size(); i++) {
        if( i % 2 == 0 ) {
            quantity.push_back(list[i]);
        } else {
            if( recipes.find(list[i]) == recipes.end() ) {
                front.expel();
            } else {
                orderList.push_back(list[i]);
            }
        }
    }

    vector<string> totalOrders;

    for(int i = 0; i < orderList.size(); i++) {
        for(int j = 0; j < stoi(quantity[i]); j++) {
            totalOrders.push_back(orderList[i]);
        }
    }

    double totalCost = calculate_order_cost(totalOrders);

    if(totalCost > front.get_money()) {
        front.expel();
    } else {
        front.charge_money(totalCost);
        money += totalCost;
    }

    if(!front.is_expelled()) {
        Order orderedItems(uid_count, totalOrders);
        orders.push(orderedItems);
    }
    
    uid_count++;
}