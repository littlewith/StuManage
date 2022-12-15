#pragma once
/*用户界面*/
#define EXIT_SYSTEM_INFO 1001
#include<iostream>
using namespace std;
#include<Windows.h>
class UI {
public:
	inline int MaxWindow();//最大化窗口
	inline void logo_print();//打印Littlewith
	inline void loading();//加载动画
	inline string* login();
	inline int Welcome_admin(string* username);//管理员欢迎
	inline int Welcome_student(string* username);//学生欢迎
	inline int Welcome_control_student();//学生管理
	inline int Welcoem_control_class();//班级管理
	inline int Welcome_change_info();//更改密码
	inline void Login_failed(int count);//登陆失败
	inline void Input_error();//输入错误
	inline void To_exit();//退出系统
};

int UI::MaxWindow()
{
	HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE); //获得控制台句柄
	COORD NewSize = GetLargestConsoleWindowSize(HOUT);//获得控制台最大坐标，坐标以字符数为单位
	NewSize.X -= 1;
	NewSize.Y -= 1; //可以不加，不加时显示滚动条
	SetConsoleScreenBufferSize(HOUT, NewSize); //设置控制台缓冲区大小
	SMALL_RECT DisplayArea = { 0,0,0,0 };
	DisplayArea.Right = NewSize.X;
	DisplayArea.Bottom = NewSize.Y;
	SetConsoleWindowInfo(HOUT, TRUE, &DisplayArea); //设置控制台大小
	//控制台已经最大化，但是初始位置不在屏幕左上角，添加如下代码
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE); //窗体最大化
	return 0;
}

