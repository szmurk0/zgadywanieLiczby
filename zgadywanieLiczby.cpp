#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

class GraZgadywanka {
private:
    int liczbaDoOdgadniecia; // Liczba, którą gracz musi odgadnąć
    int liczbaProb; // Liczba prób odgadnięcia

public:
    GraZgadywanka() {
        // Inicjalizacja generatora liczb pseudolosowych
        srand(static_cast<unsigned int>(time(0)));
        // Losowanie liczby z zakresu 1-100
        liczbaDoOdgadniecia = rand() % 100 + 1;
        liczbaProb = 0;
    }

    void rozpocznijGre() {
        setlocale(LC_CTYPE, "Polish"); // Polskie znaki

        cout << "Witaj w grze w zgadywanie liczby!\n"; // Komunikaty
        cout << "Zgadnij liczbę z zakresu 1-100.\n";

        int propozycja; // Zainicjowanie zmiennej Integer propozycja, będzie przechowywać dane wpisane przez użytkownika.
        do {
            cout << "Podaj swoją propozycję: ";
            cin >> propozycja;
            ++liczbaProb;

            if (propozycja == liczbaDoOdgadniecia) {
                cout << "Gratulacje! Odgadłeś liczbę w " << liczbaProb << " próbach.\n";
            }
            else if (propozycja < liczbaDoOdgadniecia) {
                cout << "Za mało. Spróbuj ponownie.\n";
            }
            else {
                cout << "Za dużo. Spróbuj ponownie.\n";
            }

        } while (propozycja != liczbaDoOdgadniecia); // Główna pętla programu (działa do momentu odgadnięcia liczby przez użytkownika)
    }
};

int main() {
    GraZgadywanka gra; // Utworzenie obiektu gry
    gra.rozpocznijGre(); // Rozpoczęcie gry

    return 0; // Zakończenie programu
    // Program wykonany przez Oskar Szmurło 3P
}
