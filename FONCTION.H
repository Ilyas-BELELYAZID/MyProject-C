#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include <time.h>
#define N 30
#define M 20
#define nomFile "liste_livre.txt"
#define nomFile_1 "liste_livre_1.txt"

FILE* fp = NULL;
FILE* fp_1 = NULL;

char c;
int choix, id, n, m;
long pos = 0.0;


typedef struct{
char nom[20];
char prenom[20];
char CNE[15];
char CIN[15];
char email[28];
char adresse[30];
char password[30];

}user;


typedef struct info_livre
{
    int ID , ans_publication ;
    char titre[N] , auteur[M] , editeur[N] ;
}info_livre;

info_livre *tmp = NULL;


void setBackgroundColor(int bg) {
    // Get the current console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the current attributes (foreground color)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Extract the current foreground color
    int fg = csbi.wAttributes & 0x0F; // Get the foreground color (lower 4 bits)

    // Combine foreground and new background color
    int color = (bg << 4) | fg; // Shift background color and combine with foreground
    SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}




void head(){
    setcolor(9); // Set text color to bleau
    printf("****************************************************************************************************************************************************************************\n");
    gotoxy(65, 2);
    printf("-      WELCOME TO ENSAH LIBRARY    -\n");
    gotoxy(0, 4);
    printf("****************************************************************************************************************************************************************************\n");
    setcolor(7);} // Reset text color to white


void sign_in1(){
    setcolor(9); // Set text color to bleau
    printf("****************************************************************************************************************************************************************************\n");
    gotoxy(70, 2);
    printf("-E S P A C E  D' E L E V E-");
    gotoxy(0, 4);
    printf("****************************************************************************************************************************************************************************\n");

    user u;
    fp = fopen("liste_inscription_eleve.txt","a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }
     setcolor(9); // Set color for the borders
    gotoxy(65, 8);
    printf("************************************\n");

    gotoxy(65, 9);
    printf("-             SIGN IN              -\n");

    gotoxy(65, 10);
    printf("************************************\n");
    gotoxy(55,9);
    printf("----------");
    gotoxy(101,9);
    printf("----------");
    gotoxy(65,20);
    printf("************************************");
    setcolor(7); // Reset color for text input fields
    gotoxy(65,12);
    printf("enter votre nom:\n ");
    gotoxy(65,13);
    printf("enter votre prenom:\n");
    gotoxy(65,14);
    printf("enter votre CIN:\n");
    gotoxy(65,15);
    printf("enter votre massar:\n");
    gotoxy(65,16);
    printf("enter votre email:\n");
    gotoxy(65,17);
    printf("enter adresse :\n");
    gotoxy(65,18);
    printf("enter password :\n");
    gotoxy(81,12);
    scanf("%s",u.nom);
    gotoxy(84,13);
    scanf("%s",u.prenom);
    gotoxy(81,14);
    scanf("%s",u.CIN);
    gotoxy(84,15);
    scanf("%s",u.CNE);
    gotoxy(83,16);
    scanf("%s",u.email);
    gotoxy(81,17);
    getchar();
    fgets(u.adresse,sizeof(u.adresse),stdin);
    u.adresse[strcspn(u.adresse, "\n")] = '\0';
    gotoxy(81,18);
    scanf("%s",u.password);
    fprintf(fp," %-15s|%-20s|%-15s|%-15s|%-28s|%-30s|%-30s\n",u.nom,u.prenom,u.CIN,u.CNE, u.email,u.adresse,u.password);
    fclose(fp);
    gotoxy(70,22);
    setcolor(10);
    printf("YOU REGISTER SUCCESSFULLY!\n");
    setcolor(07);
}


void LOGIN1(){
    int found=0;
    char line[100];
    head();
    fp = fopen("liste_inscription_eleve.txt", "r");
    if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1); // Ensure you handle the error appropriately
}
    char CIN[30];
    char password[30];

    setcolor(9); // Set color for the borders
    gotoxy(65, 8);
    printf("************************************\n");

    gotoxy(65, 9);
    printf("-      LOGIN TO YOUR ACCOUNT       -\n");

    gotoxy(65, 10);
    printf("************************************\n");
    gotoxy(55,9);
    printf("----------");
    gotoxy(101,9);
    printf("----------");
    gotoxy(65,17);
    printf("************************************");
    setcolor(7); // Reset color for text input fields

    // Username prompt
    gotoxy(65, 12);
    printf("CIN: ");


    // Password prompt
    gotoxy(65, 15);
    printf("Password: ");
    gotoxy(75,12);
    scanf("%s",CIN);
    gotoxy(75,15);
    scanf("%s",password);
    while (fgets(line, sizeof(line), fp)) {
        if(strstr(line,CIN)!=NULL && strstr(line,password)!=NULL){
            found=1;
            break;
        }
    }
        if(found==1){
        gotoxy(70,22);
        setcolor(10);
         printf("Login successful!\n");}
        else
            printf("CIN or password incorrect");

            setcolor(07);


    fclose(fp);}



