#ifndef WCZYTYWANIE_DANYCH_H
#define WCZYTYWANIE_DANYCH_H

#define MAXINT 999999999

void ZainicjujTablice(int* d, int* p, bool *QS, ListaSasiedztwa** graf,  int n, int *zbior_wag, int **Macierz,int m);
void OdczytDanych(int m, ListaSasiedztwa *pw, ListaSasiedztwa** graf, int **Macierz, int *zbior_wag);
void losuj_dane(int m, ListaSasiedztwa *pw, ListaSasiedztwa** graf, int n,int *zbior_wag, int **Macierz);
void WyswietlWyniki(int n, int* d,int *p, ListaSasiedztwa *pw, int* S);


#endif // WCZYTYWANIE_DANYCH_H
