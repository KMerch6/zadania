// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start) { //utworzenie funkcji
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++)       //tworzenie macierzy
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {         //wylicznie dystansu
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {    //wylicznie najbardziej optymalnego dystansu
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }


  for (i = 0; i < n; i++){
      printf("\nDistance from source to %d: %d", i, distance[i]); //wyświetlenie dystansu
}
int main() {
  int Graph[MAX][MAX], i, j, n, u;  //zainicjalizowanine zmiennych
  n = 5; //ilość wierzchołków
                    //wpisanie wszystkich wierzchołków do grafu
  Graph[0][0] = 0;
  Graph[0][1] = 6;
  Graph[0][2] = 0;
  Graph[0][3] = 1;
  Graph[0][4] = 0;

  Graph[1][0] = 6;
  Graph[1][1] = 0;
  Graph[1][2] = 5;
  Graph[1][3] = 2;
  Graph[1][4] = 2;

  Graph[2][0] = 0;
  Graph[2][1] = 5;
  Graph[2][2] = 0;
  Graph[2][3] = 0;
  Graph[2][4] = 5;

  Graph[3][0] = 1;
  Graph[3][1] = 2;
  Graph[3][2] = 0;
  Graph[3][3] = 0;
  Graph[3][4] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 2;
  Graph[4][2] = 5;
  Graph[4][3] = 1;
  Graph[4][4] = 0;

  u = 0;
  Dijkstra(Graph, n, u); //wywo³anie funkcji

  return 0;
}
