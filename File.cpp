#pragma once
#define EXIT_SYSTEM_INFO 1001
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#include<Windows.h>
#include"md5.h"
#include "Student.cpp"
#include<vector>
/*文件处理*/
class File {
public:
	inline void fetch_db_init();//数据库初始化
	inline int fetch_db_login(string username_input,string passwd_input);//登录
	inline int fetch_db_count();
	inline int fetch_db_chg_save_account(string newusername,string newpasswd,string nnewu,string nnewp);
	inline int fetch_db_input(All_students& newclass);//读入学生信息
	inline int fetch_db_output(All_students& newclass);//输出学生信息
private:
	vector<string> accountist;
};

inline int File::fetch_db_chg_save_account(string newusername,string newpasswd,string nnewu,string nnewp){

	string oldusername = MD5(newusername).toStr();
	string oldpasswd = MD5(newpasswd).toStr();
	string newusernamed = MD5(nnewu).toStr();
	string newpasswdd = MD5(nnewp).toStr();
	for (int i = 0; i < this->accountist.size(); i++) {
		for (int j = 0; j <= 100; j++) {
			string tmpj = to_string(j);
			string finatmpj = MD5(tmpj).toStr();
			string finalstring = oldusername + '|' + oldpasswd + '@' + finatmpj;
			if (finalstring==this->accountist[i]) {//匹配成功
				this->accountist[i] = newusernamed + '|' + newpasswdd + '@' + finatmpj;
			}
		}
	}
	ofstream accountfile("DataAccounts.lit", ios::trunc);//销毁的方式打开
	for (int i = 0; i < accountist.size(); i++) {
		accountfile << accountist[i];
		accountfile << '\n';
	}
	accountfile.close();
	return 0;
}

inline int File::fetch_db_output(All_students& newclass) {
	ofstream file_ptr("Database.lit", ios::trunc);//清空重写。
	file_ptr << newclass.studentlist.size() << endl;
	for (int i = 0; i < newclass.studentlist.size(); i++) {
		file_ptr << newclass.studentlist[i].name << endl;
		file_ptr << newclass.studentlist[i].idnumber << endl;
		file_ptr << newclass.studentlist[i].gender << endl;
		file_ptr << newclass.studentlist[i].score.get_Cpp_score() << endl;
		file_ptr << newclass.studentlist[i].score.get_Gaoshu_score() << endl;
		file_ptr << newclass.studentlist[i].score.get_Xiandai_score() << endl;
		file_ptr << newclass.studentlist[i].score.get_sjjg_score() << endl;
		if (i == newclass.studentlist.size() - 1) {
			file_ptr << newclass.studentlist[i].score.get_English_score();
		}
		else {
			file_ptr << newclass.studentlist[i].score.get_English_score() << endl;
		}
	}
	}

inline int File::fetch_db_count() {
	ifstream file_ptr("Database.lit");
	int stu_amount;
	file_ptr >> stu_amount;
	return stu_amount;//返回学生数量
}

 inline int File::fetch_db_input(All_students& newclass) {
		ifstream file_ptr("Database.lit");
		int stu_amount;
		file_ptr >> stu_amount;
		cout << "\t\t检测到数据库中存在的学生数量为: " << stu_amount << endl;
		Sleep(1000);
		system("cls");
		while (file_ptr.peek() != EOF) {
			string name;
			file_ptr >> name;
			//cout << name<<endl;
			string stu_number;
			file_ptr >> stu_number;
			//cout << stu_number<<endl;
			string gender;
			file_ptr >> gender;
			//cout << gender<<endl;
			float cppScore;
			file_ptr >> cppScore;
			//cout << cppScore<<endl;
			float GaoshuScore;
			file_ptr >> GaoshuScore;
			//cout << GaoshuScore<<endl;
			float XiandaiScore;
			file_ptr >> XiandaiScore;
			//cout << XiandaiScore<<endl;
			float ShujujiegouScore;
			file_ptr >> ShujujiegouScore;
			//cout << ShujujiegouScore<<endl;
			float EnglishScore;
			file_ptr >> EnglishScore;
			//cout << EnglishScore<<endl;
			newclass.add_stu(name, stu_number, gender, cppScore, ShujujiegouScore, GaoshuScore, EnglishScore, XiandaiScore);
		}
		return 0;
	}


