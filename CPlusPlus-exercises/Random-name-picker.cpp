#include <iostream>
#include <ctime>

using namespace std;

int main() {

	srand(time(NULL));
	bool input = false;
	int size;

	while (input == false) {
		cout << "How many names are you going to input?: "; cin >> size;
		if (size > 1)
			input = true;
		else
			cout << "You need atleast 2 names in order to pick a random one";
	}

	string* array = new string[size];
	int* random = new int[size];

	for (int i = 0; i < size; i++) {
		random[i] = (rand() % 1000) + 1;
		cout << "Enter a name: "; cin >> array[i];
		for (int j = 0; j < i; j++) {
			while (i != j && array[i] == array[j]) {
				cout << "It seems you entered a name more than once. You have to re-enter it: ";
				cin >> array[j];
			}
		}
	}

	int pickedname = random[0];
	int position = 0;

	for (int i = 0; i < size; i++) {
		if (random[i] > pickedname) {
			pickedname = random[i];
			position = i;
		}
	}

	cout << "The program picked " << array[position] << "!";

	delete[] random;
	delete[] array;

	return 0;
}