#ifndef PROCESSING_H
#define PROCESSING_H
#include "DataStructures.h"
#include "menu.h"
#include<cmath>
HANDLE wHnd;
HANDLE rHnd;

AirplaneList airplane_list;// tao danh sach luu giu cac may bay. toi da 300 phan tu.
flight_ptr head_flist=NULL;
psnode_ptr ps_root=NULL;


//__________________AIRPLANE_______________________________________

void traverseFlightList(flight_ptr &flight_list);
int searchPlaneId( flight_ptr &flight_list);
bool checkEmpty(TicketList &t_list,int pos);
int verifyAirplane(char temp_plane_id[]);
bool verifyAirplaneBoolean(char temp_plane_id[]);
void deleteAirplane(AirplaneList &airplane_list);
void editAirplane(AirplaneList &airplane_list);
void freeMemory(TicketList &t_list);
//__________________________________FLIGHT______________________________
void insertFlightNode(flight_ptr &f_head,FlightNode *p);
bool isTheSameTime(DateTime dt1,DateTime dt2);
bool checkFlightDecent(flight_ptr &head_flist,char temp_flight_id[],DateTime dt);
bool checkFlightDecentVersion2(flight_ptr &head_flist,flight_ptr &edit_node,char temp_flight_id[],DateTime dt);
void addNewFlight(flight_ptr &head_flist);
void freeMemory(TicketList &ticket_list);
void updateStatement(flight_ptr &head_flist);
void editFlight(flight_ptr &head_flist);
void deleteFlight(flight_ptr &head_flist,AirplaneList &airplane_list);
void sortFlightByTime(flight_ptr &head_flist);
void traverseFlight(flight_ptr &head_flist);
void sortTicketList(TicketList &ticket_list);
bool checkEmpty(TicketList &ticket_list,int pos);
void orderTicket(flight_ptr &flight_list,flight_ptr flight, TicketList &ticket_list);
void removeTicket(TicketList &ticket_list);
void printByFlightId(Flight flight);
void printFollowDayPlace(flight_ptr &head_flist);
void printEmptyTicket(TicketList &ticket_list, char temp_flight_id[]);
void printNumOfFlight(AirplaneList &airplane_list);
//____________________________________PASSENGER________________________________________
psnode_ptr searchPassenger(char temp_person_id[], psnode_ptr &root);
Passenger createData(char temp_person_id[]);
void insertPsNode(psnode_ptr &root,Passenger &passenger);
psnode_ptr rotateLeft(psnode_ptr &root);
psnode_ptr rotateRight(psnode_ptr &ya);
psnode_ptr searchPassenger(char temp_person_id[], psnode_ptr &root);
using namespace std;
//_________________________________________________________________________

void ShowConsoleCursor(bool showFlag)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    //GetConsoleCursorInfo(output, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(output, &cursorInfo);
}
//ham ve logo 
void Logo(int coor_X,int coor_Y)
{                
	int h = coor_Y;
	int i=0,colour_id =1;
	string str;
	ifstream f;
	f.open("plane.TXT",ios::in);
	srand (time(NULL));
	colour_id =3+rand() %4;
//	if (mamau == 2) mamau =8;
//	if (mamau == 3) mamau = 9;
	while (true)
	{
		SetColor(colour_id);
		SetBGColor(14); 
		getline(f,str);
		gotoxy(coor_X, h++);
		cout << str;
		if(f.eof())
		{
			break;
		}
	}
	f.close();
	ShowConsoleCursor(true);
	gotoxy(0, 0);
	
	SetColor(7);
}
//ham tat con tro chuot Console


//Ham ve hcn rong~ CD=n CR=m
void drawRectangle(int x,int y,int width,int length)
{
	gotoxy(x,y);
	cout<<char(218);
	for(int i=1;i<=width-2;i++){
		cout<<char(196);
	}
	cout<<char(191);gotoxy(x,++y);
	int j=1;
	while(j<=length-2){
	cout<<char(179);
	for(int i=1;i<=width-2;i++){
		cout<<" ";
	}
	cout<<char(179);gotoxy(x,++y);
	j++;
	}
	cout<<char(192);
	for(int i=1;i<=width-2;i++){
		cout<<char(196);
	}
	cout<<char(217);
} 
			
void drawTable(int x,int y,int length,int width, int count){
	int horizontal = (width-1)*20+5,vertical = length*3;
	int temp_x = x, temp_y = y;
	int i=1;
	while (i<=length){
		if (i==1){
			gotoxy(x,y);cout<<char(218); for (int j=1;j<=horizontal-2;j++) cout<<char(196); cout<<char(191);
			gotoxy(x,++y);
			for (int j=1;j<=horizontal;j++) 
			{
				if (j==1 || j==horizontal || j==5 || (j-5)%20==0) cout<<char(179); // ve cot
				else {
				SetBGColor(10);
				cout<<" ";
				SetBGColor(14);
				}
			} 
			gotoxy(x,++y);cout<<char(179); for (int j=1;j<=horizontal-2;j++) cout<<char(196); cout<<char(179);
	}
	else if (i==length){
		gotoxy(x,++y);
		for (int j=1;j<=horizontal;j++) {
			if (j==1 || j==horizontal || j==5 || (j-5)%20==0) cout<<char(179);
			else cout<<" ";
		}
		gotoxy(x,++y);cout<<char(192); for (int j=1;j<=horizontal-2;j++) cout<<char(196); cout<<char(217);
	}
	else{
		gotoxy(x,++y);
		for (int j=1;j<=horizontal;j++) {
			if (j==1 || j==horizontal || j==5 || (j-5)%20==0) cout<<char(179);
			else cout<<" ";
		}
		gotoxy(x,++y);cout<<char(179); for (int j=1;j<=horizontal-2;j++) cout<<char(196); cout<<char(179);
	}
	i++;
	}
	for (int i=1;i<=length-1;i++){
 		gotoxy(temp_x+1,i*2+temp_y+1);cout<<count++;
	} 	
}

void drawTable1(int x,int y,int length,int width, int count){
	int ngang =0,doc = length*3;
	if (width==5) ngang = 72;
	if (width==4) ngang = 64;
	int tempx = x, tempy = y;
	int i=1;
	while (i<=length){
		if (i==1){
			gotoxy(x,y);cout<<char(218); for (int j=1;j<=ngang-2;j++) cout<<char(196); cout<<char(191);
			gotoxy(x,++y);
			for (int j=1;j<=ngang;j++) {
				if (width==5){
					if (j==1 || j==ngang || j==5 || j== 13 || j== 25 || j==65 ) cout<<char(179);
					else {SetBGColor(10);cout<<" ";SetBGColor(14);}
				}
				if (width==4){
					if (j==1 || j==ngang || j==5 || j==17 || j==57) cout<<char(179);
					else {SetBGColor(10);cout<<" ";SetBGColor(14);}
				}
			} 
			gotoxy(x,++y);cout<<char(179); for (int j=1;j<=ngang-2;j++) cout<<char(196); cout<<char(179);
	}
	else if (i==length){
		gotoxy(x,++y);
		for (int j=1;j<=ngang;j++) {
			if (width==5){
					if (j==1 || j==ngang || j==5 || j== 13 || j== 25 || j==65 ) cout<<char(179);
					else cout<<" ";
				}
			if (width==4){
					if (j==1 || j==ngang || j==5 || j==17 || j==57) cout<<char(179);
					else cout<<" ";
				}
		}
		gotoxy(x,++y);cout<<char(192); for (int j=1;j<=ngang-2;j++) cout<<char(196); cout<<char(217);
	}
	else{
		gotoxy(x,++y);
		for (int j=1;j<=ngang;j++) {
			if (width==5){
					if (j==1 || j==ngang || j==5 || j== 13 || j== 25 || j==65 ) cout<<char(179);
					else cout<<" ";
				}
			if (width==4){
					if (j==1 || j==ngang || j==5 || j==17 || j==57) cout<<char(179);
					else cout<<" ";
				}
		}
		gotoxy(x,++y);cout<<char(179); for (int j=1;j<=ngang-2;j++) cout<<char(196); cout<<char(179);
	}
	i++;
	}
 	for (int i=1;i<=length-1;i++){
 		gotoxy(tempx+1,i*2+tempy+1);cout<<count++;
	 }
}			
void drawIntro(int width,int length)
{
	SetBGColor(14);
	SetColor(4);
	int x=6,y=23;
	gotoxy(x,y);
	cout<<char(201);
	for(int i=1;i<=width-2;i++){
		cout<<char(205);
	}
	cout<<char(187);gotoxy(x,++y);
	int j=1;
	while(j<=length-2){
	cout<<char(186);
	for(int i=1;i<=width-2;i++){
		cout<<" ";
	}
	cout<<char(186);gotoxy(x,++y);
	j++;
	}
	cout<<char(200);
	for(int i=1;i<=width-2;i++){
		cout<<char(205);
	}
	cout<<char(188);
	gotoxy(68,24);cout<<"GIOI THIEU";
	gotoxy(7,25);cout<<" Chuc nang: ";
	gotoxy(7,38);cout<<"Huong dan:";
	gotoxy(7,39);cout<<"          Nhan Phim Up/Down (len/xuong) de lua chon cac chuc nang khac";
	gotoxy(7,41);cout<<"          Nhan Phim Left/Right (trai/phai) de lua chon cac thanh chuc nang khac";
	gotoxy(10,42);cout<<"Esc : Thoat";
//	gotoxy(50,42);cout<<"F2: Luu";
	SetBGColor(14);
	SetColor(0);
}

//Ham thay doi kich thuoc man hinh
void resizeConsole(int width, int height)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SMALL_RECT windowSize = {0, 0, width, height}; 
	COORD bufferSize = {width, height};
	SetConsoleScreenBufferSize(wHnd, bufferSize);    
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
}
// Ham bat phim ki tu chu. 2, chi chu; , 1,chu & so; 3, chi so.
				//mang char, vi tri, so luong chu, mode
