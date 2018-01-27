#ifndef INDICE_H
#define INDICE_H

#include <stdlib.h>
#include <stdio.h>

/*---------------------------calcul l'indice de coincidence d'un texte de taille taille----------------------------------*/
double indice(char * texte, long taille);


/*calcule le sous texte de fichier qui recupere les lettres à la position multiple de indice, met le resultat dans res*/
/*n est le nombre de sous texte du texte de base*/
void sous_texte_indice(char * res, char * fichier, int taille, int indice, int n);



/*calcule la taille de la cle d'un texte chiffre a l'aide de vigenere*/	
int taille_cle(char * fichier, int taille);


#endif
