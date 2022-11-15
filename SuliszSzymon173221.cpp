#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int n, dol, gora; // zmienne do rozmiaru i zakresu tablicy
fstream plik; // zmienna plikowa

int zakres_gora() // funkcja podajaca gorny zakres
{
    cout << "Podaj gorny zakres losowania liczb: ";
    cin >> gora;
    return gora;
}
int zakres_dol() // funkcja podajaca dolny zakres
{
    cout << "Podaj dolny zakres losowanych liczb: ";
    cin >> dol;
    return dol;
}
int rozmiar_tablicy() // funkcja podajaca rozmiar tablicy i sprawdzajaca jej poprawnosc
{
    cout << "Podaj rozmiar tablicy: ";
    int a = 1;
    cin >> n;
    while( a == 1 )
    {
        
        if( n < 0 )
        {
            cout << "Podales zly rozmiar tablicy. Podaj go jeszcze raz: ";
            cin >> n;
        } else a = 0;
    } // instrukcja warunkowa sprawdzajaca poprawnosc rozmiaru tablicy
    return n;
}
void sprawdzenie() // funkcja sprawdzajaca czy sa dobre zakresy
{
    int a = 1;
    while( a == 1)
    {
        if( dol >= gora)
        {
            cout << "Podales zle zakresy" << endl;
            zakres_dol();
            zakres_gora();
        }else a = 0; // instrukcja warunkowa sprawdzajaca poprawnosc zakresow i ich ewentualna korekta
    }
}
void zapis(int Z[]) // funkcja zapisujaca dane do pliku dane.txt
{
    plik.open("Dane.txt", ios::out | ios::app);
    if(plik.good() == true ) // instrukcja sprawdzajaca poprawnosc otwarcia pliku
    {
        for( int i = 0 ; i < n ; i++)
        {
            plik << Z[i] << " ";
        }
        plik << endl;
        plik.close();
    }else cout << "Nie udalo sie otworzyc pliku";
}
int losowanie_liczb(int Z[]) // funkcja losujaca dane do tabeli
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
int sortowanie_malejaco(int M[]) // funkcja zawierajaca algorytm sortowania bombelkowego majaca na celu posortowac dane malejaco z tablicy
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
    return M[n];
}
int sortowanie_rosnaco(int R[]) // funkcja zawierajaca algorytm sortowania bombelkowego majaca na celu posortowac dane rosnaco z tablicy
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
    return R[n];
}
int main()
{
    clock_t start = clock(); // zmienna pobierajaca czas rozpoczecia dzialania programu
    rozmiar_tablicy();
    zakres_dol();
    zakres_gora();
    sprawdzenie();
    cout << "Rozmiar twojej tablicy wynosi " << n << " dolny zakres wynosi " << dol << " a gorny " << gora << endl;
    int Z[n]; // deklaracja tablicy o rozmiarze n podanym za pomoca funkcji rozmiar_tablicy()
    losowanie_liczb(Z);
    zapis(Z);
    sortowanie_malejaco(Z);
    zapis(Z);
    cout << endl;
    sortowanie_rosnaco(Z);
    zapis(Z);
    clock_t end = clock(); //zmienna pobierajaca czas zakonczenia dzialania programu
    double x = end - start;
    double czas = x / CLOCKS_PER_SEC; // obliczenie czasu dzialania programu
    cout << endl << "Czas trwania programu wynosi " << czas;
    plik.open("Czasy.txt", ios::out | ios::app); // zapis danych o dlugosci trwania programu do pliku czasy.txt
    if( plik.good() == true ) // funkcja sprawdzajaco poprawnosc otwarcia pliku
    {
        plik << czas << endl;
        plik.close();
    }else cout << "Nie udalo sie otworzyc pliku";
    return 0;
}