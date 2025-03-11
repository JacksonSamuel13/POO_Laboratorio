#include <iostream>
#include <string>

using namespace std;

// Clase que representa una cuenta bancaria
class CuentaBancaria {
private:
    string titular; // Nombre del titular de la cuenta
    double saldo; // Saldo actual de la cuenta
    bool activa; // Estado de la cuenta (activa/inactiva)
    int intentosFallidos; // Numero de intentos fallidos de retiro
    int mesesInactivo; // Numero de meses de inactividad

public:
    // Constructor de la clase
    CuentaBancaria(string t, double s, bool a, int m) : titular(t), saldo(s), activa(a), intentosFallidos(0), mesesInactivo(m) {}

    // Metodo para depositar dinero en la cuenta
    void depositar(double monto) {
        if (activa) {
            if (monto > 0) {
                saldo += monto;
                cout << "Deposito exitoso. Nuevo saldo: " << saldo << endl;
                if (saldo < 100) {
                    cout << "Advertencia: El saldo ha caido por debajo de 100." << endl;
                }
            }
            else {
                cout << "El monto a depositar debe ser positivo." << endl;
            }
        }
        else {
            cout << "La cuenta esta inactiva. No se puede depositar." << endl;
        }
    }

    // Metodo para retirar dinero de la cuenta
    void retirar(double monto) {
        if (activa) {
            if (monto > 0) {
                if (saldo >= monto) {
                    saldo -= monto;
                    cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
                    if (saldo < 100) {
                        cout << "Advertencia: El saldo ha caido por debajo de 100." << endl;
                    }
                }
                else {
                    cout << "Fondos insuficientes." << endl;
                    intentosFallidos++;
                    if (intentosFallidos >= 3) {
                        activa = false;
                        cout << "Cuenta bloqueada por multiples intentos fallidos." << endl;
                    }
                }
            }
            else {
                cout << "El monto a retirar debe ser positivo." << endl;
            }
        }
        else {
            cout << "La cuenta esta inactiva. No se puede retirar." << endl;
        }
    }
    // Metodo para consultar el saldo de la cuenta
    void consultarSaldo() const {
        cout << "Titular: " << titular << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "Estado de la cuenta: " << (activa ? "Activa" : "Inactiva") << endl;
    }

    // Metodo para verificar la inactividad de la cuenta
    void verificarInactividad() {
        if (mesesInactivo >= 6) {
            activa = false;
            cout << "Cuenta bloqueada por inactividad." << endl;
        }
    }

    // Metodo para incrementar los meses de inactividad
    void incrementarMesesInactivo() {
        mesesInactivo++;
        verificarInactividad();
    }

    // Metodo para reactivar la cuenta
    void reactivarCuenta() {
        if (!activa) {
            activa = true;
            intentosFallidos = 0;
            mesesInactivo = 0;
            cout << "Cuenta reactivada exitosamente." << endl;
        }
        else {
            cout << "La cuenta ya esta activa." << endl;
        }
    }
};

