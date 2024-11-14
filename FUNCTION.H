#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
typedef struct{
char nom[20];
char prenom[20];
char CNE[15];
char CIN[15];
char email[28];
char adresse[30];
char password[30];

}user;
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

    FILE *p_file;
    user u;
    p_file=fopen("liste_inscription_eleve.txt","a");
    if (p_file == NULL) {
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
    fprintf(p_file," %-15s|%-20s|%-15s|%-15s|%-28s|%-30s|%-30s\n",u.nom,u.prenom,u.CIN,u.CNE, u.email,u.adresse,u.password);
    fclose(p_file);
    gotoxy(70,22);
    setcolor(10);
    printf("YOU REGISTER SUCCESSFULLY!\n");
    setcolor(07);
}
void LOGIN1(){
    int found=0;
    char line[100];
    head();
    FILE *p_file;
    p_file = fopen("liste_inscription_eleve.txt", "r");
    if (p_file == NULL) {
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
    while (fgets(line, sizeof(line), p_file)) {
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


    fclose(p_file);}
void display_data() {
    FILE *p_file;

    char line[100];
    p_file = fopen("liste_inscription_eleve.txt", "r");
    if (p_file == NULL) {
        printf("Error opening file.\n");
        return;
    }
           while (fgets(line, sizeof(line), p_file)) {
        printf("%s",line);

    }

    fclose(p_file);}
void LOGIN2(){
    head();
    FILE *p_file;
    p_file=fopen("liste d'administration.txt","r");
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
    while(fscanf(p_file,"%s",pass)!=NULL){
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

    fclose(p_file);}

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
    setcolor(9); // Blue for Fthe border
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

#endif // FUNCTION_H_INCLUDED

