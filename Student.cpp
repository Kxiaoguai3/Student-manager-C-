#include "Student.h"
#include <iostream>
using namespace std;

//���캯��
//Student::Student(char* name_, char* gender_, char* age_, char* origin_, char* address_, char* phone_) : name(name_), gender(gender_), age(age_), origin(origin_), address(address_), phone(phone_) {}
//��������
Student::~Student() {cout << "ѧ���������" << endl;}

//����ѧ������
void Student::SetName(char* name) {
	/*name = new char[20];
	cin >> name;*/
	this->name = name;
}

//����ѧ���Ա�
void Student::SetGender(char* gender) {
	/*gender = new char[10];
	cin >> gender;*/
	this->gender = gender;
}

//����ѧ������
void Student::SetAge(char* age) {
	/*age = new char[10];
	cin >> age;*/
	this->age = age;
}

//����ѧ������
void Student::SetOrigin(char* origin) {
	/*origin = new char[20];
	cin >> origin;*/
	this->origin = origin;
}

//����ѧ����ַ
void Student::SetAddress(char* address) {
	/*address = new char[50];
	cin >> address;*/
	this->address = address;
}

//����ѧ���绰
void Student::SetPhone(char* phone) {
	/*phone = new char[20];
	cin >> phone;*/
	this->phone = phone;
}

//����ѧ����Ϣ
void Student::SetInfo() {
	char* name = new char[20];
	char* gender = new char[10];
	char* age = new char[10];
	char* origin = new char[20];
	char* address = new char[50];
	char* phone = new char[20];

	cout << "������ѧ��������";
	cin >> name;
	cout << "������ѧ���Ա�";
	cin >> gender;
	cout << "������ѧ�����䣺";
	cin >> age;
	cout << "������ѧ�����᣺";
	cin >> origin;
	cout << "������ѧ����ַ��";
	cin >> address;
	cout << "������ѧ���绰��";
	cin >> phone;

	SetName(name);
	SetGender(gender);
	SetAge(age);
	SetOrigin(origin);
	SetAddress(address);
	SetPhone(phone);
}
