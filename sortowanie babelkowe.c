#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int tab[]) {
	for (int i = 0;i < 14;i++) {                                //utworzenie funkcji sortuj¹cej
		for (int j = 0; j < (15-i-1);j++) {
			if (tab[j] > tab[j + 1]) {                          //porównanie cyfry z cyfr¹ nastêpn¹ w celu spawdzenia czy dana cyfra jest wiêksza od nastêpnej

				int x = tab[j];
				tab[j] = tab[j + 1];                            //podmiana cyfr
				tab[j + 1] = x;
			}
		}
	}
}
int main() {
	int tab[15] = { 0,1,2,6,1,1,5,1,4,8,7,9,4,3,5 };			//tworzenie tabeli

	bubbleSort(tab);								            //wywo³anie funkcji

	for (int i = 0;i < 15;i++) {
		printf("%d",tab[i]);					                //wyœwietlenie posortowanej tabeli
	}
	return 0;
}
