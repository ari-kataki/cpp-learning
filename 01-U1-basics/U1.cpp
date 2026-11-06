#define ESEMPIO_1 0
#define ESEMPIO_2 1
#define ESERCIZIO_1 2
#define ESERCIZIO_2 3
#define ESERCIZIO_3 4
#define ESERCIZIO_4 5
#define ESERCIZIO_5 6
#define ESERCIZIO_6 7
#define ESERCIZIO_7 8

#define ESERCIZIO ESERCIZIO_7

#include <iostream>
#if ESERCIZIO == ESEMPIO_2
#include <limits>
#include <iomanip>
#elif ESERCIZIO == ESERCIZIO_7
#include <bitset>
#endif

using namespace std;

int main() {
#if ESERCIZIO == ESEMPIO_1
    cout << "Ciao ragazzi... vi sono mancato?!" << endl;
    cout << "A me no!" << endl;
#elif ESERCIZIO == ESEMPIO_2
    int larghezza = 20;

    cout << "TABELLA TIPI\n";
    cout << setw(larghezza) << "TIPO"
        << setw(larghezza) << "BYTES"
        << setw(larghezza) << "MIN"
        << setw(larghezza) << "MAX" << endl;
    cout << setw(larghezza) << "int"
        << setw(larghezza) << sizeof(int)
        << setw(larghezza) << numeric_limits<int>::min()
        << setw(larghezza) << numeric_limits<int>::max() << endl;
    cout << setw(larghezza) << "unsigned char"
        << setw(larghezza) << sizeof(unsigned char)
        << setw(larghezza) << (int)numeric_limits<unsigned char>::min()
        << setw(larghezza) << (int)numeric_limits<unsigned char>::max() << endl;
    cout << setw(larghezza) << "float"
        << setw(larghezza) << sizeof(float)
        << setw(larghezza) << numeric_limits<float>::min()
        << setw(larghezza) << numeric_limits<float>::max() << endl;
    cout << setw(larghezza) << "double"
        << setw(larghezza) << sizeof(double)
        << setw(larghezza) << numeric_limits<double>::min()
        << setw(larghezza) << numeric_limits<double>::max() << endl;
    cout << setw(larghezza) << "bool"
        << setw(larghezza) << sizeof(bool)
        << setw(larghezza) << numeric_limits<bool>::min()
        << setw(larghezza) << numeric_limits<bool>::max() << endl;
#elif ESERCIZIO == ESERCIZIO_1
    cout << "ESERCIZIO 1\n";
    int base{};
    int altezza{};
    int perimetro{};
    int area{};

    cout << "Inserisci la base del rettangolo: ";
    cin >> base;
    cout << "Inserisci l'altezza del rettangolo: ";
    cin >> altezza;

    perimetro = (base + altezza) * 2;
    area = base * altezza;

    cout << "Perimetro: " << perimetro << endl;
    cout << "Area: " << area << endl;
#elif ESERCIZIO == ESERCIZIO_2
    cout << "ESERCIZIO 2\n";
    int n0{}, n1{}, n2{};
    float media{};

    cout << "Inserisci il primo numero: ";
    cin >> n0;

    cout << "Inserisci il secondo numero: ";
    cin >> n1;

    cout << "Inserisci il terzo numero: ";
    cin >> n2;

    media = (n0 + n1 + n2) / 3.0;
    cout << "La media e' " << media << endl;
#elif ESERCIZIO == ESERCIZIO_3
    cout << "ESERCIZIO 3\n";
    int giorni = 0, ore = 0, minuti = 0, secondi = 0;

    long long secondi_totali = 0;

    cout << "Inserisci il numero di giorni: ";
    cin >> giorni;

    cout << "Inserisci il numero di ore: ";
    cin >> ore;

    cout << "Inserisci il numero di minuti: ";
    cin >> minuti;

    cout << "Inserisci il numero di secondi: ";
    cin >> secondi;

    secondi_totali = secondi + ((long long)minuti * 60) + ((long long)ore * 3600) + ((long long)giorni * 86400);
    cout << "Secondi totali: " << secondi_totali << endl;
#elif ESERCIZIO == ESERCIZIO_4
    cout << "ESERCIZIO 4\n";
    unsigned char c0 = 0, c1 = 0;

    cout << "Inserisci il primo carattere: ";
    cin >> c0;

    cout << "Inserisci il secondo carattere: ";
    cin >> c1;

    cout << "Codice primo carattere: " << int(c0) << endl;
    cout << "Codice secondo carattere: " << int(c1) << endl;
#elif ESERCIZIO == ESERCIZIO_5
    cout << "ESERCIZIO 5\n";
    const int anno_corrente = 2025;
    int anno_di_nascita = 0, anni = 0;
    
    cout << "Inserisci un anno di nascita: ";
    cin >> anno_di_nascita;

    anni = anno_corrente - anno_di_nascita;
    cout << "La tua eta' e' " << anni << " anni" << endl;
#elif ESERCIZIO == ESERCIZIO_6
    cout << "ESERCIZIO 6\n";
    float peso = 0.0, altezza = 0.0, bmi = 0.0;

    cout << "Inserisci un peso in Kg: ";
    cin >> peso;

    cout << "Inserisci un'altezza in m: ";
    cin >> altezza;

    bmi = peso / (altezza * altezza);
    cout << "BMI: " << bmi << endl;
#elif ESERCIZIO == ESERCIZIO_7
    cout << "ESERCIZIO 7\n";
    int numeroUtente{};

    cout << "Inserisci un intero: ";
    cin >> numeroUtente;

    cout << "\n";
    cout << "Numero inserito dall'utente: " << numeroUtente << " base 10; " << bitset<8>(numeroUtente) << " base 2\n";
    cout << "Moltiplicazione x 2: " << (numeroUtente << 1) << "\n";
    cout << "Moltiplicazione x 16: " << (numeroUtente << 4) << "\n";
    cout << "Divisione x 2: " << (numeroUtente >> 1) << "\n";
    cout << "Divisione x 8: " << (numeroUtente >> 3) << "\n";
    cout << "Quarto bit: " << ((numeroUtente >> 3) & 1) << "\n";
    cout << "Complemento a 1: " << bitset<8>(~numeroUtente) << "\n";
    cout << "Complemento a 2: " << bitset<8>(~numeroUtente + 1) << endl;
#endif
    return 0;
}