#include "files.h"

/*calcul la taille d'un fichier*/
long taille_fichier(char * nom){
	struct stat tamp;
	long res;
		if(stat(nom, &tamp)<0){
		 printf("Erreur lors de l'ouverture du fichier verifier le nom\n");
		 return -1;
		}
	res=(long)tamp.st_size;
	return res;
}

/*renvoie le contenu du fichier nom de taille taille*/
char* lis_fichier(char * nom, long taille){

	char * file=malloc(sizeof(char)*taille);
	int d=open(nom,O_RDONLY);	
	int i=0;
	int k=0;
	char tampon[64];
	int r;
	while((r=read(d, tampon, 64))>0){
		for(k=0; k<r; k++){
			file[i]=tampon[k];
			i++;
		}
		k=0;
	}
	close(d);
	return file;
}

/*ecris dans le fichier nom, le contenu de chaine*/

void ecris(const char * nom, char * chaine, int taille_chaine){

		int desc=open(nom, O_RDWR | O_CREAT |O_TRUNC, 00777);
		write(desc, chaine, taille_chaine-1); 
		close(desc);
		
}
		
		
		
		
		
		
		
		
		
		
		