int UI::Welcome_change_info() {
	cout << "======================================================" << endl;
	cout << "\t请选择你的操作：" << endl;
	cout << "\t1.更改我的密码             2.更改我的用户名" << endl;
	cout << "\t3.返回上一步                 4.退出系统" << endl;
	cout << "======================================================" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:return 1;
	case 2:return 2;
	case 3:return 3;
	case 4:this->To_exit(); return EXIT_SYSTEM_INFO;
	default:this->Input_error();
	}
}

 void UI::logo_print() {
	system("color f");
	string up__1 = "------------------------------------------------------------";
	string logo1 = "| .__  .__  __    __  .__                .__  __  .__      |";
	string logo2 = "| |  | |__|/  |__/  |_|  |   ______  _  _|__|/  |_|  |__   |";
	string logo3 = "| |  | |  \\   __\\   __\\  | _/ __ \\ \\/ \\/ /  \\   __\\   _ \\  |";
	string logo4 = "| |  |_|  ||  |  |  | |  |_\\  ___/\\     /|  ||  | |  | \\ \\ |";
	string logo5 = "| |____/__||__|  |__| |____/\_____>\/\_/\\_/ |__||__| |__| |_/ |";
	//string logo6 = "|                               \\/                     \\/  |";
	string dw__1 = "------------------------------------------------------------";
	cout << "\t\t" << up__1 << endl;
	Sleep(600);
	cout << "\t\t" << logo1 << endl;
	Sleep(400);
	cout << "\t\t" << logo2 << endl;
	Sleep(250);
	cout << "\t\t" << logo3 << endl;
	Sleep(200);
	cout << "\t\t" << logo4 << endl;
	Sleep(150);
	cout << "\t\t" << logo5 << endl;
	Sleep(50);
	//cout << logo6 << endl;
	cout << "\t\t" << dw__1 << endl;
	Sleep(1000);
	system("color 3");
	return;
}

 void UI::loading() {
	cout << endl;
	cout << "\t\t系统载入";
	int co = 200;
	for (co = 100; co > 0; co = co - 2) {
		Sleep(co);
		cout << ".";
	}
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	cout << "Done";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	cout << endl;
	Sleep(1000);
	system("pause");
	system("cls");
	system("color f");
	return;
}

 string* UI::login() {
	 string* lgdata = new string[2];
	 cout << "\t\t\t\t\t登录\t\t\n";
	 cout <<"\t\t\t==============================================" << endl;
	 cout << "\t\t请输入用户名: ";
	 cin >> *lgdata;
	 cout << "\t\t请输入密码: ";
	 cin >> *(lgdata+1);
	 return lgdata;
 }

 void UI::Login_failed(int count) {
	 int logFailed = 0;
	 if(count<3){
		 system("cls");
		 cout << "\t\t抱歉，验证失败.......请重试" << endl;
		 getchar();
		 getchar();
		 system("cls");
	 }
	 if (count >= 3) {
		 system("cls");
		 cout << "\t\t警告，验证多次失败，程序即将退出.........." << endl;
		 getchar();
		 getchar();
		 exit(-1);
	 }
	 
 }

 int UI::Welcome_admin(string* username) {
	 Sleep(500);
	 system("cls");
	 cout << "======================================================" << endl;
	 cout << "\t" << *username << "管理员，欢迎您！" << endl;
	 cout << "\t欢迎使用小和学籍管理系统!\t" << endl;
	 cout << "\t请选择要进行的操作: \t" << endl;
	 cout << "\t1.学生信息管理                  2.班级信息管理\t" << endl;
	 cout << "\t3.修改管理员的账户密码          4.退出系统\t" << endl;
	 cout << "======================================================" << endl;
	 int choose = 0;
	 cin >>choose;
	 system("cls");
	 switch (choose) {
	 case 1:return 1;
	 case 2:return 2;
	 case 3:return 3;
	 case 4:this->To_exit(); return EXIT_SYSTEM_INFO;
	 default:this->Input_error();
	 }
 }

	 int UI::Welcome_student(string* username) {
		 Sleep(500);
		 system("cls");
		 cout << "======================================================" << endl;
		 cout << "\t" << *username << "同学，欢迎你！" << endl;
		 cout << "\t欢迎使用小和学籍系统!\t" << endl;
		 cout << "\t请选择要进行的操作: \t" << endl;
		 cout << "\t1.查分    2.修改密码 \t" << endl;
		 cout << "\t3.退出系统\t" << endl;
		 cout << "======================================================" << endl;
		 int choose = 0;
		 cin >> choose;
		 system("cls");
		 switch (choose) {
		 case 1:return 1;
		 case 2:return 2;
		 case 3:this->To_exit(); return EXIT_SYSTEM_INFO;
		 default:this->Input_error();
		 }
	 }
 
 int UI::Welcome_control_student() {
	 Sleep(500);
	 cout << "======================================================" << endl;
	 cout << "\t请选择你的操作：" << endl;
	 cout << "\t1.增加学生信息             2.删除学生信息" << endl;
	 cout << "\t3.修改学生信息             4.检索学生信息" << endl;
	 cout << "\t5.返回上级菜单             6.退出系统" << endl;
	 cout << "======================================================" << endl;
	 int tmp = 0;
	 cin >> tmp;
	 system("cls");
	 switch (tmp) {
	 case 1:return 1;
	 case 2:return 2;
	 case 3:return 3;
	 case 4:return 4;
	 case 5:return 5;
	 case 6:this->To_exit(); return EXIT_SYSTEM_INFO;
	 default:this->Input_error();
	 }
 }

 int UI::Welcoem_control_class() {
	 Sleep(500);
	 cout << "======================================================" << endl;
	 cout << "\t请选择你的操作：" << endl;
	 cout << "\t1.打印班级成绩分段情况             2.查看班级学科平均分" << endl;
	 cout << "\t3.查看班级学科合格率             4.打印学生成绩单" << endl;
	 cout << "\t5.返回上级菜单             6.退出系统" << endl;
	 cout << "======================================================" << endl;
	 int choose = 0;
	 cin >> choose;
	 system("cls");
	 switch (choose) {
	 case 1:return 1;
	 case 2:return 2;
	 case 3:return 3;
	 case 4:return 4;
	 case 5:return 5;
	 case 6:this->To_exit(); return EXIT_SYSTEM_INFO;
	 default:this->Input_error();
	 }
 }

 void UI::Input_error() {
	 cout << "\t\t不好意思......你输入的选项有误，请重试新输入...........";
	 return;
 }
 
 void UI::To_exit() {
	 system("cls");
	 Sleep(1000);
	 cout << "\t\t即将退出..................";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(50);
	 cout << "..........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(200);
	 cout << "........";
	 Sleep(500);
	 cout << ".......";
	 Sleep(2000);
	 return;
 }

 