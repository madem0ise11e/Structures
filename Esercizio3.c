#include <stdio.h>
#define MAXLEN 50

struct studente {
char cognome[MAXLEN];
int votoBasso;
int votoAlto;
float mediaVoti;
};

int menu();
void riempiArrayDati(struct studente s[], int n);
void stampaArrayDati(struct studente s[], int n);
void cercaMedia(struct studente s[], int n);

int main() {
  struct studente s[MAXLEN];
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
       	printf (" USCITA \n");
      break;
        default:
          printf (" Scelta non corretta \n");
        break;
      }
    } while (selezione!=4);
    return 0;
}

struct studente riempiDati() {
    struct studente s;
    printf("\nDammi Cognome: ");
    scanf("%s", s.cognome);
    printf("Dammi il voto piu' basso: ");
    scanf("%d", &(s.votoBasso));
    printf("Dammi il voto piu' alto: ");
    scanf("%d", &(s.votoAlto));
    printf("Dammi la media di voti: ");
    scanf("%f", &(s.mediaVoti));
    return s;
}
void riempiArrayDati(struct studente s[], int n){
  int i;
  for(i=0; i<n; ++i){
    s[i] = riempiDati();
  }
}

void stampaArrayDati(struct studente s[], int n){
  int i;
    for(i=0; i<n; ++i){
      printf("Studente %s ha il voto piu' alto %d, voto piu' basso %d, media voti %f\n", s[i].cognome, s[i].votoAlto, s[i].votoBasso, s[i].mediaVoti);
    }
  }

void cercaMedia(struct studente s[], int n){
  int i, largest;
  largest = s[0].mediaVoti;
  for(i=0; i<n; ++i){
    if (largest < s[i].mediaVoti)
    largest = s[i].mediaVoti;
  }
  printf("La media piu' alta e' %d. \n", largest);
}
