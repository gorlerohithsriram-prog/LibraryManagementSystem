#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void addBook(const char *title,const char *author,int year){
  if(count >= capacity){
    capacity = (capacity == 0) ? 2:capacity * 2;
    library = realloc(library,capacity * sizeof(Book));
    if(library == NULL){
      printf("Memory Allocation failed\n");
      exit(1);
    }
    printf("[Memory] Library Capacity now: %d\n",capacity);
  }
  
  Book *b = &library[count];
  b->id = count + 1;
  strcpy(b->title,title);
  strcpy(b->author,author);
  b->year = year;
  b->isAvailable = 1;
  count++;
  }
  
void displayAllBooks(){
  printf("\nLibrary  (%d books, capacirty %d) --\n",count,capacity);
  for(int i=0;i<count;i++){
    printf("%d. %s by %s (%d)\n",
              library[i].id,library[i].title,library[i].author,library[i].year);
  }
  }
void cleanup(){
  free(library);
  library = NULL;
  printf("[memory] library freed.\n");
}

int main(){
  addBook("Book A","Author A",1919);
  addBook("Book B","Author B",1920);
  addBook("Book C","Author C",1930);
  
  displayAllBooks();
  cleanup();
  
  return 0;
  }
  
  
    
