#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include <time.h>
#define L 256
#define N 40
#define M 20
#define K 15
#define nomFile "liste_livre.dat"
#define nomFile_1 "liste_livre_1.dat"
#define nomFile_2 "liste_inscription_eleve.dat"
#define nomFile_3 "liste_d'administration.bin"
#define nomFile_4 "liste_emprunter.txt"


FILE* fp = NULL;
FILE* fp_1 = NULL;


char c, pass[N], line[L];
int choix, id, n, m;
long pos = 0.0 ;


typedef struct user
{
    char nom[M], prenom[M], CNE[K], CIN[K], email[N], adresse[N], password[N];
}user;

user u;
user *u1 = NULL;

typedef struct info_livre
{
    float prix_jour, prix_semaine ;
    int ID , ans_publication , qte ;
    char titre[N] , auteur[M] , editeur[N] ;
}info_livre;

info_livre *tmp = NULL;

typedef struct info_livre_emprunter
{
    info_livre *livre;
    char CNE[K], CIN[K], date_debut[K], date_fin[K] ;
}info_livre_emprunter;

info_livre_emprunter *temporaire = NULL;

int isTextOnly(char* str)
{
    if(*str == '\0') return 1;
    else if(!isalpha(*str) && !isspace(*str)) return 0;
    return isTextOnly(str + 1);
}


int isTextPrint(char* str)
{
    if(*str == '\0') return 1;
    else if(!isprint(*str)) return 0;
    return isTextPrint(str + 1);
}


void convertirEnMajuscules(char *chaine)
{
    if(*chaine == '\0') return;
    *chaine = toupper(*chaine);
    return convertirEnMajuscules(chaine + 1);
}


void masquer_mot_de_passe(char *password)
{
    n = 0;
    while ((c = getch()) != '\r')
    {
        if (c == '\b')
        {
            if (n > 0)
            {
                n--;
                printf("\b \b");
            }
        }
        else if (c != '\t' && c != '\n')
        {
            if (n < N - 1)
            {
                password[n] = c;
                n++;
                printf("*");
            }
        }
    }
    password[n] = '\0';
    printf("\n");
}


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


void head_ensah()
{
    setcolor(9); // Set text color to bleau
    printf("****************************************************************************************************************************************************************************");
    gotoxy(65, 2);
    printf("-\tBIENVENUE A LA BIBLIOTHEQUE DE L'ENSAH\t-\n\n");
    printf("****************************************************************************************************************************************************************************\n");
    setcolor(7);
} // Reset text color to white


void head()
{
    setcolor(9); // Set text color to bleau
    printf("████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████");
    gotoxy(50, 3);
    printf("-LA BIBLIOTHEQUE DE L'ECOLE NATIONALE DES SCIENCES APPLIQUEES AL HOCEIMA-\n\n");
    gotoxy(0,6);
    printf("████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████\n");
    setcolor(7);
} // Reset text color to white


void sign_in1()
{
    fp = fopen(nomFile_2,"at");
    if (fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_2);
        exit(0);
    }
erreur_nom:
    setcolor(9); // Set text color to bleau
    printf("****************************************************************************************************************************************************************************");
    gotoxy(70, 3);
    printf("-E S P A C E  D' E L E V E-\n\n");
    printf("****************************************************************************************************************************************************************************\n");
    setcolor(9); // Set color for the borders
    gotoxy(65, 8);
    printf("**********************************************");
    gotoxy(65, 10);
    printf("-\t\tSE CONNECTER\t\t-");
    gotoxy(65, 11);
    printf("**********************************************");
    gotoxy(55,10);
    printf("----------");
    gotoxy(101,10);
    printf("----------");
    gotoxy(65,21);
    printf("**********************************************");
    setcolor(7); // Reset color for text input fields
    gotoxy(65,13);
    printf("Enter votre nom:\n");
    gotoxy(65,14);
    printf("Enter votre prenom:\n");
    gotoxy(65,15);
    printf("Enter votre CIN:\n");
    gotoxy(65,16);
    printf("Enter votre CNE:\n");
    gotoxy(65,17);
    printf("Enter votre e-mail:\n");
    gotoxy(65,18);
    printf("Enter adresse :\n");
    gotoxy(65,19);
    printf("Enter votre mot de passe :\n");
    gotoxy(81,13);
    fflush(stdin);
    scanf("%[^\n]",u.nom);
    if(!isTextOnly(u.nom))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE et ESPACE\nVoyez saisir un NOM valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(84,14);
    fflush(stdin);
    scanf("%[^\n]",u.prenom);
    if(!isTextOnly(u.prenom))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE et ESPACE\nVoyez saisir un PRENOM valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(81,15);
    fflush(stdin);
    scanf("%s",u.CIN);
    if(!isTextPrint(u.CIN))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir une CIN valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(81,16);
    fflush(stdin);
    scanf("%s",u.CNE);
    if(!isTextPrint(u.CNE))
    {
        gotoxy(60,23);
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir une CNE valide");
        Sleep(2000);
        system("cls");
        goto erreur_nom;
    }
    gotoxy(84,17);
    fflush(stdin); scanf("%s",u.email);
    gotoxy(81,18);
    fflush(stdin); scanf("%[^\n]",u.adresse); //fgets(u.adresse,sizeof(u.adresse),stdin);
    u.adresse[strcspn(u.adresse, "\n")] = '\0'; //A questionner ??
    gotoxy(91,19);
    fflush(stdin); scanf("%s",u.password);
    fprintf(fp,"%s|%s|%s|%s|%s|%s|%s\n",u.nom,u.prenom,u.CIN,u.CNE, u.email,u.adresse,u.password);
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_2);
    gotoxy(70,23);
    setcolor(10);
    printf("VOUS ETES INSCRIT AVEC SUCCES!\n");
    setcolor(9);
    gotoxy(65,26);
    printf("Voulez-vous aller à la page de connexion ? (O/N) : ");
    setcolor(7);
erreur_alpha5:
    fflush(stdin);
    scanf(" %c", &c);
    if(toupper(c) != 'O' && toupper(c) != 'N')
    {
        gotoxy(65,27);
        printf("Voyez saisir une choix correcte (O/N) : ");
        goto erreur_alpha5;
    }
    else if(toupper(c) == 'O')
    {
        printf("\nRedirection vers la page de connexion...\n");
        Sleep(3000);
        system("cls");
        LOGIN1();
    }
    else erreur_page();
}


