#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>



using namespace std;

// Funcion para cargar la base de conocimiento desde el codigo mismo
map<string, string> cargarBaseConocimiento() {
    map<string, string> baseConocimiento;

    baseConocimiento["Como estas?"] = "Estoy muy bien, gracias por preguntar.";
    baseConocimiento["Que es un algoritmo?"] = "Un algoritmo es una secuencia de pasos para resolver un problema.";
    baseConocimiento["Quien invento C++?"] = "Bjarne Stroustrup creo el lenguaje C++.";
    baseConocimiento["Que es un chatbot?"] = "Un chatbot es un programa que simula una conversacion con usuarios humanos.";
    baseConocimiento["Que es la inteligencia artificial?"] = "La inteligencia artificial es la simulacion de procesos de inteligencia humana por parte de maquinas.";

    return baseConocimiento;
}

// Funcion para convertir texto a minusculas
string aMinusculas(const string& texto) {
    string resultado = texto;
    transform(resultado.begin(), resultado.end(), resultado.begin(), ::tolower);
    return resultado;
}

// Funcion para busqueda exacta
bool busquedaExacta(const map<string, string>& baseConocimiento, const string& preguntaUsuario, string& respuesta) {
    auto it = baseConocimiento.find(preguntaUsuario);
    if (it != baseConocimiento.end()) {
        respuesta = it->second;
        return true;
    }
    return false;
}

// Funcion para busqueda por palabras clave
bool busquedaPorPalabrasClave(const map<string, string>& baseConocimiento, const string& preguntaUsuario, string& respuesta) {
    string preguntaMin = aMinusculas(preguntaUsuario);

    for (const auto& par : baseConocimiento) {
        string preguntaBaseMin = aMinusculas(par.first);
        istringstream iss(preguntaMin);
        string palabra;
        while (iss >> palabra) {
            if (preguntaBaseMin.find(palabra) != string::npos) {
                respuesta = par.second;
                return true;
            }
        }
    }
    return false;
}

// Funcion para generar ejemplos de codigo
void generarEjemplos() {
    cout << "Ejemplo de codigo para cargar un archivo:" << endl;
    cout << "ifstream archivo(\"ruta_del_archivo.txt\");" << endl;
    cout << "if (archivo.is_open()) {" << endl;
    cout << "    string linea;" << endl;
    cout << "    while (getline(archivo, linea)) {" << endl;
    cout << "        cout << linea << endl;" << endl;
    cout << "    }" << endl;
    cout << "    archivo.close();" << endl;
    cout << "} else {" << endl;
    cout << "    cout << \"No se pudo abrir el archivo.\" << endl;" << endl;
    cout << "}" << endl;

    cout << "\nEjemplo de codigo para buscar coincidencias:" << endl;
    cout << "string texto = \"Este es un ejemplo de texto.\";" << endl;
    cout << "string palabraClave = \"ejemplo\";" << endl;
    cout << "if (texto.find(palabraClave) != string::npos) {" << endl;
    cout << "    cout << \"Se encontro la palabra clave.\" << endl;" << endl;
    cout << "} else {" << endl;
    cout << "    cout << \"No se encontro la palabra clave.\" << endl;" << endl;
    cout << "}" << endl;
}

// Funcion para depurar el codigo
void depurarCodigo() {
    cout << "Depuracion del codigo:" << endl;
    cout << "1. Verifica que la base de conocimiento no este vacia." << endl;
    cout << "2. Asegurate de que las funciones de busqueda esten funcionando correctamente." << endl;
    cout << "3. Revisa que la conversion a minusculas se realice adecuadamente." << endl;
    cout << "4. Comprueba que las preguntas del usuario se procesen correctamente." << endl;
}

int main() {
    map<string, string> baseConocimiento = cargarBaseConocimiento();

    if (baseConocimiento.empty()) {
        cout << "Error: La base de conocimiento esta vacia." << endl;
        return 1;
    }

    cout << "Bienvenido al ChatBot!" << endl;
    cout << "Escribe 'salir' para terminar la conversacion." << endl;
    cout << "Escribe 'ejemplos' para ver ejemplos de codigo." << endl;
    cout << "Escribe 'depurar' para ver consejos de depuracion." << endl;

    string preguntaUsuario;
    while (true) {
        cout << "\nTu: ";
        getline(cin, preguntaUsuario);

        if (aMinusculas(preguntaUsuario) == "salir") {
            cout << "ChatBot: Hasta luego!" << endl;
            break;
        }
        else if (aMinusculas(preguntaUsuario) == "ejemplos") {
            generarEjemplos();
        }
        else if (aMinusculas(preguntaUsuario) == "depurar") {
            depurarCodigo();
        }
        else {
            string respuesta;
            if (busquedaExacta(baseConocimiento, preguntaUsuario, respuesta)) {
                cout << "ChatBot: " << respuesta << endl;
            }
            else if (busquedaPorPalabrasClave(baseConocimiento, preguntaUsuario, respuesta)) {
                cout << "ChatBot: " << respuesta << endl;
            }
            else {
                cout << "ChatBot: Lo siento, no entiendo tu pregunta." << endl;
            }
        }
    }

    return 0;
}
