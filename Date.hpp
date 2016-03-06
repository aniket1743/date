#include <iostream>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <string.h>
#include <string>

using namespace std;

enum Day {
	D01 = 1, D02 = 2, D03 = 3, D04 = 4, D05 = 5,
	D06 = 6, D07 = 7, D08 = 8, D09 = 9, D10 = 10,
	D11 = 11, D12 = 12, D13 = 13, D14 = 14, D15 = 15,
	D16 = 16, D17 = 17, D18 = 18, D19 = 19, D20 = 20,
	D21 = 21, D22 = 22, D23 = 23, D24 = 24, D25 = 25,
	D26 = 26, D27 = 27, D28 = 28, D29 = 29, D30 = 30,
	D31 = 31
};

enum WeekDay {
	Mon = 1, Tue = 2, Wed = 3, Thr = 4, Fri = 5, Sat = 6, Sun = 7
};

// A week starts on Monday and ends on Sunday. Weeks are numbered in a year from 1 to 52
// (or 53). Week 1 (W01) of a year starts contains the first Thursday of the year. Hence
// W01 of 2016 starts on 04/Jan and ends on 10/Jan as 07/Jan is the first Thursday.
// 01/Jan, 02/Jan, and 03/Jan therefore belongs to the last week of 2015.
enum WeekNumber {
	W01 = 1, W02 = 2, W03 = 3, W04 = 4, W05 = 5,
	W06 = 6, W07 = 7, W08 = 8, W09 = 9, W10 = 10,
	W11 = 11, W12 = 12, W13 = 13, W14 = 14, W15 = 15,
	W16 = 16, W17 = 17, W18 = 18, W19 = 19, W20 = 20,
	W21 = 21, W22 = 22, W23 = 23, W24 = 24, W25 = 25,
	W26 = 26, W27 = 27, W28 = 28, W29 = 29, W30 = 30,
	W31 = 31, W32 = 32, W33 = 33, W34 = 34, W35 = 35,
	W36 = 36, W37 = 37, W38 = 38, W39 = 39, W40 = 40,
	W41 = 41, W42 = 42, W43 = 43, W44 = 44, W45 = 45,
	W46 = 46, W47 = 47, W48 = 48, W49 = 49, W50 = 50,
	W51 = 51, W52 = 52, W53 = 53
};

enum Month {
	Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6,
	Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12
};

typedef unsigned int Year;

// This class defines the format in which a date is output or input
class DateFormat {
public:
	// The parameters below takes designated values with the specified format semantics
	// dateFormat:
	// 0: No date. This is valid for output only.
	// "d": single digit date in one digit, double digit date in two digits (7, 23)
	// "dd": all dates in two digits with single digit dates with leading 0 (07, 23)
	// monthFormat:
	// 0: each month in its full name (February, November). This is valid for output only.
	// "m": single digit month in one digit, double digit month in two digits (2, 11)
	// "mm": all months in two digits with single digit months with leading 0 (02, 11)
	// "mmm": each month with first three letters of its name (Feb, Nov). This is valid for output only.
	// yearFormat:
	// 0: No year. This is valid for output only.
	// "yy": year in last two digits (1961 as 61, 2016 as 16)
	// "yyyy": year in four digits (1961 as 1961, 2016 as 2016)

	DateFormat(char* date, char* month, char* year){

		dateFormat = new char[10]; 
		monthFormat = new char[10]; 
		yearFormat = new char[10]; 

		if(strcmp(date,"0") == 0 || strcmp(date,"d") == 0 || strcmp(date,"dd") == 0)strcpy(dateFormat, date);
		else throw invalid_argument("");
		
		if(strcmp(month,"0") == 0 || strcmp(month,"m") == 0 || strcmp(month,"mm") == 0 || strcmp(month,"mmm") == 0)strcpy(monthFormat, month);
		else throw invalid_argument("");

		if(strcmp(year,"0") == 0 || strcmp(year,"yy") == 0 || strcmp(year,"yyyy") == 0)strcpy(yearFormat, year);
		else throw invalid_argument("");

		cout << dateFormat << "-" << monthFormat << "-" << yearFormat << endl;
	}
	// Single C-string format where dateFormat, monthFormat, and yearFormat are separated by ’-’
	// Example: "dd-mmm-yy", "d-mm-yyyy", etc

