#ifndef DataStructures_H
#define DataStructures_H

#include<windows.h>
#include<mylib.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#include "timing.h"

const int MAXSIZE=300;


//cau truc danh sach may bay: MANG CON TRO.
struct Airplane{
	char plane_id[15];//15
	char plane_type[40];//40
	int seats;// so cho>=20.
	
	
	//CHI SO PHU: so luot thuc hien
	int num_of_flights=0;
	
	//CHI SO PHU: active
	bool active=true;
	
};
struct AirplaneList{
	Airplane *airplanes[MAXSIZE];
	int n=0;        //so may bay.
};



// ve: dung mang con tro
struct Ticket{
	char person_id[10]="x";
	int order;// stt-so thu tu: so ve.
};
struct TicketList{
	Ticket **seat;//khoi tao bang so_cho cua may bay.
	int booked;//so ve da duoc dat.
	int limit;// so phan tu toi da!
};


void initializeTicket(TicketList &ticket_list, int quantity,int booked){
	ticket_list.seat=new Ticket*[quantity];
	for(int i=0;i<quantity;i++){
		ticket_list.seat[i] = new Ticket[1];
	}
	ticket_list.limit = quantity;
	ticket_list.booked = booked;
}


//cau truc chuyen bay : DANH SACH LIEN KET DON!


struct Flight{
	char flight_id[16]="x";
	DateTime depart_time;
	char destination[21];
	int status; // 0:huy chuyen 1:con ve 2:het ve 3:hoan tat.
	char plane_id[16];
	
	//moi ve bao gom: cmnd va stt
	TicketList ticket_list;
	
};
struct FlightNode{	
	Flight flight;
	FlightNode* next=NULL;
};
typedef FlightNode* flight_ptr;




//Hanh khach: CAY NHI PHAN TIM KIEM CAN BANG.
 struct Passenger{
 	char person_id[10];
 	char last_name[31];
 	char name[11];
 	bool sex;
};
 
 struct PassengerNode{
 	Passenger passenger;	
 	int bf=0;//chi so can bang cua nut hien tai.
 	PassengerNode *right=NULL;
 	PassengerNode *left=NULL;
 };
typedef PassengerNode* psnode_ptr;

#endif
