# ATM Machine Simulation (Java)

## Overview

The **ATM Machine Simulation** is a console-based Java application that simulates the basic operations of an Automated Teller Machine (ATM).
It allows users to perform essential banking operations such as **cash withdrawal, cash deposit, balance inquiry, and PIN reset**.

The project demonstrates the use of **Java**, **Object-Oriented Programming (OOP)** concepts, and **Linked List** data structures for dynamic user management.

---

## Features

* New user account creation with initial balance
* Existing user authentication using a 4-digit PIN
* Cash withdrawal with balance validation
* Cash deposit functionality
* PIN reset option
* Balance inquiry
* Menu-driven console interface
* Dynamic account storage using Linked List

---

## How the Application Works

### User Verification

* User enters their **card number**
* System checks whether the user is:

  * **New User**
  * **Existing User**

### New User Flow

* User chooses to activate the card
* Sets a **4-digit PIN**
* Account is created with an initial balance of **₹10,000**
* User details are stored dynamically using a Linked List

### Existing User Menu

* Cash Withdrawal
* PIN Reset
* Check Balance
* Cash Deposit

---

## ATM Operations

### Cash Withdrawal

* User enters withdrawal amount
* PIN verification (maximum 2 attempts)
* Amount is deducted if sufficient balance is available
* Session terminates after failed authentication

### Cash Deposit

* User enters deposit amount
* PIN verification required
* Amount is added to the existing balance

### Balance Inquiry

* PIN verification required
* Displays current account balance

### PIN Reset

* User enters current PIN (one attempt)
* Sets a new valid 4-digit PIN

---

## Technologies Used

* Java
* Object-Oriented Programming (OOP)
* Linked List Data Structure
* Console-based Input/Output

---

## Project Structure

* `ATM_Machine.java` – Main source file containing all logic
* Linked List used to manage user accounts dynamically

---

## How to Run the Project

### Prerequisites

* Java Development Kit (JDK 8 or above)
* Any Java-supported IDE or terminal

### Steps

```bash
javac ATM_Machine.java
java ATM_Machine
```

Follow the on-screen instructions to perform ATM operations.

---

## Limitations

* PINs are stored in plain text
* No transaction history
* No fund transfer feature
* Fixed initial balance
* Limited input validation

---

## Future Enhancements

* Encrypt or hash PINs
* Add transaction history
* Implement fund transfer between accounts
* Add account lock mechanism
* Build a GUI using JavaFX or Swing

---

## Conclusion

This project provides a foundational understanding of how ATM systems work using **Java and core data structures**.
It is suitable for **academic projects**, **Java practice**, and **OOP demonstrations**.
