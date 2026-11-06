#include "studente.h"

Studente::Studente(string codiceFiscale, string nome, string cognome, string numeroMatricola, int annoIscrizione, string indirizzoIscrizione):
    Persona(codiceFiscale, nome, cognome), numeroMatricola(numeroMatricola), annoIscrizione(annoIscrizione), indirizzoIscrizione(indirizzoIscrizione)
{
}

string Studente::ottieniNumeroMatricola() const
{
    return this->numeroMatricola;
}

int Studente::ottieniAnnoIscrizione() const
{
    return this->annoIscrizione;
}

string Studente::ottieniIndirizzoIscrizione() const
{
    return this->indirizzoIscrizione;
}

list<Esame> Studente::ottieniListaEsami() const
{
    return this->listaEsami;
}

void Studente::aggiungi_esame(Esame esame)
{
    this->listaEsami.push_back(esame);
}

void Studente::stampa_info() const
{
    cout << "Tipo: Studente\n";
    Persona::stampa_info();
    cout << "Numero matricola: " << this->numeroMatricola << "\n";
    cout << "Anno iscrizione: " << this->annoIscrizione << "\n";
    cout << "Indirizzo iscrizione: " << this->indirizzoIscrizione << "\n";
    cout << "Esami sostenuti:\n";
    if (this->listaEsami.empty()) {
        cout << "Nessuno\n";
    }
    else {
        for (const Esame& esame : this->listaEsami) {
            cout << "- ";
            esame.stampa_info();
        }
    }
}