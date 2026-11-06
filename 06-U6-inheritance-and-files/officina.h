#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "automobile.h"
#include "libreriaITS.h"

using namespace std;

class Officina {
private:
    string nome;
    list<Automobile> listaAuto;

public:
    Officina(string nome, list<Automobile> listaAuto);

    string ottieniNome() const;
    list<Automobile> ottieniListaAuto() const;

    void settaNome(string nuovoNome);
    void settaListaAuto(list<Automobile> nuovaLista);

    bool salvaNelFile(string nomeFile) const;
    bool caricaDalFile(string nomeFile);
};