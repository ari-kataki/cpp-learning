#define ESEMPIO     0
#define ESERCIZIO_1 1
#define ESERCIZIO_2 2
#define ESERCIZIO_3 3
#define ESERCIZIO_4 4
#define ESERCIZIO_5 5
#define ESERCIZIO_6 6
#define ESERCIZIO_7 7 
#define ESERCIZIO_8 8 

#define ESERCIZIO ESERCIZIO_7

#if ESERCIZIO == ESERCIZIO_7
//#define TEST_PUNTATORE
#endif

#include <iostream>
#include <cstdint>
#include <cfloat>

using namespace std;

int calcolaSoluzioniReali(int a, int b, int c, double* risultato1, double* risultato2);
void calcolaSoluzioniSistemaLineare(double a1, double b1, double c1, double a2, double b2, double c2);
bool eseguiComandoEs5(int comando);
bool eseguiComandoEs6(int comando, int valoreMinimo, int valoreMassimo);
#ifdef TEST_PUNTATORE
void gestisciAssegni(double& saldo);
void gestisciPrelevamenti(double& saldo);
void gestisciVersamenti(double& saldo);
#else
double gestisciAssegni();
double gestisciPrelevamenti();
double gestisciVersamenti();
#endif
double ottieniDoubleUtente(string messaggio, double valoreMinimo = -DBL_MAX, double valoreMassimo = DBL_MAX);
int ottieniInteroUtente(string messaggio, int valoreMinimo = INT32_MIN, int valoreMassimo = INT32_MAX);
void stampaMioCarattere(int numero, char carattere);
void stampaQuadrato(int altezza);
void stampaTuttiINumeriTra(int a, int b);
void stampaSomma(int intero1, int intero2);
void stampaTriangolo(int altezza);
void stampaTuttiInteriTra(int a, int b);
void stampaTuttiDispari(int minimo, int massimo);
void stampaTuttiPari(int minimo, int massimo);

