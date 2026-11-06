#define ESEMPIO      0
#define ESERCIZIO_1  1
#define ESERCIZIO_2  2
#define ESERCIZIO_3  3
#define ESERCIZIO_4  4
#define ESERCIZIO_5  5
#define ESERCIZIO_6  6
#define ESERCIZIO_7  7 
#define ESERCIZIO_8  8 

#define ESERCIZIO ESERCIZIO_7

#define M_PI 3.14

#include <iostream>
#include <cstdint>
#include <list>
#include <string>
#include <random>
#include <vector>
#include <cfloat>

using namespace std;

double ottieniDoubleUtente(string messaggio, double valoreMinimo = -DBL_MAX, double valoreMassimo = DBL_MAX);
int ottieniInteroUtente(string messaggio, int valoreMinimo = INT32_MIN, int valoreMassimo = INT32_MAX);
string ottieniStringaUtente(string messaggio);

class MathITS {
private:
    double baseNumerica;
    static int contatoreOggetti;

public:
    MathITS(double baseNumerica) {
        this->baseNumerica = baseNumerica;
        contatoreOggetti++;
    }

    double calcolaRadice() {
        double risultato = sqrt(this->baseNumerica);
        return risultato;
    }

    double calcolaPotenza(int esponente) {
        double risultato = pow(baseNumerica, esponente);
        return risultato;
    }

    static int ottieniContatoreOggetti() {
        return MathITS::contatoreOggetti;
    }
};

class Cerchio {
    private:
    double r;

    public:
    Cerchio(double r) {
        this->r = r;
    }

    double ottieniDiametro() {
        return r*2;
    }

    double ottieniPerimetro() {
        return 2 * M_PI * r;
    }

    double ottieniArea() {
        return M_PI * pow(r, 2);
    }

    Cerchio ottieniSommaCerchio(Cerchio c) {
        Cerchio nuovoCerchio(this->r + c.r);
        return nuovoCerchio;
    }

    void stampaInfo() {
        cout << "----------------\n";
        cout << "Oggetto CERCHIO\n";
        cout << "Raggio: " << this->r << "\n";
        cout << "Diametro: " << this->ottieniDiametro() << "\n";
        cout << "Perimetro: " << this->ottieniPerimetro() << "\n";
        cout << "Area: " << this->ottieniArea() << "\n";
        cout << "----------------" << endl;
    }
};

class Squadra {
    private:
        string nome;
        int numeroPartitePerse, numeroPartitePareggiate, numeroPartiteVinte;

    public:
        Squadra(string nome, int numeroPartitePerse, 
            int numeroPartitePareggiate, int numeroPartiteVinte): nome(nome) {
            this->numeroPartitePerse = numeroPartitePerse;
            this->numeroPartitePareggiate = numeroPartitePareggiate;
            this->numeroPartiteVinte = numeroPartiteVinte;
        }

        void aggiungiPartitePerse() {
            this->numeroPartitePerse++;
        }

        void aggiungiPartitePareggiate() {
            this->numeroPartitePareggiate++;
        }

        void aggiungiPartiteVinte() {
            this->numeroPartiteVinte++;
        }

        int calcolaPunti() {
            int punti = this->numeroPartiteVinte*3 + this->numeroPartitePareggiate;
            return punti;
        }

        int calcolaPartiteGiocate() {
            int partiteGiocate = this->numeroPartiteVinte 
            + this->numeroPartitePareggiate + this->numeroPartitePerse;
            return partiteGiocate;
        }

        double calcolaMediaPunti() {
            double mediaPunti = static_cast<double>(this->calcolaPunti()) / static_cast<double>(this->calcolaPartiteGiocate());
            return mediaPunti;
        }

        void stampaInfo() {
            string s = this->nome;
            s += ",\t" + to_string(this->numeroPartitePerse);
            s += ",\t" + to_string(this->numeroPartitePareggiate);
            s += ",\t" + to_string(this->numeroPartiteVinte);
            s += ",\t" + to_string(this->calcolaPartiteGiocate());
            s += ",\t" + to_string(this->calcolaPunti());
            s += ",\t" + to_string(this->calcolaMediaPunti());
            cout << s << endl;
        }
};

class Studente {
    private:
        string nome, cognome;
        double mediaVoto;
        int numeroInsufficienze;

