#include <stdlib.h>
#include <stdio.h>

void insertionSort(int tab[]) {                                 //utworzenie funkcji sortującej
	for (int i = 1; i < 15;i++) {                               //przemieszcznie sie po tablicy
		int x = tab[i];
		int j = i - 1;

		while (j > 0 && tab[j] > x) {                          //przesuwanie cyfry w lewo do momentu kiedy cyfra po lewej nie będzie mniejsza bądź równa
            tab[j+1]=tab[j];
			j--;
			tab[j + 1] = x;

		}

	}
}

int main() {
	int tab[15] = { 0,1,2,6,1,1,5,1,4,8,7,9,4,3,5 };			//tworzenie tabeli

	insertionSort(tab);								            //wywołanie funkcji

	for (int i = 0;i < 15;i++) {
		printf("%d", tab[i]);						            //wyœwietlenie posortowanej tabeli
	}
	return 0;
}
