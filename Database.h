#pragma once
#ifndef _DATABASE_H_
#define _DATABASE_H_
#include <mysql.h>
#include "Student.h"

class Database
{
	private:
		//数据库连接信息
		const char* server;
		const char* user;
		const char* passwd;
		const char* db;
		const int port;
		const char* socket = NULL;
		const int flag = 0;

		//创建数据库连接结构体
		MYSQL* mysql;
		//创建数据库回应结构体
		MYSQL_RES* res = nullptr;
		///< 创建存放结果的结构体
		MYSQL_ROW row = nullptr;
		//连接数据库函数
		bool Connect();
		
	public:
		//构造函数
		Database(const char* server_, const char* user_, const char* passwd_, const char* db_, const int port_, const char* socket_, const int flag_);
		Database(const char* server_, const char* user_, const char* passwd_, const char* db_, const int port_);
		//析构函数
		~Database();
		//初始化数据库
		void Init();
		//执行SQL语句
		void Command(const char* command, bool printResult, int num);
		void Command(const char* command, bool printResult = true);
		//获取结果集
		void GetResult(int num = 6);


		//添加学生信息
		void AddStudent(Student* student);
		//修改学生信息
		void UpdateStudent(Student* student);
		//获取学生信息
		void GetStudent(const char* name);
		//删除学生信息
		void DeleteStudent(char* name);

};

#endif