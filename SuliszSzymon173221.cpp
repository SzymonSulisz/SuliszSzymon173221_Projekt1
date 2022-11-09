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
void sortowanie_malejaco(int M[], int n)
{
    for( int j = 0 ; j < n ; j++)
    {
        for( int k = 1 ; k < n ; k++)
        {
            if( M[k-1] < M[k] )
            {
                swap( M[k-1], M[k]);
            }
        }
    }
    int i = 0;
    cout << "Tablica posortowana malejaco wyglada nastepujaco: " << endl;
    while( i < n )
    {
        cout << M[i] << " ";
        i++;
    }
}
void sortowanie_rosnaco(int R[], int n)
{
    for( int j = 0 ; j < n ; j++)
    {
        for( int k = 1 ; k < n ; k++)
        {
            if( R[k-1] > R[k] )
            {
                swap( R[k-1], R[k]);
            }
        }
    }
    int i = 0;
    cout << "Tablica posortowana rosnaco wyglada nastepujaco: " << endl;
    while( i < n )
    {
        cout << R[i] << " ";
        i++;
    }
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
    sortowanie_malejaco(Z, n);
    cout << endl;
    sortowanie_rosnaco(Z, n);
    return 0;
}