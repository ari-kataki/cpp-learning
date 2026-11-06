#pragma once

#include <iostream>
#include <string>

#include "persona.h"

using namespace std;

class Docente: public Persona {
private:
    string disciplinaInsegnamento;
    double stipendio;

public:
    Docente(string codiceFiscale, string nome, string cognome, string disciplinaInsegnamento, double stipendio);

    string ottieniDisciplinaInsegnamento() const;
    double ottieniStipendio() const;

    void incrementa_soldi(double soldi);
    void stampa_info() const override;
};