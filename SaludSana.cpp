#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

// Clase para manejar las credenciales (login y registro de cuentas)
class Credenciales {
private:
    string usuario;
    string clave;

public:
    // Método para registrar un usuario en el archivo
    void registrarUsuario() {
        cout << "\n--- Registro de Usuario ---\n";
        cout << "Ingrese un nombre de usuario: ";
        cin >> usuario;

        string claveConfirmacion;
        do {
            cout << "Ingrese una contraseña: ";
            cin >> clave;
            cout << "Confirme su contraseña: ";
            cin >> claveConfirmacion;

            if (clave != claveConfirmacion) {
                cout << "Las contraseñas no coinciden. Intente nuevamente.\n";
            }
        } while (clave != claveConfirmacion);

        guardarCredenciales();
        cout << "Usuario registrado exitosamente.\n";
    }

    // Método para guardar credenciales en un archivo
    void guardarCredenciales() {
        ofstream archivo("informacion_salud_sana.txt", ios::app);
        if (archivo.is_open()) {
            archivo << "Usuario: " << usuario << "\n";
            archivo << "Clave: " << clave << "\n";
            archivo << "----------------------------------------\n";
            archivo.close();
        } else {
            throw runtime_error("Error al guardar las credenciales.");
        }
    }

    // Método para validar credenciales al hacer login
    bool validarCredenciales() {
        cout << "\n--- Acceso al Sistema ---\n";
        cout << "Usuario: ";
        cin >> usuario;
        cout << "Clave: ";
        cin >> clave;

        ifstream archivo("informacion_salud_sana.txt");
        if (archivo.is_open()) {
            string linea, usuarioArchivo, claveArchivo;
            while (getline(archivo, linea)) {
                if (linea.find("Usuario:") == 0) {
                    usuarioArchivo = linea.substr(9); // Extraer el usuario
                    getline(archivo, linea);
                    if (linea.find("Clave:") == 0) {
                        claveArchivo = linea.substr(7); // Extraer la clave
                        if (usuarioArchivo == usuario && claveArchivo == clave) {
                            return true;
                        }
                    }
                }
            }
            archivo.close();
        }
        return false;
    }

    string getUsuario() const {
        return usuario;
    }
};

// Clase para manejar la información del usuario
class Usuario {
private:
    string dni;
    string nombre;
    string apellido;
    string idAsignado;
    string colegio;

public:
    string fechaNacimiento;
    string antecedentesMedicos;
    string vacunas;
    string enfermedadesHereditarias;

    // Métodos para registrar y mostrar información personal
    void registrarUsuario() {
        cout << "\n--- Registro de Información Personal ---\n";
        cout << "DNI: ";
        cin >> dni;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Apellido: ";
        cin >> apellido;
        cout << "ID Asignado (8 dígitos): ";
        cin >> idAsignado;
        cout << "Colegio al que pertenece: ";
        cin.ignore();
        getline(cin, colegio);
    }

    void guardarDatosUsuario() const {
        ofstream archivo("informacion_salud_sana.txt", ios::app);
        if (archivo.is_open()) {
            archivo << "DNI: " << dni << "\n";
            archivo << "Nombre: " << nombre << "\n";
            archivo << "Apellido: " << apellido << "\n";
            archivo << "ID Asignado: " << idAsignado << "\n";
            archivo << "Colegio: " << colegio << "\n";
            archivo << "----------------------------------------\n";
            archivo.close();
        } else {
            throw runtime_error("Error al guardar la información del usuario.");
        }
    }

    void registrarHistorialMedico() {
        cout << "\n--- Registro de Historial Médico ---\n";
        cout << "Fecha de nacimiento (DD/MM/AAAA): ";
        cin >> fechaNacimiento;
        cout << "Antecedentes médicos (Alergias y cirugías): ";
        cin.ignore();
        getline(cin, antecedentesMedicos);
        cout << "Vacunas: ";
        getline(cin, vacunas);
        cout << "Enfermedades hereditarias: ";
        getline(cin, enfermedadesHereditarias);
    }

