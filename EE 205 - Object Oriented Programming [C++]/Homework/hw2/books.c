#include <stdio.h>
#include <string.h>

#define numBooks 5 //number of books for sale (Stored in array)

struct Books {
    char title[50];
    char author[50];
    int isbn10;
    float price;
};

int main() {

    struct Books book[numBooks];
    int buy[2]; 

    // Book 1
    strcpy( book[0].title, "Where We Once Belonged" );
    strcpy( book[0].author, "Sia Figiel" );
    book[0].isbn10 = 1885030274;
    book[0].price = 11.63;

    // Book 2
    strcpy( book[1].title, "Calculus 8th Edition" );
    strcpy( book[1].author, "James Stewart" );
    book[1].isbn10 = 1285740629;
    book[1].price = 162.82;

    // Book 3
    strcpy( book[2].title, "C++ All-in-One For Dummies" );
    strcpy( book[2].author, "John Paul Mueller" );
    book[2].isbn10 = 1118823788;
    book[2].price = 21.13;

    // Book 4
    strcpy( book[3].title, "The Cooking for One Cookbook: 100 Easy Recipes" );
    strcpy( book[3].author, "Cindy Kerschner" );
    book[3].isbn10 = 1641529849;
    book[3].price = 12.69;

    // Book 5
    strcpy( book[4].title, "Harry Potter and the Sorcerer's Stone" );
    strcpy( book[4].author, "J.K. Rowling" );
    book[4].isbn10 = 439708184;
    book[4].price = 8.50;


    printf("Books for sale:\n");
    for(int i = 0; i < numBooks; i++) {
        printf("Book Index [%d]: %s\n", i, book[i].title);
    }
    printf("Select two books to buy\n");
    scanf("%d %d", &buy[0], &buy[1]);

    printf("Book %d: %s - $%.2f\n", buy[0], book[buy[0]].title, book[buy[0]].price);
    printf("Book %d: %s - $%.2f\n", buy[1], book[buy[1]].title, book[buy[1]].price);
    printf("Total price: $%.2f\n", book[buy[0]].price + book[buy[1]].price);
    
    return 0;
}
