#include <iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cmath>

#define ILOSC_TABLIC 100
#define ROZMIAR_TABLICY_1 10000
#define ROZMIAR_TABLICY_2 50000
#define ROZMIAR_TABLICY_3 100000
#define ROZMIAR_TABLICY_4 500000
#define ROZMIAR_TABLICY_5 1000000

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

using namespace std;

void shift_downv2(int tab[],int i, int n)
{
    int j;
    int index=i;
        while (index<=n/2)
        {
            j=2*index;
            if(j+1<=n && tab[j+1]>tab[j])
                j=j+1;
            if(tab[index]<tab[j])
            {
                int x=tab[index];
                tab[index]=tab[j];
                tab[j]= x;
            }
            else break;
            index = j;
        }
}

void buduj_kopiec(int tab[], int n)
{
    for(int i=n/2;i>0;i--)
    {

        shift_downv2(tab-1,i,n);
    }

}
void burz_kopiec(int tab[],int n)
{
    for(int i=n-1; i>0; i--)
    {

        swap(tab[0],tab[i]);
        shift_downv2(tab-1, 1, i);
    }
}

int partycjonowanie(int tab[], int lewy, int prawy)
{
    int r;
	int i = lewy - 1, j = prawy + 1;
	int srodek = tab[(lewy+prawy)/2]; //wybieramy punkt odniesienia

	while(1)
	{
		while(srodek>tab[++i]); // szukamy elementow pomeidzy srodkiem ( sprawdzamy czy elementy sie ze soba nie minely)
		while(srodek<tab[--j]);


		if( i <= j)              // jezeli sa elementy po niewlasciwej stronie zamieniamy ze soba
			swap(tab[i],tab[j]); // zamieniamy ze soba skladniki z lewej na prawa
		else
			break;
	}

	tab[prawy] = tab[i];
	tab[i] = srodek;
    return i;
}

void quick_sort(int tab[], int lewy, int prawy)
{

    int k;
	if(prawy <= lewy) return;


	if(lewy<prawy)
    {

	k=partycjonowanie(tab,lewy,prawy);
    quick_sort(tab,lewy,k-1);
    quick_sort(tab,k+1,prawy);

    }
}
void sortowanie_przez_wstawianie(int tab[], int n)
{
     int pom, j;
     for(int i=1; i<n; i++)
     {
                            //wstawienie elementu w odpowiednie miejsce
             pom = tab[i]; //ten element bêdzie wstawiony w odpowiednie miejsce
             j = i-1;


             while(j>=0 && tab[j]>pom)  //przesuwanie elementów wiêkszych od pom
             {
                        tab[j+1] = tab[j]; //przesuwanie elementów
                        --j;
             }
             tab[j+1] = pom; //wstawienie pom w odpowiednie miejsce
     }
}


void sortowanie_introspektywne(int tab[], int n, int m) // zlozonosc obliczeniowa wynosi (2log n)
{
    int i;
    if(m<=0)
    {
        buduj_kopiec(tab,n);
        burz_kopiec(tab,n);
        return;
    }
    i=partycjonowanie(tab,0,n-1);
    if(i>9)
        sortowanie_introspektywne(tab,i,m-1);
    if(n-1-i>9)
        sortowanie_introspektywne(tab+i+1,n-1-i,m-1);
}


void sortowanie_hybrydowe(int tab[], int n)
{
	sortowanie_introspektywne(tab, n, (int)floor(2 * log2(n)) );
	sortowanie_przez_wstawianie(tab, n);
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
        sortowanie_hybrydowe(tablica_ilosc_10k[i],ROZMIAR_TABLICY_1-1);
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
        sortowanie_hybrydowe(tablica_ilosc_10k[i], ROZMIAR_TABLICY_2-1); ///  rozmiar-1 czy tylko rozmiar ?????????????????????
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
        sortowanie_hybrydowe(tablica_ilosc_10k[i], ROZMIAR_TABLICY_3-1); ///  rozmiar-1 czy tylko rozmiar ?????????????????????
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
        sortowanie_hybrydowe(tablica_ilosc_10k[i], ROZMIAR_TABLICY_4-1); ///  rozmiar-1 czy tylko rozmiar ?????????????????????
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
        sortowanie_hybrydowe(tablica_ilosc_10k[i], ROZMIAR_TABLICY_5-1); ///  rozmiar-1 czy tylko rozmiar ?????????????????????
        stop=clock();
        czas=(double)(stop-start)/CLOCKS_PER_SEC;
        pomiar_1m[i]=czas;
        suma_czasu=suma_czasu+czas;
        czas_danego_rozmiaru_tablicy=czas_danego_rozmiaru_tablicy+czas;
    }

     cout<<"czas dla tablicy1m = "<<czas_danego_rozmiaru_tablicy<<endl;
        czas_danego_rozmiaru_tablicy=0;
    cout<<suma_czasu<<endl;
}


int main()
{
    cout<<"sortowanie introspektywne"<<endl<<endl;

    //zapelnij_tablice_losowo();
    zapelnij_tablice_w_odwrotnej_kolejnosci();
    //  zapelnij_tablice_czesciowo_posortowane(50);
   pomiar_czasu_dla_juz_zapelnionych_tablic();
    return 0;
}