// Funcion para mostrar el menu interactivo
void mostrarMenu() {
    cout << "--- Menu ---" << endl;
    cout << "1. Depositar" << endl;
    cout << "2. Retirar" << endl;
    cout << "3. Consultar saldo" << endl;
    cout << "4. Incrementar meses de inactividad" << endl;
    cout << "5. Reactivar cuenta" << endl;
    cout << "6. Ver todas las cuentas" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Funcion para mostrar todas las cuentas
void mostrarCuentas(CuentaBancaria cuentas[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        cout << "Cuenta " << i + 1 << ":" << endl;
        cuentas[i].consultarSaldo();
        cout << endl;
    }
}
int main() {
    // Crear 30 cuentas bancarias
    CuentaBancaria cuentas[30] = {
        CuentaBancaria("Juan Perez", 1000.0, true, 0),
        CuentaBancaria("Maria Lopez", 500.0, true, 7),
        // Agregar mas cuentas segun sea necesario
        CuentaBancaria("Carlos Gomez", 1500.0, true, 2),
        CuentaBancaria("Ana Martinez", 200.0, true, 3),
        CuentaBancaria("Luis Rodriguez", 300.0, true, 1),
        CuentaBancaria("Sofia Hernandez", 800.0, true, 0),
        CuentaBancaria("Miguel Torres", 1200.0, true, 4),
        CuentaBancaria("Laura Ramirez", 600.0, true, 5),
        CuentaBancaria("Jorge Sanchez", 900.0, true, 6),
        CuentaBancaria("Elena Diaz", 400.0, true, 2),
        CuentaBancaria("Pedro Morales", 700.0, true, 1),
        CuentaBancaria("Carmen Cruz", 1100.0, true, 0),
        CuentaBancaria("Ricardo Ortiz", 1300.0, true, 3),
        CuentaBancaria("Patricia Flores", 1400.0, true, 4),
        CuentaBancaria("Fernando Ruiz", 1600.0, true, 5),
        CuentaBancaria("Gloria Castillo", 1700.0, true, 6),
        CuentaBancaria("Raul Gutierrez", 1800.0, true, 2),
        CuentaBancaria("Marta Chavez", 1900.0, true, 1),
        CuentaBancaria("Jose Vargas", 2100.0, true, 0),
        CuentaBancaria("Lucia Jimenez", 2200.0, true, 3),
        CuentaBancaria("Francisco Soto", 2300.0, true, 4),
        CuentaBancaria("Isabel Mendoza", 2400.0, true, 5),
        CuentaBancaria("Alberto Romero", 2500.0, true, 6),
        CuentaBancaria("Teresa Herrera", 2600.0, true, 2),
        CuentaBancaria("Andres Rios", 2700.0, true, 1),
        CuentaBancaria("Rosa Aguilar", 2800.0, true, 0),
        CuentaBancaria("Manuel Paredes", 2900.0, true, 3),
        CuentaBancaria("Adriana Campos", 3000.0, true, 4),
        CuentaBancaria("Julio Vega", 3100.0, true, 5),
        CuentaBancaria("Silvia Espinoza", 3200.0, true, 6)
    };

    int opcion;
    double monto;
    int cuentaSeleccionada;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Seleccione la cuenta (1-30): ";
            cin >> cuentaSeleccionada;
            if (cuentaSeleccionada < 1 || cuentaSeleccionada > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            cout << "Ingrese monto a depositar: ";
            cin >> monto;
            cuentas[cuentaSeleccionada - 1].depositar(monto);
            break;
        case 2:
            cout << "Seleccione la cuenta (1-30): ";
            cin >> cuentaSeleccionada;
            if (cuentaSeleccionada < 1 || cuentaSeleccionada > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            cout << "Ingrese monto a retirar: ";
            cin >> monto;
            cuentas[cuentaSeleccionada - 1].retirar(monto);
            break;
        case 3:
            cout << "Seleccione la cuenta (1-30): ";
            cin >> cuentaSeleccionada;
            if (cuentaSeleccionada < 1 || cuentaSeleccionada > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            cuentas[cuentaSeleccionada - 1].consultarSaldo();
            break;
        case 4:
            cout << "Seleccione la cuenta (1-30): ";
            cin >> cuentaSeleccionada;
            if (cuentaSeleccionada < 1 || cuentaSeleccionada > 30) {
                cout << "Cuenta no valida."
                    ;break;
            }
            cuentas[cuentaSeleccionada - 1].incrementarMesesInactivo();
            break;
        case 5:
            cout << "Seleccione la cuenta (1-30): ";
            cin >> cuentaSeleccionada;
            if (cuentaSeleccionada < 1 || cuentaSeleccionada > 30) {
                cout << "Cuenta no valida." << endl;
                break;
            }
            cuentas[cuentaSeleccionada - 1].reactivarCuenta();
            break;
        case 6:
            mostrarCuentas(cuentas, 30);
            break;
        case 7:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}