void hitKeyBoard(char t[],int x,int y,int count,int &check){
	fflush(stdin);
	int d=0,ch,tempx=x,dem_cach=0;
	gotoxy(x,y);
	cout<<t;
	d= strlen(t);
	x=x+strlen(t); 
	while(1){
		while (kbhit()){
			if (check == 2){
				ch = getch();
				if(ch == 224){// nut mui ten
        			check = getch();
        			if (check == 77 || check == 80)
        					return ;
        			else (check =2);
				}
				if (ch>=65 && ch<=90){
					if (d<count){
			            dem_cach = 0;
						cout<<char(ch);// in ra
						t[d]=char(ch);// cho vao mang
						d++;// tang stringlength
						x++;// tang vi tri x;
					} 
				}
				if (ch>=97 && ch<=122){
					if (d<count){
			            dem_cach = 0;
						cout<<char(ch);
						t[d]=char(ch);
						d++;
						x++;
					} 
				}
				if (ch == 32){
					if (d<count){
						if (dem_cach == 0 && d!= 0){
							dem_cach = 1;
							cout<<char(ch);
							t[d]=char(ch);
							d++;
							x++;
						}
					}	
				}
				if (ch == 8){
					dem_cach = 0;
					t[d-1] = '\0';
					if (x>tempx){
						d--;
						x--;
					}
					gotoxy(x,y); cout<<" ";
					gotoxy(x,y);
				}
				if (ch==13){
					if (t[d-1] == ' '){
						t[d-1] = '\0';
					}
					return;
				} 
			}
			if (check == 1){
				ch =0;
				ch=getch();
				if(ch == 224){
        			check = getch();
        			if (check == 77 || check == 80)
        					return ;
        			else check=1;
				}
				if (ch>=65 && ch<=90){
					if (d<count){
			            dem_cach = 0;
						cout<<char(ch);
						t[d]=char(ch);
						d++;
						x++;
					} 
				}
				if (ch>=97 && ch<=122){
					if (d<count){
			            dem_cach = 0;
						cout<<char(ch);
						t[d]=char(ch);
						d++;
						x++;
					} 
				}
				if (ch>=48 && ch<=57){
					if (d<count){
			            dem_cach = 0;
						cout<<char(ch);
						t[d]=char(ch);
						d++;
						x++;
					} 
				}
				if (ch == 32){
					if (d<count){
						if (dem_cach == 0 && d!= 0){
							dem_cach = 1;
							cout<<char(ch);
							t[d]=char(ch);
							d++;
							x++;
						}
					}	
				}
				if (ch == 8){
					dem_cach = 0;
					t[d-1] = '\0';
					if (x>tempx){
						d--;
						x--;
					}
					gotoxy(x,y); cout<<" ";
					gotoxy(x,y);
				}
				if (ch==13){
					if (t[d-1] == ' '){
						t[d-1] = '\0';
					}
					return;
				}
			}
			if (check == 3){
				ch=getch();
				if(ch == 224){
					ch =0;
        			check = getch();
        			if (check == 77 || check == 80)
        					return ;
        			else check =3;
				}
				if (ch>=48 && ch<=57){
					if (d<count){
						cout<<char(ch);
						t[d]=char(ch);
						d++;
						x++;
					} 
				}
				if (ch == 8){
					t[d-1] = '\0';
					if (x>tempx){
						d--;
						x--;
					}
					gotoxy(x,y); cout<<" ";
					gotoxy(x,y);
				}
				if (ch==13){
					if (t[d-1] == ' '){
						t[d-1] = '\0';
					}
					return;
				}	
			}	
		}
	}
	
}
// ham bat ki tu chu va so co goi y 
void hitKeyBoard2(char t[],int x,int y,int count,int &check){
	fflush(stdin);
	int d=0,ch,tempx=x,tempy = y,dem_cach=0;
	char temp_t[16] = "";
	gotoxy(x,y);
	cout<<t;
	d= strlen(t);
	x=x+strlen(t);
	while(1){
		if (check == 1 && strlen(t)!= 0 && strcmp(t,temp_t)!=0){
			ShowConsoleCursor(false);
			int dgy = 0,d1 = 0;
			strupr(t);
			strcpy(temp_t,t);
			SetBGColor(3);
			SetColor(1);
			gotoxy(tempx,y+1);cout<<"                                       ";
			gotoxy(tempx,y+2);cout<<"                                       ";
			gotoxy(tempx,y+3);cout<<"                                       ";
			gotoxy(tempx,y+4);cout<<"                                       ";
			gotoxy(tempx,y+5);cout<<"                                       ";
			for(int i=airplane_list.n-1;i>=0;i--){
				if (dgy == 5){
					break;
				}
				char temp_plane_id[16]= "";
				if (airplane_list.airplanes[i]->active == 0) continue;
				strcpy(temp_plane_id,airplane_list.airplanes[i]->plane_id);
				d1 =0;	
				for (int j=0;j<d;j++){
					if (t[j] == temp_plane_id[j]) d1++;
				}
				if (d1 == d){
					dgy++;
					gotoxy(tempx,y+dgy);
					cout<<airplane_list.airplanes[i]->plane_id;
				}
			}
			if (dgy == 0){
					SetColor(1);
					gotoxy(tempx,y+1);cout<<"                                       ";
					gotoxy(tempx,y+2);cout<<"                                       ";
					gotoxy(tempx,y+3);cout<<"                                       ";
					gotoxy(tempx,y+4);cout<<"                                       ";
					gotoxy(tempx,y+5);cout<<"                                       ";
					gotoxy(tempx+8,y+2);
					cout<<"KHONG TIM THAY DU LIEU";
			}
			SetBGColor(11);
			SetColor(0);
		}
		if ((check == 2 || check == 3 || check ==4) && strlen(t)!= 0 && strcmp(t,temp_t)!=0){
			ShowConsoleCursor(false);
			FlightNode* ptr=new FlightNode;
			ptr = head_flist;
			int dgy = 0,d1 = 0;
			strupr(t);
			strcpy(temp_t,t);
			SetBGColor(3);
			SetColor(1);
			gotoxy(tempx-1,y+1);cout<<"                                     ";
			gotoxy(tempx-1,y+2);cout<<"                                     ";
			gotoxy(tempx-1,y+3);cout<<"                                     ";
			gotoxy(tempx-1,y+4);cout<<"                                     ";
			gotoxy(tempx-1,y+5);cout<<"                                     ";
			while(ptr!=NULL){
				if (dgy == 5){
					break;
				}
				char temp_flight_id[16]= "";
				strcpy(temp_flight_id,ptr->flight.flight_id);
				d1 =0;
				for (int j=0;j<d;j++){
					if (t[j] == temp_flight_id[j]) d1++;
				}
				if (d1 == d){
					if (check == 4 && (ptr->flight.status == 1 || ptr->flight.status == 2)){
						dgy++;
						gotoxy(tempx,y+dgy);
						cout<<temp_flight_id;
					}
					if (check == 3 && ptr->flight.status == 1){
						dgy++;
						gotoxy(tempx,y+dgy);
						cout<<temp_flight_id;
					}	
					if (check == 2) {
						dgy++;
						gotoxy(tempx,y+dgy);
						cout<<temp_flight_id;
					}
				}
				ptr=ptr->next;
			}
			if (dgy == 0){
					SetColor(1);
					gotoxy(tempx-1,y+1);cout<<"                                     ";
					gotoxy(tempx-1,y+2);cout<<"                                     ";
					gotoxy(tempx-1,y+3);cout<<"                                     ";
					gotoxy(tempx-1,y+4);cout<<"                                     ";
					gotoxy(tempx-1,y+5);cout<<"                                     ";
					gotoxy(tempx+6,y+2);
					cout<<"KHONG TIM THAY DU LIEU";
			}
			SetBGColor(11);
			SetColor(0);
		}
		
		while(kbhit()){
			gotoxy(x,y);
			ShowConsoleCursor(true);
			ch =0;
			ch=getch();
			if(ch == 224){
        		ch = getch();
        		ch=0; 
			}
			if (ch>=65 && ch<=90){
				if (d<count){
			        dem_cach = 0;
					cout<<char(ch);
					t[d]=char(ch);
					d++;
					x++;
				} 
			}
			if (ch>=97 && ch<=122){
				if (d<count){
			        dem_cach = 0;
					cout<<char(ch);
					t[d]=char(ch);
					d++;
					x++;
				} 
			}
			if (ch>=48 && ch<=57){
				if (d<count){
			        dem_cach = 0;
					cout<<char(ch);
					t[d]=char(ch);
					d++;
					x++;
				} 
			}
			if (ch == 32){
				if (d<count){
					if (dem_cach == 0 && d!= 0){
						dem_cach = 1;
						cout<<char(ch);
						t[d]=char(ch);
						d++;
						x++;
					}
				}	
			}
			if (ch == 8){
				dem_cach = 0;
				t[d-1] = '\0';
				if (x>tempx){
					d--;
					x--;
				}
				gotoxy(x,y); cout<<" ";
				gotoxy(x,y);
			}
			if (ch==13){
				if (t[d-1] == ' '){
					t[d-1] = '\0';
				}
				return;
			}
		}
		
	}
}
//Ham bat phim ki tu so
void hitNumbers(int &temp_num,int x,int y,int count,int &check){
	//distance and chardistance
	int d=0,ch = 0,cd=0,tempx=x,t=temp_num;
	while(temp_num > 0){
		temp_num /= 10;
		cd ++;
	}
	temp_num = t;
	gotoxy(x,y);
	if (temp_num != 0 ) cout<<temp_num;
	x += cd;
	d = cd;
	while(1){
		while (kbhit()){
			ch = 0;
			ch=getch();
			if(ch == 224){
        		check = getch();
        		if (check == 77 || check == 80) // xuong hoac sang phai
        				return ;
			}
			if (ch >= 48 && ch<= 57){
				if (d<count){
					cout<<ch-48;
					temp_num = temp_num*10+ch-48;// tang len mot don vi roi cong them so.
					d++;
					x++;
				}
			} 
			if (ch == 8){
				temp_num = temp_num/10; //giam di 1 don vi
				if (x>tempx){
					d--;
					x--;
				}
				gotoxy(x,y); cout<<" ";
				gotoxy(x,y);
			}
			if (ch==13) return; // return;
		}
	}
}
void hitNumbers2(int &temp_num,int x,int y,int count,int check,TicketList &t_list){
	int d=0,ch = 0,cd=0,tempx=x,t=temp_num,d1 =0;
	while(temp_num > 0){
		temp_num /= 10;
		cd ++;
	}
	temp_num = t;
	gotoxy(x,y);
	if (temp_num != 0 ) cout<<temp_num;
	x += cd;
	d = cd;
	while(1){
		if (check == 1 && temp_num != 0 && d1 != 0){
			d1=0;
			drawRectangle(tempx,y+4,32,5);
			ShowConsoleCursor(false);
			if(temp_num > t_list.limit){
				//Khong ton tai so ghe nay trong chuyen bay
				SetBGColor(4);
				SetColor(15);
				gotoxy(tempx+1,y+5);cout<<"   KHONG TON TAI SO GHE NAY   ";
				gotoxy(tempx+1,y+6);cout<<"       TRONG CHUYEN BAY       ";
				gotoxy(tempx+1,y+7);cout<<"                              ";
				gotoxy(tempx+8,y+7);cout<<"0 < So ghe <= "<<t_list.limit;
				SetBGColor(11);
				SetColor(0);
				gotoxy(x,y);
			}
			else if(checkEmpty(t_list,temp_num) == true){//trong ghe
				SetBGColor(10);
				SetColor(0);
				gotoxy(tempx+1,y+5);cout<<"                              ";
				gotoxy(tempx+1,y+6);cout<<"                              ";
				gotoxy(tempx+1,y+7);cout<<"                              ";
				gotoxy(tempx+8,y+6);cout<<"So ghe hop le !";
				SetBGColor(11);
				gotoxy(x,y);
			}
			else if(checkEmpty(t_list,temp_num) == false){
				SetBGColor(4);
				SetColor(15);
				gotoxy(tempx+1,y+5);cout<<"                              ";
				gotoxy(tempx+1,y+6);cout<<"                              ";
				gotoxy(tempx+1,y+7);cout<<"                              ";
				gotoxy(tempx+3,y+6);cout<<"Ve nay da co nguoi dat !";
				SetBGColor(11);
				SetColor(0);
				gotoxy(x,y);
			}
		}
		while (kbhit()){
			ShowConsoleCursor(true);
			ch = 0,d1 = 1;
			ch=getch();
			if(ch == 224){
        		ch = getch();
        		ch = 0; 
			}
			if (ch >= 48 && ch<= 57){
				if (d<count){
					cout<<ch-48;
					temp_num = temp_num*10+ch-48;
					d++;
					x++;
				}
			} 
			if (ch == 8){
				temp_num = temp_num/10;
				if (x>tempx){
					d--;
					x--;
				}
				gotoxy(x,y); cout<<" ";
				gotoxy(x,y);
			}
			if (ch==13) return;
		}
	}
}
//Ham chuyen mau mot doan STRING s
void changeColor(int x,int y,int bg_color,int text_color,string s){
	gotoxy(x,y);
    SetBGColor(bg_color);
    SetColor(text_color);
    cout<<s;
SetBGColor(14);
SetColor(0);
gotoxy(x,y);
}

//Ham nhan phim khi nhap
int hitKey(){
	int c = getch();
    if(c == 224){
        c = getch();
        return c;
	}else return c;
}

//Ham ve thanh cong cu 
void drawToolBar(){
	gotoxy(0,1);	
	SetBGColor(14);
	SetColor(0);
	for (int i=1;i<=3;i++){
		cout<<char(186);
		for (int j=1;j<=148;j++){
			if (i==1){
				if (j==4 || j==40 || j==78 || j==114){
					SetColor(0);
					SetBGColor(10);
					if (j==4)cout<<"      QUAN LY MAY BAY          ";
					if (j==40)cout<<"      QUAN LY CHUYEN BAY       ";
					if (j==78)cout<<"         DAT / HUY VE          ";
					if (j==114)cout<<"       THONG KE DU LIEU        ";
					j=j+30;
				}else{
					SetBGColor(14);
					cout<<" ";
				}
			}else{
					SetBGColor(14);
					cout<<" ";
			}
		}
		if (i!=3){
			SetBGColor(14);
			cout<<char(186);
			cout<<endl;
		}
	}
}

//Ham xoa bang nhap du lieu
void deleteTable(){
	gotoxy(0,5);
	SetBGColor(14);
	SetColor(0);
	for(int i=5;i<=41;i++)
	 	{
	 		cout<<char(186);
	 		for (int j=1;j<=148;j++)
	 			{
	 				cout<<" ";
				 }
			cout<<endl;
		 }	 
}

void drawTool(int x,string s){
	SetBGColor(4); SetColor(0);
	gotoxy(x,1);
	cout<<char(186);
	changeColor(x+1,1,14,0,s);
	SetBGColor(4); SetColor(0); 
	gotoxy(x+30,1); cout<<char(186);
	gotoxy(x,2);
	cout<<char(200);  for(int v=1;v<=29;v++) cout<<char(205);    cout<<char(188);
}

//Ham ve Giao dien man hinh chinh 
void mainDisplay(){
	//ve duong thang tren 
	SetBGColor(14);
	SetColor(0);
 	cout<<char(201);
	for(int i=1;i<=148;i++) cout<<char(205);
	cout<<char(187);
	cout<<endl;
	//ve man hinh trung tam 
	for (int i=1;i<=42;i++){
		cout<<char(186);
		for(int j=1;j<=148;j++){
				if (i==1){
					drawToolBar();
					j=148;
					i=3;
		    	}else{
		    		cout<<" ";
				}

		}
		SetColor(0);
		SetBGColor(14);
		cout<<char(186);
		cout<<endl;
	}
	//ve duong thang duoi
	cout<<char(200);
	for(int i=1;i<=148;i++) cout<<char(205);
	cout<<char(188);
	cout<<endl;
}

//IN danh sach chuc nang
void printFunction(int x,int n,string s[]){
	if (x==4 || x==78)
	{
		for (int i=0;i<n;i++){
			drawRectangle(x,3*i+3,31,3);
			changeColor(x+1,3*i+4,11,0,s[i]);
		}
	}
	if (x==40){
		for (int i=0;i<n;i++){
			if (i==1){
				drawRectangle(x,3*i+3,31,4);
				changeColor(x+1,3*i+4,11,0,s[i]);
				i++;
				changeColor(x+1,3*(i-1)+5,11,0,s[i]);
			}else if (i==3 || i==4){
				drawRectangle(x,3*(i-1)+4,31,3);
				changeColor(x+1,3*(i-1)+5,11,0,s[i]);
			}else{
				drawRectangle(x,i+3,31,3);
				changeColor(x+1,i+4,11,0,s[i]);
			}
		}
	}
	if (x==114){
		for (int i=0;i<n;i++){
			if (i==1 || i==3 || i==5){
				drawRectangle(x,2*i+4,31,4);
				changeColor(x+1,2*i+5,11,0,s[i]);
				i++;
				changeColor(x+1,2*(i-1)+6,11,0,s[i]);
			}
			else if (i==7){
				drawRectangle(x,2*i+4,31,3);
				changeColor(x+1,2*i+5,11,0,s[i]);
			}else if (i==0){
				drawRectangle(x,i+3,31,3);
				changeColor(x+1,i+4,11,0,s[i]);	
			}
		}
	}
}
//Ham xoa thanh cong cu 
void deleteFunction(int x,int n,string s){
	gotoxy(x,1);
	SetBGColor(10);
	cout<<" "<<s<<" ";
	SetBGColor(14);
	for (int i=2;i<=n;i++){
		gotoxy(x,i);
		cout<<"                               ";
	}
}

