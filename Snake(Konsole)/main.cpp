//#include <QCoreApplication>
#include <stdlib.h>
#include <iostream>
#include "CAbase.h"
#include <conio.h>
using namespace std;

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_Q 113

char* Feld1;
int* Sneake;

int Nx = 10;
int Ny = 10;
int Head = ((Nx*Ny)/2);
int Body = Head + 1;
int Tail = Body + 1;
int Size = 3;

char Schritt;
bool Wand = false;

string Bewegung[4] = {"Unten", "Links", "Rechts", "Oben"};


//  Funktion, welche ein Array kopiert.
void kopie (int Original[], int Kopie[])
{
    for (int i = 0; i < Size + 1; i++)
    {
        Kopie[i] = Original[i];
    }
}


//  Funktion, welche das Spielfeld generiert.
void Feld(int a, int b)
{
    Nx = a;
    Ny = b;
    Feld1 = new char [Nx*Ny];
    for (int i = 0; i < Nx*Ny; i++)
    {
        Feld1[i] = '.';
    }
}

//  Funktion, welche verhindert, das Snake in die entgegengesetzte Richtung zur aktuellen Richtung laufen kann.
void Richtung(string arr[], int Richtung)
{
   for (int i = 0; i < 4; i++)
   {
       if (i == Richtung)
       {
         arr[i] = "True";
       }
       else arr[i] = "False";
   }
}


//  Funktion, welche Snake erstellt.
void Snake()
{
    Sneake = new int [Nx*Ny];
    Sneake[0] = Head;
    for (int i = 1; i < Size; i++)
    {
        Sneake[i] = Body;
        Body++;
    }
    Richtung(Bewegung, 1);
}


//  Funktion, welche die Anzeige in der Konsole ermöglicht.
void printen()
{
    for (int i = 0; i < Nx*Ny; i++)
    {
           if (i % Ny == 0 )
           {
         std::cout << "\n";
           }
        std::cout << Feld1[i] << " ";
    }
    std::cout << "\n \n";
}


//  Funktion, welche Snake zum Leben erweckt..
void leben(int arr[])
{
    for(int k = 0; k < Size; k++)
    {
        Feld1[arr[k]] = '0';
    }
}


//  Funktion, welche anziegt, dass Snake gestorben ist.
void stirb(int arr[])
{
    for(int k = 0; k < Size; k++)
    {
        Feld1[arr[k]] = '*';
    }
}


//  Funktion, welche den Tail der Schlange nach einer Bewegung wieder zu einem Spielfeld ändert.
void tod(int z)
{
    Feld1[z] = '.';
}


//  Funktion, welche den Rand des Spielfeldes erstellt.
void Rand()
{
    if (        ((Sneake[0] % Nx == 0) && (Bewegung[1] == "True"))              // Links
            ||  ((Sneake[0] % Nx == Nx - 1) && (Bewegung[2] == "True"))         // Rechts
            ||  ((Sneake[0] < Nx) && (Bewegung[3] == "True"))                   // Oben
            ||  ((Sneake[0] > ((Nx*Ny)-Nx)) && (Bewegung[0] == "True")))        // Unten
    {
        stirb(Sneake);
        Wand = true;
    }


}


//  Funktion, welche prüft, ob Snake sich selbst trifft.
void Treffer()
{
    if (Schritt == '0')
    {
       stirb(Sneake);
       Feld1[Tail] = '*';
    }
    else
        tod(Tail);
}


//  Funktion, welche die Snake die Bewegung nach links ermöglicht.
 void links(int arr[])
 {
    int* Snakelinks = new int[Size + 1];
    Snakelinks[0] = arr[0] -1;
    int k = 0;
    for (int i = 1; i <= Size; i++)
    {
        Snakelinks[i] = arr[k];
        k++;
    }
    Tail = Snakelinks[Size];
    kopie(Snakelinks, Sneake);
    leben(Sneake);
    Treffer();
 }


 //  Funktion, welche die Snake die Bewegung nach rechts ermöglicht.
 void rechts(int arr[])
 {
     int* Snakerechts = new int[Size + 1];
     Snakerechts[0] = arr[0] +1;
     int k = 0;
     for (int i = 1; i <= Size; i++)
     {
         Snakerechts[i] = arr[k];
         k++;
     }
     Tail = Snakerechts[Size];
     kopie(Snakerechts, Sneake);
     leben(Sneake);
     Treffer();
 }


