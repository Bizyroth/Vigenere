#include "Indice.h"
#include "Cesar.h"



                            /*----------LA CLE DOIT ETRE EN MINUSCULE-----------*/

/*----------chiffre le message clair avec la cle cle et met le resutat dans resultat size_clair et size_cle sont---------------------*/ 
/*-----------------------------------------la taille du clair et de la cle----------------------------------------------*/
void chiffre(char * resultat, char * clair, char * cle, int size_clair, int size_cle){
	int i;
	for(i=0; i<size_clair; i++){
		
		if(clair[i]>64 && clair[i]<91){
			resultat[i]=((clair[i]+cle[i%size_cle]-'A'-'a')%26)+'A';
		}
		else if(clair[i]>96 && clair[i]<123){
			resultat[i]=((clair[i]+cle[i%size_cle]-2*'a')%26)+'a';
		}
		else{
			resultat[i]=clair[i];
		}
	}
}

/*----------dechiffre le message chiffre avec la cle cle et met le resutat dans resultat size_chiffre et size_cle sont-----------------*/ 
/*-----------------------------------------la taille du chiffre et de la cle----------------------------------------------*/
void dechiffre(char * resultat, char * chiffre, char * cle, int size_chiffre, int size_cle){
	int i;
	for(i=0; i<size_chiffre; i++){
		if(chiffre[i]>64 && chiffre[i]<91){
			resultat[i]=((chiffre[i]-cle[i%size_cle]-'A'+'a'+26)%26)+'A';
		}
		else if(chiffre[i]>96 && chiffre[i]<123){
			resultat[i]=((chiffre[i]-cle[i%size_cle]+26)%26)+'a';
		}
		else{
			resultat[i]=chiffre[i];
		}
	}
}

/*renvoie la cle d'un chiffrede vigenere. la taille du texte est taille et celle de la cle size_cle*/
char * trouve_cle(char * chiffre, int taille, int size_cle){
	char * sous_texte[size_cle];
	char * cle=malloc(size_cle+1);	
	int i=0;
	/*allocation de memoire pour les sous texte*/
	for(i=0; i<size_cle; i++){
		sous_texte[i]=malloc(taille);
	}
	
		/*extraction des sous textes*/
	for(i=0; i<size_cle; i++){
		sous_texte_indice(sous_texte[i%size_cle], chiffre, taille, i, size_cle);	
	}
	
	for(i=0; i<size_cle; i++){
		cle[i]=calcule_cle(sous_texte[i], taille);
	}
	cle[size_cle]='\0';
	
	/*desalloue les sous textes*/
		for(i=0; i<size_cle;i++){
			free(sous_texte[i]);
		}
	printf("La cle est: %s\n", cle);
	return cle;
}

