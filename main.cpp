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
    Student *student = new Student();

    //��Ӳ���
    //db.AddStudent(student);

    //��ȡ����
    /*while(true) {
        cout << "������ѧ��������";
        cin >> name;
        db.GetStudent(name, true);
        system("pause");

    }*/

    //�޸Ĳ���



    //ɾ������
    /*char* name = new char[20];
    cin >> name;
    db.DeleteStudent(name);*/

    return 0;
}