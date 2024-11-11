#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Product {
    int productNo;
    std::string name;
    float price;
    float discount;

public:
    Product() : productNo(0), price(0.0f), discount(0.0f) {}
    Product(int pNo, const std::string& pName, float pPrice, float pDiscount) 
        : productNo(pNo), name(pName), price(pPrice), discount(pDiscount) {}

    void display() const {
        std::cout << std::setw(10) << productNo
                  << std::setw(20) << name
                  << std::setw(10) << price
                  << std::setw(10) << discount << "%\n";
    }

    int getProductNo() const { return productNo; }
    float getPrice() const { return price; }
    float getDiscount() const { return discount; }
    const std::string& getName() const { return name; }
};

#endif // PRODUCT_HPP