	DateFormat(const char* format){
	
		int i = 0, p1 = 0, p2 = 0, len = strlen(format),count = 0;

		while (i < len){
			if (format[i] == '-'){
				if (p1 == 0)p1 = i;
				else p2 = i;
				count++;
			}

			i++;
		}

		if(count != 2)throw invalid_argument("");
		if(p1 == 0)throw invalid_argument("");
		if(p2 == p1 + 1 || p2 == len)throw invalid_argument("");

		dateFormat = new char[5];
		monthFormat = new char[5];
		yearFormat = new char[10];

		for (i = 0; i < p1; i++){
			dateFormat[i] = format[i];
		}
		dateFormat[i] = '\0';

		for (i = 0; i < p2 - p1 - 1; i++){
			monthFormat[i] = format[i + p1 + 1];
		}
		monthFormat[i] = '\0';

		for (i = 0; i < len - p2 - 1; i++){
			yearFormat[i] = format[i + p2 + 1];
		}
		yearFormat[i] = '\0';

		if(!((strcmp(dateFormat,"0") == 0 || strcmp(dateFormat,"d") == 0 || strcmp(dateFormat,"dd") == 0) && 
		   (strcmp(monthFormat,"0") == 0 || strcmp(monthFormat,"m") == 0 || strcmp(monthFormat,"mm") == 0 || strcmp(monthFormat,"mmm") == 0) && 
		   (strcmp(yearFormat,"0") || strcmp(yearFormat,"yy") == 0 || strcmp(yearFormat,"yyyy") == 0)))
		{
			dateFormat = new char[5];
			monthFormat = new char[5];
			yearFormat = new char[10];
			throw invalid_argument("");
		}
	}
	// Default DateFormat created as "dd-mmm-yy"

	DateFormat(){
		dateFormat = new char[5];
		monthFormat = new char[5];
		yearFormat = new char[5];
		strcpy(dateFormat,"dd");
		strcpy(monthFormat,"mmm");
		strcpy(yearFormat,"yy");
	}

	char* getDate(){
		return dateFormat;
	}

	char* getMonth(){
		return monthFormat;
	}

	char* getYear(){
		return yearFormat;
	}

	DateFormat& operator=(DateFormat& df){

		strcpy(dateFormat,df.getDate());
		strcpy(monthFormat,df.getMonth());
		strcpy(yearFormat,df.getYear());
	}

	~DateFormat(){
		//	
	}

private:
	char* dateFormat; // C-string specifying format of date
	char* monthFormat; // C-string specifying format of month
	char* yearFormat; // C-string specifying format of year
};

// This class defines a date within 01/Jan/1950 and 31/Dec/2049
class Date {
public:
	// CONSTRUCTORS
	Date(Day d, Month m, Year y) // Construct a Date from (d, m, y)
		throw(
		invalid_argument, // One or more of the arguments d or m is/are invalid (27, 13, 13)
		domain_error, // (d, m, y) as a triplet does not define a valid date (30, 2, 61)
		out_of_range){// Date is out of range (4, 7, 2053)

		if (y > 100){if (y > 2049 || y < 1950)throw out_of_range("");}
		else{
			if (m == Feb){
				if (y % 4 == 0) { if (d > 29)throw domain_error(""); }
				else if (d > 28)throw domain_error("");
			}
			else if (m % 2 == 1){ if (d > 31)throw domain_error("");}
			else if (d > 30)throw domain_error("");
		}

		if (m > 12 || m < 1)throw domain_error("");

		date = d;
		month = m;

		if(y > 100)year = y;
		else{
			if (y > 49)year = 1900 + y;
			else year = 2000 + y;
		}

		if((month == 2) && (year%4 != 0) && (date > 28))throw domain_error("");
		if((month == 2) && (year%4 == 0) && (date > 29))throw domain_error("");
		if(date < 1)throw domain_error("");
		if(month < 8)
			if(month%2 == 0){if(date > 30)throw domain_error("");}
			else{if(date > 31) throw domain_error("");}
		else 
			if(month%2 != 0){if(date > 30)throw domain_error("");}
			else{if(date > 31) throw domain_error("");}
	}

