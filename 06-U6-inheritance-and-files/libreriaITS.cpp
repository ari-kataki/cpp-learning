#include "libreriaITS.h"

double ottieniDoubleUtente(string messaggio, double valoreMinimo, double valoreMassimo) {
    double doubleUtente = 0;
    string doubleUtenteStringa = "";

    riprova:

    try {
        do {
            cout << messaggio;
            getline(cin, doubleUtenteStringa);
            doubleUtente = stod(doubleUtenteStringa);
        } while (doubleUtente < valoreMinimo || doubleUtente > valoreMassimo);
    }
    catch (...) {
        cout << "Input non valido!\n";
        goto riprova;
    }

    return doubleUtente;
}

int ottieniInteroCasuale(int minimo, int massimo) {
    int risultato = 0;
    int temporaneo = 0;

    if (massimo < minimo) {
        temporaneo = massimo;
        massimo = minimo;
        minimo = temporaneo;
    }

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(minimo, massimo);
    risultato = dist(rng);

    return risultato;
}

int ottieniInteroUtente(string messaggio, int valoreMinimo, int valoreMassimo) {
    int interoUtente = 0;
    string interoUtenteStringa = "";

    riprova:

    try {
        do {
            cout << messaggio;
            getline(cin, interoUtenteStringa);
            interoUtente = stoi(interoUtenteStringa);
        } while (interoUtente < valoreMinimo || interoUtente > valoreMassimo);
    }
    catch (...) {
        cout << "Input non valido!\n";
        goto riprova;
    }

    return interoUtente;
}

string ottieniStringaUtente(string messaggio) {
    string stringaUtente = "";
    cout << messaggio;
    getline(cin, stringaUtente);
    return stringaUtente;
}

list<string> dividi(string stringaOrigine, char delimitatore) {
    list<string> risultato;

    int indiceCorrente = 0, indexInizio = 0, indexFine = 0;

    while (indiceCorrente <= stringaOrigine.length()) {
        if (stringaOrigine[indiceCorrente] == delimitatore || indiceCorrente == stringaOrigine.length()) {
            indexFine = indiceCorrente;
            string sottostringa = "";
            sottostringa.append(stringaOrigine, indexInizio, (indexFine - indexInizio));
            risultato.push_back(sottostringa);
            indexInizio = indexFine + 1;
        }

        indiceCorrente++;
    }

    return risultato;
}

void stampaIntArray(int intArray[], int dimensione) {
    string s = "Array di interi: [";
    for (int i = 0; i < dimensione; i++) {
        s += to_string(intArray[i]);
        if (i < dimensione - 1) {
            s += ", ";
        }
    }
    s += "]\n";
    cout << s;
}

void stampaStringArray(string stringArray[], int dimensione) {
    string s = "Array di stringhe: [";
    for (int i = 0; i < dimensione; i++) {
        s += stringArray[i];
        if (i < dimensione - 1) {
            s += ", ";
        }
    }
    s += "]\n";
    cout << s;
}

// Funzioni per l'ordinamento di elementi all'interno di array di interi
void applicaBubbleSort(int intArray[], int dimensione, bool tipoDiOrdine) {
    bool finito = false;
    int elementoSuperiore = 0;
    int temporaneo = dimensione - 1;

    while (!finito) {
        elementoSuperiore = temporaneo + 1;
        finito = true;
        for (int i = 0; i < elementoSuperiore - 1; i++) {
            if (tipoDiOrdine == ORDINE_CRESCENTE) {
                if (intArray[i] > intArray[i + 1]) {
                    scambiaElemento(&intArray[i], &intArray[i + 1]);
                    temporaneo = i;
                    finito = false;
                }
            }
            else {
                if (intArray[i] < intArray[i + 1]) {
                    scambiaElemento(&intArray[i], &intArray[i + 1]);
                    temporaneo = i;
                    finito = false;
                }
            }
        }
    }
}

void applicaSelectionSort(int intArray[], int dimensione, bool tipoDiOrdine) {
    for (int i = 0; i < dimensione - 1; i++) {
        for (int j = i + 1; j < dimensione; j++) {
            if (tipoDiOrdine == ORDINE_CRESCENTE) {
                if (intArray[i] > intArray[j]) {
                    scambiaElemento(&intArray[i], &intArray[j]);
                }
            }
            else {
                if (intArray[i] < intArray[j]) {
                    scambiaElemento(&intArray[i], &intArray[j]);
                }
            }
        }
    }
}

void scambiaElemento(int* elemento0, int* elemento1) {
    int temporaneo = *elemento0;
    *elemento0 = *elemento1;
    *elemento1 = temporaneo;
}

// Funzioni per la ricerca di elementi all'interno di array di interi
bool applicaRicercaBinaria(int intArray[], int dimensione, int elementoDaRicercare) {
    int indicePrimoElemento = 0;
    int indiceCentro = 0;
    int indiceUltimoElemento = dimensione - 1;
    bool risultato = false;

    while (indicePrimoElemento <= indiceUltimoElemento && !risultato) {
        indiceCentro = (indicePrimoElemento + indiceUltimoElemento) / 2;

        if (intArray[indiceCentro] == elementoDaRicercare) {
            risultato = true;
        }
        else {
            if (intArray[indiceCentro] > elementoDaRicercare) {
                indiceUltimoElemento = indiceCentro - 1;
            }
            else {
                indicePrimoElemento = indiceCentro + 1;
            }
        }
    }

    return risultato;
}

bool applicaRicercaSequenziale(int intArray[], int dimensione, int elementoDaRicercare) {
    bool risultato = false;

    for (int i = 0; i < dimensione; i++) {
        if (intArray[i] == elementoDaRicercare) {
            risultato = true;
            break;
        }
    }

    return risultato;
}