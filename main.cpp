#include <iostream>
#include <windows.h>
#include "Database.h"
#include <string>

using namespace std;

int main()
{
    /*
        1.���һ��ѧ����Ϣ��
        2.ʵ��ѧ����Ϣ����ɾ�Ĳ鹦��
        3.һ��ѧ����Ϣ������������Ա����䡢�༶���绰����ַ������
        4.�˻�ϵͳ
    */
    
    Database db = Database("127.0.0.1", "root", "147258369", "studentmanger", 3306);

    //db.Command("select * from student", 1);
    char* name = new char[10];

    while(true) {
        cout << "������ѧ��������";
        cin >> name;
        db.GetStudent(name);
        system("pause");

    }

    return 0;
}