	explicit Date(const char* dt) // date in string format -- to be parsed as static format member
		throw(invalid_argument, domain_error, out_of_range){

		int dash = 0,i,len = strlen(dt),d1,d2;
		char* m;

		for (i = 0; i < len; i++){
			if (dt[i] == '-'){
				dash++;
				if (dash == 1)d1 = i;
				else d2 = i;
			}
		}

		if (dash != 2)throw invalid_argument("");					//check	Date-Month-Year all are present

		if (d1 < 1 || d1 > 2)throw invalid_argument("");			// checking if date is valid or not
		if ((d2 - d1 - 1) < 1)throw invalid_argument("");			// checking if month is valid or not
		if ((len - d2 - 1) != 2 && (len - d2 - 1) != 4)throw invalid_argument("");		//checking if year is valid or not

		m = new char[d2 - d1 - 1];
		date = 0; month = 0; year = 0;
		
		for (i = 0; i < d1; i++){
			if(dt[i] > 47 && dt[i] < 58)date = 10*date + (dt[i] - '0'); 
			else throw invalid_argument("");
		}
		for (i = 0; i < d2 - d1 - 1; i++){ m[i] = dt[d1 + i + 1]; }
		
		for (i = 0; i < len - d2 - 1; i++){ 
				if(dt[d2 + i + 1] >= '0' && dt[d2 + i + 1] <= '9')year = 10*year + (dt[d2 + i + 1] - '0'); 
				else throw invalid_argument("");
			}
		
		if(year < 100){
			if (year > 49)year = 1900 + year;
			else year = 2000 + year;
		}else if((year < 1950) || (year > 2049))throw out_of_range("");

		if ((d2 - d1 - 1) <= 2){
			for (i = 0; i < (d2 - d1 - 1); i++){
				if(m[i] <= '9' && m[i] >= '0')month = 10 * month + (m[i] - '0');
				else throw invalid_argument("");
			}
		}
		else{
			if (m == "Jan" || m == "January")month = 1;
			if (m == "Feb" || m == "February")month = 2;
			if (m == "Mar" || m == "March")month = 3;
			if (m == "Apr" || m == "April")month = 4;
			if (m == "May" || m == "May")month = 5;
			if (m == "Jun" || m == "June")month = 6;
			if (m == "Jul" || m == "July")month = 7;
			if (m == "Aug" || m == "August")month = 8;
			if (m == "Sep" || m == "September")month = 9;
			if (m == "Oct" || m == "October")month = 10;
			if (m == "Nov" || m == "November")month = 11;
			if (m == "Dec" || m == "December")month = 12;
		}
		
		if(month < 1 || month > 12)throw domain_error("");
		if((month == 2) && (year%4 != 0) && (date > 28))throw domain_error("");
		if((month == 2) && (year%4 == 0) && (date > 29))throw domain_error("");
		if(date < 1)throw domain_error("");
		if(month < 8)
			if(month%2 == 0){if(date > 30)throw domain_error("");}
			else{if(date > 31) throw domain_error("");}
		else 
			if(month%2 != 0){if(date > 30)throw domain_error("");}
			else{if(date > 31) throw domain_error("");}
	}
	// "13-03-77" for "dd-mm-yy"
	// "2-7-2018" for "d-m-yyyy"

