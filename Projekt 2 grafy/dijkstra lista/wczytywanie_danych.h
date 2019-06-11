#ifndef WCZYTYWANIE_DANYCH_H
#define WCZYTYWANIE_DANYCH_H
#define MAXINT 999999999


void ZainicjujTablice(int* d, int* p, bool *QS, ListaSasiedztwa** graf,  int n);
void OdczytDanych(int m, ListaSasiedztwa *pw, ListaSasiedztwa** graf) ;
void WyswietlWyniki(int n, int* d,int *p, ListaSasiedztwa *pw, int* S);
void losuj_dane(int m, ListaSasiedztwa *pw, ListaSasiedztwa** graf, int n);


#endif // WCZYTYWANIE_DANYCH_H