int main() {
#if ESERCIZIO == ESEMPIO
    int a = 1;
    int* puntatore = &a;
    int b = *puntatore;
    int* puntatoreHeap = new int (4);

    // Valori
    cout << "Valori" << "\n";
    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    cout << "puntatore: " << puntatore << "\n";
    cout << "valore puntato da puntatore: " << *puntatore << "\n";
    cout << "puntatoreHeap: " << puntatoreHeap << "\n";
    cout << "valore puntato da puntatoreHeap: " << *puntatoreHeap << "\n";

    cout << "\n";

    // Indirizzi
    cout << "Indirizzi" << "\n";
    cout << "a: " << &a << "\n";
    cout << "b: " << &b << "\n";
    cout << "puntatore: " << &puntatore << endl;
    cout << "puntatoreHeap: " << &puntatoreHeap << endl;
#elif ESERCIZIO == ESERCIZIO_1
    cout << "Esercizio 1\n";
    int a = ottieniInteroUtente("Inserisci a: ");
    int b = ottieniInteroUtente("Inserisci b: ", a);

    cout << "Stampa di tutti i numeri tra a e b in ordine decrescente:";
    stampaTuttiINumeriTra(a, b);
#elif ESERCIZIO == ESERCIZIO_2
    cout << "Esercizio 2\n";

    int a = ottieniInteroUtente("Inserisci a: ");
    int b = ottieniInteroUtente("Inserisci b: ");
    int c = ottieniInteroUtente("Inserisci c: ");
    double risultato1{};
    double risultato2{};

    int delta = calcolaSoluzioniReali(a, b, c, &risultato1, &risultato2);

    if(delta == 0) {
        cout << "La soluzione dell'equazione e' " << risultato1 << endl;
    }
    else if(delta > 0) {
        cout << "La soluzione 1 dell'equazione e' " << risultato1 << "\n";
        cout << "La soluzione 2 dell'equazione e' " << risultato2 << endl;
    }
    else {
        cout << "L'equazione non ha soluzioni reali" << endl;
    }
#elif ESERCIZIO == ESERCIZIO_3
    cout << "Esercizio 3\n";

    int comandoUtente{};
    int altezza{};

    do {
        comandoUtente = ottieniInteroUtente("Inserisci un comando (0 = quadrato; 1 = triangolo; 2 = esci): ", 0, 2);

        if(comandoUtente != 2) {
            altezza = ottieniInteroUtente("Inserisci l'altezza del quadrato o triangolo: ", 1);
        }

        switch(comandoUtente) {
            case 0:
                stampaQuadrato(altezza);
            break;

            case 1:
                stampaTriangolo(altezza);
            break;

            default:
                cout << "Programma terminato" << endl;
        }
    } while(comandoUtente != 2);
#elif ESERCIZIO == ESERCIZIO_4
    cout << "ESERCIZIO 4\n";
    int interoUtente1{ottieniInteroUtente("Inserisci il primo numero intero: ")};
    int interoUtente2{ottieniInteroUtente("Inserisci il secondo numero intero (> del primo intero): ", interoUtente1)};

    stampaSomma(interoUtente1, interoUtente2);
#elif ESERCIZIO == ESERCIZIO_5
    cout << "ESERCIZIO 5\n";
    int comandoUtente{};
    bool esitoComando{true};

    do {
        comandoUtente = ottieniInteroUtente("Inserisci un comando (0 = stampa nome e cognome, 1 = stampa data di nascita, 2 = stampa residenza, altrimenti esci): ");
        esitoComando = eseguiComandoEs5(comandoUtente);
    } while (esitoComando == true);
#elif ESERCIZIO == ESERCIZIO_6
    cout << "ESERCIZIO 6\n";
    int comandoUtente{};
    bool esitoComando{true};
    int valoreMinimo{};
    int valoreMassimo{};

    do {
        comandoUtente = ottieniInteroUtente("Inserisci un comando (0 = stampa tutti i numeri tra un valore minimo e un valore massimo, 1 = stampa tutti i numeri pari tra un valore minimo e un valore massimo, 2 = stampa tutti i numeri dispari tra un valore minimo e un valore massimo, altrimenti esci): ");

        if (comandoUtente >= 0 && comandoUtente <= 2) {
            valoreMinimo = ottieniInteroUtente("Inserisci il valore minimo: ");
            valoreMassimo = ottieniInteroUtente("Inserisci il valore massimo: ");
        }

        esitoComando = eseguiComandoEs6(comandoUtente, valoreMinimo, valoreMassimo);
    } while (esitoComando == true);
#elif ESERCIZIO == ESERCIZIO_7
    int comandoUtente{};
    bool esitoComando{true};

    double saldoContoCorrente{ottieniDoubleUtente("Inserisci il saldo iniziale: ")};

    do {
        comandoUtente = ottieniInteroUtente("Inserisci un comando (0 = gestione versamenti, 1 = gestione prelevamenti, 2 = gestione assegni, 3 = saldo finale, 4 = esci): ", 0, 4);

        switch (comandoUtente) {
        case 0:
#ifdef TEST_PUNTATORE
            gestisciVersamenti(saldoContoCorrente);
            cout << "Saldo: " << saldoContoCorrente << endl;
#else
            saldoContoCorrente += gestisciVersamenti();
#endif
            break;
        case 1:
#ifdef TEST_PUNTATORE
            gestisciPrelevamenti(saldoContoCorrente);
            cout << "Saldo: " << saldoContoCorrente << endl;
#else
            saldoContoCorrente -= gestisciPrelevamenti();
#endif
            break;
        case 2:
#ifdef TEST_PUNTATORE
            gestisciAssegni(saldoContoCorrente);
            cout << "Saldo: " << saldoContoCorrente << endl;
#else
            saldoContoCorrente += gestisciAssegni();
#endif
            break;
        case 3:
            cout << "Saldo: " << saldoContoCorrente << endl;
            break;
        default:
            cout << "Programma terminato!";
        }
    } while (comandoUtente != 4);
#elif ESERCIZIO == ESERCIZIO_8
    cout << "ESERCIZIO 8\n";
    double a1{ottieniDoubleUtente("Inserisci a1: ")};
    double b1{ottieniDoubleUtente("Inserisci b1: ")};
    double c1{ottieniDoubleUtente("Inserisci c1: ")};

    double a2{ottieniDoubleUtente("Inserisci a2: ")};
    double b2{ottieniDoubleUtente("Inserisci b2: ")};
    double c2{ottieniDoubleUtente("Inserisci c2: ")};

    calcolaSoluzioniSistemaLineare(a1, b1, c1, a2, b2, c2);
#endif
    
    return 0;
}

