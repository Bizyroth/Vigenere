#include "Vigenere.h"
#include "Cesar.h"
#include "files.h"
#include "Indice.h"
#include <string.h>

int main(){
	printf("*------------------------------------------------*\n");
	printf("|                                                |\n");
	printf("|                   VIGENERE                     |\n");
	printf("|                                                |\n");
	printf("*------------------------------------------------*\n");
	char nom[64];
	printf("Entrez le nom du fichier à ouvrir\n");
	scanf("%s", nom);
	getchar();
	long taille=taille_fichier(nom);
	if(taille==-1){
		return 0;
	}
	char *fichier=malloc(taille-1);
	char * chiffr=malloc(taille-1);
	fichier=lis_fichier(nom, taille);
	char cle[64];
	int size_key=0;
	printf("Voulez vous: \n");
	printf("Dechiffrer le message? --> 1\n");
	printf("Chiffre le message? -----> 2\n");
	char in;
	scanf("%c", &in);
	getchar();
	if(in=='2'){
		printf("Entrez la cle de chiffrement (en minuscule pls!\n");
		scanf("%s", cle);
		getchar();
		chiffre(chiffr, fichier, cle, taille, strlen(cle));
		ecris("chiffre.txt", chiffr, taille);
		printf("Le texte chiffre a ete place dans le fichier chiffre.txt du repertoire courant\n");
	}
	else if(in=='1'){
		size_key=taille_cle(fichier, taille);
		char * key=malloc(size_key);
		key=trouve_cle(fichier, taille, size_key);
		dechiffre(chiffr, fichier, key, taille, size_key);
		ecris("dechiffre.txt", chiffr, taille);
		printf("Le fichier dechiffre a ete place dans dechiffre.txt dans le repertoire courant\n");
	}	
	else{
		printf("tu as taper %c\n", in);
		printf("C'est 1 ou 2 abruti\n");
	}
	return 0;
}