void LOGIN1()
{
    char email[N];
    fp = fopen(nomFile_2, "rt");
    if (fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_2);
        exit(1); // Ensure you handle the error appropriately
    }
    head_ensah();
    u1 = (user *)malloc(sizeof(user));
    setcolor(9); // Set color for the borders
    gotoxy(65, 10);
    printf("******************************************");
    gotoxy(65, 11);
    printf("-\tCONNEXION A VOTRE COMPTE\t-");
    gotoxy(65, 12);
    printf("******************************************");
    gotoxy(55,11);
    printf("----------");
    gotoxy(101,11);
    printf("----------");
    gotoxy(65,19);
    printf("******************************************");
    setcolor(7); // Reset color for text input fields
    // Username prompt
    gotoxy(65, 14);
    printf("Email: ");
    // Password prompt
    gotoxy(65, 16);
    printf("Mot de passe: ");
    gotoxy(65 + strlen("Email: "), 14);
    scanf("%s", email);
    gotoxy(65 + strlen("Mot de passe: "), 16);
    masquer_mot_de_passe(pass);
    m = 0;
    while (fscanf(fp, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%s\n", &(u1->nom), &(u1->prenom), &(u1->CIN), &(u1->CNE), &(u1->email), &(u1->adresse), &(u1->password)) == 7)
    {
        if (!strcmp(u1->email, email) && !strcmp(u1->password, pass))
        {
            m = 1;
            break;
        }
    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_2);
    gotoxy(65,22);
    if(!m)
    {
        gotoxy(68, 20);
        setcolor(12);
        printf("%s %s",u1->email,u1->password); /* puts("CIN ou Mot de passe incorrect"); */
        Sleep(2500);
        system("cls");
        LOGIN1();
    }
    setcolor(10);
    printf("Connexion réussie ! Bienvenue %s %s.\n", u1->nom, u1->prenom);
    setcolor(7);
    Sleep(2500);
    system("cls");
    espace_etudiant(); // Assurez-vous que cette fonction est bien définie et fonctionne
}


void LOGIN2()
{
    char password[N];
    head();
    fp = fopen(nomFile_3,"rb");
    if (fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_3);
        return;
    }
    setcolor(9); // Set color for the borders
    gotoxy(65, 10);
    printf("***********************************************");
    gotoxy(65, 12);
    printf("-\tCONNECTEZ-VOUS A VOTRE COMPTE\t-");
    gotoxy(65, 14);
    printf("***********************************************");
    gotoxy(55,12);
    printf("----------");
    gotoxy(101,22);
    printf("----------");
    gotoxy(65,20);
    printf("***********************************************");

    setcolor(7);
    gotoxy(65, 17);
    printf("Mot de passe: ");
    gotoxy(65+strlen("Mot de passe: "),17);
    masquer_mot_de_passe(password);
    m = 0;
    fflush(stdin);
    while(fscanf(fp,"%s",pass)==1)
    {
        if(!strcmp(password,pass))
        {
            m = 1;
            break;
        }
        fflush(stdin);
    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_3);
    gotoxy(70,22);
    if(!m)
    {
        setcolor(4);
        gotoxy(73, 24);
        puts("CIN ou Mot de passe incorrect\n");
        Sleep(2500);
        system("cls");
        LOGIN2();
    }
    setcolor(10);
    printf("Connexion réussie!\n");
    Sleep(2500);
    system("cls");
    espace_administration();
    exit(0);
}


void erreur_page(){
    system("cls");
    system("color F9");
    gotoxy(65, 12);
    printf("********************************************");
    gotoxy(71, 14);
    printf("Consulter cette page ulterieurement !!");
    gotoxy(87, 16);
    printf("MERCI...");
    gotoxy(65, 18);
    printf("********************************************");
    gotoxy(0,27);
    setcolor(07);
    Sleep(2500);
    exit(0);
    system("PAUSE"); // Exit the program
}


void login_sign_in1()
{
    system("color 9");
    printf("\n\n\n\n****************************************************************************************************************************************************************************");
    printf("\t\t\t\t\t\t\t\t - E S P A C E   D E S   E T U D I A N T S -");
    printf("****************************************************************************************************************************************************************************\n\n\n\n");
    while(1)
    {
        n = 0;
        // Set color for the top border
        setcolor(9); // Blue for the border
        gotoxy(65, 9);
        printf("***************************************");
        // Set color for the login option
        setcolor(9);
        gotoxy(65, 11);
        printf("|\t");
        setcolor(7);
        printf("1. Se connecter                 ");
        setcolor(9);
        puts("|");
        // Set color for the sign-in option
        setcolor(9);
        gotoxy(65, 13);
        printf("|\t");
        setcolor(7);
        printf("2. S'inscrire               ");
        setcolor(9);
        puts("|");
        // Set color for the exit option
        setcolor(9);
        gotoxy(65, 15);
        printf("| \t");
        setcolor(7);
        printf("3. Quitter                  ");
        setcolor(9);
        puts("|");
        setcolor(9);
        gotoxy(65, 17);
        printf("***************************************\n");
        setcolor(7);
        gotoxy(57, 19);
        setcolor(9);
        printf("******************************************************\n");
        gotoxy(57, 20);
        printf("|");
        setcolor(7);
        gotoxy(65, 20);
        printf("Veuillez selectionner une option valide (1-3): ");
        setcolor(9);
        gotoxy(120, 20);
        printf("|");
        gotoxy(57, 21);
        printf("******************************************************\n");
        gotoxy(112, 20);
tarik:
        setcolor(7);
        fflush(stdin); scanf("%d", &n);
        // Read user input
        switch (n)
        {
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
           default:
                    gotoxy(57, 23);
                    setcolor(9);
                    printf("**************************************************************************\n");
                    gotoxy(57, 24);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 24);
                    printf("Entree invalide!!! Veuillez selectionner une option valide (1-3): ");
                    setcolor(9);
                    gotoxy(140, 24);
                    puts("|");
                    setcolor(9);
                    gotoxy(57, 25);
                    printf("**************************************************************************\n");
                    gotoxy(131, 24);
                    goto tarik;

        }
    }
}


