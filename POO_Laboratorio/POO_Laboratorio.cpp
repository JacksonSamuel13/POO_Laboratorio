/*
#include <iostream>
using namespace std;

int main() {
	int arreglo[10];

	// Llenar el arreglo con los números del 1 al 10
	for (int i = 0; i < 10; i++) {
	arreglo[i] = i + 1;
	}

	// Imprimir cada valor con su índice correspondiente
	for (int i = 0; i < 10; i++) {
		cout << "Indice " << i << ": " << arreglo[i] << endl;
	}

	return 0;
} */

/*
#include <iostream>
using namespace std;

const int TAM = 10;

// Función para ingresar números
void ingresarNumeros(int arr[]) {
	cout << "Ingrese 10 numeros enteros:" << endl;
	for (int i = 0; i < TAM; i++) {
		cin >> arr[i];
	}
}

// Función para calcular la suma total
int calcularSuma(int arr[]) {
	int suma = 0;
	for (int i = 0; i < TAM; i++) {
		suma += arr[i];
	}
	return suma;
}

// Función para calcular el promedio
double calcularPromedio(int arr[]) {
	return static_cast<double>(calcularSuma(arr)) / TAM;
}

// Función para encontrar el valor máximo
int encontrarMaximo(int arr[]) {
	int maximo = arr[0];
	for (int i = 1; i < TAM; i++) {
		if (arr[i] > maximo) {
			maximo = arr[i];
		}
	}
	return maximo;
}

// Función para encontrar el valor mínimo
int encontrarMinimo(int arr[]) {
	int minimo = arr[0];
	for (int i = 1; i < TAM; i++) {
		if (arr[i] < minimo) {
			minimo = arr[i];
		}
	}
	return minimo;
}

// Función para contar números pares e impares
void contarParesImpares(int arr[], int& pares, int& impares) {
	pares = 0;
	impares = 0;
	for (int i = 0; i < TAM; i++) {
		if (arr[i] % 2 == 0) {
			pares++;
		}
		else {
			impares++;
		}
	}
}

int main() {
	int numeros[TAM];
	ingresarNumeros(numeros);

	int suma = calcularSuma(numeros);
	double promedio = calcularPromedio(numeros);
	int maximo = encontrarMaximo(numeros);
	int minimo = encontrarMinimo(numeros);
	int pares, impares;
	contarParesImpares(numeros, pares, impares);

	cout << "Suma total: " << suma << endl;
	cout << "Promedio: " << promedio << endl;
	cout << "Valor maximo: " << maximo << endl;
	cout << "Valor minimo: " << minimo << endl;
	cout << "Cantidad de numeros pares: " << pares << endl;
	cout << "Cantidad de numeros impares: " << impares << endl;

	return 0;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;

const int TAM = 10;

// Función para ingresar números
void ingresarNumeros(vector<int>& vec) {
	cout << "Ingrese 10 numeros enteros:" << endl;
	for (int i = 0; i < TAM; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}
}

// Función para calcular la suma total
int calcularSuma(const vector<int>& vec) {
	int suma = 0;
	for (int num : vec) {
		suma += num;
	}
	return suma;
}

// Función para calcular el promedio
double calcularPromedio(const vector<int>& vec) {
	return static_cast<double>(calcularSuma(vec)) / vec.size();
}

// Función para encontrar el valor máximo
int encontrarMaximo(const vector<int>& vec) {
	int maximo = vec[0];
	for (int num : vec) {
		if (num > maximo) {
			maximo = num;
		}
	}
	return maximo;
}

// Función para encontrar el valor mínimo
int encontrarMinimo(const vector<int>& vec) {
	int minimo = vec[0];
	for (int num : vec) {
		if (num < minimo) {
			minimo = num;
		}
	}
	return minimo;
}

// Función para contar números pares e impares
void contarParesImpares(const vector<int>& vec, int& pares, int& impares) {
	pares = 0;
	impares = 0;
	for (int num : vec) {
		if (num % 2 == 0) {
			pares++;
		}
		else {
			impares++;
		}
	}
}

// Función para imprimir el arreglo en orden inverso usando punteros
void imprimirInverso(int* arr, int tam) {
	for (int i = tam - 1; i >= 0; i--) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

int main() {
	vector<int> numeros;
	ingresarNumeros(numeros);

	int suma = calcularSuma(numeros);
	double promedio = calcularPromedio(numeros);
	int maximo = encontrarMaximo(numeros);
	int minimo = encontrarMinimo(numeros);
	int pares, impares;
	contarParesImpares(numeros, pares, impares);

	cout << "Suma total: " << suma << endl;
	cout << "Promedio: " << promedio << endl;
	cout << "Valor maximo: " << maximo << endl;
	cout << "Valor minimo: " << minimo << endl;
	cout << "Cantidad de numeros pares: " << pares << endl;
	cout << "Cantidad de numeros impares: " << impares << endl;

	// Imprimir el arreglo en orden inverso
	imprimirInverso(numeros.data(), numeros.size());

	return 0;
}
*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int SIZE = 15;
	int numbers[SIZE];
	int sum = 0;
	double average;

	// Ingresar 15 números enteros
	cout << "Ingrese 15 numeros enteros:" << endl;
	for (int i = 0; i < SIZE; ++i) {
		cin >> numbers[i];
		sum += numbers[i];
	}

	// Calcular el promedio
	average = static_cast<double>(sum) / SIZE;

	// Crear un nuevo arreglo con valores mayores al promedio
	vector<int> aboveAverage;
	for (int i = 0; i < SIZE; ++i) {
		if (numbers[i] > average) {
			aboveAverage.push_back(numbers[i]);
		}
	}

	// Imprimir ambos arreglos
	cout << "Arreglo original: ";
	for (int i = 0; i < SIZE; ++i) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << "Arreglo con valores mayores al promedio: ";
	for (int i = 0; i < aboveAverage.size(); ++i) {
		cout << aboveAverage[i] << " ";
	}
	cout << endl;

	return 0;
}