#include <stdio.h>
#include<string.h>

typedef struct books{
    int id;
    char title[100];
    int price;
    char boo[100];
}book_t;
void list_books(book_t boo){
    printf("book id = %d\n",boo.id);
    printf("book title = %s\n",boo.title);
    printf("book price = %d\n",boo.price);
    
}
int total_price(book_t boo[],int n){
    int sum=0;
    for(int i=0;i<6;i++){
        sum+=boo[i].price;
    }
    return sum;
}
int main(){
    FILE*list_books_file=fopen("list_books.txt","w");
    
    
    book_t boo[6];
    boo[0].id = 1;
    boo[0].price = 1000;
    strcpy(boo[0].title,"All the Light We Cannot See");
    
    boo[1].id = 2;
    boo[1].price = 300;
    strcpy(boo[1].title,"The 38 Letters from J.D. Rockefeller to his son");
    
    boo[2].id = 3;
    boo[2].price = 1000; 
    strcpy(boo[2].title,"The Balled of Songbirds and Snakes");
    
    boo[3].id = 4;
    boo[3].price = 550; 
    strcpy(boo[3].title,"Kellers of the Flower Moon");
    
    boo[4].id = 5;
    boo[4].price = 870; 
    strcpy(boo[4].title,"Elon Musk");
    
    boo[5].id = 6;
    boo[5].price = 1344; 
    strcpy(boo[5].title,"Milk and Honey 12-Month 2024");
    
    for(int i=0;i<6;i++){
        list_books(boo[i]);
    }
    
    printf("Total price of all books: %d\n",total_price(boo, 6));
    
    for (int i = 0; i < 6; i++) {
        fwrite(&boo[i], sizeof(book_t), 1, list_books_file);
    }

    fclose(list_books_file);
    return 0;
} 
