#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[50];
    int year;
    int isAvailable;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook(const char *title, const char *author, int year) {
    if (bookCount >= MAX_BOOKS) {
        printf("Library full!\n");
        return;
    }
    Book *b = &library[bookCount];
    b->id = bookCount + 1;
    strcpy(b->title, title);
    strcpy(b->author, author);
    b->year = year;
    b->isAvailable = 1;
    bookCount++;
    printf("Added: %s\n", title);
}

void displayAllBooks() {
    if (bookCount == 0) {
        printf("\nNo books in library!\n");
        return;
    }
    printf("\n========= LIBRARY =========\n");
    printf("%-5s %-30s %-20s %-6s %s\n", "ID", "Title", "Author", "Year", "Status");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        Book *b = &library[i];
        printf("%-5d %-30s %-20s %-6d %s\n",
               b->id, b->title, b->author, b->year,
               b->isAvailable ? "Available" : "Borrowed");
    }
}

int main() {
    addBook("The C Programming Language", "K&R", 1978);
    addBook("Clean Code", "Robert Martin", 2008);
    addBook("Pragmatic Programmer", "Hunt & Thomas", 1999);
    addBook("Making Embedded Systems", "Elecia White", 2011);

    displayAllBooks();

    return 0;
}
