#include "camion.h"

#include <iomanip>
#include <sstream>

Camion::Camion(string targa, string marca, string modello, double potenza, double kmPercorsi, bool haRimorchio, bool noleggiato):
    Veicolo(targa, marca, modello, potenza, kmPercorsi), haRimorchio(haRimorchio), noleggiato(noleggiato)
{
    this->haRimorchio = haRimorchio;
    this->noleggiato = noleggiato;
}

Camion::~Camion()
{
    
}

double Camion::calcolaCostoAssicurazione() const
{
    double costoBase = 1000.0 * this->potenza; // Costo base per un camion
    if (!noleggiato && haRimorchio) {
        costoBase += 500.0;
    }
    return costoBase;
}

void Camion::stampaInfo() const
{
    Veicolo::stampaInfo(); // Stampa le informazioni di base del veicolo
    cout << "Ha rimorchio: " << (haRimorchio ? "Sì" : "No") << "\n";
    cout << "Noleggiato: " << (noleggiato ? "Sì" : "No") << "\n";
    ostringstream costoAssicurazione;
    costoAssicurazione << fixed << setprecision(0) << this->calcolaCostoAssicurazione();
    cout << "Costo assicurazione: " << costoAssicurazione.str() << endl;
}