#include <iostream>
#include <vector>
using namespace std;
class Producto {
private:
	string nombre;
	int codigo;
	float precio;
	int stock;
public:
    Animal(string n, int e) : nombre(n), edad(e) {}

    virtual void hacerSonido() {
        cout << nombre << " hace un sonido desconocido." << endl;
    }
};

class Perro : public Animal {
public:
    Perro(string n, int e) : Animal(n, e) {}

    void hacerSonido() override {
        cout << nombre << " dice: Guau!" << endl;
    }
};

class Automovil {
private:
    string marca;
    int velocidad;

public:
    Automovil(string m, int v) : marca(m), velocidad(v) {}

    void acelerar() {
        velocidad += 10;
        cout << "El automovil " << marca << " ahora va a " << velocidad << " km/h." << endl;
    }
};

void agregarProducto(vector<Producto>& inventario) {
	string nombre;
	int codigo, stock;
	float precio;
	cout << "Ingrese el nombre del producto: ";
	cin >> ws; // Limpia el buffer de entrada
	getline(cin, nombre);
	cout << "Ingrese el c�digo: ";
	cin >> codigo;
	cout << "Ingrese el precio: ";
	cin >> precio;
	cout << "Ingrese la cantidad en stock: ";
	cin >> stock;
	inventario.push_back(Producto(nombre, codigo, precio, stock));
}
void mostrarInventario(vector<Producto>& inventario) {
	if (inventario.empty()) {
		cout << "No hay productos en el inventario." << endl;
		return;
	}
	for (Producto& producto : inventario) {
		producto.mostrar();
	}
}
void buscarProducto(vector<Producto>& inventario) {
	int codigo;
	cout << "Ingrese el c�digo del producto a buscar: ";
	cin >> codigo;
	for (Producto& producto : inventario) {
		if (producto.obtenerCodigo() == codigo) {
			cout << "Producto encontrado: ";
			producto.mostrar();
			return;
		}
	}
	cout << "Producto no encontrado." << endl;
}
void actualizarStock(vector<Producto>& inventario) {
	int codigo, cantidad;
	cout << "Ingrese el c�digo del producto a actualizar: ";
	cin >> codigo;
	for (Producto& producto : inventario) {
		if (producto.obtenerCodigo() == codigo) {
			cout << "Ingrese la cantidad a restar del stock: ";
			cin >> cantidad;
			producto.actualizarStock(cantidad);
			return;
		}
	}
	cout << "Producto no encontrado." << endl;
}
void calcularValorTotal(vector<Producto>& inventario) {
	float total = 0;
	for (Producto& producto : inventario) {
		total += producto.obtenerValor();
	}
	cout << "Valor total del inventario: Q" << total << endl;
}
int main() {
	vector<Producto> inventario;
	int opcion;
	do {
		cout << "\nSistema de Inventario\n";
		cout << "1. Agregar producto\n";
		cout << "2. Mostrar inventario\n";
		cout << "3. Buscar producto por c�digo\n";
		cout << "4. Actualizar stock\n";
		cout << "5. Calcular valor total del inventario\n";
		cout << "6. Salir\n";
		cout << "Seleccione una opci�n: ";
		cin >> opcion;
		switch (opcion) {
		case 1: agregarProducto(inventario); break;
		case 2: mostrarInventario(inventario); break;
		case 3: buscarProducto(inventario); break;
		case 4: actualizarStock(inventario); break;
		case 5: calcularValorTotal(inventario); break;
		case 6: cout << "Saliendo del programa...\n"; break;
		default: cout << "Opci�n no v�lida, intente de nuevo.\n";
		}
	} while (opcion != 6);
	return 0;
}
