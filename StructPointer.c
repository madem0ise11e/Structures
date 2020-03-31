struct point p;     /*p è una variabile strutturata di tipo point*/
struct point *pnt;     /*pnt è il puntatore ad una struttura di tipo point*/
pnt=&p;     /*pnt punta a l'indirizzo di p. */ 
(*pnt).x=1;    /*Accedo ai campi x ed y di p tramite il puntatore pnt */
(*pnt).y=0;
pnt->x=2;    /*In maniera equivalente accedo ai campi di p tramite pnt */
pnt->y=3;
Si osservi che l'uso delle parentesi in (*pnt).x
è necessario in quanto la precedenza dell'operatore di campo '.' è superiore a quella di '*'.
L'operatore '->' fornisce, quindi,
un modo di accedere al campo di una struttura
in maniera più “semplice” quando si
fa uso dei puntatori a variabili di tipo struct.
