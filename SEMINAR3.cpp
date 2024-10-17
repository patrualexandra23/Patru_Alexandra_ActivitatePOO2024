#include <iostream>
using namespace std;

class Magazin {
public:
	string oras;
	int nrAngajati;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;


	Magazin() :anDeschidere(2024), nrAngajati(2) {
		this->oras = "Bucuresti";
		this->suprafata = 50;

	}

	Magazin(string oras, int nrAngajati, float suprafata, int anDeschidere) :anDeschidere(anDeschidere) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;

	}



	void afisare() {
		cout << "Oras:" << this->oras << endl;
		cout << "Numar anagajati:" << this->nrAngajati << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe M2:" << this->impozitM2 << endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {

			return this->suprafata / this->nrAngajati;
		}
		else
			return 0;
	}

	static void modificaImpozit(int impozit) {
		if (impozit > 0) {
			Magazin::impozitM2 = impozit;
		}
	}
	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;





	}
};

int Magazin::impozitM2 = 2;

int main() {
	Magazin m1;
	m1.afisare();
	Magazin::modificaImpozit(3);
	m1.modificaImpozit(4);

	Magazin m2("Iasi", 7, 200, 2019);
	m2.afisare();
	Magazin* pointer = new Magazin("Timisoara", 4, 120, 2022); //initializam pointer
	pointer->afisare(); //-> -derefentiere si accesare
	cout << "Suprafata medie per anagajat este de:" << pointer->calculeazaSuprafataMedie() << endl;
	int nrMagazine = 3;
	Magazin* vector = new Magazin[nrMagazine];
	cout << "Vector\n";
	for (int i = 0; i < nrMagazine; i++) {
		//(*(vector + i)).afisare();

		vector[i].afisare();            //[] - deplasare + dereferentiere
	}

	cout << "Suprafata totala:" << Magazin::calculeazaSuprafataTotala(vector, nrMagazine) << endl;
	delete[]vector;
	delete pointer;

	return 0;

}