    void guardarHistorialMedico() const {
        ofstream archivo("informacion_salud_sana.txt", ios::app);
        if (archivo.is_open()) {
            archivo << "Fecha de nacimiento: " << fechaNacimiento << "\n";
            archivo << "Antecedentes médicos: " << antecedentesMedicos << "\n";
            archivo << "Vacunas: " << vacunas << "\n";
            archivo << "Enfermedades hereditarias: " << enfermedadesHereditarias << "\n";
            archivo << "----------------------------------------\n";
            archivo.close();
        } else {
            throw runtime_error("Error al guardar el historial médico.");
        }
    }

    string getNombre() const {
        return nombre;
    }
};

// Clase para manejar el menú principal
class Menu {
public:
    static void mostrarMenu() {
        cout << "\nMenú de opciones:\n";
        cout << "1. Registrar Historial Médico\n";
        cout << "2. Mostrar Consejos sobre Alimentos\n";
        cout << "3. Guardar Información\n";
        cout << "4. SALIR\n";
        cout << "Ingrese la opción deseada: ";
    }

    static void mostrarConsejos() {
        cout << "\n--- Consejos sobre Alimentos ---\n";
        cout << "1. Mantén una dieta equilibrada.\n";
        cout << "2. Asegúrate de consumir alimentos frescos y etiquetados correctamente.\n";
        cout << "3. Sigue el sistema FIFO (Primero en Entrar, Primero en Salir).\n";
    }
};

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    Credenciales credenciales;
    Usuario usuario;

    int opcionLogin;
    do {
         cout << "\n";
        cout << "   *****     *****     *****   \n";
        cout << "  *******   *******   *******  \n";
        cout << " ********* ********* ********* \n";
        cout << "******************************* \n";
        cout << " ***************************** \n";
        cout << "   *************************   \n";
        cout << "     *********************     \n";
        cout << "       *****************       \n";
        cout << "         *************         \n";
        cout << "           *********           \n";
        cout << "             *****             \n";
        cout << "               *               \n";
        cout << "\n";
        cout << "********************************\n";
        cout << " *     Bienvenido a Salud     *\n";
        cout << " *      Sana y Saludable      *\n";
        cout << "********************************\n";
        cout << "\n";
        cout << "   1. Crear Cuenta\n";
        cout << "   2. Acceder\n";
        cout << "   3. Salir\n";
        cout << "\n";
        cout << "Elija una opción: ";
        cin >> opcionLogin;


        if (opcionLogin == 1) {
            credenciales.registrarUsuario();
        } else if (opcionLogin == 2) {
            if (credenciales.validarCredenciales()) {
                cout << "Login exitoso.\n";
                usuario.registrarUsuario();
                usuario.guardarDatosUsuario();

                int opcion;
                do {
                    limpiarPantalla();
                    Menu::mostrarMenu();
                    cin >> opcion;

                    switch (opcion) {
                        case 1:
                            usuario.registrarHistorialMedico();
                            usuario.guardarHistorialMedico();
                            break;
                        case 2:
                            Menu::mostrarConsejos();
                            break;
                        case 3:
                            cout << "Información guardada correctamente.\n";
                            break;
                        case 4:
                            cout << "Hasta pronto, " << usuario.getNombre() << ".\n";
                            break;
                        default:
                            cout << "Opción no válida. Intente nuevamente.\n";
                    }
                    if (opcion != 4) {
                        cout << "\nPresione Enter para continuar...";
                        cin.ignore();
                        cin.get();
                    }
                } while (opcion != 4);
            } else {
                cout << "Credenciales incorrectas.\n";
            }
        }
    } while (opcionLogin != 3);

    cout << "Gracias por usar Salud Sana. Hasta pronto.\n";
    return 0;
}