// Ham gioi thieu chuc nang 
void deleteIntro(int t){
	if (t==1){
		for(int i=23;i<=42;i++){
			gotoxy(6,i);
			for (int j=1;j<=138;j++) cout<<" ";
		}
	}
	if (t==0){
		for(int i=26;i<=37;i++){
			gotoxy(7,i);
			for (int j=1;j<=136;j++) cout<<" ";
		}
	}	
}
void intro(int i){
	deleteIntro(0);
	SetColor(4);
	if (i==1){
		gotoxy(7,26);cout<<"           Them mot may bay vao danh sach may bay ";
		gotoxy(7,27);cout<<"(bao gom cac thong tin nhu: so hieu may bay, loai may bay , so cho) ";
		gotoxy(7,28); cout<<"*Luu y : -So hieu may bay khong duoc trung voi cac so hieu may bay trong danh sach may bay";
		gotoxy(7,30);cout<<" Danh sach may bay hien co : ["<<airplane_list.n<<"]";
	}
	if (i==2){
		gotoxy(7,26);cout<<"            Xoa mot may bay khoi danh sach may bay ";
		gotoxy(7,27);cout<<" (ban can so hieu may bay hien dang co trong danh sach may bay de xoa) ";
		gotoxy(7,28);cout<<" *Luu y: -Neu nhap so hieu may bay khong co trong danh sach thi se khong thuc hien duoc lenh";
		gotoxy(7,30);cout<<" Danh sach may bay hien co : ["<<airplane_list.n<<"]";
	}
	if (i==3){
		gotoxy(7,26);cout<<"            Hieu chinh mot may bay trong danh sach may bay ";
		gotoxy(7,27);cout<<" (ban can so hieu may bay hien dang co trong danh sach may bay de hieu chinh) ";
		gotoxy(7,28);cout<<" *Luu y: -Neu nhap so hieu may bay khong co trong danh sach thi se khong thuc hien duoc lenh";
		gotoxy(7,29);cout<<"        -Ban chi thay doi duoc loai may bay va so cho cua may bay";
		gotoxy(7,30);cout<<" Danh sach may bay hien co : ["<<airplane_list.n<<"]";
	}
	if (i==4){
		gotoxy(7,26);cout<<"           Them mot chuyen bay vao danh sach chuyen bay ";
		gotoxy(7,27);cout<<"(bao gom cac thong tin nhu: Ma chuyen bay, so hieu may bay,  Ngay gio khoi hanh, san bay den , *trang thai) ";
		gotoxy(7,28);cout<<"*trang thai bao gom : 0: huy chuyen, 1: con ve, 2: het ve, 3: hoan tat ";
		gotoxy(7,30); cout<<"*Luu y : -Chi them chuyen bay khi danh sach may bay co it nhat 1 may bay";
		gotoxy(7,31); cout<<"        -Ma chuyen bay khong duoc trung voi cac ma chuyen bay trong danh sach chuyen bay";
		gotoxy(7,32); cout<<"        -So hieu may bay cua chuyen bay phai ton tai trong danh sach may bay";
	}
	if (i==41){
		gotoxy(7,26);cout<<"           In Danh sach cac chuyen bay co trong du lieu chuyen bay ";
		gotoxy(7,27);cout<<"(bao gom cac thong tin nhu: Ma chuyen bay, so hieu may bay,  Ngay gio khoi hanh, san bay den , *trang thai) ";
		gotoxy(7,28);cout<<"*trang thai bao gom : 0: huy chuyen, 1: con ve, 2: het ve, 3: hoan tat ";
		gotoxy(7,30); cout<<"*Luu y :";
//		gotoxy(7,31); cout<<"        -Ma chuyen bay khong duoc trung voi cac ma chuyen bay trong danh sach chuyen bay";
//		gotoxy(7,32); cout<<"        -So hieu may bay cua chuyen bay phai ton tai trong danh sach may bay";
	}
	if (i==5){
		gotoxy(7,26);cout<<"            Hieu chinh ngay gio mot chuyen bay trong danh sach chuyen bay ";
		gotoxy(7,27);cout<<" (ban can ma chuyen bay va so hieu may bay hien dang co trong danh sach may ba de hieu chinh) ";
		gotoxy(7,29);cout<<" *Luu y: -Neu nhap ma chuyen bay khong co trong danh sach thi se khong thuc hien duoc lenh";
	}
	if (i==6){
		gotoxy(7,26);cout<<"            Huy mot chuyen bay ";
		gotoxy(7,27);cout<<" (ban can ma chuyen bay hien dang co trong danh sach chuyen bay de huy) ";
		gotoxy(7,29);cout<<" *Luu y: -Neu nhap ma chuyen bay khong co trong danh sach thi se khong thuc hien duoc lenh";
	}
	if (i==7){
		gotoxy(7,26);cout<<"             Cho phep dat ve tren 1 chuyen bay";
		gotoxy(7,27);cout<<"			  (Ban can co so cmnd de dang ky)";
		gotoxy(7,29); cout<<"*Luu y: -Tren 1 chuyen bay, moi hanh khach chi duoc mua 1 ve.";
		int y=26;
		gotoxy(96,y);cout<<"        Mo phong so do cho ngoi";
		gotoxy(96,y+1);cout<<" -----------------------------------";
		gotoxy(96,y+2);cout<<char(186)<<" | 1 || 2 || 3 |...| 8 || 9 ||10 | "<<char(186);
		gotoxy(96,y+3);cout<<char(176)<<" |11 ||12 ||13 |...|18 ||19 ||20 | "<<char(176);
		gotoxy(96,y+4);cout<<char(186)<<" |21 ||22 ||23 |...|28 ||29 ||30 | "<<char(186);
		gotoxy(96,y+5);cout<<char(176)<<" |31 ||32 ||33 |...|38 ||39 ||40 | "<<char(176);
		gotoxy(96,y+6);cout<<char(186)<<" |41 ||42 ||43 |...|48 ||49 ||50 | "<<char(186);
		gotoxy(96,y+7);cout<<char(176)<<" |51 ||52 ||53 |...|58 ||59 ||60 | "<<char(176);
		gotoxy(96,y+8);cout<<char(186)<<"                 .                 "<<char(186);
	    gotoxy(96,y+9);cout<<char(176)<<"                 .                 "<<char(176);
	   gotoxy(96,y+10);cout<<char(186)<<" |281||282||283|...|288||289||290| "<<char(186);
	   gotoxy(96,y+11);cout<<char(176)<<" |291||292||293|...|298||299||300| "<<char(176);
	}
	if (i==8){
		gotoxy(7,26);cout<<"             Cho phep huy ve da dat cua hanh khach";
		gotoxy(7,27);cout<<"			  (Ban can co so cmnd de huy ve)";
		gotoxy(7,29); cout<<"*Luu y:";
	}
	if (i==9){
		gotoxy(7,26);cout<<"             In danh sach cac hanh khach thuoc 1 chuyen bay dua vao ma chuyen bay";
		gotoxy(7,27);cout<<"(Bao gom cac thong tin nhu: STT, So ve, So cmnd, Ho ten, Phai)";
		gotoxy(7,29); cout<<"*Luu y:";
	}
	if (i==91){
		gotoxy(7,26);cout<<"             In du lieu tat ca hanh khach ";
		gotoxy(7,27);cout<<"(Bao gom cac thong tin nhu: So cmnd, Ho ten, Phai)";
		gotoxy(7,29); cout<<"*Luu y:";
	}
	if (i==10){
		gotoxy(7,26);cout<<"             In danh sach cac chuyen bay khoi hanh trong ngay dd/mm/yyyy den noi XXXX   ";
		gotoxy(7,27);cout<<"(Danh sach cho biet cu the so luong cac ve con trong va gio khoi hanh)";
		gotoxy(7,29); cout<<"*Luu y:";
	}
	if (i==11){
		gotoxy(7,26);cout<<"             In danh sach cac ve con trong cua 1 chuyen bay co ma chuyen bay la X";
		gotoxy(7,27);cout<<"(Danh sach cho biet cu the so luong cac ve con trong cua chuyen bay X)";
		gotoxy(7,29); cout<<"*Luu y:";
	}
	if (i==12){
		gotoxy(7,26);cout<<"             Thong ke so luot thuc hien chuyen bay cua tung may bay theo thu tu so luot thuc hien giam dan";
		gotoxy(7,27);cout<<"(Danh sach cho biet cu the so luot thuc hien cua cac chuyen bay)";
		gotoxy(7,29); cout<<"*Luu y:";
	}
	SetColor(0); 
}

//Ham viet hoa chu cai dau va sau khoang trang
void Uppercase(char t[]){
	strlwr(t);
	t[0] = toupper(t[0]);
	for (int i=1;i<=strlen(t);i++){
		if (t[i]==' '){
			t[i+1] = toupper(t[i+1]);
		}
	}
}
//Ham loading 
void Loading(int x,int y){
	deleteTable();
//	gotoxy(x+25,y+7); cout<<"LOADING...";
	gotoxy(x+25,y+7); cout<<"THONG BAO";
	drawRectangle(x+10,y+8,40,3);
	SetBGColor(10);
	SetColor(15);
	gotoxy(x+11,y+9); 
	int j=1; 
//	while (j!=39){
//		    while(kbhit()) getch();
//			cout<<" ";
//			if (j>30 && j<=35) Sleep(50);
//			else Sleep(20);
//			j++;
//		}
	for (;j<=38;j++){
		cout<<" ";
	}
	Sleep(400);
} 
//////////////////////////////////////////////Phan danh sach may bay////////////////////////////////////////////////////////////////////

//Ham tim may bay khong can ma may bay
int searchPlaneId( AirplaneList &airplane_list,int x,int y){
	int check = 1;
	char temp_plane_id[16] = "";
	gotoxy(x+6,y+5);cout<<"So Hieu MB :                                        ";
	do{
		hitKeyBoard2(temp_plane_id,x+19,y+5,15,check);
	} while(strlen(temp_plane_id) == 0 );
		strupr(temp_plane_id);
		
	for(int i=0;i<airplane_list.n;i++){
		if(strcmp(airplane_list.airplanes[i]->plane_id,temp_plane_id)==0){
			return i;
		}
	}
	return -1;
}
//Ham tim may bay co ma may bay  
int searchPlaneId( AirplaneList &airplane_list, char temp_plane_id[]){
	for(int i=0;i<airplane_list.n;i++){
		if(strcmp(airplane_list.airplanes[i]->plane_id,temp_plane_id)==0){
			return i;
		}
	}
	return -1;
}



//Ham them may bay vao danh sach
void addNewAirplane(AirplaneList &airplane_list){
	int x=42,y=12,check; 
	char temp_plane_id[16] = "";
	char temp_airplane_type[41] = "";
	int temp_seats = 0;
	ShowConsoleCursor(true);
    drawRectangle(x,y,64,19);
    drawRectangle(x+5,y+5,54,3);
    drawRectangle(x+5,y+9,54,3);
    drawRectangle(x+5,y+14,54,3);
    SetBGColor(14);
    gotoxy(x+7,y+2) ;cout<<" [NHAP DU LIEU MAY BAY BAN MUON THEM VAO DANH SACH] ";
    SetBGColor(11);
    SetColor(0);
    gotoxy(x+6,y+6);cout<<"So Hieu MB :                                        ";
    gotoxy(x+6,y+10);cout<<"Loai MB    :                                        ";
    gotoxy(x+6,y+15);cout<<"So cho     :                                        ";
	fflush(stdin);
			
	do{
	  	do{
	  		check =1;
	  		hitKeyBoard(temp_plane_id,x+19,y+6,15,check);
		  }while(strlen(temp_plane_id) == 0);
		  	strupr(temp_plane_id);  
		if(searchPlaneId(airplane_list,temp_plane_id)!=-1){
			MessageBox(NULL,"So hieu May bay da ton tai, nhap lai !","THONG BAO",MB_ICONHAND|MB_OK);
			while (kbhit()) getch();
		}
	}while(searchPlaneId(airplane_list,temp_plane_id)!=-1); //lap den khi khong trung ma may bay
	
	do{
		check =1;
		hitKeyBoard(temp_airplane_type,x+19,y+10,40,check); // nhap loai may bay
	}while(strlen(temp_airplane_type) == 0);
	 	strupr(temp_airplane_type);
	 	
	do{
		gotoxy(x+19,y+15);cout<<"   ";
		check = 0;
		temp_seats = 20;
		hitNumbers(temp_seats,x+19,y+15,3,check); // nhap so cho
		if (temp_seats < 20 || temp_seats > 300 ){
			MessageBox(NULL,"So cho phai nhieu hon hoac bang 20 va nho hon hoac bang 300 !\n\t( 20 <= So cho <= 300 )","THONG BAO",MB_ICONHAND|MB_OK);
			while (kbhit()) getch();
		}
	}while(temp_seats == 0 || temp_seats < 20 || temp_seats > 300);
	 	
	Airplane* airplane=new Airplane; // tao moi
	
	//gan gia tri
	strcpy(airplane->plane_id,temp_plane_id);
	strcpy(airplane->plane_type,temp_airplane_type);
	airplane->seats=temp_seats;
	airplane_list.airplanes[airplane_list.n]=airplane;
	airplane_list.n++;
	
	ShowConsoleCursor(false);
	deleteTable();
}