    public:
        Studente(string nome, string cognome, double mediaVoto, int numeroInsufficienze): nome(nome), cognome(cognome) {
            this->mediaVoto = mediaVoto;
            this->numeroInsufficienze = numeroInsufficienze;
        }

        string ottieniNome() {
            return this->nome;
        }

        string ottieniCognome() {
            return this->cognome;
        }

        double ottieniMediaVoto() {
            return this->mediaVoto;
        }

        int ottieniNumeroInsufficienze() {
            return this->numeroInsufficienze;
        }

        void settaNome(string nuovoNome) {
            this->nome = nuovoNome;
        }

        void settaCognome(string nuovoCognome) {
            this->cognome = nuovoCognome;
        }

        void settaMediaVoto(double nuovaMediaVoto) {
            this->mediaVoto = nuovaMediaVoto;
        }

        void settaNumeroInsufficienze(int nuovoNI) {
            this->numeroInsufficienze = nuovoNI;
        }

        bool verificaRecuperoEstivo() {
            return (numeroInsufficienze > 0);
        }

        bool verificaBocciatura() {
            return (mediaVoto < 6.0);
        }

        void stampaInfo() {
            string s = "Studente: " + this->nome + " " + this->cognome + "\n";
            string esitoRecuperoEstivo = this->verificaRecuperoEstivo() ? "Recupero estivo: SI\n" : "Recupero estivo: NO\n";
            s += esitoRecuperoEstivo;
            string esitoBocciatura = this->verificaBocciatura() ? "Rischio bocciatura: SI\n" : "Rischio bocciatura: NO\n";
            s += esitoBocciatura;
            cout << s << endl;
        }
};

class Scuola {
    private:
        string nome;
        list<Studente> listaStudenti;

    public:
        Scuola(string nome, list<Studente> lS): nome(nome), listaStudenti(lS) {}

        void stampaDatiStudenti() {
            cout << "--------------------------------\n";
            int numeroStudentiRimandati{};
            int numeroStudentiRischioBocciatura{};
            for(Studente s: listaStudenti) {
                if(s.verificaRecuperoEstivo()) {
                    numeroStudentiRimandati++;
                }

                if(s.verificaBocciatura()) {
                    numeroStudentiRischioBocciatura++;
                }

                s.stampaInfo();
            }

            cout << "Numero studenti rimandati: " << numeroStudentiRimandati << "\n";
            cout << "Numero studenti rischio bocciatura: " << numeroStudentiRischioBocciatura << "\n";
            cout << "--------------------------------" << endl;
        }

        void stampaStudenteMigliore() {
            cout << "--------------------------------\n";
            auto iteratore = listaStudenti.begin();
            Studente studenteMigliore = *iteratore;
            for(int i = 1; i < listaStudenti.size(); i++) {
                iteratore++;
                Studente studente = *iteratore;
                if(studente.ottieniMediaVoto() > studenteMigliore.ottieniMediaVoto()) {
                    studenteMigliore = studente;
                }
            }
            cout << "Studente migliore della scuola: " << studenteMigliore.ottieniNome() 
            << " " << studenteMigliore.ottieniCognome() << "\n"; 
            cout << "--------------------------------" << endl;
        }
};

class ClienteBanca
{
private:
    int identificativo = 0;
    string nome = "", cognome = "";
    double saldo = 0.0;

public:
    ClienteBanca(int id, string n, string c, double s) {
        this->identificativo = id;
        this->nome = n;
        this->cognome = c;
        this->saldo = s;
    }

    int ottieniIdentificativo() const {
        return this->identificativo;
    }

    string ottieniNome() const {
        return this->nome;
    }

    string ottieniCognome() const {
        return this->cognome;
    }

    double ottieniSaldo() const {
        return this->saldo;
    }

    void settaSaldo(double s) {
        this->saldo = s;
    }

    void eseguiTransazione(double s) {
        this->saldo += s;
    }

    bool controllaInRosso() const {
        return this->saldo < 0;
    }

    void stampaInfo() const {
        cout << "Identificativo: " << identificativo << ";\n";
        cout << "Nome e cognome: " << nome << " " << cognome << ";\n";
        cout << "Saldo: " << saldo << ";\n";
    }
};

class Banca
{
private:
    string nome;
    list<ClienteBanca> listaClienti;

public:
    Banca(string n, list<ClienteBanca> l) {
        this->nome = n;
        this->listaClienti = l;
    }

