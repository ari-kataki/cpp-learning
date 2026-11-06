#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "cartaIdentita.h"
#include "libreriaITS.h"

using namespace std;

class Citta
{
private:
    string nome{};
    list<CartaIdentita*> listaCarteIdentita{};

public:
    Citta(string nome, list<CartaIdentita*> listaCarteIdentita);

    string ottieniNome() const;
    list<CartaIdentita*> ottieniListaCarteIdentita() const;

    bool salvaNelFile(string nomeFile) const;
    bool caricaDalFile(string nomeFile);
};