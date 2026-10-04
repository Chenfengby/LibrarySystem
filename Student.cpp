#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(string n, string id)
{
  name = n;
  studentId = id;
  borrowedCount = 0;
}
// 体现依赖关系，参数是Book类的引用
bool Student::borrowBook(Book &book)
{
  cout << "\n[借阅尝试]学生" << name << "尝试借阅《" << book.getTitle() << "》..." << endl;
  // 判断图书状态（书的状态发生改变）
  if (book.getAvailability())
  {
    book.setAvailability(false); // 书被借走，状态变为不可借
    borrowedCount++;
    cout << ">>>借阅成功！" << endl;
    return true;
  }
  else
  {
    cout << ">>>借阅失败：该书已被借出！" << endl;
    return false;
  }
}
void Student::displayInfo() const
{
  cout << "学生姓名：" << name << ",学号：" << studentId
       << ",当前已借阅：" << borrowedCount << "本" << endl;
}