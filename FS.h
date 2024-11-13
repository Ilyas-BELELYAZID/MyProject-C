#ifndef FS_H_INCLUDED
#define FS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define nomFile "livre.txt"
#define nomFile_1 "livre_1.txt"




// creation d'une structure :
typedef struct livre
{
    int ID , ans_publication ;
    char titre[20] , auteur[20] , editeur[30] ;
    struct livre *suivant ;
}livre;

void saiser_informations(livre **b)
{
    printf("Entrer id du livre \: ") ; scanf("%d",&((*b)->ID) );
    printf("Entrer le titre du livre \: ") ; scanf("%s",&((*b)->titre)) ;
    printf("Entrer nom d'acteur du livre \: ") ; scanf("%s",&((*b)->auteur)) ;
    printf("Entrer l'ans du publication du livre \: ") ; scanf("%d",&((*b)->ans_publication)) ;
    printf("Entrer l'editeur du livre \: ") ; scanf("%s",&((*b)->editeur)) ;
}

void ajouter_livre(livre ** debut)
{
        // ajout des livres :
        printf("Entrer les informations sur livre : \n\n");
        livre *b , *temp;
        b = (livre*) malloc (sizeof(livre));
        saiser_informations(&b);
        b->suivant = NULL;
        if((*debut) == NULL) (*debut) = b;
        else
        {
            temp = (*debut);
            while(temp->suivant != NULL) temp = temp->suivant;
            temp->suivant = b;
        }
        FILE* fp = fopen(nomFile , "a+t");
        if(fp == NULL) {
            printf("\.\.\.\.\.\.\.\.\.\.Impossible d\'ouvrir le fichier %s\.\.\.\.\.\.\.\.\.\.\. \n", nomFile);
            exit(1);
        }
        //if(ftell(fp)) fputs("ID \t Titre \t Auteur \t Editeur \t Ans Publication\n" , fp);

        fprintf(fp , "%d \t %s \t %s \t\t  %s \t\t  %d\n" , (b->ID) , (b->titre) , (b->auteur) , (b->editeur) , (b->ans_publication));
        printf("l'enregesretement des informations s'effectue avec succee \n") ;

        int n = fclose(fp);
        if(n) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
}


void suprimer_livre(livre ** debut)
{
    printf("Entrer les informations sur livre que vous voulez supprimer : \n\n");
    livre *tmp , *P , *info;
    info = (livre*) malloc (sizeof(livre));
    tmp = (*debut);
    saiser_informations(&info);
    info->suivant = NULL;
    if((*debut) != NULL)
    {
        if(((*debut)->ID == info->ID) && ((*debut)->titre == info->titre) && ((*debut)->auteur == info->auteur) && ((*debut)->editeur == info->editeur) && ((*debut)->ans_publication == info->ans_publication))
        {
            P = (*debut);
            (*debut) = (*debut)->suivant;
            free(P);
            P = NULL;
        }
        else
        {
            tmp = (*debut);
            while((tmp->suivant != NULL) && ((tmp->suivant->ID != info->ID) || (tmp->suivant->titre != info->titre) || (tmp->suivant->auteur != info->auteur) || (tmp->suivant->editeur != info->editeur) || (tmp->suivant->ans_publication != info->ans_publication))) tmp = tmp->suivant;
            if(tmp->suivant != NULL)
            {
                P = tmp->suivant;
                tmp->suivant = P->suivant;
                free(P);
                P = NULL;
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
            fprintf(fp_1 , "%d \t %s \t %s \t\t  %s \t\t  %d\n" , (tmp->ID) , (tmp->titre) , (tmp->auteur) , (tmp->editeur) , (tmp->ans_publication));
            tmp = tmp->suivant;
        }
        remove(nomFile);
        int n = rename(nomFile_1 , nomFile);
        if(!n) printf("la suppression des informations de livre s'effectue avec succee \n") ;
        else printf("la suppression des informations de livre s'effectue avec echoue \n") ;

        int m = fclose(fp_1);
        if(m) printf("\n\n\.\.\.\.\.\.\.\.\.\.Erreur de fermer le fichier %s\.\.\.\.\.\.\.\.\.\.\. ", nomFile);
}

#endif // FS_H_INCLUDED