void display_data() {

    char line[100];
    fp = fopen("liste_inscription_eleve.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
           while (fgets(line, sizeof(line), fp)) {
        printf("%s",line);

    }

    fclose(fp);}


void LOGIN2(){
    head();
    fp = fopen("liste d'administration.txt","r");
    char password[30],pass[20];
    int found=0;

    setcolor(9); // Set color for the borders
    gotoxy(65, 8);
    printf("************************************\n");

    gotoxy(65, 9);
    printf("-      LOGIN TO YOUR ACCOUNT       -\n");

    gotoxy(65, 10);
    printf("************************************\n");
    gotoxy(55,9);
    printf("----------");
    gotoxy(101,9);
    printf("----------");
    gotoxy(65,17);
    printf("************************************");
    setcolor(7); // Reset color for text input fields

    // Username prompt
    gotoxy(65, 13);
    printf("Password:");
    scanf("%s",password);
    while(fscanf(fp,"%s",pass)!=NULL){
        if(strcmp(password,pass)==0){
        found=1;
        break;
        }
    }
            if(found==1){
        gotoxy(70,22);
        setcolor(10);
         printf("Login successful!\n");}
        else
            printf("CIN or password incorrect");
            setcolor(07);

    fclose(fp);}



void erreur_page(){
    system("cls");
    system("color F9");
    gotoxy(65, 12);
    printf("********************************************");
    gotoxy(65, 13);
    printf("                                            ");
    gotoxy(62, 14);
    printf("      consulter cette page ulterieurement !!");
    gotoxy(65, 15);
    printf("                                            ");
    gotoxy(65, 16);
    printf("                     MERCI...               ");
    gotoxy(65, 17);
    printf("                                            ");
    gotoxy(65, 18);
    printf("********************************************");
    gotoxy(0,27);
            setcolor(07);
            getch();
                exit(0); // Exit the program
    return 0;
}



void login_sign_in1(){
system("color 9");
printf("\n\n\n\n");
printf("****************************************************************************************************************************************************************************");
printf("                                                                   -E S P A C E   D' E T U D I A N T -\n");
printf("****************************************************************************************************************************************************************************\n\n\n\n");
    int n;
    while(1){
    // Set color for the top border
    setcolor(9); // Blue for the border
    gotoxy(65, 9);
    printf("***************************************\n");

    // Set color for the login option
    setcolor(9);
    gotoxy(65, 10);
    printf("|            ");
    setcolor(7);
    printf("1. Login                 ");
    setcolor(9);
    printf("|\n");

    // Set color for the sign-in option
    setcolor(9);
    gotoxy(65, 12);
    printf("|            ");
    setcolor(7);
    printf("2. Sign In               ");
    setcolor(9);
    printf("|\n");
    // Set color for the exit option
    setcolor(9);
    gotoxy(65, 14);
    printf("|            ");
    setcolor(7);
    printf("3. Exit                  ");
    setcolor(9);
    printf("|\n");
    setcolor(9);
        gotoxy(65, 15);
        printf("***************************************\n");

        setcolor(07);
        gotoxy(57, 18);
        setcolor(9);
        printf("******************************************************\n");
        gotoxy(57, 19);
        printf("|");
        setcolor(7);
        gotoxy(65, 19);
        printf("Please select a valid option (1-3): ");
        setcolor(9);
        gotoxy(110, 19);
        printf("|");
        gotoxy(57, 20);
        printf("******************************************************\n");
        gotoxy(101, 19);
        setcolor(7);
        scanf("%d", &n);
        tarik:
    // Read user input
    switch (n) {
            case 1:
               system("cls"); // Clear the screen
               LOGIN1(); // Call the login function
               return; // Exit the function after successful login
            case 2:
                system("cls");
                sign_in1();
                return ;
            case 3:
                system("cls");
                homepage();

                exit(0); // Exit the program
           default:
                    gotoxy(57, 22);
                    setcolor(9);
                    printf("******************************************************\n");
                    gotoxy(57, 23);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 23);
                    printf("Invalid input.Please select a valid option (1-3): ");
                    setcolor(9);
                    gotoxy(110, 23);
                    printf("|\n");
                    setcolor(9);
                    gotoxy(57, 24);
                    printf("******************************************************\n");
                    gotoxy(109, 23);
                    setcolor(7);
                    scanf("%d",&n);
                    goto tarik;

    }
    }
}