	Date() // Default Constructor - construct ’today’ (get from system)
		throw(domain_error, out_of_range){

		time_t now = time(0);
		tm *stm = gmtime(&now);

		date = stm->tm_mday;
		month = stm->tm_mon + 1;
		year = stm->tm_year + 1900;

		if((year < 1950) || (year > 2049))throw out_of_range("");
	}

	int getDate(){
		return date;						// return Date to user
	}
	int getMonth(){
		return month;						// return Month to user
	}
	int getYear(){
		return year;						// return Year to user
	}

	Date(Date& dt){ // Copy Constructor
		
		date = dt.getDate();
		month = dt.getMonth();
		year = dt.getYear();
	}
	// DESTRUCTOR

	~Date(){ // No virtual destructor needed
		//
	}// BASIC ASSIGNMENT OPERATOR

	Date& operator=(Date& dt){

		if (this != &dt){

			date = dt.getDate();
			month = dt.getMonth();
			year = dt.getYear();
		}
		
		return *this;
	}

	// UNARY ARITHMETIC OPERATORS
	Date& operator++(){ // Next day

		if (month == 2){
			if (year % 4 == 0){
				if (date == 29){
					date = 1;
					month++;
				}
				else date++;
			}
			else{
				if (date == 28){
					date = 1;
					month++;
				}
				else date++;
			}
			return *this;
		}

		if (month == 12){
			if (date == 31){
				date = 1;
				month = 1;
				year++;
			}
			else date++;
			return *this;
		}

		if (month < 8){
			if (month % 2 == 0){
				if (date == 30){
					date = 1;
					month++;
				}
				else if(month!= 2)date++;
			}
			else{
				if (date == 31){
					date = 1;
					month++;
				}
				else date++;
			}
		}
		else{
			if (month % 2 == 0){
				if (date == 31){
					date = 1;
					month++;
				}
				else date++;
			}
			else{
				if (date == 30){
					date = 1;
					month++;
				}
				else date++;
			}
		}

		return *this;
	}

	Date& operator++(int){ // Same day next week
		int i = 0;
		for(i = 0;i < 7;i++)++(*this);
		return *this;
	}

	Date& operator--(){ // Previous day
		if (month == 3){
			if (year % 4 == 0){
				if (date == 1){
					date = 29;
					month--;
				}
				else date--;
			}
			else{
				if (date == 1){
					date = 28;
					month--;
				}
				else date--;
			}
			return *this;
		}

		if (month == 1){
			if (date == 1){
				date = 31;
				month = 12;
				year--;
			}
			else date--;
			return *this;
		}

		if (month < 9){
			if (month % 2 == 0){
				if (date == 1){
					date = 31;
					month--;
				}
				else date--;
			}
			else{
				if (date == 1){
					date = 30;
					month--;
				}
				else date--;
			}
		}
		else{
			if (month % 2 == 0){
				if (date == 1){
					date = 30;
					month--;
				}
				else date--;
			}
			else{
				if (date == 1){
					date = 31;
					month--;
				}
				else date--;
			}
		}

		return *this;
	}

	Date& operator--(int){ // Same day previous week
		int i = 0;
		for(i = 0;i < 7;i++)--(*this);
		return *this;
	}	

// BINARY ARITHMETIC OPERATORS
	unsigned int operator-(Date& dt){ // Number of days between otherDate and current date
		unsigned int i = 0;
		Date temp = *this;

		if(temp == dt)return 0;

		if (temp > dt)
			while (temp != dt){
				--(temp);
				i++;
			}
		else if (temp < dt)while (temp != dt){
								++(temp);
								i++;
							}
			else return 0;

		return i;
	}
	
	Date& operator+(int n) // Day noOfDays after (before) the current date
		// (sign of noOfDays decides ahead or behind)
		throw(domain_error, out_of_range){
		int i;

		if (n > 0){
			for (i = 0; i < n; i++)++(*this);
		}
		else{
			for (i = 0; i > n; i--)--(*this);
		}

		if(year > 2049 || year < 1950)throw out_of_range("");

		return *this;
	}

