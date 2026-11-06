#pragma once

#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    string codiceFiscale;
    string nome;
    string cognome;

public:
    Persona(string codiceFiscale, string nome, string cognome);
    virtual ~Persona();

    string ottieniCodiceFiscale() const;
    string ottieniNome() const;
    string ottieniCognome() const;

    virtual void stampa_info() const;
};