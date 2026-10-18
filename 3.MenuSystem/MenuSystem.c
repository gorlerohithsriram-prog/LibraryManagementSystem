#include<stdio.h>
#include<string.h>

#define MAX_BOOKS 100

typedef struct{
  int id;
  char title[100];
  char author[100];
  int year;
  int isAvailable;
} Book;

Book Library[MAX_BOOKS];
int count = 0;

void addBook();
void searchBook();
void displayAllBooks();
void borrowBook();
void returnBook();
int findBookById(int id);

void showMenu(){
  printf("\n===================Library================\n");
  printf("1. Add Book\n");
  printf("2. Search Book\n");
  printf("3. Borrow Book\n");
  printf("4. Return Book\n");
  printf("0. Exit\n");
  printf("=======================\n");
  printf("Enter choice:");
}

int main(){
  int choice;
  while(1){
    showMenu();
    scanf("%d",&choice);
    getchar(); //*
    
    switch(choice) {
    case 1: addBook();break;
    case 2: searchBook();break;
    case 3: borrowBook();break;
    case 4: returnBook();break;
    case 0: printf("Exitted\n");return 0;
    default : printf("Undefined Choice\n");
    
    }
  }

return 0;
}

void addBook(){
  if(count >= MAX_BOOKS){
    printf("Library FULL\n");
    return;
  }
  Book *b = &Library[count];
  b->id = count + 1;
  
  printf("Enter Title :");
  fgets(b->title,sizeof(b->title),stdin);
  b->title[strcspn(b->title,"\n")] = '\0';
  
  printf("Enter author :");
  fgets(b->author,sizeof(b->author),stdin);
  b->author[strcspn(b->author,"\n")] = '\0';
  
  printf("Year :");
  scanf("%d",&b->year);
  
  b->isAvailable = 1;
  count++;
  printf("Book added with id:%d\n",b->id);
}

void displayBook(){
  if(count == 0){
    printf("No Books in the Library\n");
    return;
    }
    printf("\n==============LIBRARY============\n");
    printf("%-5s %-20s %-20s %-5s %-5s\n","ID","Title","Author","Year","Available");
    for(int i=0;i<count;i++){
      Book *b = &Library[i];
      printf("%-5d %-20s %-20s %-5d %-5s\n",b->id,b->title,b->author,b->year,b->isAvailable ? "Yes" : "No");
      }
  }
  

int findBookById(int id){
  for(int i=0;i<count;i++){
    if(Library[i].id == id) return i;
    }
    return -1;
    }

void searchBook(){
  int id;
  printf("Enter ID:");
  scanf("%d",&id);
  
  int idx = findBookById(id);
  if(idx==-1){
    printf("Book Not found\n");
    return;
    }
  Book *b = &Library[idx];
  printf("Book %s by %s in %d is %s\n",b->title,b->author,b->year,b->isAvailable ? "Yes":"No");
}

void borrowBook(){
  int id;
  printf("Enter Book Id to Borrow:\n");
  scanf("%d",&id);
  
  int idx = findBookById(id);
  if(idx == -1){
    printf("Book not found\n");
    return;
    }
  if(!Library[idx].isAvailable){
    printf("Book aldready Borrowed\n");
    return;
  }
  Library[idx].isAvailable = 0;
  printf("You borrowed %s\n",Library[idx].title);
}

void returnBook(){
  int id;
  printf("Enter ID to return\n");
  scanf("%d",&id);
  int idx = findBookById(id);
  if(Library[idx].isAvailable){
    printf("Book not borrowed\n");
    return;
    }
    
  Library[idx].isAvailable = 1;
  printf("Returned %s\n",Library[idx].title);
}
    
    
  
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
