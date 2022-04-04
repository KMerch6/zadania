#include <stdio.h>
#include <stdlib.h>

int tab_size=0;                                                             //rozmar tablicy

void insert(int tab[],int newValue){                                        //dodawanie nowych wartosci do kopca
    if(tab_size==0){
        scanf ("%d", &newValue);                                            //wpisanie nowej wartosci
        tab[0]=newValue;                                                    //wpisanie wartosci do tablicy
        tab_size++;                                                         //zwiekszenie rozmiaru o 1
    }else{
        scanf ("%d", &newValue);                                            //wpisanie nowej wartosci
        tab[tab_size]=newValue;                                             //wpisanie wartosci do tablicy
        tab_size++;                                                         //zwiekszenie rozmiaru o 1
        for(int i=tab_size/2-1;i>=0;i--){
            heapify(tab, tab_size, i);                                      //wywolywanie funkcji do ukladania kopca
        }
    }
}

void heapify(int tab[],int tab_size,int i){                                 //ukladanie kopca
    if(tab_size==1) printf("By³a to pierwsza wartoœæ");
    else{
        int max=i;                                                          //index teoretycznego najwiekszego wezla
        int leftChildIndex=2*i+1;                                           //wyliczanie intexu lewego dziecka
        int rightChildIndex=2*i+2;                                          //wyliczanie intexu prawego dziecka
        if(leftChildIndex<tab_size&&tab[leftChildIndex]>tab[max]){          //jezeli index lewego dziecka miesci sie w tablicy i wartosc lewego dziecka jest jest wieksza od max
            max=leftChildIndex;                                             //to ustawiamy index lewego dziecka jako index max
        }
        if(rightChildIndex<tab_size&&tab[rightChildIndex]>tab[max]){        //jezeli index prawego dziecka miesci sie w tablicy i wartosc prawego dziecka jest jest wieksza od max
            max=rightChildIndex;                                            //to ustawiamy index lewego dziecka jako index max
        }
        if(max!=i){                                                         //jezeli wartosc max jest inna niz i
            change(&tab[i],&tab[max]);                                      //zamieniamy miejscami wartosc z tablicy spod indexu i z wartoscia z tablicy spod indexu max
            heapify(tab,tab_size,max);                                      //wywolujemy funkcje ponownie
        }
    }
}

void deleteRoot(int tab[],int deleteNum){                                   //usuniecie wartosci z kopca
      int i;
  for (i = 0; i < tab_size; i++){
    if (deleteNum == tab[i])break;                                          //szukanie w kopcu wartosci która chce sie usunac i jej indexu
  }

    change(&tab[i],&tab[tab_size-1]);                                       //umieszczenie ostatniej wartosci z kopca w miejscu usunietego wezla
    tab_size--;                                                             //zmniejszenie rozmiaru tablicy o 1
    heapify(tab,tab_size,tab[i]);                                           //wywolanie funkcji co wywolania kopca
}

void change(int *x, int *y){                                                //zamiana miejscami wartosci
    int temp=*y;                                                            //utworzenie zmiennej pomocniczej i wrzucenie do niej indexu y wartosci z tablicy
    *y=*x;                                                                  //przypisanie indexu x wartosci z tablicy do miejsca gdzie jest przypisany index y
    *x=temp;                                                                //umieszczenie zawartosci zmiennej pomocniczej w miejscu indexu x
}


int main()
{
    int tab[10];                                                            //zainicjalizowanie tablicy dziesiecioelementowej
    int deleteNum=0;                                                        //zmienna potrzebna do wywolania usuwania
    
    printf("Wpisz 10 liczb: \n");                                           //dodawanie 10 wartosci do kopca
    for (int i = 0; i < 10; i++){
        int newValue=0;
        insert(tab,newValue);
    }
    for (int i = 0; i < tab_size; i++){                                     //wyswietlenie kopca
        printf("%d ", tab[i]);
    }
    printf("\n");

    printf("Wpisz liczbê do usuniêcia: ");  
    scanf ("%d", &deleteNum);   
    deleteRoot(tab,deleteNum);                                          //usuniecie konkrenej liczby z kopca

    for (int i = 0; i < tab_size; i++){                                 //wyswietlenie kopca
        printf("%d ", tab[i]);
    }

    return 0;
}
