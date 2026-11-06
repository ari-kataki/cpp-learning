#pragma once

#include <iostream>
#include <list>

#include "autobus.h"
#include "camion.h"
#include "veicolo.h"

using namespace std;

class Garage {
private:
    string nome;
    list<Veicolo*> listaVeicoli;
public:
    Garage(string nome, list<Veicolo*> listaVeicoli);

    double calcolaCostoTotaleAssicurazione() const;

    void stampaInfo() const;
};

