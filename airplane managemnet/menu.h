#ifndef menu
#define menu
#include "IO.h"




//function.

void chooseFunction(){
	//_____________________DOC DU LIEU__________________________
		openAirplaneFile(airplane_list,PLANE_FILE);
		openPsFile(ps_root,PASSENGER_FILE);
		openFlightFile(head_flist,FLIGHT_FILE,TICKET_LIST_FILE);
		//thiet lap trang thai chuyen bay
		updateStatement(head_flist);
		resizeConsole(200,200);
		ShowConsoleCursor(false);
		mainDisplay();
	while(1){
	    
		char temp_flight_id[15] = "";
		char temp_person_id[10] = "";
		flight_ptr check2=NULL;
		drawToolBar();
		int i =0;int x=4,check;
		while(!kbhit()){
			Logo(20,15);
			Sleep(200);
		}
		i=hitKey();
		if (i!=27){//not escape
			deleteTable(); //xoa cai intro
		while(1){
			int j;
			switch (x){
		    	case 4:{
		    		string f_list[3]={"             THEM            ","             XOA             ","          HIEU CHINH         "};
		    		string s="     QUAN LY MAY BAY         ";
		    		drawTool(x,s); // 
        			printFunction(x,3,f_list);//
        			int y=3;
        			drawRectangle(x,y,31,3);
        			changeColor(x+1,y+1,3,0,f_list[y-3]);
        			drawIntro(138,20);
        			intro(1);
        			while(1){
        				j=hitKey();
        				if(j==80){ // mui ten xuong
        					switch(y){
        					case 3:{
        						intro(2);
								changeColor(x+1,y+1,11,0,f_list[0]);
        						y+=3;
        						changeColor(x+1,y+1,3,0,f_list[1]);
        						break;
								} 
							case 6:{
								intro(3);
        						changeColor(x+1,y+1,11,0,f_list[1]);
        						y+=3;
        						changeColor(x+1,y+1,3,0,f_list[2]);
        						break;
								} 
							case 9:{
								intro(1);
        						changeColor(x+1,y+1,11,0,f_list[2]);
        						y=3;
        						changeColor(x+1,y+1,3,0,f_list[0]);
        						break;
								} 
							}
						}
						if(j==72){
							switch(y){
        					case 3:{
        						intro(3);
        						changeColor(x+1,y+1,11,0,f_list[0]);
        						y=9;
        						changeColor(x+1,y+1,3,0,f_list[2]);
        						break;
								} 
							case 6:{
								intro(1);
        						changeColor(x+1,y+1,11,0,f_list[1]);
        						y-=3;
        						changeColor(x+1,y+1,3,0,f_list[0]);
        						break;
								} 
							case 9:{
								intro(2);
        						changeColor(x+1,y+1,11,0,f_list[2]);
        						y-=3;
        						changeColor(x+1,y+1,3,0,f_list[1]);
        						break;
								} 
							}
						}
						if (j==13){
        					deleteFunction(x,11,s);
        					deleteIntro(1);
        					//Lenh khi chon bang phim ENTER
        					SetBGColor(14);
        					if (y==3){
        						int n=0;
								drawRectangle(42+20,12,23,3); 
								gotoxy(63,13);
								SetBGColor(11);
								cout<<"So luong may bay :   ";
								ShowConsoleCursor(true);
								while(true){
									do{
										check =0;
										hitNumbers(n,81,13,2,check);//nhap so luong may bay;
									}while( n == 0);
										if (n+airplane_list.n > 300){ 
											int result = MessageBox(NULL,"So luong may bay khong duoc qua 300\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
											while(kbhit()) getch();
											if (result == IDCANCEL){
												deleteTable();
												break;
											}
										}else break; // thoat khoi vong lap
								}
								
								SetBGColor(14);
								for (int t=1;t<=n;t++)//add n may bay
									addNewAirplane(airplane_list);	 
								
							} 
        					if (y==6) deleteAirplane(airplane_list); 
        					if (y==9) editAirplane(airplane_list);
        					break;
						}
						if (j==27){
							deleteFunction(x,11,s);
							deleteIntro(1);
							break;
						} // dung khi nhan Esc
						if (j==75) {
							deleteFunction(x,11,s);
							x=114; 
							break;
						}
						if (j==77) {
							deleteFunction(x,11,s);
							x=40; 
							break;
						}
					}					
					break;
				}
				case 40:{
		    		string f_list[5]={"      LAP CHUYEN BAY MOI     ","     HIEU CHINH NGAY GIO     ","        CUA CHUYEN BAY       ","        HUY CHUYEN BAY       ","     IN DS CAC CHUYEN BAY    "};
		    		string s="     QUAN LY CHUYEN BAY      ";                                                                                    
		    		drawTool(x,s);
        			printFunction(x,5,f_list);
        			int y=3;
        			drawRectangle(x,y,31,3);
        			changeColor(x+1,y+1,3,0,f_list[y-3]);
        			intro(4);
        			while(1){
        				j=hitKey();
        				if(j==80){
        					switch(y){
        					case 3:{
        						intro(5);
        						changeColor(x+1,y+1,11,0,f_list[0]);
        						y+=3;
        						changeColor(x+1,y+1,3,0,f_list[1]);
        						changeColor(x+1,y+2,3,0,f_list[2]);
        						break;
								} 
							case 6:{
								intro(6);
        						changeColor(x+1,y+1,11,0,f_list[1]);
        						changeColor(x+1,y+2,11,0,f_list[2]);
        						y=10;
        						changeColor(x+1,y+1,3,0,f_list[3]);
        						break;
								} 
							case 10:{
								intro(41);
        						changeColor(x+1,y+1,11,0,f_list[3]);
        						y=13;
        						changeColor(x+1,y+1,3,0,f_list[4]);
        						break;
								} 
							case 13:{
								intro(4);
        						changeColor(x+1,y+1,11,0,f_list[4]);
        						y=3;
        						changeColor(x+1,y+1,3,0,f_list[0]);
        						break;
								}
							}
						}
						if(j==72){
							switch(y){
        					case 3:{
        						intro(41);
        						changeColor(x+1,y+1,11,0,f_list[0]);
        						y=13;
        						changeColor(x+1,y+1,3,0,f_list[4]);
        						break;
								} 
							case 6:{
								intro(4);
        						changeColor(x+1,y+1,11,0,f_list[1]);
        						changeColor(x+1,y+2,11,0,f_list[2]);
        						y-=3;
        						changeColor(x+1,y+1,3,0,f_list[0]);
        						break;
								} 
							case 10:{
								intro(5);
        						changeColor(x+1,y+1,11,0,f_list[3]);
        						y=6;
        						changeColor(x+1,y+1,3,0,f_list[1]);
        						changeColor(x+1,y+2,3,0,f_list[2]);
        						break;
								}
							case 13:{
        						intro(6);
        						changeColor(x+1,y+1,11,0,f_list[4]);
        						y=10;
        						changeColor(x+1,y+1,3,0,f_list[3]);
        						break;
								} 
							}
						}
						if (j==13){
        					deleteFunction(x,17,s);
        					deleteIntro(1);
        					//Lenh khi chon bang phim ENTER
        					SetBGColor(14);
        					if (y==3) addNewFlight(head_flist);
        					if (y==6) editFlight(head_flist);
        					if (y==10) deleteFlight(head_flist,airplane_list);
        					if (y==13) traverseFlight(head_flist);
        					break;
						}
						if (j==27) {
							deleteFunction(x,17,s);
							deleteIntro(1);
							break;
						}
						if (j==75) {
							deleteFunction(x,17,s);
							x=4; 
							break;
						}
						if (j==77) {
							deleteFunction(x,17,s);
							x=78; 
							break;
						}
					}					
					break;
				}
				case 78:{
		    		string f_list[2]={"           DAT VE            ","           HUY VE            "};
        			string s="        DAT / HUY VE         ";
		    		drawTool(x,s);
        			printFunction(x,2,f_list);
        			int y=3;
        			drawRectangle(x,y,31,3);
        			changeColor(x+1,y+1,3,0,f_list[y-3]);
        			intro(7);
        			while(1){
        				j=hitKey();
        				if(j==80 || j==72){
        					switch(y){
        					case 3:{
        						intro(8);
        						changeColor(x+1,y+1,11,0,f_list[0]);
        						y+=3;
        						changeColor(x+1,y+1,3,0,f_list[1]);
        						break;
								} 
							case 6:{
								intro(7);
        						changeColor(x+1,y+1,11,0,f_list[1]);
        						y-=3;
        						changeColor(x+1,y+1,3,0,f_list[0]);
        						break;
								} 
							}
						}
						if (j==13){
        					deleteFunction(x,8,s);
        					deleteIntro(1);
        					//Lenh khi chon bang phim ENTER
        					gotoxy(20,20);
        					SetBGColor(14);
        					SetColor(0);
        					if (y==3) {
        						fflush(stdin);
        						updateStatement(head_flist); // update trang thai cac chuyen bay.
								do{
									memset(temp_flight_id,'\0',sizeof(temp_flight_id));
									deleteTable();
									drawRectangle(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay :                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										check =3;
										hitKeyBoard2(temp_flight_id,69,16,15,check);
									}while(strlen(temp_flight_id)==0);
										strupr(temp_flight_id);
									SetBGColor(14);
									ShowConsoleCursor(false);
									check2=searchNode(head_flist,temp_flight_id);
									
									if(check2!=NULL && check2->flight.status==1){ //dat ve
										orderTicket(head_flist,check2,check2->flight.ticket_list);
		
										break;
									}
									else if (check2 == NULL){
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										} 
									}
									else if(check2->flight.status==3){
										int result = MessageBox(NULL,"Chuyen bay nay da thuc hien!\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										}
									}
									else if(check2->flight.status==0){
										int result = MessageBox(NULL,"Chuyen bay nay da bi huy!\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										}
									}
									else if(check2->flight.status==2){
										int result = MessageBox(NULL,"Chuyen bay nay da het ve!\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										}
									}
								}while(true);
							}	
        					if (y==6){
        						fflush(stdin);
        						do{
        							deleteTable();
        							memset(temp_flight_id,'\0',sizeof(temp_flight_id));
									drawRectangle(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay :                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										check =4;
										hitKeyBoard2(temp_flight_id,69,16,15,check);
									}while(strlen(temp_flight_id)==0);
										strupr(temp_flight_id);
									SetBGColor(14);
									ShowConsoleCursor(false);
									check2=searchNode(head_flist,temp_flight_id);
									if (check2!=NULL && check2->flight.status == 0){
										int result = MessageBox(NULL,"Chuyen bay da bi huy\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										}
									}
									if (check2!=NULL && check2->flight.status == 3){
										int result = MessageBox(NULL,"Chuyen bay da hoan tat khong duoc huy ve\n Ban co muon nhap lai","THONG BAO",MB_ICONHAND|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										}
									}
									if (check2 != NULL && check2->flight.status != 3 && check2->flight.status != 0 && check2->flight.ticket_list.booked == 0 ){
										int result = MessageBox(NULL,"Danh sach hanh khach trong \n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										}
									}
									else if(check2!=NULL && check2->flight.status != 3 && check2->flight.status != 0){
										deleteTable();
										removeTicket(check2->flight.ticket_list);
										break;
									}
									if (check2 == NULL){
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										} 
									}
								}while(true);
							} 
        					break;
						}
						if (j==27){
							deleteFunction(x,8,s);
							deleteIntro(1);
							break;
						} 
						if (j==75) {
							deleteFunction(x,8,s);
							x=40; 
							break;
						}
						if (j==77) {
							deleteFunction(x,8,s);
							x=114; 
							break;
						}
					}					
					break;
				}
				case 114:{
		    		string f_list[8]={"  IN DS HK CUA 1 CHUYEN BAY  ","    IN DS CAC CHUYEN BAY     ","         KHOI HANH           ","  IN DS CAC VE CON TRONG CUA ","          CHUYEN BAY         ","  THONG KE SO LUOT THUC HIEN ","       CUA CAC MAY BAY       ","   IN DS TAT CA HANH KHACH   "};
        			string s="      THONG KE DU LIEU       ";					 		
		    		drawTool(x,s);
        			printFunction(x,8,f_list);
        			int y=3;
        			drawRectangle(x,y,31,3);
        			changeColor(x+1,y+1,3,0,f_list[y-3]);
        			intro(9);
        			while(1){
        				j=hitKey();
        				if(j==80){
        					switch(y){
        					case 3:{
        						intro(10);
        						changeColor(x+1,y+1,11,0,f_list[0]);
        						y+=3;
        						changeColor(x+1,y+1,3,0,f_list[1]);
        						changeColor(x+1,y+2,3,0,f_list[2]);
        						break;
								} 
							case 6:{
								intro(11);
        						changeColor(x+1,y+1,11,0,f_list[1]);
        						changeColor(x+1,y+2,11,0,f_list[2]);
        						y+=4;
        						changeColor(x+1,y+1,3,0,f_list[3]);
        						changeColor(x+1,y+2,3,0,f_list[4]);
        						break;
								} 
							case 10:{
								intro(12);
        						changeColor(x+1,y+1,11,0,f_list[3]);
        						changeColor(x+1,y+2,11,0,f_list[4]);
        						y+=4;
        						changeColor(x+1,y+1,3,0,f_list[5]);
        						changeColor(x+1,y+2,3,0,f_list[6]);
        						break;
								} 
							case 14:{
								intro(91);
								changeColor(x+1,y+1,11,0,f_list[5]);
        						changeColor(x+1,y+2,11,0,f_list[6]);
								y=18;
        						changeColor(x+1,y+1,3,0,f_list[7]);
								break;
							}
							case 18:{
								intro(9);
								changeColor(x+1,y+1,11,0,f_list[7]);
								y=3;
        						changeColor(x+1,y+1,3,0,f_list[0]);
								break;
							}
							}
						}
						if(j==72){
							switch(y){
        					case 3:{
        						intro(91);
        						changeColor(x+1,y+1,11,0,f_list[0]);
        						y=18;
        						changeColor(x+1,y+1,3,0,f_list[7]);
        						break;
								} 
							case 6:{
								intro(9);
        						changeColor(x+1,y+1,11,0,f_list[1]);
        						changeColor(x+1,y+2,11,0,f_list[2]);
        						y-=3;
        						changeColor(x+1,y+1,3,0,f_list[0]);
        						break;
								} 
							case 10:{
								intro(10);
        						changeColor(x+1,y+1,11,0,f_list[3]);
        						changeColor(x+1,y+2,11,0,f_list[4]);
        						y-=4;
        						changeColor(x+1,y+1,3,0,f_list[1]);
        						changeColor(x+1,y+2,3,0,f_list[2]);
        						break;
								} 
							case 14:{
								intro(11);
								changeColor(x+1,y+1,11,0,f_list[5]);
        						changeColor(x+1,y+2,11,0,f_list[6]);
        						y-=4;
        						changeColor(x+1,y+1,3,0,f_list[3]);
        						changeColor(x+1,y+2,3,0,f_list[4]);
								break;
							}
							case 18:{
								intro(12);
        						changeColor(x+1,y+1,11,0,f_list[7]);
        						y=14;
        						changeColor(x+1,y+1,3,0,f_list[5]);
        						changeColor(x+1,y+2,3,0,f_list[6]);
								break;
							}
							}
						}
						if (j==13){
        					deleteFunction(x,21,s);
        					deleteIntro(1);
        					//Lenh khi chon bang phim ENTER.
        					gotoxy(20,20);
        					SetBGColor(14);
        					SetColor(0);
        					if (y==3){
        						fflush(stdin);
        						do{
									drawRectangle(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay:                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										check =2;
										hitKeyBoard2(temp_flight_id,69,16,15,check);
									}while(strlen(temp_flight_id)==0);
										strupr(temp_flight_id);
									SetBGColor(14);
									ShowConsoleCursor(false);
									check2=searchNode(head_flist,temp_flight_id);
									if(check2!=NULL){
										deleteTable();
										printByFlightId(check2->flight);
									}
									else{
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										} 
									}
								}while(check2==NULL);
							
						    }
        					if (y==6) printFollowDayPlace(head_flist);
        					if (y==10){
        					 	fflush(stdin);
								do{
									drawRectangle(42,15,65,3); 
									gotoxy(44,16);
									SetBGColor(11);
									cout<<"Nhap vao Ma chuyen bay :                                     ";
									ShowConsoleCursor(true);
									fflush(stdin);
									do{
										check = 2;
										hitKeyBoard2(temp_flight_id,69,16,15,check);
									}while(strlen(temp_flight_id)==0);
										strupr(temp_flight_id);
									SetBGColor(14);
									ShowConsoleCursor(false);
									check2=searchNode(head_flist,temp_flight_id);
									if(check2!=NULL){
										deleteTable();
										printEmptyTicket(check2->flight.ticket_list,temp_flight_id);
									}
									else{
										int result = MessageBox(NULL,"Ma chuyen bay khong ton tai\n Ban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
										while(kbhit()) getch();
										if (result == IDCANCEL){
											deleteTable();
											break;
										} 
									}
								}while(check==NULL);
							}
        					if (y==14) printNumOfFlight(airplane_list);
        					if (y==18) printAllPassenger();
        					break;
						}
						if (j==27) {
							deleteFunction(x,21,s);
							deleteIntro(1);
							break;
						}
						if (j==75) {
							deleteFunction(x,21,s);
							x=78; 
							break;
						}
						if (j==77) {
							deleteFunction(x,21,s);
							x=4; 
							break;
						}
					}					
					break;
				}
			}
		if (j==27 ||j==13) {
			saveAirplaneFile(airplane_list,PLANE_FILE);
			saveFlightFile(head_flist,FLIGHT_FILE,TICKET_LIST_FILE);
			savePsFile(ps_root,PASSENGER_FILE);
			break;	
		}	
		}  
    	}	
	if (i==27) break;			
	}
}

#endif
