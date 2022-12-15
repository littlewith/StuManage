#pragma once
/*�û�����*/
#define EXIT_SYSTEM_INFO 1001
#include<iostream>
using namespace std;
#include<Windows.h>
class UI {
public:
	inline int MaxWindow();//��󻯴���
	inline void logo_print();//��ӡLittlewith
	inline void loading();//���ض���
	inline string* login();
	inline int Welcome_admin(string* username);//����Ա��ӭ
	inline int Welcome_student(string* username);//ѧ����ӭ
	inline int Welcome_control_student();//ѧ������
	inline int Welcoem_control_class();//�༶����
	inline int Welcome_change_info();//��������
	inline void Login_failed(int count);//��½ʧ��
	inline void Input_error();//�������
	inline void To_exit();//�˳�ϵͳ
};

int UI::MaxWindow()
{
	HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE); //��ÿ���̨���
	COORD NewSize = GetLargestConsoleWindowSize(HOUT);//��ÿ���̨������꣬�������ַ���Ϊ��λ
	NewSize.X -= 1;
	NewSize.Y -= 1; //���Բ��ӣ�����ʱ��ʾ������
	SetConsoleScreenBufferSize(HOUT, NewSize); //���ÿ���̨��������С
	SMALL_RECT DisplayArea = { 0,0,0,0 };
	DisplayArea.Right = NewSize.X;
	DisplayArea.Bottom = NewSize.Y;
	SetConsoleWindowInfo(HOUT, TRUE, &DisplayArea); //���ÿ���̨��С
	//����̨�Ѿ���󻯣����ǳ�ʼλ�ò�����Ļ���Ͻǣ�������´���
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE); //�������
	return 0;
}

int UI::Welcome_change_info() {
	cout << "======================================================" << endl;
	cout << "\t��ѡ����Ĳ�����" << endl;
	cout << "\t1.�����ҵ�����             2.�����ҵ��û���" << endl;
	cout << "\t3.������һ��                 4.�˳�ϵͳ" << endl;
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
	cout << "\t\tϵͳ����";
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
	 cout << "\t\t\t\t\t��¼\t\t\n";
	 cout <<"\t\t\t==============================================" << endl;
	 cout << "\t\t�������û���: ";
	 cin >> *lgdata;
	 cout << "\t\t����������: ";
	 cin >> *(lgdata+1);
	 return lgdata;
 }

 void UI::Login_failed(int count) {
	 int logFailed = 0;
	 if(count<3){
		 system("cls");
		 cout << "\t\t��Ǹ����֤ʧ��.......������" << endl;
		 getchar();
		 getchar();
		 system("cls");
	 }
	 if (count >= 3) {
		 system("cls");
		 cout << "\t\t���棬��֤���ʧ�ܣ����򼴽��˳�.........." << endl;
		 getchar();
		 getchar();
		 exit(-1);
	 }
	 
 }

 int UI::Welcome_admin(string* username) {
	 Sleep(500);
	 system("cls");
	 cout << "======================================================" << endl;
	 cout << "\t" << *username << "����Ա����ӭ����" << endl;
	 cout << "\t��ӭʹ��С��ѧ������ϵͳ!\t" << endl;
	 cout << "\t��ѡ��Ҫ���еĲ���: \t" << endl;
	 cout << "\t1.ѧ����Ϣ����                  2.�༶��Ϣ����\t" << endl;
	 cout << "\t3.�޸Ĺ���Ա���˻�����          4.�˳�ϵͳ\t" << endl;
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
		 cout << "\t" << *username << "ͬѧ����ӭ�㣡" << endl;
		 cout << "\t��ӭʹ��С��ѧ��ϵͳ!\t" << endl;
		 cout << "\t��ѡ��Ҫ���еĲ���: \t" << endl;
		 cout << "\t1.���    2.�޸����� \t" << endl;
		 cout << "\t3.�˳�ϵͳ\t" << endl;
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
	 cout << "\t��ѡ����Ĳ�����" << endl;
	 cout << "\t1.����ѧ����Ϣ             2.ɾ��ѧ����Ϣ" << endl;
	 cout << "\t3.�޸�ѧ����Ϣ             4.����ѧ����Ϣ" << endl;
	 cout << "\t5.�����ϼ��˵�             6.�˳�ϵͳ" << endl;
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
	 cout << "\t��ѡ����Ĳ�����" << endl;
	 cout << "\t1.��ӡ�༶�ɼ��ֶ����             2.�鿴�༶ѧ��ƽ����" << endl;
	 cout << "\t3.�鿴�༶ѧ�ƺϸ���             4.��ӡѧ���ɼ���" << endl;
	 cout << "\t5.�����ϼ��˵�             6.�˳�ϵͳ" << endl;
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
	 cout << "\t\t������˼......�������ѡ������������������...........";
	 return;
 }
 
 void UI::To_exit() {
	 system("cls");
	 Sleep(1000);
	 cout << "\t\t�����˳�..................";
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

 