#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include "Book.h"
class Student
{
private:
  std::string name;
  std::string studentId;
  int borrowedCount;                        // 当前已借图书数量
  std::vector<std::string> borrowedHistory; // 借阅历史记录
public:
  Student(std::string n, std::string id);
  // 依赖关系：借书操作需要传入图书对象的引用
  bool borrowBook(Book &book);
  void displayInfo() const;
  void displayHistory() const; // 显示借阅历史记录
};
#endif