#include<stdio.h>
#include<string.h>
#include"library.h"

#define DATA_FILE "library.data"

void promptAddBook(void){
  char title[MAX_TITLE],author[MAX_AUTHOR];
  int year;
  printf("Title: ");
  fgets(title,sizeof(title),stdin);
  title[strcspn(title,"\n")] = '\0';
  printf("Author: ");
  fgets(author,sizeof(author),stdin);
  author[strcspn(author,"\n")] = '\0';
  printf("Year: ");
  scanf("%d",&year);
  getchar();
  int id = addBook(title,author,year);
  if(id>0)printf("Adder Book with ID %d\n",id);
  else printf("Failed to add Book\n");
}

int main(){
  initLibrary();
  loadFromFile(DATA_FILE);
  int choice;
  while(1){
    printf("\n===LIBRARY MENU===\n");
    printf("1.Add Book\n2.Display All\n3.Borrow\n4.Return\n0.Exit\n");
    printf("choice: ");
    scanf("%d",&choice);
    getchar();
    if(choice==0)break;
    switch(choice){
      case 1: promptAddBook();break;
      case 2: displayAllBooks();break;
      case 3:{
                int id;
                printf("Book ID: ");
                scanf("%d",&id);
                int r = borrowBook(id);
                if(r==0) printf("Borrowed\n");
                else if (r==-1)printf("Not found\n");
                else printf("Aldready Borrowed\n");
                break;
              }
              
      case 4:{
                int id;
                printf("Book ID: ");
                scanf("%d",&id);
                int r = returnBook(id);
                if(r==0)printf("Returned\n");
                else if(r==-1)printf("Not Found\n");
                else printf("Was not Borrowed\n");
                break;
              }
      default:printf("Invalid Choice\n");
    }
  }

saveToFile(DATA_FILE);
cleanupLibrary();
return 0;
}
                
