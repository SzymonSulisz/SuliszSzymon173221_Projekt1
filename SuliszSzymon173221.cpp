#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int n, dol, gora;

int rozmiar_tablicy()
{
    cout << "Podaj rozmiar tablicy: ";
    cin >> n;
    return n;
}
int zakres_dol()
{
    cout << "Podaj dolny zakres losowanych liczb: ";
    cin >> dol;
    return dol;
}
int zakres_gora()
{
    cout << "Podaj gorny zakres losowania liczb: ";
    cin >> gora;
    return gora;
}
int losowanie_liczb(int Z[])
{
    srand(time(NULL));
    cout << "Wylosowane dla ciebie liczby to: " << endl;
    for ( int i = 0 ; i < n ; i++)
    {
        Z[i] = rand() % (gora - dol + 1) + dol;
        cout << Z[i] << " ";
    }
    cout << endl;
    return Z[n];
}
int main()
{
    rozmiar_tablicy();
    zakres_dol();
    zakres_gora();
    if( dol >= gora)
    {
        cout << "Podales zle zakresy" << endl;
        zakres_dol();
        zakres_gora();
    }
    cout << "Rozmiar twojej tablicy wynosi " << n << " dolny zakres wynosi " << dol << " a gorny " << gora << endl;
    int Z[n];
    losowanie_liczb(Z);
    return 0;
}