# Banking System Project

## Project Title

**Banking System Using C++ (OOP Concepts)**

## Description

This project is a simple Banking System developed in C++. It demonstrates Object-Oriented Programming concepts like Inheritance, Encapsulation, and Polymorphism. Users can create different types of bank accounts and perform banking operations such as deposit, withdrawal, displaying account details, and calculating interest.

---

# Features

* Create Savings Account
* Create Checking Account
* Create Fixed Deposit Account
* Deposit Money
* Withdraw Money
* Display Account Information
* Calculate Interest
* Menu Driven Program

---

# OOP Concepts Used

* Class & Object
* Inheritance
* Encapsulation
* Polymorphism
* Function Overriding

---

# Classes

## BankAccount

* Account Number
* Holder Name
* Balance
* Deposit()
* Withdraw()
* DisplayAccountInfo()
* CalculateInterest()

## SavingsAccount

* Derived from BankAccount
* Calculates interest using interest rate

## CheckingAccount

* Derived from BankAccount
* Does not provide interest

## FixedDepositAccount

* Derived from BankAccount
* Calculates fixed deposit interest

---

# Technologies Used

* C++
* OOP
* Console Application

---

# How to Run

1. Open `main.cpp` in Code::Blocks / Dev C++ / VS Code.
2. Compile the program.
3. Run the program.
4. Select menu options.

---

# Sample Output

### Menu Screen

```text
===== BANKING SYSTEM =====

1. Savings Account
2. Checking Account
3. Fixed Deposit
4. Deposit
5. Withdraw
6. Display
7. Calculate Interest
8. Exit
```

### Create Savings Account

```text
Enter Choice : 1
Account Number : 101
Holder Name : Rahul
Balance : 10000
Interest Rate : 5

Savings Account Created Successfully!
```

### Deposit

```text
Enter Choice : 4
Deposit Amount : 2000

Deposit Successful!
```

### Display

```text
Account Number : 101
Holder Name : Rahul
Balance : 12000
```

### Interest

```text
Interest = 600
```

### Exit

```text
Thank You!
```

---

# Output Screenshot

**Banking System Output**

```text
===== BANKING SYSTEM =====

1. Savings Account
2. Checking Account
3. Fixed Deposit
4. Deposit
5. Withdraw
6. Display
7. Calculate Interest
8. Exit

Enter Choice : 1
Account Number : 101
Holder Name : Rahul
Balance : 10000
Interest Rate : 5

Savings Account Created Successfully!

Enter Choice : 4
Deposit Amount : 2000

Deposit Successful!

Enter Choice : 6

Account Number : 101
Holder Name : Rahul
Balance : 12000

Enter Choice : 7

Interest = 600

Enter Choice : 8

Thank You!
```
<!-- output (2).png -->
**Screenshot:**
![BankingSystem](assets/output%20(2).png)


---

# Explanation Video

(https://drive.google.com/file/d/1MVi3MnnfFvsXBEskBnRfov7wHUVneEjN/view?usp=sharing)

1. Project Introduction
2. OOP Concepts Used
3. BankAccount Class
4. SavingsAccount Class
5. CheckingAccount Class
6. FixedDepositAccount Class
7. Deposit Function
8. Withdraw Function
9. Display Function
10. Interest Calculation
11. Program Execution
12. Conclusion

---

# Conclusion

This Banking System project successfully demonstrates Object-Oriented Programming concepts using C++. It is a simple menu-driven application that performs basic banking operations such as account creation, deposit, withdrawal, displaying account information, and interest calculation.
