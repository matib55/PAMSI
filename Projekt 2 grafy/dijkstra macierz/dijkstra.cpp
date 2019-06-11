#include "dijkstra.h"
#include "wczytywanie_danych.h"



void dijkstra_Macierz()
{
    int i,j,m,n,v,u,w,x,y,sptr,*d,*p,*S,*zbior_wag;
  bool *QS;                       // Zbiory Q i S
  ListaSasiedztwa **graf;                 // Tablica list sąsiedztwa
  ListaSasiedztwa *pw,*rw;
  int **Macierz;
cout<<"Podaj ilosc krawedzi, liczbe wierzcholkow oraz wierzcholek startowu"<<endl;
  cin >> m>> n >> v;             // Węzeł startowy, liczba wierzchołków i krawędzi

  // Tworzymy tablice dynamiczne

  d = new int [n];                // Tablica kosztów dojścia
  p = new int [n];                // Tablica poprzedników
  QS = new bool [n];              // Zbiory Q i S
  graf = new ListaSasiedztwa * [n];       // Tablica list sąsiedztwa
  S = new int [n];                // Stos
  sptr = 0;                       // Wskaźnik stosu

  Macierz = new int * [n];    // Tworzymy tablicę wskaźników
   zbior_wag=new int[n];    // Tworzymy tablicę wag

   for(i = 0; i < n; i++)
    Macierz[i] = new int [m]; // Tworzymy wiersze


  cout << endl;



  ZainicjujTablice(d,p,QS,graf,n,zbior_wag,Macierz,m);
  OdczytDanych(m,pw,graf,Macierz,zbior_wag);
  d[v] = 0;                       // Koszt dojścia v jest zerowy

  // Wyznaczamy ścieżki

  for(i = 0; i < n; i++)
  {
    // Szukamy wierzchołka w Q o najmniejszym koszcie d

    for(j = 0; QS[j]; j++);
    for(u = j++; j < n; j++)
      if(!QS[j] && (d[j] < d[u])) u = j;

    // Znaleziony wierzchołek przenosimy do S

    QS[u] = true;
    // Modyfikujemy odpowiednio wszystkich sąsiadów u, którzy są w Q

    for(int l=0;l<m;l++) //krawedzie
    {
    if (Macierz[u][l] != 0)  // potrzebne ??? tak jak k!=u && Macierz[k][l]==1????
    for(int k=0;k<n;k++)  //wierzcholki
      if(k!=u && Macierz[k][l]==1 && !QS[k] && (d[k] > d[u] + zbior_wag[l]))
      {

        d[k] = d[u] + zbior_wag[l];
        p[k] = u;
      }
    }
  }
  WyswietlWyniki(n,d,p,pw,S);

}


void dijkstra_Macierz_pod_testy(int n, double gestosc)// ilosc wierzcholkow oraz gestosc
{

    int i,j,m,v,u,w,x,y,sptr,*d,*p,*S,*zbior_wag;
  bool *QS;                       // Zbiory Q i S
  ListaSasiedztwa **graf;                 // Tablica list sąsiedztwa
  ListaSasiedztwa *pw,*rw;
  int **Macierz;

  srand( time( NULL ) );

   m=(n*(n-1)*gestosc)/2; // liczba krawedzi
   v=rand()%n+0; // wierzcholek startowy

   //cout<<m<<" "<<n<<" "<<v<<endl;

  // Tworzymy tablice dynamiczne

  d = new int [n];                // Tablica kosztów dojścia
  p = new int [n];                // Tablica poprzedników
  QS = new bool [n];              // Zbiory Q i S
  graf = new ListaSasiedztwa * [n];       // Tablica list sąsiedztwa
  S = new int [n];                // Stos
  sptr = 0;                       // Wskaźnik stosu

  Macierz = new int * [n];    // Tworzymy tablicę wskaźników
   zbior_wag=new int[n];    // Tworzymy tablicę wag

   for(i = 0; i < n; i++)
    Macierz[i] = new int [m]; // Tworzymy wiersze

  ZainicjujTablice(d,p,QS,graf,n,zbior_wag,Macierz,m);
  losuj_dane(m,pw,graf,n, zbior_wag, Macierz);
  d[v] = 0;                       // Koszt dojścia v jest zerowy

  // Wyznaczamy ścieżki

  for(i = 0; i < n; i++)
  {
    // Szukamy wierzchołka w Q o najmniejszym koszcie d

    for(j = 0; QS[j]; j++);
    for(u = j++; j < n; j++)
      if(!QS[j] && (d[j] < d[u])) u = j;

    // Znaleziony wierzchołek przenosimy do S

    QS[u] = true;
    // Modyfikujemy odpowiednio wszystkich sąsiadów u, którzy są w Q

    for(int l=0;l<m;l++) //krawedzie
    {
    if (Macierz[u][l] != 0)
    for(int k=0;k<n;k++)  //wierzcholki
      if(k!=u && Macierz[k][l]==1 && !QS[k] && (d[k] > d[u] + zbior_wag[l]))
      {
        d[k] = d[u] + zbior_wag[l];
        p[k] = u;
      }
    }
  }
  //WyswietlWyniki(n,d,p,pw,S);


}
