#include "Indice.h"
/*---------------------------calcul l'indice de coincidence d'un texte de taille taille----------------------------------*/
double indice(char * texte, long taille){
	long na[26];
	long nT=0;
	double ind=0;
	long i=0;
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
		//printf("na de %c vaut %lu \n", (int)i+97, na[i]);
		nT+=na[i];
	}
	//printf("n de T vaut %lu\n", nT);
	for(i=0; i<26; i++){
		ind+= ((float)(na[i]*(na[i]-1)))/((float)(nT*(nT-1)));
	}
	return ind;
}
/*calcule le sous texte de fichier qui recupere les lettres à la position multiple de indice, met le resultat dans res*/
/*n est le nombre de sous texte du texte de base*/
void sous_texte_indice(char * res, char * fichier, int taille, int indice, int n){
	int i=0;
	int c=0;
	for(i=0; i<taille; i++){
		if(i%n==indice){
			res[c]=fichier[i];
			c++;
		}
	}
	return ;
}
/*calcule la taille de la cle d'un texte chiffre a l'aide de vigenere*/	
int taille_cle(char * fichier, int taille){
	int n=1;
	int i=0;
	int res;
	double moyenne_id=0;
	while(res!=n && n<taille){
		moyenne_id=0;
		res=0;	
		char * sous_texte[n];           						//tableau des sous texte
		double* indi=malloc(n*sizeof(double));					//tableau des indices de chaque sous texte
		
		/*allocation de memoire pour les sous texte*/
		for(i=0; i<n; i++){
			sous_texte[i]=malloc(taille);
		}
		
		/*extraction des sous textes*/
		for(i=0; i<n; i++){
			sous_texte_indice(sous_texte[i%n], fichier, taille, i, n);
			
		}
		
		/*calcule des indice de coincidence des sous texte*/
		for(i=0; i<n; i++){
			indi[i]=indice(sous_texte[i], taille/n);
			moyenne_id+=indi[i];
		}
		moyenne_id/=n;
//		printf("Lindice pour n=%d est %f\n",i, moyenne_id);
		/*comparaison des indice calcules avec celui de la langue francaise*/
		for(i=0; i<n; i++){
			if(moyenne_id<0.085 && moyenne_id>0.06){
				res++;
			}
		}
		/*desalloue les sous textes*/
		for(i=0; i<n;i++){
			free(sous_texte[i]);
		}
		
		free(indi);
		if(res!=n){
			n++;
		}
	}
	if(res==n){
		printf("La longueur de la cle est %d\n", n);
	}
	return n;
}