void login_sign_in2(){
system("color 9");
printf("\n\n\n\n");
printf("****************************************************************************************************************************************************************************");
printf("                                                              -E S P A C E   D' A D M I N I S T R A T I O N-\n");
printf("****************************************************************************************************************************************************************************\n\n\n\n");
    int n;
    while(1){
    // Set color for the top border
    setcolor(9); // Blue for Fthe border
    gotoxy(65, 9);
    printf("***************************************\n");

    // Set color for the login option
    setcolor(9);
    gotoxy(65, 11);
    printf("|            ");
    setcolor(7);
    printf("1. Login                 ");
    setcolor(9);
    printf("|\n");

    // Set color for the sign-in option
    setcolor(9);
    gotoxy(65, 13);
    printf("|            ");
    setcolor(7);
    printf("2. Exit                  ");
    setcolor(9);
    printf("|\n");
    setcolor(9);
        gotoxy(65, 15);
        printf("***************************************\n");

        setcolor(07);
        gotoxy(57, 18);
        setcolor(9);
        printf("******************************************************\n");
        gotoxy(57, 19);
        printf("|");
        setcolor(7);
        gotoxy(65, 19);
        printf("Please select a valid option (1-3): ");
        setcolor(9);
        gotoxy(110, 19);
        printf("|");
        gotoxy(57, 20);
        printf("******************************************************\n");

        gotoxy(101, 19);
        setcolor(7);
        scanf("%d", &n);
        tarik:
    // Read user input
    switch (n) {
            case 1:
               system("cls"); // Clear the screen
               LOGIN2(); // Call the login function
               return; // Exit the function after successful login
            case 2:
                system("cls");
                homepage();

                exit(0); // Exit the program
           default:
                    gotoxy(57, 22);
                    setcolor(9);
                    printf("******************************************************\n");
                    gotoxy(57, 23);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 23);
                    printf("Invalid input.Please select a valid option (1-3): ");
                    setcolor(9);
                    gotoxy(110, 23);
                    printf("|\n");
                    setcolor(9);
                    gotoxy(57, 24);
                    printf("******************************************************\n");
                    gotoxy(109, 23);
                    setcolor(7);
                    scanf("%d",&n);
                    goto tarik;

    }
    }
}


