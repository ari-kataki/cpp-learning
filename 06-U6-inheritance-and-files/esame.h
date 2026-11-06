#pragma once

#include <iostream>
#include <string>

using namespace std;

class Esame {
private:
    string codice;
    string nome;
    string dataSvolgimento;

public:
    Esame(string codice, string nome, string dataSvolgimento);

    string ottieniCodice() const;
    string ottieniNome() const;
    string ottieniDataSvolgimento() const;

    void stampa_info() const;
};