int calcolaSoluzioniReali(int a, int b, int c, double* risultato1, double* risultato2) {
    int delta = pow(b, 2) - 4*a*c;

    if(delta == 0) {
        *risultato1 = (-b) / (2.0*a);
        *risultato2 = (-b) / (2.0*a);
    }
    else {
        *risultato1 = (-b + sqrt(static_cast<double>(delta))) / (2.0*a);
        *risultato2 = (-b - sqrt(static_cast<double>(delta))) / (2.0*a);
    }

    return delta;
}

void calcolaSoluzioniSistemaLineare(double a1, double b1, double c1, double a2, double b2, double c2) {
    double x{};
    double y{};

    // Calcolo con il Metodo di Sostituzione
    double determinantePrincipale{((a1 * b2) - (a2 * b1))};
    double determinanteY{((a1 * c2) - (a2 * c1))};

    if (a1 != 0 && determinantePrincipale != 0) {
        y = determinanteY / determinantePrincipale;
        x = (c1 - (b1 * y)) / a1;
        cout << "La soluzione x per il sistema lineare e' " << x << endl;
        cout << "La soluzione y per il sistema lineare e' " << y;
    }
    else {
        cout << "Il sistema lineare ha infinite o nessuna soluzione";
    }
}

bool eseguiComandoEs5(int comando) {
    bool risultatoFunzione{true};

    switch (comando) {
    case 0:
        cout << "Paolo Bicchielli" << endl;
        break;
    case 1:
        cout << "04/05/1989" << endl;
        break;
    case 2:
        cout << "Via Bo, Foligno" << endl;
        break;
    default:
        cout << "Comando non valido!" << endl;
        risultatoFunzione = false;
    }

    return risultatoFunzione;
}

bool eseguiComandoEs6(int comando, int valoreMinimo, int valoreMassimo) {
    bool risultatoFunzione{true};

    switch (comando) {
    case 0:
        stampaTuttiINumeriTra(valoreMinimo, valoreMassimo);
        break;
    case 1:
        stampaTuttiPari(valoreMinimo, valoreMassimo);
        break;
    case 2:
        stampaTuttiDispari(valoreMinimo, valoreMassimo);
        break;
    default:
        cout << "Comando non valido!";
        risultatoFunzione = false;
    }

    return risultatoFunzione;
}

#ifdef TEST_PUNTATORE
void gestisciAssegni(double& saldo) {
    double totaleAssegni{};

    int numeroAssegni{ottieniInteroUtente("Inserisci il numero di assegni effettuati: ", 1)};
    for (int indice{}; indice < numeroAssegni; indice++) {
        double assegnoCorrente{ottieniDoubleUtente("Inserisci il valore dell'assegno: ", 1.0)};
        totaleAssegni += assegnoCorrente;
    }

    saldo += totaleAssegni;
}

void gestisciPrelevamenti(double& saldo) {
    double totalePrelevamenti{};

    int numeroPrelevamenti{ottieniInteroUtente("Inserisci il numero di prelevamenti effettuati: ", 1)};
    for (int indice{}; indice < numeroPrelevamenti; indice++) {
        double prelievoCorrente{ottieniDoubleUtente("Inserisci il valore del prelevamento: ", 1.0)};
        totalePrelevamenti += prelievoCorrente;
    }

    saldo -= totalePrelevamenti;
}

