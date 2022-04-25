#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int czybylo=0;

void selectionSort(int tab[]) {						                                        //utworzenie funkcji sortującej
	for (int i = 0; i < 11;i++) {					                                        //wybranie cyfry z tabeli
		int min = i;

		for (int j = i+1; j < 11;j++) {				                                        //szukanie najmniejszej cyfty spośród pozostałych
			if (tab[min] > tab[j]) min = j;
		}
			int x = tab[i];							                                        //zamiana pierwszej cyfry z najmniejszą w tabeli
			tab[i] = tab[min];
			tab[min] = x;
	}
}

void binarySearch(int tab[],int poczatek,int rozmiar,int szukane){                          //utworzenie funkcji szukającej
    int pivot;                                                                              //implementacja pivota
    do{
        pivot=poczatek + (rozmiar-poczatek)/2;                                              //równanie na pivota
        if(szukane>tab[pivot]) poczatek=pivot+1;                                            //przejście w szukaniu na połowę z większymi wartościami
        else if(szukane<tab[pivot]) rozmiar=pivot-1;                                        //przejście w szukaniu na połowę z mniejszymi wartościami
        else if (szukane==tab[pivot]){                                                      //jeżeli szukana liczba została znaleziona
        ++czybylo;                                                                          //zmienna pomocnicza o 1 większa
        if(czybylo==1) printf("\nindex \t adres w pamiêci\n");                              //sprawienie, że tylko raz wyświetli się opis co jest czym
            printf("%d ", pivot);                                                           //wyświetlenie indexu
            printf("\t\t");                                                                 //tabulacja
            printf("%d ", &tab[pivot]);                                                     //adres pamięci liczby w tabeli
       }
       if (pivot == poczatek + (rozmiar-poczatek)/2){                                       //zaprzestanie programu, żeby nie był w nieskończonej pętlii
            break;
        }
    }while(pivot>=0&&pivot<=9);                                                             //dzięki temu nie wyjdziemy poza zakres tabeli
}


int main() {
    setlocale(LC_CTYPE, "Polish");                                                          //ustawienie polskich znaków w konsoli
    int tab[10];                                                                            //implementacja zmiennych
    int szukane=0;
    srand(time(0));
    int poczatek=0;
    int rozmiar = 10;

    printf("Proszę o zwolnienie blokady… i rozpoczynamy losowanie dziesięciu liczb: \n");
    for(int i=0;i<10;i++){                                                                  //pętla dzięki której zapisujemy nowe wartości do tabeli
        int r = rand()%50;                                                                  //losowanie liczby od 0 do 50
        printf("%d", r);                                                                    //wypisanie wylosowanej cyfry
        tab[i]=r;                                                                           //wpisanie cyfry do tabeli
        printf("\t");                                                                       //tabulacja
    }

	selectionSort(tab);								                                        //wywołanie funkcji sortującej

    printf("\nLiczby posortowane: \n");
	for (int i = 0;i < 10;i++) {                                                            //poruszanie się po tabeli
		printf("%d", tab[i]);						                                        //wyświetlenie posortowanej tabeli
		printf("\t");                                                                       //tabulacja
	}

    printf("\n\nWpisz wartość którą chcesz wyszukać: ");
    scanf ("%d", &szukane);                                                                 //wpisanie liczby którą chcemy znaleźć w tabeli

	binarySearch(tab,poczatek,rozmiar-1,szukane);                                           //wywołanie funkcji szukającej

	if(czybylo==0)printf("\nnie ma takiej liczby\n");                                       //jeżeli nie byłoby żadnej liczby to wyświetli się komunikat

	return 0;
}
