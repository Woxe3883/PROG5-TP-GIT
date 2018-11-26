#include "fap.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define TAILLE_BUFFER 128

void aide()
{
  fprintf(stderr,"Aide :\n");
  fprintf(stderr,"Saisir l'une des commandes suivantes\n");
  fprintf(stderr,"\n");
  fprintf(stderr,"i nombre priorite  :   inserer un nombre avec sa priorite\n");
  fprintf(stderr,"e                  :   extraire le nombre de priorite maximale\n");
  fprintf(stderr,"v                  :   teste si la fap est vide\n");
  fprintf(stderr,"h                  :   afficher cette aide\n");
  fprintf(stderr,"q                  :   quitter ce programme\n");
}
//STRUCTURE QUI EXTRAIT LE MIN EN PRIO
/*
int compa_croissant(int *a, int *b){
	if(*a < *b)return 1;
	return 0;
}*/

//STRUCTURE QUI EXTRAIT LE MAX EN PRIO
/*
int compa_decroissant(int *a, int *b){
	if(*a < *b)return 0;
	return 1;
}*/

//STRUCTURE QUI EXTRAIT LE DERNIER ELEMENT INSERE EN PRIO (=PILE)

int compa_1(int *a, int *b){
	return 1;
}
//STRUCTURE QUI EXTRAIT LE PREMIER ELEMENT INSERE EN PRIO (=FILE)

int compa_0(int *a, int *b){
	return 0;
}

//STRUCTURE QUI EXTRAIT AU HASARD
/*
int compa_0_ou_1(int *a, int *b){
	int srand=time(NULL);
	return rand()%2;
}*/
		
int main()
{
  char buffer[TAILLE_BUFFER];
  char commande;
  int nombre,priorite;
  fap f,f1;

  f = creer_fap_vide(compa_1);
  f1 = creer_fap_vide(compa_0);
  aide();
  while (1)
    {
      commande = getchar();
      switch (commande)
        {
        case 'i':
          scanf ("%d",&nombre);
          scanf ("%d",&priorite);
          f = inserer(f,nombre,priorite);
		  printf("(%d,%d) a ete insere\n",nombre,priorite);
		  f1 = inserer(f1,nombre,priorite);
          printf("(%d,%d) a ete insere\n",nombre,priorite);
          break;
        case 'e':
          if (!est_fap_vide(f) && !est_fap_vide(f1))
            {
              f = extraire(f,&nombre,&priorite);
			  printf("(%d,%d) a ete extrait\n",nombre,priorite);
			  f1 = extraire(f1,&nombre,&priorite);
			  printf("(%d,%d) a ete extrait\n",nombre,priorite);
		  }else{
              printf("La fap 1 est vide !\n");
		      printf("La fap 2 est vide !\n");
		  }
          break;
        case 'v':
          printf("Est_fap_vide a retourne %d\n",est_fap_vide(f));
		  printf("Est_fap_vide a retourne %d\n",est_fap_vide(f1));
          break;
        case 'h':
          aide();
          break;
        case 'q':
          detruire_fap(f);
		  detruire_fap(f1);
          exit(0);
        default:
          fprintf(stderr,"Commande inconnue !\n");
        }
      /* vide ce qu'il reste de la ligne dans le buffer d'entree */
      fgets(buffer,TAILLE_BUFFER,stdin);
    }
  detruire_fap(f);
  detruire_fap(f1);
  return 0;
}
