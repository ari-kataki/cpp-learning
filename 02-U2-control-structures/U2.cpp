#define ESEMPIO       0
#define ESERCIZIO_1   1
#define ESERCIZIO_2   2
#define ESERCIZIO_3   3
#define ESERCIZIO_4   4
#define ESERCIZIO_5   5
#define ESERCIZIO_6   6
#define ESERCIZIO_7   7
#define ESERCIZIO_8   8
#define ESERCIZIO_10 10
#define ESERCIZIO_9   9
#define ESERCIZIO_11 11
#define ESERCIZIO_12 12
#define ESERCIZIO_13 13
#define ESERCIZIO_14 14
#define ESERCIZIO_15 15
#define ESERCIZIO_16 16

#define ESERCIZIO ESEMPIO

#include <iostream>
#include <cstdint>
#if ESERCIZIO == ESEMPIO
#include <chrono>
#elif ESERCIZIO == ESERCIZIO_2
#include <cstdlib>
#endif

using namespace std;

int main() {
#if ESERCIZIO == ESEMPIO
    // Punto di inizio
    auto inizio = std::chrono::high_resolution_clock::now();
    long long fineContatore = 1000000;

    // Codice da misurare
    for (int i = 0; i < fineContatore; ++i) {
        volatile int x = i * i;
    }

    // Punto di fine
    auto fine = std::chrono::high_resolution_clock::now();

    // Durata in millisecondi
    auto durata = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio);

    cout << "Tempo di esecuzione: " << durata.count() << " millisecondi" << std::endl;
#elif ESERCIZIO == ESERCIZIO_1
    cout << "ESERCIZIO 1\n";
    int numeroUtente{};

    cout << "Inserisci un numero intero: ";
    cin >> numeroUtente;

    if(numeroUtente % 2 == 0) {
        cout << "Il numero inserito dall'utente e' pari" << endl;
    }
    else {
        cout << "Il numero inserito dall'utente e' dispari" << endl;
    }
#elif ESERCIZIO == ESERCIZIO_2
    cout << "ESERCIZIO 2\n";

    int numeroCasuale{};
    int numeroUtente{};

    srand(time(0));
    numeroCasuale = rand() % 10;

    do {
        cout << "Inserisci un numero da 0 a 9: ";
        cin >> numeroUtente;
    } while(numeroUtente < 0 || numeroUtente > 9);

    if(numeroCasuale == numeroUtente) {
        cout << "Il numero inserito e' UGUALE a quello generato (" << numeroCasuale << ")" << endl;
    }
    else {
        cout << "Il numero inserito NON e' UGUALE a quello generato (" << numeroCasuale << ")" << endl;
    }
#elif ESERCIZIO == ESERCIZIO_3
    cout << "ESERCIZIO 3\n";
    int numeroMese{};
    int numeroAnno{};
    int numeroGiorni{};

    do {
        cout << "Inserisci un numero del mese dell'anno (1..12): ";
        cin >> numeroMese;
    } while (numeroMese <= 0 || numeroMese > 12);

    cout << "Inserisci un anno: ";
    cin >> numeroAnno;

    switch (numeroMese) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        numeroGiorni = 31;
        break;
    case 4: case 6: case 9: case 11:
        numeroGiorni = 30;
        break;
    case 2:
        if ((numeroAnno % 4 == 0 && numeroAnno % 100 != 0) || numeroAnno % 400 == 0) {
            numeroGiorni = 29;
        }
        else {
            numeroGiorni = 28;
        }
    }

    cout << "Il numero dei giorni e' " << numeroGiorni << endl;
#elif ESERCIZIO == ESERCIZIO_4
    cout << "ESERCIZIO 4\n";
    int interoUtente{};

    cout << "Inserisci un numero: ";
    cin >> interoUtente;

    cout << "[";
    if (interoUtente > 0) {
        for (int indice{}; indice <= interoUtente; indice++) {
            if (indice < interoUtente) cout << indice << ", ";
            else cout << indice;
        }
    }
    else {
        for (int indice{}; indice >= interoUtente; indice--) {
            if (indice > interoUtente) cout << indice << ", ";
            else cout << indice;
        }
    }
    cout << "]" << endl;
#elif ESERCIZIO == ESERCIZIO_5
    cout << "ESERCIZIO 5\n";
    int n{};
    int k{};
    int risultato{};

    do {
        cout << "Inserisci n (>0): ";
        cin >> n;
    } while (n <= 0);

    do {
        cout << "Inserisci k (>0): ";
        cin >> k;
    } while (k <= 0);

    cout << "Risultato di ";
    for (int indice{1}; indice <= n; indice++) {
        risultato += static_cast<int>(pow(k, indice));

        if (indice < n) cout << k << "^" << indice << " + ";
        else cout << k << "^" << indice << " = ";
    }
    cout << risultato << endl;
#elif ESERCIZIO == ESERCIZIO_8
    cout << "ESERCIZIO 8\n";
    int n{};
    int accumulatore{};
    double media{};

    do {
        cout << "Inserisci n: ";
        cin >> n;
    } while (n <= 0);

    for (int indice{}; indice < n; indice++) {
        int numeroUtente{};
        cout << "Inserisci il numero in posizione " << (indice + 1) << ": ";
        cin >> numeroUtente;

        accumulatore += numeroUtente;
    }

    media = static_cast<double>(accumulatore) / static_cast<double>(n);
    cout << "La media dei numeri inseriti e' " << media << endl;