//ham xoa may bay
void deleteAirplane(AirplaneList &airplane_list){
	int x=42,y=12;
	drawRectangle(x,y,64,18);
	drawRectangle(x+5,y+4,54,3);
	SetBGColor(14);
	gotoxy(x+12,y+2) ;cout<<" [NHAP VAO SO HIEU MAY BAY BAN MUON XOA] ";
	SetBGColor(11);
	ShowConsoleCursor(true);
	int result=searchPlaneId(airplane_list,x,y);
	if(result==-1) {
		MessageBox(NULL,"MAY BAY KHONG TON TAI !!","THONG BAO",MB_ICONWARNING|MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		deleteTable();
		return;
	}
	int times=verifyAirplane(airplane_list.airplanes[result]->plane_id);
	//xoa may bay thi phai dang khong phai thuc hien chuyen bay tuc la(huy chuyen hoac hoan tat hoac chua thuc hien chuyen nao)
	 
	if(times==0){
		if(verifyAirplaneBoolean(airplane_list.airplanes[result]->plane_id) )
		{
			for(int i=result;i<airplane_list.n-1;i++){
				*airplane_list.airplanes[i]=*airplane_list.airplanes[i+1];
			}
		airplane_list.n--;
		ShowConsoleCursor(false);
		deleteTable();
		Loading(x,y); 
		gotoxy(x+11,y+9); cout<<"           XOA THANH CONG !";
		Sleep(500);
		deleteTable();
		
		return;
		}
	else if (airplane_list.airplanes[result]->active == true){
		airplane_list.airplanes[result]->active=false;
		ShowConsoleCursor(false);
		deleteTable();
		Loading(x,y); 
		gotoxy(x+11,y+9); cout<<"           XOA THANH CONG !";
		Sleep(500);
		deleteTable();
		return;
	}
	else if (airplane_list.airplanes[result]->active == false){
		ShowConsoleCursor(false);
		MessageBox(NULL,"May bay da bi xoa tu truoc","THONG BAO",MB_ICONHAND|MB_OK);
		while (kbhit()) getch();
		deleteTable();
		return;
	}
	}
	
	else if(times!=0){
		ShowConsoleCursor(false);
		MessageBox(NULL,"Khong the xoa vi May bay nay con chuyen bay phai thuc hien!","THONG BAO",MB_ICONHAND|MB_OK);
		while (kbhit()) getch();
		deleteTable();
		return;
	}
//	else if (dsmb.data[result]->active == true){
//		dsmb.data[result]->active=false;
//		ShowConsoleCursor(false);
//		Xoa_khunhap();
//		Loading(x,y); 
//		gotoxy(x+11,y+9); cout<<"           XOA THANH CONG !";
//		Sleep(500);
//		Xoa_khunhap();
//		return;
//	}
//	else if (dsmb.data[result]->active == false){
//		ShowConsoleCursor(false);
//		MessageBox(NULL,"May bay da bi xoa tu truoc","THONG BAO",MB_ICONHAND|MB_OK);
//		while (kbhit()) getch();
//		Xoa_khunhap();
//		return;
//	}
}


//Ham hieu chinh may bay
void editAirplane(AirplaneList &airplane_list){
	int x=42 ,y=12,check ;
	drawRectangle(x,y,64,10);
    drawRectangle(x+5,y+4,54,3);
	SetBGColor(14);
	gotoxy(x+10,y+2) ;cout<<" [NHHAP VAO SO HIEU MAY BAY BAN MUON HIEU CHINH] ";
	ShowConsoleCursor(true);
	SetBGColor(11); 
	int result=searchPlaneId(airplane_list,x,y);
	if(result==-1){
		MessageBox(NULL,"MAY BAY KHONG TON TAI !!","THONG BAO",MB_ICONWARNING|MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		deleteTable();
	}
	else if(airplane_list.airplanes[result]->active==0){
		airplane_list.airplanes[result]->active = 1;
		MessageBox(NULL,"MAY BAY KHONG CON HOAT DONG, KHONG THE HIEU CHINH!","THONG BAO",MB_ICONWARNING|MB_OK);
		while (kbhit()) getch();
		ShowConsoleCursor(false);
		deleteTable();
	}
	else{
		SetBGColor(14); 
		drawRectangle(x,y,64,18);
		drawRectangle(x+5,y+5,54,3);
    	drawRectangle(x+5,y+9,54,3);
    	drawRectangle(x+5,y+14,54,3);
    	SetBGColor(14);
    	gotoxy(x+10,y+2) ;cout<<"[NHHAP VAO DU LIEU MAY BAY BAN MUON HIEU CHINH]";
    	SetBGColor(11);
    	SetColor(0);
    	char temp_plane_id[15];
		char temp_plane_type[40];
		int temp_seats = airplane_list.airplanes[result]->seats;
		strcpy(temp_plane_type,airplane_list.airplanes[result]->plane_type);
    	gotoxy(x+6,y+6);cout<<"So Hieu MB :                                        ";
   		gotoxy(x+6,y+10);cout<<"Loai MB    :                                        ";
    	gotoxy(x+6,y+15);cout<<"So cho     :                                        ";
    	gotoxy(x+19,y+6);cout<<airplane_list.airplanes[result]->plane_id;
    	gotoxy(x+19,y+10);cout<<airplane_list.airplanes[result]->plane_type;
    	gotoxy(x+19,y+15);cout<<airplane_list.airplanes[result]->seats;
    	fflush(stdin);

    		do{
   				check =1;
   				hitKeyBoard(temp_plane_type,x+19,y+10,40,check);
			}while(strlen(temp_plane_type) == 0);
				strupr(temp_plane_type);
			while(1){
				do{
					temp_seats = airplane_list.airplanes[result]->seats;
					check =0;
					gotoxy(x+19,y+15); cout<<"    ";
					temp_seats = airplane_list.airplanes[result]->seats;
					hitNumbers(temp_seats,x+19,y+15,4,check);
				}while(temp_seats == 0 || temp_seats <20 || temp_seats >300);
				if (verifyAirplaneBoolean(airplane_list.airplanes[result]->plane_id) == false && temp_seats!=airplane_list.airplanes[result]->seats){
					MessageBox(NULL,"May bay da duoc dua vao danh sach chuyen bay \n\tnen khong the thay doi so cho","THONG BAO",MB_ICONHAND|MB_OK);
					while (kbhit()) getch();
				}else break;
			}
			
		strcpy(airplane_list.airplanes[result]->plane_type,temp_plane_type);
		airplane_list.airplanes[result]->seats=temp_seats; // so cho
		ShowConsoleCursor(false);
		Loading(x,y);
		gotoxy(x+11,y+9); cout<<"        CHINH SUA THANH CONG !";
		Sleep(500);
		deleteTable();
    }
}

int verifyAirplane(char temp_plane_id[]){
	FlightNode* ptr=new FlightNode;
	ptr= head_flist;
	int count=0;
	while(ptr!=NULL){
		if(ptr->flight.ticket_list.booked== ptr->flight.ticket_list.limit && ptr->flight.status!=0){
			ptr->flight.status=2;
		}
		
		if(checkDepartTime(ptr->flight.depart_time)==false && ptr->flight.status!=0){
			ptr->flight.status=3;
		}
		if(strcmp(ptr->flight.plane_id,temp_plane_id)==0 && ptr->flight.status!=3 && ptr->flight.status!=0){
			count++;
		}
		ptr=ptr->next;
	}
	return count;
}
bool verifyAirplaneBoolean(char temp_plane_id[]){
	FlightNode* ptr;
	ptr = head_flist;
	while(ptr!=NULL){
		if(strcmp(ptr->flight.plane_id,temp_plane_id)==0){
			return false;
		}
		ptr=ptr->next;
	}
	return true;
}

//////////////////////////////////////////////Chuyen bay//////////////////////////////////////////////////////////////////////////////////
//override check_exit
flight_ptr searchNode(flight_ptr &head,char temp_flight_id[]){	
	FlightNode* ptr= head;
	while(ptr!=NULL){
		if(strcmp(ptr->flight.flight_id,temp_flight_id)==0){
			return ptr;
		}
		ptr=ptr->next;
	}
	return NULL;
}


bool checkFlightDecent(flight_ptr &head,char temp_flight_id[],DateTime dt){
	
	
	FlightNode* ptr=head;
	
	
	
	while(ptr!=NULL){
	if(strcmp(ptr->flight.plane_id,temp_flight_id)==0 && ptr->flight.status!=0){
		if(ptr->flight.depart_time.day==dt.day && ptr->flight.depart_time.mon==dt.mon
		&& ptr->flight.depart_time.year==dt.year ){
			
			if(ptr->flight.depart_time.hour!=dt.hour){
				int time=abs((ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)
				-(dt.hour*60+dt.min));
				if(time<120){ // nho hon 2 tieng hoac lon hon 2 tieng ||
					return false;
				}
			}
			
			else if(ptr->flight.depart_time.hour==dt.hour) return false;				
		}
			
		else if(abs(ptr->flight.depart_time.day-dt.day)==1 && ptr->flight.depart_time.mon==dt.mon
		&& ptr->flight.depart_time.year==dt.year){
			
			//cach nhau 1 ngay, cb truoc ptr->flight
			if(ptr->flight.depart_time.day>dt.day){
				int time=(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)
				+(1440-(dt.hour*60+dt.min)); //ngay tiep
			   if(time<120) return false;
			}
			
			//cach nhau 1 ngay, cb sau ptr->flight
			else if(dt.day>ptr->flight.depart_time.day){
				int time=(1440-(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min))
				+(dt.hour*60+dt.min); //ngay sau
				if(time<120) return false;
			}
        }
        //cach nhau 1 thang
    else if(ptr->flight.depart_time.year==dt.year && abs(ptr->flight.depart_time.mon-dt.mon)==1 ){
    			//dau thang 																		cuoi thang
		if((ptr->flight.depart_time.day==day[ptr->flight.depart_time.mon] && dt.day==1) || (dt.day==day[dt.mon] && ptr->flight.depart_time.day==1)){
			if(ptr->flight.depart_time.mon > dt.mon){
					//ra ngay tiep theo - ngay hien tai <120 p thi
				if((ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)+(1440-(dt.hour*60+dt.min))<120){
				return false;
				}
			}
			else{
				if((dt.hour*60+dt.min)+(1440-(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min))<120){
				return false;
			}
		}
	}
	}
	else if(abs(ptr->flight.depart_time.year-dt.year)==1 ){
		if(ptr->flight.depart_time.day==31 && ptr->flight.depart_time.mon==12 && dt.day==1 && dt.mon==1){
			//thoi gian ngay hom do + thoi gian con lai ke tu luc cat canh <120
			if((dt.hour*60+dt.min)+(1440-(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min))<120){
				return false;
		}
	}
		else if(ptr->flight.depart_time.day==1 && ptr->flight.depart_time.mon==1 && dt.day==31 && dt.mon==12){
			// thoi gian cat canh + so phut con lai cua ngay hom do <120
			if((ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)+(1440-(dt.hour*60+dt.min))<120){
				return false;
				}
		}

	}

	}
		ptr=ptr->next;

	}
		return true;
}
bool checkFlightDecentVersion2(flight_ptr &head,flight_ptr &edit_node,char temp_plane_id[],DateTime dt){
	
	
	FlightNode* ptr = head;
	
	
	
	while(ptr!=NULL){
	if(strcmp(ptr->flight.plane_id,temp_plane_id)==0 && ptr->flight.status!=0 && ptr!=edit_node){
		if(ptr->flight.depart_time.day==dt.day && ptr->flight.depart_time.mon==dt.mon
		&& ptr->flight.depart_time.year==dt.year ){
			
			if(ptr->flight.depart_time.hour!=dt.hour){
				int time=abs((ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)
				-(dt.hour*60+dt.min));
				if(time<120){
					return false;
				}
			}
			
			else if(ptr->flight.depart_time.hour==dt.hour) return false;				
		}
			
		else if(abs(ptr->flight.depart_time.day-dt.day)==1 && ptr->flight.depart_time.mon==dt.mon
		&& ptr->flight.depart_time.year==dt.year){
			
			//cach nhau 1 ngay, cb truoc ptr->data
			if(ptr->flight.depart_time.day>dt.day){
				int time=(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)
				+(1440-(dt.hour*60+dt.min));
			   if(time<120) return false;
			}
			
			//cach nhau 1 ngay, cb sau ptr->data
			else if(dt.day>ptr->flight.depart_time.day){
				int time=(1440-(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min))
				+(dt.hour*60+dt.min);
				if(time<120) return false;
			}
        }
    else if(ptr->flight.depart_time.year==dt.year && abs(ptr->flight.depart_time.mon-dt.mon)==1 ){
    	
		if((ptr->flight.depart_time.day==day[ptr->flight.depart_time.mon] && dt.day==1) || (dt.day==day[dt.mon] && ptr->flight.depart_time.day==1)){
			if(ptr->flight.depart_time.mon>dt.mon){
				if((ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)+(1440-(dt.hour*60+dt.min))<120){
				return false;
				}
			}
			else{
				if((dt.hour*60+dt.min)+(1440-(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min))<120){
				return false;
			}
		}
	}
	}
	else if(abs(ptr->flight.depart_time.year-dt.year)==1 ){
		if(ptr->flight.depart_time.day==31 && ptr->flight.depart_time.mon==12 && dt.day==1 && dt.mon==1){
			if((dt.hour*60+dt.min)+(1440-(ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min))<120){
				return false;
		}
	}
		else if(ptr->flight.depart_time.day==1 && ptr->flight.depart_time.mon==1 && dt.day==31 && dt.mon==12){
			if((ptr->flight.depart_time.hour*60+ptr->flight.depart_time.min)+(1440-(dt.hour*60+dt.min))<120){
				return false;
				}
		}

	}

	}
		ptr=ptr->next;

	}
		return true;
}
//kiem tra co cung thoi gian hoac lech nhau 30p.
bool isTheSameTime(DateTime dt1,DateTime dt2){
	if(dt1.day==dt2.day){
		if(dt1.year==dt2.year && dt1.mon==dt2.mon &&dt1.hour==dt2.hour && abs(dt1.min-dt2.min)<=30){
			return true;
		}
	}
	else if(dt1.year==dt2.year && dt1.mon==dt2.mon && abs(dt1.day-dt2.day)==1){
		if(dt1.day>dt2.day){
			if((dt1.hour*60+dt1.min)+(1440-(dt2.hour*60+dt2.min))<=30){
				return true;
			}
		}
		else if(dt1.day<dt2.day){
				if((dt2.hour*60+dt2.min)+(1440-(dt1.hour*60+dt1.min))<=30){
				return true;
			}
		}
	}
	else if(dt1.year==dt2.year && abs(dt1.mon-dt2.mon)==1 ){
		if(dt1.day==day[dt1.mon] && dt2.day==1 || dt2.day==day[dt2.mon] && dt1.day==1){
			if(dt1.mon>dt2.mon){
				if((dt1.hour*60+dt1.min)+(1440-(dt2.hour*60+dt2.min))<=30){
				return true;
				}
			}
			else{
				if((dt2.hour*60+dt2.min)+(1440-(dt1.hour*60+dt1.min))<=30){
				return true;
			}
		}
	}
	}
	else if(abs(dt1.year-dt2.year)==1 ){
		if(dt1.day==31 && dt1.mon==12 && dt2.day==1 && dt2.mon==1){
			if((dt2.hour*60+dt2.min)+(1440-(dt1.hour*60+dt1.min))<=30){
				return true;
		}
	}
		else if(dt1.day==1 && dt1.mon==1 && dt2.day==31 && dt2.mon==12){
			if((dt1.hour*60+dt1.min)+(1440-(dt2.hour*60+dt2.min))<=30){
				return false;
				}
		}

	}
	return false;
}
void insertFlightNode(flight_ptr &head,FlightNode *p){
	if(head==NULL){
		head = p;
		return;
	}
	else{
		flight_ptr ptr = head;
		while(ptr->next!=NULL) ptr=ptr->next;
		ptr->next = p;//insert last // them 1 may bay mat O(n).
		return;
	}
}

void drawBoxToEnterFlight(int x,int y){
	SetBGColor(14);
	SetColor(0);
	drawRectangle(x,y,71,25);
    drawRectangle(x+5,y+4,61,3);
    drawRectangle(x+5,y+9,61,3);
    drawRectangle(x+5,y+14,61,3);
    drawRectangle(x+24,y+18,22,3);
	drawRectangle(x+5,y+21,10,3);drawRectangle(x+15,y+21,6,3);drawRectangle(x+22,y+21,6,3);gotoxy(x+21,y+22);cout<<":";
	drawRectangle(x+30,y+21,16,3);drawRectangle(x+46,y+21,6,3);drawRectangle(x+53,y+21,6,3);drawRectangle(x+60,y+21,8,3);
	gotoxy(x+52,y+22);cout<<"\\";gotoxy(x+59,y+22);cout<<"\\";
	SetBGColor(14);
	gotoxy(x+20,y+2) ;cout<<" [NHHAP DU LIEU CHUYEN BAY MOI] ";  
	gotoxy(x+25,y+19);cout<<"[Ngay gio khoi hanh]";
    SetBGColor(11);
    gotoxy(x+6,y+5);cout<<"Ma chuyen bay     :                                        ";
    gotoxy(x+6,y+10);cout<<"So hieu MB        :                                        ";
    gotoxy(x+6,y+15);cout<<"San bay den       :                                        ";
    gotoxy(x+6,y+22); cout<<"Gio:Phut";gotoxy(x+16,y+22);cout<<"    ";gotoxy(x+23,y+22);cout<<"    ";
    gotoxy(x+31,y+22);cout<<"Ngay\\thang\\nam";gotoxy(x+47,y+22);cout<<"    ";gotoxy(x+54,y+22);cout<<"    ";gotoxy(x+61,y+22);cout<<"      "; 
}
//ham lap chuyen bay moi 
void addNewFlight(flight_ptr &head){
	int x=42,y=12,check;
	if(airplane_list.n==0){
		MessageBox(NULL,"Can khoi tao danh sach may bay truoc!","THONG BAO",MB_ICONWARNING|MB_OK);
		while(kbhit()) getch();
		return;
	}
	drawBoxToEnterFlight(x,y);
    //================================================================================//
	
	int result=0;//kiem tra so_hieu_may_bay co ton tai hay khong.
	char temp_plane_id[16] = "";
	char temp_airport[21] = "";
	
	//tao ngay gio khoi hanh: 
	int temp_hour = 0;
	int temp_min  = 0;
	int temp_day  = 0;
	int temp_mon  = 0;
	int temp_year = 0; 
	
	
	TicketList temp_tlist; //danh sach ve cua chuyen bay.
	
	ShowConsoleCursor(true);
	char temp_flight_id[16] = "";
	fflush(stdin);
	
	do{
		gotoxy(x+6,y+5);cout<<"Ma chuyen bay     :                                        ";
		do{
			check =1;
			hitKeyBoard(temp_flight_id,x+26,y+5,15,check);
		}while(strlen(temp_flight_id) == 0);
			strupr(temp_flight_id);
			
		if(searchNode(head, temp_flight_id)!=NULL){
			MessageBox(NULL,"Ma chuyen bay da ton tai\n nhap lai","THONG BAO",MB_ICONWARNING|MB_OK);
			while(kbhit()) getch();
		}
	}while(searchNode(head,temp_flight_id)!=NULL);

	do{
		drawBoxToEnterFlight(x,y);
		gotoxy(x+26,y+5);cout<<temp_flight_id;
		do{
			memset(temp_plane_id, '\0', sizeof(temp_plane_id));
			gotoxy(x+26,y+10);cout<<temp_plane_id;
			check =1;
			hitKeyBoard2(temp_plane_id,x+26,y+10,15,check);
		}while(strlen(temp_plane_id) == 0);
			strupr(temp_plane_id);
		result=searchPlaneId(airplane_list,temp_plane_id);
		if(result<0){
			int temp = MessageBox(NULL,"So hieu May bay khong ton tai\n Ban co muon nhap lai khong?","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
			while(kbhit()) getch();
			if (temp==IDCANCEL){
				ShowConsoleCursor(false);
				deleteTable();
				return;
			} 
		}
		else if(airplane_list.airplanes[result]->active==0)
		{
			int temp = MessageBox(NULL,"May bay khong con hoat dong nen khong the thuc hien chuyen bay moi\n Ban co muon nhap lai khong?","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
			while(kbhit()) getch();
			if (temp==IDCANCEL){
				ShowConsoleCursor(false);
				deleteTable();
				return;
			}
			else 
			result =-1;
		} 
	}while(result<0);
	drawBoxToEnterFlight(x,y);
	gotoxy(x+26,y+5);cout<<temp_flight_id;
	gotoxy(x+26,y+10);cout<<temp_plane_id;
	fflush(stdin);
	do{
		check =2;
		hitKeyBoard(temp_airport,x+26,y+15,20,check); // nhap chu
	}while(strlen(temp_airport) == 0);
		Uppercase(temp_airport);
		
	DateTime depart;
	bool stop_check_time=false;
	
	gotoxy(x+17,y+22);
	cout<<"00";
	gotoxy(x+24,y+22);
	cout<<"00";
	do{
		bool exit=true;
		//	cout<<"nhap vao gio/phut khoi hanh ";
		do{
			gotoxy(x+17,y+22);
			cout<<"  ";
			temp_hour = 0,check = 0;
			hitNumbers(temp_hour,x+17,y+22,2,check);
			if (temp_hour == 24 || temp_hour == 0){
				temp_hour = 0;
				gotoxy(x+17,y+22);
				cout<<"00";
			}
		}while(temp_hour > 24 || temp_hour < 0);
		do{
			gotoxy(x+24,y+22);
			cout<<"  ";
			temp_min = 0,check=0;
			hitNumbers(temp_min,x+24,y+22,2,check);
			if (temp_min == 60 || temp_min == 0){
				if (temp_min == 60){
					temp_hour++;
					temp_hour %= 24;
					gotoxy(x+17,y+22);
					cout<<"  ";
					gotoxy(x+17,y+22);
					if (temp_hour > 0)cout<<temp_hour;
					else cout<<"00";
				}
				temp_min = 0;
				gotoxy(x+24,y+22);
				cout<<"00";
			} 
		}while(temp_min > 60);
		//	cout<<"nhap vao ngay/thang/nam ";
		do{
			gotoxy(x+48,y+22);
			cout<<"  ";
			temp_day = 0,check =0;
			hitNumbers(temp_day,x+48,y+22,2,check);
		}while(temp_day == 0 || temp_day > 31);
		do{
			gotoxy(x+55,y+22);
			cout<<"  ";
			temp_mon = 0,check =0;
			hitNumbers(temp_mon,x+55,y+22,2,check);
		}while(temp_mon == 0 || temp_mon > 12);
		do{
			temp_year = 2021,check =0;
			hitNumbers(temp_year,x+62,y+22,4,check);
		}while(temp_year == 0 || temp_year < 2021);
		
		depart.hour=temp_hour;
		depart.min=temp_min;
		depart.day=temp_day;
		depart.mon=temp_mon;
		depart.year=temp_year;
		
		if(checkDepartTime(depart)==false){
			MessageBox(NULL,"Vui long kiem tra lai thoi gian khoi hanh!","THONG BAO",MB_ICONWARNING|MB_OK);
			while(kbhit()) getch();
			exit=false;
		}
		if(checkFlightDecent(head, temp_plane_id, depart)==false){
			MessageBox(NULL,"Trong 2 gio, mot may bay khong the thuc hien 2 chuyen bay khac nhau!\n\tNhap lai!","THONG BAO",MB_ICONWARNING|MB_OK);
			while(kbhit()) getch();
			exit=false;
		}
		if(exit==true){
		stop_check_time=true;
		}
		
	}while(stop_check_time==false);

	ShowConsoleCursor(false);
	Loading(x,y);
	
	Flight flight;// gan truc tiep se bi sai!.
	strcpy(flight.flight_id,temp_flight_id);
	strcpy(flight.plane_id,temp_plane_id);
	strcpy(flight.destination,temp_airport);
	flight.depart_time=depart;
	flight.status = 1;
	

	//khoi tao node_cb moi: 
	FlightNode* p=new FlightNode;
	
	
	//khoi tao danh sach ve cua may bay 
	initializeTicket(temp_tlist,airplane_list.airplanes[result]->seats,0);
	flight.ticket_list = temp_tlist;
	
	//cong them so luot thuc hien chuyen bay.
	airplane_list.airplanes[result]->num_of_flights++;
	
	
	p->flight = flight;
	p->next = NULL;
	insertFlightNode(head, p);
	
	gotoxy(x+11,y+9); cout<<"        	THEM THANH CONG !";
	Sleep(500);
	deleteTable();
	
}

//xoa vung nho thua
void freeMemory(TicketList &t_list){
	for(int i=t_list.booked;i<t_list.limit;i++){
		delete t_list.seat[i];
		t_list.seat[i]=NULL; //?
	}
}

// update trang thai chuyen bay moi lan them hanh khach
void updateStatement(flight_ptr &head){
	
	FlightNode* ptr=new FlightNode;
	ptr = head;
	
	while(ptr!=NULL){
		
		if(ptr->flight.ticket_list.booked<ptr->flight.ticket_list.limit && ptr->flight.status!=0 && ptr->flight.status!=3){
			ptr->flight.status=1;
		}
		if(ptr->flight.ticket_list.booked== ptr->flight.ticket_list.limit && ptr->flight.status!=0){
			ptr->flight.status = 2;
		}
		
		if(checkDepartTime(ptr->flight.depart_time)==false && ptr->flight.status!=0 && ptr->flight.status!=3){
			ptr->flight.status=3;
			freeMemory(head->flight.ticket_list);
		}
		
		ptr=ptr->next;
	}
}

//ham hieu chinh ngay gio cua chuyen bay
void editFlight(flight_ptr &head){
	int x=42,y=12,check; 
	if(head==NULL){
		MessageBox(NULL,"danh sach chuyen bay trong!","THONG BAO",MB_ICONHAND|MB_OK);
		while(kbhit()) getch();
		return;
	}
	drawRectangle(x,y,66,18);  
    drawRectangle(x+5,y+4,54,3);
    SetBGColor(14);
    gotoxy(x+1,y+2) ;cout<<"[NHAP VAO MA CHUYEN BAY BAN MUON HIEU CHINH NGAY GIO KHOI HANH]";
    SetBGColor(11);
    gotoxy(x+6,y+5);cout<<"Ma chuyen bay :                                     ";
    ShowConsoleCursor(true);
	char temp_id[15] = "";
	do{
		check =4;
		hitKeyBoard2(temp_id,x+22,y+5,15,check);
	}while(strlen(temp_id) == 0);
		strupr(temp_id);
	
	FlightNode* edit_node = head;
	SetBGColor(14);
	while(edit_node!=NULL){
		if(strcmp(edit_node->flight.flight_id,temp_id)==0){
			break;
		}
		else edit_node=edit_node->next;
	}
	if(edit_node==NULL){
		MessageBox(NULL,"Ma chuyen bay khong ton tai!","THONG BAO",MB_ICONHAND|MB_OK);
		while(kbhit()) getch();
		ShowConsoleCursor(false);
		deleteTable();
		return;
	}
	else if(edit_node->flight.status==3){
		MessageBox(NULL,"Chuyen bay nay da thuc hien thanh cong!\n\tKhong the hieu chinh!","THONG BAO",MB_ICONWARNING|MB_OK);
		while(kbhit()) getch();
		ShowConsoleCursor(false);
		deleteTable();
		return;
	}
	else if (edit_node->flight.status==0){
		MessageBox(NULL,"Chuyen bay nay da bi huy!\nKhong the hieu chinh!","THONG BAO",MB_ICONWARNING|MB_OK);
		while(kbhit()) getch();
		ShowConsoleCursor(false);
		deleteTable();
		return;
	}
	else{
			drawRectangle(x,y,66,18);
			drawRectangle(x+5,y+7,10,3);drawRectangle(x+15,y+7,6,3);drawRectangle(x+22,y+7,6,3);gotoxy(x+21,y+8);cout<<":";
			drawRectangle(x+5,y+13,16,3);drawRectangle(x+21,y+13,6,3);drawRectangle(x+28,y+13,6,3);drawRectangle(x+35,y+13,8,3);
			gotoxy(x+27,y+14);cout<<"\\";gotoxy(x+34,y+14);cout<<"\\";
			SetBGColor(14);
			gotoxy(x+5,y+2) ;cout<<"[NHAP VAO THOI GIAN KHOI HANH MA BAN MUON THAY DOI]"; 
			SetBGColor(11);
			gotoxy(x+6,y+8); cout<<"Gio:Phut";gotoxy(x+16,y+8);cout<<"    ";gotoxy(x+23,y+8);cout<<"    ";
   			gotoxy(x+6,y+14);cout<<"Ngay\\thang\\nam";gotoxy(x+22,y+14);cout<<"    ";gotoxy(x+29,y+14);cout<<"    ";gotoxy(x+36,y+14);cout<<"      ";	
			
			int temp_hour = edit_node->flight.depart_time.hour , 
			temp_min = edit_node->flight.depart_time.min,
			temp_day = edit_node->flight.depart_time.day, 
			temp_mon = edit_node->flight.depart_time.mon,
			temp_year = edit_node->flight.depart_time.year;
			
			gotoxy(x+17,y+8);cout<<temp_hour;
			gotoxy(x+24,y+8);cout<<temp_min;
			gotoxy(x+23,y+14);cout<<temp_day;
			gotoxy(x+30,y+14);cout<<temp_mon;
			gotoxy(x+37,y+14);cout<<temp_year;
			while(true){
				//gio phut
				do{
					gotoxy(x+17,y+8); cout<<"  ";
					temp_hour = edit_node->flight.depart_time.hour;
					check =0;
					hitNumbers(temp_hour,x+17,y+8,2,check);
					if (temp_hour == 24 || temp_hour == 0){
					temp_hour = 0;
					gotoxy(x+17,y+8);
					cout<<"00";
					}
				}while(temp_hour > 24 || temp_hour < 0);
			
				do{
					gotoxy(x+24,y+8); cout<<"  ";
					temp_min = edit_node->flight.depart_time.min;
					check =0;
					hitNumbers(temp_min,x+24,y+8,2,check);
					if (temp_min == 60 || temp_min == 0){
						if (temp_min == 60){
							temp_hour++;
							temp_hour %= 24;
							gotoxy(x+17,y+8);
							cout<<"  ";
							gotoxy(x+17,y+8);
							if (temp_hour > 0)cout<<temp_hour;
							else cout<<"00";
						}
						temp_min = 0;
						gotoxy(x+24,y+8);
						cout<<"00";
					} 
				}while(temp_min > 60);
				//			nhap ngay/thang/nam 		
				do{
					gotoxy(x+23,y+14); cout<<"  ";
					temp_day = edit_node->flight.depart_time.day;
					check =0;
					hitNumbers(temp_day,x+23,y+14,2,check);
				}while(temp_day == 0 || temp_day > 31);
				do{
					gotoxy(x+30,y+14); cout<<"  ";
					temp_mon = edit_node->flight.depart_time.mon;
					check =0;
					hitNumbers(temp_mon,x+30,y+14,2,check);
				}while(temp_mon == 0 || temp_mon > 12);
				do{
					gotoxy(x+37,y+14); cout<<"    ";
					temp_year = edit_node->flight.depart_time.year;
					check =0;
					hitNumbers(temp_year,x+37,y+14,4,check);
				}while(temp_year == 0 || temp_year < 2021);
				
				DateTime temp_depart;
				temp_depart.hour=temp_hour;
				temp_depart.min=temp_min;
				temp_depart.day=temp_day;
				temp_depart.mon=temp_mon;
				temp_depart.year=temp_year;
				if(checkDepartTime(temp_depart)==false){
					MessageBox(NULL,"Thoi gian nhap vao khong hop le!\nVui long nhap lai!","THONG BAO",MB_ICONWARNING|MB_OK);
					while(kbhit()) getch();
				}
				else if(checkFlightDecentVersion2(head_flist,edit_node,edit_node->flight.plane_id,temp_depart)==false){
					MessageBox(NULL,"Mot may bay khong the thuc hien 2 chuyen bay cach nhau duoi 2 gio!\nVui long nhap lai!","THONG BAO",MB_ICONWARNING|MB_OK);
					while(kbhit()) getch();
				}
				else{
					ShowConsoleCursor(false);
					Loading(x,y);
					gotoxy(x+11,y+9); cout<<"         CAP NHAT THANH CONG !";
					edit_node->flight.depart_time=temp_depart;
					Sleep(500);
					deleteTable();
					return;
				}
			}
	}
	
}

//ham huy chuyen bay  
void deleteFlight(flight_ptr &head,AirplaneList &airplane_list){
	int x=42,y=12,check;
	if(head==NULL){
		MessageBox(NULL,"danh sach chuyen bay trong!","THONG BAO",MB_ICONHAND|MB_OK);
		while(kbhit()) getch();
		return;
	}	
	else{
		drawRectangle(x,y,66,18);  
    	drawRectangle(x+5,y+4,54,3);
    	SetBGColor(14);
    	gotoxy(x+15,y+2) ;cout<<"[NHHAP VAO MA CHUYEN BAY BAN MUON HUY]";
    	SetBGColor(11);
    	gotoxy(x+6,y+5);cout<<"Ma chuyen bay :                                     ";
    	ShowConsoleCursor(true);
		char delete_id[16] = "";
		int check=0;
		do{
			check =4;
			hitKeyBoard2(delete_id,x+22,y+5,15,check);
		}while(strlen(delete_id) == 0);
			strupr(delete_id);
			
			flight_ptr ptr = head;
			while(ptr != NULL){
				if(strcmp(delete_id,ptr->flight.flight_id)==0){
					if(ptr->flight.status==0){
						ShowConsoleCursor(false);
						MessageBox(NULL,"Chuyen bay da bi huy tu truoc!","THONG BAO",MB_ICONWARNING|MB_OK);
						while(kbhit()) getch();	
						deleteTable();
						return;
					}
					else if(ptr->flight.status==3){
						ShowConsoleCursor(false);
						MessageBox(NULL,"Chuyen bay da hoan tat \nKhong the huy!","THONG BAO",MB_ICONWARNING|MB_OK);
						while(kbhit()) getch();	
						deleteTable();
						return;
					}
					else if(ptr->flight.status!=0){
						ShowConsoleCursor(false);
						Loading(x,y);
						ptr->flight.status=0;
						gotoxy(x+11,y+9); cout<<"          HUY THANH CONG !";
						int result=searchPlaneId(airplane_list,ptr->flight.plane_id);
						airplane_list.airplanes[result]->num_of_flights--;
						freeMemory(ptr->flight.ticket_list);
						Sleep(500);
						deleteTable();
						return;
					}
			
				}
				ptr=ptr->next;
			}		
			MessageBox(NULL,"Ma chuyen bay khong ton tai!","THONG BAO",MB_ICONHAND|MB_OK);
			while(kbhit()) getch();	
			ShowConsoleCursor(false);
			deleteTable();
			return;
	}
}
void sortFlightByTime(flight_ptr &head){
	flight_ptr ptr1 = head;
	while(ptr1!=NULL){
		flight_ptr ptr2 = ptr1->next;
		while(ptr2!=NULL){
			if(checkDepartTime(ptr1->flight.depart_time)==true 
			&& checkDepartTime(ptr2->flight.depart_time)==true){
				if(isNearer(ptr2->flight.depart_time,ptr1->flight.depart_time)){
					Flight temp_flight=ptr1->flight;
					ptr1->flight=ptr2->flight;
					ptr2->flight=temp_flight;
				}
			}			
			else if( (ptr1->flight.status==3 || checkDepartTime(ptr1->flight.depart_time)==false) &&checkDepartTime(ptr2->flight.depart_time)==true){
					Flight temp_flight=ptr1->flight;
					ptr1->flight=ptr2->flight;
					ptr2->flight=temp_flight;
				}
			
			else if(checkDepartTime(ptr1->flight.depart_time)==false 
			&& checkDepartTime(ptr2->flight.depart_time)==false ){
				if(isNearer2(ptr2->flight.depart_time,ptr1->flight.depart_time)){
					Flight temp_flight=ptr1->flight;
					ptr1->flight=ptr2->flight;
					ptr2->flight=temp_flight;
				}

			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}
// duyet danh sach cac chuyen bay
void traverseFlight(flight_ptr &head){
	FlightNode* ptr=new FlightNode;
	ptr = head;
	int x=4,y=8,n=16,j=3,count =1,pageht =0,page =0,cd =0;
	drawRectangle(x+112,y,25,11);
	drawTable(x,y,n,6,count);
	SetBGColor(10);
	SetColor(14);
	gotoxy(x+113,y+1);cout<<"       TRANG THAI      ";
	gotoxy(x+1,y+1);cout<<"STT";gotoxy(x+12,y+1); cout<<"Ma CB"; gotoxy(x+29,y+1); cout<<"So hieu MB";gotoxy(x+48,y+1); cout<<"San bay den";gotoxy(x+67,y+1); cout<<"Ngay khoi hanh";gotoxy(x+87,y+1); cout<<"Trang thai";
	SetBGColor(10);
	SetColor(0);
	gotoxy(x+113,y+3);cout<<"  1 : CON VE           ";
	gotoxy(x+113,y+7);cout<<"  3 : HOAN TAT         ";
	SetBGColor(4);
	SetColor(15);
	gotoxy(x+113,y+9);cout<<"  0 : HUY CHUYEN       ";
	gotoxy(x+113,y+5);cout<<"  2 : HET VE           ";
	SetBGColor(14);
	SetColor(0);
	updateStatement(head);
	sortFlightByTime(head);
	while(ptr!=NULL){
		cd++;
		if (cd<=15){
			gotoxy(x+6,y+j); cout<<ptr->flight.flight_id;gotoxy(x+26,y+j);cout<<ptr->flight.plane_id;gotoxy(x+46,y+j); cout<<ptr->flight.destination;
			gotoxy(x+66,y+j); cout<<ptr->flight.depart_time.hour<<":"<<ptr->flight.depart_time.min<<"  "<<ptr->flight.depart_time.day<<"/"
			<<ptr->flight.depart_time.mon<<"/"<<ptr->flight.depart_time.year;
			gotoxy(x+92,y+j); cout<<ptr->flight.status;
			j+=2;
		}
		ptr=ptr->next;
	}
	page = cd/15;
	if ((cd - (page*15)) > 0) page++;
	pageht =1;
	gotoxy(x+43,y+33);cout<<pageht<<"/"<<page;
	int np = 0;
	while (1){
		np = hitKey();int k=0;
		if (np == 27 || np ==13 ) break;
		if (np == 77 && pageht < page){
			pageht++;
			k=1;
		}
		if (np == 75 && pageht >1){
			pageht--;
			k=1;
		}
		if (k==1){
			cd =0;
			count=pageht*15-14;
			drawTable(x,y,n,6,count);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x+1,y+1);cout<<"STT";gotoxy(x+12,y+1); cout<<"Ma CB"; gotoxy(x+29,y+1); cout<<"So hieu MB";gotoxy(x+48,y+1); cout<<"San bay den";gotoxy(x+67,y+1); cout<<"Ngay khoi hanh";gotoxy(x+87,y+1); cout<<"Trang thai";
			SetBGColor(14);
			SetColor(0);
			j=3;
			ptr=head;
			while(ptr!=NULL){
				cd++;
				if (cd<=pageht*15 && cd>=count){
					gotoxy(x+6,y+j); cout<<ptr->flight.flight_id;gotoxy(x+26,y+j);cout<<ptr->flight.plane_id;gotoxy(x+46,y+j); cout<<ptr->flight.destination;
					gotoxy(x+66,y+j); cout<<ptr->flight.depart_time.hour<<":"<<ptr->flight.depart_time.min<<"  "<<ptr->flight.depart_time.day<<"/"
					<<ptr->flight.depart_time.mon<<"/"<<ptr->flight.depart_time.year;
					gotoxy(x+92,y+j); cout<<ptr->flight.status;
					j+=2;
				}
				ptr=ptr->next;
			}
			gotoxy(x+43,y+33);cout<<pageht<<"/"<<page;
		}
	}
	deleteTable();
}
void printByFlightId(Flight flight){
	psnode_ptr result;
	
	int x=33,y=8,n=16,j=3,count =0,np =0,page =0,pageht = 1, d1=0,cd = 0;
	drawTable1(x,y,n,5,1);
	gotoxy(x+15,6);cout<<"DANH SACH HANH KHACH THUOC CHUYEN BAY : "<<flight.flight_id;
	gotoxy(x+12,7);cout<<"Ngay gio khoi hanh: "<<flight.depart_time.day<<"/"<<flight.depart_time.mon<<"/"<<flight.depart_time.year<<" "<<flight.depart_time.hour<<":"<<flight.depart_time.min
	<<"  Noi den: "<<flight.destination;
	SetBGColor(10);
	SetColor(15);
	gotoxy(x+1,y+1);cout<<"STT";gotoxy(x+5,y+1); cout<<"SO GHE"; gotoxy(x+14,y+1); cout<<"SO CMND";gotoxy(x+40,y+1); cout<<"HO TEN";gotoxy(x+66,y+1); cout<<"PHAI";
	SetBGColor(14);
	SetColor(0);
	for(int i=0;i<flight.ticket_list.booked;i++){
			cd++;
			
			//tim du lieu trong cay nhi phan
			result=searchPassenger(flight.ticket_list.seat[i]->person_id,ps_root);
			
			if (cd <= 15) {
				gotoxy(x+7,y+j); cout<<flight.ticket_list.seat[i]->order; gotoxy(x+14,y+j); cout<<result->passenger.person_id;
				gotoxy(x+26,y+j); cout<<result->passenger.last_name<<" "<<result->passenger.name;
		    	gotoxy(x+66,y+j); cout<<(result->passenger.sex==0? "Nam": "Nu");
				j+=2;
				
			} 
				
	}
	  	page = flight.ticket_list.booked/15;
		if ((flight.ticket_list.booked - (page*15)) > 0) page++; // tang len 1 trang neu vuot qua 15
	  	gotoxy(x+43,y+33);cout<<pageht<<"/"<<page;
	while (1){
		np = hitKey();
		int k=0;
		if (np == 27 || np == 13) break;
		
		if (np == 77 && pageht < page){ //page hien tai < page
			pageht++;
			k=1;
		}
		if (np == 75 && pageht > 1){
	  		pageht--;
			  k=1; 
	  	}
	  	if (k==1){
	  		count = pageht*15-14;
			drawTable1(x,y,n,5,count);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x+1,y+1);cout<<"STT";gotoxy(x+5,y+1); cout<<"SO GHE"; gotoxy(x+14,y+1); cout<<"SO CMND";gotoxy(x+40,y+1); cout<<"HO TEN";gotoxy(x+66,y+1); cout<<"PHAI";
			SetBGColor(14);
			SetColor(0);
			j=3;
			for (int i=count-1;i<=pageht*15-1;i++){
				if (i>cd-1) break;
				result=searchPassenger(flight.ticket_list.seat[i]->person_id,ps_root);
				if (result!=NULL){
					gotoxy(x+7,y+j);cout<<flight.ticket_list.seat[i]->order; gotoxy(x+14,y+j); cout<<result->passenger.person_id;gotoxy(x+26,y+j); cout<<result->passenger.last_name<<" "<<result->passenger.name;
		    		gotoxy(x+66,y+j); cout<<(result->passenger.sex==0? "Nam": "Nu");
					j+=2;
				}
				
			}
			gotoxy(x+43,y+33);cout<<pageht<<"/"<<page;
		}
	}
	deleteTable();
	return;
}

//In danh sach  cac chuyen bay khoi hanh trong ngay dd/mm/yy den noi X
void printFollowDayPlace(flight_ptr &head){
	if(head==NULL){
		MessageBox(NULL,"Chua co chuyen bay nao !","THONG BAO",MB_ICONWARNING|MB_OK);
		while (kbhit()) getch();
		return;
	}
	int x=42,y=12,check =0;
	drawRectangle(x,y,64,18);
    gotoxy(x+1,y+2) ;cout<<"            THONG TIN THOI GIAN KHOI HANH VA DIA DIEM";  
    drawRectangle(x+5,y+4,20,3); drawRectangle(x+25,y+4,6,3); gotoxy(x+31,y+5);cout<<"\\";drawRectangle(x+32,y+4,6,3);gotoxy(x+38,y+5);cout<<"\\";drawRectangle(x+39,y+4,8,3);
	drawRectangle(x+5,y+10,54,3);
    SetBGColor(11);
    gotoxy(x+26,y+5);cout<<"    ";gotoxy(x+33,y+5);cout<<"    ";gotoxy(x+40,y+5);cout<<"      ";
    gotoxy(x+6,y+5);cout<<" Ngay\\thang\\nam : ";
    gotoxy(x+6,y+11);cout<<" Nhap vao noi den  :                                ";
    
	ShowConsoleCursor(true);
    int temp_day = 0,temp_mon = 0,temp_year = 0;
	while(1){
		do{
			gotoxy(x+27,y+5);
			cout<<"  ";
			temp_day = 0,check =0;
			hitNumbers(temp_day,x+27,y+5,2,check);
		}while(temp_day == 0 || temp_day > 31);
		
		do{
			gotoxy(x+34,y+5);
			cout<<"  ";
			temp_mon = 0,check =0;
			hitNumbers(temp_mon,x+34,y+5,2,check);
		}while(temp_mon == 0 || temp_mon > 12);
		
		do{
			temp_year = 2021,check =0;
			hitNumbers(temp_year,x+41,y+5,4,check);
		}while(temp_year == 0 || temp_year < 2021);
		
		DateTime dt;
		dt.day=temp_day;
		dt.mon=temp_mon;
		dt.year=temp_year;
		if(dayOfMonth(dt)==false){
			int kq = MessageBox(NULL,"Thoi gian bi sai!\nban co muon nhap lai","THONG BAO",MB_ICONWARNING|MB_OKCANCEL);
			while (kbhit()) getch();	
			if (kq == IDCANCEL){
				ShowConsoleCursor(false);
				deleteTable();
				return;
			}
		}else break;
	}
		
    
	char temp_airport[20] ="";
	fflush(stdin);
	do{
		int check =2;
		hitKeyBoard(temp_airport,x+27,y+11,20,check);
	}while(strlen(temp_airport)==0);
		Uppercase(temp_airport);
		
	ShowConsoleCursor(false);
	deleteTable();
	flight_ptr ptr=head;

    x=37,y=8;
	int n=16,j=3,np =0,cd = 0,page =0,pageht =0,count =1,d =0;
	drawTable(x,y,n,5,count);
	SetBGColor(10);
	SetColor(15);
	gotoxy(x+1,y+1); cout<<"STT";gotoxy(x+12,y+1); cout<<"MA CB"; gotoxy(x+29,y+1); cout<<"SO HIEU MB";gotoxy(x+52,y+1); cout<<"GIO";gotoxy(x+70,y+1); cout<<"CON TRONG";
	SetBGColor(14);
	SetColor(0);
	while(ptr!=NULL){
		if(ptr->flight.depart_time.day==temp_day && ptr->flight.depart_time.mon==temp_mon &&ptr->flight.depart_time.year==temp_year
		&& (strcmp(ptr->flight.destination,temp_airport)==0)){
			cd++;
			gotoxy(x+10,y+j); cout<<ptr->flight.flight_id; gotoxy(x+30,y+j); cout<<ptr->flight.plane_id;gotoxy(x+50,y+j); cout<<ptr->flight.depart_time.hour<<" : "<<ptr->flight.depart_time.min;
		    gotoxy(x+73,y+j); cout<<(ptr->flight.ticket_list.limit - ptr->flight.ticket_list.booked);
			j+=2;
		}
		ptr=ptr->next;
	}
	page = cd/15;
	if ( (cd - (page*15)) > 0) page++;
	pageht=1;
	gotoxy(x+43,y+33);cout<<pageht<<"/"<<page;
	while(1){
		np = hitKey();
		int k=0;
		if (np == 27 || np == 13) break;
		if (np == 77 && pageht < page){
			pageht++;
			k=1;
		}
		if (np == 75 && pageht > 1){
			pageht--;
			k=1;
		}
		if (k==1){
			count = pageht*15-14;
			drawTable(x,y,n,5,count);
			SetBGColor(1);
			SetColor(15);
			gotoxy(x+1,y+1); cout<<"STT";gotoxy(x+12,y+1); cout<<"MA CB"; gotoxy(x+29,y+1); cout<<"SO HIEU MB";gotoxy(x+52,y+1); cout<<"GIO";gotoxy(x+70,y+1); cout<<"CON TRONG";
			SetBGColor(14);
			SetColor(0);
			d=0;
			while(ptr!=NULL){
				if(ptr->flight.depart_time.day==temp_day && ptr->flight.depart_time.mon==temp_mon &&ptr->flight.depart_time.year==temp_year
				&& (strcmp(ptr->flight.destination,temp_airport)==0)){
					d++;
					if (d>=count && d<=pageht*15){
						gotoxy(x+10,y+j); cout<<ptr->flight.flight_id; gotoxy(x+30,y+j); cout<<ptr->flight.plane_id;gotoxy(x+50,y+j); cout<<ptr->flight.depart_time.hour<<" : "<<ptr->flight.depart_time.min;
		    			gotoxy(x+73,y+j); cout<<(ptr->flight.ticket_list.limit-ptr->flight.ticket_list.booked);
						j+=2;
					}	
				}
				ptr=ptr->next;
			}
			gotoxy(x+43,y+33);cout<<pageht<<"/"<<page;
		}
			
	}
	deleteTable();
	return;
}

//In danh sach ve con trong cua chuyen bay X 
void printEmptyTicket(TicketList &t_list, char temp_flight_id[]){
	int x=53,y=8;int n=16,j=3,count = 1 ,np = 0,cd =0,page = 0, pageht = 0;
	drawRectangle(x-41,y,34,3);
	drawRectangle(x-41,y+4,34,3);
	drawRectangle(x-41,y+8,34,3);
	drawTable(x,y,n,2,count);
	count = 16;
	drawTable(x+48,y,n,2,count);
	SetBGColor(11);
	gotoxy(x-40,y+1);cout<<"Ma chuyen bay:                  ";
	gotoxy(x-25,y+1);cout<<temp_flight_id;
	SetBGColor(10);
	SetColor(15);
	gotoxy(x+1,y+1); cout<<"STT";gotoxy(x+7,y+1); cout<<"STT VE CON TRONG"; 
	gotoxy(x+49,y+1); cout<<"STT";gotoxy(x+55,y+1); cout<<"STT VE CON TRONG";
	SetBGColor(14);
	SetColor(0);
	for(int i=0;i<t_list.limit;i++){
		if(checkEmpty(t_list,i+1)){ // kiem tra ghe trong, con trong thi in ra
			cd++;
			if (cd == 16) j=3;
			if (cd <= 15){
				gotoxy(x+10,y+j); cout<<i+1;
				j+=2;
			}
			if (cd > 15 && cd <= 30){
				gotoxy(x+58,y+j); cout<<i+1;
				j+=2;
			}
		}
	}
	SetBGColor(10);
	gotoxy(x-40,y+5);cout<<"Tong so ve   :                  ";
	gotoxy(x-25,y+5);cout<<t_list.limit;
	SetBGColor(10);
	gotoxy(x-40,y+9);cout<<"Ve con trong :                  ";
	gotoxy(x-25,y+9);cout<<(t_list.limit-t_list.booked);
	SetBGColor(14);
	SetColor(0);
	page = cd/15;
	if ( (cd - (page*15)) > 0 ) page++;
	if (page%2 == 1) page++;
	gotoxy(x+35,y+33);cout<<"2/"<<page;
	pageht = 2;
	count =1;int count2 = 0,k = 0;
	while(1){
		np = hitKey();
		k=0;
		if (np == 27 || np ==13) break;
		if (np == 77 && pageht < page){
			pageht++;
			count = pageht*15-14;
			pageht++;
			count2 = pageht*15-14;
			k=1;
		}
		if ( np == 75 && pageht > 2){
			pageht-=3;
			count = pageht*15-14;
			pageht++;
			count2 = pageht*15-14;
			k=1;
		}
		if (k==1){
			cd =0,j=3;
			drawTable(x,y,n,2,count);
			drawTable(x+48,y,n,2,count2);
			SetBGColor(10);
			SetColor(15);
			gotoxy(x+1,y+1); cout<<"STT";gotoxy(x+7,y+1); cout<<"STT VE CON TRONG"; 
			gotoxy(x+49,y+1); cout<<"STT";gotoxy(x+55,y+1); cout<<"STT VE CON TRONG";
			SetBGColor(14);
			SetColor(0);
			
			for(int i=0;i<t_list.limit;i++){
				if(checkEmpty(t_list,i+1)){
					cd++;
					if (cd == count2) j=3;
					if (cd <= count+14 && cd >=count){
						gotoxy(x+10,y+j); cout<<i+1;
						j+=2;
					}
					if (cd >= count2 && cd <= count2+14){
						gotoxy(x+58,y+j); cout<<i+1;
						j+=2;
					}
				}
			}
		gotoxy(x+35,y+33);cout<<pageht<<"/"<<page;
		}
	}
	deleteTable();
}

//In so lan thuc hien cua chuyen bay 
void printNumOfFlight(AirplaneList &airplane_list){
	for(int i=0;i<airplane_list.n;i++){
		
		int temp_index=i;	
		for(int j=i+1;j<airplane_list.n;j++){
			if(airplane_list.airplanes[temp_index]->num_of_flights<airplane_list.airplanes[j]->num_of_flights){
			temp_index=j; // vi tri co so lan thuc hien lon nhat.
			}	
		}
	Airplane *temp_plane=airplane_list.airplanes[i];
	airplane_list.airplanes[i]=airplane_list.airplanes[temp_index]; // doi cho neu  cai if tren xay ra.
	airplane_list.airplanes[temp_index]=temp_plane;	
	}
	int x=12,y=8;int n1=16,j=3,count=1,np = 0,page = 0, pageht = 0;
	drawRectangle(x+98,y,25,8);
	drawTable(x,y,n1,5,count);
	SetBGColor(10);
	SetColor(15);
	gotoxy(x+99,y+1);cout<<"       TRANG THAI      ";
	gotoxy(x+1,y+1); cout<<"STT";gotoxy(x+8,y+1); cout<<"SO HIEU MAY BAY"; gotoxy(x+26,y+1); cout<<"SO LUOT THUC HIEN";
	gotoxy(x+48,y+1); cout<<"TRANG THAI";gotoxy(x+68,y+1); cout<<"SO LUONG GHE";
	SetBGColor(9);
	SetColor(0);
	gotoxy(x+99,y+3);cout<<"  1 : HOAT DONG        ";
	SetBGColor(4);
	SetColor(15);
	gotoxy(x+99,y+5);cout<<"  0 : KHONG HOAT DONG  ";
	SetBGColor(14);
	SetColor(0);
	for(int i=0;i<15;i++){
		if (i>=airplane_list.n) break;
		gotoxy(x+9,y+j); cout<<airplane_list.airplanes[i]->plane_id; gotoxy(x+30,y+j); cout<<airplane_list.airplanes[i]->num_of_flights;
		gotoxy(x+51,y+j); cout<<(airplane_list.airplanes[i]->active == true? "1" : "0");gotoxy(x+68,y+j); cout<<airplane_list.airplanes[i]->seats;
		j+=2;
	}
	page = airplane_list.n/15;
	if ((airplane_list.n - (page*15)) > 0) page++;
	pageht=1;
	gotoxy(x+35,y+33);cout<<pageht<<"/"<<page;
	while(1){
		np = hitKey();
		int k=0;
		if (np == 27 || np ==13) break;
		if (np == 77 && pageht < page){
			pageht++;// 2, 3
			count = pageht*15-14;//15 30
			k=1;
		}
		if (np == 75 && pageht > 1){
			pageht--;
			count = pageht*15-14;
			k=1;
		}
		if (k==1){
			drawTable(x,y,n1,5,count);
			SetBGColor(10);
			SetColor(15);
			gotoxy(x+1,y+1); cout<<"STT";gotoxy(x+8,y+1); cout<<"SO HIEU MAY BAY"; gotoxy(x+26,y+1); cout<<"SO LUOT THUC HIEN";
			gotoxy(x+48,y+1); cout<<"TRANG THAI";gotoxy(x+68,y+1); cout<<"SO LUONG GHE";
			SetBGColor(14);
			SetColor(0);
			j=3;
			for(int i=count-1;i<pageht*15;i++){
				if (i>=airplane_list.n) break;
				gotoxy(x+9,y+j); cout<<airplane_list.airplanes[i]->plane_id; gotoxy(x+30,y+j); cout<<airplane_list.airplanes[i]->num_of_flights;
				gotoxy(x+51,y+j); cout<<(airplane_list.airplanes[i]->active == true? "1" : "0");gotoxy(x+68,y+j); cout<<airplane_list.airplanes[i]->seats;
				j+=2;
			}
			gotoxy(x+35,y+33);cout<<pageht<<"/"<<page;
		}
	}
	deleteTable();
}

///////////////////////////////////////////////////// HANH KHACH ////////////////////////////////////////////////////////////
//===============================HANH KHACH: cay AVL=====================
 


//overfload : create_data

Passenger createData(char temp_person_id[]){


	char temp_name[11] = "";
	char temp_last[31] = "";
	bool temp_sex;
	int x=42,y=12,check; 
	drawRectangle(x,y,70,18);
    drawRectangle(x+5,y+4,36,3);
    drawRectangle(x+5,y+7,28,3);
    drawRectangle(x+5,y+10,41,3);
    drawRectangle(x+23,y+13,5,3); drawRectangle(x+30,y+13,5,3);
    SetBGColor(14);
    gotoxy(x+24,y+2) ;cout<<"[ NHHAP DU LIEU KHACH HANG ]"; 
    gotoxy(x+12,y+14);cout<<"Gioi tinh :";
    SetBGColor(14);
    gotoxy(x+24,y+14);cout<<"Nam";  gotoxy(x+31,y+14);cout<<"Nu";
    SetBGColor(11);
    gotoxy(x+6,y+5);cout<<"Ho :                              ";
	gotoxy(x+6,y+8);cout<<"Ten :                     ";
    gotoxy(x+6,y+11);cout<<" CMND         :                        ";
    gotoxy(x+22,y+11);cout<<temp_person_id;
	ShowConsoleCursor(true);
	do{
		check =2;
		hitKeyBoard(temp_last,x+11,y+5,30,check);
	}while(strlen(temp_last) == 0);
		Uppercase(temp_last);
		
	do{
		check =2;
		hitKeyBoard(temp_name,x+12,y+8,10,check);
	}while(strlen(temp_name)==0);
		Uppercase(temp_name);
		
	ShowConsoleCursor(false);
	SetBGColor(11);
	gotoxy(x+24,y+14);cout<<"Nam";
	int np,tempx = 66;
	while(1){
		np = hitKey();
		switch(tempx){
			case 66:{
				if ( np == 77 || np == 75){
					tempx = 73;
					SetBGColor(14);
					gotoxy(x+24,y+14);cout<<"Nam";
					SetBGColor(11);
					gotoxy(x+31,y+14);cout<<"Nu";
				}
				break;
			}
			case 73:{
				if ( np == 77 || np == 75){
					tempx = 66;
					SetBGColor(11);
					gotoxy(x+24,y+14);cout<<"Nam";
					SetBGColor(14);
					gotoxy(x+31,y+14);cout<<"Nu";
				}
				break;
			}
		}
		if (np == 13){
			break;
		}
	};
	if (tempx == 66) temp_sex = 0;
	if (tempx == 73) temp_sex = 1;
	Passenger passenger;
	strcpy(passenger.person_id,temp_person_id);
	strcpy(passenger.last_name,temp_last);
	strcpy(passenger.name,temp_name);
	passenger.sex=temp_sex;

	return passenger;
	deleteTable();
}


//gan du lieu vao node hanh khach
PassengerNode * create_node(Passenger &passenger){
	PassengerNode* new_node=new PassengerNode;
	new_node->passenger=passenger;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

// quay trai
psnode_ptr RotateLeft(psnode_ptr &root){
 	psnode_ptr p;
 	if(root == NULL) return p;
 	else
 		if(root->right == NULL) return p;
 		else{
 			p = root->right;
 			root->right = p->left;
 			p->left = root;
 		}
 return p;
}

//ham quay phai
psnode_ptr RotateRight(psnode_ptr &ya){
	
	psnode_ptr s;

 	if(ya == NULL) return s;
 	else
 		if(ya->left == NULL) return s;
 		else
 		{
 			s = ya->left;
 			ya->left = s->right;
 			s->right = ya;
 		}
 	return s;
}
//chen them node moi vao cay.
void insertPsNode(psnode_ptr &root,Passenger &passenger ){
	
	if(root==NULL){
	
	psnode_ptr new_node=new PassengerNode;
	strcpy(new_node->passenger.person_id,passenger.person_id);
	strcpy(new_node->passenger.last_name,passenger.last_name);
	strcpy(new_node->passenger.name,passenger.name);
	new_node->passenger.sex=passenger.sex;
	new_node->left=NULL;
	new_node->right=NULL;
	root=new_node;
	
	return;
	}
	
 	psnode_ptr fp, p, q, s,fya,ya;
 	int imbal; 
 	fp = NULL; p = root;
 	fya = NULL; ya = p;

 	while(p != NULL)//tim vi tri insert
 	{
 
 		if (strcmp(passenger.person_id,p->passenger.person_id)==0) 
 			return;
 		if (strcmp(passenger.person_id,p->passenger.person_id)<0)
			q = p->left;
 		else
			q = p->right;
 	if(q != NULL){
 		if(q->bf != 0){
	 	 fya = p;
 		ya = q;
		}		
	 }
	  	
	fp = p; // father of p now is p
 	p = q;  // p now is q
 }
	//vi p va q tro toi NULL nen thoat vong lap
	//tao new Ps roi gan 
	q = new PassengerNode;
	q->passenger = passenger;
 	q->bf = 0;
	
	
	//gan nut q vao cay!
	if(strcmp(passenger.person_id,fp->passenger.person_id)<0)
 		fp->left = q;
 	else fp->right = q;	


	// chinh lai bf theo huong q duoc them vao!
 	if(strcmp(passenger.person_id,ya->passenger.person_id)<0)
 		p = ya->left;
 	else
 		p = ya->right;
 	s = p; // s la con nut ya
 	
	 //dieu chinh lai chi so can bang! cho p tro tung nut den nut q thi dung lai 
	 while(p != q){ 
	 if(strcmp(passenger.person_id,p->passenger.person_id)<0){ 
 		p->bf = 1;
 		p = p->left;
	}
 	else{ 
		p->bf = -1;
		p = p->right;
 	}
}

 // xac dinh huong lech
 	if(strcmp(passenger.person_id,ya->passenger.person_id)<0)
 		imbal = 1;
 	else
 		imbal = -1;
 		
 	
 	if(ya->bf == 0){
		ya->bf = imbal;
 		return;
	}
 	if(ya->bf != imbal){
 		ya->bf = 0;
 		return;
    }
	// Truong hop xoay don
 	if(s->bf == imbal){
		if(imbal == 1) // xoay phai
 		p = RotateRight(ya);
 		
 		else // xoay trai
 		p = RotateLeft(ya);
 		
 		
 		ya->bf = 0;
 		s->bf = 0;
 	}
 	
 	
 	// Truong hop xoay kep
 	else { 
 	
 	// xoay kep trai-phai
	 if(imbal == 1) {
		ya->left = RotateLeft(s);
		p = RotateRight(ya);
	}
	// xoay kep phai-trai -
 	else{
		ya->right = RotateRight(s);
		p = RotateLeft(ya);
	}

	// truong hop p la nut moi them vao
	if(p->bf == 0) {
		ya->bf = 0;
 		s->bf = 0;
 	}
 	else
 		if(p->bf == imbal){
			ya->bf = -imbal;
 			s->bf = 0;
		}
 		else{
  			ya->bf = 0;
			s->bf = imbal;
	 	}
	p->bf = 0;
}
 	if(fya == NULL)
 		root = p;
 	else
 		if(ya == fya->right)
 			fya->right = p;
 		else
 			fya->left = p;
}
//duyet cay tien tu: khong dung

//dung duyet trung tu: co bien tau.
//duyet theo hau tu :khong dung


psnode_ptr searchPassenger(char temp_person_id[], psnode_ptr &root){

	if(root==NULL){
		return root; 
	}
	else if(strcmp(temp_person_id, root->passenger.person_id)<0){
		searchPassenger(temp_person_id,root->left);
	}
	else if(strcmp(temp_person_id,root->passenger.person_id)>0){
		searchPassenger(temp_person_id,root->right);
	}
	else{
		return root;
	}
}




////////////////////////////////////////////////////////////// VE //////////////////////////////////////////////////////////////
//bang thong bao lua chon
int notification(int x,int y,string s){
	int kc = (70-s.length())/2;
	SetBGColor(14);
	drawRectangle(x,y+19,70,8);
	drawRectangle(x+5,y+22,5,3);
	drawRectangle(x+59,y+22,4,3);
	gotoxy(x+6,y+23);cout<<"YES"; gotoxy(x+60,y+23);cout<<"NO";
	SetBGColor(14);
	gotoxy(x+kc,y+20);cout<<"[ "<<s<<" ]";
	SetBGColor(2);
	SetColor(15);
	gotoxy(x+6,y+23);cout<<"YES";
	int kp = 0,tempx = 48;
	while (1){
		fflush(stdin);
		kp = hitKey();
		if (kp == 13) break;
		switch(tempx){
			case 48:{
				if (kp == 75 || kp == 77){
					SetBGColor(4);
					SetColor(15);
					gotoxy(x+60,y+23);cout<<"NO";
					SetBGColor(14);
					SetColor(0);
					gotoxy(x+6,y+23);cout<<"YES";
					tempx = 102;
				}
				break;
			}
			case 102:{
				if (kp == 75 || kp == 77){
					SetBGColor(2);
					SetColor(15);
					gotoxy(x+6,y+23);cout<<"YES";
					SetBGColor(14);
					SetColor(0);
					gotoxy(x+60,y+23);cout<<"NO";
					tempx = 48;
				}
				break;
			}
		}
	}
	if ( tempx == 48) return 1;
	else return 0;
}
void sortTicketList(TicketList &t_list){
	for(int i=0;i<t_list.booked-1;i++){
		Ticket* temp_t=t_list.seat[i];
		int temp_t_index=i;
		for(int j=i+1;j<t_list.booked;j++){
			if(temp_t->order>t_list.seat[j]->order){
				temp_t=t_list.seat[j];
				temp_t_index=j;
			}
		}
		
		temp_t=t_list.seat[i];
		t_list.seat[i]=t_list.seat[temp_t_index];
		t_list.seat[temp_t_index]=temp_t;		
	}
}
bool checkEmpty(TicketList &t_list,int pos){
	for(int i=0;i<t_list.booked;i++){
		if(t_list.seat[i]->order==pos){
			return false;
		}
	}
	return true;
}
//ham dat ve chuyen bay
void orderTicket(flight_ptr &f_list,flight_ptr f, TicketList &t_list){
	deleteTable();
	int x=42,y=12,check;
	if(t_list.booked==t_list.limit){
		MessageBox(NULL,"Chuyen bay da du hanh khach! \nMoi chon chuyen bay khac!","THONG BAO",MB_ICONHAND|MB_OK);
		while(kbhit()) getch();	
		return;
	}	
	char temp_person_id[10] = "";
	psnode_ptr check2;
	bool stop=true;
	Passenger passenger;	
	do{
		drawRectangle(x,y,64,18); 
    	drawRectangle(x+5,y+4,54,3);
    	SetBGColor(14);
    	gotoxy(x+17,y+2) ;cout<<"[NHAP CMND DE DAT VE MAY BAY]"; 
    	SetBGColor(11);
    	gotoxy(x+6,y+5);cout<<"  CMND :                                            ";
    	ShowConsoleCursor(true);
		do{
			check =3;
			hitKeyBoard(temp_person_id,x+14,y+5,9,check);
		}while(strlen(temp_person_id) == 0 || strlen(temp_person_id) < 9 );
		
		ShowConsoleCursor(false);
		
		for(int i=0;i<t_list.booked;i++){
			if(strcmp(temp_person_id,t_list.seat[i]->person_id)==0){
				MessageBox(NULL,"So CMND da dat ve tren chuyen bay nay!","THONG BAO",MB_ICONHAND|MB_OK);
				while(kbhit()) getch();
				stop=false;
				deleteTable();
				return;
			}
			stop=true;
		}
		
	}while(stop==false);
		deleteTable();
		check2=searchPassenger(temp_person_id,ps_root);
		if(check2==NULL){
			passenger= createData(temp_person_id);
			stop = true;
		}
		  // da co du lieu cua hanh khach nay!
			else{  
				flight_ptr p=head_flist;
				while(p!=NULL){
					if(isTheSameTime(p->flight.depart_time,f->flight.depart_time)==true && p!=f){
						for(int i=0;i<p->flight.ticket_list.booked;i++){
							if(strcmp(temp_person_id,p->flight.ticket_list.seat[i]->person_id)==0){
							MessageBox(NULL,"Hanh khach khong the dat 2 chuyen bay khoi hanh cach nhau duoi 30 phut!","THONG BAO",MB_ICONHAND|MB_OK);
							while(kbhit()) getch();
							deleteTable();
							return ;
							}
						}
					}
					p=p->next;
				}
			deleteTable();
			drawRectangle(x,y,70,18);
    		drawRectangle(x+5,y+4,36,3);
    		drawRectangle(x+5,y+7,28,3);
    		drawRectangle(x+5,y+10,41,3);
    		drawRectangle(x+23,y+13,5,3); drawRectangle(x+30,y+13,5,3);
    		SetBGColor(14);
    		gotoxy(x+26,y+2) ;cout<<"[ DU LIEU KHACH HANG ]"; 
   			gotoxy(x+12,y+14);cout<<"Gioi tinh :";
   			SetBGColor(14);
    		gotoxy(x+24,y+14);cout<<"Nam";  gotoxy(x+31,y+14);cout<<"Nu";
    		SetBGColor(11);
    		gotoxy(x+6,y+5);cout<<"Ho :                              ";
			gotoxy(x+6,y+8);cout<<"Ten :                     ";
    		gotoxy(x+6,y+11);cout<<" CMND         :                        ";
    		gotoxy(x+22,y+11);cout<<check2->passenger.person_id;
    		gotoxy(x+11,y+5);cout<<check2->passenger.last_name;
    		gotoxy(x+12,y+8);cout<<check2->passenger.name;

			if (check2->passenger.sex == 0){
				gotoxy(x+24,y+14);cout<<"Nam";
			}	
			if (check2->passenger.sex == 1){
				gotoxy(x+31,y+14);cout<<"Nu";
			} 
			
			
			if(notification(x,y,"DAT VE CHO HANH KHACH NAY ?") == 0){
				deleteTable();
				return;
			}
		}
	while(true){
		deleteTable();
		drawRectangle(x,y,64,18); 
    	drawRectangle(x+5,y+4,54,3);
    	SetBGColor(14);
    	gotoxy(x+17,y+2) ;cout<<"[NHAP SO GHE DE DAT VE MAY BAY]"; 
    	SetBGColor(11);
    	gotoxy(x+6,y+5);cout<<"  So ghe :                                          ";
    	ShowConsoleCursor(true);
    	int ticket = 0,ID = 0;
		do{
			check =1;
			hitNumbers2(ticket,x+17,y+5,3,check,t_list);
		}while(ticket == 0);
		ShowConsoleCursor(false);
		
		if(ticket > t_list.limit){
			MessageBox(NULL,"Khong ton tai so ghe nay trong chuyen bay\n Vui long nhap so ghe khac!","THONG BAO",MB_ICONHAND|MB_OK);
			while(kbhit()) getch();
		}
		 
		else if(checkEmpty(t_list, ticket)){
			
			
			
			if (check2 == NULL){
				insertPsNode(ps_root,passenger);
				t_list.seat[t_list.booked]->order = ticket;
				strcpy(t_list.seat[t_list.booked]->person_id,passenger.person_id);
			}
			else if (check2 != NULL){
				t_list.seat[t_list.booked]->order = ticket;
				strcpy(t_list.seat[t_list.booked]->person_id,check2->passenger.person_id);
			} 
			Loading(x,y); 
			gotoxy(x+11,y+9); cout<<"         DAT VE THANH CONG !";
			Sleep(500);
			t_list.booked++;//tang so luong hanh khach len 1 don vi.
			sortTicketList(t_list);
			deleteTable();
			return;
		}
		else{
			ID = MessageBox(NULL,"Ve nay da co nguoi dat ! \nban co muon chon ve khac!","THONG BAO",MB_ICONQUESTION|MB_OKCANCEL);
			while(kbhit()) getch();
			if (ID == IDCANCEL){
				deleteTable();
				return;
			}
		}
	}	
}

// ham huy ve 
void removeTicket(TicketList &t_list){
	deleteTable();
	char temp_person_id[10] ="";
	int key;
	psnode_ptr passenger=NULL;
	int x=42,y=12,check;
	drawRectangle(x,y,64,18);
    gotoxy(x+1,y+2) ;cout<<"                NHAP CMND DE HUY VE MAY BAY";  
    drawRectangle(x+5,y+4,54,3);
    SetBGColor(11);
    gotoxy(x+6,y+5);cout<<"  CMND :                                            ";
    gotoxy(x+14,y+5);
    ShowConsoleCursor(true);
	do{
		check =3;
		hitKeyBoard(temp_person_id,x+14,y+5,9,check);
	}while(strlen(temp_person_id) == 0 || strlen(temp_person_id) < 9);
	
	ShowConsoleCursor(false);
	deleteTable();
	Loading(x,y);
	deleteTable();
	for(int i=0;i<t_list.booked;i++){
		if(strcmp(temp_person_id,t_list.seat[i]->person_id)==0){ // tim hanh khach trong danh sach
			drawRectangle(x,y,64,18);
    		drawRectangle(x+5,y+4,26,3);drawRectangle(x+31,y+4,28,3);
    		drawRectangle(x+5,y+7,41,3);
    		drawRectangle(x+5,y+10,41,3);
    		SetBGColor(14);
    		gotoxy(x+16,y+2) ;cout<<"[DU LIEU KHACH HANG MUON HUY VE]"; 
    		SetBGColor(11);
    		gotoxy(x+6,y+5);cout<<"Ho :                    ";gotoxy(x+32,y+5);cout<<"Ten :                     ";
    		gotoxy(x+6,y+8);cout<<" CMND         :                        ";
    		gotoxy(x+6,y+11);cout<<"     PHAI     :                        ";
    		
			passenger = searchPassenger(temp_person_id,ps_root);
			gotoxy(x+11,y+5);cout<<passenger->passenger.last_name; gotoxy(x+38,y+5);cout<<passenger->passenger.name;
			gotoxy(x+22,y+8);cout<<passenger->passenger.person_id;
			string s=(passenger->passenger.sex==0)?"Nam" : "Nu";
			gotoxy(x+22,y+11);cout<<s;
			
			if(notification(x,y,"ban co muon xoa hanh khach nay khong?") == 1){ // tim dc tai vi tri thu i dich sang trai.
				for(int j=i;j<t_list.booked-1;j++){
					*t_list.seat[j]=*t_list.seat[j+1];//dereference poiter -> ticket //
				}
				MessageBox(NULL,"XOA VE THANH CONG !","THONG BAO",MB_ICONINFORMATION|MB_OK);
				t_list.booked--;
				while(kbhit()) getch();
				deleteTable();
				return;
			}
			else{
				MessageBox(NULL,"XOA VE KHONG THANH CONG !","THONG BAO",MB_ICONINFORMATION|MB_OK);
				while(kbhit()) getch();
				deleteTable();
				return;
			}
		}
	}
	MessageBox(NULL,"Hanh khach van chua dat ve tren chuyen bay nay!","THONG BAO",MB_ICONWARNING|MB_OK);
	while(kbhit()) getch();
	return;
}

//////////////////////////////////////////////////// In Danh Sach //////////////////////////////////////

//duyet theo trung tu lay thong tin hanh khach
void LNR(psnode_ptr &root,int x,int &y,int &count,int bd,int max){
	if (count > max ) return;
	if(root!=NULL){
		LNR(root->left,x,y,count,bd,max);
		if (count <= max && count >= bd){
			gotoxy(x+6,y);cout<<root->passenger.person_id; gotoxy(x+18,y);cout<<root->passenger.last_name<<" "<<root->passenger.name;
			gotoxy(x+58,y);cout<<(root->passenger.sex==0? "Nam": "Nu");
			y = y+2;
		}
		count++;
		LNR(root->right,x,y,count,bd,max);
	}
}
//duyet theo trung tu lay chieu dai
void LNR(psnode_ptr &root,int &cd){
	if(root!=NULL){
		LNR(root->left,cd);
		cd++;
		LNR(root->right,cd);
	}
}

void printAllPassenger(){
	int x=45,y=8,tempy =11,n=16,count =1,np =0,page =0,pageht = 1,bd = 1,cd =0;
	LNR(ps_root,cd);
	drawTable1(x,y,n,4,1);
	SetBGColor(10);
	SetColor(15);
	gotoxy(x+1,y+1);cout<<"STT";gotoxy(x+6,y+1); cout<<"SO CMND"; gotoxy(x+28,y+1); cout<<"HO VA TEN";gotoxy(x+58,y+1);cout<<"PHAI";
	SetBGColor(14);
	SetColor(0);
	LNR(ps_root,x,tempy,count,1 , 15);
	page = cd/15;
	if (cd - (page*15) > 0) page++;
	gotoxy(x+28,y+33);cout<<pageht<<"/"<<page;
  while(1){
  	np = hitKey();
  	int k=0;
  	if (np == 13 || np == 27 )break;
  	if (np == 77 && pageht < page){
			pageht++;
			k=1;
	}
	if (np == 75 && pageht > 1){
	  		pageht--;
			  k=1; 
	}
	if (k==1){
		bd = pageht*15-14;
		drawTable1(x,y,n,4,bd);
		SetBGColor(10);
		SetColor(15);
		gotoxy(x+1,y+1);cout<<"STT";gotoxy(x+6,y+1); cout<<"SO CMND"; gotoxy(x+28,y+1); cout<<"HO VA TEN";gotoxy(x+58,y+1);cout<<"PHAI";
		SetBGColor(14);
		SetColor(0);
		tempy =11,count =1;
		LNR(ps_root,x,tempy,count,bd,pageht*15);
		gotoxy(x+28,y+33);cout<<pageht<<"/"<<page;
	}
  }
  deleteTable();
}
void deleteTree(psnode_ptr &root) {
    if (root == NULL) {
        return;
    }
    if (root->left) {
        deleteTree(root->left);
    }
     if (root->right) {
        deleteTree(root->right);
    }
    
	delete root;
  root=NULL;
}
void deleteAirplaneList(AirplaneList &airplane_list){
	for(int i=0;i<airplane_list.n;i++){
		delete airplane_list.airplanes[i];
	}
}
void deleteFlightList(flight_ptr &head){
	flight_ptr ptr=head;
	while(ptr != NULL){
		delete ptr;
		ptr=ptr->next;
	}
}

//Xuat danh sach thong tin hanh khach cua 1 chuyen bay X


#endif
