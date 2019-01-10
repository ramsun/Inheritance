/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 271 - Machine Problem 2
Fall 2018

class.h

This is the definition of a bank account inherritence heirarchy.

This file includes the definition of the Account base class and the derived
classes SavingsAccount and CheckingAccount.

The Account base class has a few function definitions that are overrided by the
derived classes.  This is because these unique accounts have an interest rate that
will either add or subtract some kind of amount every transaction.

The SavingsAccount derived class accumulates interest at a rate of 0.0001 percent every
transaction.  The CheckingAccount derived class will subtract a 0.02 percent fee from the balance
every transaction.

All credit and debit operations stream their output to a text file.
*/

#pragma once
#include <iostream>
#include <exception>
#include <fstream>

//Account base class
class Account {
private:
	double balance;

public:
	Account(double bal = 0) : balance(bal) {}
	void debit(const double withdrawal, std::ofstream &outfile);
	void credit(const double deposit, std::ofstream &outfile);
	double getBalance() const;
};

//SavingsAccount derived class
class SavingsAccount : public Account {
private:
	const double interest = 0.0001;

public:
	SavingsAccount(double bal = 0) : Account(bal) {}
	double calculateInterest() const;
	void credit(const double deposit, std::ofstream &outfile);
	void debit(const double withdrawal, std::ofstream &outfile);
};

//ChackingAccount derived class
class CheckingAccount : public Account {
private:
	const double interest = 0.02;

public:
	CheckingAccount(double bal = 0) : Account(bal) {}
	void credit(const double deposit, std::ofstream &outfile);
	void debit(const double withdrawal, std::ofstream &outfile);
};