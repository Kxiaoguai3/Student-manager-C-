#pragma once
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
	public:
		
		//Student(char* name, char* gender, char* age, char* origin, char* address, char* phone);
		~Student();
		char* name;         //姓名
		char* gender;       //性别
		char* age;          //年龄
		char* origin;       //籍贯
		char* address;      //地址
		char* phone;        //电话

		void SetInfo();
		void SetName(char* name);
		void SetGender(char* gender);
		void SetAge(char* age);
		void SetOrigin(char* origin);
		void SetAddress(char* address);
		void SetPhone(char* phone);



		private:
			

};

#endif // !STUDENT_H