    void stampaTuttiClienti() const{
        for (ClienteBanca cliente : this->listaClienti) {
            cliente.stampaInfo();
        }
    }

    void eseguiTransazioni() {
        bool trovato = true;
        int id_utente = 0;
        double importo = 0.0;

        while (trovato) {
            id_utente = ottieniInteroUtente("Inserisci l'identificativo dell'account bancario: ");
            trovato = false;

            for (ClienteBanca& cliente : this->listaClienti) {
                if (cliente.ottieniIdentificativo() == id_utente) {
                    trovato = true;
                    importo = ottieniDoubleUtente(
                        "Inserisci l'importo della transazione per l'account bancario con identificativo " +
                        to_string(id_utente) + ": ");
                    cliente.eseguiTransazione(importo);
                    break;
                }
            }
        }
    }

    void stampaClientiInRosso() const{
        cout << "Stampa dei clienti in rosso:\n";
        for (ClienteBanca cliente : this->listaClienti) {
            if (cliente.controllaInRosso()) {
                cliente.stampaInfo();
            }
        }
    }
};

enum Stato { ACCESO, SPENTO };
enum Marcia { RETROMARCIA, FOLLE, PRIMA, SECONDA, TERZA, QUARTA, QUINTA, SESTA, SETTIMA, OTTAVA };

class Auto
{
private:
    string marca, modello, colore;
    double cilindrata, livelloSerbatoio, capacitaMassimaSerbatoio;
    Marcia marcia_massima;
    Marcia marcia;
    Stato stato;

public:
    Auto(string ma, string mo, string co, double ci, double cap_max, Marcia mar_max) {
        marca = ma;
        modello = mo;
        colore = co;
        cilindrata = ci;
        capacitaMassimaSerbatoio = cap_max;
        marcia_massima = mar_max;

        livelloSerbatoio = 0.0;
        marcia = FOLLE;
        stato = SPENTO;
    }

    void aumentaSerbatoio(double incremento) {
        double nuovo_livello = livelloSerbatoio + incremento;

        if (nuovo_livello > capacitaMassimaSerbatoio) {
            livelloSerbatoio = capacitaMassimaSerbatoio;
        }
        else {
            livelloSerbatoio = nuovo_livello;
        }
    }

    void aumentaMarcia() {
        if (stato == ACCESO) {
            if ((int)marcia < (int)marcia_massima) {
                marcia = Marcia((int)marcia + 1);
            }
        }
    }

    void diminuisciMarcia() {
        if (stato == ACCESO) {
            if ((int)marcia > (int)(RETROMARCIA)) {
                marcia = Marcia((int)marcia - 1);
            }
        }
    }

    void gestisciStato() {
        if (stato == SPENTO) {
            stato = ACCESO;
        }
        else {
            stato = SPENTO;
        }
    }

    void stampaDati() const{
        cout << "Dati Auto:" << "\n";
        cout << "Marca: " << marca << "\n";
        cout << "Modello: " << modello << "\n";
        cout << "Colore: " << colore << "\n";
        cout << "Cilindrata: " << cilindrata << " cm^3" << "\n";
        cout << "Livello serbatoio: " << livelloSerbatoio << " L" << "\n";
        cout << "Capacita' serbatoio: " << capacitaMassimaSerbatoio << " L" << "\n";
        cout << "Marcia inserita: " << marcia << "\n";
        cout << "Marcia massima: " << marcia_massima << "\n";
        cout << "Stato: " << stato << "\n";
    }
};

class DataOra {
private:
    int giorno = 0;
    int mese = 0;
    int anno = 0;
    int ora = 0;
    int minuto = 0;

public:
    DataOra() {}

    DataOra(int nuovoGiorno, int nuovoMese, int nuovoAnno, int nuovaOra, int nuovoMinuto) {
        giorno = nuovoGiorno;
        mese = nuovoMese;
        anno = nuovoAnno;
        ora = nuovaOra;
        minuto = nuovoMinuto;
    }

    long long ottieniMinutiTotali() {
        long long risultato = 0;
        risultato += minuto;
        risultato += ora * 60;
        risultato += giorno * 24 * 60;
        risultato += mese * 30 * 24 * 60;
        risultato += (anno - 2000) * 12 * 30 * 24 * 60;
        return risultato;
    }

