#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to represent a product
struct Product {
    int pCode;
    string productName;
    float price;
    float discount;
};

class Shopping {
private:
    string databaseFile = "database.txt";

    // Helper function to load all products from the database file
    vector<Product> loadProducts() {
        vector<Product> products;
        ifstream file(databaseFile);
        if (file.is_open()) {
            Product product;
            while (file >> product.pCode >> product.productName >> product.price >> product.discount) {
                products.push_back(product);
            }
            file.close();
        }
        return products;
    }

    // Helper function to save all products to the database file
    void saveProducts(const vector<Product>& products) {
        ofstream file(databaseFile);
        if (file.is_open()) {
            for (const auto& product : products) {
                file << product.pCode << " " << product.productName << " " << fixed << setprecision(2) << product.price << " " << fixed << setprecision(2) << product.discount << "\n";
            }
            file.close();
        } else {
            cout << "Error: Unable to open database file for writing.\n";
        }
    }

    // Helper function to check if a product code already exists
    bool productCodeExists(int code, const vector<Product>& products) {
        for (const auto& product : products) {
            if (product.pCode == code) {
                return true;
            }
        }
        return false;
    }

public:
    void menu();
    void admin();
    void buyer();
    void addProduct();
    void editProduct();
    void removeProduct();
    void listProducts();
    void generateReceipt();
};

void Shopping::menu() {
    int choice;
    string email;
    string password;

m:
    cout << "\t\t\t\t ____________________________\n";
    cout << "\t\t\t\t                   \n";
    cout << "\t\t\t\t            Supermarket Main Menu       \n";
    cout << "\t\t\t\t                   \n";
    cout << "\t\t\t\t ____________________________\n";
    cout << "\t\t\t\t  1) Admin     |\n";
    cout << "\t\t\t\t               |\n";
    cout << "\t\t\t\t  2) Buyer     |\n";
    cout << "\t\t\t\t               |\n";
    cout << "\t\t\t\t  3) Exit      |\n";
    cout << "\t\t\t\t               |\n";
    cout << "\n\t\t\t  Please select! \n";
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "\t\t\t Login \n";
        cout << "\t\t\t Email: ";
        cin >> email;
        cout << "\t\t\t Password: ";
        cin >> password;

        if (email == "test@gmail.com" && password == "test123") {
            admin();
        } else {
            cout << "\t\t\t Invalid email/password\n";
        }
        break;
    }
    case 2: {
        buyer();
        break;
    }
    case 3: {
        cout << "\n\t\t\t Thank you for visiting!\n";
        exit(0);
    }
    default: {
        cout << "\t\t\t Please select from the given options\n";
    }
    }
    goto m;
}

void Shopping::admin() {
m:
    int choice;
    cout << "\n\n\n\t\t\t Admin Menu";
    cout << "\n\t\t\t|____1) Add Product____|";
    cout << "\n\t\t\t                     ";
    cout << "\n\t\t\t|____2) Edit Product____|";
    cout << "\n\t\t\t                     ";
    cout << "\n\t\t\t|____3) Remove Product____|";
    cout << "\n\t\t\t                     ";
    cout << "\n\t\t\t|____4) List Products____|";
    cout << "\n\t\t\t                     ";
    cout << "\n\t\t\t|____5) Back to Main Menu____|";

    cout << "\n\n\t Please enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        addProduct();
        break;
    case 2:
        editProduct();
        break;
    case 3:
        removeProduct();
        break;
    case 4:
        listProducts();
        break;
    case 5:
        menu();
        break;
    default:
        cout << "\t\t\t Invalid choice\n";
    }
    goto m;
}

void Shopping::buyer() {
m:
    int choice;
    cout << "\t\t\t  Buyer \n";
    cout << "\t\t\t________________\n";
    cout << "\t\t\t 1) Buy product \n";
    cout << "\t\t\t________________\n";
    cout << "\t\t\t 2) Go back \n";
    cout << " \t\t\t Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        generateReceipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "\t\t\t Invalid choice\n";
    }
    goto m;
}

void Shopping::addProduct() {
m:
    Product newProduct;
    vector<Product> products = loadProducts();
    bool exists = false;

    cout << "\n\n\t\t\t Add New Product";
    cout << "\n\n\t Product Code: ";
    cin >> newProduct.pCode;

    if (productCodeExists(newProduct.pCode, products)) {
        cout << "\t\t\t Error: Product code already exists!\n";
        goto m;
    }

    cout << "\n\n\t Name of the Product: ";
    cin >> newProduct.productName;
    cout << "\n\n\t Price of the Product: ";
    cin >> newProduct.price;
    cout << "\n\n\t Discount on the Product (%): ";
    cin >> newProduct.discount;

    products.push_back(newProduct);
    saveProducts(products);

    cout << "\n\n\t\t Record inserted successfully!\n";
}

