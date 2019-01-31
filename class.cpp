/*
Ramamurthy Sundar
class.cpp

Implementation of classes defined in class.h.  See comments bellow for
function explanations.
*/

#include "class.h"

//Debit function for Account class. Takes withdrawal and file stream as input.
//Updates balance private variable.  Deals with exceptions.
void Account::debit(const double withdrawal, std::ofstream &outfile) {
	//exception handling
	try {
		if ((balance - withdrawal) < 0) {
			throw "account overdrawn";
		}
		else if (withdrawal < 0) {
			throw "please enter possitive dollar amounts";
		}
		else {
			balance -= withdrawal;
		}
	}
	catch (const char *e) {
		std::cout << "\tSorry, there is an error: " << e << std::endl;
		outfile << "\tSorry, there is an error: " << e << "\n";
	}
}

//Credit function for Account class. Takes deposit and file stream as input.
//Updates balance private variable.  Deals with exceptions.
void Account::credit(const double deposit, std::ofstream &outfile) {
	//exception handling
	try {
		if (deposit < 0) {
			throw "please enter possitive dollar amounts";
		}
		else {
			balance += deposit;
		}
	}
	catch (const char *e) {
		std::cout << "\tSorry, there is an error: " << e << std::endl;
		outfile << "\tSorry, there is an error: " << e << "\n";
	}
}

//returns balance private variables
double Account::getBalance() const {
	return balance;
}

//calculates interest gaines by savings account
double SavingsAccount::calculateInterest() const {
	return getBalance()*interest;
}

//overload Account credit function
void SavingsAccount::credit(const double deposit, std::ofstream &outfile) {
	std::cout << "Deposit into Savings Account: " << deposit << std::endl;
	outfile << "Deposit into Savings Account: " << deposit << "\n";
	double added_interest = calculateInterest();
	Account::credit(deposit + added_interest, outfile);
	std::cout << "\t" << "Savings Balance: " << getBalance() << std::endl;
	outfile << "\t" << "Savings Balance: " << getBalance() << "\n";

}

//overload Account debit function
void SavingsAccount::debit(const double withdrawal, std::ofstream &outfile) {
	std::cout << "Withdrawal from Savings Account: " << withdrawal << std::endl;
	outfile << "Withdrawal from Savings Account: " << withdrawal << "\n";
	double added_interest = calculateInterest();
	Account::credit(added_interest, outfile);
	Account::debit(withdrawal, outfile);
	std::cout << "\t" << "Savings Balance: " << getBalance() << std::endl;
	outfile << "\t" << "Savings Balance: " << getBalance() << "\n";
}

//overload Account credit function
void CheckingAccount::credit(const double deposit, std::ofstream &outfile) {
	std::cout << "Deposit into Checking Account: " << deposit << std::endl;
	outfile << "Deposit into Checking Account: " << deposit << "\n";
	double fee = deposit * interest;
	Account::credit(deposit - fee, outfile);
	std::cout << "\t" << "Checking Balance: " << getBalance() << std::endl;
	outfile << "\t" << "Checking Balance: " << getBalance() << "\n";

}

//overload Account debit function
void CheckingAccount::debit(const double withdrawal, std::ofstream &outfile) {
	std::cout << "Withdrawal from Checking Account: " << withdrawal << std::endl;
	outfile << "Withdrawal from Checking Account: " << withdrawal << "\n";
	double fee = withdrawal * interest;
	Account::debit(withdrawal + fee, outfile);
	std::cout << "\t" << "Checking Balance: " << getBalance() << std::endl;
	outfile << "\t" << "Checking Balance: " << getBalance() << "\n";
}
