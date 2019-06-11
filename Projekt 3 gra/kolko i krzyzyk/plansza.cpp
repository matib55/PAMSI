#include "plansza.hh"

void rysuj_plansze(char **znak, int rozmiar_planszy)
{
    for(int i=1; i<=rozmiar_planszy; i++)
        cout<<"  "<<i<<" ";

        cout<<endl;

    for(int i=1; i<=rozmiar_planszy; i++)    // petla wierszy, rzedu
    {
        cout<<i;
        for(int j=1; j<=rozmiar_planszy; j++)   //petla kolumny
        {
            cout<<" "<<znak[i][j]<<" ";      // rysowanie pojedynczego pola
             if(j%rozmiar_planszy !=0)
                cout << "|";                    // kreska odzielajaca pole
        }

        cout<<endl;

        cout<<" ";
        if(i != rozmiar_planszy)
        for(int k=1; k<=rozmiar_planszy; k++)           // rysowanie poziomej kreski odzielajacej wiersze
        {
            cout<<"---";
            if(k!=rozmiar_planszy)
            cout<<"+";
        }
            cout<<endl;
    }
}