void homepage() {
           int n;
system("color 9");
printf("\n\n\n\n");
printf("****************************************************************************************************************************************************************************");
printf("                                                                      *M E N U  P R I N C I P A L*\n");
printf("****************************************************************************************************************************************************************************\n\n\n\n");
gotoxy(18,10);
printf("                              veuillez choisir l'espace que vous voulez souhaiter faire des operations :");

gotoxy(50,15);
printf("1-espace d'etudiants:                          2-espace administration :");
gotoxy(35,19);
printf("                                            3-QUITTER : \n\n\n");
printf("****************************************************************************************************************************************************************************\n");
gotoxy(68,25);
printf("Veuillez entrer votre choix : ");
    setcolor(07);
    scanf("%d", &n);

tarik:
switch (n) {
            case 1:
               system("cls"); // Clear the screen
              login_sign_in1(); // Call the login sign in function
               return; // Exit the function after successful login
            case 2:
               system("cls"); // Clear the screen
              login_sign_in2(); // Call the login sign in function
               return; // Exit the function after successful login
            case 3:
                erreur_page();

                exit(0); // Exit the program
           default:
                    gotoxy(57, 22);
                    setcolor(9);
                    printf("******************************************************\n");
                    gotoxy(57, 23);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 23);
                    printf("Invalid input.Please select a valid option (1-3): ");
                    setcolor(9);
                    gotoxy(110, 23);
                    printf("|\n");
                    setcolor(9);
                    gotoxy(57, 24);
                    printf("******************************************************\n");
                    gotoxy(109, 23);
                    setcolor(7);
                    scanf("%d",&n);
                    goto tarik;

    }
}

//Mes traveaux situent ci-dessous (Ilyas)

void afficher_menu_etu()
{
    setcolor(9);
    gotoxy(10,5);
    puts("------------------ESPACE ETUDIANT------------------");
    gotoxy(10,6);
    printf("*\t1 \. Emprunter un livre                      *");
    gotoxy(10,7);
    printf("***************************************************");
    gotoxy(10,8);
    printf("*\t2 \. Rechercher un livre                     *");
    gotoxy(10,9);
    printf("***************************************************");
    gotoxy(10,10);
    printf("*\t3 \. Lister les livres disponibles           *");
    gotoxy(10,11);
    printf("***************************************************");
    gotoxy(10,12);
    printf("*\t0 \. Exit                                    *");
    gotoxy(10,13);
    puts("---------------------------------------------------");
    gotoxy(0,14);

    printf("\nPlease select a valid option (0-3): ");
    scanf("%d", &choix);
}


void espace_etudiant()
{
    afficher_menu_etu();
    do
    {
    switch(choix)
    {
        case 0 : break;
        case 1 : break;
        case 2 :
            recherche_livre();
            if(pos == -2.0) printf("\nLa liste est vide !!!\n");
            else
            {
                printf("Donner ID de livre : ");
                scanf("%d", &id);
                recherche_livre();
                afficher_fpos();
            }
            getch();
            break;
        case 3 : break;
        default :
            puts("\nErreur!!! ");
            break;
    }
    getch();
    system("cls");

    if(choix) afficher_menu_etu();
    }while(choix != 0);

    getch();
}


void afficher_menu_admini()
{
    setcolor(9);
    gotoxy(10,5);
    puts("---------------ESPACE ADMINISTRATION---------------");
    gotoxy(10,6);
    printf("*\t1 \. Ajouter un livre                        *");
    gotoxy(10,7);
    printf("***************************************************");
    gotoxy(10,8);
    printf("*\t2 \. Supprimer un livre                      *");
    gotoxy(10,9);
    printf("***************************************************");
    gotoxy(10,10);
    printf("*\t3 \. Modifier les informations d\'un livre    *");
    gotoxy(10,11);
    printf("***************************************************");
    gotoxy(10,12);
    printf("*\t4 \. Retourner un livre                      *");
    gotoxy(10,13);
    printf("***************************************************");
    gotoxy(10,14);
    printf("*\t5 \. Statistique                             *");
    gotoxy(10,15);
    printf("***************************************************");
    gotoxy(10,16);
    printf("*\t6 \. Recherche un livre                      *");
    gotoxy(10,17);
    printf("***************************************************");
    gotoxy(10,18);
    printf("*\t7 \. Lister les livres empruntes             *");
    gotoxy(10,19);
    printf("***************************************************");
    gotoxy(10,20);
    printf("*\t0 \. Exit                                    *");
    gotoxy(10,21);
    puts("---------------------------------------------------");
    gotoxy(0,22);

    printf("\nPlease select a valid option (0-7): ");
    scanf("%d", &choix);
}


