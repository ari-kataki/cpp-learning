#include "garage.h"

#include <iomanip>
#include <sstream>

Garage::Garage(string nome, list<Veicolo *> listaVeicoli): nome(nome), listaVeicoli(listaVeicoli)
{
}

double Garage::calcolaCostoTotaleAssicurazione() const
{
    double totaleAssicurazione {0.0};
    
    for (Veicolo* veicolo : this->listaVeicoli) {
        totaleAssicurazione += veicolo->calcolaCostoAssicurazione();
    }

    return totaleAssicurazione;
}

void Garage::stampaInfo() const
{
    cout << "Garage: " << this->nome << "\n";
    for (Veicolo* veicolo : this->listaVeicoli) {
        if (typeid(*veicolo) == typeid(Autobus)) {
            cout << "Tipo: Autobus\n";
        }
        else if (typeid(*veicolo) == typeid(Camion)) {
            cout << "Tipo: Camion\n";
        }
        else {
            cout << "Tipo: Veicolo sconosciuto\n";
        }
        veicolo->stampaInfo();
        ostringstream costoAssicurazione;
        costoAssicurazione << fixed << setprecision(0) << veicolo->calcolaCostoAssicurazione();
        cout << "Costo assicurazione: " << costoAssicurazione.str() << " euro\n";
        cout << "-----------------------------\n";
    }
}
