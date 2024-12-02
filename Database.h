#pragma once
#ifndef _DATABASE_H_
#define _DATABASE_H_
#include <mysql.h>
#include "Student.h"

class Database
{
	private:
		//���ݿ�������Ϣ
		const char* server;
		const char* user;
		const char* passwd;
		const char* db;
		const int port;
		const char* socket = NULL;
		const int flag = 0;

		//�������ݿ����ӽṹ��
		MYSQL* mysql;
		//�������ݿ��Ӧ�ṹ��
		MYSQL_RES* res = nullptr;
		///< ������Ž���Ľṹ��
		MYSQL_ROW row = nullptr;
		//�������ݿ⺯��
		bool Connect();
		
	public:
		//���캯��
		Database(const char* server_, const char* user_, const char* passwd_, const char* db_, const int port_, const char* socket_, const int flag_);
		Database(const char* server_, const char* user_, const char* passwd_, const char* db_, const int port_);
		
		//��������
		~Database();
		
		//��ʼ�����ݿ�
		void Init();
		
		//ִ��SQL���,�����Ƿ��ӡ��������Զ�����������
		void Command(const char* command, bool printResult, int num);
		
		//ִ��SQL��䣬Ĭ�ϴ�ӡ�����
		void Command(const char* command, bool printResult = true);
		
		//ִ��SQL
		//��ȡ�������Ĭ�ϴ�ӡ
		void GetResult(int num = 6);
		
		//���ѧ����Ϣ
		void AddStudent(Student* student, bool haveInfo = false);
		
		//�޸�ѧ����Ϣ
		void UpdateStudent(char* name_);
		
		//��ȡѧ����Ϣ, Ĭ�ϲ���ӡ���
		void GetStudent(const char* name, bool printResult = false);
		
		//ɾ��ѧ����Ϣ
		void DeleteStudent(const char* name);

};

#endif