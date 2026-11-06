#pragma once

#include <iostream>

using namespace std;

class Automobile {
private:
    string telaio, marca, modello;
    float kmPercorsi;
    int numeroControlli;

public:
    Automobile(string telaio, string marca, string modello, float kmPercorsi, int numeroControlli);

    string ottieniTelaio() const;
    string ottieniMarca() const;
    string ottieniModello() const;
    float ottieniKmPercorsi() const;
    int ottieniNumeroControlli() const;

    void modificaKmPercorsi(float kmPercorsi);
    void incrementaControlli();

    void stampaInfo();
};