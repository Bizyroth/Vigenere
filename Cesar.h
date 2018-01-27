#ifndef CESAR_H
#define CESAR_H

/*chiffre le message texte avec la cle, taille est la taille du message. Met le resultat dans res*/
void chif_cesar(char * res, char * texte, char cle, int taille);


/*calcule la cle de chiffrement de cesar d'un texte assez long en francais. Renvoie la cle*/
char calcule_cle(char * texte, int taille);

/*dechiffre le message texte avec la cle, taille est la taille du message. Met le resultat dans res*/
void dechif_cesar(char * res, char * texte, char cle, int taille);

#endif
