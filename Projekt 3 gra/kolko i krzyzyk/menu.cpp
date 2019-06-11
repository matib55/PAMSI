#include "menu.hh"

void menu_wyboru(char **znak, int rozmiar_planszy, char gracz, int ilosc_w_rzedzie, int poziom_glebokosci)
{
    int wybor;
    char n, kto_zaczyna;

 while(wybor!=3)
    {
    int koniec=true;

    cout<<"===================================="<<endl;
    cout<<"||  Witaj w grze kolko i krzyzyk  ||"<<endl;
    cout<<"===================================="<<endl;
    cout<<endl;
    cout<<"Wybierz opcje gry:"<<endl;
    cout<<"1. gracz vs gracz            "<<endl;
    cout<<"2. gracz vs komputer         "<<endl;
    cout<<"3. Wyjscie z gry             "<<endl;
    cout<<endl;
    cout<<"Twoj wybor to:";


    while(!(cin>>wybor)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
    {
        cin.clear(); //kasowanie flagi błędu strumienia
        cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
        cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
        cout<<"Twoj wybor to:";
    }


        switch(wybor)
        {
            case 1:
                cout<<endl;
                cout<<"Wybrales/Wybralas gracz vs gracz"<<endl;
                cout<<"Podaj rozmiar planszy"<<endl;
                cout<<"Rozmiar planszy :";
                while(!(cin>>rozmiar_planszy)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
                {
                    cin.clear(); //kasowanie flagi błędu strumienia
                    cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
                    cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
                    cout<<"Rozmiar planszy :";
                }
                cout<<endl;
                cout<<"Podaj ilosc znakow w rzedzie,kolumnie lub na skos do wygrania"<<endl;
                cout<<"Ilosc znakow :";
                while(!(cin>>ilosc_w_rzedzie)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
                {
                    cin.clear(); //kasowanie flagi błędu strumienia
                    cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
                    cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
                    cout<<"Ilosc znakow :";
                }

                cout<<endl;

                 znak=new char*[rozmiar_planszy+1];
                for(int i=0; i<rozmiar_planszy+1;i++)
                    znak[i]=new char[rozmiar_planszy+1];

                while(koniec==true)
                {
                    for(int i=0; i<rozmiar_planszy+1; i++) // zerowanie planszy
                    for(int j=0;j<rozmiar_planszy+1;j++)
                        znak[i][j]=' ';

                    gracz='o';

                    while(!remis(znak,rozmiar_planszy,false)&&!wygrana(znak,rozmiar_planszy,'x',false, ilosc_w_rzedzie)&&!wygrana(znak,rozmiar_planszy,'o',false, ilosc_w_rzedzie))
                    {
                        ruch_gracz_vs_gracz(znak,rozmiar_planszy,gracz);
                    }

                    cout<<"Jeszcze raz ? (T=TAK)(N=NIE)"<<endl;
                    cin>>n;
                    if( (n=='n') || (n=='N'))
                        koniec=false;
                }
                break;

            case 2:
                cout<<endl;
                cout<<"Wybrales/Wybralas gracz vs komputer- powodzenia :D"<<endl;
                cout<<"Podaj rozmiar planszy"<<endl;
                cout<<"Rozmiar planszy :";
                while(!(cin>>rozmiar_planszy)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
                {
                    cin.clear(); //kasowanie flagi błędu strumienia
                    cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
                    cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
                    cout<<"Rozmiar planszy :";
                }
                cout<<endl;
                cout<<"Podaj ilosc znakow w rzedzie,kolumnie lub na skos do wygrania"<<endl;
                cout<<"Ilosc znakow :";
                while(!(cin>>ilosc_w_rzedzie)) //dopóki strumień jest w stanie błędu -> dopóki podawane są błędne dane
                {
                    cin.clear(); //kasowanie flagi błędu strumienia
                    cin.ignore( 1000, '\n' ); //kasowanie zbędnych znaków z bufora
                    cout<<"Wproadziles/Wprowadzilas zly znak, podaj liczbe"<<endl;
                    cout<<"Ilosc znakow :";
                }
                cout<<endl;

                znak=new char*[rozmiar_planszy+1];
                for(int i=0; i<rozmiar_planszy+1;i++)
                    znak[i]=new char[rozmiar_planszy+1];

                while(koniec==true)
                {
                    for(int i=0; i<rozmiar_planszy+1; i++) // zerowanie planszy
                    for(int j=0;j<rozmiar_planszy+1;j++)
                        znak[i][j]=' ';

                    cout<<"Wybierz kto zaczyna k-komputer,c-czlowiek: ";cin>>kto_zaczyna;
                    if(kto_zaczyna=='k')  // jezeli komputer zaczyna to wybiera losowe pole
                    {
                        gracz='x';
                        srand( time( NULL ) );
                        int x=(rand()%rozmiar_planszy)+1;
                        int y=(rand()%rozmiar_planszy)+1;

                        znak[x][y]='x';
                        gracz='o';
                    }
                    else
                        gracz='o';

                    cout<<endl<<endl;

                    while(!remis(znak,rozmiar_planszy,false)&&!wygrana(znak,rozmiar_planszy,'x',false, ilosc_w_rzedzie)&&!wygrana(znak,rozmiar_planszy,'o',false, ilosc_w_rzedzie))
                    {
                        ruch_gracz_vs_komputer(znak,rozmiar_planszy,gracz, ilosc_w_rzedzie, poziom_glebokosci);
                    }

                    cout<<"Jeszcze raz ? (T=TAK)(N=NIE)"<<endl;
                    cin>>n;
                    if( (n=='n') || (n=='N'))
                        koniec=false;
                }
            break;

            case 3:
            break;

            default:
            cout<<"Naciśij odpowiedni przycisk wyboru"<<endl;
            cout<<endl<<endl;
        }

    }
}