void login_sign_in2()
{
    system("color 9");
    printf("\n\n\n\n****************************************************************************************************************************************************************************");
    printf("\t\t\t\t\t\t\t\t-E S P A C E   D' A D M I N I S T R A T I O N-");
    printf("****************************************************************************************************************************************************************************\n\n\n\n");
    while(1)
    {
        n = 0;
        // Set color for the top border
        setcolor(9); // Blue for the border
        gotoxy(65, 9);
        printf("***************************************");
        // Set color for the login option
        setcolor(9);
        gotoxy(65, 11);
        printf("|\t");
        setcolor(7);
        printf("1. Connexion                 ");
        setcolor(9);
        puts("|");
        // Set color for the sign-in option
        setcolor(9);
        gotoxy(65, 13);
        printf("|\t");
        setcolor(7);
        printf("2. Quitter                  ");
        setcolor(9);
        puts("|");
        setcolor(9);
        gotoxy(65, 15);
        printf("***************************************\n");
        setcolor(7);
        gotoxy(57, 18);
        setcolor(9);
        printf("******************************************************\n");
        gotoxy(57, 19);
        printf("|");
        setcolor(7);
        gotoxy(65, 19);
        printf("Veuillez selectionner une option valide (1-3): ");
        setcolor(9);
        gotoxy(120, 19);
        printf("|");
        gotoxy(57, 20);
        printf("******************************************************\n");
        gotoxy(112, 19);
tarik:
        setcolor(7);
        fflush(stdin); scanf("%d", &n);
        // Read user input
        switch (n)
        {
            case 1:
               system("cls"); // Clear the screen
               LOGIN2(); // Call the login function
               return; // Exit the function after successful login
            case 2:
                system("cls");
                homepage();
           default:
                    gotoxy(57, 23);
                    setcolor(9);
                    printf("**************************************************************************\n");
                    gotoxy(57, 24);
                    printf("|");
                    setcolor(7);
                    gotoxy(60, 24);
                    printf("Entree invalide!!! Veuillez selectionner une option valide (1-3): ");
                    setcolor(9);
                    gotoxy(140, 24);
                    puts("|");
                    setcolor(9);
                    gotoxy(57, 25);
                    printf("**************************************************************************\n");
                    gotoxy(131, 24);
                    goto tarik;
        }
    }
}


void homepage()
{
    n = 0;
    system("color 9");
    printf("\n\n\n\n****************************************************************************************************************************************************************************");
    gotoxy(72, 3);
    printf("-M E N U  P R I N C I P A L-\n");
    printf("****************************************************************************************************************************************************************************");
    gotoxy(48,10);
    printf("Veuillez choisir l'espace que vous voulez souhaiter faire des operations :");
    gotoxy(50,15);
    printf("1-Espace Etudiants : \t\t\t 2-Espace Administration :");
    gotoxy(79,19);
    printf("3-QUITTER :\n\n\n");
    printf("****************************************************************************************************************************************************************************");
    gotoxy(130,40);
    puts("¸2024 ENSAH LIBRARY. All rights reserved - Developed by T. BOUKAIDI and I. BEL EL YAZID");
    gotoxy(68,25);
    printf("Veuillez entrer votre choix : ");
tarik:
    setcolor(07);
    fflush(stdin); scanf("%d", &n);
    switch (n)
    {
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
        default:
            gotoxy(57, 22);
            setcolor(9);
            printf("**************************************************************************\n");
            gotoxy(57, 23);
            printf("|");
            setcolor(7);
            gotoxy(60, 23);
            printf("Entree invalide!!! Veuillez selectionner une option valide (1-3): ");
            setcolor(9);
            gotoxy(140, 23);
            puts("|");
            setcolor(9);
            gotoxy(57, 24);
            printf("**************************************************************************\n");
            gotoxy(131, 23);
            goto tarik;
    }
}


void afficher_livre(const char *nom)
{
    if((pos != -1.0) && (pos != -2.0))
    {
        fp = fopen(nom , "rt");
        if (fp == NULL)
        {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nom);
            return;
        }
        tmp = (info_livre*) malloc (sizeof(info_livre));
        fseek(fp , pos , SEEK_SET);
        fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%f|%f\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nom);
        afficher_informations1(*tmp);
        free(tmp);
    }
    else if(pos == -1.0) puts("Aucun livre correspond avec vos informations !!");
    else puts("\nDesole!!! Actuellement, Il n'y a pas de livre en stock!!!\n\tVoyez revenir ulterierement\n\tMERCI POUR VOTRE COMPREHENSION.");
}


void afficher_informations1(info_livre tmp)
{
    printf("\n============== Details du Livre ==============\n");
    printf("ID               : %d\n", tmp.ID);
    printf("Titre            : %s\n", tmp.titre);
    printf("Acteur           : %s\n", tmp.auteur);
    printf("Editeur          : %s\n", tmp.editeur);
    printf("Année            : %d\n", tmp.ans_publication);
    printf("Prix par jour    : %.2f\n", tmp.prix_jour);
    printf("Prix par semaine : %.2f\n", tmp.prix_semaine);
    printf("================================================\n");
}


void affiche_livre(const char *fichier_source)
{
    recherche_livre();
    if(pos == -2.0) puts("Desole!!! Actuellement, Il n'y a pas de livre dans la bibliotheque !!!\n\tMerci de revenir ulterierement.");
    else
    {
        n = 0;
        tmp = (info_livre*) malloc (sizeof(info_livre));
        printf("____________________________________________________________________________________________________________________________\n");
        gotoxy(30,35);
        printf("| ID         | Titre               | Auteur            | Éditeur            |  Année  | Prix/Jour | Prix Aprés une Semaine |\n");
        gotoxy(30,36);
        printf("____________________________________________________________________________________________________________________________\n");
        fp = fopen(fichier_source, "r+t");
        if (fp == NULL)
        {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", fichier_source);
            return;
        }
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%f|%f\n", &(tmp->ID), &(tmp->titre), &(tmp->auteur), &(tmp->editeur), &(tmp->ans_publication), &(tmp->prix_jour), &(tmp->prix_semaine)) == 7)
        {
            gotoxy(30, 37 + n);
            printf("| %-10d | %-19s | %-17s | %-18s | %-7d | %-9.2f | %-22.2f |\n", (tmp->ID), (tmp->titre), (tmp->auteur), (tmp->editeur), (tmp->ans_publication), (tmp->prix_jour), (tmp->prix_semaine));
            n++;
        }
        gotoxy(30, 37 + n);
        printf("____________________________________________________________________________________________________________________________\n");
        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", fichier_source);
    }
}