inline int File::fetch_db_login(string username_input, string passwd_input) {
	fstream file_ptrj;
	file_ptrj.open("DataAccounts.lit", ios::in);//读入文件
	string content = "";//raw

	username_input = MD5(username_input).toStr();
	passwd_input = MD5(passwd_input).toStr();//转为加密

	/*
	C++中提供了Map对象用于封装，类似于Python中的字典
	*/
	//定义账户字典
	//ACCOUNT account;

	while (!(file_ptrj.peek() == EOF)) {
		string tmp_data = "";
		getline(file_ptrj, tmp_data);
		this->accountist.push_back(tmp_data);//压入数据
	}
	file_ptrj.close();
	
	fstream file_ptr;
	file_ptr.open("DataAccounts.lit", ios::in);
	file_ptr.seekg(0);//转到头
	int k = file_ptr.peek();
	
	while (!(file_ptr.peek() == EOF)) {
		int username_length = 0;
		int passwd_length = 0;
		int identify_length = 0;
		char* username_tmp = new char[256];
		char* passwd_tmp = new char[256];
		char* identify_tmp = new char[256];
		getline(file_ptr, content);//读取一行
		//cout << content << endl;
		//cout << content << endl;
		//cout<<"fgx" << endl;
		for (int i = 0; i < content.length(); i++) {
			if (content[i] != '|') {
				username_tmp[i] = content[i];//没到截止符号就继续赋值。
				username_length++;//用户名长度
			}
			else {
				break;
			}
		}

		//============================================//

		for (int i = 0; i < content.length(); i++) {
			if (!(content[i] == '|')) {

			}
			else {
				int k = 0;
				for (int j = i + 1; content[j] != '@'; j++, k++) {
					passwd_tmp[k] = content[j];
					passwd_length++;
				}
				break;
			}
		}

		//===============================================//

		for (int i = 0; i < content.length(); i++) {
			if (!(content[i] == '@')) {

			}
			else {
				int k = 0;
				for (int j = i + 1; j < content.length(); j++, k++) {
					identify_tmp[k] = content[j];
					identify_length++;//密码长度
				}
				break;
			}
		}
		string username_file = username_tmp;
		string passwd_file = passwd_tmp;
		string identify_file = identify_tmp;

		identify_file = identify_file.substr(0, identify_length);
		username_file = username_file.substr(0, username_length);
		passwd_file = passwd_file.substr(0, passwd_length);

		//cout << username_file << endl;
		//cout << passwd_file << endl;

		//用循环来验证身份。
		bool res2 = false;//身份默认不是管理员
		for (int i = 0; i <= 100; i++) {
			string id = to_string(i);
			if (MD5(id).toStr() == identify_file) {
				if (i % 2 == 0) {//如果为偶数，那么就是管理员
					res2 = true;
					break;
				}
				else {
					res2 = false;
					break;
				}
			}
		}

		//cout << username_file << endl;
		//cout << passwd_file << endl;
		//cout << identify_file << endl;


		//bool res1 = username_file.compare(username_input);
		//bool res2 = passwd_file.compare(passwd_input);
		bool res1 = username_input == username_file && passwd_input == passwd_file;

		if (res1) {
			if (res2) {
				return 0;//0是最高权限
			}
			else {
				return 1;//1是普通用户权限
			}
		}
		else {
			continue;
		}
	}
	return 2;//登录失败
}

inline void File::fetch_db_init(){
	fstream file_ptr_list;//新建学生数据库文件对象；
	fstream file_ptr_manager;//新建程序的账号数据库文件对象；

	file_ptr_list.open("Database.lit", ios::in);//打开文件，先以in的方式读入
	file_ptr_manager.open("DataAccounts.lit", ios::in);
	if (!file_ptr_list.is_open()) {
		cout << "Oops....检测到" << "学生数据库" << "不存在，准备初始化数据库" << endl;
		int i = 0;//i用于计数，统计新建文件次数
		do {
			file_ptr_list.close();
			file_ptr_list.open("Database.lit", ios::app); file_ptr_list.close();//创建完成数据库后关闭文件

			i++;
			if (file_ptr_list.open("Database.lit", ios::in), file_ptr_list.is_open()) {
				cout << "Database.lit" << "数据库初始化数据库完成" << endl;
				break;
				return;
			}
		} while (file_ptr_list.open("Database.lit", ios::in), !file_ptr_list.is_open() && i < 5);
		cout << "程序出现问题，请重新安装程序解决" << endl;
		//如果超过五次还是新建失败的话，那么就直接打回，结束程序
		exit(-1);
	}
	else {
		cout << "\t\t学生数据库已找到.......OK" << endl;
		Sleep(1000);
	}
	if (!file_ptr_manager.is_open()) {
		cout << "Oops....检测到" << "账户数据库" << "不存在，准备初始化数据库" << endl;
		int i = 0;//i用于计数，统计新建文件次数
		do {
			file_ptr_list.close();
			file_ptr_list.open("DataAccounts.lit", ios::app); file_ptr_list.close();//创建完成数据库后关闭文件

			i++;
			if (file_ptr_list.open("DataAccounts.lit", ios::in), file_ptr_list.is_open()) {
				cout << "DataAccounts.lit" << "数据库初始化数据库完成" << endl;
				break;
				return;
			}
		} while (file_ptr_list.open("DataAccounts.lit", ios::in), !file_ptr_list.is_open() && i < 5);
		cout << "程序出现问题，请重新安装程序解决" << endl;
		//如果超过五次还是新建失败的话，那么就直接打回，结束程序
		exit(-1);
	}
	else {
		cout << "\t\t账户数据库已找到.......OK" << endl;
		Sleep(1000);
		system("cls");
	}
}