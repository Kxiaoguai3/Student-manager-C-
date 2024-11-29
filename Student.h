#pragma once

class Student
{
	public:
		char* name;         //姓名
		char* gender;       //性别
		char* age;          //年龄
		char* origin;       //籍贯
		char* address;      //地址
		char* phone;        //电话
		Student(char* name, char* gender, char* age, char* origin, char* address, char* phone);
		~Student();

};

