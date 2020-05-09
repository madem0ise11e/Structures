#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARTE 52
#define FACCIE 13

struct carta {
  const char *faccia;
  const char *tuta;
};

typedef struct carta Carte;

void RiempiMazzo(Carte * const wMazzo, const char * wFaccia[], const char * wTuta[]);
void MischiaCarte(Carte * const wMazzo);
void DistribuisciCarte(const Carte * const wMazzo);

int main(void){
  Carte mazzo[CARTE]; //definito l'array di Carte
  //inizializzo  array di puntatori
  const char *faccia[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
  const char *tuta[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  srand (time(NULL)); //randomizzo
  RiempiMazzo(mazzo, faccia, tuta);
  MischiaCarte(mazzo);
  DistribuisciCarte(mazzo);
}

void RiempiMazzo(Carte * const wMazzo, const char * wFaccia[], const char * wTuta[]){
  size_t i;
  //effettuo un un'iterazione attraverso wMazzo
  for (size_t i = 0; i < CARTE; ++i) {
    wMazzo[i].faccia = wFaccia[i % FACCIE];
    wMazzo[i].tuta = wTuta[i / FACCIE];
  }
}

void MischiaCarte(Carte * const wMazzo){
  size_t i;
  size_t j; //valore per memorizzare un valore casuale da 0 a 52
  Carte temp; //definito una strutura temporanea per scambiare le carte

  //effettuo un'iterazione attraverso wMazzo scambaindo le carte
  for (size_t i = 0; i < CARTE; ++i) {
    j = rand() % CARTE;
    temp = wMazzo[i];
    wMazzo[i] = wMazzo[j];
    wMazzo[j] = temp;
  }
}

void DistribuisciCarte(const Carte * const wMazzo){
  size_t i;
  //effettuo un un'iterazione attraverso wMazzo
  for (size_t i = 0; i < CARTE; ++i) {
    printf("%5s of %-8s%s", wMazzo[i].faccia, wMazzo[i].tuta, (i+1) % 4 ? " " : "\n");
  }
}
