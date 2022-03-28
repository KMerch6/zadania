#include <stdio.h>
#include <stdlib.h>
int tab_size=0;
void insert(int tab[],int newValue){
    if(tab_size==0){
        scanf ("%d", &newValue);
        tab[0]=newValue;
        tab_size++;
    }else{
        scanf ("%d", &newValue);
        tab[tab_size]=newValue;
        tab_size++;
        for(int i=tab_size/2-1;i>=0;i--){
            heapify(tab, tab_size, i);
        }
    }
}

void heapify(int tab[],int tab_size,int i){
    if(tab_size==1) printf("By³a to pierwsza wartoœæ");
    else{
        int max=i;
        int leftChildIndex=2*i+1;
        int rightChildIndex=2*i+2;
        if(leftChildIndex<tab_size&&tab[leftChildIndex]>tab[max]){
            max=leftChildIndex;
        }
        if(rightChildIndex<tab_size&&tab[rightChildIndex]>tab[max]){
            max=rightChildIndex;
        }
        if(max!=i){
            change(&tab[i],&tab[max]);
            heapify(tab,tab_size,max);
        }
    }
}

void deleteRoot(int tab[],int deleteNum){
      int i;
  for (i = 0; i < tab_size; i++){
    if (deleteNum == tab[i])break;
  }

    change(&tab[i],&tab[tab_size-1]);
    tab_size--;
    heapify(tab,tab_size,tab[i]);
}

void change(int *x, int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}


int main()
{
    int tab[10];
    int deleteNum=0;

    printf("Wpisz 10 liczb: \n");
    for (int i = 0; i < 10; i++){
        int newValue=0;
        insert(tab,newValue);
    }
    for (int i = 0; i < tab_size; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");

    printf("Wpisz liczbê do usuniêcia: ");
    scanf ("%d", &deleteNum);
    deleteRoot(tab,deleteNum);

    for (int i = 0; i < tab_size; i++){
        printf("%d ", tab[i]);
    }

    return 0;
}
