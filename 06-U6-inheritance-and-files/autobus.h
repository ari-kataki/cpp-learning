#pragma once

#include "veicolo.h"

class Autobus : public Veicolo {
protected:
    int numeroPasseggeri;
    bool aziendale;



public:
    Autobus(string targa, string marca, string modello, double potenza, double kmPercorsi, int numeroPasseggeri, bool aziendale);
    virtual ~Autobus();
    
    virtual double calcolaCostoAssicurazione() const override;
    
    virtual void stampaInfo() const override;
};