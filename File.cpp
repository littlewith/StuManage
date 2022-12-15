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
/*�ļ�����*/
class File {
public:
	inline void fetch_db_init();//���ݿ��ʼ��
	inline int fetch_db_login(string username_input,string passwd_input);//��¼
	inline int fetch_db_count();
	inline int fetch_db_chg_save_account(string newusername,string newpasswd,string nnewu,string nnewp);
	inline int fetch_db_input(All_students& newclass);//����ѧ����Ϣ
	inline int fetch_db_output(All_students& newclass);//���ѧ����Ϣ
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
			if (finalstring==this->accountist[i]) {//ƥ��ɹ�
				this->accountist[i] = newusernamed + '|' + newpasswdd + '@' + finatmpj;
			}
		}
	}
	ofstream accountfile("DataAccounts.lit", ios::trunc);//���ٵķ�ʽ��
	for (int i = 0; i < accountist.size(); i++) {
		accountfile << accountist[i];
		accountfile << '\n';
	}
	accountfile.close();
	return 0;
}

inline int File::fetch_db_output(All_students& newclass) {
	ofstream file_ptr("Database.lit", ios::trunc);//�����д��
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
	return stu_amount;//����ѧ������
}

 inline int File::fetch_db_input(All_students& newclass) {
		ifstream file_ptr("Database.lit");
		int stu_amount;
		file_ptr >> stu_amount;
		cout << "\t\t��⵽���ݿ��д��ڵ�ѧ������Ϊ: " << stu_amount << endl;
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
	file_ptrj.open("DataAccounts.lit", ios::in);//�����ļ�
	string content = "";//raw

	username_input = MD5(username_input).toStr();
	passwd_input = MD5(passwd_input).toStr();//תΪ����

	/*
	C++���ṩ��Map�������ڷ�װ��������Python�е��ֵ�
	*/
	//�����˻��ֵ�
	//ACCOUNT account;

	while (!(file_ptrj.peek() == EOF)) {
		string tmp_data = "";
		getline(file_ptrj, tmp_data);
		this->accountist.push_back(tmp_data);//ѹ������
	}
	file_ptrj.close();
	
	fstream file_ptr;
	file_ptr.open("DataAccounts.lit", ios::in);
	file_ptr.seekg(0);//ת��ͷ
	int k = file_ptr.peek();
	
	while (!(file_ptr.peek() == EOF)) {
		int username_length = 0;
		int passwd_length = 0;
		int identify_length = 0;
		char* username_tmp = new char[256];
		char* passwd_tmp = new char[256];
		char* identify_tmp = new char[256];
		getline(file_ptr, content);//��ȡһ��
		//cout << content << endl;
		//cout << content << endl;
		//cout<<"fgx" << endl;
		for (int i = 0; i < content.length(); i++) {
			if (content[i] != '|') {
				username_tmp[i] = content[i];//û����ֹ���žͼ�����ֵ��
				username_length++;//�û�������
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
					identify_length++;//���볤��
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

		//��ѭ������֤��ݡ�
		bool res2 = false;//���Ĭ�ϲ��ǹ���Ա
		for (int i = 0; i <= 100; i++) {
			string id = to_string(i);
			if (MD5(id).toStr() == identify_file) {
				if (i % 2 == 0) {//���Ϊż������ô���ǹ���Ա
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
				return 0;//0�����Ȩ��
			}
			else {
				return 1;//1����ͨ�û�Ȩ��
			}
		}
		else {
			continue;
		}
	}
	return 2;//��¼ʧ��
}

inline void File::fetch_db_init(){
	fstream file_ptr_list;//�½�ѧ�����ݿ��ļ�����
	fstream file_ptr_manager;//�½�������˺����ݿ��ļ�����

	file_ptr_list.open("Database.lit", ios::in);//���ļ�������in�ķ�ʽ����
	file_ptr_manager.open("DataAccounts.lit", ios::in);
	if (!file_ptr_list.is_open()) {
		cout << "Oops....��⵽" << "ѧ�����ݿ�" << "�����ڣ�׼����ʼ�����ݿ�" << endl;
		int i = 0;//i���ڼ�����ͳ���½��ļ�����
		do {
			file_ptr_list.close();
			file_ptr_list.open("Database.lit", ios::app); file_ptr_list.close();//����������ݿ��ر��ļ�

			i++;
			if (file_ptr_list.open("Database.lit", ios::in), file_ptr_list.is_open()) {
				cout << "Database.lit" << "���ݿ��ʼ�����ݿ����" << endl;
				break;
				return;
			}
		} while (file_ptr_list.open("Database.lit", ios::in), !file_ptr_list.is_open() && i < 5);
		cout << "����������⣬�����°�װ������" << endl;
		//���������λ����½�ʧ�ܵĻ�����ô��ֱ�Ӵ�أ���������
		exit(-1);
	}
	else {
		cout << "\t\tѧ�����ݿ����ҵ�.......OK" << endl;
		Sleep(1000);
	}
	if (!file_ptr_manager.is_open()) {
		cout << "Oops....��⵽" << "�˻����ݿ�" << "�����ڣ�׼����ʼ�����ݿ�" << endl;
		int i = 0;//i���ڼ�����ͳ���½��ļ�����
		do {
			file_ptr_list.close();
			file_ptr_list.open("DataAccounts.lit", ios::app); file_ptr_list.close();//����������ݿ��ر��ļ�

			i++;
			if (file_ptr_list.open("DataAccounts.lit", ios::in), file_ptr_list.is_open()) {
				cout << "DataAccounts.lit" << "���ݿ��ʼ�����ݿ����" << endl;
				break;
				return;
			}
		} while (file_ptr_list.open("DataAccounts.lit", ios::in), !file_ptr_list.is_open() && i < 5);
		cout << "����������⣬�����°�װ������" << endl;
		//���������λ����½�ʧ�ܵĻ�����ô��ֱ�Ӵ�أ���������
		exit(-1);
	}
	else {
		cout << "\t\t�˻����ݿ����ҵ�.......OK" << endl;
		Sleep(1000);
		system("cls");
	}
}