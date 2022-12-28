#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

/*
ZADANIE PARK (par)
https://szkopul.edu.pl/problemset/problem/vFeShEOnczXpanZEaYQpDnus/site/?key=statement

Park
Limit pamięci: 32 MB
Bajtocki Park Narodowy słynie z długiego (choć niezbyt szerokiego) pasma górskiego, rozciągającego się przez cały park z zachodu na wschód. Co roku przyjeżdżają do niego tłumy turystów, którzy często nie są zbyt rozgarnięci. Dlatego zarząd parku postanowił przygotować mapę całego pasma, podzieloną na fragmenty równej długości. Przy każdym punkcie podziału zarząd zamierza umieścić wysokość tego punktu oraz dwie inne liczby: wysokość najwyższego punktu podziału na zachód od niego oraz na wschód od niego.

Cała mapa jest już właściwie gotowa. Pozostaje jedynie obliczyć maksymalne wysokości na zachód i na wschód od każdego punktu podziału. Zarząd parku poprosił Cię o napisanie programu, który wyznaczy te wartości.

Wejście
W pierwszym wierszu standardowego wejścia znajduje się jedna liczba całkowita  () oznaczająca długość pasma górskiego. W każdym z następnych  wierszy znajduje się po jednej liczbie całkowitej  () oznaczającej wysokość -tego punktu podziału. Punkty te podane są w kolejności z zachodu na wschód.

W testach wartych przynajmniej 40% punktów zachodzi dodatkowy warunek .

Wyjście
Twój program powinien wypisać na standardowe wyjście dokładnie  wierszy, odpowiadających kolejnym punktom podziału (w kolejności z zachodu na wschód). W każdym z tych wierszy powinny znaleźć się dwie liczby całkowite  oraz  oddzielone pojedynczym odstępem - wysokość najwyższego punktu podziału na zachód od punktu  oraz na wschód od niego. W przypadku, gdy na zachód od punktu  nie ma szczytu wyższego niż , przyjmujemy . Podobnie, jeśli na wschód od punktu  nie ma szczytu wyższego niż , to przyjmujemy .

Przykład
Dla danych wejściowych:

5
1
3
2
4
3
poprawną odpowiedzią jest:

1 4
3 4
3 4
4 4
4 3
Autor zadania: Marian M. Kędzierski.
*/

const int MAX_NUMBER_OF_POINTS = 1e6 + 7;
int main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 
 int i;
 int points_number;
 int max_height;

/*example*/
points_number = 5;

/*or*/

/*read from line*/
/*
cin >> points_number;
*/

if(points_number>MAX_NUMBER_OF_POINTS){
    return -1;
}
int *points;
int *max_height_on_left;
int *max_height_on_right;
points = (int*) malloc(points_number*sizeof(int));
max_height_on_left = (int*) malloc(points_number*sizeof(int));
max_height_on_right = (int*) malloc(points_number*sizeof(int));

/*example*/
points[0] = 1;
points[1] = 3;
points[2] = 2;
points[3] = 4;
points[4] = 3;

/*or */

/*read from line*/
/* 
 cin >> points_number;
 for (i=0; i<points_number; i++)
    cin >> points[i];
*/
 max_height = 0;
 for (i=0; i<points_number; i++) {
    if ( points[i] > max_height ) {
       max_height = points[i]; 
    }
    max_height_on_left[i] = max_height;
 }

 max_height = 0;
 for (i = points_number; i>=0; --i) {
    if ( points[i] > max_height ) {
       max_height = points[i];
    }
    max_height_on_right[i] = max_height;
 }

 for (i=0; i<points_number; i++) {
    cout << max_height_on_left[i] << " " << max_height_on_right[i] << "\n";
 }

 free(points);
 free(max_height_on_left);
 free(max_height_on_right);
 return 0;
}
