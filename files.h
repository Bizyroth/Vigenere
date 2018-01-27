#define _POSIX_C_SOURCE 200112L
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*calcul la taille d'un fichier*/
long taille_fichier(char * nom);


/*renvoie le contenu du fichier nom de taille taille*/
char* lis_fichier(char * nom, long taille);

/*ecris dans le fichier nom, le contenu de chaine*/

void ecris(const char * nom, char * chaine, int taille_chaine);
