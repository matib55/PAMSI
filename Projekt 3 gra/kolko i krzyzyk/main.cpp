#include <iostream>
#include <ctime>
#include "plansza.cpp"
#include "ruch.cpp"
#include "komputer.cpp"
#include "wygrana_remis.cpp"
#include "menu.cpp"

int main()
{
    int wybor;
    char gracz='o',n=' ',kto_zaczyna;
    char **znak;
    bool koniec=true;
    int rozmiar_planszy=3;
    int ilosc_w_rzedzie = 3;
    int poziom_glebokosci=0;


menu_wyboru(znak,rozmiar_planszy,gracz, ilosc_w_rzedzie, poziom_glebokosci);

    return 0;
}
