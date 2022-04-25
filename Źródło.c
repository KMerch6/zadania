#include <iostream>
#include "Źródło.h"

using namespace std;

void selectionSort(int tab[]) {						//utworzenie funkcji sortującej
	for (int i = 0; i < 11;i++) {					//wybranie cyfry z tabeli
		int min = i;

		for (int j = i+1; j < 11;j++) {				//szukanie najmniejszej cyfty spośród pozostałych
			if (tab[min] > tab[j]) min = j;
		}
			int x = tab[i];							//zamiana pierwszej cyfry z najmniejszą w tabeli
			tab[i] = tab[min];
			tab[min] = x;
	}
}

int main() {
	int tab[11] = {0,1,2,6,1,1,5,1,4,8,7};			//tworzenie tabeli

	selectionSort(tab);								//wywołanie funkcji

	for (int i = 0;i < 11;i++) {
		printf("%d", tab[i]);						//wyświetlenie posortowanej tabeli
	}
}
