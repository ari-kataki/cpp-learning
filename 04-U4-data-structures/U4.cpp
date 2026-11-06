#define ESEMPIO      0
#define ESERCIZIO_1  1
#define ESERCIZIO_2  2
#define ESERCIZIO_3  3
#define ESERCIZIO_4  4
#define ESERCIZIO_5  5
#define ESERCIZIO_6  6
#define ESERCIZIO_7  7 
#define ESERCIZIO_8  8 
#define ESERCIZIO_9  9
#define ESERCIZIO_10 10
#define ESERCIZIO_11 11

#define ESERCIZIO ESERCIZIO_11

#define ARRAY  0
#define VECTOR 1
#define LIST   2

#define TIPO_ESERCIZIO ARRAY

#define DIMENSIONE_MASSIMA 512
#define M_PI 3.14

#if ESERCIZIO == ESEMPIO
#include <chrono>
#endif
#include <iostream>
#include <cstdint>
#include <list>
#include <string>
#include <random>
#include <vector>
#include <cfloat>
#include <climits>

using namespace std;

bool applicaRicercaSequenziale(int arrayInteri[], int dimensione, int elementoDaCercare);
int convertiInBinario(int numeroDaConvertire, int arrayDiBit[]);
void modificaOrdinaArray(int arrayDiInteri[], int dimensione);
double ottieniDoubleUtente(string messaggio, double valoreMinimo = -DBL_MAX, double valoreMassimo = DBL_MAX);
int ottieniInteroCasuale(int minimo, int massimo);
int ottieniInteroUtente(string messaggio, int valoreMinimo = INT32_MIN, int valoreMassimo = INT32_MAX);
string ottieniStringaUtente(string messaggio);
int riempiArrayDoppioni(int arrayDiInteri[], int dimensioneArrayInteri, int arrayDiInteriDoppioni[]);
void stampaIntArray(int arrayInteri[], int dimensione);
void stampaStringArray(string arrayStringhe[], int dimensione);

#if ESERCIZIO == ESERCIZIO_11
struct Display {
    string marca = "";
    string modello = "";
    int altezza = 0;
    int larghezza = 0;
    char** pixel = nullptr;
};

const char C_FONT[2][5][6] {
  {
    " *** ",
    "*   *",
    "   * ",
    "  *  ",
    "*****",
  },
  {
    "  *  ",
    "***  ",
    "  *  ",
    "  *  ",
    "*****",
  },
};

void disegnaDisplay(Display& display);
void inizializzaDisplay(Display& display);
void resetDisplay(Display& display);
void settaCarattereDisplay(Display& display, int indiceCarattere, int x, int y);
#endif

