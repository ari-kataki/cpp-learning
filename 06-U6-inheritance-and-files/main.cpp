#define ESEMPIO       0
#define ESERCIZIO_1   1
#define ESERCIZIO_2   2
#define ESERCIZIO_3   3
#define ESERCIZIO_4   4
#define ESERCIZIO_5   5
#define ESERCIZIO_6   6

#define ESERCIZIO  ESERCIZIO_4

#define SALVATAGGIO 0
#define CARICAMENTO 1

#define TIPO_TEST CARICAMENTO

#include <iostream>
#include <list>
#include <iomanip>
#include <sstream>

#include "libreriaITS.h"

#if ESERCIZIO == ESERCIZIO_1
#include "cartaIdentita.h"
#include "citta.h"
#elif ESERCIZIO == ESERCIZIO_2
#include "automobile.h"
#include "officina.h"
#elif ESERCIZIO == ESERCIZIO_3
#include "veicolo.h"
#include "autobus.h"
#include "camion.h"
#include "garage.h"
#elif ESERCIZIO == ESERCIZIO_4
#include "esame.h"
#include "persona.h"
#include "studente.h"
#include "docente.h"
#include "universita.h"
#elif ESERCIZIO == ESERCIZIO_5
#elif ESERCIZIO == ESERCIZIO_6
#endif

using namespace std;

