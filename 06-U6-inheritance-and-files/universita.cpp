#include "universita.h"

Universita::Universita(string nome, list<Persona*> listaPersone):
    nome(nome), listaPersone(listaPersone)
{
}

string Universita::ottieniNome() const
{
    return this->nome;
}

list<Persona*> Universita::ottieniListaPersone() const
{
    return this->listaPersone;
}

void Universita::stampa_info() const
{
    cout << "Universita: " << this->nome << "\n";
    for (Persona* persona : this->listaPersone) {
        cout << "-----------------------------\n";
        persona->stampa_info();
    }
    cout << "-----------------------------\n";
}