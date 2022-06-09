#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <conio.h>
#include <mylib.h>
HANDLE wHnd;
HANDLE rHnd;
using namespace std;

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

void drawsmt()
{
	SetBGColor(14);
	for(int i= 0; i<= 7000; i++)
	{
		cout<<" ";
	}
}

void drawbox()
{
	
}

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

string* choose(int code)
{	
	
	if(code == 1)
	{
	
		string *test = new string[3];
		test[0] = "             THEM            ";
		test[1] = "             XOA             ";
		test[2] = "          HIEU CHINH         ";
		return test;
	}
	else{
		string *test = new string[3];
		test[0] = "             ADD             ";
		test[1] = "             XOA             ";
		test[2] = "             EDIT            ";
		return test;
	}
}
void changeColor(int x,int y,int bg_color,int text_color,string s){
	gotoxy(x,y);
    SetBGColor(bg_color);
    SetColor(text_color);
    cout<<s;
SetBGColor(14);
SetColor(0);
gotoxy(x,y);
}
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
int main()
{
	
	/*drawsmt();
	gotoxy(0, 0);
	drawToolBar();
	gotoxy(0, 18);
	cout<<"chon ngon ngu: ";
	deleteTable();
	//gotoxy(149, 44);*/
	string *x;
	x = choose(2);
	printFunction(78, 3, x);
	


	return 0;
}