//  Funktion, welche die Snake die Bewegung nach oben ermöglicht.
 void oben(int arr[])
 {
     int* Snakeoben = new int[Size + 1];
     Snakeoben[0] = arr[0] - Nx;
     int k = 0;
     for (int i = 1; i <= Size; i++)
     {
         Snakeoben[i] = arr[k];
         k++;
     }
     Tail = Snakeoben[Size];
     kopie(Snakeoben, Sneake);
     leben(Sneake);
     Treffer();
 }


 //  Funktion, welche die Snake die Bewegung nach unten ermöglicht.
 void unten(int arr[])
 {
     int* Snakeunten = new int[Size + 1];
     Snakeunten[0] = arr[0] + Nx;
     int k = 0;
     for (int i = 1; i <= Size; i++)
     {
         Snakeunten[i] = arr[k];
         k++;
     }
     Tail = Snakeunten[Size];
     kopie(Snakeunten, Sneake);
     leben(Sneake);
     Treffer();
 }


 //  Funktion, welche eine Nahrung auf ein zufälliges Feld wirft.
 void Futter()
 {
     if (Size == (Nx*Ny)-1)
     {
         stirb(Sneake);
         Feld1[Tail] = '*';
         std::cout << "\n" << "Glückwunsch du hast das optimale Spiel geschafft" << "\n \n";
     }
     int r = rand() % (Nx*Ny);
     if (Feld1[r] != '0')
         Feld1[r] = 'z';
     else Futter();
 }

 //  Funktion, welche Snake bei einer Bewegung nach links das Fressen ermöglicht.
 void fressenLinks (int arr[])
 {
    int* Snakelinks = new int[Size + 1];
    Schritt = Feld1[arr[0] - 1];
    if (Schritt == 'z')
    {
    Snakelinks[0] = arr[0] - 1;
    int k = 0;
    for (int i = 1; i <= Size; i++)
    {
        Snakelinks[i] = arr[k];
        k++;
    }
    Tail = Sneake[Size];
    kopie(Snakelinks, Sneake);
    leben(Sneake);
    Size++;
    Futter();
    }
    else
        links(Sneake);
 }


 //  Funktion, welche Snake bei einer Bewegung nach rechts das Fressen ermöglicht.
 void fressenRechts (int arr[])
 {
    int* Snakerechts = new int[Size + 1];
    Schritt = Feld1[arr[0] + 1];
    if (Schritt == 'z')
    {
    Snakerechts[0] = arr[0] + 1;
    int k = 0;
    for (int i = 1; i <= Size; i++)
    {
        Snakerechts[i] = arr[k];
        k++;
    }
    Tail = Sneake[Size];
    kopie(Snakerechts, Sneake);
    leben(Sneake);
    Size++;
    Futter();
    }
    else
        rechts(Sneake);
 }

 //  Funktion, welche Snake bei einer Bewegung nach oben das Fressen ermöglicht.
 void fressenOben (int arr[])
 {
    int* Snakeoben = new int[Size + 1];
    Schritt = Feld1[arr[0] - Nx];
    if (Schritt == 'z')
    {
    Snakeoben[0] = arr[0] - Nx;
    int k = 0;
    for (int i = 1; i <= Size; i++)
    {
        Snakeoben[i] = arr[k];
        k++;
    }
    Tail = Sneake[Size];
    kopie(Snakeoben, Sneake);
    leben(Sneake);
    Size++;
    Futter();
    }
    else
        oben(Sneake);
 }


 //  Funktion, welche Snake bei einer Bewegung nach unten das Fressen ermöglicht.
 void fressenUnten (int arr[])
 {
    int* Snakeunten = new int[Size + 1];
    Schritt = Feld1[arr[0] + Nx];
    if (Schritt == 'z')
    {
    Snakeunten[0] = arr[0] + Nx;
    int k = 0;
    for (int i = 1; i <= Size; i++)
    {
        Snakeunten[i] = arr[k];
        k++;
    }
    Tail = Sneake[Size];
    kopie(Snakeunten, Sneake);
    leben(Sneake);
    Size++;
    Futter();
    }
    else
        unten(Sneake);
 }





 //  Funktion, welche Das Menue erstellt.
 void menu0()
 {
     std::cout << "Q Exit" << "\n";
     std::cout << "S -> Unten " << "\n";
     std::cout << "A -> Links" << "\n";
     std::cout << "D -> Rechts" << "\n";
     std::cout << "W -> Oben" << "\n";
 }

 //  Funktion, welche Snake vorbereitet.
 void prepareFieldSnake()
 {
     Feld (6 , 6);
     Snake();
     Futter();
     leben(Sneake);
     printen();
 }

int main()
{
    prepareFieldSnake();
    int Eingabe0;
    menu0();
    do
    {
        switch (getch())
        {
        case KEY_Q:
            std::cout << "\n" << "Vielen Dank" << "\n \n";
            break;
        case KEY_DOWN:
            if (Bewegung[3] == "True")
            {
                printen();
                break;
            }
            else
            Richtung(Bewegung, 0);
            Rand();
            if (Wand == true)
            {
                printen();
                break;
            }
            fressenUnten(Sneake);
            printen();
            break;
        case KEY_LEFT:
            if (Bewegung[2] == "True")
            {
                printen();
                break;
            }
            Richtung(Bewegung, 1);
            Rand();
            if (Wand == true)
            {
                printen();
                break;
            }
            fressenLinks(Sneake);
            printen();
            break;
        case KEY_RIGHT:
            if (Bewegung[1] == "True")
            {
                printen();
                break;
            }
            Richtung(Bewegung, 2);
            Rand();
            if (Wand == true)
            {
                printen();
                break;
            }
            fressenRechts(Sneake);
            printen();
            break;
        case KEY_UP:
            if (Bewegung[0] == "True")
            {
                printen();
                break;
            }
            Richtung(Bewegung, 3);
            Rand();
            if (Wand == true)
            {
                printen();
                break;
            }
            fressenOben(Sneake);
            printen();
            break;
        }
    }
    while (Eingabe0 != 0);

    return 0;

}
