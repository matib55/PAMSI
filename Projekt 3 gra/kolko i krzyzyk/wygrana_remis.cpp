#include "wygrana_remis.hh"

bool remis(char **znak, int rozmiar_planszy, bool cisza)
{
    for(int i=1; i<=rozmiar_planszy; i++)
        for(int j=1; j<=rozmiar_planszy; j++)
            if(znak[i][j]==' ') return false;

    if(cisza!=true)  // stworzone po to by algorytm minimaxi nie zwariowal wypisujac w nieskonczonosc przewidziane ruchy
    {
        rysuj_plansze(znak,rozmiar_planszy);
        cout<<endl;
        cout<<"remis"<<endl;
    }
    return true;
}

bool wygrana(char **znak, int rozmiar_planszy, char gracz, bool cisza, int ilosc_w_rzedzie) // ilosc_rzedzie - gracz wybiera ile znakow w rzedzie kolumnie lub na skos daje wygrana
{
    int pom,test1,test2,test3=0,test4=0, test5=0, test6=0;;

    // wygrana w poziomie
    for(int i=1; i<=rozmiar_planszy; i++)  //jezeli n=rozmiar_planszy takich samych znaków w rzedzie to wygrana
    {
        test1=0;
        for(int j=1; j<=rozmiar_planszy; j++)
        {
            if(znak[i][j]==gracz) test1++;
            else if(test1<ilosc_w_rzedzie)test1=0;
         }
            if(test1>=ilosc_w_rzedzie)
                break;
    }
    // wygrana w pionie
    for(int j=1; j<=rozmiar_planszy; j++)     // jezeli n=rozmiar_planszy takich samych znaków w kolumnie to wygrana
    {
        test2=0;
        for(int i=1; i<=rozmiar_planszy; i++)
        {
            if(znak[i][j]==gracz) test2++;
            else if(test2<ilosc_w_rzedzie) test2=0;

        }
        if(test2>=ilosc_w_rzedzie)
                break;
    }

/*
    for(int i=1; i<=rozmiar_planszy; i++)// jezeli n=rozmiar_planszy takich samych znakow na skos w jedna strone to wygrana
    {
            if(znak[i][i]==gracz) test3++;
            if(test3==ilosc_w_rzedzie)
                break;
    }
    for(int i=1; i<=rozmiar_planszy; i++) // jezeli n=rozmiar_planszy takich samych znakow na skos w druga strone to wygrana
    {
        if(znak[i][rozmiar_planszy+1-i]==gracz) test4++;
        if(test4==ilosc_w_rzedzie)
            break;
    }

   */

    //wygrana na skos w lewo
    pom=rozmiar_planszy-ilosc_w_rzedzie;
    for(int k=0; k<=pom; k++)
    {
      test3=0;
      test4=0;

        for(int i=1; i<=rozmiar_planszy-k; i++)// jezeli n=rozmiar_planszy takich samych znakow na skos w jedna strone to wygrana
        {
            if(znak[i][i+k] == gracz) test3++;
            else if(test3<ilosc_w_rzedzie) test3=0;
            if(znak[i+k][i]==gracz) test4++;
            else if(test4<ilosc_w_rzedzie) test4=0;
        }
        if(test3>=ilosc_w_rzedzie)break;
        if(test4>=ilosc_w_rzedzie)break;

    }



    //wygrana na skos w prawo

    pom=rozmiar_planszy-ilosc_w_rzedzie;
    for(int k=0; k<=pom; k++)
    {
        test5=0;
        test6=0;

        for(int i=1; i<=rozmiar_planszy-k; i++) // jezeli n=rozmiar_planszy takich samych znakow na skos w druga strone to wygrana
        {
            if(znak[i][rozmiar_planszy+1-i-k] == gracz) test5++;
            else if(test5<ilosc_w_rzedzie) test5=0;
            if(znak[i+k][rozmiar_planszy+1-i] == gracz) test6++;
            else if(test6<ilosc_w_rzedzie) test6=0;
        }
        if(test5>=ilosc_w_rzedzie) break;
        if(test6>=ilosc_w_rzedzie) break;
    }




    if((test1>=ilosc_w_rzedzie)||(test2>=ilosc_w_rzedzie)||(test3>=ilosc_w_rzedzie)||(test4>=ilosc_w_rzedzie)||(test5>=ilosc_w_rzedzie)||(test6>=ilosc_w_rzedzie))   //  jezeli ilosc znakow jest ustawionych w pozycji wygranej jest rowna rozmiarowi planszy to wygrana
    {
        if(cisza!=true) // stworzone po to by algorytm minimaxi nie zwariowal wypisujac w nieskonczonosc przewidziane ruchy
        {
            rysuj_plansze(znak,rozmiar_planszy);
            cout<<"wygrywa gracz: "<<gracz<<endl;
        }
        return true;
    }
    return false;
}
