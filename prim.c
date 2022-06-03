#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 9999

#define V 11                                                                    //liczba wierzcho³ków

int minKey(int key[], bool mds[])                                               //funkcja do znalezienia wierzcho³ka
{
	int min = INT_MAX, min_index;                                               //utworzenie wartoœci minimalnej

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
	int key[V];                                                                 //wartoœci u¿ywane do wybrania krawêdzi o minimalnej wadze
	bool mds[V];                                                                //³¹czniki

	for (int i = 0; i < V; i++){                                                //ustawienie wszysztkich ³¹czników jako max
		key[i] = INT_MAX, mds[i] = false;
    }
	key[0] = 0;                                                                 //wybranie wierzcho³ka 0 jako pierwszego
	vertex[0] = -1;                                                             //pierwszy wêze³ jest zawsze korzeniem mds

	for (int count = 0; count < V - 1; count++) {                               //mds ma 11 wierzcho³ków
		int u = minKey(key, mds);                                               //minimalny wierzcho³ek klucza ze zbioru wierzcho³ków nieuwzglêdnionych jeszcze w mds
		mds[u] = true;                                                          //dodania wiercho³ka do tablicy mds

		for (int i = 0; i < V; i++){                                            //zmiana wartoœci klucza i indeksu, rozwarzamy wierzcho³ki które nie sa jeszcze zawarte w mds
			if (graf[u][i] && mds[i] == false && graf[u][i] < key[i]){          //do mds s¹ wrzucane tylko wartoœci nie zerowe i mniejsze od wczeœniej zapisanych
				vertex[i] = u, key[i] = graf[u][i];
            }
        }
    }

	wypisz(vertex, graf);                                                       //wywo³anie funkcji drukuj¹cej
}

int wypisz(int vertex[], int graf[V][V])                                        //funkcja drukuj¹ca
{
	printf("Vertex - Lacznik(krawedz) \tWaga\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t\t\t\t%d \n", vertex[i], i, graf[i][vertex[i]]);
}

int main()
{
	int graf[V][V] = { {0, 0, 1, 4, 5, 5, 0, 0, 22, 0, 0},                      //wpisanie wszystkich wierzcho³ków do grafu
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
	prim(graf);                                                                 //wywo³anie funkcji

	return 0;
}
