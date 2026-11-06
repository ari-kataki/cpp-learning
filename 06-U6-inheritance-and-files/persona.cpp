#include "persona.h"

Persona::Persona(string codiceFiscale, string nome, string cognome):
    codiceFiscale(codiceFiscale), nome(nome), cognome(cognome)
{
}

Persona::~Persona()
{
}

string Persona::ottieniCodiceFiscale() const
{
    return this->codiceFiscale;
}

string Persona::ottieniNome() const
{
    return this->nome;
}

string Persona::ottieniCognome() const
{
    return this->cognome;
}

void Persona::stampa_info() const
{
    cout << "Codice fiscale: " << this->codiceFiscale << "\n";
    cout << "Nome: " << this->nome << "\n";
    cout << "Cognome: " << this->cognome << "\n";
}