    bool vienePrimaDi(DataOra dataOra) {
        bool risultato = false;

        if (this->ottieniMinutiTotali() <= dataOra.ottieniMinutiTotali()) {
            risultato = true;
        }

        return risultato;
    }

    bool vieneDopoDi(DataOra dataOra) {
        bool risultato = false;

        if (this->ottieniMinutiTotali() >= dataOra.ottieniMinutiTotali()) {
            risultato = true;
        }

        return risultato;
    }

    string ottieniInfo() {
        string risultato = "";
        risultato += "Data: " + to_string(giorno) + "/" + to_string(mese)
            + "/" + to_string(anno) + "; ";
        risultato += "Ora: " + to_string(ora) + ":" + to_string(minuto) + ";";
        return risultato;
    }
};

class Treno {
private:
    int identificativo = 0;
    string destinazione = "";
    DataOra partenza;
    DataOra arrivo;

public:
    Treno() {}

    Treno(int nuovoIdentificativo, string nuovaDestinazione, DataOra nuovaPartenza, DataOra nuovoArrivo)
        : partenza(nuovaPartenza), arrivo(nuovoArrivo) {
        identificativo = nuovoIdentificativo;
        destinazione = nuovaDestinazione;
    }

    string ottieniDestinazione() {
        return destinazione;
    }

    void impostaDestinazione(string nuovaDestinazione) {
        destinazione = nuovaDestinazione;
    }

    DataOra ottieniPartenza() {
        return partenza;
    }

    void impostaPartenza(DataOra nuovaPartenza) {
        partenza = nuovaPartenza;
    }

    DataOra ottieniArrivo() {
        return arrivo;
    }

    void impostaArrivo(DataOra nuovoArrivo) {
        arrivo = nuovoArrivo;
    }

    void stampaInfo() {
        cout << "Id treno: " << identificativo << "\n";
        cout << "Destinazione del treno: " << destinazione << "\n";
        cout << "Orario di partenza del treno: " << partenza.ottieniInfo() << "\n";
        cout << "Orario di arrivo treno: " << arrivo.ottieniInfo() << "\n";
    }
};

class Stazione {
private:
    string nome = "";
    list<Treno> elencoTreni;

public:
    Stazione(string nuovoNome, list<Treno> nuovoElencoTreni) {
        nome = nuovoNome;
        elencoTreni = nuovoElencoTreni;
    }

    void ottieniTreniPerDestinazione(string destinazioneCercata) {
        cout << "Elenco dei treni che partono per " << destinazioneCercata << ":\n";

        for (Treno treno : elencoTreni) {
            if (treno.ottieniDestinazione() == destinazioneCercata) {
                treno.stampaInfo();
            }
        }
    }

    void ottieniTreniPerPartenza(DataOra inizio, DataOra fine) {
        cout << "Elenco dei treni che partono tra " << inizio.ottieniInfo()
            << " e " << fine.ottieniInfo() << ":\n";

        for (Treno treno : elencoTreni) {
            if (treno.ottieniPartenza().vieneDopoDi(inizio) &&
                treno.ottieniPartenza().vienePrimaDi(fine)) {
                treno.stampaInfo();
            }
        }
    }
};

// Inizializzazione della variabile statica
int MathITS::contatoreOggetti = 0;