int main() {
#if ESERCIZIO == ESEMPIO
    const int N = 100000;

    // Misura il tempo per array
    {
        int* a = new int[N];
        auto inizio = chrono::high_resolution_clock::now();

        // Riempimento di elementi nell'array
        for(int i = 0; i < N; i++) {
            a[i] = i;
        }

        // Lettura di elementi nell'array
        long long somma{};
        for(int i = 0; i < N; i++) {
            somma += a[i];
        }

        auto fine = chrono::high_resolution_clock::now();
        chrono::duration<double> durata = fine - inizio;
        cout << "Durata array:\t" << durata.count() << "secondi\n";
        delete[] a;
    }

    // Misura il tempo per vector
    {
        vector<int> v;
        auto inizio = chrono::high_resolution_clock::now();

        // Inserimento di elementi nel vettore
        for(int i = 0; i < N; i++) {
            //v.push_back(i);
            v.insert(v.begin(), i);
        }

        // Lettura di elementi nel vettore
        long long somma{};
        for(int i = 0; i < N; i++) {
            somma += v[i];
        }

        // Rimozione di elementi nel vettore
        for(int i = 0; i < N; i++) {
            //v.pop_back();
            v.erase(v.begin());
        }

        auto fine = chrono::high_resolution_clock::now();
        chrono::duration<double> durata = fine - inizio;
        cout << "Durata vector:\t" << durata.count() << "secondi\n";
    }

    // Misura il tempo per list
    {
        list<int> l;
        auto inizio = chrono::high_resolution_clock::now();

        // Inserimento di elementi nella lista
        for(int i = 0; i < N; i++) {
            //l.push_back(i);
            l.push_front(i);
        }

        // Lettura di elementi nella lista
        long long somma{};
        for(auto iteratore = l.begin(); iteratore != l.end(); iteratore++) {
            somma += *iteratore;
        }

        // Rimozione di elementi nella lista
        for(int i = 0; i < N; i++) {
            //l.pop_back();
            l.pop_front();
        }

        auto fine = chrono::high_resolution_clock::now();
        chrono::duration<double> durata = fine - inizio;
        cout << "Durata list:\t" << durata.count() << "secondi\n";
    }
#elif ESERCIZIO == ESERCIZIO_1
#if TIPO_ESERCIZIO == ARRAY
    int* arrayDiBit = new int[DIMENSIONE_MASSIMA];
    int n = ottieniInteroUtente("Inserisci un numero di bit (<= " + to_string(DIMENSIONE_MASSIMA) + "): ", 1, DIMENSIONE_MASSIMA);
    long long numeroBase10{};

    // Riempimento array
    for(int i = 0; i < n; i++) {
        int bitUtente = ottieniInteroUtente("Inserisci il bit in posizione " + to_string(i) + ": ", 0, 1);
        arrayDiBit[i] = bitUtente;
    }

    // Calcolo numero base 10
    for(int i = 0; i < n; i++) {
        numeroBase10 += pow(2.0, i) * arrayDiBit[i];
    }

    // Stampa della sequenza di bit e del numero base 10
    cout << "La sequenza di bit dell'utente e': ";
    for(int i = n - 1; i >= 0; i--) {
        cout << arrayDiBit[i];
    }
    cout << "\nIl numero base 10 e': " << numeroBase10 << endl;
#elif TIPO_ESERCIZIO == VECTOR
    vector<int> vettoreDiBit;
    int n = ottieniInteroUtente("Inserisci un numero di bit (<= " + to_string(DIMENSIONE_MASSIMA) + "): ", 1, DIMENSIONE_MASSIMA);
    long long numeroBase10{};

    // Riempimento vettore
    for(int i = 0; i < n; i++) {
        int bitUtente = ottieniInteroUtente("Inserisci il bit in posizione " + to_string(i) + ": ", 0, 1);
        vettoreDiBit.push_back(bitUtente);
    }

    // Calcolo numero base 10
    for(int i = 0; i < n; i++) {
        numeroBase10 += pow(2.0, i) * vettoreDiBit[i];
    }

    // Stampa della sequenza di bit e del numero base 10
    cout << "La sequenza di bit dell'utente e': ";
    for(int i = n - 1; i >= 0; i--) {
        cout << vettoreDiBit[i];
    }
    cout << "\nIl numero base 10 e': " << numeroBase10 << endl;
#elif TIPO_ESERCIZIO == LIST
    list<int> listaDiBit;
    int n = ottieniInteroUtente("Inserisci un numero di bit (<= " + to_string(DIMENSIONE_MASSIMA) + "): ", 1, DIMENSIONE_MASSIMA);
    long long numeroBase10{};

    // Riempimento lista
    for(int i = 0; i < n; i++) {
        int bitUtente = ottieniInteroUtente("Inserisci il bit in posizione " + to_string(i) + ": ", 0, 1);
        listaDiBit.push_back(bitUtente);
    }

    // Calcolo numero base 10
    int indice{};
    for(auto i = listaDiBit.begin(); i != listaDiBit.end(); i++) {
        numeroBase10 += pow(2.0, indice) * (*i);
        indice++;
    }

    // Stampa della sequenza di bit e del numero base 10
    cout << "La sequenza di bit dell'utente e': ";
    for(auto i = listaDiBit.begin(); i != listaDiBit.end(); i++) {
        cout << *i;
    }
    cout << "\nIl numero base 10 e': " << numeroBase10 << endl;
#endif
#elif ESERCIZIO == ESERCIZIO_2
    int arrayDiBit[DIMENSIONE_MASSIMA]{};
    int numeroUtente{ottieniInteroUtente("Inserisci un intero base 10: ")};
    int contatore{convertiInBinario(numeroUtente, arrayDiBit)};

    cout << "La conversione binaria del numero " << numeroUtente << " e': ";
    for (int indice{contatore}; indice >= 0; indice--) {
        cout << arrayDiBit[indice];
    }
    cout << endl;
#elif ESERCIZIO == ESERCIZIO_3
    string nome{ottieniStringaUtente("Inserisci il tuo nome: ")};
    string cognome{ottieniStringaUtente("Inserisci il tuo cognome: ")};

    cout << "Dati utente: Nome -> " << nome << "; Cognome -> " << cognome << "\n";

    char primoCarattereNome{nome[0]};
    primoCarattereNome = tolower(primoCarattereNome);
    char primoCarattereCognome{cognome[0]};
    primoCarattereCognome = tolower(primoCarattereCognome);

    if (primoCarattereNome == 'a' || primoCarattereNome == 'e' ||
        primoCarattereNome == 'i' || primoCarattereNome == 'o' ||
        primoCarattereNome == 'u' || primoCarattereNome == 'y') {
        cout << "Il tuo nome inizia con una vocale";
    }
    else {
        cout << "Il tuo nome inizia con una consonante";
    }

    cout << endl;

    if (primoCarattereCognome == 'a' || primoCarattereCognome == 'e' ||
        primoCarattereCognome == 'i' || primoCarattereCognome == 'o' ||
        primoCarattereCognome == 'u' || primoCarattereCognome == 'y') {
        cout << "Il tuo cognome inizia con una vocale" << endl;
    }
    else {
        cout << "Il tuo cognome inizia con una consonante" << endl;
    }
#elif ESERCIZIO == ESERCIZIO_4
    int n{ottieniInteroUtente("Inserisci la dimensione dell'array: ", 0, 100)};
    int* arrayDiInteri{new int[n]};

    for (int indice{}; indice < n; indice++) {
        arrayDiInteri[indice] = ottieniInteroCasuale(0, 1000);
    }

    stampaIntArray(arrayDiInteri, n);

    int contaPari{};
    int contaDispari{};
    for (int indice{}; indice < n; indice++) {
        if (arrayDiInteri[indice] % 2 == 0) {
            contaPari++;
        }
        else {
            contaDispari++;
        }
    }

    cout << "Il numero di elementi pari e' " << contaPari << endl;
    cout << "Il numero di elementi dispari e' " << contaDispari;
#elif ESERCIZIO == ESERCIZIO_5
    int comandoUtente{INT32_MIN};

    int base{};
    int altezza{};
    double raggio{};
    double perimetro{};
    double area{};

    vector<int> vettoreComandi;

    do {
        comandoUtente = ottieniInteroUtente("Inserisci un comando (0 = triangolo, 1 = rettangolo, 2 = cerchio): ");

        switch (comandoUtente) {
        case 0:
            base = ottieniInteroUtente("Inserisci la base del trinagolo: ");
            altezza = ottieniInteroUtente("Inserisci l'altezza del trinagolo: ");
            area = static_cast<double>(base * altezza) / 2.0;
            cout << "Area del triangolo: " << area << endl;
            system("pause");
            system("cls");
            vettoreComandi.push_back(comandoUtente);
            break;
        case 1:
            base = ottieniInteroUtente("Inserisci la base del rettangolo: ");
            altezza = ottieniInteroUtente("Inserisci l'altezza del rettangolo: ");
            perimetro = static_cast<double>(base + altezza) * 2;
            area = static_cast<double>(base * altezza);
            cout << "Perimetro del rettangolo: " << perimetro << "\n";
            cout << "Area del rettangolo: " << area << "\n";
            system("pause");
            system("cls");
            vettoreComandi.push_back(comandoUtente);
            break;
        case 2:
            raggio = ottieniDoubleUtente("Inserisci il raggio del cerchio: ", 0.0);
            perimetro = 2.0 * M_PI * raggio;
            area = M_PI * pow(raggio, 2);
            cout << "Perimetro del cerchio: " << perimetro << "\n";
            cout << "Area del cerchio: " << area << "\n";
            system("pause");
            system("cls");
            vettoreComandi.push_back(comandoUtente);
            break;
        default:
            cout << "Comando non valido\n";
        }
    } while (comandoUtente >= 0 && comandoUtente <= 2);

    cout << "Elenco dei comandi richiesti: [";
    for (int indice{}; indice < vettoreComandi.size(); indice++) {
        if (indice < vettoreComandi.size() - 1) {
            cout << to_string(vettoreComandi[indice]) + ", ";
        }
        else {
            cout << to_string(vettoreComandi[indice]) + "]";
        }
    }
#elif ESERCIZIO == ESERCIZIO_6
    int arrayDiInteri[DIMENSIONE_MASSIMA]{};
    int n{ottieniInteroUtente("Inserisci il numero di elementi da inserire: ", 1, DIMENSIONE_MASSIMA)};

    for (int indice{}; indice < n; indice++) {
        int numeroUtente{ottieniInteroUtente("Inserisci un intero in posizione " + to_string(indice + 1) + ": ")};
        arrayDiInteri[indice] = numeroUtente;
    }

    system("cls");
    int comandoUtente{};
    do {
        stampaIntArray(arrayDiInteri, n);
        comandoUtente = ottieniInteroUtente("Inserisci un comando (da 0 a 7): ", 0, 7);
        int somma{};
        string stringaDiLavoro{};
        int interoUtenteDaCercare{};
        bool risultato{};
        int risultatoContatore{};

        switch (comandoUtente) {
        case 0:
            for (int indice{}; indice < n; indice++) {
                somma += arrayDiInteri[indice];
            }
            cout << "La somma degli elementi e' " << somma << endl;
            break;
        case 1:
            stringaDiLavoro = "Array di interi inverso: [";
            for (int indice{n - 1}; indice >= 0; indice--) {
                stringaDiLavoro += to_string(arrayDiInteri[indice]);
                if (indice > 0) stringaDiLavoro += ", ";
            }
            stringaDiLavoro += "]\n";
            cout << stringaDiLavoro;
            break;
        case 2:
            stringaDiLavoro = "Elementi di indice pari: ";
            for (int indice{}; indice < n; indice++) {
                if (indice % 2 == 0) {
                    stringaDiLavoro += to_string(arrayDiInteri[indice]) + " ";
                }
            }
            stringaDiLavoro += "\n";
            cout << stringaDiLavoro;
            break;
        case 3:
            stringaDiLavoro = "Elementi dispari: ";
            for (int indice{}; indice < n; indice++) {
                if (arrayDiInteri[indice] % 2 == 1) {
                    stringaDiLavoro += to_string(arrayDiInteri[indice]) + " ";
                }
            }
            stringaDiLavoro += "\n";
            cout << stringaDiLavoro;
            break;
        case 4:
            interoUtenteDaCercare = ottieniInteroUtente("Inserisci un intero");
            risultato = false;
            for (int indice{}; indice < n; indice++) {
                if (arrayDiInteri[indice] == interoUtenteDaCercare) {
                    risultato = true;
                    break;
                }
            }
            if (risultato) {
                cout << "L'elemento " << interoUtenteDaCercare << " e' stato trovato!" << endl;
            }
            else {
                cout << "L'elemento " << interoUtenteDaCercare << " NON e' stato trovato!" << endl;
            }
            break;
        case 5:
            interoUtenteDaCercare = ottieniInteroUtente("Inserisci un intero: ");
            risultatoContatore = 0;
            for (int indice{}; indice < n; indice++) {
                if (arrayDiInteri[indice] == interoUtenteDaCercare) {
                    risultatoContatore++;
                }
            }
            if (risultatoContatore > 0) {
                cout << "L'elemento " << interoUtenteDaCercare << " e' presente " << risultatoContatore << " volte!" << endl;
            }
            else {
                cout << "L'elemento " << interoUtenteDaCercare << " NON e' stato trovato!" << endl;
            }
            break;
        case 6:
            risultato = true;
            for (int indice{}; indice < n - 1; indice++) {
                if (arrayDiInteri[indice] > arrayDiInteri[indice + 1]) {
                    risultato = false;
                    break;
                }
            }
            if (risultato) {
                cout << "L'array e' ordinato in maniera crescente!" << endl;
            }
            else {
                cout << "L'array NON e' ordinato in maniera crescente!" << endl;
            }
            break;
        default:
            cout << "Programma terminato!" << endl;
        }

        system("pause");
        system("cls");
    } while (comandoUtente < 7);
#elif ESERCIZIO == ESERCIZIO_7
    string arrayDiStringhe[DIMENSIONE_MASSIMA]{};
    int n{ottieniInteroUtente("Inserisci il numero di elementi da inserire: ", 1, DIMENSIONE_MASSIMA)};

    for (int indice{}; indice < n; indice++) {
        string stringaUtente{ottieniStringaUtente("Inserisci una stringa in posizione " + to_string(indice + 1) + ": ")};
        arrayDiStringhe[indice] = stringaUtente;
    }

    system("cls");
    int comandoUtente{};
    int contatoreComandi{};
    do {
        stampaStringArray(arrayDiStringhe, n);
        comandoUtente = ottieniInteroUtente("Inserisci un comando (da 0 a 6): ", 0, 6);
        string stringaDiLavoro{};
        int indiceUtente{};
        bool risultato{};
        int risultatoContatore{};
        char carattereUtente{};

        switch (comandoUtente) {
        case 0:
            for (int indice{}; indice < n; indice++) {
                if (arrayDiStringhe[indice].length() > stringaDiLavoro.length()) {
                    stringaDiLavoro = arrayDiStringhe[indice];
                }
            }
            cout << "La stringa piu' lunga e': " << stringaDiLavoro << endl;
            contatoreComandi++;
            break;
        case 1:
            for (int indice{}; indice < n; indice++) {
                if (indice % 2 == 0) {
                    stringaDiLavoro += arrayDiStringhe[indice];
                }
            }
            cout << "La stringa di concatenazione degli elementi di indice pari e': " << stringaDiLavoro << endl;
            contatoreComandi++;
            break;
        case 2:
            do {
                stringaDiLavoro = ottieniStringaUtente("Inserisci un carattere: ");
            } while (stringaDiLavoro.length() > 1);

            carattereUtente = stringaDiLavoro[0];
            cout << "Stringhe che iniziano con il carattere " << carattereUtente << ": [";
            for (int indice{}; indice < n; indice++) {
                if (tolower(carattereUtente) == tolower(arrayDiStringhe[indice][0])) {
                    cout << arrayDiStringhe[indice] << " ";
                }
            }
            cout << "]" << endl;
            contatoreComandi++;
            break;
        case 3:
            indiceUtente = ottieniInteroUtente("Inserisci un indice: ");
            cout << "Caratteri in posizione " << indiceUtente << ": [";
            for (int indice{}; indice < n; indice++) {
                if (arrayDiStringhe[indice].length() < indiceUtente) {
                    cout << "Carattere non disponibile";
                }
                else {
                    carattereUtente = arrayDiStringhe[indice][indiceUtente - 1];
                    cout << carattereUtente;
                }
                if (indice < n - 1) cout << ", ";
            }
            cout << "]" << endl;
            contatoreComandi++;
            break;
        case 4:
            stringaDiLavoro = ottieniStringaUtente("Inserisci la stringa da cercare: ");
            risultatoContatore = 0;
            for (int indice{}; indice < n; indice++) {
                if (stringaDiLavoro == arrayDiStringhe[indice]) {
                    risultatoContatore++;
                }
            }
            if (risultatoContatore > 0) {
                cout << "La stringa " << stringaDiLavoro << " e' presente " << risultatoContatore << " volta/volte" << endl;
            }
            else {
                cout << "La stringa " << stringaDiLavoro << " non e' presente" << endl;
            }
            contatoreComandi++;
            break;
        case 5:
            stringaDiLavoro = "Array di stringhe: [";
            for (int indice{}; indice < n; indice++) {
                stringaDiLavoro += "Stringa " + to_string(indice + 1) + " = " + arrayDiStringhe[indice];
                if (indice < n - 1) {
                    stringaDiLavoro += ", ";
                }
            }
            stringaDiLavoro += "]\n";
            cout << stringaDiLavoro;
            contatoreComandi++;
            break;
        default:
            if (contatoreComandi >= 4) {
                cout << "Programma terminato!" << endl;
            }
        }

        system("pause");
        system("cls");
    } while (comandoUtente < 6 || contatoreComandi < 4);
#elif ESERCIZIO == ESERCIZIO_8
    bool finito{};

    do {
        double a{ottieniDoubleUtente("Inserisci il numero reale a: ")};
        double b{ottieniDoubleUtente("Inserisci il numero reale b: ")};

        string operatoreStringa{};
        char operatore{};
        do {
            operatoreStringa = ottieniStringaUtente("Inserisci un operatore (+, -, x, :, ^, %, b e a): ");
        } while (operatoreStringa.length() > 1);
        operatore = operatoreStringa[0];

        double risultatoOperazione{};
        int contatore{};
        int arrayDiInteri[DIMENSIONE_MASSIMA]{};

        switch (operatore) {
        case '+':
            risultatoOperazione = a + b;
            cout << a << " + " << b << " = " << risultatoOperazione;
            break;
        case '-':
            risultatoOperazione = a - b;
            cout << a << " - " << b << " = " << risultatoOperazione;
            break;
        case 'x':
            risultatoOperazione = a * b;
            cout << a << " x " << b << " = " << risultatoOperazione;
            break;
        case ':':
            risultatoOperazione = a / b;
            cout << a << " : " << b << " = " << risultatoOperazione;
            break;
        case '^':
            risultatoOperazione = pow(a, b);
            cout << a << " ^ " << b << " = " << risultatoOperazione;
            break;
        case '%':
            risultatoOperazione = static_cast<int>(a) % static_cast<int>(b);
            cout << a << " % " << b << " = " << risultatoOperazione;
            break;
        case 'b':
            risultatoOperazione = a + b;
            contatore = convertiInBinario(static_cast<int>(risultatoOperazione), arrayDiInteri);
            cout << a << " + " << b << " = ";
            for (int indice{contatore}; indice >= 0; indice--) {
                cout << arrayDiInteri[indice];
            }
            cout << " base 2";
            break;
        case 'a':
            contatore = a + b;
            cout << "Array creato: [";
            for (int indice{}; indice < contatore; indice++) {
                arrayDiInteri[indice] = ottieniInteroCasuale(static_cast<int>(a), static_cast<int>(b));
                cout << "Elemento " << (indice + 1) << " = " << arrayDiInteri[indice];
                if (indice < contatore - 1) cout << ", ";
            }
            cout << "]";
            break;
        default:
            cout << "Operatore non valido!";
        }

        cout << endl;
        string comandoUtente{ottieniStringaUtente("Vuoi continuare? (S = si): ")};
        if (comandoUtente != "S") {
            finito = true;
            cout << "Programma terminato!";
        }
        else {
            system("cls");
        }
    } while (!finito);
#elif ESERCIZIO == ESERCIZIO_9
    int arrayDiInteri[DIMENSIONE_MASSIMA]{};
    int arrayDiInteriDoppioni[DIMENSIONE_MASSIMA]{};

    int n{ottieniInteroUtente("Inserisci la dimensione dell'array originale: ")};
    for (int indice{}; indice < n; indice++) {
        arrayDiInteri[indice] = ottieniInteroCasuale(0, 50);
    }
    stampaIntArray(arrayDiInteri, n);

    int dimensioneArrayInteriDoppioni =
    riempiArrayDoppioni(arrayDiInteri, n, arrayDiInteriDoppioni);
    stampaIntArray(arrayDiInteriDoppioni, dimensioneArrayInteriDoppioni);
#elif ESERCIZIO == ESERCIZIO_10
    int arrayDiInteriOrigine[DIMENSIONE_MASSIMA]{};
    int dimensione{ottieniInteroUtente("Inserisci il numero di elementi da creare nell'array: ", 0, DIMENSIONE_MASSIMA)};
    for (int indice{}; indice < dimensione; indice++) {
        arrayDiInteriOrigine[indice] = ottieniInteroCasuale(0, 100);
    }
    stampaIntArray(arrayDiInteriOrigine, dimensione);

    modificaOrdinaArray(arrayDiInteriOrigine, dimensione);
#elif ESERCIZIO == ESERCIZIO_11
    Display display;

    inizializzaDisplay(display);

    cout << "Marca " << display.marca << "\n";
    cout << "Modello " << display.modello << "\n";
    cout << "Aletezza(pxl) " << display.altezza << "\n";
    cout << "Larghezza(pxl) " << display.larghezza << "\n";

    disegnaDisplay(display);

    system("pause");
    system("cls");

    settaCarattereDisplay(display, 0, 0, 0);
    settaCarattereDisplay(display, 1, 0, 6);

    disegnaDisplay(display);

    system("pause");
    system("cls");

    cout << "Programma terminato!";
#endif
    
    return 0;
}

