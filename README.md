#  🛒Online Shopping System

This is a simple Online Shopping System built using C++, simulating the basic functionalities of an e-commerce platform for both owners and customers. It includes user registration, login, inventory management, and bill generation.

## 📌 Features
👤 User Roles
Owner:

Add new items to the store.

Update available stock quantities.

Customer:

Register and login with a secure system.

View available items.

Add items to cart and generate a final bill.

## 📂 File Handling
Data persistence is achieved using file I/O.

users.dat: Stores registered user credentials.

bill1.txt: Maintains item inventory and stock levels.

## 💾 Sample Functionalities
Add items with name, rate, and quantity.

Purchase items (only if stock is available).

Generates a detailed bill with total amount.

Updates inventory after each purchase.

## 🛠️ How It Works
On launch, the user chooses their role: Owner or Customer.

Owners can:

Add new items.

View the current inventory.

Customers can:

Register or login.

Browse and purchase available items.

Get a printed bill.

All changes are stored persistently in .txt files.

## 💡 Technologies Used
C++ (Object-Oriented Programming)

File Streams (fstream)

Windows.h for delays (Sleep)

Vectors and Classes for structured data management

## 🔐 Classes Overview
User: Handles user data and authentication.

Bill: Manages item information (name, rate, quantity).

ShoppingSystem: Manages user-related operations.

main(): Menu-driven interface for user interaction.

## 📁 Files Created
users.dat: Holds user login details.

bill1.txt: Inventory and item data.

temp1.txt: Temporary file used during billing and updating stock.

## 🚀 How to Run
Compile the code using any C++ compiler (e.g., g++).

Run the executable:

bash
Copy
Edit
g++ shopping_system.cpp -o shopping_system
./shopping_system

💡 Note: This code uses windows.h for system-specific operations. It may require modification to run on Linux/Mac (e.g., replacing system("cls") and Sleep() with platform-specific equivalents).


## 📌 To Do / Improvements
Add item deletion or update functionality.

Encrypt stored passwords.

GUI-based version using C++ frameworks or web-based frontend.

## 🧑‍💻 Author
Jyotismrita Basisthya
Priti Goala


