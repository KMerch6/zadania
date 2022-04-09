#include <stdio.h>
#include <stdlib.h>

int top=-1;                                     //utworzeznie zmiennych globalnych
int *queue;

void enqueue(element){                             //dodanie elementów do kolejki
    top++;
    queue[top]=element;
}
void dequeue(){                                     //usuniêcie elementów z kolejki
    for(int i=1; i<5;i++){
        queue[i-1] = queue[i];
    }
    top--;

}
int main(){
    queue=(int*)malloc(sizeof(int)*5);          //zarerwowanie miejsca w pamiêci na 6 elementów
    for(int i=0;i<5;i++){                       //dodawanie wartoœci do stosu
        enqueue(i+1);
    }
    for(int i=0;i<5;i++){                       //wyœwietlanie wartoœci
        printf("%d", queue[i]);
    }
    printf("\n");

    dequeue();                                  //usuniêcie wartoœci z kolejki

    for(int i=0;i<4;i++){                       //wyœwietlanie wartoœci
        printf("%d", queue[i]);
    }
    return 0;
}