bool applicaRicercaSequenziale(int arrayInteri[], int dimensione, int elementoDaCercare) {
    bool risultato{};

    for (int indice{}; indice < dimensione; indice++) {
        if (arrayInteri[indice] == elementoDaCercare) {
            risultato = true;
            break;
        }
    }

    return risultato;
}

int convertiInBinario(int numeroDaConvertire, int arrayDiBit[]) {
    int contatore{};
    int quoziente{numeroDaConvertire};
    for (contatore = 0; contatore < DIMENSIONE_MASSIMA; contatore++) {
        int resto{quoziente % 2};
        quoziente = quoziente / 2;

        arrayDiBit[contatore] = resto;

        if (quoziente == 0) {
            break;
        }
    }

    return contatore;
}

void modificaOrdinaArray(int arrayDiInteri[], int dimensione) {
    int passoDiLavoro{};
    int contatoreDiPosizioni{};

    while (passoDiLavoro != 3) {
        switch (passoDiLavoro) {
        case 0:
            for (int indice{}; indice < dimensione - 1; indice++) {
                if ((arrayDiInteri[indice] % 2 == 1) && (arrayDiInteri[indice + 1] % 2 == 0)) {
                    arrayDiInteri[indice] = 0;
                }
            }
            cout << "Fase di azzeramento dei dati dispari se seguiti da un dato pari -> ";
            stampaIntArray(arrayDiInteri, dimensione);
            passoDiLavoro++;
            break;
        case 1:
            for (int indice{}; indice < dimensione; indice++) {
                if (arrayDiInteri[indice] % 2 == 0 && arrayDiInteri[indice] != 0) {
                    contatoreDiPosizioni++;
                }
                else {
                    for (int indiceSecondario{indice + 1}; indiceSecondario < dimensione; indiceSecondario++) {
                        if (arrayDiInteri[indiceSecondario] % 2 == 0 && arrayDiInteri[indiceSecondario] != 0) {
                            swap(arrayDiInteri[indice], arrayDiInteri[indiceSecondario]);
                            contatoreDiPosizioni++;
                            break;
                        }
                    }
                }
            }
            cout << "Fase di posizionamento dei dati pari all'inizio -> ";
            stampaIntArray(arrayDiInteri, dimensione);
            passoDiLavoro++;
            break;
        case 2:
            for (int indice{contatoreDiPosizioni}; indice < dimensione; indice++) {
                if (arrayDiInteri[indice] == 0) {
                    contatoreDiPosizioni++;
                }
                else {
                    for (int indiceSecondario{indice + 1}; indiceSecondario < dimensione; indiceSecondario++) {
                        if (arrayDiInteri[indiceSecondario] == 0) {
                            swap(arrayDiInteri[indice], arrayDiInteri[indiceSecondario]);
                            break;
                        }
                    }
                }
            }
            cout << "Fase di posizionamento degli zeri al centro -> ";
            stampaIntArray(arrayDiInteri, dimensione);
            passoDiLavoro++;
            break;
        }
    }
}

