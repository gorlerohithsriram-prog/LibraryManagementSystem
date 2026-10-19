#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_TITLE 100
#define MAX_AUTHOR 50

typedef struct{
  int id;
  char title[MAX_TITLE];
  char author[MAX_AUTHOR];
  int year;
  int isAvailable;
} Book;

//Functions
void initLibrary(void);
void cleanupLibrary(void);
int addBook(const char *title,const char *author,int year);
void displayAllBooks(void);
int findBookById(int id);
int borrowBook(int id);
int returnBook(int id);
int saveToFile(const char *filename);
int loadFromFile(const char *filename);
int getBookCount(void);

#endif
