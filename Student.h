#pragma once
#ifndef STUDENT_H
#define STUDENT_H

class Student
{
	public:
		
		//Student(char* name, char* gender, char* age, char* origin, char* address, char* phone);
		~Student();
		char* name;         //����
		char* gender;       //�Ա�
		char* age;          //����
		char* origin;       //����
		char* address;      //��ַ
		char* phone;        //�绰

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

