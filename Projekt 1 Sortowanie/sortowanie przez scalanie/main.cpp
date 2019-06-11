#include <iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>

#define ILOSC_TABLIC 100
#define ROZMIAR_TABLICY_1 10000
#define ROZMIAR_TABLICY_2 50000
#define ROZMIAR_TABLICY_3 100000
#define ROZMIAR_TABLICY_4 500000
#define ROZMIAR_TABLICY_5 1000000

using namespace std;

int tablica_ilosc_10k[ILOSC_TABLIC][ROZMIAR_TABLICY_1];
int tablica_ilosc_50k[ILOSC_TABLIC][ROZMIAR_TABLICY_2];
int tablica_ilosc_100k[ILOSC_TABLIC][ROZMIAR_TABLICY_3];
int tablica_ilosc_500k[ILOSC_TABLIC][ROZMIAR_TABLICY_4];
int tablica_ilosc_1m[ILOSC_TABLIC][ROZMIAR_TABLICY_5];

double pomiar_10k[ILOSC_TABLIC];
double pomiar_50k[ILOSC_TABLIC];
double pomiar_100k[ILOSC_TABLIC];
double pomiar_500k[ILOSC_TABLIC];
double pomiar_1m[ILOSC_TABLIC];


int pom[100000000];   // pomocnicza tablica do zczytywanie liczb   !!!!!zmien na ilosc!!!

void scalanie (int tab[], int lewy, int srodek, int prawy)  // scalanie posortowanych tablic
{
    int s=srodek+1;

    for(int i=lewy; i<=prawy; i++)
    {
            pom[i]=tab[i];
    }

    for(int k=lewy; k<=prawy; k++)
    {
        if(lewy<=srodek)   // jezeli lewy jest mniejszy niz srodkowy  l<s
            if(s<=prawy)  // jezeli srodkowy+1 jest mniejszy niz prawy s+1<p
               if(pom[s]<pom[lewy]) // jezeli srodek+1 jest mniejszy niz lewy l>s+1
                tab[k]=pom[s++];
                else
                tab[k]=pom[lewy++];
            else
            tab[k]=pom[lewy++];
        else
        tab[k]=pom[s++];

    }

}

void sortowanie_przez_scalanie(int tab[], int lewy, int prawy)
{
    if(prawy<=lewy) return;   // jezeli mamy tylko jeden element lub dwa posortowane

    int srodek=(lewy+prawy)/2;
    sortowanie_przez_scalanie(tab,lewy,srodek);
    sortowanie_przez_scalanie(tab,srodek+1,prawy);

    scalanie(tab,lewy,srodek,prawy);

}

void zapelnij_tablice_losowo()
{
    cout<<"tablice zapelnione losowo"<<endl<<endl;
    for(int i=0; i<ILOSC_TABLIC; i++)
    {
        for(int j=0; j<ROZMIAR_TABLICY_1; j++)
            tablica_ilosc_10k[i][j]=rand()%ROZMIAR_TABLICY_1;

        for(int j=0; j<ROZMIAR_TABLICY_2; j++)
            tablica_ilosc_50k[i][j]=rand()%ROZMIAR_TABLICY_2;

        for(int j=0; j<ROZMIAR_TABLICY_3; j++)
            tablica_ilosc_100k[i][j]=rand()%ROZMIAR_TABLICY_3;

        for(int j=0; j<ROZMIAR_TABLICY_4; j++)
            tablica_ilosc_500k[i][j]=rand()%ROZMIAR_TABLICY_4;

        for(int j=0; j<ROZMIAR_TABLICY_5; j++)
            tablica_ilosc_1m[i][j]=rand()%ROZMIAR_TABLICY_5;
    }
}

void zapelnij_tablice_w_odwrotnej_kolejnosci()
{
    cout<<"tablice zapelnione w odwrotnej kolejniosci"<<endl<<endl;
    for(int i=0; i<ILOSC_TABLIC; i++)
    {
        for(int j=0; j<ROZMIAR_TABLICY_1; j++)
            tablica_ilosc_10k[i][j]=ROZMIAR_TABLICY_1-j;
        for(int j=0; j<ROZMIAR_TABLICY_2; j++)
            tablica_ilosc_50k[i][j]=ROZMIAR_TABLICY_2-j;
        for(int j=0; j<ROZMIAR_TABLICY_3; j++)
            tablica_ilosc_100k[i][j]=ROZMIAR_TABLICY_3-j;
        for(int j=0; j<ROZMIAR_TABLICY_4; j++)
            tablica_ilosc_500k[i][j]=ROZMIAR_TABLICY_4-j;
        for(int j=0; j<ROZMIAR_TABLICY_5; j++)
            tablica_ilosc_1m[i][j]=ROZMIAR_TABLICY_5-j;
    }
}

