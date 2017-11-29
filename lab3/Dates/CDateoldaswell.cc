// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

using namespace std;

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	// TODO
    int month_num = monthStr2Num(month);
    setDate(year, month_num, day);
	// HINT use monthStr2Num to get the month_num 
}

bool CDate::isValidDate(int year, int month, int day){
    bool result = false;
    if (year > 0) {
        if (month>=1 && month<=12){
            if (isValidDay(year,month,day)){
                result =  true;
            }
        }
    }
    return result;
	// then check the validity of a year, month, and day
	
}

bool CDate::isValidDate(int year, std::string month, int day){
	// TODO
    int month_num = monthStr2Num(month);
    return isValidDate(year,month_num,day);
}

int CDate::monthStr2Num(std::string month){
	// TODO
    int result = 0;
    
    if (month==("January")){
        result = 1;
    }
    else if (month==("February")){
        result = 2;
        //cout << "February" << endl;
    }
    else if (month==("March")){
        result = 3;
    }
    else if (month==("April")){
        result = 4;
    }
    else if (month==("May")){
        result = 5;
    }
    else if (month==("June")){
        result = 6;
    }
    else if (month==("July")){
        result = 7;
    }
    else if (month==("August")){
        result = 8;
    }
    else if (month==("September")){
        result = 9;
    }
    else if (month==("October")){
        result = 10;
    }
    else if (month==("November")){
        result = 11;
    }
    else if (month==("December")){
        result = 12;
    }
    //cout << month<< result << endl;
    return result;
}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	bool valid = false;
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			// TODO
            if((day >= 1) && (day <= 31)){
                valid = true;
            }
            break;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			// TODO
            if((day >= 1) && (day <= 30)){
                valid = true;
            }
            break;
		default:
			// TODO
            valid = false;
            break;
	}
	return valid;
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	// TODO
    int month_num = monthStr2Num(month);
    setDate(year,month_num,day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

