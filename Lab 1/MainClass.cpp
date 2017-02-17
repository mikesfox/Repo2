#include "MainClass.h"
#include <iostream>
#include <string>

using namespace std;



MainClass::MainClass()
{
}


MainClass::~MainClass()
{
}

//forward declarations for functions
float computeTax(float sal, float taxRate);
float computeAnnualNet(float salary, float taxRate);

int main()
{
	const float taxRate = 0.2;					//assume 20% tax
	
	float salary;
	while (true)
	{
		cout << "Enter Annual gross salary, 0 to exit: ";
		cin >> salary;							//needs check for numeric
		if (salary == 0)
		{
			break;								//done with calculations
		}
		cout << "Annual Salary = $" << salary << endl;
		printf("Tax = $%.2f\n", computeTax(salary, taxRate));
		float netSalary = computeAnnualNet(salary, taxRate);
		float monthly = netSalary / 12;
		monthly = roundf(monthly * 100) / 100;	//multiply / divide by 100 to effect rounding
		printf("Net Salary = $%.2f\n", netSalary);
		printf("Monthly = $%.2f", monthly);
		cout << endl << endl;

		//alternatively output this way, but you don't always get 2 decimal places
		//cout << "Tax = $" << tax << endl;
		//cout << "Net Salary = $" << netSal << "   Monthly = $" << monthly << endl << endl;
		//
	}
}

float computeTax(float sal, float taxRate)
{
	float tax = roundf(sal * 100 * taxRate) / 100;	//multiply / divide by 100 to effect rounding
	return tax;
}

float computeAnnualNet(float salary, float taxRate)
{
	float netSal = salary - computeTax(salary, taxRate);
	return netSal;
}