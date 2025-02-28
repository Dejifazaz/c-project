#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void question1();
int main() {
    question1();
    }

struct Product {
    string Name;
    string Category;
    double Price;
    int Quantity;
    double Rating;
};
void readfile(const string & filename, vector<Product> &products) {
    ifstream fin(filename);
    if (fin)
    {
        Product product;
        while (!fin.eof) {
            fin >> product.Name >> product.Category >> product.Price >> product.Quantity;
            products.push_back(product);

        }
        fin.close();

    } else{
        cout << "Error opening file " << filename << endl;
        system("exit");

    }
}
void display(const vector<Product> &products) {
    vector<Product>::const_iterator iter;
    for (iter = products.cbegin(); iter != products.cend(); ++iter) {
        cout << "display";

        if (iter != products.cbegin()) {
            cout << "\n";
        }
        cout << iter->Name << ","<< iter->Category << ","<< iter->Price << ","
            << iter->Quantity << ","<<iter->Rating << "\n";
    }

}

void print(vector<Product> &products)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (i != 0) {
            cout << ",";
        }
        cout << products.at(i).Name;
    }
    cout << endl;
}

void question1() {
vector<Product> products;
    string filename = "../product_sales.csv";
    readfile(filename, products);
    print(products);
    cout << "completed";
    }




