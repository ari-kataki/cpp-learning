#pragma once

#include <iostream>
#include <list>
#include <random>
#include <string>
#include <vector>
#include <cfloat>

using namespace std;

#define ORDINE_CRESCENTE   0
#define ORDINE_DECRESCENTE 1

double ottieniDoubleUtente(string messaggio, double valoreMinimo = -DBL_MAX, double valoreMassimo = DBL_MAX);
int ottieniInteroCasuale(int minimo, int massimo);
int ottieniInteroUtente(string messaggio, int valoreMinimo = INT32_MIN, int valoreMassimo = INT32_MAX);
string ottieniStringaUtente(string messaggio);
list<string> dividi(string stringaOrigine, char delimitatore);
void stampaIntArray(int intArray[], int dimensione);
void stampaStringArray(string stringArray[], int dimensione);

// Funzioni per l'ordinamento di elementi all'interno di array di interi
void applicaBubbleSort(int intArray[], int dimensione, bool tipoDiOrdine);
void applicaSelectionSort(int intArray[], int dimensione, bool tipoDiOrdine);
void scambiaElemento(int* elemento0, int* elemento1);

// Funzioni per la ricerca di elementi all'interno di array di interi
bool applicaRicercaBinaria(int intArray[], int dimensione, int elementoDaRicercare);
bool applicaRicercaSequenziale(int intArray[], int dimensione, int elementoDaRicercare);