void zapelnij_tablice_czesciowo_posortowane(double procent_posortowania)
{
    cout<<"tablice czesciowo posortowane - procent posortowania :    "<<procent_posortowania<<endl<<endl;
    int ile_sortowac;
    zapelnij_tablice_losowo();

    ile_sortowac=(procent_posortowania/100)*ROZMIAR_TABLICY_1;
    for(int i=0; i<ILOSC_TABLIC; i++)
        sort(tablica_ilosc_10k[i]+0,tablica_ilosc_10k[i]+ile_sortowac); // komenda ktora sortuje (tablica+(od ktorej liczby sortowac), tablica+(do kad sortowac))

    ile_sortowac=(procent_posortowania/100)*ROZMIAR_TABLICY_2;
    for(int i=0; i<ILOSC_TABLIC; i++)
        sort(tablica_ilosc_50k[i]+0,tablica_ilosc_50k[i]+ile_sortowac);

    ile_sortowac=(procent_posortowania/100)*ROZMIAR_TABLICY_3;
    for(int i=0; i<ILOSC_TABLIC; i++)
        sort(tablica_ilosc_100k[i]+0,tablica_ilosc_100k[i]+ile_sortowac);

   ile_sortowac=(procent_posortowania/100)*ROZMIAR_TABLICY_4;
    for(int i=0; i<ILOSC_TABLIC; i++)
        sort(tablica_ilosc_500k[i]+0,tablica_ilosc_500k[i]+ile_sortowac);

    ile_sortowac=(procent_posortowania/100)*ROZMIAR_TABLICY_5;
    for(int i=0; i<ILOSC_TABLIC; i++)
        sort(tablica_ilosc_1m[i]+0,tablica_ilosc_1m[i]+ile_sortowac);
}

void pomiar_czasu_dla_juz_zapelnionych_tablic()
{
    double czas=0;
    double suma_czasu=0;
    double czas_danego_rozmiaru_tablicy=0;
    clock_t start, stop;

    for(int i=0; i<ILOSC_TABLIC; i++)
    {
        start=clock();
        sortowanie_przez_scalanie(tablica_ilosc_10k[i], 0, ROZMIAR_TABLICY_1-1);
        stop=clock();
        czas=(double)(stop-start)/CLOCKS_PER_SEC;
        pomiar_10k[i]=czas;
        suma_czasu=suma_czasu+czas;
        czas_danego_rozmiaru_tablicy=czas_danego_rozmiaru_tablicy+czas;
    }
        cout<<"czas dla tablicy10k = "<<czas_danego_rozmiaru_tablicy<<endl;
        czas_danego_rozmiaru_tablicy=0;

    for(int i=0; i<ILOSC_TABLIC; i++)
    {
        start=clock();
        sortowanie_przez_scalanie(tablica_ilosc_50k[i], 0, ROZMIAR_TABLICY_2-1);
        stop=clock();
        czas=(double)(stop-start)/CLOCKS_PER_SEC;
        pomiar_50k[i]=czas;
        suma_czasu=suma_czasu+czas;
        czas_danego_rozmiaru_tablicy=czas_danego_rozmiaru_tablicy+czas;
    }
     cout<<"czas dla tablicy50k = "<<czas_danego_rozmiaru_tablicy<<endl;
     czas_danego_rozmiaru_tablicy=0;

    for(int i=0; i<ILOSC_TABLIC; i++)
    {
        start=clock();
        sortowanie_przez_scalanie(tablica_ilosc_100k[i], 0, ROZMIAR_TABLICY_3-1);
        stop=clock();
        czas=(double)(stop-start)/CLOCKS_PER_SEC;
        pomiar_100k[i]=czas;
        suma_czasu=suma_czasu+czas;
        czas_danego_rozmiaru_tablicy=czas_danego_rozmiaru_tablicy+czas;
    }
     cout<<"czas dla tablicy100k = "<<czas_danego_rozmiaru_tablicy<<endl;
      czas_danego_rozmiaru_tablicy=0;

    for(int i=0; i<ILOSC_TABLIC; i++)
    {
        start=clock();
        sortowanie_przez_scalanie(tablica_ilosc_500k[i], 0, ROZMIAR_TABLICY_4-1);
        stop=clock();
        czas=(double)(stop-start)/CLOCKS_PER_SEC;
        pomiar_500k[i]=czas;
        suma_czasu=suma_czasu+czas;
       czas_danego_rozmiaru_tablicy=czas_danego_rozmiaru_tablicy+czas;
    }
     cout<<"czas dla tablicy500k = "<<czas_danego_rozmiaru_tablicy<<endl;
      czas_danego_rozmiaru_tablicy=0;

    for(int i=0; i<ILOSC_TABLIC; i++)
    {
        start=clock();
        sortowanie_przez_scalanie(tablica_ilosc_1m[i], 0, ROZMIAR_TABLICY_5-1);
        stop=clock();
        czas=(double)(stop-start)/CLOCKS_PER_SEC;
        pomiar_1m[i]=czas;
        suma_czasu=suma_czasu+czas;
        czas_danego_rozmiaru_tablicy=czas_danego_rozmiaru_tablicy+czas;
    }
     cout<<"czas dla tablicy1m = "<<czas_danego_rozmiaru_tablicy<<endl;
     cout<<endl<<endl;
    cout<<"suma wszystkich czasow = "<<suma_czasu<<endl;
}

int main()
{
    int n=10000; // liczba elementow tablicy
    int tab[n];
    int pom[n];

    cout<<"sortowanie przez scalanie"<<endl<<endl;
   zapelnij_tablice_losowo();
  // zapelnij_tablice_w_odwrotnej_kolejnosci();
  //zapelnij_tablice_czesciowo_posortowane(25);
   pomiar_czasu_dla_juz_zapelnionych_tablic();



    return 0;
}
