#ifndef VIGENERE_H
#define VIGENERE_H

           /*----------LA CLE DOIT ETRE EN MINUSCULE-----------*/

/*----------chiffre le message clair avec la cle cle et met le resutat dans resultat size_clair et size_cle sont---------------------*/ 
/*-----------------------------------------la taille du clair et de la cle----------------------------------------------*/
void chiffre(char * resultat, char * clair, char * cle, int size_clair, int size_cle);




/*----------dechiffre le message chiffre avec la cle cle et met le resutat dans resultat size_chiffre et size_cle sont-----------------*/ 
/*-----------------------------------------la taille du chiffre et de la cle----------------------------------------------*/
void dechiffre(char * resultat, char * chiffre, char * cle, int size_chiffre, int size_cle);



/*renvoie la cle d'un chiffrede vigenere. la taille du texte est taille et celle de la cle size_cle*/
char * trouve_cle(char * chiffre, int taille, int size_clezz);




#endif