	// CAST OPERATORS
	operator WeekNumber() const{ // Cast to the week number of the year in which the current date falls
		static int arr[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
		int i,t = year,dt,mt,yt,d1 = date,m1 = month - 1,y1 = year - 1900;	double difference;

		for(i = 0;i <= 7;i++){
			t -= 1 < 3;
			if((t + t/4 - t/100 + t/400 + arr[1 - 1] + i - 1) == 3)break;
		}

		if((i - 3) > 0){dt = i - 3;	mt = 1;	yt = year;}
		else{dt = 31 + (i - 3);	mt = 12; yt = year - 1;}

		tm a = {0,0,0,dt,mt - 1,yt - 1900}; 
	    tm b = {0,0,0,date,month - 1,year - 1900};
	    time_t x = std::mktime(&a);
	    time_t y = std::mktime(&b);
	    if ( x != (time_t)(-1) && y != (time_t)(-1) ){difference = difftime(y, x) / (60 * 60 * 24);}
	    return static_cast<WeekNumber>((int)(difference)/7 + 1);
	}
	operator Month() const{ // Cast to the month of the year in which the current date falls
		return static_cast<Month>(month);
	}
	operator WeekDay() const{ // Cast to the day of the week of the current date
		static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
		int temp = year;
    	
    	temp -= month < 3;
    	temp = ( temp + temp/4 - temp/100 + temp/400 + t[month-1] + date - 1) % 7;
    	
		return static_cast<WeekDay>(temp + 1);
	}
	bool leapYear() const{ // True if the year of the current date is a leap year
		if (year % 4 == 0)return true;
		else return false;
	}

	// BINARY RELATIONAL OPERATORS
	bool operator==(Date& dt){
		if ((date == dt.getDate()) && (month == dt.getMonth()) && (year == dt.getYear()))return true;
		else return false;
	}
	bool operator!=(Date& dt){
		if ((date != dt.getDate()) || (month != dt.getMonth()) || (year != dt.getYear()))return true;
		else return false;
	}
	bool operator<(Date& dt){
		if (year >= dt.getYear()){
			if (month >= dt.getMonth()){
				if (date >= dt.getDate())return false;
				else return true;
			}
			else return true;
		}
		else return true;
	}
	bool operator<=(Date& dt){
		if(*this == dt || *this < dt)return true;
		else false;
	}
	bool operator>(Date& dt){
		if ((*this == dt) || (*this < dt))return false;
		else return true;
	}
	bool operator>=(Date& dt){
		if (*this < dt)return false;
		else return true;
	}

	// BASIC I/O using FRIEND FUNCTIONS
	// These functions use Date::format to write or read
	friend ostream& operator<<(ostream&, Date& dt){
		char dtemp[5] ;
		char mtemp[15] ;
		char ytemp[10] ;
		unsigned int temp;

		if(!strcmp(format.getDate(),"0")){
			strcpy(dtemp," ");
		}
		if(!strcmp(format.getDate(),"d")){
			if(dt.getDate() < 10){
				dtemp[0] = '0' + dt.getDate();
				dtemp[1]='\0';
			}
			else{
				dtemp[0] = '0' + dt.getDate()/10;
				dtemp[1] = '0' + dt.getDate()%10;
				dtemp[2]='\0';
			}
		}
		if(!strcmp(format.getDate(),"dd")){
			if(dt.getDate() < 10){
				dtemp[0] = '0';
				dtemp[1] = '0' + dt.getDate();
				dtemp[2]='\0';
			}
			else{
				dtemp[0] = '0' + (dt.getDate()/10);
				dtemp[1] = '0' + (dt.getDate()%10);
				dtemp[2]='\0';
			}	
		}

		if(!strcmp(format.getMonth(),"0")){
			if(dt.getMonth() == 1){	strcpy(mtemp,"January");}
			if(dt.getMonth() == 2){ strcpy(mtemp,"February");}
			if(dt.getMonth() == 3){	strcpy(mtemp,"March");}
			if(dt.getMonth() == 4){	strcpy(mtemp,"April");}
			if(dt.getMonth() == 5){	strcpy(mtemp,"May");}
			if(dt.getMonth() == 6){	strcpy(mtemp,"June");}
			if(dt.getMonth() == 7){	strcpy(mtemp,"July");}
			if(dt.getMonth() == 8){	strcpy(mtemp,"August");}
			if(dt.getMonth() == 9){	strcpy(mtemp,"September");}
			if(dt.getMonth() == 10){strcpy(mtemp,"October");}
			if(dt.getMonth() == 11){strcpy(mtemp,"November");}
			if(dt.getMonth() == 12){strcpy(mtemp,"December");}
		}
		if(!strcmp(format.getMonth(),"mmm")){
			if(dt.getMonth() == 1){	strcpy(mtemp,"Jan");}
			if(dt.getMonth() == 2){	strcpy(mtemp,"Feb");}
			if(dt.getMonth() == 3){	strcpy(mtemp,"Mar");}
			if(dt.getMonth() == 4){	strcpy(mtemp,"Apr");}
			if(dt.getMonth() == 5){	strcpy(mtemp,"May");}
			if(dt.getMonth() == 6){	strcpy(mtemp,"Jun");}
			if(dt.getMonth() == 7){	strcpy(mtemp,"Jul");}
			if(dt.getMonth() == 8){	strcpy(mtemp,"Aug");}
			if(dt.getMonth() == 9){	strcpy(mtemp,"Sep");}
			if(dt.getMonth() == 10){strcpy(mtemp,"Oct");}
			if(dt.getMonth() == 11){strcpy(mtemp,"Nov");}
			if(dt.getMonth() == 12){strcpy(mtemp,"Dec");}	
		}
		if(!strcmp(format.getMonth(),"m")){
			if(dt.getMonth() < 10){
				mtemp[0] = '0' + dt.getMonth();
				mtemp[1]='\0';
			}
			else{
				mtemp[0] = '0' + dt.getMonth()/10;
				mtemp[1] = '0' + dt.getMonth()%10;
				mtemp[2]='\0';
			}

		}
		if(!strcmp(format.getMonth(),"mm")){
			if(dt.getMonth() < 10){
				mtemp[0] = '0';
				mtemp[1] = '0' + dt.getMonth()%10;
				mtemp[2]='\0';
			}
			else{
				mtemp[0] = '0' + dt.getMonth()/10;
				mtemp[1] = '0' + dt.getMonth()%10;
				mtemp[2]='\0';
			}	
		}

		if(!strcmp(format.getYear(),"0")){
			strcpy(ytemp," ");
		}
		if(!strcmp(format.getYear(),"yy")){
			temp = dt.getYear()%100;
			ytemp[0] = '0' + temp/10;
			ytemp[1] = '0' + temp%10;
			ytemp[2]='\0';
		}
		if(!strcmp(format.getYear(),"yyyy")){
			temp = dt.getYear();
			ytemp[0] = '0' + temp/1000;
			ytemp[1] = '0' + (temp%1000)/100;
			ytemp[2] = '0' + ((temp%1000)%100)/10;
			ytemp[3] = '0' + ((temp%1000)%100)%10;
			ytemp[4]='\0';
		}

		cout << dtemp << "-" << mtemp << "-" << ytemp;
	}
	//friend ostream& operator<<(ostream&, Date& dt);

	friend istream& operator>>(istream&, Date& dt){
		char s[50];
		cin >> s;
		Date temp(s);
		dt = temp;
	}

	// Format Function
	static void setFormat(DateFormat& ft){
		format = ft;
	}
	static DateFormat& getFormat(){
		return format;
	}

private:
	// Format to represent Date
	static DateFormat format;
	int date, month, year;
	// Data members for Date
	// Need to fill up
};

DateFormat Date::format ;