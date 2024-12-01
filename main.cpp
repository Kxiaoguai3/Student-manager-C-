#include <iostream>
#include <windows.h>
#include "Database.h"
#include <string>

using namespace std;

int main()
{
    /*
        1.添加一个学生信息类
        2.实现学生信息的增删改查功能
        3.一个学生信息类包含姓名、性别、年龄、班级、电话、地址等属性
        4.账户系统
    */
    
    Database db = Database("127.0.0.1", "root", "147258369", "studentmanger", 3306);
    Student *student = new Student();

    //添加测试
    //db.AddStudent(student);

    //获取测试
    /*while(true) {
        cout << "请输入学生姓名：";
        cin >> name;
        db.GetStudent(name, true);
        system("pause");

    }*/

    //修改测试



    //删除测试
    /*char* name = new char[20];
    cin >> name;
    db.DeleteStudent(name);*/

    return 0;
}