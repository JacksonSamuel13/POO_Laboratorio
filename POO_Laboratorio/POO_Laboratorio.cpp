#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base Vehículo
class Vehiculo {
private:
    string marca;
    int modelo;
    float precio;
public:
    Vehiculo(string mar, int mod, float prec)
        : marca(mar), modelo(mod), precio(prec) {
    }

    virtual void mostrarInfo() const {
        cout << "Marca: " << marca << ", Modelo: " << modelo << ", Precio: $" << precio;
    }

    string getMarca() const { return marca; }
    int getModelo() const { return modelo; }
    float getPrecio() const { return precio; }

    void setMarca(string mar) { marca = mar; }
    void setModelo(int mod) { modelo = mod; }
    void setPrecio(float prec) { precio = prec; }
};

// Clase derivada Automovil
class Automovil : public Vehiculo {
private:
    int numPuertas;
public:
    Automovil(string mar, int mod, float prec, int puertas)
        : Vehiculo(mar, mod, prec), numPuertas(puertas) {
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << ", Puertas: " << numPuertas << endl;
    }

    int getNumPuertas() const { return numPuertas; }
    void setNumPuertas(int puertas) { numPuertas = puertas; }
};

// Clase derivada Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindrada;
public:
    Motocicleta(string mar, int mod, float prec, int cil)
        : Vehiculo(mar, mod, prec), cilindrada(cil) {
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << ", Cilindrada: " << cilindrada << "cc" << endl;
    }

    int getCilindrada() const { return cilindrada; }
    void setCilindrada(int cil) { cilindrada = cil; }
};

// Clase derivada Camioneta
class Camioneta : public Vehiculo {
private:
    float capacidadCarga;
public:
    Camioneta(string mar, int mod, float prec, float carga)
        : Vehiculo(mar, mod, prec), capacidadCarga(carga) {
    }

    void mostrarInfo() const override {
        Vehiculo::mostrarInfo();
        cout << ", Capacidad de carga: " << capacidadCarga << "kg" << endl;
    }

    float getCapacidadCarga() const { return capacidadCarga; }
    void setCapacidadCarga(float carga) { capacidadCarga = carga; }
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    int edad;
public:
    Cliente(string nom, int ed) : nombre(nom), edad(ed) {}

    void comprarVehiculo(const Vehiculo& v) const {
        cout << "Cliente: " << nombre << " ha comprado un ";
        v.mostrarInfo();
    }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void setNombre(string nom) { nombre = nom; }
    void setEdad(int ed) { edad = ed; }
};

int main() {
    // Instanciando objetos de diferentes clases derivadas
    Automovil auto1("Toyota", 2022, 25000, 4);
    Motocicleta moto1("Yamaha", 2020, 18000, 1000);
    Camioneta camioneta1("Ford", 2021, 30000, 1500);

    // Mostrando información de los vehículos
    auto1.mostrarInfo();
    moto1.mostrarInfo();
    camioneta1.mostrarInfo();

    // Instanciando un objeto de Cliente y simulando la compra de un vehículo
    Cliente cliente1("Juan", 35);
    cliente1.comprarVehiculo(auto1);

    return 0;
}