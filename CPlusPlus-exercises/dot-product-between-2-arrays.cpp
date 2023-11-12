#include <iostream>

using namespace std;

int main() {
	bool input = false;

	int dimensiune;

	while (input == false) {
		cout << "Input the size of the two arrays: "; cin >> dimensiune;

		if (dimensiune < 1) {
			cout << "\nInvalid size. Input the size of the array again.";
		}
		else input = true;
	}

	int* tablou1 = new int[dimensiune];
	int* tablou2 = new int[dimensiune];

	for (int i = 0; i < dimensiune; i++) {
		cout << "\nInput the value of element " << i << " from array A: ";
		cin >> tablou1[i];
	}

	for (int i = 0; i < dimensiune; i++) {
		cout << "\nInput the value of element " << i << " from array B: ";
		cin >> tablou2[i];
	}

	double dotproduct = 0;

	for (int j = 0; j < dimensiune; j++) {
		dotproduct += (tablou1[j] * tablou2[j]);
	}

	cout << "Dot product of array A and B is: " << dotproduct;

	delete[] tablou1;
	delete[] tablou2;
}