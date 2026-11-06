#include "cartaIdentita.h"

CartaIdentita::CartaIdentita(string id, string nome, string cognome, string luogoDiNascita, 
                            string dataDiNascita, string nazionalita, CartaIdentita::Gender gender, int altezza):
                            id(id), nome(nome), cognome(cognome), luogoDiNascita(luogoDiNascita),
                            dataDiNascita(dataDiNascita), nazionalita(nazionalita) {
                                this->gender = gender;
                                this->altezza = altezza;
}

string CartaIdentita::ottieniId() const {
    return this->id;
}

string CartaIdentita::ottieniNome() const {
    return this->nome;
}

string CartaIdentita::ottieniCognome() const {
    return this->cognome;
}

string CartaIdentita::ottieniLuogoDiNascita() const {
    return this->luogoDiNascita;
}

string CartaIdentita::ottienidataDiNascita() const {
    return this->dataDiNascita;
}

string CartaIdentita::ottieniNazionalita() const {
    return this->nazionalita;
}

CartaIdentita::Gender CartaIdentita::ottieniGender() const {
    return this->gender;
}

int CartaIdentita::ottieniAltezza() const {
    return this->altezza;
}

void CartaIdentita::settaNome(string nuovoNome) {
    this->nome = nuovoNome;
}

void CartaIdentita::settaCognome(string nuovoCognome) {
    this->cognome = nuovoCognome;
}

void CartaIdentita::settaNazionalita(string nuovaNazionalita) {
    this->nazionalita = nuovaNazionalita;
}

void CartaIdentita::settaGender(Gender nuovoGender) {
    this->gender = nuovoGender;
}

void CartaIdentita::settaAltezza(int nuovaAltezza) {
    this->altezza = nuovaAltezza;
}

void CartaIdentita::stampaInfo() const {
        cout << "----------------\n";
        cout << "Oggetto Carta Identita'\n";
        cout << "Identificativo: " << this->id << "\n";
        cout << "Nome: " << this->nome << "\n";
        cout << "Cognome: " << this->cognome << "\n";
        cout << "Luogo di nascita: " << this->luogoDiNascita << "\n";
        cout << "Data di nascita: " << this->dataDiNascita << "\n";
        cout << "Nazionalita': " << this->nazionalita << "\n";

        // cout << "Gender:" << this->gender << "\n"; 
        if (this->gender == CartaIdentita::M) {
            cout << "Gender: M" << "\n"; 
        }
        else if (this->gender == CartaIdentita::F) {
            cout << "Gender: F" << "\n"; 
        }
        else {
            cout << "Gender: N" << "\n"; 
        }
        
        cout << "Altezza: " << to_string(this->altezza) << "\n";
        cout << "----------------" << endl;
}