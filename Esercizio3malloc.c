#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50

struct studente {
char cognome[MAXLEN];
int votoBasso;
int votoAlto;
float mediaVoti;
};

int menu();
void riempiArrayDati(struct studente *s[], int n);
void stampaArrayDati(struct studente *s[], int n);
void stampaArrayStudente(struct studente *s);
void cercaMedia(struct studente *s[], int n);
void eliminaStudente(struct studente *s);

int main() {
  struct studente *s[MAXLEN];
  int n, selezione, i;
  printf("Quanti studenti vuoi inserire? ");
  scanf("%d", &n);
  printf("Riempi i dati per gli studenti:\n");
  riempiArrayDati(s, n);


    printf("\n\nProgramma menu a selezione\n");
      do {
      printf("\nDigita il numero corrispondente:\n");
      printf("1 per visualizzare i dati dei %d studenti\n2 per vedere i dati dello studente con la media piu' alta\n4 per uscire\n\n", n);
      printf("Selezione: ");
      scanf("%d", &selezione);
      switch(selezione) {
       case 1:

        printf("\nDati dei %d studenti: \n", n);
        stampaArrayDati(s,n);
          break;
       case 2:
        cercaMedia(s,n);
       break;
       case 4:
       eliminaStudente(s);
       printf (" \n\n USCITA \n");

      break;
        default:
          printf (" Scelta non corretta \n");
        break;
      }
    } while (selezione!=4);

    return 0;
}

void riempiDati(struct studente *s) {

    printf("\nDammi Cognome: ");
    scanf("%s", s->cognome);
    printf("Dammi il voto piu' basso: ");
    scanf("%d", &(s->votoBasso));
    printf("Dammi il voto piu' alto: ");
    scanf("%d", &(s->votoAlto));
    printf("Dammi la media di voti: ");
    scanf("%f", &(s->mediaVoti));

}
void riempiArrayDati(struct studente *s[], int n){
  int i;
  struct studente *p;
  for(i=0; i<n; ++i){
    p= (struct studente *)malloc(sizeof(struct studente));
    s[i] = p;
    riempiDati(p);
  }

}

void stampaArrayDati(struct studente *s[], int n){
  int i;
    for(i=0; i<n; ++i){
      stampaArrayStudente(s[i]);
    }
  }

  void stampaArrayStudente(struct studente *s){
    printf("Studente %s ha il voto piu' alto %d, voto piu' basso %d, media voti %f\n", s->cognome, s->votoAlto, s->votoBasso, s->mediaVoti);
  }


void cercaMedia(struct studente *s[], int n){
  int i, largest, stud=0;
  largest = s[0]->mediaVoti;
  for(i=0; i<n; ++i){
    if (largest < s[i]->mediaVoti){
    largest = s[i]->mediaVoti;
    stud = i;
    }
  }
  stampaArrayStudente(s[stud]);
}
void eliminaStudente(struct studente *s){
	/*
	s= (struct studente *) malloc(sizeof(struct studente));
	s->nome= (char *) malloc(sizeof(char)*MAXLEN);
	s->cognome= (char *) malloc(sizeof(char)*MAXLEN);

	*/

	free(s);
  printf("\nLibero la memoria.");
}