void retourner_livre()
{
    m = 0; // Flag pour indiquer si le livre est trouvé
    char nom[100]; // Titre du livre à retourner
    // Ouverture des fichiers
    fp = fopen(nomFile, "r+t");
    fp_1 = fopen(nomFile_1, "w+t");
    if(fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
        exit(1);
    }
    if(fp_1 == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
        exit(1);
    }
    // Lecture du titre du livre
    printf("Entrez le titre du livre : ");
    fflush(stdin);
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';  // Supprimer le saut de ligne (\n)
    info_livre *livre = (info_livre*) malloc (sizeof(info_livre));
    // Lecture ligne par ligne du fichier source
    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(livre->ID), &(livre->titre), &(livre->auteur), &(livre->editeur), &(livre->ans_publication), &(livre->qte), &(livre->prix_jour), &(livre->prix_semaine)) == 8)
    {
        // Affiche le livre lu pour vérifier
        printf("Vérification du livre : %s\n", livre->titre);
        // Comparer le titre
        if (!strcmp(livre->titre, nom))
        {                                    // Si le livre est trouvé
            livre->qte += 1;             // Incrémenter la quantité
            m = 1;                       // Marquer comme trouvé
        }
        // Écrire le livre (modifié ou non) dans le fichier temporaire
        fprintf(fp_1, "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n", (livre->ID), (livre->titre), (livre->auteur), (livre->editeur), (livre->ans_publication), (livre->qte), (livre->prix_jour), (livre->prix_semaine));
    }
    // Fermeture des fichiers
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
    n = fclose(fp_1);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_1);
    // Vérification si le livre a été trouvé
    if (m)
    {
        remove(nomFile);            // Supprime le fichier source
        rename(nomFile_1, nomFile); // Renomme le fichier temporaire
        printf("Le livre a été retourné avec succès.\n");
    }
    else
    {
        remove(nomFile_1);          // Supprime le fichier temporaire
        printf("Erreur : Le livre n'existe pas.\n");
    }
}


void afficher_menu_etu()
{
    head_ensah();
    setcolor(9);
        gotoxy(60,12);
    puts("━━━━━━━━━━━━━━━━━━ESPACE ETUDIANTS━━━━━━━━━━━━━━━━━");
    gotoxy(60, 14);
    printf("*\t1           Emprunter un livre               *");
    gotoxy(60, 16);
    printf("---------------------------------------------------");
    gotoxy(60, 18);
    printf("*\t2           Rechercher un livre              *");
    gotoxy(60, 20);
    printf("---------------------------------------------------");
    gotoxy(60, 22);
    printf("*\t3       Lister les livres disponibles        *");
    gotoxy(60, 24);
    printf("---------------------------------------------------");
    gotoxy(60, 26);
    printf("*\t0                Exit                        *");
    gotoxy(60, 28);
    puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoxy(64, 30);
    printf("Veuillez entrer une meilleure choix (0-3):  ");
    setcolor(07);
    gotoxy(64+strlen("Veuillez entrer une meilleure choix (0-3): "),30);
    scanf("%d", &choix);
}


void espace_etudiant()
{
    head();
    convertirEnMajuscules(u1->nom);
    convertirEnMajuscules(u1->prenom);
    gotoxy(73,9);
    printf("BIENVENUE %s %s ", u1->nom, u1->prenom);
    Is_Fichier_Livre(nomFile);
    Is_Fichier_Livre(nomFile_2);
    Is_Fichier_Livre(nomFile_4);
    afficher_menu_etu();
    do
    {
    switch(choix)
    {
        case 0 :
            system("cls");
            homepage();
            break;
        case 1 :
            emprunter_livre();
            break;
        case 2 :
            recherche_livre();
            if(pos == -2.0) puts("\nDesole!!! Actuellement, Il n'y a pas de livre !!!\n\tVoyez revenir ulterierement\n\tMERCI POUR VOTRE COMPREHENSION.");
            else
            {
                espace_recherche_livre();
                afficher_livre(nomFile);
                getch();
            }
            break;
        case 3 :
            affiche_livre(nomFile);
            break;
        default :
            setcolor(4);
            gotoxy(62,32);
            puts("Erreur!!! entrer un nombre valide entre (0-3):");
            Sleep(2000);
            gotoxy(65,33);
            puts("Appuyez sur une touche pour continuer...");
            break;
    }
    printf("Appuyez sur une touche pour continuer...");
    getch();
    system("cls");

    if(choix) espace_etudiant();
    }while(choix != 0);

    getch();
}