void Shopping::editProduct() {
    int productCodeToEdit;
    vector<Product> products = loadProducts();
    bool found = false;

    cout << "\n\n\t\t\t Modify Product Record";
    cout << "\n\t\t\t Enter Product Code to Modify: ";
    cin >> productCodeToEdit;

    for (auto& product : products) {
        if (product.pCode == productCodeToEdit) {
            cout << "\n\t\t Product New Code (" << product.pCode << "): ";
            int newCode;
            cin >> newCode;
            if (newCode != product.pCode && productCodeExists(newCode, products)) {
                cout << "\t\t\t Error: New product code already exists!\n";
                return;
            }
            product.pCode = newCode;

            cout << "\n\t\t Name of the Product (" << product.productName << "): ";
            cin >> product.productName;
            cout << "\n\t\t Price (" << fixed << setprecision(2) << product.price << "): ";
            cin >> product.price;
            cout << "\n\t\t Discount (%) (" << fixed << setprecision(2) << product.discount << "): ";
            cin >> product.discount;

            cout << "\n\n\t\t Record updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\n\n\t\t Product not found!\n";
    }

    saveProducts(products);
}

void Shopping::removeProduct() {
    int productCodeToRemove;
    vector<Product> products = loadProducts();
    bool found = false;

    cout << "\n\n\t\t\t Remove Product Record";
    cout << "\n\t\t\t Enter Product Code to Remove: ";
    cin >> productCodeToRemove;

    vector<Product> updatedProducts;
    for (const auto& product : products) {
        if (product.pCode != productCodeToRemove) {
            updatedProducts.push_back(product);
        } else {
            found = true;
        }
    }

    if (found) {
        saveProducts(updatedProducts);
        cout << "\n\n\t\t Product removed successfully!\n";
    } else {
        cout << "\n\n\t\t Product not found!\n";
    }
}

void Shopping::listProducts() {
    vector<Product> products = loadProducts();

    cout << "\n\n\t\t\t List of All Products\n";
    cout << "-----------------------------------------------------------\n";
    cout << left << setw(10) << "Code" << left << setw(25) << "Name" << left << setw(10) << "Price" << left << setw(10) << "Discount\n";
    cout << "-----------------------------------------------------------\n";

    if (products.empty()) {
        cout << "\t\t\t No products available.\n";
    } else {
        for (const auto& product : products) {
            cout << left << setw(10) << product.pCode
                 << left << setw(25) << product.productName
                 << left << setw(10) << fixed << setprecision(2) << product.price
                 << left << setw(10) << fixed << setprecision(2) << product.discount << "\n";
        }
    }
    cout << "-----------------------------------------------------------\n";
}

void Shopping::generateReceipt() {
    vector<Product> products = loadProducts();
    vector<Product> cart;
    int productCode;
    int quantity;
    float totalAmount = 0;
    char addMore;

    cout << "\n\n\t\t\t\t Place Order";
    cout << "\n\t\t\t\t _______________\n";
    do {
        cout << "\n\t\t Enter Product Code to Buy: ";
        cin >> productCode;

        bool found = false;
        for (const auto& product : products) {
            if (product.pCode == productCode) {
                cout << "\n\t\t Enter Quantity: ";
                cin >> quantity;
                if (quantity > 0) {
                    Product cartItem = product;
                    cartItem.price = product.price * quantity * (1 - (product.discount / 100.0));
                    cart.push_back(cartItem);
                    totalAmount += cartItem.price;
                    found = true;
                } else {
                    cout << "\t\t\t Invalid quantity.\n";
                }
                break;
            }
        }
        if (!found) {
            cout << "\t\t\t Product not found!\n";
        }

        cout << "\n\t\t Do you want to add more items? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    cout << "\n\n\t\t\t\t ______RECEIPT______\n";
    cout << "-----------------------------------------------------------\n";
    cout << left << setw(10) << "Code" << left << setw(25) << "Name" << left << setw(10) << "Quantity" << left << setw(15) << "Amount\n";
    cout << "-----------------------------------------------------------\n";

    for (const auto& item : cart) {
        cout << left << setw(10) << item.pCode
             << left << setw(25) << item.productName
             << left << setw(10) << static_cast<int>(item.price / (item.price / (1 - (item.discount / 100.0)))) // Rough way to get original quantity
             << left << setw(15) << fixed << setprecision(2) << item.price << "\n";
    }

    cout << "-----------------------------------------------------------\n";
    cout << "\t\t\t\t Total Amount: $" << fixed << setprecision(2) << totalAmount << "\n";
    cout << "-----------------------------------------------------------\n";
    cout << "\t\t\t Thank you for your purchase!\n";
}

int main() {
    Shopping supermarket;
    supermarket.menu();
    return 0;
}