void gestisciVersamenti(double& saldo) {
    double totaleVersamenti{};

    int numeroVersamenti{ottieniInteroUtente("Inserisci il numero di versamenti effettuati: ", 1)};
    for (int indice{}; indice < numeroVersamenti; indice++) {
        double versamentoCorrente{ottieniDoubleUtente("Inserisci il valore del versamento: ", 1.0)};
        totaleVersamenti += versamentoCorrente;
    }

    saldo += totaleVersamenti;
}
#else
double gestisciAssegni() {
    double totaleAssegni{};

    int numeroAssegni{ottieniInteroUtente("Inserisci il numero di assegni effettuati: ", 1)};
    for (int indice{}; indice < numeroAssegni; indice++) {
        double assegnoCorrente{ottieniDoubleUtente("Inserisci il valore dell'assegno: ", 1.0)};
        totaleAssegni += assegnoCorrente;
    }

    return totaleAssegni;
}

double gestisciPrelevamenti() {
    double totalePrelevamenti{};

    int numeroPrelevamenti{ottieniInteroUtente("Inserisci il numero di prelevamenti effettuati: ", 1)};
    for (int indice{}; indice < numeroPrelevamenti; indice++) {
        double prelievoCorrente{ottieniDoubleUtente("Inserisci il valore del prelevamento: ", 1.0)};
        totalePrelevamenti += prelievoCorrente;
    }

    return totalePrelevamenti;
}

double gestisciVersamenti() {
    double totaleVersamenti{};

    int numeroVersamenti{ottieniInteroUtente("Inserisci il numero di versamenti effettuati: ", 1)};
    for (int indice{}; indice < numeroVersamenti; indice++) {
        double versamentoCorrente{ottieniDoubleUtente("Inserisci il valore del versamento: ", 1.0)};
        totaleVersamenti += versamentoCorrente;
    }

    return totaleVersamenti;
}
#endif

double ottieniDoubleUtente(string messaggio, double valoreMinimo, double valoreMassimo) {
    double doubleUtente{};

    do {
        cout << messaggio;
        cin >> doubleUtente;
    } while (doubleUtente < valoreMinimo || doubleUtente > valoreMassimo);

    return doubleUtente;
}

int ottieniInteroUtente(string messaggio, int valoreMinimo, int valoreMassimo) {
    int interoUtente{};

    do {
        cout << messaggio;
        cin >> interoUtente;
    } while(interoUtente < valoreMinimo || interoUtente > valoreMassimo);

    return interoUtente;
}

void stampaMioCarattere(int numero, char carattere) {
    for(int i = 0; i < numero; i++) {
        cout << carattere;
    }
}

void stampaQuadrato(int altezza) {
    for(int i = 0; i < altezza; i++) {
        stampaMioCarattere(altezza, '*');
        cout << endl;
    }
}

void stampaSomma(int intero1, int intero2) {
    int somma{};

    for (int indice{intero1}; indice <= intero2; indice++) {
        somma += indice;
    }

    cout << "La somma dei numeri tra " << intero1 << " e " << intero2 << " e' " << somma;
}

void stampaTriangolo(int altezza) {
    for(int i = 0; i < altezza; i++) {
        stampaMioCarattere(i + 1, '*');
        cout << endl;
    }
}

void stampaTuttiINumeriTra(int a, int b) {
    for(int contatore = b; contatore >= a; contatore--) {
        if(contatore > a) {
            cout << contatore << ", ";
        }
        else {
            cout << contatore << endl;
        }
    }
}

void stampaTuttiPari(int minimo, int massimo) {
    for (int indice{minimo}; indice <= massimo; indice++) {
        if (indice % 2 == 0) {
            cout << indice << ", ";
        }
    }

    cout << endl;
}

void stampaTuttiDispari(int minimo, int massimo) {
    for (int indice{minimo}; indice <= massimo; indice++) {
        if (indice % 2 == 1) {
            cout << indice << ", ";
        }
    }

    cout << endl;
}