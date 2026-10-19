#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"library.h"

static Book *library = NULL;
static int count = 0;
static int capacity = 0;

void initLibrary(void){
  library = NULL;
  count = 0;
  capacity = 0;
}

void cleanupLibrary(void){
  free(library);
  library = NULL;
  count = 0;
  capacity = 0;
}

int addBook(const char *title,const char *author,int year){
  if(count >= capacity){
    capacity = (capacity == 0) ? 4:capacity*2;
    Book *temp = realloc(library,capacity * sizeof(Book));
    if(!temp) return -1;
    library = temp;
  }
  Book *b = &library[count];
  b->id = count+1;
  strncpy(b->title,title,MAX_TITLE-1);
  b->title[MAX_TITLE-1] = '\0';
  strncpy(b->author,author,MAX_AUTHOR-1);
  b->author[MAX_AUTHOR-1] = '\0';
  b->year = year;
  b->isAvailable = 1;
  count++;
  return b->id;
}

void displayAllBooks(void){
  if(count == 0){
    printf("No books in library\n");
    return;
  }
  printf("\n %-5s %-20s %-20s %-5s %s\n","Id","Title","Author","Year","Availablity");
  printf("------------------\n");
  for(int i=0;i<count;i++){
    Book *b = &library[i];
    printf("%-5d %-20s %-20s %-5d %s\n",b->id,b->title,b->author,b->year,b->isAvailable ? "Available" : "Borrowed");
  }
}

int findBookById(int id){
  for(int i=0;i<count;i++)
    if(library[i].id==id)return i;
  return -1;
}

int borrowBook(int id){
  int idx = findBookById(id);
  if(idx==-1) return -1;
  if(!library[idx].isAvailable)return -2;
  library[idx].isAvailable=0;
  return 0;
}

int returnBook(int id){
  int idx = findBookById(id);
  if(idx==-1)return -1;
  if(library[idx].isAvailable)return -2;
  library[idx].isAvailable = 1;
  return 0;
}

int saveToFile(const char *filename){
  FILE *fp = fopen(filename,"wb");
  if(!fp)return -1;
  fwrite(&count,sizeof(int),1,fp);
  fwrite(library,sizeof(Book),count,fp);
  fclose(fp);
  return 0;
}

int loadFromFile(const char *filename){
  FILE *fp = fopen(filename,"rb");
  if(!fp)return -1;
  fread(&count,sizeof(int),1,fp);
  capacity = count>0?count:4;
  library = malloc(capacity*sizeof(Book));
  if(!library){fclose(fp);return -1;}
  fread(library,sizeof(Book),count,fp);
  fclose(fp);
  return 0;
}

int getBookCount(void){return count;}