void afficher_menu_admini()
{
    head_ensah();
    setcolor(9);
        gotoxy(35,11);
    puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━│ESPACE ADMINISTRATION│━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoxy(50,15);
    printf("1-Ajouter un livre");
    gotoxy(107,15);
    printf("2-Supprimer un livre                      ");
    gotoxy(50,19);
    printf("3-Modifier les informations d\'un livre    ");
    gotoxy(107,19);
    printf("4-Retourner un livre                      ");
    gotoxy(50,23);
    printf("5-Statistique");
    gotoxy(107,23);
    printf("6-Recherche un livre");
    gotoxy(50,27);
    printf("7-Lister les livres empruntes");
    gotoxy(107,27);
    printf("0-Exit");
    gotoxy(35,30);
    puts("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
    gotoxy(70,33);
    printf("Veuillez entrer une meilleur choix (0-7): ");
    scanf("%d", &choix);
}


void espace_administration()
{
    head();
    Is_Fichier_Livre(nomFile);
    Is_Fichier_Livre(nomFile_2);
    Is_Fichier_Livre(nomFile_4);
    afficher_menu_admini();
    do
    {
    switch(choix)
    {
        case 0 :
            system("cls");
            homepage();
            break;
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
        case 4 :
            retourner_livre();
            break;
        case 5 : break;
        case 6 :
            recherche_livre();
            if(pos == -2.0) puts("\nLa liste est vide !!!");
            else
            {
                espace_recherche_livre();
                afficher_fpos();
                getch();
            }
            break;
        case 7 :
            liste_livre_emprunter();
            break;
        default :
            setcolor(4);
            gotoxy(62,34);
            puts("Erreur!!! entrer un nombre valide entre (0-3):");
            sleep(2);
            gotoxy(65,35);
            puts("Appuyez sur une touche pour continuer...");
            break;
    }
    getch();
    system("cls");

    if(choix) espace_administration();
    }while(choix != 0);

    getch();
}


void saiser_informations_etudiant(info_livre_emprunter **tmp)
{
    printf("Enter la CIN    : ");
erreur_print1:
    fflush(stdin);
    scanf("%s",&((*tmp)->CIN));
    if(!isTextPrint((*tmp)->CIN))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir une CIN valide");
        goto erreur_print1;
    }
    printf("Enter la CNE    : ");
erreur_print2:
    fflush(stdin);
    scanf("%s",&((*tmp)->CNE));
    if(!isTextPrint((*tmp)->CNE))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir une CNE valide");
        goto erreur_print2;
    }
}


int recherche_etudiant_user(info_livre_emprunter *tmp)
{
    fp = fopen(nomFile_2 , "r+t");
    if(fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\n", nomFile_2);
        exit(1);
    }
    m = 0;
    while (fgets(line, sizeof(line), fp))
    {
        if(strstr(line , (tmp->CIN)) && strstr(line , (tmp->CNE)))
        {
            m = 1;
            break;
        }
    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\. ", nomFile_2);
    return m;
}


void emprunter_livre()
{
    recherche_livre();
    if(pos != -2.0)
    {
        // Demander l'ID a l'utilisateur
        printf("Entrez l'ID du livre : ");
erreur_num:
        fflush(stdin);
        n = scanf("%d", &id);
        if((n != 1) || (id <= 0))
        {
            printf("Voyez saisir une valeur correcte (>0) : ");
            goto erreur_num;
        }
        temporaire = (info_livre_emprunter*) malloc (sizeof(info_livre_emprunter));
        // Charger le livre correspondant a l'ID
        recherche_livre();
        if ((pos != -1.0) && (pos != -2.0))
        {
            if(!(tmp->qte))
            {
                puts("Nous sommes désolés, mais nous n'avons pas ce livre en stock pour le moment\n");
                return;
            }
            saiser_informations_etudiant(&temporaire);
            m = recherche_etudiant_user(temporaire);
            if(m)
            {
                temporaire->livre = tmp ;
                puts("Combien de jours voulez-vous d'emprunt ? (N.B : Ne dépasse pas 2 mois)");
erreur_num1:
                fflush(stdin);
                m = scanf("%d", &n);
                if((m != 1) || (n <= 0) || (n > 60) )
                {
                    printf("Voyez saisir une valeur correcte (0<Jours<60) : ");
                    goto erreur_num1;
                }
                // Calculer le cout
                float total = (n < 7) ? tmp->prix_jour * n : tmp->prix_semaine;
                if(n == 1) printf("Le coût total d'un seul jour est : %.2fDH\n", total);
                else printf("Le coût total des %d jours est : %.2fDH\n", n, total);
                printf("Voulez-vous suiver cette processus : ");
erreur_alpha4:
                fflush(stdin);
                scanf(" %c", &c);
                if(toupper(c) != 'O' && toupper(c) != 'N')
                {
                    printf("Voyez saisir une choix correcte (O/N) : ");
                    goto erreur_alpha4;
                }
                else if(toupper(c) == 'O')
                {
                    int jour = 0, mois = 0, annee = 0;
                    while(((jour > 31) || (jour < 1)) || ((mois > 12) || (mois < 1)) || (annee < 1900))
                    {
                        printf("Donnez la date de livraison du livre (jj / mm / aaaa) (N.B : la date doit egalement >= 2jours) : ");
erreur_date:
                        scanf("%d\t %d\t %d", &jour, &mois, &annee);
                    }
                    time_t now = time(NULL);
                    struct tm *cur_time = localtime(&now);
                    if((((cur_time->tm_mday) - jour < -1) && !((cur_time->tm_mon) - mois + 1) && !((cur_time->tm_year) - annee + 1900)) || ((cur_time->tm_year) - annee + 1900 < 0) || (((cur_time->tm_mon) - mois + 1 > 0) && ((cur_time->tm_year) - annee + 1900 < 0)))
                    {
                        cur_time->tm_year = annee - 1900;
                        cur_time->tm_mon = mois - 1;
                        cur_time->tm_mday = jour;
                    }
                    else
                    {
                        printf("Voyer une date convenable (Date >= 2jours) : ");
                        goto erreur_date;
                    }
                    char *s1 = (char*) malloc (K * sizeof(char));
                    strftime(s1 , K , "%H:%M" , cur_time);
                    char *s2 = (char*) malloc (M * sizeof(char));
                    strftime(s2 , M , "%Z" , cur_time);
                    strftime((temporaire->date_debut) , K , "%d %m %Y" , cur_time);
                    struct tm *cur_time1 = localtime(&now);
                    cur_time1->tm_year = annee - 1900;
                    cur_time1->tm_mon = mois - 1;
                    cur_time1->tm_mday = jour + n;
                    while(1)
                    {
                        if((!(cur_time1->tm_mon) || (cur_time1->tm_mon == 2) || (cur_time1->tm_mon == 4) || (cur_time1->tm_mon == 6) || (cur_time1->tm_mon == 7) || (cur_time1->tm_mon == 9) || (cur_time1->tm_mon == 11)) && (cur_time1->tm_mday > 31))
                        {
                            cur_time1->tm_mday -= 31;
                            cur_time1->tm_mon += 1;
                        }
                        else if(((cur_time1->tm_mon == 3) || (cur_time1->tm_mon == 5) || (cur_time1->tm_mon == 8) || (cur_time1->tm_mon == 10)) && (cur_time1->tm_mday > 30))
                        {
                            cur_time1->tm_mday -= 30;
                            cur_time1->tm_mon += 1;
                        }
                        else
                        {
                            if((cur_time1->tm_mday > 29) && !((cur_time1->tm_year + 1900) % 4) && ((cur_time1->tm_mon) == 1)) cur_time1->tm_mday -= 29;
                            else if((cur_time1->tm_mday > 28) && ((cur_time1->tm_year + 1900) % 4) && ((cur_time1->tm_mon) == 1)) cur_time1->tm_mday -= 28;
                            else break;
                            cur_time1->tm_mon += 1;
                        }
                        if(cur_time1->tm_mon > 11)
                        {
                            cur_time1->tm_mon -= 12;
                            cur_time1->tm_year += 1;
                        }
                    }
                    strftime((temporaire->date_fin) , K , "%d %m %Y" , cur_time1);
                    n = 0;
                    copier_livres(nomFile , nomFile_1);
                    fp = fopen(nomFile_4,"a+t");
                    if(fp==NULL)
                    {
                        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_4);
                        return;
                    }
                    fprintf(fp , "%-7d %-28s %-20s %-28s %-7d %-12s %-12s %-12s %-12s\n" , (temporaire->livre->ID) , (temporaire->livre->titre) , (temporaire->livre->auteur) , (temporaire->livre->editeur) , (temporaire->livre->ans_publication) , (temporaire->CIN), (temporaire->CNE), (temporaire->date_debut), (temporaire->date_fin));
                    n = fclose(fp);
                    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_4);
                    puts("Votre emprunte a été effectué sans erreur!!");
                    Sleep(2000);
                    printf("Vous recevez la livraison le jour : %s a %s (%s) , Jusqu'au : %s a %s (%s) .\n", temporaire->date_debut, s1, s2, temporaire->date_fin, s1, s2);
                }
                else puts("Merci de votre visite!!");
            }
            else puts("\nL'etudiant(e) n'inscrit pas a la bibliotheque .");
        }
        else printf("Aucun livre trouvé avec l'ID %d.\n", id);
    }
    else puts("\nDesole!!! Actuellement, Il n'y a pas de livre pour emprunter !!!\n\tVoyez revenir ulterierement\n\tMERCI POUR VOTRE COMPREHENSION.");
}


