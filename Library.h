#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
class Library
{
private:
  Book books[10];
  int bookCount;

public:
  Library();
  void addBook(const Book &b);
  void displayAllBooks() const;
  Book *getBookByIsbn(const std::string &isbn);
};
#endif