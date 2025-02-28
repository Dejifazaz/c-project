#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


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

void display(const vector<Product> &products) {
    cout << "--------------------------------------\n";
    cout << "       Product Details\n";
    cout << "--------------------------------------\n";

    for (const Product &product : products) {
        cout << "Name:       " << product.Name << "\n";
        cout << "Category:   " << product.Category << "\n";
        cout << "Price:      $" << product.Price << "\n";
        cout << "Quantity:   " << product.Quantity << "\n";
        cout << "Rating:     " << product.Rating << " / 5.0\n";
        cout << "--------------------------------------\n";
    }
}



void question1() {
    vector<Product> products;
    string filename = "../products.csv";

    readFile(filename, products);
    display(products);
}

int main() {
    question1();
    return 0;
}
