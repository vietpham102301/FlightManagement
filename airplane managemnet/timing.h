#ifndef TIME_H
#define TIME_H
#include<time.h>
#include<_mingw.h>
#include<iostream>
using namespace std;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct DateTime{
	int min;
	int hour;
	int day;
	int mon;
	int year;
};
bool dayOfMonth(DateTime date_time){
	if(date_time.mon==2){
		if(date_time.year%400==0 ||(date_time.year%4==0 && date_time.year%100!=0)){
			if(date_time.day>29) return false;
			return true;
		}
		else{
			if(date_time.day>28) return false;
			return true;
		}
	}
	else{
		
	if(date_time.day>day[date_time.mon]) return false;
	return true;
	}
	
}
bool checkDepartTime(DateTime date_time){
	if(dayOfMonth(date_time)==false) {
		//cout<<"Ngay trong thang khong hop le!"<<endl;
		return false;
	}
	
	time_t now=time(0);
	tm *ltm=localtime(&now); // con tro kieu tm
	DateTime dt_now;
	dt_now.day=ltm->tm_mday;
	dt_now.mon=1+ltm->tm_mon;
	dt_now.year=1900+ltm->tm_year;
	dt_now.hour=ltm->tm_hour;
	dt_now.min=ltm->tm_min;
	
	
	
	if(date_time.year<dt_now.year) return false;
	if(date_time.year==dt_now.year){
		if(date_time.mon<dt_now.mon) return false;
			if(date_time.mon==dt_now.mon){
				if(date_time.day<dt_now.day) return false;
					if(date_time.day==dt_now.day){
						if(date_time.hour<dt_now.hour) return false;
						if(date_time.hour==dt_now.hour){
							if(date_time.min<=dt_now.min) return false;
						}
					}
			}
	}
	return true;
}

//den day;
// thoi gian tuong lai
bool isNearer(DateTime time1,DateTime time2){
	if(time1.year<time2.year) return true;
	else if(time1.year>time2.year) return false;
	else if(time1.year==time2.year){
		if(time1.mon<time2.mon) return true;
		else if(time1.mon>time2.mon) return false;
		else if(time1.mon==time2.mon){
			if(time1.day<time2.day) return true;
			else if(time1.day>time2.day) return false;
			else if(time1.day==time2.day){
				if(time1.hour<time2.hour) return true;
				else if(time1.hour>time2.hour) return false;
				else if(time1.hour==time2.hour){
					if(time1.min<time2.min) return true;
					else if(time1.min>time2.min) return false;
					else if(time1.min==time2.min) return false;
				}
			}
		}
	}

}

//thoi gian qua khu
bool isNearer2(DateTime time1, DateTime time2){
		if(time1.year>time2.year) return true;
	else if(time1.year<time2.year) return false;
	else if(time1.year==time2.year){
		if(time1.mon>time2.mon) return true;
		else if(time1.mon<time2.mon) return false;
		else if(time1.mon==time2.mon){
			if(time1.day>time2.day) return true;
			else if(time1.day<time2.day) return false;
			else if(time1.day==time2.day){
				if(time1.hour>time2.hour) return true;
				else if(time1.hour<time2.hour) return false;
				else if(time1.hour==time2.hour){
					if(time1.min>time2.min) return true;
					else if(time1.min<time2.min) return false;
					else if(time1.min==time2.min) return false;
				}
			}
		}
	}
}

#endif
