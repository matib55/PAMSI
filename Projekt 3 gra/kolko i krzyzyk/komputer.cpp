#include "komputer.hh"
#include "wygrana_remis.hh"


//minmax glebokosc

int minimax(char **znak, char rozmiar_planszy, char gracz, int ilosc_w_rzedzie, int poziom_glebokosci)
{
    int m, mmx;  // mmx-maksimum lub mimimun zalezy co liczymy

    if(wygrana(znak,rozmiar_planszy,gracz,true,ilosc_w_rzedzie)==true)
    {
        if(gracz=='x') return 1;   // jezeli wygrana zwracamy jak nie to -1
        else return -1;
    }

    if(remis(znak, rozmiar_planszy,true)==true) return 0;

    if(poziom_glebokosci==4) return 0;

    if(gracz=='x') gracz='o';         // zamieniamy gracza
    else gracz='x';

    if(gracz=='o') mmx=(rozmiar_planszy*rozmiar_planszy) + 1;   // jezeli gramy my to podajemy wartosc max , a jak przeciwnik to wartosc min
    else mmx=-((rozmiar_planszy*rozmiar_planszy) + 1);

    for(int i=1; i<=rozmiar_planszy; i++)
        for(int j=1; j<=rozmiar_planszy; j++)
        {
            if(znak[i][j]==' ')
            {
                znak[i][j]=gracz;              // podstawiamy pod puste pole znak gracza by rozwazyc wszystkie przypadki
                m=minimax(znak,rozmiar_planszy,gracz,ilosc_w_rzedzie,poziom_glebokosci+1);
                znak[i][j]=' ';
                if( ((gracz=='o') && (m<mmx)) || ((gracz=='x') && (m>mmx)) )
                mmx=m;
            }
        }

  return mmx;
}



/*
//  minmax alpha-beta glebokosc (nie dziala !!!)
int minimax(char **znak, char rozmiar_planszy, char gracz, int ilosc_w_rzedzie, int poziom_glebokosci, int alpha, int beta)
{

    if(wygrana(znak,rozmiar_planszy,gracz,true,ilosc_w_rzedzie)==true)
    {
        if(gracz=='x') return 1;   // jezeli wygrana zwracamy jak nie to -1
        else return -1;
    }

    if(remis(znak, rozmiar_planszy,true)==true) return 0;

    if(poziom_glebokosci==3) return 0; // jezeli drzewo doszlo do poziomu glebokosci 3 zakoncz rekurencje (jest po to bo dla duzych tablic liczy baaaaaardzo dlugo)

    if(gracz=='x') gracz='o';         // zamieniamy gracza
    else gracz='x';


    for(int i=1; i<=rozmiar_planszy; i++)
        for(int j=1; j<=rozmiar_planszy; j++)
        {
            if(znak[i][j]==' ')
            {
                if(gracz=='o')
                {
                    znak[i][j]=gracz;              // podstawiamy pod puste pole znak gracza by rozwazyc wszystkie przypadki
                    alpha=max(alpha,minimax(znak,rozmiar_planszy,gracz,ilosc_w_rzedzie,poziom_glebokosci+1,alpha,beta));
                    znak[i][j]=' ';
                    if(alpha>=beta) return alpha;
                }

                if(gracz=='x')
                {
                    znak[i][j]=gracz;              // podstawiamy pod puste pole znak gracza by rozwazyc wszystkie przypadki
                    beta=min(beta,minimax(znak,rozmiar_planszy,gracz,ilosc_w_rzedzie,poziom_glebokosci+1,alpha,beta));
                    znak[i][j]=' ';
                    if(alpha>=beta) return beta;
                }
            }
        }
}
*/
void komputer(char **znak, int rozmiar_planszy, int ilosc_w_rzedzie, int poziom_glebokosci)
{
    int ruch_w,ruch_k,m;
    int mmx=-((rozmiar_planszy*rozmiar_planszy) + 1);
    for(int i=1; i<=rozmiar_planszy; i++)
        for(int j=1; j<=rozmiar_planszy; j++)
        {
            if(znak[i][j]==' ')
            {
                znak[i][j]='x';
                m=minimax(znak,rozmiar_planszy,'x', ilosc_w_rzedzie, poziom_glebokosci+1);
                znak[i][j]=' ';

                if(m>mmx)
                {
                    mmx=m;
                    ruch_w=i;
                    ruch_k=j;
                }
            }
        }

    znak[ruch_w][ruch_k]='x';
    cout<<"rzad - "<<ruch_w<<endl;
    cout<<"kolumna - "<<ruch_k<<endl;

}



