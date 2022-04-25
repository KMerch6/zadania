#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "Polish");                                      //ustawienie polskich znaków w konsoli
    int tab[10];                                                        //implementacja zmiennych
    int newValue=0;
    int szukane=0;
    int czybylo=0;

    printf("Wpisz 10 wartoœci:\n");
    for(int i=0;i<10;i++){                                              //pętla dzięki której zapisujemy nowe wartości do tabeli
        scanf ("%d", &newValue);                                        //wpisywanie wartoœci do konsoli
        tab[i]=newValue;                                                //umieszczenie nowej wartości w tabeli
    }

    printf("\n\nWpisz wartoœæ któr¹ chcesz wyszukaæ: ");
    scanf ("%d", &szukane);                                             //wpisanie liczby którą chcemy znaleźć w tabeli

    for(int i=0;i<10;i++){                                              //poruszanie się po tabeli
        if(tab[i]==szukane){                                            //sprawdzanie czy liczba z tabeli jest równa szukanej liczbie
            czybylo ++;                                                 //powiększenie o 1 zmiennej pomocniczej
            if(czybylo==1) printf("\nindex \t adres w pamiêci\n");      //sprawienie, że tylko raz wyświetli się opis co jest czym
            printf("%d ", i);                                           //wyświetlenie indexu
            printf("\t\t");                                             //tabulacja
            printf("%d ", &tab[i]);                                     //adres pamięci liczby w tabeli
            printf("\n");                                               //jeżeli byłyby kolejne liczby takie jak szukana to będą w nowej linii
        }
        if(czybylo==0)printf("\nnie ma takiej liczby\n");               //jeżeli nie byłoby żadnej liczby to wyświetli się komunikat
    }
}
