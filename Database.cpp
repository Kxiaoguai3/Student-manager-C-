#include "Database.h"
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
//执行SQL命令，返回结果默认6列
void Database::Command(const char* command, bool printResult) {
	//执行SQL命令
	if (!mysql_real_query(mysql, command, (unsigned int)strlen(command))) {
		//执行成功
		//有返回值
		if (printResult) {
			GetResult();
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
			free(mysql);
			exit(0);
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
void Database::GetStudent(const char* name) {
	string command = "SELECT * FROM student WHERE 姓名 = '" + string(name)+"'";
	Command(command.c_str(), true);
}

//添加学生信息
void Database::AddStudent(Student* student){
	//string command = "INSERT INTO student(姓名, 性别, 班级, 学号, 电话, 邮箱) VALUES("+student->name;
	//cin >> student->name;         //姓名
	//cin >> student->gender;       //性别
	//cin >> student->age;          //年龄
	//cin >> student->origin;       //籍贯
	//cin >> student->address;      //住址
	//cin >> student->phone;        //电话
	string command = "INSERT INTO student(姓名, 性别, 年龄, 籍贯, 住址, 电话) VALUES('" +
		student->name + "', '" +
		student->gender + "', '" +
		student->age + "', '" +
		student->origin + "', '" +
		student->phone + "');";

	
}

//修改学生信息
void Database::UpdateStudent(Student* student){}

//删除学生信息
void Database::DeleteStudent(char* name){}
