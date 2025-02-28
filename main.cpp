#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Define a struct to represent a row in the CSV file
struct Product {
    string Name;
    string Category;
    string Price;
    string Quantity;
    string Rating;
};


void readFile(const string &filename, vector<Product> &products) {
    ifstream myFile("../product_sales.csv");
    if (!myFile.is_open()) {
        cout << "File failed to open: " << filename << endl;
        return;
    }

    while (myFile.good()) {
        Product product;
        getline(myFile, product.Name, ',');
        getline(myFile, product.Category, ',');
        getline(myFile, product.Price, ',');
        getline(myFile, product.Quantity, ',');
        getline(myFile, product.Rating, '\n');

        if (!product.Name.empty()) {
            products.push_back(product);
        }
    }
    myFile.close();
}


void displayProducts(const vector<Product> &products) {

    for (const auto &product : products) {
        cout << product.Name << ","
             << product.Category << ","
             << product.Price << ","
             << product.Quantity << ","
             << product.Rating << endl;
    }
}


void question1() {
    vector<Product> products;
    string filename = "../products.csv";

    readFile(filename, products);
    displayProducts(products);
}

int main() {
    question1();
    return 0;
}
