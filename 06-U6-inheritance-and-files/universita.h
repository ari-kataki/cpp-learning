#pragma once

#include <iostream>
#include <list>
#include <string>

#include "persona.h"

using namespace std;

class Universita {
private:
    string nome;
    list<Persona*> listaPersone;

public:
    Universita(string nome, list<Persona*> listaPersone);

    string ottieniNome() const;
    list<Persona*> ottieniListaPersone() const;

    void stampa_info() const;
};