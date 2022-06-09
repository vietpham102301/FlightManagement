#ifndef IO_H
#define IO_H
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include "processing.h"
#define PLANE_FILE "airplanes.txt"
#define FLIGHT_FILE "flights.txt"
#define PASSENGER_FILE "passengers.txt"
#define TICKET_LIST_FILE "ticket_list.txt"



void saveAirplaneFile(AirplaneList &airplane_list,char *filename) {
 FILE * f;
 if ((f=fopen(filename,"wb"))==NULL)
 {  
 cout<<"Khong the ket noi voi file!"<<endl;
 return;
 }
 for (int i=0; i < airplane_list.n; i++){
 	//									so byte cua kieu nay= x, so lan ghi kieu nay=1!
 	//ghi airplane_list.airplanes[i] vao file
   fwrite (airplane_list.airplanes[i], sizeof(Airplane),1,f);//1. pointer to the array elements to be written 2.size in bytes of each elements 3.Number of elements, each one with a size of size bytes 4.Pointer to a FILE object that specifies an output stream.
 }
 	fclose(f);
// cout<<"Ghi thanh cong!"<<endl;
}
void openAirplaneFile(AirplaneList &airplane_list, char *filename) {
 FILE * f;
  Airplane airplane;
 if ((f=fopen(filename,"rb"))==NULL)
 {  
 	cout<<"Khong the ket noi voi file!"<<endl;
 	return;
 }
 airplane_list.n=0;
 //copy content of the file into airplane, den cuoi file hoac xay ra loi thi fread = 0;
 while  (fread (&airplane, sizeof (Airplane), 1, f)!=0) 
 {
 	airplane_list.airplanes[airplane_list.n]=new Airplane;
 	*airplane_list.airplanes[airplane_list.n]=airplane;
 	airplane_list.n ++;
 }
// cout<<"Mo file thanh cong!"<<endl;
 
}



void saveFlightFile(flight_ptr &flight_head,char *filename1, char *filename2){

 FILE * f1;
 FILE *f2;
 if ((f1=fopen(filename1,"wb"))==NULL)
 {  	cout<<"Duong dan luu file bi loi!"<<endl;
 		 return ;
 }
 if((f2=fopen(filename2,"wb"))==NULL){
 	cout<<"Duong dan file bi loi!"<<endl;
 	return;
 }
 
 flight_ptr ptr=flight_head;
 while(ptr!=NULL)
 {
 	fwrite(&(ptr->flight), sizeof(Flight), 1, f1);
	
	
	for(int i=0;i<ptr->flight.ticket_list.booked;i++)
		{
 		fwrite(ptr->flight.ticket_list.seat[i],sizeof(Ticket),1,f2);
		}
 	ptr=ptr->next;
 }
 
 fclose(f1);
 fclose(f2);
// cout<<"Da luu vao file thanh cong!"<<endl;

}

void openFlightFile(flight_ptr &head , char *filename1,char *filename2){
 FILE * f1;
 FILE *f2; 
 Flight flight;
 Ticket ticket;
 if ((f1=fopen(filename1,"rb"))==NULL)
 {  cout<<"Duong dan file bi loi"<<endl;
 	return ;
 }
 if ((f2=fopen(filename2,"rb"))==NULL)
 {  cout<<"Duong dan file bi loi"<<endl;
 	return ;
 }
 
 //xoa du lieu khi doc file!
 while(head!=NULL){
			FlightNode* p= head;
			head= head->next;
			
			delete p;
			p= NULL;
		}

//bat dau doc file.
 while(fread (&flight, sizeof (Flight), 1, f1)!=0) {
 	
 	Ticket temp_ticket;
 	


	 	initializeTicket(flight.ticket_list,flight.ticket_list.limit,flight.ticket_list.booked);
 	
 		for(int i=0;i<flight.ticket_list.booked;i++){
 			fread ((flight.ticket_list.seat[i]), sizeof (Ticket), 1, f2);
	 	}
 	
 	
 	if(checkDepartTime(flight.depart_time)==false){
 		freeMemory(flight.ticket_list);
	 }
 	
 	FlightNode *temp_node = new FlightNode;
 	temp_node->flight = flight;
 	temp_node->next = NULL;
 	
 	
 	if(head==NULL){
		head = temp_node;
	}
	else{
		temp_node->next = head;
		head = temp_node;
	}
 }
 fclose(f1);
 fclose(f2);
// cout<<"Doc du lieu thanh cong!"<<endl;
}


//==========================HANH KHACH ============================

//save file theo hinh thuc NLR
 void passengerOutPut(psnode_ptr ps_root,FILE *f){
	if(ps_root!=NULL){
	fwrite (&ps_root->passenger, sizeof (Passenger), 1, f);
 	passengerOutPut(ps_root->left,f);
 	passengerOutPut(ps_root->right,f);
 	}
}
void savePsFile(psnode_ptr &ps_root,char *filename){

	FILE *f;
 if ((f=fopen(filename,"wb"))==NULL)
 {  	cout<<"Duong dan luu file bi loi!"<<endl;
 		 return ;
 }
//ROOT_hanhkhach temp_root=root_hk;
passengerOutPut(ps_root,f);
fclose(f);
//cout<<"Ghi file thanh cong!"<<endl;
 
}

void openPsFile(psnode_ptr &ps_root , char *filename){
	
	FILE * f; 
	Passenger ps;
	PassengerNode *p;// ~PTR_hanhkhach
	
	
 if ((f=fopen(filename,"rb"))==NULL)
 {  cout<<"Duong dan file bi loi"<<endl;
 	return;
 }
 
 
while(fread (&ps, sizeof (Passenger), 1, f)!=0){

	
	insertPsNode(ps_root, ps);
	
} 
fclose(f);
}
#endif


