#ifndef SUPERMARKET_BILLING_SYSTEM_HPP
#define SUPERMARKET_BILLING_SYSTEM_HPP

#include "Product.hpp"
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>

class SupermarketBillingSystem {
    std::vector<std::shared_ptr<Product>> productList;
    std::string fileName;

    void loadProducts();
    void saveProducts() const;

public:
    SupermarketBillingSystem(const std::string& file) : fileName(file) {
        loadProducts();
    }
    
    ~SupermarketBillingSystem() {
        saveProducts();
    }

    void addProduct(const Product& product);
    void displayAllProducts() const;
    std::shared_ptr<Product> findProduct(int productNo) const;
    void modifyProduct(int productNo, const Product& newProduct);
    void deleteProduct(int productNo);
    void generateBill();
    void displayMenu() const;
    void handleUserChoice(int choice);
};

#endif // SUPERMARKET_BILLING_SYSTEM_HPP
