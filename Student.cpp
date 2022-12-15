#pragma once
#define EXIT_SYSTEM_INFO 1001
#include<iostream>
#include<string>
using namespace std;
#include<fstream>
#include<vector>
#include"md5.h"
#include"UI.cpp"
class Account {//�˻��࣬�洢�û��˻���Ϣ�����潫���ù���Ա��ѧ�����м̳�
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
		if (setuid % 2 == 0) {//ʶ��Ϊ����Ա�˻�
			srand(time(0));
			int tmp = rand() % 100;
			if (tmp % 2 == 0) {
				this->uid = MD5(to_string(tmp)).toStr();
			}
			else {
				this->uid = MD5(to_string(tmp + 1)).toStr();
			}
		}
		else {//ʶ��Ϊ��ͨ�û�
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
	inline string  get_uid() {//�����û���ʶ
		return this->uid;
	}
private:
	string username;
	string passwd;
	string uid;
};
class Lesson {//�����γ��ࣺ���ڴ洢�γ̵����ֺͷ���
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
	string lesson_name;//�γ�����
	float lesson_score;//�γ̷���
};
class Multi_lessons {
public:
	inline Multi_lessons() :Cpp("C++�������"), Gaoshu("�ߵ���ѧ"), Xiandai("���Դ���"), English("Ӣ��"), Shujujiegou("���ݽṹ") {

	}
	inline Multi_lessons(float cppscore, float gaoshuscore, float xiandaiscore, float enscore, float shujuscore) :Cpp("C++�������", cppscore), Gaoshu("�ߵ���ѧ", gaoshuscore), Xiandai("���Դ���", xiandaiscore), English("Ӣ��", enscore), Shujujiegou("���ݽṹ", shujuscore) {
		//����½�һ�����캯��
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
	inline float get_Total_score() {//�����ܷ�
		return this->Cpp.get_lesson_score() + this->English.get_lesson_score() + this->Gaoshu.get_lesson_score() + this->Shujujiegou.get_lesson_score() + this->English.get_lesson_score();
	}
	inline float get_Cpp_score() {
		return this->Cpp.get_lesson_score();
		//����CPP�ɼ���
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
class Student {//ѧ���࣬�����������ڴ洢��Ϣ���ѡ�
public:
	//inline Student(){}
	//inline ~Student(){}
	string name;
	string idnumber;//ѧ��
	string gender;
	Multi_lessons score;//�ɼ�
	int stu_id;//���
};
class All_students {
public:
	All_students() {
		this->stu_amount = 0;
		/*
		for (int i = 0; i < stu_amount; i++) {
			Student tmpstu;//������ܻ����
			tmpstu.stu_id = i;
			this->studentlist.push_back(tmpstu);//��������
		}
		*/
	}
	 ~All_students() {
		//����
		ofstream file_ptr("Database.lit", ios::trunc);//�����д��
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
			cout << "��Ҫ��ʲô��" << endl;
			cout << "1.����    2.ѧ��   3.�Ա�  4.�ɼ�" << endl;
			cout << "�����ϼ�������5,   �˳�������6" << endl;
			int choose;
			cin >> choose;
			if (choose == 1) {
				string name;
				cout << "����ԭ��������: ";
				cin >> name;
				cout << "�ĳ�ʲô��";
				string newname;
				cin >> newname;
				for (int i = 0; i < studentlist.size(); i++) {
					if (studentlist[i].name == name) {
						this->studentlist[i].name = newname;
					}
				}
				cout << "�ɹ���" << endl;
				getchar();
				getchar();

				return;
			}
			else if (choose == 2) {
				string name;
				cout << "����ԭ����ѧ��: ";
				cin >> name;
				cout << "�ĳ�ʲô��";
				string newname;
				cin >> newname;
				for (int i = 0; i < studentlist.size(); i++) {
					if (studentlist[i].idnumber == name) {
						this->studentlist[i].name = newname;
					}
				}
				cout << "�ɹ���" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 3) {
				string name;
				cout << "���ĸ�ͬѧ�ģ�: ";
				cin >> name;
				cout << "�ĳ�ʲô��";
				string newname;
				cin >> newname;
				for (int i = 0; i < studentlist.size(); i++) {
					if (studentlist[i].name == name) {
						this->studentlist[i].gender = newname;
					}
				}
				cout << "�ɹ���" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 4) {
				while (true) {
					cout << "\t\t��˭�ģ�";
					string name;
					cin >> name;
					cout << "\t\tѡ����Ҫ����һ�ſεĳɼ���" << endl;
					cout << "\t\t1.����  2.�ߴ�  3.C++  4.Ӣ��  5.���ݽṹ" << endl;
					cout << "\t\t����6���˻���һ��,����7����������" << endl;
					int choose;
					cin >> choose;
					cout << "\t\t�ĳɶ��٣�";
					float new_score;
					cin >> new_score;
					if (choose == 1) {
						for (int i = 0; i < studentlist.size(); i++) {
							if (studentlist[i].name == name) {
								studentlist[i].score.set_gaoshu_score(new_score);
							}
						}
						cout << "�ɹ���" << endl;
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
						cout << "�ɹ���" << endl;
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
						cout << "�ɹ���" << endl;
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
						cout << "�ɹ���" << endl;
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
						cout << "�ɹ���" << endl;
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
						cout << "����ѡ���ȷ.....������" << endl;
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
				cout << "û�����ѡ��......������";
				return;
			}
			cout << "��Ϣ���³ɹ�!" << endl;
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
		cout << "C++������Ƶĺϸ���Ϊ: " << cpp * 100 << "%" << endl;

		float sjjg;
		float count1 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_sjjg_score() >= 60) {
				count1++;
			}
		}
		sjjg = count1 / studentlist.size();
		cout << "���ݽṹ�ĺϸ���Ϊ: " << sjjg * 100 << "%" << endl;

		float gdsx;
		float count2 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_Gaoshu_score() >= 60) {
				count2++;
			}
		}
		gdsx = count2 / studentlist.size();
		cout << "�ߵ���ѧ�ĺϸ���Ϊ: " << gdsx * 100 << "%" << endl;

		float xxds;
		float count3 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_Xiandai_score() >= 60) {
				count3++;
			}
		}
		xxds = count3 / studentlist.size();
		cout << "���Դ����ĺϸ���Ϊ: " << xxds * 100 << "%" << endl;

