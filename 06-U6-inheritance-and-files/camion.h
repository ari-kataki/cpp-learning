#pragma once

#include "veicolo.h"

class Camion : public Veicolo {
protected:
    bool haRimorchio, noleggiato;


public:
    Camion(string targa, string marca, string modello, double potenza, double kmPercorsi, bool haRimorchio, bool noleggiato);
    virtual ~Camion();

    double calcolaCostoAssicurazione() const override;
    
    void stampaInfo() const override;
};