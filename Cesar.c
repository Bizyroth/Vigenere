#include "Cesar.h"


/*chiffre le message texte avec la cle, taille est la taille du message. Met le resultat dans res*/

void chif_cesar(char * res, char * texte, char cle, int taille){
	int i=0;
	for(i=0; i<taille; i++){
		if(texte[i]>96 && texte[i]<123){
			res[i]=(texte[i]-'a'+cle-'a')%26+'a';
		}
		else if(texte[i]>64 && texte[i]<91 ){
			res[i]=(texte[i]-'A'+cle-'a')%26+'A';
		}
		else{
			res[i]=texte[i];
		}
	}
	return;
}
/*calcule la cle de chiffrement de cesar d'un texte assez long en francais. Renvoie la cle*/
char calcule_cle(char * texte, int taille){
	long na[26]; //nombre de fois qu'une lettre apparaisse
	long nT=0;   // nombre de lettre total
	double frequence[26]; //frequence d'apparition des lettres
	long i=0;
	int lettre_prob=0;   // indice de la lettre la plus probable
	char cle_cesar;
	for(i=0; i<26;i++){
		na[i]=0;
	}
	for(i=0; i<taille; i++){
		if(texte[i]>96 && texte[i]<123){
			na[texte[i]-'a']++;
		}
		else if(texte[i]>64 && texte[i]<91 ){
			na[texte[i]-'A']++;
		}
	}
	
	for(i=0; i<26; i++){
		nT+=na[i];
	}
	for(i=0; i<26; i++){
		frequence[i]=((double)na[i]/(double)nT);
	}
	for(i=1; i<26; i++){
		if(frequence[i]>frequence[lettre_prob]){
			lettre_prob=i;
		}
	}
	//printf("La lettre qui apparait le plus souvent est: %c\n", lettre_prob+'a');
	cle_cesar=lettre_prob+'a'-'e'+'a';
	return cle_cesar;
}

/*dechiffre le message texte avec la cle, taille est la taille du message. Met le resultat dans res*/
void dechif_cesar(char * res, char * texte, char cle, int taille){
	int i=0;
	for(i=0; i<taille; i++){
		if(texte[i]>96 && texte[i]<123){
			res[i]=(texte[i]-cle+26)%26+'a';
		}
		else if(texte[i]>64 && texte[i]<91 ){
			res[i]=(texte[i]-'A'+'a'-cle+26)%26+'A';
		}
		else{
			res[i]=texte[i];
		}
	}
	return;
}

