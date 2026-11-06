#pragma once

#include <iostream>
#include <list>
#include <string>

#include "esame.h"
#include "persona.h"

using namespace std;

class Studente: public Persona {
private:
    string numeroMatricola;
    int annoIscrizione;
    string indirizzoIscrizione;
    list<Esame> listaEsami;

public:
    Studente(string codiceFiscale, string nome, string cognome, string numeroMatricola, int annoIscrizione, string indirizzoIscrizione);

    string ottieniNumeroMatricola() const;
    int ottieniAnnoIscrizione() const;
    string ottieniIndirizzoIscrizione() const;
    list<Esame> ottieniListaEsami() const;

    void aggiungi_esame(Esame esame);
    void stampa_info() const override;
};