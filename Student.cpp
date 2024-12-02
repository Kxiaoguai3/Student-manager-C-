#include "Student.h"
#include <iostream>
using namespace std;

//构造函数
//Student::Student(char* name_, char* gender_, char* age_, char* origin_, char* address_, char* phone_) : name(name_), gender(gender_), age(age_), origin(origin_), address(address_), phone(phone_) {}
//析构函数
Student::~Student() {cout << "学生类已清除" << endl;}

//设置学生姓名
void Student::SetName(char* name) {
	/*name = new char[20];
	cin >> name;*/
	this->name = name;
}

//设置学生性别
void Student::SetGender(char* gender) {
	/*gender = new char[10];
	cin >> gender;*/
	this->gender = gender;
}

//设置学生年龄
void Student::SetAge(char* age) {
	/*age = new char[10];
	cin >> age;*/
	this->age = age;
}

//设置学生籍贯
void Student::SetOrigin(char* origin) {
	/*origin = new char[20];
	cin >> origin;*/
	this->origin = origin;
}

//设置学生地址
void Student::SetAddress(char* address) {
	/*address = new char[50];
	cin >> address;*/
	this->address = address;
}

//设置学生电话
void Student::SetPhone(char* phone) {
	/*phone = new char[20];
	cin >> phone;*/
	this->phone = phone;
}

//设置学生信息
void Student::SetInfo() {
	char* name = new char[20];
	char* gender = new char[10];
	char* age = new char[10];
	char* origin = new char[20];
	char* address = new char[50];
	char* phone = new char[20];

	cout << "请输入学生姓名：";
	cin >> name;
	cout << "请输入学生性别：";
	cin >> gender;
	cout << "请输入学生年龄：";
	cin >> age;
	cout << "请输入学生籍贯：";
	cin >> origin;
	cout << "请输入学生地址：";
	cin >> address;
	cout << "请输入学生电话：";
	cin >> phone;

	SetName(name);
	SetGender(gender);
	SetAge(age);
	SetOrigin(origin);
	SetAddress(address);
	SetPhone(phone);
}
