// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................
#include <iostream>
#include <string>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
    int month_int = monthStr2Num(month);
    CDate(year, month_int, day);
}

bool CDate::isValidDate(int year, int month, int day){
	// comment out the "return false" below 
	// then check the validity of a year, month, and day
    if (year > 0){
        if (isValidDay(year, month, day)){
            return true;
        }
    }
	return false;
}

bool CDate::isValidDate(int year, std::string month, int day){
	int month_int = monthStr2Num(month);
    return isValidDate(year,month_int,day);
}

int CDate::monthStr2Num(std::string month){
    int result = 0;
    
    std::string str1 ("January");
    std::string str1num ("1");
    std::string str2 ("February");
    std::string str2num ("2");
    std::string str3 ("March");
    std::string str3num ("3");
    std::string str4 ("April");
    std::string str4num ("4");
    std::string str5 ("May");
    std::string str5num ("5");
    std::string str6 ("June");
    std::string str6num ("6");
    std::string str7 ("July");
    std::string str7num ("7");
    std::string str8 ("August");
    std::string str8num ("8");
    std::string str9 ("September");
    std::string str9num ("9");
    std::string str10 ("October");
    std::string str10num ("10");
    std::string str11 ("November");
    std::string str11num ("11");
    std::string str12 ("December");
    std::string str12num ("12");
    
    if (month.compare(str1) == 0 || month.compare(str1num) == 0){
        result = 1;
    }
    else if (month.compare(str2) == 0 || month.compare(str2num) == 0){
        result = 2;
    }
    else if (month.compare(str3) == 0 || month.compare(str3num) == 0){
        result = 3;
    }
    else if (month.compare(str4) == 0 || month.compare(str4num) == 0){
        result = 4;
    }
    else if (month.compare(str5) == 0 || month.compare(str5num) == 0){
        result = 5;
    }
    else if (month.compare(str6) == 0 || month.compare(str6num) == 0){
        result = 6;
    }
    else if (month.compare(str7) == 0 || month.compare(str7num) == 0){
        result = 7;
    }
    else if (month.compare(str8) == 0 || month.compare(str8num) == 0){
        result = 8;
    }
    else if (month.compare(str9) == 0 || month.compare(str9num) == 0){
        result = 9;
    }
    else if (month.compare(str10) == 0 || month.compare(str10num) == 0){
        result = 10;
    }
    else if (month.compare(str11) == 0 || month.compare(str11num) == 0){
        result = 11;
    }
    else if (month.compare(str12) == 0 || month.compare(str12num) == 0){
        result = 12;
    }
    
    //int result = atoi(month);
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
            if((day >= 1) || (day <= 31)){
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
            if((day >= 1) || (day <= 30)){
                valid = true;
            }
            break;
		default:
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
	int month_int = monthStr2Num(month);
    setDate(year,month_int,day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

