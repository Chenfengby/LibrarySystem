#ifndef STUDENT_H
#define STUDENT_h
#include <string>
#include "Book.h"
class Student
{
private:
  std::string name;
  std::string studentId;
  int borrowedCount; // 当前已借图书数量
public:
  Student(std::string n, std::string id);
  // 依赖关系：借书操作需要传入图书对象的引用
  // 只有传递地址，才能改变图书馆里那本书的状态
  bool borrowBook(Book &book);
  void displayInfo() const;
};
#endif