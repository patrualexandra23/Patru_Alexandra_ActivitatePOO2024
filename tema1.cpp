#include<iostream>
using namespace std;

struct Bloc {

    string strada;
    int nrScari;
    int nrApartamente;
    int anConstructie;
    float suprafata;


};

void citireBloc(Bloc& bloc) {
    cout << "Introduceti caracteristicile pentru un bloc:\n";

    cout << "Strada: ";
    cin >> bloc.strada;

    cout << "Numar de scari: ";
    cin >> bloc.nrScari;

    cout << "Numar de apartamente: ";
    cin >> bloc.nrApartamente;

    cout << "Anul construnctiei: ";
    cin >> bloc.anConstructie;

    cout << "Suprafata: ";
    cin >> bloc.suprafata;




}



void afisareBloc(const Bloc& bloc) {
    cout << "Blocul de pe strada" << bloc.strada << ",are" << bloc.nrScari << "scari," << bloc.nrApartamente << "apartamente,a fost construit in anul" << bloc.anConstructie << "si are o suprafata de" << bloc.suprafata << "metrii patrati" << endl;



}

int main() {
    const int numarBlocuri = 10;

    Bloc** blocuri = new Bloc * [numarBlocuri];

    for (int i = 0; i < numarBlocuri; i++) {
        blocuri[i] = new Bloc;
        cout << "Blocul " << i + 1 << ":\n";
        citireBloc(*blocuri[i]);
    }

    cout << "\nDetalii blocuri:\n";
    for (int i = 0; i < numarBlocuri; i++) {
        cout << "Blocul " << i + 1 << ": ";
        afisareBloc(*blocuri[i]);
    }

    for (int i = 0; i < numarBlocuri; i++) {
        delete blocuri[i];
    }
    delete[] blocuri;


    return 0;

}