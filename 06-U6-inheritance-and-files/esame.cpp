#include "esame.h"

Esame::Esame(string codice, string nome, string dataSvolgimento):
    codice(codice), nome(nome), dataSvolgimento(dataSvolgimento)
{
}

string Esame::ottieniCodice() const
{
    return this->codice;
}

string Esame::ottieniNome() const
{
    return this->nome;
}

string Esame::ottieniDataSvolgimento() const
{
    return this->dataSvolgimento;
}

void Esame::stampa_info() const
{
    cout << "Codice esame: " << this->codice << "\n";
    cout << "Nome esame: " << this->nome << "\n";
    cout << "Data svolgimento: " << this->dataSvolgimento << "\n";
}