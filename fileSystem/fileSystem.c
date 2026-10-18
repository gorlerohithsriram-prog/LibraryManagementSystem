#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "library.dat"
typedef struct{
  int id;
  char title[100];
  char author[50];
  int year;
  int isAvailable;
} Book;

Book *library = NULL;
int count = 0;
int capacity = 0;

void addBook(const char *title,const char *author,int year);
void saveToFile(){
  FILE *fp = fopen(FILENAME,"wb");
    if(fp == NULL){
      printf("Error opening file for writing\n");
      return;
    }

  fwrite(&count,sizeof(int),1,fp);
  
  fwrite(library,sizeof(Book),count,fp);
  
  fclose(fp);
  printf("Saved %d books to %s\n",count,FILENAME);
}

void loadFromFile(){
  FILE *fp = fopen(FILENAME,"rb");
    if(fp == NULL){
      printf("File cannot be read!\n");
      return;
    }
    
  fread(&count,sizeof(int),1,fp);
  
  capacity = count;
  library = malloc(capacity*sizeof(Book));
  
  fread(library,sizeof(Book),count,fp);
  
  fclose(fp);
  printf("Loaded %d books from %s\n",count,FILENAME);
}

void addBook(const char *title,const char *author,int year){
  if(count >= capacity){
    capacity = (capacity == 0)? 2 : capacity*2;
    library = realloc(library,capacity*sizeof(Book));
    }
  Book *b = &library[count];
  b->id = count + 1;
  strcpy(b->title,title);
  strcpy(b->author,author);
  b->year = year;
  b->isAvailable = 1;
  count ++;
}

void displayAllBooks(){
  printf("Library %d books\n",count);
  for(int i=0;i<count;i++){
    printf("%d. %s by %s (%d) [%s]\n",library[i].id,library[i].title,library[i].author,library[i].year,library[i].isAvailable ? "Yes" : "No");
  }
}


int main(){
  loadFromFile();
  
  if(count == 0){
    addBook("hii","bye",900);
    addBook("hell0","END",9000);
  }
  
  displayAllBooks();
  saveToFile();

  free(library);
  return 0;
}



