void espace_administration()
{
    afficher_menu_admini();
    do
    {
    switch(choix)
    {
        case 0 : break;
        case 1 :
            ajouter_livre();
            puts("Merci Pour Votre Visite !!!");
            break;

        case 2 :
            supprimer_livre();
            break;
        case 3 :
            modifier_livre();
            puts("Merci Pour Votre Visite !!!");
            break;
        case 4 : break;
        case 5 : break;
        case 6 :
            recherche_livre();
            if(pos == -2.0) printf("\nLa liste est vide !!!\n");
            else
            {
                printf("Donner ID de livre : ");
                scanf("%d", &id);
                recherche_livre();
                afficher_fpos();
            }
            getch();
            break;
        case 7 : break;
        default :
            puts("\nErreur!!! ");
            break;
    }
    getch();
    system("cls");

    if(choix) afficher_menu_admini();
    }while(choix != 0);

    getch();
}


void afficher_informations(info_livre *b)
{
    printf("ID du livre : %d \n",b->ID);
    printf("Le titre du livre : %s \n",b->titre) ;
    printf("Nom d'acteur du livre : %s \n",b->auteur) ;
    printf("L'ans du publication du livre : %d \n",b->ans_publication) ;
    printf("L'editeur du livre : %s \n",b->editeur) ;
}



void saiser_informations(info_livre **b)
{

    if(!id)
    {
        printf("Entrer id du livre : ") ;
        scanf("%d",&((*b)->ID) );
    }
    printf("Entrer le titre du livre : ") ; scanf("%s",&((*b)->titre)) ;
    printf("Entrer nom d'acteur du livre : ") ; scanf("%s",&((*b)->auteur)) ;
    printf("Entrer l'ans du publication du livre : ") ; scanf("%d",&((*b)->ans_publication)) ;
    printf("Entrer l'editeur du livre : ") ; scanf("%s",&((*b)->editeur)) ;
}



void ajouter_livre()
{
        // ajout des livres :
        fp = fopen(nomFile , "a+t");
        if(fp == NULL) {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
            exit(1);
        }
        puts("Entrer les informations sur livre : \n");
        printf("Entrer id du livre : ") ; scanf("%d",&id);
        recherche_livre();
        if((pos != -1.0) && (pos != -2.0)) printf("\nERREUR!!! VOYEZ ENTRER UN AUTRE ID!!! Cette ID est deja remplie.\n");
        else
        {
            info_livre *debut = (info_livre*)malloc(sizeof(info_livre));
            debut->ID = id;
            saiser_informations(&debut);
            fprintf(fp , "%d \t %s \t %s \t  %s \t  %d\n" , (debut->ID) , (debut->titre) , (debut->auteur) , (debut->editeur) , (debut->ans_publication));
            printf("\nl'enregesretement des informations s'effectue avec succee \n") ;

            n = fclose(fp);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
        }
        printf("Voulez-vous ajouter une autre livre (O/N) ? ");
        fflush(stdin);
        scanf("%c", &c);
        c = toupper(c);

        if(c == 'O') ajouter_livre();
}



