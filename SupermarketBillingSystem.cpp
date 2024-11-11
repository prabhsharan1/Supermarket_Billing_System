#include "SupermarketBillingSystem.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

void SupermarketBillingSystem::loadProducts() {
    std::ifstream inFile(fileName, std::ios::binary);
    if (!inFile) return;

    Product product;
    while (inFile.read(reinterpret_cast<char*>(&product), sizeof(Product))) {
        productList.push_back(std::make_shared<Product>(product));
    }
}

void SupermarketBillingSystem::saveProducts() const {
    std::ofstream outFile(fileName, std::ios::binary);
    if (!outFile) {
        throw std::runtime_error("Error saving products.");
    }

    for (const auto& product : productList) {
        outFile.write(reinterpret_cast<const char*>(&(*product)), sizeof(Product));
    }
}

void SupermarketBillingSystem::addProduct(const Product& product) {
    productList.push_back(std::make_shared<Product>(product));
    std::cout << "Product added successfully.\n";
}

void SupermarketBillingSystem::displayAllProducts() const {
    std::cout << "\nProduct List:\n";
    for (const auto& product : productList) {
        product->display();
    }
}

std::shared_ptr<Product> SupermarketBillingSystem::findProduct(int productNo) const {
    auto it = std::find_if(productList.begin(), productList.end(),
                           [productNo](const std::shared_ptr<Product>& p) {
                               return p->getProductNo() == productNo;
                           });
    return (it != productList.end()) ? *it : nullptr;
}

void SupermarketBillingSystem::modifyProduct(int productNo, const Product& newProduct) {
    auto product = findProduct(productNo);
    if (product) {
        *product = newProduct;
        std::cout << "Product updated successfully.\n";
    } else {
        std::cout << "Product not found.\n";
    }
}

void SupermarketBillingSystem::deleteProduct(int productNo) {
    productList.erase(
        std::remove_if(productList.begin(), productList.end(),
                       [productNo](const std::shared_ptr<Product>& p) {
                           return p->getProductNo() == productNo;
                       }),
        productList.end()
    );
    std::cout << "Product deleted successfully.\n";
}

void SupermarketBillingSystem::generateBill() {
    int productNo, quantity;
    float totalAmount = 0.0;

    while (true) {
        std::cout << "Enter Product No. (-1 to stop): ";
        std::cin >> productNo;
        if (productNo == -1) break;

        std::cout << "Enter Quantity: ";
        std::cin >> quantity;

        auto product = findProduct(productNo);
        if (product) {
            float amount = product->getPrice() * quantity;
            float discountedAmount = amount * (1 - product->getDiscount() / 100);
            std::cout << "Item: " << product->getName() << ", Total after discount: $" << discountedAmount << "\n";
            totalAmount += discountedAmount;
        } else {
            std::cout << "Product not found.\n";
        }
    }
    std::cout << "Total bill: $" << totalAmount << "\n";
}