void liste_livre_emprunter()
{
    system("cls");
    fp = fopen(nomFile_4,"r+t");
    if(fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_4);
        return ;
    }
    printf("   ID  |            Titre           |        Acteur      |           Editeur          | Annee |     CIN    |     CNE    |  DateDebut |   DateFin \n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s\n", line);
        fflush(stdin);
    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_4);
}


void copier_livres(const char *fichier_source, const char *fichier_destination)
{
    fp = fopen(fichier_source, "r+t");
    fp_1 = fopen(fichier_destination, "w+t");
    // Verification de l'ouverture des fichiers
    if (fp == NULL) {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", fichier_source);
        return;
    }
    if (fp_1 == NULL) {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", fichier_destination);
        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", fichier_source); // Fermer le fichier source avant de quitter
        return;
    }
    tmp = (info_livre*) malloc (sizeof(info_livre));
    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(tmp->ID), (tmp->titre), (tmp->auteur), (tmp->editeur), &(tmp->ans_publication), &(tmp->qte), &(tmp->prix_jour), &(tmp->prix_semaine)) == 8)
    {
        if((tmp->ID) != id) fprintf(fp_1, "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n", (tmp->ID), (tmp->titre), (tmp->auteur), (tmp->editeur), (tmp->ans_publication), (tmp->qte), (tmp->prix_jour), (tmp->prix_semaine));
        else if(!n) fprintf(fp_1, "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n", (tmp->ID), (tmp->titre), (tmp->auteur), (tmp->editeur), (tmp->ans_publication), ((tmp->qte) - 1), (tmp->prix_jour), (tmp->prix_semaine));
        else fprintf(fp_1, "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n", (tmp->ID), (tmp->titre), (tmp->auteur), (tmp->editeur), (tmp->ans_publication), ((tmp->qte) + 1), (tmp->prix_jour), (tmp->prix_semaine));
    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", fichier_source);
    n = fclose(fp_1);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", fichier_destination);
    remove(fichier_source);
    rename(fichier_destination , fichier_source);
}

/*
void statistique()
{
    int maxi = 0, mini = 0;
    float maxi1 = 0.0, mini1 = 0.0;
    int *tab_id_qte, *tab_id_ans, *tab_id_prix;
    tab_id_qte = (int*) malloc (L * sizeof(int));
    tab_id_ans = (int*) malloc (L * sizeof(int));
    tab_id_prix = (int*) malloc (L * sizeof(int));
    tmp = (info_livre*) malloc (sizeof(info_livre));
    fp = fopen(nomFile, "r+t");
    fp_1 = fopen(nomFile_4, "r+t");
    if (fp == NULL) {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
        return;
    }
    if (fp_1 == NULL) {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_4); // Fermer le fichier source avant de quitter
        return;
    }
    printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ Statistique ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
    printf("º   Les livre(s) (a/ont) plus grand quantité (sont/est):           º\n");
    while(!feof(fp))
    {
        fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        if(maxi <= (tmp->qte))
        {
            maxi = (tmp->qte);
        }
        if(mini >= (tmp->qte)) mini = (tmp->qte);

        if(maxi <= (tmp->ans_publication)) maxi = (tmp->ans_publication);

        if(mini >= (tmp->ans_publication)) mini = (tmp->ans_publication);

        if(maxi1 <= (tmp->prix_semaine)) maxi1 = (tmp->prix_semaine);

        if(mini1 >= (tmp->prix_semaine)) mini1 = (tmp->prix_semaine);

    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
    n = fclose(fp_1);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_4);


}
*/

/*
void affiche_livre_emprunter()
{
    setcolor(9);
    char line[L];
    fp = fopen(nomFile_4,"r+t");
    if(fp == NULL)
    {
        printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_4);
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) printf("%s", line);
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_4);
}
*/

void espace_recherche_livre()
{
    printf("Donner ID de livre : ");
erreur_num2:
    fflush(stdin);
    n = scanf("%d", &id);
    if((n != 1) || (id <= 0))
    {
        printf("Voyez saisir une valeur correcte (>0) : ");
        goto erreur_num2;
    }
    recherche_livre();
    if((pos != -1.0) && (pos != -2.0)) puts("Les informations du livre sont comme suit : ");
}


