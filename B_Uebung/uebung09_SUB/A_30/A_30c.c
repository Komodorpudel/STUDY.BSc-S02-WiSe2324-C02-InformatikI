#include <stdio.h>
#include <string.h>

int main () {

    /* ++++++++++++++++++++++++++++++++++ */
    /* /* (i) Deklarieren Sie einen Zeiger p, der auf die funfte Komponente eines double-Feldes d zeigt. */
    double d[5];
    double *p = &d[4];


    /* ++++++++++++++++++++++++++++++++++ */
    /* (ii) Deklarieren Sie einen Zeiger p, der auf die erste bin¨are Null in einem char-Feld w zeigt. Sie durfen hierf ¨ ur Bibliotheksfunktionen verwenden. ¨ */

    char w[] = "Beispieltext"; /* Ein char-Array (String) */
    char* p = strchr(w, '\0'); /* p zeigt auf die erste binäre Null in w */


    /* ++++++++++++++++++++++++++++++++++ */
    /* (iii) Schreiben Sie eine Anweisung, die pruft, ob zwei ¨ int-Zeiger p und q auf dieselbe Speicherstelle zeigen. */
    int *p2;
    int *p3;

    if (p2 == p3) {
        printf("Same address");
    }

    else {
        printf("different address");
    }


    /* ++++++++++++++++++++++++++++++++++ */
    /* (iv) Deklarieren Sie einen char-Zeiger p, der nirgendwo hin zeigt. */
    char *p4; /* Zeigt irgendwo hin */
    char *p4 = NULL; /* Zeigt nirgendo hin */


    /* ++++++++++++++++++++++++++++++++++ */
    /* (v) Sei pi eine Variable vom Typ double. Deklarieren Sie einen Zeiger p mit Bezugsvariable pi. */
    double pi = 10;
    double *p5 = &pi;

    /* ++++++++++++++++++++++++++++++++++ */
    /* (vi) Schreiben Sie eine Anweisung, die pruft, ob zwei ¨ int-Zeiger p und q auf den gleichen Wert im Speicher zeigen. */
    int x = 7;
    int y = 7;

    int *p6 = &x;
    int *q = &y;

    if (*p == *q) { /* Ich dereferenziere und vergleiche Wertemiteinander */
        printf("Werte sind gleich");
        
    } else {
        printf("Werte sind unterschiedlich");
        
    }


    /* ++++++++++++++++++++++++++++++++++ */

    return 0;

}

/* ++++++++++++++++++++++++++++++++++ */
/* (vii) Geben Sie den Prototypen einer Funktion fun an, die als Parameter zwei doubleWerte x und y gem¨aß des Call-By-Value-Prinzips erh¨alt und die einen double-Pointer zuruckgibt. ¨ */

double *call_By_Value (double x, double y);


/* ++++++++++++++++++++++++++++++++++ */
/* (viii) Geben Sie den Prototypen einer Funktion fun an, die als Parameter zwei doubleWerte x und y gem¨aß des Call-By-Reference-Prinzips erh¨alt und die einen doubleDoppelpointer zuruckgibt. ¨ */

double **call_By_Reference (double *x, double *y);


/* ++++++++++++++++++++++++++++++++++ */
int ix (void) {
/* (ix) Betrachten Sie die folgende Anweisung: */
char *w = "Hallo!";
/* Welchen Wert hat der Ausdruck *w? */

/* Antwort:
*w hat den Wert 'H' */
}

/* ++++++++++++++++++++++++++++++++++ */
int x (void) {
/* (x) Betrachten Sie die folgenden Anweisungen: */
char *w = "Hallo!";
char *p = w;
/* Welchen Wert hat der Ausdruck *(p++)? */

/* Antwort:
*p würde mir H geben.
(p++) ist Post-Inkrement.
Insofern hat *(p++) den selben Wert wie *p und das ist 'H'
 */
}


/* ++++++++++++++++++++++++++++++++++ */
int xi (void) {
/* (xi) Betrachten Sie die folgenden Anweisungen: */
char *w = "Hallo!";
char *p = w;
/* Welchen Wert hat der Ausdruck *(++p) + 1? */

/* Antwort:
++p erhöht den Zeiger selbst (x13 wird zu x14)
*(++p) gibt mir den Wert 'a'
'a' + 1 = 'b'
 */
}


/* ++++++++++++++++++++++++++++++++++ */
int xii (void) {
/* (xii) Betrachten Sie die folgenden Anweisungen: */
int array[] = {1, 2, 3};
*(array + 2) = 5;
printf("[%i, %i, %i]", array[0], array[1], array[2]);
/* Was ist die Ausgabe der printf-Anweisung? */

/* Antwort:
Die 3 wird zur 5,

Ausgabe: [1, 2, 5]
 */
}


/* ++++++++++++++++++++++++++++++++++ */
int xiii (void) {
/* (xiii) In die folgenden Anweisungen hat sich ein Fehler in der Benutzung von Zeigern oder Feldern eingeschlichten: */
char v[] = "Informatik"; /* btw: Zu Kompilierzeit muss größe bekannt sein */
char w[] = v;
/* Welcher? Was musste man ¨ ¨andern, damit das Programm funktioniert? */

/* Antwort:
/* Array muss initalisiert werden.
Stattdessen: */

char v[] = "Informatik";
char *w = v;

}


/* ++++++++++++++++++++++++++++++++++ */
int xiv (void) {
/* (xiv) In die folgenden Anweisungen hat sich ein Fehler in der Benutzung von Zeigern oder Feldern eingeschlichten: */
char* v;
*v = 'x';
/* Welcher? Was musste man ¨ ¨andern, damit das Programm funktioniert? */

/* Antwort:

v zeigt auf irgendwas weil nicht initialisiert. Lösung: */
char x;
char* v = &x; /* v zeigt jetzt auf x */
*v = 'x';     /* setzt x auf 'x' */
}


/* ++++++++++++++++++++++++++++++++++ */
int xv (void) {
/* (xv) In die folgenden Anweisungen hat sich ein Fehler in der Benutzung von Zeigern oder Feldern eingeschlichten: */
char* v = NULL;
char* w = v;
*w = 'x';
/* Welcher? */

/* Antwort:
An der Adresse von v steht eine NULL und keine Adresse auf die gezeigt wird.

w hat den gleichen Wert wie v, nämlich NULL.

Mit "*w = 'x';" versuche ich an die Adresse NULL zu gehen und dort 'x' zu schreiben. Das geht nicht. Laufzeitfehler.

*/

}