double ottieniDoubleUtente(string messaggio, double valoreMinimo, double valoreMassimo) {
    double doubleUtente{};
    string doubleUtenteStringa{};

    do {
        cout << messaggio;
        getline(cin, doubleUtenteStringa);
        doubleUtente = stod(doubleUtenteStringa);
    } while (doubleUtente < valoreMinimo || doubleUtente > valoreMassimo);

    return doubleUtente;
}

int ottieniInteroCasuale(int minimo, int massimo) {
    int risultato{};
    int temporaneo{};

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
    int interoUtente{};
    string interoUtenteStringa{};

    do {
        cout << messaggio;
        getline(cin, interoUtenteStringa);
        interoUtente = stoi(interoUtenteStringa);
    } while (interoUtente < valoreMinimo || interoUtente > valoreMassimo);

    return interoUtente;
}

string ottieniStringaUtente(string messaggio) {
    string stringaUtente{};
    cout << messaggio;
    getline(cin, stringaUtente);
    return stringaUtente;
}

int riempiArrayDoppioni(int arrayDiInteri[], int dimensioneArrayInteri, int arrayDiInteriDoppioni[]) {
    int dimensioneArrayInteriDoppioni{};

    for (int indice{}; indice < dimensioneArrayInteri - 1; indice++) {
        int valoreInteroDaVerificare{arrayDiInteri[indice]};
        if (!applicaRicercaSequenziale(arrayDiInteriDoppioni, dimensioneArrayInteriDoppioni, valoreInteroDaVerificare)) {
            for (int indiceSecondario{indice + 1}; indiceSecondario < dimensioneArrayInteri; indiceSecondario++) {
                if (valoreInteroDaVerificare == arrayDiInteri[indiceSecondario]) {
                    arrayDiInteriDoppioni[dimensioneArrayInteriDoppioni] = valoreInteroDaVerificare;
                    dimensioneArrayInteriDoppioni++;
                    break;
                }
            }
        }
    }

    return dimensioneArrayInteriDoppioni;
}

