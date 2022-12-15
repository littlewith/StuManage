#pragma once
#define EXIT_SYSTEM_INFO 1001
#include<iostream>
#include<string>
using namespace std;
#include<fstream>
#include<vector>
#include"md5.h"
#include"UI.cpp"
class Account {//账户类，存储用户账户信息，下面将会用管理员和学生进行继承
public:
	inline Account(string username, string passwd, string uid) {
		this->username = username;
		this->passwd = MD5(passwd).toStr();
		this->uid = MD5(uid).toStr();
	}
	inline ~Account() {
		ofstream file_ptr("DataAccounts.lit", ios::app);
		file_ptr << endl;
		file_ptr << this->username << "|" << this->passwd << "@" << this->uid;
	}
	inline Account(string username, string passwd) {
		this->username = MD5(username).toStr();
		this->passwd = MD5(passwd).toStr();
	}
	inline void chg_username(string new_username) {
		this->username = MD5(new_username).toStr();
	}
	inline void chg_passwd(string new_passwd) {
		this->passwd = MD5(new_passwd).toStr();
	}
	inline void chg_uid(int setuid) {
		if (setuid % 2 == 0) {//识别为管理员账户
			srand(time(0));
			int tmp = rand() % 100;
			if (tmp % 2 == 0) {
				this->uid = MD5(to_string(tmp)).toStr();
			}
			else {
				this->uid = MD5(to_string(tmp + 1)).toStr();
			}
		}
		else {//识别为普通用户
			srand(time(0));
			int tmp = rand() % 100;
			if (tmp % 2 != 0) {
				this->chg_uid(tmp);
			}
			else {
				this->chg_uid(tmp);
			}
		}
	}
	inline string get_username() {
		return this->username;
	}
	inline string  get_uid() {//返回用户标识
		return this->uid;
	}
private:
	string username;
	string passwd;
	string uid;
};
class Lesson {//单个课程类：用于存储课程的名字和分数
public:
	inline Lesson(string name) {
		this->lesson_name = name;
		this->lesson_score = 0;
	}
	inline Lesson(string lesson_name, float lesson_score) {
		this->lesson_name = lesson_name;
		this->lesson_score = lesson_score;
	}
	inline string get_lesson_name() {
		return this->lesson_name;
	}
	inline float get_lesson_score() {
		return this->lesson_score;
	}
	inline void set_lesson(string lesson_name, float lesson_score) {
		this->lesson_name = lesson_name;
		this->lesson_score = lesson_score;
	}
	inline void set_lesson_score(float score) {
		this->lesson_score = score;
	}

private:
	string lesson_name;//课程名字
	float lesson_score;//课程分数
};
class Multi_lessons {
public:
	inline Multi_lessons() :Cpp("C++程序设计"), Gaoshu("高等数学"), Xiandai("线性代数"), English("英语"), Shujujiegou("数据结构") {

	}
	inline Multi_lessons(float cppscore, float gaoshuscore, float xiandaiscore, float enscore, float shujuscore) :Cpp("C++程序设计", cppscore), Gaoshu("高等数学", gaoshuscore), Xiandai("线性代数", xiandaiscore), English("英语", enscore), Shujujiegou("数据结构", shujuscore) {
		//这边新建一个构造函数
	}
	inline ~Multi_lessons(){
		
	}
	inline void set_cpp_score(float score) {
		this->Cpp.set_lesson_score(score);
	}
	inline void set_gaoshu_score(float score) {
		this->Gaoshu.set_lesson_score(score);
	}
	inline void set_xiandai_score(float score) {
		this->Xiandai.set_lesson_score(score);
	}
	inline void set_english_score(float score) {
		this->English.set_lesson_score(score);
	}
	inline void set_sjjg_score(float score) {
		this->Shujujiegou.set_lesson_score(score);
	}
	inline float get_Total_score() {//计算总分
		return this->Cpp.get_lesson_score() + this->English.get_lesson_score() + this->Gaoshu.get_lesson_score() + this->Shujujiegou.get_lesson_score() + this->English.get_lesson_score();
	}
	inline float get_Cpp_score() {
		return this->Cpp.get_lesson_score();
		//返回CPP成绩；
	}
	inline float get_Gaoshu_score() {
		return this->Gaoshu.get_lesson_score();
	}
	inline float get_Xiandai_score() {
		return this->Gaoshu.get_lesson_score();
	}
	inline float get_English_score() {
		return this->English.get_lesson_score();
	}
	inline float get_sjjg_score() {
		return this->Shujujiegou.get_lesson_score();
	}
private:
	Lesson Cpp;
	Lesson Gaoshu;
	Lesson Xiandai;
	Lesson English;
	Lesson Shujujiegou;
};
class Student {//学生类，这个类仅仅用于存储信息而已。
public:
	//inline Student(){}
	//inline ~Student(){}
	string name;
	string idnumber;//学号
	string gender;
	Multi_lessons score;//成绩
	int stu_id;//编号
};
class All_students {
public:
	All_students() {
		this->stu_amount = 0;
		/*
		for (int i = 0; i < stu_amount; i++) {
			Student tmpstu;//这里可能会出错
			tmpstu.stu_id = i;
			this->studentlist.push_back(tmpstu);//放入容器
		}
		*/
	}
	 ~All_students() {
		//存盘
		ofstream file_ptr("Database.lit", ios::trunc);//清空重写。
		file_ptr << this->studentlist.size() << endl;
		for (int i = 0; i < this->studentlist.size(); i++) {
			file_ptr << this->studentlist[i].name << endl;
			file_ptr << this->studentlist[i].idnumber << endl;
			file_ptr << this->studentlist[i].gender << endl;
			file_ptr << this->studentlist[i].score.get_Cpp_score() << endl;
			file_ptr << this->studentlist[i].score.get_Gaoshu_score() << endl;
			file_ptr << this->studentlist[i].score.get_Xiandai_score() << endl;
			file_ptr << this->studentlist[i].score.get_sjjg_score() << endl;
			if (i == studentlist.size() - 1) {
				file_ptr << this->studentlist[i].score.get_English_score();
			}
			else {
				file_ptr << this->studentlist[i].score.get_English_score() << endl;
			}
		}
	}
	inline void chg() {
		while (true) {
			system("cls");
			cout << "你要改什么？" << endl;
			cout << "1.姓名    2.学号   3.性别  4.成绩" << endl;
			cout << "返回上级请输入5,   退出请输入6" << endl;
			int choose;
			cin >> choose;
			if (choose == 1) {
				string name;
				cout << "输入原来的名字: ";
				cin >> name;
				cout << "改成什么？";
				string newname;
				cin >> newname;
				for (int i = 0; i < studentlist.size(); i++) {
					if (studentlist[i].name == name) {
						this->studentlist[i].name = newname;
					}
				}
				cout << "成功！" << endl;
				getchar();
				getchar();

				return;
			}
			else if (choose == 2) {
				string name;
				cout << "输入原来的学号: ";
				cin >> name;
				cout << "改成什么？";
				string newname;
				cin >> newname;
				for (int i = 0; i < studentlist.size(); i++) {
					if (studentlist[i].idnumber == name) {
						this->studentlist[i].name = newname;
					}
				}
				cout << "成功！" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 3) {
				string name;
				cout << "给哪个同学改？: ";
				cin >> name;
				cout << "改成什么？";
				string newname;
				cin >> newname;
				for (int i = 0; i < studentlist.size(); i++) {
					if (studentlist[i].name == name) {
						this->studentlist[i].gender = newname;
					}
				}
				cout << "成功！" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 4) {
				while (true) {
					cout << "\t\t给谁改？";
					string name;
					cin >> name;
					cout << "\t\t选择你要改哪一门课的成绩？" << endl;
					cout << "\t\t1.高数  2.线代  3.C++  4.英语  5.数据结构" << endl;
					cout << "\t\t输入6来退回上一步,输入7来结束程序" << endl;
					int choose;
					cin >> choose;
					cout << "\t\t改成多少？";
					float new_score;
					cin >> new_score;
					if (choose == 1) {
						for (int i = 0; i < studentlist.size(); i++) {
							if (studentlist[i].name == name) {
								studentlist[i].score.set_gaoshu_score(new_score);
							}
						}
						cout << "成功！" << endl;
						getchar();
						getchar();
						return;
					}
					else if (choose == 2) {
						for (int i = 0; i < studentlist.size(); i++) {
							if (studentlist[i].name == name) {
								studentlist[i].score.set_xiandai_score(new_score);
							}
						}
						cout << "成功！" << endl;
						getchar();
						getchar();
						return;
					}
					else if (choose == 3) {
						for (int i = 0; i < studentlist.size(); i++) {
							if (studentlist[i].name == name) {
								studentlist[i].score.set_cpp_score(new_score);
							}
						}
						cout << "成功！" << endl;
						getchar();
						getchar();
						return;
					}
					else if (choose == 4) {
						for (int i = 0; i < studentlist.size(); i++) {
							if (studentlist[i].name == name) {
								studentlist[i].score.set_english_score(new_score);
							}
						}
						cout << "成功！" << endl;
						getchar();
						getchar();
						return;
					}
					else if (choose == 5) {
						for (int i = 0; i < studentlist.size(); i++) {
							if (studentlist[i].name == name) {
								studentlist[i].score.set_sjjg_score(new_score);
							}
						}
						cout << "成功！" << endl;
						getchar();
						getchar();
						return;
					}
					else if (choose == 6) {
						exit(0);
						return;
					}
					else if (choose == 7) {
						return;
					}
					else {
						cout << "输入选项不正确.....请重试" << endl;
						getchar();
						getchar();
						return;
					}
				}
			}
			else if (choose == 5) {
				return;
			}
			else if (choose == 6) {
				exit(0);
			}
			else {
				cout << "没有这个选项......请重试";
				return;
			}
			cout << "信息更新成功!" << endl;
			getchar();
		}
	}
	inline void hegelv() {
		float cpp;
		float count0 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_Cpp_score() >= 60) {
				count0++;
			}
		}
		cpp = count0 / studentlist.size();
		cout << "C++程序设计的合格率为: " << cpp * 100 << "%" << endl;

		float sjjg;
		float count1 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_sjjg_score() >= 60) {
				count1++;
			}
		}
		sjjg = count1 / studentlist.size();
		cout << "数据结构的合格率为: " << sjjg * 100 << "%" << endl;

		float gdsx;
		float count2 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_Gaoshu_score() >= 60) {
				count2++;
			}
		}
		gdsx = count2 / studentlist.size();
		cout << "高等数学的合格率为: " << gdsx * 100 << "%" << endl;

		float xxds;
		float count3 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_Xiandai_score() >= 60) {
				count3++;
			}
		}
		xxds = count3 / studentlist.size();
		cout << "线性代数的合格率为: " << xxds * 100 << "%" << endl;

		float eng;
		float count4 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_English_score() >= 60) {
				count4++;
			}
		}
		eng = count4 / studentlist.size();
		cout << "英语的合格率为: " << eng * 100 << "%" << endl;
		getchar();
		getchar();
		system("cls");
	}
	inline void average() {
		float cppsum = 0;
		float xxiandaisum = 0;
		float sjjgsum = 0;
		float gaoshusum = 0;
		float engsum = 0;
		for (int i = 0; i < studentlist.size(); i++) {
			cppsum = cppsum + studentlist[i].score.get_Cpp_score();
			xxiandaisum = xxiandaisum + studentlist[i].score.get_Xiandai_score();
			sjjgsum = sjjgsum + studentlist[i].score.get_sjjg_score();
			gaoshusum = gaoshusum + studentlist[i].score.get_Gaoshu_score();
			engsum = engsum + studentlist[i].score.get_English_score();
		}
		cppsum = cppsum / studentlist.size();
		xxiandaisum = xxiandaisum / studentlist.size();
		sjjgsum = sjjgsum / studentlist.size();
		gaoshusum = gaoshusum / studentlist.size();
		engsum = engsum / studentlist.size();

		cout << "高数平均分:" << gaoshusum << endl;
		cout << "C++平均分:" << cppsum << endl;
		cout << "线代平均分:" << xxiandaisum << endl;
		cout << "英语平均分:" << engsum << endl;
		cout << "数据结构平均分:" << sjjgsum << endl;
		getchar();
		getchar();
		system("cls");
		return;
	}
	inline void del() {
		int choose;
		cout << "\t\t======请选择您删除学生的方式======" << endl;
		cout << "\t\t1.按照学号进行删除          2.按照姓名进行删除" << endl;
		cin >> choose;
		if (choose == 1) {
			cout << "请输入您要删除的学生的学号：";
			string number;
			cin >> number;
			for (int i = 0; i < studentlist.size(); i++) {
				if (number == studentlist[i].idnumber) {
					studentlist.erase(studentlist.begin() + i);
				}
			}
			this->stu_amount--;
			cout << "删除成功！" << endl;
			Sleep(1000);
		}
		else if (choose == 2) {
			cout << "请输入您要删除的学生的姓名：";
			string name;
			cin >> name;
			for (int i = 0; i < studentlist.size(); i++) {
				if (name == studentlist[i].name) {
					studentlist.erase(studentlist.begin() + i);
				}
			}
			this->stu_amount--;
			cout << "删除成功！" << endl;
			Sleep(1000);
		}
		else {
			cout << "您输入的选项不正确，请重新输入......." << endl;
		}
	}
	inline string get_stu_name(int i) {
		return this->studentlist[i].name;
	}
	inline string get_stu_idnumber(int i) {
		return this->studentlist[i].idnumber;
	}
	inline string get_stu_gender(int i) {
		return this->studentlist[i].gender;
	}
	inline float get_stu_cppscore(int i) {
		return this->studentlist[i].score.get_Cpp_score();
	}
	inline float get_sjjg_score(int i) {
		return this->studentlist[i].score.get_sjjg_score();
	}
	inline float get_xiandai_score(int i) {
		return this->studentlist[i].score.get_Xiandai_score();
	}
	inline float get_eng_score(int i) {
		return this->studentlist[i].score.get_English_score();
	}
	inline float get_gaoshu_score(int i) {
		return this->studentlist[i].score.get_Gaoshu_score();
	}
	inline void add_stu(string name, string idnumber, string gender, float cppscore, float sjjgscore, float gaoshuscore, float engscore, float xiandaiscore) {
		Student newstu;
		newstu.stu_id = this->studentlist.size();
		newstu.name = name;
		newstu.gender = gender;
		newstu.idnumber = idnumber;
		newstu.score.set_cpp_score(cppscore);
		newstu.score.set_english_score(engscore);
		newstu.score.set_gaoshu_score(gaoshuscore);
		newstu.score.set_sjjg_score(sjjgscore);
		newstu.score.set_xiandai_score(xiandaiscore);
		this->studentlist.push_back(newstu);//放入容器
		this->stu_amount++;
	}
	inline void add_stu() {
		system("cls");
		Student newstudent;
		newstudent.stu_id = this->studentlist.size();
		cout << "\t\t========增加学生信息========" << endl;
		cout << "请输入学生姓名: ";
		cin >> newstudent.name;
		cout << endl;

		cout << "请输入学生学号: ";
		cin >> newstudent.idnumber;
		cout << endl;

		cout << "请输入学生性别: ";
		cin >> newstudent.gender;
		cout << endl;

		cout << "------下面开始录入该学生的成绩信息: ------" << endl;;
		cout << "请输入高等数学成绩: ";
		float gs;
		cin >> gs;
		newstudent.score.set_gaoshu_score(gs);

		cout << "请输入线性代数成绩: ";
		cin >> gs;
		newstudent.score.set_xiandai_score(gs);

		cout << "请输入英语成绩: ";
		cin >> gs;
		newstudent.score.set_english_score(gs);

		cout << "请输入C++程序设计成绩: ";
		cin >> gs;
		newstudent.score.set_cpp_score(gs);

		cout << "请输入数据结构成绩: ";
		cin >> gs;
		newstudent.score.set_sjjg_score(gs);

		studentlist.push_back(newstudent);
		this->stu_amount++;//数量加一
		cout << "学生信息增加成功!" << endl;
		getchar();
		getchar();
		return;
	}
	inline int get_id_by_name(string name) {//通过名字来获取学生的唯一标识符
		for (int i = 0; i < stu_amount; i++) {
			if (studentlist[i].name == name) {
				return this->studentlist[i].stu_id;
			}
		}
	}
	inline void find_students() {
		string names;
		string numberd;
		cout << "为了确保安全，请再次输入姓名和学号: " << endl;
		cout << "姓名: ";
		cin >> names;
		cout << "学号: ";
		cin >> numberd;
		for (int i = 0; i < stu_amount; i++) {
			if (names == studentlist[i].name && numberd == studentlist[i].idnumber) {
				cout << "姓名: " << studentlist[i].name << "  学号: " << studentlist[i].idnumber << "  性别: " << studentlist[i].gender << endl;
				cout << "高等数学: " << studentlist[i].score.get_Gaoshu_score() << "  线性代数: " << studentlist[i].score.get_Xiandai_score() << "  英语: " << studentlist[i].score.get_English_score() << "  C++程序设计: " << studentlist[i].score.get_Cpp_score() << "  数据结构: " << studentlist[i].score.get_sjjg_score() << endl;
				getchar();
				getchar();
				system("cls");
				return;
			}
		}
		cout << "\t\t验证失败，请重试！！！" << endl;
		getchar();
		getchar();
		system("cls");
		return;
	}
	inline void find_student() {//检索学生
		while (true){
			system("cls");
			int choose;
			cout << "\t\t======请选择您查找学生的方式======" << endl;
			cout << "\t\t1.按照学号进行查找          2.按照姓名进行查找" << endl;
			cout << "\t\t3.返回上一步  " << endl;
			cin >> choose;
			if (choose == 1) {
				cout << "请输入您要查找的学生的学号：";
				string number;
				cin >> number;
				for (int i = 0; i < studentlist.size(); i++) {
					if (number == studentlist[i].idnumber) {
						cout << "姓名: " << studentlist[i].name << "  学号: " << studentlist[i].idnumber << "  性别: " << studentlist[i].gender << endl;
						cout << "高等数学: " << studentlist[i].score.get_Gaoshu_score() << "  线性代数: " << studentlist[i].score.get_Xiandai_score() << "  英语: " << studentlist[i].score.get_English_score() << "  C++程序设计: " << studentlist[i].score.get_Cpp_score() << "  数据结构: " << studentlist[i].score.get_sjjg_score() << endl;
						getchar();
						getchar();
						system("cls");
						return;
					}
				}
				system("cls");
				cout << "\t\t没找到....请重试" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 2) {
				cout << "请输入您要查找的学生的姓名：";
				string name;
				cin >> name;
				for (int i = 0; i < studentlist.size(); i++) {
					if (name == studentlist[i].name) {
						cout << "姓名: " << studentlist[i].name << "  学号: " << studentlist[i].idnumber << "  性别: " << studentlist[i].gender << endl;
						cout << "高等数学: " << studentlist[i].score.get_Gaoshu_score() << "  线性代数: " << studentlist[i].score.get_Xiandai_score() << "  英语: " << studentlist[i].score.get_English_score() << "  C++程序设计: " << studentlist[i].score.get_Cpp_score() << "  数据结构: " << studentlist[i].score.get_sjjg_score() << endl;
						getchar();
						getchar();
						system("cls");
						return;
					}
				}
				system("cls");
				cout << "没找到....请重试" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 3) {
				return;
			}
			else {
				system("cls");
				cout << "您输入的选项不正确，请重新输入......." << endl;
				getchar();
				this->find_student();
			}
			return;
		}
		
	}
	inline void set_stu_name(string name, int stu_id) {//设置学生的姓名
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				this->studentlist[i].name = name;
			}
		}
	}
	inline void set_stu_idnumber(string idnumber, int stu_id) {//设置学生的学号
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				this->studentlist[i].idnumber = idnumber;
			}
		}
	}
	inline void set_stu_gender(string gender, int stu_id) {//设置学生的性别
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				this->studentlist[i].gender = gender;
			}
		}
	}
	inline void set_stu_score(string score_name, float score_value, int stu_id) {//设置学生的成绩
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				if (score_name == "C++程序设计") {
					this->studentlist[i].score.set_cpp_score(score_value);
				}
				else if (score_name == "高等数学") {
					this->studentlist[i].score.set_gaoshu_score(score_value);
				}
				else if (score_name == "线性代数") {
					this->studentlist[i].score.set_xiandai_score(score_value);
				}
				else if (score_name == "英语") {
					this->studentlist[i].score.set_english_score(score_value);
				}
				else if (score_name == "数据结构") {
					this->studentlist[i].score.set_sjjg_score(score_value);
				}
				else {
					cout << "没有找到您要更改的课程名称,请确保您的输入正确....." << endl;
				}
			}
		}
	}
	inline int get_stu_number() {
		return this->studentlist.size();
	}
	inline void show_rank() {//打印成绩并且排序
		int j;
		for (int i = 0; i < stu_amount - 1; i++) {//冒泡排序
			for (j = 0; j < stu_amount - 1 - i; j++) {
				if (studentlist[j].score.get_Total_score() > studentlist[i].score.get_Total_score()) {
					Student tmp = studentlist[j];
					studentlist[j] = studentlist[j + 1];
					studentlist[j + 1] = tmp;
				}
			}
		}
		cout << "\t\t成绩表" << endl;
		cout << "\t\t\t姓名----C++程序设计-----数据结构-----高等数学-----线性代数-----英语-----总分" << endl;
		for (int i = 0; i < stu_amount; i++) {//冒泡排序
			cout << "\t\t\t" << studentlist[i].name << " \t" << studentlist[i].score.get_Cpp_score() << "\t\t  " << studentlist[i].score.get_sjjg_score() << "\t  " << studentlist[i].score.get_Gaoshu_score() << "\t\t  " << studentlist[i].score.get_Xiandai_score() << "\t  " << studentlist[i].score.get_English_score() << "\t\t  " << studentlist[i].score.get_Total_score() << endl;
		}
		getchar();
		getchar();
		system("cls");
	}
	inline int get_stu_amount() {
		return this->stu_amount;
	}
	inline void print() {
		cout << "\t\t请选择你要打印柱状图的科目: " << endl;
		cout << "1.高等数学               2.线性代数" << endl;
		cout << "3.C++程序设计       4.数据结构" << endl;
		cout << "5.英语" << endl;
		int choose;
		cin >> choose;

		if (choose == 1) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//柱状图
			for (int i = 0; i < studentlist.size(); i++) {//统计不满60分的学生数量.
				if (studentlist[i].score.get_Gaoshu_score() <= 10) {
					tolbar[0]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 10 && studentlist[i].score.get_Gaoshu_score() <= 20) {
					tolbar[1]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 20 && studentlist[i].score.get_Gaoshu_score() <= 30) {
					tolbar[2]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 30 && studentlist[i].score.get_Gaoshu_score() <= 40) {
					tolbar[3]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 40 && studentlist[i].score.get_Gaoshu_score() <= 50) {
					tolbar[4]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 50 && studentlist[i].score.get_Gaoshu_score() <= 60) {
					tolbar[5]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 60 && studentlist[i].score.get_Gaoshu_score() <= 70) {
					tolbar[6]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 70 && studentlist[i].score.get_Gaoshu_score() <= 80) {
					tolbar[7]++;
				}
				else if (studentlist[i].score.get_Gaoshu_score() > 80 && studentlist[i].score.get_Gaoshu_score() <= 90) {
					tolbar[8]++;
				}
				else {
					tolbar[9]++;
				}
			}
			system("cls");
			cout << "高等数学成绩分段占比如下: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//四舍五入取整
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 2) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//柱状图
			for (int i = 0; i < stu_amount; i++) {//统计不满60分的学生数量.
				if (studentlist[i].score.get_Xiandai_score() <= 10) {
					tolbar[0]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 10 && studentlist[i].score.get_Xiandai_score() <= 20) {
					tolbar[1]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 20 && studentlist[i].score.get_Xiandai_score() <= 30) {
					tolbar[2]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 30 && studentlist[i].score.get_Xiandai_score() <= 40) {
					tolbar[3]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 40 && studentlist[i].score.get_Xiandai_score() <= 50) {
					tolbar[4]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 50 && studentlist[i].score.get_Xiandai_score() <= 60) {
					tolbar[5]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 60 && studentlist[i].score.get_Xiandai_score() <= 70) {
					tolbar[6]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 70 && studentlist[i].score.get_Xiandai_score() <= 80) {
					tolbar[7]++;
				}
				else if (studentlist[i].score.get_Xiandai_score() > 80 && studentlist[i].score.get_Xiandai_score() <= 90) {
					tolbar[8]++;
				}
				else {
					tolbar[9]++;
				}
			}
			system("cls");
			cout << "线性代数成绩分段占比如下: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//四舍五入取整
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 3) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//柱状图
			for (int i = 0; i < stu_amount; i++) {//统计不满60分的学生数量.
				if (studentlist[i].score.get_Cpp_score() <= 10) {
					tolbar[0]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 10 && studentlist[i].score.get_Cpp_score() <= 20) {
					tolbar[1]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 20 && studentlist[i].score.get_Cpp_score() <= 30) {
					tolbar[2]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 30 && studentlist[i].score.get_Cpp_score() <= 40) {
					tolbar[3]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 40 && studentlist[i].score.get_Cpp_score() <= 50) {
					tolbar[4]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 50 && studentlist[i].score.get_Cpp_score() <= 60) {
					tolbar[5]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 60 && studentlist[i].score.get_Cpp_score() <= 70) {
					tolbar[6]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 70 && studentlist[i].score.get_Cpp_score() <= 80) {
					tolbar[7]++;
				}
				else if (studentlist[i].score.get_Cpp_score() > 80 && studentlist[i].score.get_Cpp_score() <= 90) {
					tolbar[8]++;
				}
				else {
					tolbar[9]++;
				}
			}
			system("cls");
			cout << "C++程序设计成绩分段占比如下: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//四舍五入取整
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 4) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//柱状图
			for (int i = 0; i < stu_amount; i++) {//统计不满60分的学生数量.
				if (studentlist[i].score.get_sjjg_score() <= 10) {
					tolbar[0]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 10 && studentlist[i].score.get_sjjg_score() <= 20) {
					tolbar[1]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 20 && studentlist[i].score.get_sjjg_score() <= 30) {
					tolbar[2]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 30 && studentlist[i].score.get_sjjg_score() <= 40) {
					tolbar[3]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 40 && studentlist[i].score.get_sjjg_score() <= 50) {
					tolbar[4]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 50 && studentlist[i].score.get_sjjg_score() <= 60) {
					tolbar[5]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 60 && studentlist[i].score.get_sjjg_score() <= 70) {
					tolbar[6]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 70 && studentlist[i].score.get_sjjg_score() <= 80) {
					tolbar[7]++;
				}
				else if (studentlist[i].score.get_sjjg_score() > 80 && studentlist[i].score.get_sjjg_score() <= 90) {
					tolbar[8]++;
				}
				else {
					tolbar[9]++;
				}
			}
			system("cls");
			cout << "数据结构成绩分段占比如下: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//四舍五入取整
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 5) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//柱状图
			for (int i = 0; i < stu_amount; i++) {//统计不满60分的学生数量.
				if (studentlist[i].score.get_English_score() <= 10) {
					tolbar[0]++;
				}
				else if (studentlist[i].score.get_English_score() > 10 && studentlist[i].score.get_English_score() <= 20) {
					tolbar[1]++;
				}
				else if (studentlist[i].score.get_English_score() > 20 && studentlist[i].score.get_English_score() <= 30) {
					tolbar[2]++;
				}
				else if (studentlist[i].score.get_English_score() > 30 && studentlist[i].score.get_English_score() <= 40) {
					tolbar[3]++;
				}
				else if (studentlist[i].score.get_English_score() > 40 && studentlist[i].score.get_English_score() <= 50) {
					tolbar[4]++;
				}
				else if (studentlist[i].score.get_English_score() > 50 && studentlist[i].score.get_English_score() <= 60) {
					tolbar[5]++;
				}
				else if (studentlist[i].score.get_English_score() > 60 && studentlist[i].score.get_English_score() <= 70) {
					tolbar[6]++;
				}
				else if (studentlist[i].score.get_English_score() > 70 && studentlist[i].score.get_English_score() <= 80) {
					tolbar[7]++;
				}
				else if (studentlist[i].score.get_English_score() > 80 && studentlist[i].score.get_English_score() <= 90) {
					tolbar[8]++;
				}
				else {
					tolbar[9]++;
				}
			}
			system("cls");
			cout << "英语成绩分段占比如下: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//四舍五入取整
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		getchar();
		getchar();
		system("cls");
	}
	friend class File;
private:
	UI newui; 
	vector<Student> studentlist;//容器
	int stu_amount;
};