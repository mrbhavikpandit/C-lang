# 🛒 ABC Super Market Billing System

A simple **console-based billing system written in C** that simulates a supermarket checkout system.
The program allows users to select products, generate bills, calculate tax and discounts, and save the receipt to a file.

---

## 🚀 Features

* Display available products
* Add new products
* Generate customer bill
* Automatic **5% tax calculation**
* **10% discount** for bills above ₹1000
* Shows **date and time** on the receipt
* Saves bill automatically to **bill.txt**

---

## 🧑‍💻 Technologies Used

* **Language:** C
* **Libraries:**

  * `stdio.h`
  * `stdlib.h`
  * `string.h`
  * `time.h`

---

## 📋 Program Menu

```
========== ABC SUPER MARKET ==========
1. New Billing
2. Add New Product
3. Exit
```

---

## 🧾 Sample Bill Output

```
================= BILL RECEIPT =================
Date & Time: Tue Mar 11 12:30:21 2026

Item                     Qty       Price      Total
------------------------------------------------
Rice (1kg)               2         60.00      120.00
Milk (1L)                3         25.00      75.00
------------------------------------------------
Subtotal: ₹195.00
Tax (5%): ₹9.75
Discount: ₹0.00
Grand Total: ₹204.75
================================================
```

---

## ⚙️ How to Run

### Compile

```
gcc supermarket.c -o supermarket
```

### Run

```
./supermarket
```

---

## 📂 Output File

The generated bill is saved as:

```
bill.txt
```

---

## 📚 Learning Concepts

This project demonstrates:

* Structures in C
* Arrays
* Functions
* File handling
* Menu-driven programs
* Basic billing logic

---

## 🔮 Future Improvements

* Product search feature
* Remove item from cart
* Multiple bill storage
* Database integration
* GUI version

---

## 👨‍💻 Author

**Bhavik Pandit**
B.Tech Computer Science (AI & ML)

---

⭐ If you like this project, consider giving it a **star on GitHub**!
