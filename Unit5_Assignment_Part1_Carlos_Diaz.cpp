#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
using namespace std;
/*
Carlos Diaz
REPLIT
This program takes parameters and calculates the pay of several employees
*/

double weeklyPay(double, double, string, int); // function prototype

int main() {

  // a function call for each person - no input from the console for part 1

  cout << fixed << setprecision(2);
  cout << weeklyPay(47, 505.75, "Carlos", 1) << endl;
  cout << weeklyPay(45, 55.25, "Melivin", 1) << endl;
  cout << weeklyPay(15, 65.25, "Susan", 0) << endl;
  cout << weeklyPay(41, 14.75, "Mika", 1) << endl;
  cout << weeklyPay(25, 15.00, "Eldridge", 0) << endl;
  cout << weeklyPay(55, 203.50, "Freedom", 1) << endl;
  cout << weeklyPay(32.5, 100.25, "Tyson", 1) << endl;
  // cout << weeklyPay (, 100.25,"cin",1) << endl; user input working

  // re-type " or ' if necessary

  return 0;
}

double weeklyPay(double hours, double rate, string name,
                 int empType) { // complete the function definition
  double overTimeHours = 0.0;
  string status = "";
  double netPay = 0.0, grossPay = 0.0, grossPay2 = 0.0;
  double fit = 0.0;
  double dental = 0.0;
  double retirement = 0.0;
  double fitDeduction = 0.0;
  double ss = 0.062;
  double med = 0.0145, ssExpense, medExpense;
  locale loc;
  string color = "\x1b[" + to_string(32) + ";4m";  // green and underlined
  string color2 = "\x1b[" + to_string(34) + ";1m"; // blue
  string reset = "\x1b[0m";

  // Name of employee will be given
  cout << color << endl;
  for (int i = 0; i < name.length(); i++) {
    cout << toupper(name[i], loc);
  }
  cout << reset << endl;
  // this line will determine wether the employee is a fulltime or part time
  // employee
  if (empType == 0) {
    status = "Parttime";
  } else if (empType == 1) {
    status = "Fulltime";
  } else {
    status = "Invalid";
  }
  cout << "\t Status: " << status << endl;

  // Now we will get hours vs overtime hours
  if (hours > 40.00) {
    overTimeHours = hours - 40.00;
    hours = 40.00;
  } else {
    overTimeHours = 0;
  }
  cout << "\t Hourly Pay: $" << rate << endl;
  cout << "\t Regular Hours Worked: " << hours << endl;
  cout << "\t Overtime Hours Worked: " << overTimeHours << endl;

  // now we will get the fit rate
  if (rate >= 15.1) {
    fit = 0.15;
  } else {
    fit = 0.12;
  }
  cout << "\t FIT rate: " << fit << endl;

  // now we will get the gross pay
  grossPay = (hours * rate) + (overTimeHours * (rate * 2));
  grossPay2 = grossPay;
  cout << "\t GrossPay: $" << grossPay << endl;

  cout << color2 << endl;
  cout << "Deductions PreTax" << endl;
  cout << reset << endl;
  // we will now determine if we should take out dental and retirement
  if (status == "Parttime") {
    cout << "\t Dental Deduction: $" << dental << endl;
    cout << "\t Retirement Deduction: $" << retirement << endl;
    cout << "\t Taxable Wages For FIT: $" << grossPay << endl;
  } else {
    dental = 17.00;
    cout << "\t Dental Deduction: $" << dental << endl;
    retirement = 77.00;
    cout << "\t Retirement Deduction: $" << retirement << endl;
    grossPay = grossPay - dental - retirement;
    cout << "\t Taxable Wages For FIT: $" << grossPay << endl;
  }

  cout << color2 << endl;
  cout << "Deductions" << endl;
  cout << reset << endl;
  // we will now determine if we should take out fit deduction
  fitDeduction = grossPay * fit;
  cout << "\t FIT tax amount: $" << fitDeduction << endl;

  // now we will get social security and Medical deduction
  ssExpense = grossPay2 * ss;
  cout << "\tSocial Security Deduction: $" << ssExpense << endl;
  medExpense = grossPay2 * med;
  cout << "\tMedical Deduction: $" << medExpense << endl;

  // Now we will get the net pay
  cout << dental << retirement << ss << med << fitDeduction << endl;
  netPay =
      grossPay2 - (dental + retirement + ssExpense + medExpense + fitDeduction);
  cout << "\tNet pay for " << name << " is :$ " << netPay << endl;
  cout << "\n";

  return 0;
}