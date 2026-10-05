#include <iostream>
#include <windows.h>
#include "Book.h"
#include "Library.h"
#include "Student.h"

using namespace std;

int main()
{
  SetConsoleOutputCP(65001); // 解决中文乱码

  cout << "=== 图书馆借阅管理系统 - 实验二测试 ===" << endl;

  // 1. 创建图书对象 (组合关系的部分类)
  Book book1("C++ Primer", "9780321714114", "Addison-Wesley", 128.0, 976, true);
  Book book2("Effective C++", "9780321334879", "Addison-Wesley", 99.0, 320, true);

  // 2. 创建图书馆对象 (组合关系的整体类)
  Library myLibrary;
  myLibrary.addBook(book1);
  myLibrary.addBook(book2);

  // 展示图书馆初始藏书
  myLibrary.displayAllBooks();

  // 3. 创建学生对象 (依赖关系的发起方)
  Student student1("张三", "2024001");
  student1.displayInfo();

  // 4. 测试借书 (依赖关系：传入图书对象的引用)
  Book *targetBook = myLibrary.getBookByIsbn("9780321714114"); // 查找C++ Primer
  if (targetBook != nullptr)
  {
    student1.borrowBook(*targetBook); // 传引用，体现依赖关系
  }
  else
  {
    cout << "未找到该ISBN的图书！" << endl;
  }

  // 5. 测试重复借阅同一本书（应该失败）
  if (targetBook != nullptr)
  {
    student1.borrowBook(*targetBook);
  }
  student1.displayHistory();

  // 6. 查看借阅后的状态
  cout << "\n--- 借阅后学生状态 ---" << endl;
  student1.displayInfo();
  cout << "\n--- 借阅后图书馆状态 ---" << endl;
  myLibrary.displayAllBooks();

  system("pause");
  return 0;
}