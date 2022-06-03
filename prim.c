#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 9999

#define V 11                                                                    //liczba wierzcho�k�w

int minKey(int key[], bool mds[])                                               //funkcja do znalezienia wierzcho�ka
{
	int min = INT_MAX, min_index;                                               //utworzenie warto�ci minimalnej

	for (int i = 0; i < V; i++){
		if (mds[i] == false && key[i] < min){
			min = key[i], min_index = i;
        }
	}
	return min_index;
}

void prim(int graf[V][V])                                                       //funkcja do tworzenia mds
{
	int vertex[V];                                                              //tablica do przechowywania mds
	int key[V];                                                                 //warto�ci u�ywane do wybrania kraw�dzi o minimalnej wadze
	bool mds[V];                                                                //��czniki

	for (int i = 0; i < V; i++){                                                //ustawienie wszysztkich ��cznik�w jako max
		key[i] = INT_MAX, mds[i] = false;
    }
	key[0] = 0;                                                                 //wybranie wierzcho�ka 0 jako pierwszego
	vertex[0] = -1;                                                             //pierwszy w�ze� jest zawsze korzeniem mds

	for (int count = 0; count < V - 1; count++) {                               //mds ma 11 wierzcho�k�w
		int u = minKey(key, mds);                                               //minimalny wierzcho�ek klucza ze zbioru wierzcho�k�w nieuwzgl�dnionych jeszcze w mds
		mds[u] = true;                                                          //dodania wiercho�ka do tablicy mds

		for (int i = 0; i < V; i++){                                            //zmiana warto�ci klucza i indeksu, rozwarzamy wierzcho�ki kt�re nie sa jeszcze zawarte w mds
			if (graf[u][i] && mds[i] == false && graf[u][i] < key[i]){          //do mds s� wrzucane tylko warto�ci nie zerowe i mniejsze od wcze�niej zapisanych
				vertex[i] = u, key[i] = graf[u][i];
            }
        }
    }

	wypisz(vertex, graf);                                                       //wywo�anie funkcji drukuj�cej
}

int wypisz(int vertex[], int graf[V][V])                                        //funkcja drukuj�ca
{
	printf("Vertex - Lacznik(krawedz) \tWaga\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t\t\t\t%d \n", vertex[i], i, graf[i][vertex[i]]);
}

int main()
{
	int graf[V][V] = { {0, 0, 1, 4, 5, 5, 0, 0, 22, 0, 0},                      //wpisanie wszystkich wierzcho�k�w do grafu
                    {0, 0, 16, 0, 0, 0, 0, 0, 3, 30, 0},
                    {1, 16, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                    {4, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                    {5, 0, 0, 1, 0, 12, 0, 0, 0, 0, 0},
                    {5, 0, 0, 0, 12, 0, 27, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 27, 0, 5, 0, 10, 18},
                    {0, 0, 0, 0, 0, 0, 5, 0, 5, 20, 0},
                    {22, 3, 0, 0, 0, 0, 0, 5, 0, 25, 0},
                    {0, 30, 0, 0, 0, 0, 10, 20, 25, 0, 3},
                    {0, 0, 0, 0, 0, 0, 18, 0, 0, 3, 0 }};
	prim(graf);                                                                 //wywo�anie funkcji

	return 0;
}
