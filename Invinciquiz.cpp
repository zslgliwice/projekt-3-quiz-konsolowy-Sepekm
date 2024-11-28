#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

string imie;
string odp;

void displayQuestion(const string& question, const string& a, const string& b, const string& c, const string& correctAnswer, int& pkt) {
    cout << question << endl;
    cout << "a) " << a << endl;
    cout << "b) " << b << endl;
    cout << "c) " << c << endl;
    cout << "Twoja odpowiedz: ";
    cin >> odp;
    if (odp == correctAnswer || odp == string(1, toupper(correctAnswer[0]))) {
        cout << "Poprawna odpowiedz!\n";
        pkt++;
    } else {
        cout << "Zle! Poprawna odpowiedz to: " << correctAnswer << endl;
    }
    Sleep(3000);
    system("cls");
}

int main() {
    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(uchwyt, 12);

    cout << "Podaj imie: ";
    cin >> imie;
    int pkt = 0;

    system("cls");
    cout << imie << ", witaj w tescie z Invincible!\n";
    Sleep(3000);
    system("cls");

    displayQuestion("Kim jest ojciec Invincible?", "Omni-Man", "Robot", "Atom Eve", "a", pkt);
    displayQuestion("Jak ma na imię główny bohater, Invincible?", "Mark Grayson", "Eve Wilkins", "Rex Sloan", "a", pkt);
    displayQuestion("Kto NIE jest członkiem Teen Team?", "Rex Splode", "Dupli-Kate", "The Immortal", "c", pkt);
    displayQuestion("Jaką moc posiada Atom Eve?", "Super siła", "Latanie i tworzenie energii", "Czytanie w myślach", "b", pkt);
    displayQuestion("Kto zdradził Guardians of the Globe?", "Omni-Man", "Robot", "Black Samson", "a", pkt);

    cout << "Gratulacje, ukonczyles quiz!\n";
    cout << "Twoja liczba punktow wynosi: " << pkt << "/5.\n";
    if(pkt < 2) {
        cout << "Może warto jeszcze raz obejrzeć serial?\n";
    } else if(pkt == 3 || pkt == 4) {
        cout << "Nieźle! Jesteś na dobrej drodze, aby stać się ekspertem.\n";
    } else {
        cout << "Świetnie! Znasz Invincible jak własną kieszeń!\n";
    }

    return 0;
}
