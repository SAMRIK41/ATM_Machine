# ATM Machine Fuctionality Using C Language

## **About the Project**

This project is a simple **ATM Machine Simulation** developed in **C language**. It mimics the basic functionalities of an ATM machine, allowing users to perform various banking operations like cash withdrawal, PIN reset, balance inquiry, and cash deposit. The program uses a **linked list** to manage customer profiles dynamically and includes basic password-based authentication for security.

---

## **How the Project Works**

1. **Welcome Screen**:
   - The program starts with a welcome message and requests and the user to insert their **card number**.

2. **Card Verification**:
   - The program checks whether the card user is a **new user** or an **existing user**:
     - **New User**:
       - The program asks if the user wants to activate their card.
       - If the user agrees, they are prompted to set a **4-digit password** (validated during input).
       - The new user is then added to the system with an initial account balance of **₹10,000**.
     - **Existing User**:
       - The program provides the following menu of operations:
         1. **Cash Withdrawal**
         2. **PIN Reset**
         3. **Check Balance**
         4. **Cash Deposit**

---

## **ATM Functionalities**

### 1. **Cash Withdrawal**:
   - The user is prompted to:
     - Enter the amount they wish to withdraw.
     - Enter their password for verification.
   - **Password Validation**:
     - The user gets **two attempts** to enter the correct password.
     - If the correct password is entered, the requested amount is deducted from the balance.
     - If the password is incorrect after two attempts, the program terminates with a message to remove the card.
   - **Sufficient Balance Check**:
     - Withdrawal is only allowed if the account has sufficient balance.

---

### 2. **PIN Reset**:
   - The user is prompted to:
     - Enter their **current password** (one attempt only).
     - Enter a **new 4-digit password**.
   - If the current password is correct, the password is updated successfully.

---

### 3. **Check Balance**:
   - The user is prompted to:
     - Enter their password for verification.
   - If the password is correct (within two attempts), the account balance is displayed.

---

### 4. **Cash Deposit**:
   - The user is prompted to:
     - Enter the amount they wish to deposit.
     - Enter their password for verification.
   - If the password is correct (within two attempts), the deposit is added to the account balance.

---

## **Core Features**

- **New User Account Creation**:
  - Automatically assigns an initial balance of **₹10,000**.
  - Ensures only **4-digit passwords** are accepted for security.

- **Password Security**:
  - Password verification is required for all operations.
  - Users are allowed **two attempts** to enter the correct password before their session is terminated.

- **Dynamic Customer Management**:
  - The program uses a **linked list** to dynamically manage customer profiles (card number, password, balance).

- **Interactive Menu**:
  - Offers a clear and intuitive menu for existing users to select their desired operation.

---

## **How to Run the Program**

1. **Requirements**:
   - A C compiler (e.g., GCC).
   - Basic knowledge of compiling and running C programs.

2. **Steps to Compile and Run**:
   - Save the program as `atm_machine.c`.
   - Open a terminal or IDE and navigate to the directory containing the file.
   - Compile the program using:
     ```bash
     gcc atm_machine.c -o atm_machine
     ```
   - Run the program using:
     ```bash
     ./atm_machine
     ```

3. Follow the on-screen instructions to simulate ATM operations.

---

## **Limitations**

1. **Basic Security**:
   - Passwords are stored in plaintext, which is not secure for real-world applications.

2. **Limited Features**:
   - Advanced banking features like transaction history, account locking, or fund transfers are not implemented.

3. **Hardcoded Initial Balance**:
   - Every new user starts with a fixed balance of **₹10,000**.

4. **Error Handling**:
   - Invalid card numbers or edge cases (e.g., very large deposits) are not thoroughly handled.

---

## **Potential Enhancements**

1. Implement **encryption** for password storage.
2. Add features like **transaction history** and **fund transfers**.
3. Include **account locking mechanisms** for repeated incorrect password attempts.
4. Develop a **graphical user interface (GUI)** for improved user experience.

---

## **Conclusion**

This project demonstrates the basic workings of an ATM machine using simple C programming concepts. It is a foundational implementation that highlights the use of **linked lists**, **authentication**, and **modular programming** in real-life applications. 

Feel free to extend and modify the project to add more features and improve its security and functionality! 🎉
