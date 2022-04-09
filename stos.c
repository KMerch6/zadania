#include <stdio.h>
#include <stdlib.h>

int top=-1;                                     //utworzeznie zmiennych globalnych
int *stack;

void stack_empty (int top){                     //czy stos pusty czy nie pusty
    if(top==-1) printf("stos pusty \n\n");
    else printf("stos niepusty \n\n");
}
void push(element){                             //dodanie elementów do stosu
    top++;
    stack[top]=element;
}
void pop(){                                     //usunięcie elementów ze stosu
    if(top>-1) top--;
}
int main(){
    stack=(int*)malloc(sizeof(int)*6);          //zarerwowanie miejsca w pamięci na 6 elementów
    stack_empty(top);
    for(int i=0;i<6;i++){                       //dodawanie wartości do stosu
        push(i+1);
    }
    for(int i=0;i<6;i++){                       //wyświetlanie wartości
        printf("%d", stack[i]);
    }
    printf("\n");
    for(int i=0;i<2;i++){                       //usuwanie wartości ze stosu
        pop();
    }
    for(int i=0;i<4;i++){                       //wyświetlanie wartości
        printf("%d", stack[i]);
    }
    return 0;
}
