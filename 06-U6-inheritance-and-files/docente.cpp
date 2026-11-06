#include "docente.h"

#include <iomanip>
#include <sstream>

Docente::Docente(string codiceFiscale, string nome, string cognome, string disciplinaInsegnamento, double stipendio):
    Persona(codiceFiscale, nome, cognome), disciplinaInsegnamento(disciplinaInsegnamento), stipendio(stipendio)
{
}

string Docente::ottieniDisciplinaInsegnamento() const
{
    return this->disciplinaInsegnamento;
}

double Docente::ottieniStipendio() const
{
    return this->stipendio;
}

void Docente::incrementa_soldi(double soldi)
{
    this->stipendio += soldi;
}

void Docente::stampa_info() const
{
    cout << "Tipo: Docente\n";
    Persona::stampa_info();
    cout << "Disciplina insegnamento: " << this->disciplinaInsegnamento << "\n";
    ostringstream stipendioFormattato;
    stipendioFormattato << fixed << setprecision(0) << this->stipendio;
    cout << "Stipendio: " << stipendioFormattato.str() << " euro\n";
}