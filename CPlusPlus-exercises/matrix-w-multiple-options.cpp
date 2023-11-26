#include <iostream>

using namespace std;

int input();
void option(int** matrice, int size);
void afisare(int** matrice, int size);
void procent(int** matrice, int size);
void matriceC(int** matrice, int size);
void matrix(int** matrice, int size);
void minim(int** matrice, int size);
void maxim(int** matrice, int size);
void prime(int** matrice, int size);
void hasura(int** matrice, int size);

int main() {
	int size = input();
	int** matrice = new int* [size];
	for (int i = 0; i < size; i++) {
		matrice[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "\n Introduce valoarea elementului [" << i << "][" << j << "]: ";
			cin >> matrice[i][j];
		}
	}
	option(matrice, size);

	for (int i = 0; i < size; ++i) {
		delete[] matrice[i];
	}

	delete[] matrice;
}

int input() {
	bool input = false;
	int sizef;
	while (!input) {
		cout << "\nCe dimensiune vrei sa aiba matricea? : ";
		cin >> sizef;
		if (sizef > 1) input = true;
		else if (sizef > 10) cout << "\nMarimea matricii este prea mare. Maximul este 10.";
		else cout << "\nTrebuie sa introduci macar o dimensiune de 2x2";
	}
	return sizef;
}

void option(int** matrice, int size) {
	bool input = false;
	char optiune;
	while (!input) {
		cout << "\n * Lista optiuni valabile *";
		cout << "\n Sa se afiseze matricea C [A]";
		cout << "\n Sa se calculeze si sa se afiseze procentul elementelor impare de pe liniile pare [B]";
		cout << "\n Sa se calculeze si sa se afiseze matricea B, unde B = C^2 [C]";
		cout << "\n Sa se calculeze si sa se afiseze matricea E, unde E = (C+C^T)^2+I, unde I este matricea unitate [D]";
		cout << "\n Sa se afle elementul minim din matricea C [E]";
		cout << "\n Sa se inlocuiasca elementul maxim din matricea C cu valoarea val, introdusa de la tastatura [F]";
		cout << "\n Sa se afiseze elementele matricii C care sunt numere prime [G]";
		cout << "\n Sa se calculeze si sa se afiseze sumele si produsele elementelor matricii A [H]";
		cout << "\n\n Ce optiune doresti sa alegi? : ";

		cin >> optiune;

		optiune = toupper(optiune);

		if (optiune == 'A' || optiune == 'B' || optiune == 'C' || optiune == 'D' || optiune == 'E' || optiune == 'F' || optiune == 'G' || optiune == 'H') {
			input = true;
		}
		else {
			cout << "\n\n Optiune invalida.";
		}
	}

	switch (optiune) {
	case 'A':
		afisare(matrice, size);
		break;
	case 'B':
		procent(matrice, size);
		break;
	case 'C':
		matriceC(matrice, size);
		break;
	case 'D':
		matrix(matrice, size);
		break;
	case 'E':
		minim(matrice, size);
		break;
	case 'F':
		maxim(matrice, size);
		break;
	case 'G':
		prime(matrice, size);
		break;
	case 'H':
		hasura(matrice, size);
		break;
	}
}

void afisare(int** matrice, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrice[i][j] << " ";
		}
		cout << "\n";
	}
}

void procent(int** matrice, int size) {
	int counter = 0;
	for (int i = 1; i < size; i += 2) {
		for (int j = 0; j < size; j++) {
			if (matrice[i][j] % 2 != 0) counter += 1;
		}
	}
	int procent = (static_cast<double>(counter) / static_cast<double>(size * size)) * 100;
	cout << "Procentul elementelor impare de pe liniile pare este: " << procent;
}

void matriceC(int** matrice, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << pow(matrice[i][j], 2) << " ";
		}
		cout << "\n";
	}
}

void matrix(int** matrice, int size) {
	int** transpusa = new int* [size];
	for (int i = 0; i < size; i++) {
		transpusa[i] = new int[size];
	}

	int** unitate = new int* [size];
	for (int i = 0; i < size; i++) {
		unitate[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			unitate[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {
		unitate[i][i] = 1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			transpusa[j][i] = matrice[i][j];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			transpusa[i][j] = pow((transpusa[i][j] + matrice[i][j]), 2) + unitate[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << transpusa[i][j] << " ";
		}
		cout << "\n";
	}
	delete[] unitate;
	delete[] transpusa;
}

void minim(int** matrice, int size) {
	int minim = matrice[0][0];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (minim > matrice[i][j]) minim = matrice[i][j];
		}
	}
	cout << "\n Numarul minim din matrice este: " << minim;
}

void maxim(int** matrice, int size) {
	int maxim = matrice[0][0];
	int linie = 0;
	int coloana = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (maxim < matrice[i][j]) {
				maxim = matrice[i][j];
				linie = i;
				coloana = j;
			}
		}
	}
	cout << "\n Numarul minim din matrice este: " << maxim;
	int val;
	cout << "\n Cu ce numar doresti sa il inlocuiesti?: "; cin >> val;
	matrice[linie][coloana] = val;
	afisare(matrice, size);
}

void prime(int** matrice, int size) {
	cout << "\n Numerele prime din matrice sunt: ";
	int counter = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			bool ePrim = true;

			for (int k = 2; k <= matrice[i][j]; k++) {
				if (matrice[i][j] % k == 0 && k != matrice[i][j]) {
					ePrim = false;
					break;
				}
			}

			if (ePrim) {
				cout << matrice[i][j] << " ";
				counter++;
			}
		}
	}
	if (counter == 0) cout << "NU EXISTA";
}

void hasura(int** matrice, int size) {
	// valori pentru triunghiuri
	int suma = 0;
	int produs = 1;
	int contor = size;

	//triunghi din stanga;

	for (int i = 0; i < contor; i++) {
		for (int j = i; j < contor; j++) {
			suma += matrice[j][i];
			produs *= matrice[j][i];
		}
		contor--;
	}
	cout << "\n Triunghiul din stanga - Suma = " << suma << " | Produs = " << produs;

	// reset valori

	suma = 0;
	produs = 1;
	contor = size;

	// triunghi dreapta

	int time = 0;

	for (int i = contor - 1; i < contor && time < contor; i--) {
		for (int j = time; j < contor; j++) {
			suma += matrice[j][i];
			produs *= matrice[j][i];
		}
		contor--;
		time++;
	}
	cout << "\n Triunghiul din dreapta - Suma = " << suma << " | Produs = " << produs;

	// reset valori

	suma = 0;
	produs = 1;
	contor = size;

	// triunghi sus

	time = 0;

	for (int i = 0; i < contor && time < contor; i++) {
		for (int j = time; j < contor; j++) {
			suma += matrice[i][j];
			produs *= matrice[i][j];
		}
		contor--;
		time++;
	}
	cout << "\n Triunghiul de sus - Suma = " << suma << " | Produs = " << produs;

	// reset valori

	suma = 0;
	produs = 1;
	contor = size;

	// triunghi jos

	time = 0;

	for (int i = contor - 1; i < contor && time < contor; i--) {
		for (int j = time; j < contor; j++) {
			suma += matrice[i][j];
			produs *= matrice[i][j];
		}
		contor--;
		time++;
	}
	cout << "\n Triunghiul de jos - Suma = " << suma << " | Produs = " << produs;
}