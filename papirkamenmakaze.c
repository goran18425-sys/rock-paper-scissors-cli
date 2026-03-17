#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int uzmiIzborBot();
int uzmiIzborIgrac();
void proveriPobednika(int izborIgraca, int izborBot);

int dobijene = 0;
int odigranePartije = 0;


int main()
{


    srand(time(NULL));

    int igraTraje = 1;
    double stopaDobitka = 0;

    printf("PAPIR, KAMEN, MAKAZE\n");
    printf("PRAVILA IGRE:\n");
    printf("1 - PAPIR\n2 - KAMEN\n3 - MAKAZE\n0 - PREKID IGRE");

    do
    {
        int izborIgrac = uzmiIzborIgrac();
        if(izborIgrac == 0)
        {
            igraTraje = 0;
            break;
        }
        int IzborBot = uzmiIzborBot();
        
        switch (izborIgrac)
        {
        case 1:
            printf("Izabrao si papir\n");
            break;

        case 2:
            printf("Izabrao si kamen\n");
            break;
        
        case 3:
            printf("Izabrao si makaze\n");
            break;
        
        case 67:
            igraTraje = 0;
            break;

        }

        switch (IzborBot)
        {
        case 1:
            printf("Bot je izabrao papir\n");
            break;

        case 2:
            printf("Bot je izabrao kamen\n");
            break;
        
        case 3:
            printf("Bot je izabrao makaze\n");
            break;
        
        default:
            break;
        }

        proveriPobednika(izborIgrac, IzborBot);
    } while (igraTraje);

    
    printf("\nIGRA JE ZAVRSENA!\n");
    printf("Broj odigranih partija: %d\nBroj dobijenih: %d\n", odigranePartije, dobijene);
    stopaDobitka = (double)dobijene / odigranePartije * 100;
    printf("Procenat pobedjenih igara naspram odigranih: %.2lf%%\n", stopaDobitka);
    return 0;
}

int uzmiIzborBot()
{
    return (rand() % 3) + 1;
}

int uzmiIzborIgrac()
{   
    int izbor = 0;
    do
    {
        printf("\nUnesi svoj izbor: ");
        scanf("%d", &izbor);


    } while (izbor < 0 || izbor > 3);
    
    return izbor;
}

void proveriPobednika(int izborIgraca, int izborBot)
{
    if(izborIgraca == izborBot)
    {
        printf("Izjednaceno je!\n");
    } 

    else if(izborIgraca == 1 && izborBot == 2)
    {
        printf("POBEDIO SI!\n");
        dobijene++;
    }

    else if(izborIgraca == 2 && izborBot == 3)
    {
        printf("POBEDIO SI!\n");
        dobijene++;

    }

    else if(izborIgraca == 3 && izborBot == 1)
    {
        printf("POBEDIO SI!\n");
        dobijene++;

    }

    else
    {
        printf("izgubio si...\n");

    }

    odigranePartije++;
}