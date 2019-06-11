#include "testy.h"
#include "dijkstra.h"


void testy()
  {
    int n; // ilosc wierzcholkow
    double gestosc=1;
    double czas=0;
    double suma_czasu=0;
    double czas_danego_grafu=0;
    clock_t start, stop;



      n=50;
      for(int i=0; i<100; i++)
      {

          start=clock();
          dijkstra_lista_pod_test(n,gestosc);
          stop=clock();
          czas=(double)(stop-start)/CLOCKS_PER_SEC;
          suma_czasu=suma_czasu+czas;
          czas_danego_grafu=czas_danego_grafu+czas;
      }
      std::cout<<"czas dla grafu z "<<n<<" wierzcholkami = "<<czas_danego_grafu<<std::endl;
      czas_danego_grafu=0;

      n=100;
      for(int i=0; i<100; i++)
      {

          start=clock();
          dijkstra_lista_pod_test(n,gestosc);
          stop=clock();
          czas=(double)(stop-start)/CLOCKS_PER_SEC;
          suma_czasu=suma_czasu+czas;
          czas_danego_grafu=czas_danego_grafu+czas;
      }
      std::cout<<"czas dla grafu z "<<n<<" wierzcholkami = "<<czas_danego_grafu<<std::endl;
      czas_danego_grafu=0;

      n=200;
      for(int i=0; i<100; i++)
      {

          start=clock();
          dijkstra_lista_pod_test(n,gestosc);
          stop=clock();
          czas=(double)(stop-start)/CLOCKS_PER_SEC;
          suma_czasu=suma_czasu+czas;
          czas_danego_grafu=czas_danego_grafu+czas;
      }
      std::cout<<"czas dla grafu z "<<n<<" wierzcholkami = "<<czas_danego_grafu<<std::endl;
      czas_danego_grafu=0;

      n=500;
      for(int i=0; i<100; i++)
      {

          start=clock();
          dijkstra_lista_pod_test(n,gestosc);
          stop=clock();
          czas=(double)(stop-start)/CLOCKS_PER_SEC;
          suma_czasu=suma_czasu+czas;
          czas_danego_grafu=czas_danego_grafu+czas;
      }
      std::cout<<"czas dla grafu z "<<n<<" wierzcholkami = "<<czas_danego_grafu<<std::endl;
      czas_danego_grafu=0;

      n=1000;
      for(int i=0; i<100; i++)
      {

          start=clock();
          dijkstra_lista_pod_test(n,gestosc);
          stop=clock();
          czas=(double)(stop-start)/CLOCKS_PER_SEC;
          suma_czasu=suma_czasu+czas;
          czas_danego_grafu=czas_danego_grafu+czas;
      }
      std::cout<<"czas dla grafu z "<<n<<" wierzcholkami = "<<czas_danego_grafu<<std::endl;
      czas_danego_grafu=0;

      std::cout<<"calkowity czas = "<<suma_czasu<<std::endl;


       // for(int i=0; i<1000; i++)
     //  dijkstra_lista(11,1);       /////////// nie zmienia bo za szybko robi sprawdz czy teraz tez
  }