void Is_Fichier_Livre(const char *nom)
{
    fp = fopen(nom , "r+t");
    if(fp == NULL)
    {
        fp = fopen(nom , "w+t");
        if(fp == NULL)
        {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nom);
            exit(1);
        }
    }
    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nom);
}


void afficher_informations(info_livre b)
{
    printf("ID du livre\t\t\t\t\t\t\t: %d \n",b.ID);
    printf("Le titre du livre\t\t\t\t\t\t: %s \n",b.titre) ;
    printf("Nom d'acteur du livre\t\t\t\t\t        : %s \n",b.auteur) ;
    printf("L'ans du publication du livre\t\t\t\t        : %d \n",b.ans_publication) ;
    printf("L'editeur du livre \t\t\t\t\t\t: %s \n",b.editeur) ;
    printf("La quantite du livres en stock     \t\t\t\t: %d \n",b.qte) ;
    printf("Le prix de livre pour emprunter par jour (en MAD)  \t\t: %.2f \n",b.prix_jour) ;
    printf("Le prix de livre pour emprunter de plus une semaine (en MAD)    : %.2f \n",b.prix_semaine) ;
}


void saiser_informations(info_livre **b)
{
    if(!id)
    {
        printf("Entrer id du livre : ") ;
erreur_num3:
        fflush(stdin);
        n = scanf("%d",&((*b)->ID));
        if((n != 1) || (((*b)->ID) <= 0))
        {
            printf("Voyez saisir une valeur correcte (>0) : ");
            goto erreur_num3;
        }
    }
    printf("Entrer le titre du livre : ") ;
erreur_print3:
    fflush(stdin);
    scanf("%[^\n]",&((*b)->titre)) ;
    if(!isTextPrint((*b)->titre))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir un titre valide : ");
        goto erreur_print3;
    }
    printf("Entrer nom d'acteur du livre : ") ;
erreur_nom3:
    fflush(stdin);
    scanf("%[^\n]",&((*b)->auteur)) ;
    if(!isTextOnly((*b)->auteur))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE et ESPACE\nVoyez saisir un nom valide : ");
        goto erreur_nom3;
    }
    printf("Entrer l'ans du publication du livre : ") ;
erreur_num4:
    fflush(stdin);
    n = scanf("%d",&((*b)->ans_publication)) ;
    if((n != 1) || (((*b)->ans_publication) <= 0))
    {
        printf("Voyez saisir une annee correcte (>0) : ");
        goto erreur_num4;
    }
    printf("Entrer l'editeur du livre : ") ;
erreur_print4:
    fflush(stdin);
    scanf("%[^\n]",&((*b)->editeur)) ;
    if(!isTextPrint((*b)->editeur))
    {
        printf("\n\t!!! N.B : Seul de CARACTERE, ESPACE et CHIFFRE\nVoyez saisir un editeur valide : ");
        goto erreur_print4;
    }
    printf("Entrer la quantite du livres en stock : ") ;
erreur_num5:
    fflush(stdin);
    n = scanf("%d",&((*b)->qte)) ;
    if((n != 1) || (((*b)->qte) <= 0))
    {
        printf("Voyez saisir une valeur correcte (>0) : ");
        goto erreur_num5;
    }
    printf("Entrer le prix de livre pour emprunter par jour (en MAD) : ") ;
erreur_flo:
    fflush(stdin);
    n = scanf("%f",&((*b)->prix_jour)) ;
    if((n != 1) || (((*b)->prix_jour) < 0))
    {
        printf("Voyez saisir un prix correct (>0) : ");
        goto erreur_flo;
    }
    printf("Entrer le prix de livre pour emprunter de plus une semaine (en MAD)  : ") ;
erreur_flo1:
    fflush(stdin);
    n = scanf("%f",&((*b)->prix_semaine)) ;
    if((n != 1) || (((*b)->prix_semaine) < 0))
    {
        printf("Voyez saisir un prix correct (>0) : ");
        goto erreur_flo1;
    }
}


void ajouter_livre()
{
        // ajout des livres :
        puts("Entrer les informations sur livre : \n");
        printf("Entrer id du livre : ") ;
erreur_num6:
        fflush(stdin);
        n = scanf("%d",&id);
        if((n != 1) || (id <= 0))
        {
            printf("Voyez saisir une valeur correcte (>0): ");
            goto erreur_num6;
        }

        recherche_livre();
        if((pos != -1.0) && (pos != -2.0)) printf("\nERREUR!!! VOYEZ ENTRER UN AUTRE ID!!! Cette ID est deja remplie.\n");
        else
        {
            info_livre *debut = (info_livre*)malloc(sizeof(info_livre));
            debut->ID = id;
            saiser_informations(&debut);
            info_livre_equ(debut);
            if((pos != -1.0) && (pos != -2.0))
            {
                puts("\n\nS'il vous plait !!!\nVeuillez entrer un autre livre cette livre deja existe\nSes informations sont representent comme suit :\n");
                afficher_fpos();
            }
            else
            {
                fp = fopen(nomFile , "a+t");
                if(fp == NULL)
                {
                    printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                    exit(1);
                }
                fprintf(fp , "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n" , (debut->ID) , (debut->titre) , (debut->auteur) , (debut->editeur) , (debut->ans_publication) , (debut->qte) , (debut->prix_jour) , (debut->prix_semaine));
                puts("\nL'enregesretement des informations s'effectue avec succee") ;

                n = fclose(fp);
                if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
            }

        }
        printf("Voulez-vous ajouter une autre livre (O/N) ? ");
erreur_alpha:
        fflush(stdin);
        scanf(" %c", &c);
        if(toupper(c) != 'O' && toupper(c) != 'N')
        {
            printf("Voyez saisir une choix correcte (O/N) : ");
            goto erreur_alpha;
        }
        else if(toupper(c) == 'O') ajouter_livre();
}