#elif ESERCIZIO == ESERCIZIO_9
    cout << "ESERCIZIO 9\n";
    double raggio{};
    double perimetro{};
    double area{};

    do {
        cout << "Inserisci il raggio del cerchio: ";
        cin >> raggio;
    } while (raggio <= 0.0);

    perimetro = 2 * M_PI * raggio;
    area = M_PI * pow(raggio, 2);

    cout << "Il perimetro del cerchio e' " << perimetro << endl;
    cout << "L'area del cerchio e' " << area << endl;
#elif ESERCIZIO == ESERCIZIO_10
    cout << "ESERCIZIO 10\n";
    int n{};
    int massimo{INT32_MIN};

    do {
        cout << "Inserisci n: ";
        cin >> n;
    } while (n <= 0);

    for (int indice{}; indice < n; indice++) {
        int numeroUtente{};
        cout << "Inserisci il numero in posizione " << (indice + 1) << ": ";
        cin >> numeroUtente;

        if (massimo < numeroUtente) {
            massimo = numeroUtente;
        }
    }

    cout << "Il numero massimo e' " << massimo << endl;
#elif ESERCIZIO == ESERCIZIO_11
    cout << "ESERCIZIO 11\n";
    double raggio{};
    double altezza{};
    double superficie{};
    double volume{};

    do {
        cout << "Inserisci il raggio del cilindro (cm): ";
        cin >> raggio;
    } while (raggio <= 0);

    do {
        cout << "Inserisci l'altezza del cilindro (cm): ";
        cin >> altezza;
    } while (altezza <= 0);

    superficie = 2 * M_PI * raggio * (raggio + altezza);
    volume = M_PI * pow(raggio, 2) * altezza;

    cout << "La superficie del cilindro e' " << superficie << " cm^2" << endl;
    cout << "Il volume del cilindro e' " << volume << " cm^3" << endl;
#elif ESERCIZIO == ESERCIZIO_12
    cout << "ESERCIZIO 12\n";
    int n{};
    int contaNumeriPari{};
    int contaNumeriDispari{};

    do {
        cout << "Inserisci il numero di interi che vuoi inserire: ";
        cin >> n;
    } while (n <= 0);

    for (int indice{}; indice < n; indice++) {
        int numeroInserito{};
        cout << "Inserisci il numero in posizione " << (indice + 1) << ": ";
        cin >> numeroInserito;

        if (numeroInserito % 2 == 0) {
            contaNumeriPari++;
        }
        else {
            contaNumeriDispari++;
        }
    }

    cout << "Il numero di elementi interi pari inseriti e' " << contaNumeriPari << "\n";
    cout << "Il numero di elementi interi dispari inseriti e' " << contaNumeriDispari << endl;
#elif ESERCIZIO == ESERCIZIO_13
    cout << "ESERCIZIO 13\n";
    int n{};
    long long accumulatore{1};

    do {
        cout << "Inserisci n: ";
        cin >> n;
    } while (n <= 0);

    for (int indice{1}; indice <= n; indice++) {
        accumulatore = accumulatore * static_cast<long long>(indice);
    }

    cout << "Il fattoriale di " << n << " e' " << accumulatore << endl;
#elif ESERCIZIO == ESERCIZIO_14
    cout << "ESERCIZIO 14\n";
    int n{};
    int m{};
    int mcd{};

    do {
        cout << "Inserisci n: ";
        cin >> n;
    } while (n <= 0);

    do {
        cout << "Inserisci m: ";
        cin >> m;
    } while (m <= 0);

    if (m == n) {
        mcd = m;
    }
    else {
        if (m > n) {
            for (int indice{n}; indice >= 1; indice--) {
                if ((m % indice == 0) && (n % indice == 0)) {
                    mcd = indice;
                    break;
                }
            }
        }
        else {
            for (int indice{m}; indice >= 1; indice--) {
                if ((m % indice == 0) && (n % indice == 0)) {
                    mcd = indice;
                    break;
                }
            }
        }
    }

    cout << "L'MCD tra " << m << " e " << n << " e' " << mcd << endl;
#elif ESERCIZIO == ESERCIZIO_15
    cout << "ESERCIZIO 15\n";
    int risultato{};

    for (int indice{3}; indice >= 0; indice--) {
        int bitUtente{};
        do {
            cout << "Inserisci il bit in posizione " << indice << ": ";
            cin >> bitUtente;
        } while (bitUtente < 0 || bitUtente > 1);

        risultato = risultato + static_cast<int>(pow(2, indice)) * bitUtente;
    }

    cout << "La conversione base 10 e' " << risultato << endl;
#elif ESERCIZIO == ESERCIZIO_16
    cout << "ESERCIZIO 16\n";
    int interoUtente{};

    do {
        cout << "Inserisci il numero in base 10: ";
        cin >> interoUtente;
    } while (interoUtente < 0 || interoUtente > 15);

    int bit0{};
    int bit1{};
    int bit2{};
    int bit3{};

    int quoziente{};
    bit3 = interoUtente % 2;
    quoziente = interoUtente / 2;
    bit2 = quoziente % 2;
    quoziente = quoziente / 2;
    bit1 = quoziente % 2;
    quoziente = quoziente / 2;
    bit0 = quoziente % 2;

    cout << "Il numero base 2 di " << interoUtente << " e' " << bit0 << bit1 << bit2 << bit3 << endl;
#endif
    return 0;
}