int main() {
#if ESERCIZIO == ESERCIZIO_1
#if (TIPO_TEST == SALVATAGGIO)
    int numeroCI = ottieniInteroUtente("Inserisci il numero di carte di identita': ");
    list<CartaIdentita*> listaCI;

    for (int i = 0; i < numeroCI; i++) {
        string id = ottieniStringaUtente("Inserisci l'ID della CI in posizione " + to_string(i + 1) + ": ");
        string nome = ottieniStringaUtente("Inserisci il nome della CI in posizione " + to_string(i + 1) + ": ");
        string cognome = ottieniStringaUtente("Inserisci il cognome della CI in posizione " + to_string(i + 1) + ": ");
        string luogo_nascita = ottieniStringaUtente("Inserisci il luogo di nascita della CI in posizione " + to_string(i + 1) + ": ");
        string data_nascita = ottieniStringaUtente("Inserisci la data di nascita della CI in posizione " + to_string(i + 1) + ": ");
        string genere_s = ottieniStringaUtente("Inserisci il genere della CI in posizione " + to_string(i + 1) + ": ");
        int altezza = ottieniInteroUtente("Inserisci l'altezza della CI in posizione " + to_string(i + 1) + ": ");
        string nazionalita = ottieniStringaUtente("Inserisci la nazionalita' della CI in posizione " + to_string(i + 1) + ": ");

        CartaIdentita::Gender genere;
        if (genere_s == "M") {
            genere = CartaIdentita::M;
        }
        else if (genere_s == "F") {
            genere = CartaIdentita::F;
        }
        else {
            genere = CartaIdentita::N;
        }

        CartaIdentita* ci = new CartaIdentita(id, nome, cognome, luogo_nascita,
            data_nascita, nazionalita, genere, altezza);
        listaCI.push_back(ci);
    }

    Citta citta("Perugia", listaCI);
    if (citta.salvaNelFile("Città.txt")) {
        cout << "Salvataggio avvenuto con successo!\n";
    }
    else {
        cout << "Salvataggio NON riuscito!\n";
    }
#else
    list<CartaIdentita*> listaCI;
    Citta citta("Perugia", listaCI);
    if (citta.caricaDalFile("Città.txt")) {
        cout << "Caricamento avvenuto con successo!\n";
    }
    else {
        cout << "Caricamento NON riuscito!\n";
    }

    for (CartaIdentita* ci : citta.ottieniListaCarteIdentita()) {
        ci->stampaInfo();
    }
#endif
#elif ESERCIZIO == ESERCIZIO_2
#if (TIPO_TEST == SALVATAGGIO)
    int numeroA = ottieniInteroUtente("Inserisci il numero di automobili: ");
    list<Automobile> listaA;

    for (int i = 0; i < numeroA; i++) {
        string telaio = ottieniStringaUtente("Inserisci il telaio dell'automobile in posizione " + to_string(i + 1) + ": ");
        string marca = ottieniStringaUtente("Inserisci la marca dell'automobile in posizione " + to_string(i + 1) + ": ");
        string modello = ottieniStringaUtente("Inserisci il modello dell'automobile in posizione " + to_string(i + 1) + ": ");
        float kmPercorsi = ottieniDoubleUtente("Inserisci i km percorsi dell'automobile in posizione " + to_string(i + 1) + ": ");
        int numeroControlli = ottieniInteroUtente("Inserisci il numero di controlli dell'automobile in posizione " + to_string(i + 1) + ": ");

        Automobile a(telaio, marca, modello, kmPercorsi, numeroControlli);
        listaA.push_back(a);
    }

    Officina officina("Da Paolo", listaA);
    if (officina.salvaNelFile("Officina.txt")) {
        cout << "Salvataggio avvenuto con successo!\n";
    }
    else {
        cout << "Salvataggio NON riuscito!\n";
    }
#else
    list<Automobile> listaA;
    Officina officina("Da Paolo", listaA);
    if (officina.caricaDalFile("Officina.txt")) {
        cout << "Caricamento avvenuto con successo!\n";
    }
    else {
        cout << "Caricamento NON riuscito!\n";
    }

    for (Automobile a: officina.ottieniListaAuto()) {
        a.stampaInfo();
    }
#endif
#elif ESERCIZIO == ESERCIZIO_3
    int numerov = ottieniInteroUtente("Inserisci il numero di veicoli: ");
    list<Veicolo*> listaV;

    for (int i = 0; i < numerov; i++) {
        string targa = ottieniStringaUtente("Inserisci la targa del veicolo in posizione " + to_string(i + 1) + ": ");
        string marca = ottieniStringaUtente("Inserisci la marca del veicolo in posizione " + to_string(i + 1) + ": ");
        string modello = ottieniStringaUtente("Inserisci il modello del veicolo in posizione " + to_string(i + 1) + ": ");
        float kmPercorsi = ottieniDoubleUtente("Inserisci i km percorsi del veicolo in posizione " + to_string(i + 1) + ": ");
        double potenza = ottieniDoubleUtente("Inserisci la potenza del veicolo in posizione " + to_string(i + 1) + ": ");

        string scelta;
        do {
            scelta = ottieniStringaUtente("Il veicolo in posizione " + to_string(i + 1) + " è un autobus (A) o un camion (C)? ");
        } while (scelta != "A" && scelta != "C");
        if (scelta == "C") {
            bool rimarchio = ottieniInteroUtente("Il camion in posizione " + to_string(i + 1) + " ha un rimorchio? (1 per sì, 0 per no): ") == 1;
            bool noleggiato = ottieniInteroUtente("Il camion in posizione " + to_string(i + 1) + " è noleggiato? (1 per sì, 0 per no): ") == 1;
            Camion* c = new Camion(targa, marca, modello, potenza, kmPercorsi, rimarchio, noleggiato);
            listaV.push_back(c);
        }
        else {
            int numeroPasseggeri = ottieniInteroUtente("L'autobus in posizione " + to_string(i + 1) + " ha quanti passeggeri? ");
            bool aziendale = ottieniInteroUtente("L'autobus in posizione " + to_string(i + 1) + " è aziendale? (1 per sì, 0 per no): ") == 1;
            Autobus* a = new Autobus(targa, marca, modello, potenza, kmPercorsi, numeroPasseggeri, aziendale);
            listaV.push_back(a);
        }
    }

    string nomeGarage = ottieniStringaUtente("Inserisci il nome del garage: ");
    Garage garage(nomeGarage, listaV);
    garage.stampaInfo();
    ostringstream costoTotaleAssicurazione;
    costoTotaleAssicurazione << fixed << setprecision(0) << garage.calcolaCostoTotaleAssicurazione();
    cout << "Costo totale assicurazione: " << costoTotaleAssicurazione.str() << " euro\n";
#elif ESERCIZIO == ESERCIZIO_4
    Esame analisi("E001", "Analisi 1", "2026-06-10");
    Esame algebra("E002", "Algebra Lineare", "2026-06-12");
    Esame programmazione("E003", "Programmazione", "2026-06-15");

    Studente studente1("RSSMRA80A01H501U", "Mario", "Rossi", "12345", 2024, "Informatica");
    studente1.aggiungi_esame(analisi);
    studente1.aggiungi_esame(programmazione);

    Studente studente2("BNCLGU01B02H501Z", "Luca", "Bianchi", "12346", 2023, "Matematica");
    studente2.aggiungi_esame(algebra);

    Docente docente1("VRDLNZ70C03H501X", "Laura", "Verdi", "Informatica", 28000.0);
    docente1.incrementa_soldi(2500.0);

    list<Persona*> listaPersone;
    listaPersone.push_back(&studente1);
    listaPersone.push_back(&studente2);
    listaPersone.push_back(&docente1);

    Universita universita("Universita degli Studi", listaPersone);
    universita.stampa_info();
#elif ESERCIZIO == ESERCIZIO_5
#elif ESERCIZIO == ESERCIZIO_6
#endif

    return 0;
}