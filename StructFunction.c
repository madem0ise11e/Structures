#include <stdio.h>

struct point {
      int x;
      int y;
};

struct point creaPunto(int x,int y);
void stampaPunto(struct point p);
struct point sommaPunti(struct point p1,struct point p2);

int main() {
  struct point p1, p2, p;
  int x,y;
  printf("Dammi le coordinate del primo punto: ");
  scanf("%d %d", &x, &y);
  p1=creaPunto(x,y);
  printf("Dammi le coordinate del secondo punto:");
  scanf("%d %d",&x,&y);
  p2=creaPunto(x,y);
  p=sommaPunti(p1,p2);
  printf("Primo e secondo punto:\n");
  stampaPunto(p1);
  stampaPunto(p2);
  printf("Somma dei punti:\n");
  stampaPunto(p);
return 0;
}

struct point creaPunto(int x,int y){
  struct point p;
  p.x = x;
  p.y = y;
  return p;
}

void stampaPunto(struct point p){
  printf("x= %d  y= %d\n", p.x,p.y);
}

struct point sommaPunti(struct point p1, struct point p2){
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}
