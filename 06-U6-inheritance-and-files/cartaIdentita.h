#pragma once

#include <iostream>
#include <string>

using namespace std;

class CartaIdentita {
public:
    enum Gender {M, F, N};

private:
    string id, nome, cognome, luogoDiNascita, dataDiNascita, nazionalita;
    Gender gender;
    int altezza;

public:
    CartaIdentita(string id, string nome, string cognome, string luogoDiNascita, string dataDiNascita, string nazionalita, Gender gender, int altezza);

    string ottieniId() const;
    string ottieniNome() const;
    string ottieniCognome() const;
    string ottieniLuogoDiNascita() const;
    string ottienidataDiNascita() const;
    string ottieniNazionalita() const;
    Gender ottieniGender() const;
    int ottieniAltezza() const;

    void settaNome(string nuovoNome);
    void settaCognome(string nuovoCognome);
    void settaNazionalita(string nuovaNazionalita);
    void settaGender(Gender nuovoGender);
    void settaAltezza(int nuovaAltezza);

    void stampaInfo() const;
};