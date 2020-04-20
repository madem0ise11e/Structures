#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 100
#define NUMLETTERE 26

int main (void){
  char frase[MAXDIM+1];
  int lung_stringa;
  int vocali, consonanti;
  int contatori[NUMLETTERE];
  int posizione_alfabeto;
  int i;

  //leggi la frase inserita da tastiera
  printf("inserisci una frase di al massimo %d caratteri: ", MAXDIM);
  gets(frase);
  //calcola la lunghezza della frase
  lung_stringa = strlen(frase);
  //stampa la frase inserita
  printf("La frase inserita e': ");
  puts(frase);
  printf("La frase contiene %d caratteri (inclusi gli spazi)\n", lung_stringa);
  //azzera il vettore dei contatori. ogni cella di questo vettore e' associativa
  // a una lettera dell'alfabeto. la cella 0 alla lettera A, la cella 1 alla B e così via
  for(i=0; i<NUMLETTERE; i++)
    contatori[i] = 0;
  //analizza la frase lettera per lettera e aggiorna il vettore dei contatori
  for(i=0; i<lung_stringa; i++){
    if(frase[i] >= 'A' && frase[i] <= 'Z'){
      posizione_alfabeto = frase[i] - 'A';
      contatori[posizione_alfabeto]++;
    } else {  //calcola la lunchezza della frase
        if (frase[i] >= 'a' && frase[i] <= 'z'){
          posizione_alfabeto = frase[i] - 'a';
          contatori[posizione_alfabeto]++;
        }
    }
  }
  //stampa i contatori delle varie lettere
  for(i=0; i<NUMLETTERE; i=i+1)
    printf("La lettura %c compare %d volte\n", 'A'+i, contatori[i]);
    //Calcola il numero di vocali. Somma il numero di occorrenze presenti
    //nel vettore «contatori» nelle celle associate alle lettere A, E, I, O, U, Y
    vocali = contatori['A'-'A'] + contatori['E'-'A'] + contatori['I'-'A']+contatori['O'-'A']+contatori['U'-'A']+contatori['Y'-'A'];
    //Calcola il numero di consonanti. Il numero di consonanti si ottiene sottraendo il numero
    //complessivo di vocali dal numero complessivo di occorrenze di tutte le lettere
    consonanti = 0;
    for (i=0; i<NUMLETTERE; i=i+1)
        consonanti = consonanti + contatori[i];
      consonanti = consonanti - vocali;
    //stampa il numero di vocali e consonanti
      printf("Il numero di vocali e': %d\n", vocali);
      printf("Il numero di consonanti e': %d\n", consonanti);

      exit(0);
}
