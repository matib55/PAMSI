#include "dijkstra.h"
#include "wczytywanie_danych.h"


void dijkstra_lista()
  {
    int i,j,m,n,v,u,w,x,y,sptr,*d,*p,*S;
  bool *QS;                       // Zbiory Q i S
  ListaSasiedztwa **graf;                 // Tablica list sąsiedztwa
  ListaSasiedztwa *pw,*rw;

  cout<<"Podaj ilosc krawedzi, liczbe wierzcholkow oraz wierzcholek startowu"<<endl;
  cin >> m>> n >> v;             // Węzeł startowy, liczba wierzchołków i krawędzi

  // Tworzymy tablice dynamiczne

  d = new int [n];                // Tablica kosztów dojścia
  p = new int [n];                // Tablica poprzedników
  QS = new bool [n];              // Zbiory Q i S
  graf = new ListaSasiedztwa * [n];       // Tablica list sąsiedztwa
  S = new int [n];                // Stos
  sptr = 0;                       // Wskaźnik stosu

  cout << endl;

  ZainicjujTablice(d,p,QS,graf,n);
  OdczytDanych(m,pw,graf);
  d[v] = 0;                       // Koszt dojścia v jest zerowy
  //tworz_sciezke(n, QS, d, p, pw, graf);


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

    for(pw = graf[u]; pw; pw = pw->next)
      if(!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
      {
        d[pw->v] = d[u] + pw->w;
        p[pw->v] = u;
      }
  }
  WyswietlWyniki(n,d,p,pw,S);

  // Usuwamy tablice dynamiczne

  delete [] d;
  delete [] p;
  delete [] QS;
  delete [] S;

  for(i = 0; i < n; i++)
  {
    pw = graf[i];
    while(pw)
    {
      rw = pw;
      pw = pw->next;
      delete rw;
    }
  }

  delete [] graf;
}




void dijkstra_lista_pod_test(int n, double gestosc)// ilosc wierzcholkow oraz gestosc
  {
    int i,j,m,v,u,w,x,y,sptr,*d,*p,*S;
  bool *QS;                       // Zbiory Q i S
  ListaSasiedztwa **graf;                 // Tablica list sąsiedztwa
  ListaSasiedztwa *pw,*rw;

  srand( time( NULL ) );

   m=(n*(n-1)*gestosc)/2; // liczba krawedzi
   v=rand()%n+0; // wierzcholek startowy


  // cout<<m<<" "<<n<<" "<<v<<endl;


  // Tworzymy tablice dynamiczne

  d = new int [n];                // Tablica kosztów dojścia
  p = new int [n];                // Tablica poprzedników
  QS = new bool [n];              // Zbiory Q i S
  graf = new ListaSasiedztwa * [n];       // Tablica list sąsiedztwa
  S = new int [n];                // Stos
  sptr = 0;                       // Wskaźnik stosu


  ZainicjujTablice(d,p,QS,graf,n);
  losuj_dane(m,pw,graf,n);
  d[v] = 0;                       // Koszt dojścia v jest zerowy
  //tworz_sciezke(n, QS, d, p, pw, graf);


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

    for(pw = graf[u]; pw; pw = pw->next)
      if(!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
      {
        d[pw->v] = d[u] + pw->w;
        p[pw->v] = u;
      }
  }
  //WyswietlWyniki(n,d,p,pw,S);
// Usuwamy tablice dynamiczne

  delete [] d;
  delete [] p;
  delete [] QS;
  delete [] S;

  for(i = 0; i < n; i++)
  {
    pw = graf[i];
    while(pw)
    {
      rw = pw;
      pw = pw->next;
      delete rw;
    }
  }

  delete [] graf;
}
