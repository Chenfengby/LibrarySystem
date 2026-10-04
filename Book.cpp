#include "Book.h"

using namespace std;

// 默认构造函数
Book::Book()
{
  title = "未知书名";
  isbn = "0000000000000";
  publisher = "未知出版社";
  price = 0.0;
  pages = 0;
  isAvailable = true; // 默认在馆
}

// 重载的构造函数
Book::Book(string t, string i, string p, double pr, int pg, bool avail)
{
  title = t;
  isbn = i;
  publisher = p;
  price = pr;
  pages = pg;
  isAvailable = avail;
}

// 修改图书信息
void Book::setInfo(string t, string i, string p, double pr, int pg, bool avail)
{
  title = t;
  isbn = i;
  publisher = p;
  price = pr;
  pages = pg;
  isAvailable = avail;
}

// 修改在馆状态
void Book::setAvailability(bool avail)
{
  isAvailable = avail;
}

// 获取书名
string Book::getTitle() const
{
  return title;
}

// 获取ISBN
string Book::getIsbn() const
{
  return isbn;
}

// 获取在馆状态
bool Book::getAvailability() const
{
  return isAvailable;
}

// 显示图书全部信息
void Book::display() const
{
  cout << "------------------------" << endl;
  cout << "书名: " << title << endl;
  cout << "ISBN: " << isbn << endl;
  cout << "出版社: " << publisher << endl;
  cout << "价格: " << price << " 元" << endl;
  cout << "页数: " << pages << " 页" << endl;
  cout << "状态: " << (isAvailable ? "可借" : "不可借") << endl;
  cout << "------------------------" << endl;
}

// 验证ISBN合法性
bool Book::isValidIsbn() const
{
  // 1. 长度必须在10到13位之间
  if (isbn.length() < 10 || isbn.length() > 13)
  {
    return false;
  }
  // 2. 必须全部是数字
  for (char c : isbn)
  {
    if (!isdigit(c))
    {
      return false;
    }
  }
  return true;
}