int main() {
#if ESERCIZIO == ESERCIZIO_1
    cout << "Esercizio 1" << endl;

    MathITS m0(4.0);
    MathITS* m1 = new MathITS(5.0);

    cout << "La radice dell'oggetto m0 e': " << m0.calcolaRadice() << "\n";
    cout << "La radice dell'oggetto m1 e': " << m1->calcolaRadice() << "\n";

    cout << "La potenza alla seconda dell'oggetto m0 e': " << m0.calcolaPotenza(2) << "\n";
    cout << "La potenza alla terza dell'oggetto m1 e': " << m1->calcolaPotenza(3) << "\n";

    cout << "Oggetti MathITS creati: " << MathITS::ottieniContatoreOggetti() << endl;
#elif ESERCIZIO == ESERCIZIO_2
    cout << "Esercizio 2" << endl;

    Cerchio* c1 = new Cerchio(ottieniDoubleUtente("Inserisci il raggio del cerchio 1: "));
    Cerchio* c2 = new Cerchio(ottieniDoubleUtente("Inserisci il raggio del cerchio 2: "));

    c1->stampaInfo();
    c2->stampaInfo();

    Cerchio c3 = c1->ottieniSommaCerchio(*c2);
    c3.stampaInfo();
#elif ESERCIZIO == ESERCIZIO_3
    cout << "Esercizio 3" << endl;

    int n = ottieniInteroUtente("Inserisci il numero di oggetti Squadra da creare: ", 1);
    list<Squadra> squadre;

    for(int i = 0; i < n; i++) {
        string nome = ottieniStringaUtente("Inserisci il nome della squadra in posizione " + to_string(i + 1) + ": ");
        int numeroPPe = ottieniInteroUtente("Inserisci il numero di partite perse della squadra in posizione " + to_string(i + 1) + ": ", 0);
        int numeroPPa = ottieniInteroUtente("Inserisci il numero di partite pareggiate della squadra in posizione " + to_string(i + 1) + ": ", 0);
        int numeroPV = ottieniInteroUtente("Inserisci il numero di partite vinte della squadra in posizione " + to_string(i + 1) + ": ", 0);

        Squadra s(nome, numeroPPe, numeroPPa, numeroPV);
        squadre.push_back(s);
    }

    cout << "Nome,\tNPPe,\tNPPa,\tNPV,\tNPG,\tP,\tMP" << endl;
    for(Squadra s: squadre) {
        s.stampaInfo();
    }
#elif ESERCIZIO == ESERCIZIO_4
    cout << "Esercizio 4" << endl;

    int n = ottieniInteroUtente("Inserisci il numero di oggetti Studente da creare: ", 1);
    list<Studente> studenti;

    for (int i = 0; i < n; i++) {
        string nome = ottieniStringaUtente("Inserisci il nome dello studente in posizione " + to_string(i + 1) + ": ");
        string cognome = ottieniStringaUtente("Inserisci il cognome dello studente in posizione " + to_string(i + 1) + ": ");
        double mediaVoto = ottieniDoubleUtente("Inserisci la media voto dello studente in posizione " + to_string(i + 1) + ": ");
        int numeroInsufficienze = ottieniInteroUtente("Inserisci il numero di insufficienze dello studente in posizione " + to_string(i + 1) + ": ");

        Studente* s = new Studente(nome, cognome, mediaVoto, numeroInsufficienze);
        studenti.push_back(*s);
        delete s;
    }

    Scuola scuola("ITS", studenti);
    scuola.stampaStudenteMigliore();
    scuola.stampaDatiStudenti();
#elif ESERCIZIO == ESERCIZIO_5
    cout << "Esercizio 5" << endl;

	list<ClienteBanca> listaClienti;

	int dimensione = ottieniInteroUtente("Digita il numero di clienti da creare: ");
	for (int i = 0; i < dimensione; i++) {
		int identificativo = ottieniInteroUtente("Inserisci l'identificativo del cliente in posizione " + to_string(i + 1) + ": ");
		string nome = ottieniStringaUtente("Inserisci il nome del cliente in posizione " + to_string(i + 1) + ": ");
		string cognome = ottieniStringaUtente("Inserisci il cognome del cliente in posizione " + to_string(i + 1) + ": ");
		double saldo = ottieniDoubleUtente("Inserisci il saldo iniziale del cliente in posizione " + to_string(i + 1) + ": ");

		ClienteBanca cliente(identificativo, nome, cognome, saldo);
		listaClienti.push_back(cliente);
	}

	string nomeBanca = ottieniStringaUtente("Inserisci il nome della banca: ");
	Banca banca(nomeBanca, listaClienti);

	banca.stampaTuttiClienti();
	banca.eseguiTransazioni();
	banca.stampaTuttiClienti();
	cout << endl;
	banca.stampaClientiInRosso();
#elif ESERCIZIO == ESERCIZIO_6
    cout << "Esercizio 6" << endl;

	string marca = ottieniStringaUtente("Inserisci la marca dell'auto: ");
	string modello = ottieniStringaUtente("Inserisci il modello dell'auto: ");
	string colore = ottieniStringaUtente("Inserisci il colore dell'auto: ");
	double cilindrata = ottieniDoubleUtente("Inserisci la cilindrata dell'auto: ");
	double capacita_massima = ottieniDoubleUtente("Inserisci la capacità massima del serbatoio: ");
	int marcia_max = ottieniInteroUtente("Inserisci la marcia massima: ", 0, 9);

	Auto autoCreata(marca, modello, colore, cilindrata, capacita_massima, Marcia(marcia_max));
	autoCreata.stampaDati();
#elif ESERCIZIO == ESERCIZIO_7
    cout << "Esercizio 7" << endl;

    list<DataOra> elencoDateOra;
    int numeroDateOra = ottieniInteroUtente("Inserisci il numero di oggetti DataOra: ");

    for (int i = 0; i < numeroDateOra; i++) {
        int giorno = ottieniInteroUtente("Inserisci il giorno dell'oggetto DataOra in posizione " + to_string(i + 1) + ": ");
        int mese = ottieniInteroUtente("Inserisci il mese dell'oggetto DataOra in posizione " + to_string(i + 1) + ": ");
        int anno = ottieniInteroUtente("Inserisci l'anno dell'oggetto DataOra in posizione " + to_string(i + 1) + ": ");
        int ora = ottieniInteroUtente("Inserisci l'ora dell'oggetto DataOra in posizione " + to_string(i + 1) + ": ");
        int minuto = ottieniInteroUtente("Inserisci il minuto dell'oggetto DataOra in posizione " + to_string(i + 1) + ": ");

        DataOra dataOra(giorno, mese, anno, ora, minuto);
        elencoDateOra.push_back(dataOra);
    }

    list<Treno> elencoTreni;
    int numeroTreni = ottieniInteroUtente("Inserisci il numero di oggetti Treno: ");

    for (int i = 0; i < numeroTreni; i++) {
        int identificativo = ottieniInteroUtente("Inserisci l'identificativo dell'oggetto Treno in posizione " + to_string(i + 1) + ": ");
        string destinazione = ottieniStringaUtente("Inserisci la destinazione dell'oggetto Treno in posizione " + to_string(i + 1) + ": ");

        int indiceDataOra = ottieniInteroUtente("Inserisci l'id della partenza dell'oggetto Treno in posizione " + to_string(i + 1) + ": ", 0, (int)elencoDateOra.size());
        list<DataOra>::iterator iteratoreDataOra = elencoDateOra.begin();
        advance(iteratoreDataOra, indiceDataOra);
        DataOra partenza = *iteratoreDataOra;

        indiceDataOra = ottieniInteroUtente("Inserisci l'id dell'arrivo dell'oggetto Treno in posizione " + to_string(i + 1) + ": ", 0, (int)elencoDateOra.size());
        iteratoreDataOra = elencoDateOra.begin();
        advance(iteratoreDataOra, indiceDataOra);
        DataOra arrivo = *iteratoreDataOra;

        Treno treno(identificativo, destinazione, partenza, arrivo);
        elencoTreni.push_back(treno);
    }

    cout << endl;

    Stazione stazione("Foligno", elencoTreni);
    stazione.ottieniTreniPerDestinazione("Perugia");
    list<DataOra>::iterator iteratoreDataOra = elencoDateOra.begin();
    DataOra inizio = *iteratoreDataOra;
    advance(iteratoreDataOra, ((int)elencoDateOra.size() - 1));
    DataOra fine = *iteratoreDataOra;
    stazione.ottieniTreniPerPartenza(inizio, fine);
#elif ESERCIZIO == ESERCIZIO_8
    cout << "Esercizio 8" << endl;

    //TODO
#endif
    return 0;
}

double ottieniDoubleUtente(string messaggio, double valoreMinimo, double valoreMassimo) {
    double doubleUtente{};
    string doubleUtenteStringa{};

    do {
        cout << messaggio;
        getline(cin, doubleUtenteStringa);
        doubleUtente = stod(doubleUtenteStringa);
    } while (doubleUtente < valoreMinimo || doubleUtente > valoreMassimo);

    return doubleUtente;
}

int ottieniInteroUtente(string messaggio, int valoreMinimo, int valoreMassimo) {
    int interoUtente{};
    string interoUtenteStringa{};

    do {
        cout << messaggio;
        getline(cin, interoUtenteStringa);
        interoUtente = stoi(interoUtenteStringa);
    } while (interoUtente < valoreMinimo || interoUtente > valoreMassimo);

    return interoUtente;
}

string ottieniStringaUtente(string messaggio) {
    string stringaUtente{};
    cout << messaggio;
    getline(cin, stringaUtente);
    return stringaUtente;
}