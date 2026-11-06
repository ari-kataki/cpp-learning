#include "veicolo.h"

Veicolo::Veicolo(string targa, string marca, string modello, double potenza, double kmPercorsi):
    targa(targa), marca(marca), modello(modello), potenza(potenza), kmPercorsi(kmPercorsi)
{
    this->potenza = potenza;
    this->kmPercorsi = kmPercorsi;
}

Veicolo::~Veicolo()
{
    // Distruttore virtuale
}

void Veicolo::aggiungiKm(double nuoviKm)
{
    if (nuoviKm < 0) {
        this->kmPercorsi += nuoviKm;
    }
}

void Veicolo::stampaInfo() const
{
    cout << "Informazioni veicolo:\n";
    cout << "Targa: " << targa << "\n";
    cout << "Marca: " << marca << "\n";
    cout << "Modello: " << modello << "\n";
    cout << "Potenza: " << potenza << "\n";
    cout << "Chilometri percorsi: " << kmPercorsi << "\n";
}
