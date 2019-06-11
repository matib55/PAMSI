#include "ruch.hh"
#include "komputer.hh"

void ruch_gracz_vs_gracz(char **znak, int rozmiar_planszy, char &gracz)
{
    int w,k;

    cout<<endl;
    rysuj_plansze(znak,rozmiar_planszy);
    cout<<endl;
    cout<<"Ruch gracza: "<<gracz<<" | Twoj ruch to (wybierz rząd i kolumne):"<<endl;
    cout<<"rzad - ";
    while(!(cin>>w)|| !((w>=1) && (w<=rozmiar_planszy)) ) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
    {
        cin.clear(); //kasowanie flagi błędu strumienia
        cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
        cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
        cout<<"rzad - ";

    }

    cout<<"kolumna - ";
    while(!(cin>>k)||!((k>=1) && (k<=rozmiar_planszy))) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
    {
        cin.clear(); //kasowanie flagi błędu strumienia
        cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
        cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
        cout<<"kolumna - ";
    }

    while(znak[w][k]!=' ')                                       // sprawdzamy czy pole jest napewno puste
    {
        cout<<"Te pole jest juz zajete, wybierz inne"<<endl;
        cout<<"rzad - ";
            while(!(cin>>w)|| !((w>=1) && (w<=rozmiar_planszy)) ) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
        {
            cin.clear(); //kasowanie flagi błędu strumienia
            cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
            cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
            cout<<"rzad - ";

        }
        cout<<"kolumna - ";
        while(!(cin>>k)||!((k>=1) && (k<=rozmiar_planszy))) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
        {
            cin.clear(); //kasowanie flagi błędu strumienia
            cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
            cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
            cout<<"kolumna - ";
        }
    }

    znak[w][k]=gracz;

    if(gracz=='x')
        gracz='o';
    else
        gracz='x';

}

void ruch_gracz_vs_komputer(char **znak, int rozmiar_planszy, char &gracz, int ilosc_w_rzedzie, int poziom_glebokosci)
{
    int w,k;

    if(gracz=='o')
    {
        cout<<endl<<endl;
        rysuj_plansze(znak,rozmiar_planszy);
        cout<<endl;
         cout<<"Ruch gracza: "<<gracz<<" | Twoj ruch to (wybierz rząd i kolumne):"<<endl;
        cout<<"rzad - ";
        while(!(cin>>w)|| !((w>=1) && (w<=rozmiar_planszy)) ) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
        {
            cin.clear(); //kasowanie flagi błędu strumienia
            cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
            cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
            cout<<"rzad - ";
        }

        cout<<"kolumna - ";
        while(!(cin>>k)||!((k>=1) && (k<=rozmiar_planszy))) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
        {
            cin.clear(); //kasowanie flagi błędu strumienia
            cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
            cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
            cout<<"kolumna - ";
        }
        while(znak[w][k]!=' ')                                       // sprawdzamy czy pole jest puste
        {
            cout<<"To pole jest juz zajete, wybierz inne"<<endl;
            cout<<"rzad - ";
             while(!(cin>>w)|| !((w>=1) && (w<=rozmiar_planszy)) ) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
            {
                cin.clear(); //kasowanie flagi błędu strumienia
                cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
                cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
                cout<<"rzad - ";
            }
            cout<<"kolumna - ";
             while(!(cin>>k)||!((k>=1) && (k<=rozmiar_planszy))) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane oraz sprawdzamy czy gracz wybiera rzad i kolumne z zakresu planszy
            {
                cin.clear(); //kasowanie flagi błędu strumienia
                cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
                cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
                cout<<"kolumna - ";
            }
        }
        znak[w][k]=gracz;
    }

    else
    {
        cout<<endl<<endl;
        rysuj_plansze(znak,rozmiar_planszy);
        cout<<endl;
        cout<<"Ruch komputera : "<<gracz<<" | Ruch komputera to:"<<endl;
        komputer(znak,rozmiar_planszy,ilosc_w_rzedzie, poziom_glebokosci);

    }

    if(gracz=='o')
        gracz='x';
        else gracz='o';

}
