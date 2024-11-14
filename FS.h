#ifndef FS_H_INCLUDED
#define FS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>
#define nomFile "livre.txt"
#define nomFile_1 "livre_1.txt"


typedef struct info_livre
{
    int ID , ans_publication ;
    char titre[20] , auteur[20] , editeur[30] ;
}info_livre;



// creation d'une structure :
typedef struct livre
{
    info_livre donnees;
    struct livre *suivant ;
    struct livre *precedent ;
}livre;

typedef livre* plivre;

void saiser_informations(plivre *b)
{
    printf("Entrer id du livre : ") ; scanf("%d",&((*b)->donnees.ID) );
    printf("Entrer le titre du livre : ") ; scanf("%s",&((*b)->donnees.titre)) ;
    printf("Entrer nom d'acteur du livre : ") ; scanf("%s",&((*b)->donnees.auteur)) ;
    printf("Entrer l'ans du publication du livre : ") ; scanf("%d",&((*b)->donnees.ans_publication)) ;
    printf("Entrer l'editeur du livre : ") ; scanf("%s",&((*b)->donnees.editeur)) ;
}


void creation_maillon(plivre *b)
{
    (*b) = (plivre) malloc (sizeof(livre));
    saiser_informations(b);
    (*b)->suivant = NULL;
    (*b)->precedent = NULL;
}


void ajouter_livre(plivre * debut)
{
        // ajout des livres :
        plivre b = NULL , temp;
        puts("Entrer les informations sur livre : \n");
        creation_maillon(&b);
        if((*debut) == NULL) (*debut) = b;
        else
        {
            temp = (*debut);
            while(temp->suivant != NULL) temp = temp->suivant;
            temp->suivant = b;
            b->precedent = temp;
        }

        FILE* fp = fopen(nomFile , "a+t");
        if(fp == NULL) {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
            exit(1);
        }
        //if(ftell(fp)) fputs("ID \t Titre \t Auteur \t Editeur \t Ans Publication\n" , fp);

        fprintf(fp , "%d \t %s \t %s \t\t  %s \t\t  %d\n" , (b->donnees.ID) , (b->donnees.titre) , (b->donnees.auteur) , (b->donnees.editeur) , (b->donnees.ans_publication));
        printf("l'enregesretement des informations s'effectue avec succee \n") ;

        int n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
}


void suprimer_livre(plivre * debut)
{
    plivre tmp , info = NULL;
    printf("Entrer les informations sur livre que vous voulez supprimer : \n\n");
    creation_maillon(&info);
    if((*debut) != NULL)
    {
        if(((*debut)->donnees.ID == info->donnees.ID) && !stricmp((*debut)->donnees.titre , info->donnees.titre) && !stricmp((*debut)->donnees.auteur , info->donnees.auteur) && !stricmp((*debut)->donnees.editeur , info->donnees.editeur) && ((*debut)->donnees.ans_publication == info->donnees.ans_publication))
        {
            (*debut) = (*debut)->suivant;
            free((*debut)->precedent);
            (*debut)->precedent = NULL;
        }
        else
        {
            tmp = (*debut)->suivant;
            while((tmp->suivant != NULL) && ((tmp->donnees.ID != info->donnees.ID) || stricmp(tmp->donnees.titre , info->donnees.titre) || stricmp(tmp->donnees.auteur , info->donnees.auteur) || stricmp(tmp->donnees.editeur , info->donnees.editeur) || (tmp->donnees.ans_publication != info->donnees.ans_publication))) tmp = tmp->suivant;
            if((tmp->donnees.ID == info->donnees.ID) && !stricmp(tmp->donnees.titre , info->donnees.titre) && !stricmp(tmp->donnees.auteur , info->donnees.auteur) && !stricmp(tmp->donnees.editeur , info->donnees.editeur) && (tmp->donnees.ans_publication == info->donnees.ans_publication))
            {
                if(tmp->suivant != NULL) tmp->suivant->precedent = tmp->precedent;
                tmp->precedent->suivant = tmp->suivant;
                free(tmp);
                tmp = NULL;
            }
            else puts("Ce livre n'exist pas !!!");
        }
    }


    FILE* fp_1 = fopen(nomFile_1 , "w+t");
        if(fp_1 == NULL) {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile_1);
            exit(1);
        }

        tmp = (*debut);

        //fputs("ID \t Titre \t Auteur \t Editeur \t Ans Publication\n" , fp_1);
        while(tmp != NULL)
        {
            fprintf(fp_1 , "%d \t %s \t %s \t\t  %s \t\t  %d\n" , (tmp->donnees.ID) , (tmp->donnees.titre) , (tmp->donnees.auteur) , (tmp->donnees.editeur) , (tmp->donnees.ans_publication));
            tmp = tmp->suivant;
        }

        int m = fclose(fp_1);
        if(m) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);

        remove(nomFile);
        int n = rename(nomFile_1 , nomFile);
        if(!n) printf("la suppression des informations de livre s'effectue avec succee \n") ;
        else printf("la suppression des informations de livre s'effectue avec echoue \n") ;
}

#endif // FS_H_INCLUDED