void afficher_fpos()
{
    setcolor(7);
    if((pos != -1.0) && (pos != -2.0))
    {
        fp = fopen(nomFile , "r+t");
        if(fp == NULL)
        {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
            exit(1);
        }
        fseek(fp , pos , SEEK_SET);
        tmp = (info_livre*)malloc(sizeof(info_livre));
        fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        afficher_informations(*tmp);

        n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
    }
    else if(pos == -1.0) printf("Ce livre n'existe pas !!! \n");
    else printf("\nLa liste est vide !!!\n");

}


void info_livre_equ(info_livre *debut)
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
        m = fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        if(!stricmp(debut->titre , tmp->titre) && !stricmp(debut->auteur , tmp->auteur) && !stricmp(debut->editeur , tmp->editeur) && (debut->ans_publication == tmp->ans_publication)) break;
    }
    if(!stricmp(debut->titre , tmp->titre) && !stricmp(debut->auteur , tmp->auteur) && !stricmp(debut->editeur , tmp->editeur) && (debut->ans_publication == tmp->ans_publication))
    {
        pos = ftell(fp);
        pos -= pos / n ;
    }
    else if((m == -1) && (n == 1)) pos = -2.0;
    else pos = -1.0;

    n = fclose(fp);
    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

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
        m = fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n", &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
        if(id == tmp->ID) break;
    }
    if(id == tmp->ID)
    {
        pos = ftell(fp);
        pos -= pos / n ;
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
erreur_num7:
        fflush(stdin);
        n = scanf("%d", &id);
        if((n != 1) || (id <= 0))
        {
            printf("Voyez saisir une valeur correcte (>0) : ");
            goto erreur_num7;
        }
        recherche_livre();
        if (pos == -1.0) printf("Ce livre n'existe pas !!! \n");
        else
        {
            puts("Les informations du livre que vous voulez supprimer sont comme suit :\n");
            afficher_fpos();
            n = 1 ;
            printf("Voulez-vous suiver cette operation (O/N) : ");
erreur_alpha1:
            fflush(stdin);
            scanf(" %c", &c);
            if(toupper(c) != 'O' && toupper(c) != 'N')
            {
                printf("Voyez saisir une choix correcte (O/N) : ");
                goto erreur_alpha1;
            }
            else if(toupper(c) == 'O')
            {
                fp = fopen(nomFile , "r+t");
                fp_1 = fopen(nomFile_1 , "w+t");
                if(fp == NULL)
                {
                    printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                    exit(1);
                }
                if(fp_1 == NULL)
                {
                    printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
                    n = fclose(fp);
                    if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
                    exit(1);
                }
                tmp = (info_livre*)malloc(sizeof(info_livre));
                while(!feof(fp))
                {
                    fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
                    if(id != tmp->ID) fprintf(fp_1 , "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication) ,  (tmp->qte) , (tmp->prix_jour) , (tmp->prix_semaine));
                }
                n = fclose(fp);
                if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
                n = fclose(fp_1);
                if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_1);
                remove(nomFile);
                n = rename(nomFile_1 , nomFile);
            }
            if(!n) printf("\nLa suppression des informations de livre de ID = %d s'effectue avec succee \n", id) ;
            else printf("\nLa suppression des informations de livre de ID = %d s'effectue avec echoue \n", id) ;
        }
    }
        printf("\nVoulez-vous supprimer une autre livre (O/N) ? ");
erreur_alpha2:
        fflush(stdin);
        scanf(" %c", &c);
        if(toupper(c) != 'O' && toupper(c) != 'N')
        {
            printf("Voyez saisir une choix correcte (O/N) : ");
            goto erreur_alpha2;
        }
        else if(toupper(c) == 'O') supprimer_livre();
}


void modifier_livre()
{
    recherche_livre();
    if(pos == -2.0) printf("\nLa liste est vide !!!\n");
    else
    {
        printf("Donner ID de livre que vous souhaitez modifier ses informations : ");
erreur_num8:
        fflush(stdin);
        n = scanf("%d", &id);
        if((n != 1) || (id <= 0))
        {
            printf("Voyez saisir une valeur correcte (>0) : ");
            goto erreur_num8;
        }
        recherche_livre();
        if(pos != -1.0)
        {
            n = 1 ;
            fp = fopen(nomFile , "r+t");
            fp_1 = fopen(nomFile_1 , "w+t");
            if(fp == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
                exit(1);
            }
            if(fp_1 == NULL)
            {
                printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
                n = fclose(fp);
                if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
                exit(1);
            }

            tmp = (info_livre*)malloc(sizeof(info_livre));
            while(!feof(fp))
            {
                fscanf(fp , "%d|%[^|]|%[^|]|%[^|]|%d|%d|%f|%f\n" , &(tmp->ID) , &(tmp->titre) , &(tmp->auteur) , &(tmp->editeur) , &(tmp->ans_publication) , &(tmp->qte) , &(tmp->prix_jour) , &(tmp->prix_semaine));
                if(id != tmp->ID) fprintf(fp_1 , "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication) , (tmp->qte) , (tmp->prix_jour) , (tmp->prix_semaine));
                else
                {
                    puts("Les anciennes informations de ce livre sont comme suit : \n");
                    afficher_informations(*tmp);
                }
            }
            puts("Donner les nouveaux informations de ce livre : \n");
            tmp->ID = id;
            saiser_informations(&tmp);
            fprintf(fp_1 , "%d|%s|%s|%s|%d|%d|%.2f|%.2f\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication) , (tmp->qte) , (tmp->prix_jour) , (tmp->prix_semaine));

            n = fclose(fp);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

            n = fclose(fp_1);
            if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile_1);

            remove(nomFile);
            n = rename(nomFile_1 , nomFile);
            if(!n) printf("\nLa modification des informations de livre de ID = %d s'effectue avec succee \n", id) ;
            else printf("\nLa modification des informations de livre de ID = %d s'effectue avec echoue \n", id) ;
        }
        else printf("Ce livre n'existe pas !!! \n");
        printf("\nVoulez-vous modifier une autre livre (O/N) ? ");
erreur_alpha3:
        fflush(stdin);
        scanf(" %c", &c);
        if(toupper(c) != 'O' && toupper(c) != 'N')
        {
            printf("Voyez saisir une choix correcte (O/N) : ");
            goto erreur_alpha3;
        }
        else if(toupper(c) == 'O') modifier_livre();
    }
}


#endif // FUNCTION_H_INCLUDED

