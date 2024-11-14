#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include "FUNCTION.H"
#include "FS.h"
#define fileName "code.txt"
int main()
{
    int choix;
    plivre debut ;
    FILE* pFile = fopen(fileName , "r+t");
    fscanf(pFile , "%p" , &debut);
    fclose(pFile);



    setcolor(9);
    gotoxy(10,5);
    puts("Voici le menu \: ");
    gotoxy(10,6);
    printf("***************************************************");
    gotoxy(10,7);
    printf("*\t1 \. Ajouter un livre                        *");
    gotoxy(10,8);
    printf("***************************************************");
    gotoxy(10,9);
    printf("*\t2 \. Supprimer un livre                      *");
    gotoxy(10,10);
    printf("***************************************************");
    gotoxy(10,11);
    printf("*\t3 \. Modifier les informations d\'un livre    *");
    gotoxy(10,12);
    printf("***************************************************");
    gotoxy(10,13);
    printf("*\t4 \. Enregistrer un utilisateur              *");
    gotoxy(10,14);
    printf("***************************************************");
    gotoxy(10,15);
    printf("*\t5 \. Emprunter un livre                      *");
    gotoxy(10,16);
    printf("***************************************************");
    gotoxy(10,17);
    printf("*\t6 \. Retourner un livre                      *");
    gotoxy(10,18);
    printf("***************************************************");
    gotoxy(10,19);
    printf("*\t7 \. Rechercher un livre                     *");
    gotoxy(10,20);
    printf("***************************************************");
    gotoxy(10,21);
    printf("*\t8 \. Lister les livres disponibles           *");
    gotoxy(10,22);
    printf("***************************************************");
    gotoxy(10,23);
    printf("*\t9 \. Lister les livres empruntes             *");
    gotoxy(10,24);
    printf("***************************************************");
    gotoxy(10,25);
    printf("*\t0 \. Exit                                    *");
    gotoxy(10,26);
    printf("***************************************************");
    gotoxy(0,27);
    getch();

    printf("\nPlease select a valid option (0-9): ");
    scanf("%d", &choix);
    do
    {
    switch(choix)
    {
        case 1 :
            ajouter_livre(&debut);
            break;

        case 2 :
            suprimer_livre(&debut);
            break;
        case 3 : break;
        case 4 : break;
        case 5 : break;
        case 6 : break;
        case 7 : break;
        case 8 : break;
        case 9 : break;
        default :
            puts("\nErreur!!! ");
            break;
    }
    printf("\nPlease select a valid option (0-9): ");
    scanf("%d", &choix);
    }while(choix != 0);
    printf("debut = %p", debut);

    pFile = fopen(fileName , "w+t");
    fprintf(pFile , "%p" , debut);
    fclose(pFile);

    getch();
    return 0;
}
