#include "autobus.h"

#include <iomanip>
#include <sstream>

Autobus::Autobus(string targa, string marca, string modello, double potenza, double kmPercorsi, int numeroPasseggeri, bool aziendale):
    Veicolo(targa, marca, modello, potenza, kmPercorsi), numeroPasseggeri(numeroPasseggeri), aziendale(aziendale)
{
    this->numeroPasseggeri = numeroPasseggeri;
    this->aziendale = aziendale;
}

Autobus::~Autobus()
{
    
}

double Autobus::calcolaCostoAssicurazione() const
{
    double costoBase = 750.0 * this->potenza; // Costo base per un autobus
    if (numeroPasseggeri > 30) {
        costoBase += 1000.0;
    }
    
    return costoBase;
}

void Autobus::stampaInfo() const
{
    Veicolo::stampaInfo(); // Stampa le informazioni di base del veicolo
    cout << "Numero passeggeri: " << this->numeroPasseggeri << "\n";
    cout << "Aziendale: " << (aziendale ? "Sì" : "No") << "\n";
    ostringstream costoAssicurazione;
    costoAssicurazione << fixed << setprecision(0) << this->calcolaCostoAssicurazione();
    cout << "Costo assicurazione: " << costoAssicurazione.str() << endl;
}