void stampaIntArray(int arrayInteri[], int dimensione) {
    string s{"Array di interi: ["};
    for (int indice{}; indice < dimensione; indice++) {
        s += to_string(arrayInteri[indice]);
        if (indice < dimensione - 1) {
            s += ", ";
        }
    }
    s += "]\n";
    cout << s;
}

void stampaStringArray(string arrayStringhe[], int dimensione) {
    string s{"Array di stringhe: ["};
    for (int indice{}; indice < dimensione; indice++) {
        s += arrayStringhe[indice];
        if (indice < dimensione - 1) {
            s += ", ";
        }
    }
    s += "]\n";
    cout << s;
}

#if ESERCIZIO == ESERCIZIO_11
void disegnaDisplay(Display& display) {
    for(int riga = 0; riga < display.altezza; riga++) {
        for(int colonna = 0; colonna < display.larghezza; colonna++) {
            cout << display.pixel[riga][colonna];
        }
        cout << endl;
    }
}

void inizializzaDisplay(Display& display) {
    display.marca = ottieniStringaUtente("Inserisci la marca del display: ");
    display.modello = ottieniStringaUtente("Inserisci il modello del display: ");
    display.altezza = ottieniInteroUtente("Inserisci l'altezza (pxl) del display: ", 0);
    display.larghezza = ottieniInteroUtente("Inserisci la larghezza (pxl) del display: ", 0);

    display.pixel = new char*[display.altezza];
    for(int riga = 0; riga < display.altezza; riga++) {
        display.pixel[riga] = new char[display.larghezza];
    }

    resetDisplay(display);
}

void resetDisplay(Display& display) {
    for(int riga = 0; riga < display.altezza; riga++) {
        for(int colonna = 0; colonna < display.larghezza; colonna++) {
            display.pixel[riga][colonna] = ' ';
        }
    }
}

void settaCarattereDisplay(Display& display, int indiceCarattere, int x, int y) {
    for(int riga = 0; riga < 5; riga++) {
        for(int colonna = 0; colonna < 5; colonna++) {
            display.pixel[x + riga][y + colonna] = C_FONT[indiceCarattere][riga][colonna];
        }
    }
}
#endif