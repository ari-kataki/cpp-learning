#pragma once

#include <iostream>

using namespace std;

class Veicolo {
protected:
    string targa, marca, modello;
    double potenza, kmPercorsi;

public:
    Veicolo(string targa, string marca, string modello, double potenza, double kmPercorsi);
    virtual ~Veicolo();
    
    void aggiungiKm(double nuoviKm);

    virtual double calcolaCostoAssicurazione() const = 0;

    virtual void stampaInfo() const = 0;
};