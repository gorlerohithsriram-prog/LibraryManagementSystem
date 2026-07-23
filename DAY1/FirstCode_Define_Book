#include<stdio.h>
#include<string.h>

struct book{
    int id;
    char title[100];
    char author[100];
    int isAvailable;
};

void AddBook(struct book *b,int id,const char *title,const char *author,int isAvailable){
    b->id = id;
    strcpy(b->title,title);
    strcpy(b->author,author);
    b->isAvailable = isAvailable;
}

void printBook(const struct book *b){
    printf("Book ID:%d\n",b->id);
    printf("Book Title:%s\n",b->title);
    printf("Book Author:%s\n",b->author);
    printf("Book Availability:%s\n", b->isAvailable ? "Available" : "Borrowed");
}

int main(){
    struct book book1;
    AddBook(&book1,1,"C-programming","R&K",1);
    printBook(&book1);
    return 0;
}
