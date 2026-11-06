#include "automobile.h"

Automobile::Automobile(string telaio, string marca, string modello, float kmPercorsi, int numeroControlli): 
                telaio(telaio),
                marca(marca),
                modello(modello) {
    this->kmPercorsi = kmPercorsi;
    this->numeroControlli = numeroControlli;
}

string Automobile::ottieniTelaio() const {
    return this->telaio;
}

string Automobile::ottieniMarca() const {
    return this->marca;
}

string Automobile::ottieniModello() const {
    return this->modello;
}

float Automobile::ottieniKmPercorsi() const {
    return this->kmPercorsi;
}

int Automobile::ottieniNumeroControlli() const {
    return this->numeroControlli;
}

void Automobile::modificaKmPercorsi(float kmPercorsi) {
    if (kmPercorsi < 0) {
        cout << "Input inserito non valido";
    }
    else {
        this->kmPercorsi += kmPercorsi;
    }
}

void Automobile::incrementaControlli() {
    this->numeroControlli++;
}

void Automobile::stampaInfo() {
    cout << "----------------\n";
    cout << "Oggetto Automobile\n";
    cout << "Telaio: " << this->telaio << "\n";
    cout << "Marca: " << this->marca << "\n";
    cout << "Modello: " << this->modello << "\n";
    cout << "Km percorsi: " << this->kmPercorsi << "\n";
    cout << "Numero controlli: " << this->numeroControlli << endl;
}