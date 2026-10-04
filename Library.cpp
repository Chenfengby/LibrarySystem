#include "Library.h"
#include <iostream>
using namespace std;

Library::Library()
{
  bookCount = 0;
}
void Library::addBook(const Book &b)
{
  if (bookCount < 10)
  {
    books[bookCount] = b;
    bookCount++;
    cout << "成功入库图书：" << b.getTitle() << endl;
  }
  else
  {
    cout << "书架已满，无法增加新书！" << endl;
  }
}
void Library::displayAllBooks() const
{
  cout << "\n=========图书馆藏书列表========" << endl;
  if (bookCount == 0)
  {
    cout << "暂无图书。" << endl;
  }
  else
  {
    for (int i = 0; i < bookCount; ++i)
    {
      books[i].display();
    }
  }
  cout << "=========================" << endl;
}
Book *Library::getBookByIsbn(const string &isbn)
{
  for (int i = 0; i < bookCount; ++i)
  {
    if (books[i].getIsbn() == isbn)
    {
      return &books[i]; // 找到图书，返回地址
    }
  }
  return nullptr; // 没找到
}