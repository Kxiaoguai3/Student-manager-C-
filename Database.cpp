﻿#include "Database.h"
#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;

//构造函数

//参数：服务器地址、用户名、密码、数据库名、端口号、socket指针、标记
Database::Database(const char* server_, const char* user_, const char* passwd_, const char* db_, const int port_, const char* socket_, const int flag_) : server(server_), user(user_), passwd(passwd_), db(db_), port(port_), socket(socket_), flag(flag_) {Init();}

//参数：服务器地址、用户名、密码、数据库名、端口号
Database::Database(const char* server_, const char* user_, const char* passwd_, const char* db_, const int port_)    : server(server_), user(user_), passwd(passwd_), db(db_), port(port_) {Init();}

//析构函数
Database::~Database()
{
	mysql_close(mysql);
}

//初始化数据库
void Database::Init() {
	//初始化对象
	mysql = mysql_init(NULL);
	//mysql_options(mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	//设置字符编码
	mysql_query(mysql, "set names utf8");
	//连接的数据库（句柄、主机名、用户名、密码、数据库名、端口号、socket指针、标记）
	if (!Connect()) {
		//连接失败
		cout << "Connect failed" << mysql_error(mysql) << endl;
		cout << "press q to exit or any key to continue..." << endl;

		//等待用户输入选择是否重连
		char c;
		cin >> c;
		if (c == 'q') {
			//退出程序
			mysql_close(mysql);
			free(mysql);
			exit(0);
		}
		else {
			Init();
		}
	}
	else {
		//连接成功
		cout << "Connect success" << endl;
		mysql_query(mysql, "set names 'gb2312'");//解决中文乱码问题
	}
}

//连接数据库
bool Database::Connect() {
	//连接数据库
	if (mysql_real_connect(mysql, server, user, passwd, db, port, socket, flag)) {
		return true;
	}
	else {
		return false;
	}
}

//执行SQL命令，自定义返回结果列数
void Database::Command(const char* command, bool printResult, int num) {
	//执行SQL命令
	if (!mysql_real_query(mysql, command, (unsigned int)strlen(command))) {
		//执行成功
		//有返回值
		if (printResult) {
			GetResult(num);
		}
		//没有返回值
		else {

		}
	}
	//执行失败
	else {
		cout << "SQL execute failed: " << mysql_error(mysql) << endl;
		cout << "Press any key to continue or q to exit..." << endl;
		char c;
		cin >> c;
		if (c == 'q') {
			//退出程序
			mysql_close(mysql);
			exit(0);
			free(mysql);
		}
		else {
			Command(command);
		}
	}
}

//执行SQL命令，默认要输出,6列
void Database::Command(const char* command, bool printResult, bool getResult = true) {
	//执行SQL命令
	//执行成功
	if (!mysql_real_query(mysql, command, (unsigned int)strlen(command))) {
		//有返回值
		if (printResult) {
			GetResult();
		}
		//没有返回值
		else {
			//记得删掉
			cout << "当前没有返回值";
		}
	}
	//执行失败
	else {
		cout << "SQL execute failed: " << mysql_error(mysql) << endl;
		cout << "Press any key to continue or q to exit..." << endl;
		char c;
		cin >> c;
		if (c == 'q') {
			//退出程序
			mysql_close(mysql);
			exit(0);
			free(mysql);
		}
		else {
			Command(command);
		}
	}
}

//获取结果集
void Database::GetResult(int num) {
	//获取结果集
	res = mysql_store_result(mysql);

	//获取结果集失败
	if (res == NULL) {
		cout << "Failed to get result set：" << mysql_error(mysql) << endl;
		cout << "Press any key to continue or q to exit..." << endl;
		char c;
		cin >> c;
		if (c == 'q') {
			//退出程序
			mysql_close(mysql);
			exit(0);
			free(mysql);
		}
		else {
			GetResult(num);
		}
	}

	//获取结果集成功
	else {
		cout << "Got result set successfully!" << endl;

		//打印结果集
		while (row = mysql_fetch_row(res)) {
			//打印一行
			for (int i = 0; i < num; i++) {    //这里之前是6
				printf("%s  ", row[i]);
			}
			cout << endl;
		}
	}

	//释放结果集
	mysql_free_result(res);
}

//获取学生信息
void Database::GetStudent(const char* name, bool printResult) {
	//构造SQL语句
	string command = "SELECT * FROM student WHERE 姓名 = '" + string(name)+"'";
	
	//执行SQL语句
	Command(command.c_str(), printResult);
}

//添加学生信息
void Database::AddStudent(Student* student){
	//设置添加学生的信息
	student->SetInfo();

	//拿出学生的信息
	string name = student->name;
	string gender = student->gender;
	string age = student->age;
	string origin = student->origin;
	string address = student->address;
	string phone = student->phone;

	//构造SQL语句
	string command = "INSERT INTO student(姓名, 性别, 年龄, 籍贯, 住址, 联系方式) VALUES('" +
		name + "', '" +
		gender + "', '" +
		age + "', '" +
		origin + "', '" +
		address + "', '" +
		phone + "');";

	//执行SQL语句
	Command(command.c_str(), false);

	//记得删掉
	cout << "添加成功！" << endl;
}

//修改学生信息
void Database::UpdateStudent(char* name_){
	string name = string(name_);
	//由于学生在数据库中没有排序，所以先删除，再添加
	//获取学生信息
	/*string name = student->name;
	string gender = student->gender;
	string age = student->age;
	string origin = student->origin;
	string address = student->address;
	string phone = student->phone;*/

	//获取学生信息
	//构造SQL语句
	string command = "SELECT * FROM student WHERE 姓名 = '" + name + "';";

	//执行SQL语句
	Command(command.c_str(), true);

	
	//询问删除
	char* updateInfo = new char[20];
	cout << "输入要修改的信息";
	cin >> updateInfo;

	//开始判断修改信息
	if()

	//删除学生信息
	DeleteStudent(name.c_str());

	//添加学生信息
	AddStudent(student);
    //记得删掉
	cout << "修改成功！" << endl;
}

//删除学生信息
void Database::DeleteStudent(const char* name){
	//删除姓名为name的学生
	//构造SQL语句
	string command = "DELETE FROM student WHERE 姓名 = '" + string(name) + "';";

	//执行SQL语句
	Command(command.c_str(), false);

	//记得删掉
	cout << "删除成功！" << endl;
}

