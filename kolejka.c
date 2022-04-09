#include <stdio.h>
#include <stdlib.h>

int top=-1;                                     //utworzeznie zmiennych globalnych
int *queue;

void enqueue(element){                             //dodanie element�w do kolejki
    top++;
    queue[top]=element;
}
void dequeue(){                                     //usuni�cie element�w z kolejki
    for(int i=1; i<5;i++){
        queue[i-1] = queue[i];
    }
    top--;

}
int main(){
    queue=(int*)malloc(sizeof(int)*5);          //zarerwowanie miejsca w pami�ci na 6 element�w
    for(int i=0;i<5;i++){                       //dodawanie warto�ci do stosu
        enqueue(i+1);
    }
    for(int i=0;i<5;i++){                       //wy�wietlanie warto�ci
        printf("%d", queue[i]);
    }
    printf("\n");

    dequeue();                                  //usuni�cie warto�ci z kolejki

    for(int i=0;i<4;i++){                       //wy�wietlanie warto�ci
        printf("%d", queue[i]);
    }
    return 0;
}
