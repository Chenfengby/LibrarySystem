#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book
{
private:
  // 数据成员：根据实验提示，包括名称、ISBN、出版社、价格、页数、在馆状态
  std::string title;     // 书名
  std::string isbn;      // ISBN号
  std::string publisher; // 出版社
  double price;          // 价格
  int pages;             // 页数
  bool isAvailable;      // 在馆状态（true表示可借，false表示不可借）

public:
  Book();

  // 2. 重载的构造函数
  Book(std::string t, std::string i, std::string p, double pr, int pg, bool avail);

  // 3. 基本操作：修改数据成员
  void setInfo(std::string t, std::string i, std::string p, double pr, int pg, bool avail);
  void setAvailability(bool avail);

  // 4. 基本操作：获取数据成员
  std::string getTitle() const;
  std::string getIsbn() const;
  bool getAvailability() const;

  // 5. 基本操作：输出数据成员
  void display() const;

  // 6. 其他操作：验证图书ISBN号的合法性（检查是否是10-13位纯数字）
  bool isValidIsbn() const;
};

#endif