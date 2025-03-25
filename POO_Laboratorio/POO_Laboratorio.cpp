#include <iostream>
using namespace std;

//Funcion recursiva para calcular el factorial de un numero}
int factorial(int n)
{
	if (n < 0) {
		throw invalid_argument("Error: Factorial de un numero negativo no esta definido. ");
	}
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	try {
		int numero;
		cout << "Ingrese un numero para calcularle el factorial: ";
		cin >> numero;

		int resultado = factorial(numero);
		cout << "El factorial de " << numero << " es: " << resultado << endl;
	}
	/*catch (const exception& e) {
		cerr << "Exception capturada: " << e.what() << endl;
	}*/
	catch (...) {
		cerr << "No seas wey y coloca un numero positivo." << endl;
	}

	return 0;
	
}

