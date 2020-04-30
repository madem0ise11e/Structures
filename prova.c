#include <stdio.h>
#define MAXLEN 10
int main(){
  int flag = 1, scelta;
  while (flag>0){
    printf("Scegli che tipo di ricerca vuoi fare (1,2,3): ");
    scanf("%d", &scelta);
    switch(scelta){

    }
    printf("Vuoi continuare? (0=NO, 1=SI)");
    scanf("%d", &flag);
  }
return 0;
}
