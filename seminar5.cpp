#include<iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;//
	float* salarii;
	float suprafata;//
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin():anDeschidere(2024),nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m):anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}




	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}


	Magazin operator=(const Magazin& m) {
		if (&m != this) { //verificare de autoasignare
			this->oras = m.oras;
			this->nrAngajati = m.nrAngajati;
			if (this->salarii) {
				delete[]this->salarii;
			}
			this->salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				this->salarii[i] = m.salarii[i];
			}
			this->suprafata = m.suprafata;
		}
		return *this;
	}


	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float * salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float suprafataNoua) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}
	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Magazin operator+(Magazin m2)const {
		Magazin temp = *this;
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = m2.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Magazin& operator+=(Magazin m) {
		*this = *this + m;
		return *this;
	}

	Magazin operator+(float salariu)const {
		Magazin temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati]=salariu;
		temp.nrAngajati++;
		return temp;
	}

	bool operator>(Magazin m) {
		return this->suprafata > m.suprafata && this->nrAngajati > m.nrAngajati;

	}

	bool operator==(Magazin m) {
		return this->suprafata == m.suprafata && this->nrAngajati > m.nrAngajati;

	}




	//friend Magazin operator+(float salariu, Magazin m) {
	//	Magazin temp = m;
	//	if (temp.salarii != NULL) {
	//		delete[]temp.salarii;
	//	}
	//	temp.salarii = new float[temp.nrAngajati + 1];
	//	for (int i = 0; i < m.nrAngajati; i++) {
	//		temp.salarii[i] = m.salarii[i];
	//	}
	//	temp.salarii[temp.nrAngajati] = salariu;
	//	temp.nrAngajati++;
	//	return temp;
	//}

	friend Magazin operator+(float salariu, Magazin m);
	friend istream& operator>>(istream& input, Magazin& m);



	void afisare() {
		cout << "Oras:" << this->oras <<endl;
		cout << "Numar angajati:" << this->nrAngajati <<endl;
		cout << "Suprafata:" << this->suprafata <<endl;
		cout << "An deschidere:" << this->anDeschidere <<endl;
		cout << "Impozit pe m2:" << Magazin::impozitM2 <<endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
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

	explicit operator int() {
		return this->nrAngajati;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "indexul este inafara limitelor";

			//throw
			//try
			//catch
		}
	}

	operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];

		}
		return s;
	}


	friend ostream& operator<<(ostream& out, const Magazin m) {
		cout << "Oras:" << m.oras << endl;
		cout << "Numar angajati:" <<m.nrAngajati << endl;
		if (m.nrAngajati >0) {
			for (int i = 0; i < m.nrAngajati; i++) {
				out << m.salarii[i] << "";
			}

		}
		out << endl;
		cout << "Suprafata:" << m.suprafata << endl;
		cout << "An deschidere:" << m.anDeschidere << endl;
		cout << "Impozit pe m2:" << Magazin::impozitM2 << endl;

		return out;
	}



};
int Magazin::impozitM2 = 2;

istream& operator>>(istream& input, Magazin& m) {
	cout << "Oras:";
		input >> m.oras;
		cout << "nrAngajati";
		input >> m.nrAngajati;
		if (m.salarii != NULL) {
			delete[]m.salarii;
		}
		if (m.nrAngajati > 0) {
			m.salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				cout << "Salariul" << i + 1 << ":";
				input >> m.salarii[i];
			}
		}
		else {
			m.salarii = NULL;

		} 
		return input;
}

Magazin operator+(float salariu, Magazin m) {
	float valoare = m.nrAngajati;
	return m + salariu;
}

Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

int main() {

	Magazin m1;
	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2;
	cin >> m2;
	cout << endl<< m2;
	if (m1 > m2) { //m1.operator>(m2)
		cout << "m1 este mai mare";
	}

	if (m1 == m2) {
		cout << "m1 este este egal cu m2";
	}
	else{
		cout << "sunt diferite";
	}


	int nrAngajati =(int) m2;
	float salariiTotale = m2;
	cout << endl << "SalariiTotale:" << salariiTotale;

	try {
		cout<<endl<< m2[1]<<endl;

		m2[1] = 200;
		cout << m2[1] << endl;
		float s = m2[-9];

	}
	catch (int exceptie) {

	}
	catch (float exceptie) {

	}
	catch (const char* exceptie) {
		cout<<endl << exceptie << endl;
	}
	catch (string ex) {

	}
	catch (...) {

	}



	return 0;
}