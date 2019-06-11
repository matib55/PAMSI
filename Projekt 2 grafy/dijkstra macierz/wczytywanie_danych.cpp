#include "wczytywanie_danych.h"


void ZainicjujTablice(int* d, int* p, bool *QS, ListaSasiedztwa** graf,  int n, int *zbior_wag, int **Macierz,int m) {
	 // Inicjujemy tablice dynamiczne

  for(int i = 0; i < n; i++)
  {
    d[i] = MAXINT;
    zbior_wag[i]=0;
    p[i] = -1;
    QS[i] = false;
    graf[i] = NULL;
  }

  // Macierz wypełniamy zerami

  for(int i = 0; i < n; i++)
    for(int j= 0; j < m; j++) Macierz[i][j] = 0;
}

void OdczytDanych(int m, ListaSasiedztwa *pw, ListaSasiedztwa** graf, int **Macierz, int *zbior_wag) {

  // Odczytujemy dane wejściowe
int x,y,w;
  for(int i = 0; i < m; i++)
  {
    cin >> x >> y >> w;           // Odczytujemy krawędź z wagą
    pw = new ListaSasiedztwa;             // Tworzymy element listy sąsiedztwa
    pw->v = y;                    // Wierzchołek docelowy krawędzi
    pw->w = w;                    // Waga krawędzi
    zbior_wag[i]=w;
    pw->next = graf[x];
    graf[x] = pw;                 // Element dołączamy do listy
    Macierz[x][i]=1;
    Macierz[y][i]=1;
  }
}

void losuj_dane(int m, ListaSasiedztwa *pw, ListaSasiedztwa** graf, int n,int *zbior_wag, int **Macierz) {

  // Odczytujemy dane wejściowe
int x,y,w;
  for(int i = 0; i < m; i++)
  {
        x=rand()%n;
        y=rand()%n;
        w=rand()%10;
      // cout<<x<<" "<<y<<" "<<w<<endl;
    pw = new ListaSasiedztwa;             // Tworzymy element listy sąsiedztwa
    pw->v = y;                    // Wierzchołek docelowy krawędzi
    pw->w = w;                    // Waga krawędzi
    zbior_wag[i]=w;
    pw->next = graf[x];
    graf[x] = pw;                 // Element dołączamy do listy
    Macierz[x][i]=1;
    Macierz[y][i]=1;
  }
}


void WyswietlWyniki(int n, int* d,int *p, ListaSasiedztwa *pw, int* S) {
	int sptr = 0;
	// Gotowe, wyświetlamy wyniki

  for(int i = 0; i < n; i++)
  {
    cout << i << ": ";

    // Ścieżkę przechodzimy od końca ku początkowi,
    // Zapisując na stosie kolejne wierzchołki

    for(int j = i; j > -1; j = p[j]) S[sptr++] = j;

    // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu

    while(sptr) cout << S[--sptr] << " ";

    // Na końcu ścieżki wypisujemy jej koszt

    cout << "$" << d[i] << endl;
  }
}
