#include <iostream>
#include <stdexcept>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include "Date.hpp"
#include <vector>

using namespace std;

void testdate(){
	//
	cout << "Checking DateFormat Constructors.........................................................................................\n";
	cout << "\nDateFormat(char* date,char* month,char* year)\n";
	try{
		char s1[] = "ddd";	char s2[] = "mm";	char s3[] = "yy";
		cout << "date : " << s1 << "\tmonth : " << s2 << "\tyear : " << s3 << endl; 
		DateFormat df(s1,s2,s3);
	}catch(invalid_argument ia){
		cout << "invalid_argument Exception" << endl;
	}
	try{
		char s1[] = "dd";	char s2[] = "qwe";	char s3[] = "yy";
		cout << "date : " << s1 << "\tmonth : " << s2 << "year : " << s3 << endl; 
		DateFormat df(s1,s2,s3);
	}catch(invalid_argument ia){
		cout << "invalid_argument Exception" << endl;
	}
	try{
		char s1[] = "dd";	char s2[] = "mm";	char s3[] = "qwe";
		cout << "date : " << s1 << "\tmonth : " << s2 << "\tyear : " << s3 << endl; 
		DateFormat df(s1,s2,s3);
	}catch(invalid_argument ia){
		cout << "invalid_argument Exception" << endl;
	}
	try{
		char s1[] = "ddd";	char s2[] = "mm";	char s3[] = "yy";
		cout << "DateFormat : " << s1 << "-" << s2 << "-" << s3 << endl; 
		DateFormat df(s1,s2,s3);
		cout << "DateFormat created, DateFormat";
	}catch(invalid_argument ia){
		cout << "invalid_argument Exception" << endl;
	}
  
	cout << "\nDateFormat(char* str)\n";
	try{
		char s1[] = "ddd,mm,yy";
		cout << "String : " << s1 << endl;
		DateFormat df(s1);
	}catch(invalid_argument ia){
		cout << "invalid_argument Exception\n";
	}
	try{
		char s2[] = "dd,pa,yy";
		cout << "String : " << s2 << endl;
		DateFormat df(s2);
	}catch(invalid_argument ia){
		cout << "invalid_argument Exception\n";
	}
	try{
		char s3[] = "dd,mm,asdf";
		cout << "String : " << s3 << endl;
		DateFormat df(s3);
	}catch(invalid_argument ia){
		cout << "invalid_argument Exception\n";
	}
	// Checking Date Constructors
	Date date;

	cout << "\nChecking Date Constructors.............................................................................................\n";	
	try{
		date;
		cout << "Default Constructor, Date: " << date << endl;
	}catch(out_of_range re){
		cout << "out_of_range Exception" << endl;
	}

	cout << "\nConstructor with Enum Argument\n";


	Day da[4] = {static_cast<Day>(0),static_cast<Day>(32),static_cast<Day>(30),static_cast<Day>(29)};	
	Month m[3] = {static_cast<Month>(0),static_cast<Month>(23),static_cast<Month>(2)};	
	Year y[4] = {157,2015,3000,2016};

	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 3;j++)
			for(int k = 0;k < 4;k++)
				try{
					cout << da[i] << "-" << m[j] << '-' << y[k] << "\t";
					Date dat(static_cast<Day>(da[i]),static_cast<Month>(m[j]),y[k]);					
					cout << " Date Constructed, Date : " << dat << endl;
				}catch(domain_error de){
					cout << "domain_error Exception" << endl;
				}
				catch(out_of_range re){
					cout << "out_of_range Exception" << endl;	
				}catch(invalid_argument ae){
					cout << "invalid_argument Excepton" << endl;
				}

	cout << "\nChecking istream\n";	
	try{
		cout << "Enter Date : ";
		cin >> date;
		cout << " Date created using istream : " << date << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}


	char s1[] = "pp-2-2015",s2[] = "-2-2015",s3[] = "31-2-2015",s4[] = "30-2-2000",s5[] = "12--2015",s6[] = "12-pp-2018",s7[] = "12-19-2014",s8[] = "12-5-2060",s9[] = "12-7-1900",s10[] = "14-2-2016";
	cout << "\nChecking Constructor with String Argument\n";

	try{
		cout << s1 << "\t";
		Date temp(s1);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s2 << "\t";
		Date temp(s2);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s3 << "\t";
		Date temp(s3);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s4 << "\t";
		Date temp(s4);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s5 << "\t";
		Date temp(s5);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s6 << "\t";
		Date temp(s6);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s7 << "\t";
		Date temp(s7);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s8 << "\t";
		Date temp(s8);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s9 << "\t";
		Date temp(s9);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}

	try{
		cout << s10 << "\t";
		Date temp(s10);
		cout << "Date Constructed, Date : " << temp << endl;
	}catch(domain_error de){
		cout << "domain_error Exception" << endl;
	}
	catch(out_of_range re){
		cout << "out_of_range Exception" << endl;	
	}catch(invalid_argument ae){
		cout << "invalid_argument Excepton" << endl;
	}	
	
	Date d1("27-1-2016");
	Date d2("29-2-2016");
	cout << "\nChecking Copy Constructor...............................................................................................\n" 
	<< "Source Date : " << d1 << endl;
	Date d(d1);
	Date d0;
	cout << "Date after copying : " << d << endl;

	cout << "\nChecking Operator=()....................................................................................................\n"
	 << "Source Date : " << d2 << endl;
	d0 = d2;
	cout << "Date after Operator=() " << d0 << endl; 
	
	//   Checking Cast Operators
	cout << "\nChecking Cast Operators................................................................................................\n";
	cout << d1 << ", WeekDay : " << WeekDay(d1) << endl;
	cout << d1 << ", Month : " << Month(d1) << endl;
	cout << d1 << ", WeekNumber : " << WeekNumber(d1) << endl;

	Date dl(D05,Feb,2015);

	//Checking LEAPYEAR()
	cout << "\nChecking leapYear()....................................................................................................\n";
	if(dl.leapYear())cout << "Yes\t" << dl << endl;
	else  cout << "No\t" << dl << endl;

	if(d1.leapYear())cout << "Yes\t" << d1 << endl;
	else  cout << "No\t" << d1 << endl;

	//Checking Format Functions
	cout << "\nChecking Format Fuctions...............................................................................................\n";
	cout << "Initial DateFormat : "<< d1.getFormat().getDate() << "-" << d1.getFormat().getMonth() << "-" << d1.getFormat().getYear() << endl;
	DateFormat df("dd-0-yyyy");
	d1.setFormat(df);
	cout << "Changed DateFormat : " << d1.getFormat().getDate() << "-" << d1.getFormat().getMonth() << "-" << d1.getFormat().getYear() << endl;

	//Binary Relational Operators
	cout << "\nChecking Binary Relational Operators...................................................................................\n";
	cout << "Checking Operator==()\n";
	if(d1 == d)cout << "Yes\t" << d1 << " == " << d << endl;
	else cout << "No\t" << d1 << " != " << d << endl;

	if(d1 == d2)cout << "Yes\t" << d1 << " == " << d2 << endl;
	else cout << "No\t" << d1 << " != " << d2 << endl;

	cout << "\nChecking Operator!=()\n";
	if(d1 != d)cout << "Yes\t" << d1 << " != " << d << endl;
	else cout << "No\t" << d1 << " == " << d << endl;

	if(d1 != d2)cout << "Yes\t" << d1 << " != " << d2 << endl;
	else cout << "No\t" << d1 << " == " << d2 << endl;

	cout << "\nChecking Operator<()\n";
	if(d1 < d)cout << "Yes\t" << d1 << " < " << d << endl;
	else cout << "No\t" << d1 << " >= " << d << endl;

	if(d1 < d2)cout << "Yes\t" << d1 << " < " << d2 << endl;
	else cout << "No\t" << d1 << " >= " << d2 << endl;

	cout << "\nChecking Operator<=()\n";
	if(d1 <= d)cout << "Yes\t" << d1 << " <= " << d << endl;
	else cout << "No\t" << d1 << " > " << d << endl;

	if(d2 <= d1)cout << "Yes\t" << d2 << " <= " << d1 << endl;
	else cout << "No\t" << d2 << " > " << d1 << endl;	

	cout << "\nChecking Operator>()\n";
	if(d1 > d)cout << "Yes\t" << d1 << " > " << d << endl;
	else cout << "No\t" << d1 << " <= " << d << endl;

	if(d2 > d1)cout << "Yes\t" << d2 << " > " << d1 << endl;
	else cout << "No\t" << d2 << " <= " << d1 << endl;	

	cout << "\nChecking Operator>=()\n";
	if(d1 >= d)cout << "Yes\t" << d1 << " >= " << d << endl;
	else cout << "No\t" << d1 << " < " << d << endl;

	if(d1 >= d2)cout << "Yes\t" << d1 << " >= " << d2 << endl;
	else cout << "No\t" << d1 << " < " << d2 << endl;

	//Checking Unary Arithmetic Operators
	cout << "\nChecking Unary Arithmetic Operators....................................................................................\n";
	cout << "Checking Operator++()\n" << "Initial Date : " << d2 << endl;
	++d2;
	cout << "Final Date : " << d2 << endl;

	cout << "\nChecking Operator--()\n" << "Initial Date : " << d2 << endl;
	--d2;
	cout << "Final Date : " << d2 << endl;	

	cout << "\nChecking Operator++(int)\n" << "Initial Date : " << d1 << endl;
	d1++;
	cout << "Final Date : " << d1 << endl;

	cout << "\nChecking Operator--(int)\n" << "Initial Date : " << d1 << endl;
	d1--;
	cout << "Final Date : " << d1 << endl;

	//Checking Binary Arithmetic Operators
	int f = 3;
	cout << "\nChecking Binary Arithmetic Operators....................................................................................\n"
	 << "Checking Operator-()\n";
	cout << "Operator-()" << endl;
	cout << (d2 - d1) << " = " << d2 << " - " << d1 << endl;
	
	cout << "Operator+()\n";
	Date dtemp = d2;
	cout << (d2 + f) << " = " << dtemp << " + " << f << endl;

	Date dt("30-12-2049");
	f = 100;
	
	try{
		dtemp =  dt;
		dt = dt + f;
		cout << dt << " = " << dtemp << " + " << f << endl;
	}catch(out_of_range re){
		cout << "out_of_range Exception\n" << dtemp << " + " << f << endl;
	}
}

int main(){

	testdate();

	return 0;
}