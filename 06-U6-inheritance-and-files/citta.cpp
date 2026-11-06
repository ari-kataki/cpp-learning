#include "citta.h"

Citta::Citta(string nome, list<CartaIdentita*> listaCarteIdentita)
    : nome(nome), listaCarteIdentita(listaCarteIdentita) {
}

string Citta::ottieniNome() const {
    return this->nome;
}

list<CartaIdentita*> Citta::ottieniListaCarteIdentita() const {
    return this->listaCarteIdentita;
}

bool Citta::salvaNelFile(string nomeFile) const {
    bool risultato{true};

    try {
        ofstream fileScrittura(nomeFile);

        for (CartaIdentita* cartaIdentita : this->listaCarteIdentita) {
            string riga{cartaIdentita->ottieniId() + ","};
            riga += cartaIdentita->ottieniNome() + ",";
            riga += cartaIdentita->ottieniCognome() + ",";
            riga += cartaIdentita->ottieniLuogoDiNascita() + ",";
            riga += cartaIdentita->ottienidataDiNascita() + ",";

            switch (cartaIdentita->ottieniGender()) {
            case CartaIdentita::M:
                riga += "M,";
                break;

            case CartaIdentita::F:
                riga += "F,";
                break;

            case CartaIdentita::N:
            default:
                riga += "N,";
                break;
            }

            riga += to_string(cartaIdentita->ottieniAltezza()) + ",";
            riga += cartaIdentita->ottieniNazionalita() + "\n";

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

bool Citta::caricaDalFile(string nomeFile) {
    bool risultato{true};

    this->listaCarteIdentita.clear();

    try {
        ifstream fileLettura(nomeFile);

        string riga{};

        while (getline(fileLettura, riga)) {

            list<string> campi{dividi(riga, ',')};

            if (!campi.empty()) {

                auto iteratore{campi.begin()};

                string id{*iteratore++};
                string nome{*iteratore++};
                string cognome{*iteratore++};
                string luogoNascita{*iteratore++};
                string dataNascita{*iteratore++};
                string genereStringa{*iteratore++};
                string altezzaStringa{*iteratore++};
                string nazionalita{*iteratore};

                CartaIdentita::Gender genere{};

                if (genereStringa == "M") {
                    genere = CartaIdentita::M;
                }
                else if (genereStringa == "F") {
                    genere = CartaIdentita::F;
                }
                else {
                    genere = CartaIdentita::N;
                }

                int altezza{stoi(altezzaStringa)};

                CartaIdentita* cartaIdentita{
                    new CartaIdentita(
                        id,
                        nome,
                        cognome,
                        luogoNascita,
                        dataNascita,
                        nazionalita,
                        genere,
                        altezza
                    )
                };

                this->listaCarteIdentita.push_back(cartaIdentita);
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