		float eng;
		float count4 = 0;
		for (int i = 0; i < this->studentlist.size(); i++) {

			if (this->studentlist[i].score.get_English_score() >= 60) {
				count4++;
			}
		}
		eng = count4 / studentlist.size();
		cout << "Ӣ��ĺϸ���Ϊ: " << eng * 100 << "%" << endl;
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

		cout << "����ƽ����:" << gaoshusum << endl;
		cout << "C++ƽ����:" << cppsum << endl;
		cout << "�ߴ�ƽ����:" << xxiandaisum << endl;
		cout << "Ӣ��ƽ����:" << engsum << endl;
		cout << "���ݽṹƽ����:" << sjjgsum << endl;
		getchar();
		getchar();
		system("cls");
		return;
	}
	inline void del() {
		int choose;
		cout << "\t\t======��ѡ����ɾ��ѧ���ķ�ʽ======" << endl;
		cout << "\t\t1.����ѧ�Ž���ɾ��          2.������������ɾ��" << endl;
		cin >> choose;
		if (choose == 1) {
			cout << "��������Ҫɾ����ѧ����ѧ�ţ�";
			string number;
			cin >> number;
			for (int i = 0; i < studentlist.size(); i++) {
				if (number == studentlist[i].idnumber) {
					studentlist.erase(studentlist.begin() + i);
				}
			}
			this->stu_amount--;
			cout << "ɾ���ɹ���" << endl;
			Sleep(1000);
		}
		else if (choose == 2) {
			cout << "��������Ҫɾ����ѧ����������";
			string name;
			cin >> name;
			for (int i = 0; i < studentlist.size(); i++) {
				if (name == studentlist[i].name) {
					studentlist.erase(studentlist.begin() + i);
				}
			}
			this->stu_amount--;
			cout << "ɾ���ɹ���" << endl;
			Sleep(1000);
		}
		else {
			cout << "�������ѡ���ȷ������������......." << endl;
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
		this->studentlist.push_back(newstu);//��������
		this->stu_amount++;
	}
	inline void add_stu() {
		system("cls");
		Student newstudent;
		newstudent.stu_id = this->studentlist.size();
		cout << "\t\t========����ѧ����Ϣ========" << endl;
		cout << "������ѧ������: ";
		cin >> newstudent.name;
		cout << endl;

		cout << "������ѧ��ѧ��: ";
		cin >> newstudent.idnumber;
		cout << endl;

		cout << "������ѧ���Ա�: ";
		cin >> newstudent.gender;
		cout << endl;

		cout << "------���濪ʼ¼���ѧ���ĳɼ���Ϣ: ------" << endl;;
		cout << "������ߵ���ѧ�ɼ�: ";
		float gs;
		cin >> gs;
		newstudent.score.set_gaoshu_score(gs);

		cout << "���������Դ����ɼ�: ";
		cin >> gs;
		newstudent.score.set_xiandai_score(gs);

		cout << "������Ӣ��ɼ�: ";
		cin >> gs;
		newstudent.score.set_english_score(gs);

		cout << "������C++������Ƴɼ�: ";
		cin >> gs;
		newstudent.score.set_cpp_score(gs);

		cout << "���������ݽṹ�ɼ�: ";
		cin >> gs;
		newstudent.score.set_sjjg_score(gs);

		studentlist.push_back(newstudent);
		this->stu_amount++;//������һ
		cout << "ѧ����Ϣ���ӳɹ�!" << endl;
		getchar();
		getchar();
		return;
	}
	inline int get_id_by_name(string name) {//ͨ����������ȡѧ����Ψһ��ʶ��
		for (int i = 0; i < stu_amount; i++) {
			if (studentlist[i].name == name) {
				return this->studentlist[i].stu_id;
			}
		}
	}
	inline void find_students() {
		string names;
		string numberd;
		cout << "Ϊ��ȷ����ȫ�����ٴ�����������ѧ��: " << endl;
		cout << "����: ";
		cin >> names;
		cout << "ѧ��: ";
		cin >> numberd;
		for (int i = 0; i < stu_amount; i++) {
			if (names == studentlist[i].name && numberd == studentlist[i].idnumber) {
				cout << "����: " << studentlist[i].name << "  ѧ��: " << studentlist[i].idnumber << "  �Ա�: " << studentlist[i].gender << endl;
				cout << "�ߵ���ѧ: " << studentlist[i].score.get_Gaoshu_score() << "  ���Դ���: " << studentlist[i].score.get_Xiandai_score() << "  Ӣ��: " << studentlist[i].score.get_English_score() << "  C++�������: " << studentlist[i].score.get_Cpp_score() << "  ���ݽṹ: " << studentlist[i].score.get_sjjg_score() << endl;
				getchar();
				getchar();
				system("cls");
				return;
			}
		}
		cout << "\t\t��֤ʧ�ܣ������ԣ�����" << endl;
		getchar();
		getchar();
		system("cls");
		return;
	}
	inline void find_student() {//����ѧ��
		while (true){
			system("cls");
			int choose;
			cout << "\t\t======��ѡ��������ѧ���ķ�ʽ======" << endl;
			cout << "\t\t1.����ѧ�Ž��в���          2.�����������в���" << endl;
			cout << "\t\t3.������һ��  " << endl;
			cin >> choose;
			if (choose == 1) {
				cout << "��������Ҫ���ҵ�ѧ����ѧ�ţ�";
				string number;
				cin >> number;
				for (int i = 0; i < studentlist.size(); i++) {
					if (number == studentlist[i].idnumber) {
						cout << "����: " << studentlist[i].name << "  ѧ��: " << studentlist[i].idnumber << "  �Ա�: " << studentlist[i].gender << endl;
						cout << "�ߵ���ѧ: " << studentlist[i].score.get_Gaoshu_score() << "  ���Դ���: " << studentlist[i].score.get_Xiandai_score() << "  Ӣ��: " << studentlist[i].score.get_English_score() << "  C++�������: " << studentlist[i].score.get_Cpp_score() << "  ���ݽṹ: " << studentlist[i].score.get_sjjg_score() << endl;
						getchar();
						getchar();
						system("cls");
						return;
					}
				}
				system("cls");
				cout << "\t\tû�ҵ�....������" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 2) {
				cout << "��������Ҫ���ҵ�ѧ����������";
				string name;
				cin >> name;
				for (int i = 0; i < studentlist.size(); i++) {
					if (name == studentlist[i].name) {
						cout << "����: " << studentlist[i].name << "  ѧ��: " << studentlist[i].idnumber << "  �Ա�: " << studentlist[i].gender << endl;
						cout << "�ߵ���ѧ: " << studentlist[i].score.get_Gaoshu_score() << "  ���Դ���: " << studentlist[i].score.get_Xiandai_score() << "  Ӣ��: " << studentlist[i].score.get_English_score() << "  C++�������: " << studentlist[i].score.get_Cpp_score() << "  ���ݽṹ: " << studentlist[i].score.get_sjjg_score() << endl;
						getchar();
						getchar();
						system("cls");
						return;
					}
				}
				system("cls");
				cout << "û�ҵ�....������" << endl;
				getchar();
				getchar();
				return;
			}
			else if (choose == 3) {
				return;
			}
			else {
				system("cls");
				cout << "�������ѡ���ȷ������������......." << endl;
				getchar();
				this->find_student();
			}
			return;
		}
		
	}
	inline void set_stu_name(string name, int stu_id) {//����ѧ��������
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				this->studentlist[i].name = name;
			}
		}
	}
	inline void set_stu_idnumber(string idnumber, int stu_id) {//����ѧ����ѧ��
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				this->studentlist[i].idnumber = idnumber;
			}
		}
	}
	inline void set_stu_gender(string gender, int stu_id) {//����ѧ�����Ա�
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				this->studentlist[i].gender = gender;
			}
		}
	}
	inline void set_stu_score(string score_name, float score_value, int stu_id) {//����ѧ���ĳɼ�
		for (int i = 0; i < this->stu_amount; i++) {
			if (this->studentlist[i].stu_id == stu_id) {
				if (score_name == "C++�������") {
					this->studentlist[i].score.set_cpp_score(score_value);
				}
				else if (score_name == "�ߵ���ѧ") {
					this->studentlist[i].score.set_gaoshu_score(score_value);
				}
				else if (score_name == "���Դ���") {
					this->studentlist[i].score.set_xiandai_score(score_value);
				}
				else if (score_name == "Ӣ��") {
					this->studentlist[i].score.set_english_score(score_value);
				}
				else if (score_name == "���ݽṹ") {
					this->studentlist[i].score.set_sjjg_score(score_value);
				}
				else {
					cout << "û���ҵ���Ҫ���ĵĿγ�����,��ȷ������������ȷ....." << endl;
				}
			}
		}
	}
	inline int get_stu_number() {
		return this->studentlist.size();
	}
	inline void show_rank() {//��ӡ�ɼ���������
		int j;
		for (int i = 0; i < stu_amount - 1; i++) {//ð������
			for (j = 0; j < stu_amount - 1 - i; j++) {
				if (studentlist[j].score.get_Total_score() > studentlist[i].score.get_Total_score()) {
					Student tmp = studentlist[j];
					studentlist[j] = studentlist[j + 1];
					studentlist[j + 1] = tmp;
				}
			}
		}
		cout << "\t\t�ɼ���" << endl;
		cout << "\t\t\t����----C++�������-----���ݽṹ-----�ߵ���ѧ-----���Դ���-----Ӣ��-----�ܷ�" << endl;
		for (int i = 0; i < stu_amount; i++) {//ð������
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
		cout << "\t\t��ѡ����Ҫ��ӡ��״ͼ�Ŀ�Ŀ: " << endl;
		cout << "1.�ߵ���ѧ               2.���Դ���" << endl;
		cout << "3.C++�������       4.���ݽṹ" << endl;
		cout << "5.Ӣ��" << endl;
		int choose;
		cin >> choose;

		if (choose == 1) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//��״ͼ
			for (int i = 0; i < studentlist.size(); i++) {//ͳ�Ʋ���60�ֵ�ѧ������.
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
			cout << "�ߵ���ѧ�ɼ��ֶ�ռ������: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//��������ȡ��
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 2) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//��״ͼ
			for (int i = 0; i < stu_amount; i++) {//ͳ�Ʋ���60�ֵ�ѧ������.
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
			cout << "���Դ����ɼ��ֶ�ռ������: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//��������ȡ��
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 3) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//��״ͼ
			for (int i = 0; i < stu_amount; i++) {//ͳ�Ʋ���60�ֵ�ѧ������.
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
			cout << "C++������Ƴɼ��ֶ�ռ������: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//��������ȡ��
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 4) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//��״ͼ
			for (int i = 0; i < stu_amount; i++) {//ͳ�Ʋ���60�ֵ�ѧ������.
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
			cout << "���ݽṹ�ɼ��ֶ�ռ������: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//��������ȡ��
				for (int j = 0; j < tmpbar; j++) {
					cout << "6";
				}
				cout << endl;
			}
		}
		else if (choose == 5) {
			float tolbar[10] = { 0,0,0,0,0,0,0,0,0,0 };//��״ͼ
			for (int i = 0; i < stu_amount; i++) {//ͳ�Ʋ���60�ֵ�ѧ������.
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
			cout << "Ӣ��ɼ��ֶ�ռ������: " << endl;
			for (int i = 0; i < 10; i++) {
				cout << i * 10 << "--" << (i + 1) * 10 << ":";
				tolbar[i] = tolbar[i] / this->stu_amount * 100;
				int tmpbar = round(tolbar[i]);//��������ȡ��
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
	vector<Student> studentlist;//����
	int stu_amount;
};