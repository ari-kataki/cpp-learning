#include "officina.h"

Officina::Officina(string nome, list<Automobile> listaAuto): nome(nome), listaAuto(listaAuto)
{
}

string Officina::ottieniNome() const
{
    return this->nome;
}

list<Automobile> Officina::ottieniListaAuto() const
{
    return this->listaAuto;
}

void Officina::settaNome(string nuovoNome)
{
    this->nome = nuovoNome;
}

void Officina::settaListaAuto(list<Automobile> nuovaLista)
{
    this->listaAuto = nuovaLista;
}

bool Officina::salvaNelFile(string nomeFile) const
{
    bool risultato{true};

    try {
        ofstream fileScrittura(nomeFile);

        for(Automobile automobile: this->listaAuto) {
            string riga{automobile.ottieniTelaio() + ","};
            riga += automobile.ottieniMarca() + ",";
            riga += automobile.ottieniModello() + ",";
            riga += to_string(automobile.ottieniKmPercorsi()) + ",";
            riga += to_string(automobile.ottieniNumeroControlli()) + "\n";

            fileScrittura << riga;
        }

        fileScrittura.close();
    }
    catch (...) {
        cout << "Errore nell'apertura del file "
             << nomeFile
             << " in scrittura!";
        risultato = false;
    }

    return risultato;
}

bool Officina::caricaDalFile(string nomeFile)
{
    bool risultato{true};

    try {
        ifstream fileLettura(nomeFile);
        this->listaAuto.clear();

        string riga{};

        while (getline(fileLettura, riga)) {
            list<string> campi{dividi(riga, ',')};

            if (!campi.empty()) {
                auto iteratore{campi.begin()};
                string telaio = *iteratore++;
                string marca = *iteratore++;
                string modello = *iteratore++;
                string kmPercorsiStringa = *iteratore++;
                string numeroControlliStringa = *iteratore;

                float kmPersorsi = stof(kmPercorsiStringa);
                int numeroControlli = stoi(numeroControlliStringa);

                Automobile automobile(telaio, marca, modello, kmPersorsi, numeroControlli);
                this->listaAuto.push_back(automobile);
            }
        }

        fileLettura.close();
    }
    catch (...) {
        cout << "Errore nell'apertura del file "
             << nomeFile
             << " in lettura!";
        risultato = false;
    }

    return risultato;
}
