/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 271 - Machine Problem 2
Fall 2018

main.cpp

This is the driver for Machine Problem 2.  It simply performs various credit and debit
operations on a Savings and Checking account.  Exception handling is performed in the
class definition itself.

All operations and errors are printed to an output file.
*/

#include "class.h"

int main() {

	//initialize file stream
	std::ofstream outfile;
	outfile.open("Output.txt");

	//initialize accounts
	SavingsAccount s1(500);
	CheckingAccount c1(1000);
	std::cout << "Checking Account Starting Balance: " << c1.getBalance() << std::endl;
	std::cout << "Savings Account Starting Balance: " << s1.getBalance() << std::endl;
	outfile << "Checking Account Starting Balance: " << c1.getBalance() << "\n";
	outfile << "Savings Account Starting Balance: " << s1.getBalance() << "\n";

	//Run a test of various transactions
	c1.debit(230, outfile);
	s1.debit(100.85, outfile);
	c1.credit(400.25, outfile);
	c1.credit(250, outfile);
	s1.credit(500, outfile);
	//errors begin to occur after these examples
	s1.debit(2000, outfile);
	s1.debit(1000, outfile);
	s1.debit(-500, outfile);

	//close file stream and end program
	outfile.close();
	return 0;


}