void afficher_fpos()
{
    tmp = (info_livre*)malloc(sizeof(info_livre));
    if((pos != -1.0) && (pos != -2.0))
    {
        fp = fopen(nomFile , "r+t");
        if(fp == NULL)
        {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
            exit(1);
        }

        fseek(fp , (int)pos , SEEK_SET);
        fscanf(fp , "%d \t %s \t %s \t  %s \t  %d\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication));
        puts("Les informations du livre sont comme suit : ");
        afficher_informations(tmp);

        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
    }
    else if(pos == -1.0) printf("ce livre n'existe pas !!! \n");
    else printf("\nLa liste est vide !!!\n");

}



void recherche_livre()
{
    tmp = (info_livre*)malloc(sizeof(info_livre));
    fp = fopen(nomFile , "r+t");
    if(fp == NULL) {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
        exit(1);
    }
    n = 0;
    while(!feof(fp))
    {
        n++;
        m = fscanf(fp , "%d \t %s \t %s \t  %s \t  %d\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication));
        if(id == tmp->ID) break;
    }
    if(id == tmp->ID)
    {
        pos = ftell(fp);
        pos -= pos / n;
    }
    else if((m == -1) && (n == 1)) pos = -2.0;
    else pos = -1.0;

    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

}



void supprimer_livre()
{
    recherche_livre();
    if(pos == -2.0) printf("\nLa liste est vide !!!\n");
    else
    {
        printf("Donner ID de livre que vous souhaitez supprimer : ");
        scanf("%d", &id);
        recherche_livre();
        if(pos != -1.0)
        {
            n = 1 ;
            fp = fopen(nomFile , "rt");
            fp_1 = fopen(nomFile_1 , "wt");
            if(fp == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                exit(1);
            }
            if(fp_1 == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
                exit(1);
            }

            tmp = (info_livre*)malloc(sizeof(info_livre));

            while(!feof(fp))
            {
                fscanf(fp , "%d \t %s \t %s \t  %s \t  %d\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication));
                if(id != tmp->ID) fprintf(fp_1 , "%d \t %s \t %s \t  %s \t  %d\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication));
            }

            n = fclose(fp);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

            n = fclose(fp_1);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_1);

            remove(nomFile);
            n = rename(nomFile_1 , nomFile);
            if(!n) printf("\nla suppression des informations de livre de ID = %d s'effectue avec succee \n", id) ;
            else printf("\nla suppression des informations de livre de ID = %d s'effectue avec echoue \n", id) ;
        }
        else printf("ce livre n'existe pas !!! \n");
        printf("\nVoulez-vous supprimer une autre livre (O/N) ? ");
        fflush(stdin);
        scanf("%c", &c);
        c = toupper(c);

        if(c == 'O') supprimer_livre();
    }
}



void modifier_livre()
{
    recherche_livre();
    if(pos == -2.0) printf("\nLa liste est vide !!!\n");
    else
    {
        printf("Donner ID de livre que vous souhaitez modifier ses informations : ");
        scanf("%d", &id);
        recherche_livre();
        if(pos != -1.0)
        {
            n = 1 ;
            fp = fopen(nomFile , "rt");
            fp_1 = fopen(nomFile_1 , "wt");
            if(fp == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                exit(1);
            }
            if(fp_1 == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
                exit(1);
            }

            tmp = (info_livre*)malloc(sizeof(info_livre));
            while(!feof(fp))
            {
                fscanf(fp , "%d \t %s \t %s \t  %s \t  %d\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication));
                if(id != tmp->ID) fprintf(fp_1 , "%d \t %s \t %s \t  %s \t  %d\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication));
                else
                {
                    puts("les anciennes informations de ce livre sont comme suit : \n");
                    afficher_informations(tmp);
                }
            }
            puts("Donner les nouveaux informations de ce livre : \n");
            saiser_informations(&tmp);
            fprintf(fp_1 , "%d \t %s \t %s \t  %s \t  %d\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication));

            n = fclose(fp);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

            n = fclose(fp_1);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_1);

            remove(nomFile);
            n = rename(nomFile_1 , nomFile);
            if(!n) printf("\nla modification des informations de livre de ID = %d s'effectue avec succee \n", id) ;
            else printf("\nla modification des informations de livre de ID = %d s'effectue avec echoue \n", id) ;
        }
        else printf("ce livre n'existe pas !!! \n");
        printf("\nVoulez-vous modifier une autre livre (O/N) ? ");
        fflush(stdin);
        scanf("%c", &c);
        c = toupper(c);

        if(c == 'O') modifier_livre();
    }
}



#endif // FUNCTION_H_INCLUDED

