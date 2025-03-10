#include <string>
#include <iostream>
#include <cstdlib> // Para usar system("cls") o system("clear")
using namespace std;

//***********************************************************************Clase Cuentas********************************************
class Cuentas {
private:
    string usuarioCuenta;
    string numeroCuenta;
    double saldo;
    bool estatus; // inactiva o activa
    bool estado;  // Desbloqueada o bloqueada
    int intentos;
public:
    Cuentas(string _usuarioCuenta, string _numeroCuenta, double _saldo, bool _estatus, bool _estado, int _intentos) {
        usuarioCuenta = _usuarioCuenta;
        numeroCuenta = _numeroCuenta;
        saldo = _saldo;
        estatus = _estatus;
        estado = _estado;
        intentos = _intentos;
    }

    void retiros(double monto) {
        if (intentos < 3) {
            if (saldo >= monto && estado && monto <= (saldo/2)) {
                saldo -= monto;
                cout << "El nuevo saldo es de: " << saldo << endl;
            }
            else {
                cout << "Fondos Insuficientes o cuenta bloqueada!" << endl;
                intentos++;
                cout << "Usted lleva: " << intentos << " intentos antes que se bloquee la cuenta." << endl;
            }
        }
        else {
            cout << "La cuenta ha sido bloqueada!" << endl;
            estado = false;
        }
    }

    void depositos(double monto) {
        if (estatus && estado) {
            saldo += monto;
            cout << "Deposito realizado! " << endl;
            cout << "Nuevo saldo : " << saldo << endl;
        }
        else {
            cout << "La cuenta se encuentra inactiva o bloqueada." << endl;
        }
    }

    void mostrarCuenta() {
        cout << "Usuario: " << usuarioCuenta << ", Numero Cuenta: " << numeroCuenta
            << ", Saldo: " << saldo
            << ", Estatus: " << (estatus ? "Activa" : "Inactiva")
            << ", Estado: " << (estado ? "Desbloqueada" : "Bloqueada") << endl;
    }

    string getUsuario() {
        return usuarioCuenta;
    }

    string getNumeroCuenta() {
        return numeroCuenta;
    }

    double getSaldo() {
        return saldo;
    }
};

//**************************************************************Menu***********************************************************************************
void menu() {
    cout << "" << endl;
    cout << "Escoja las opciones en el menu: " << endl;
    cout << "1. Retiros" << endl;
    cout << "2. Depositos" << endl;
    cout << "3. Transferencias" << endl;
    cout << "4. Cuentas existentes" << endl;
    cout << "" << endl;
}

//************************************************************Limpiar pantall**********************************************************************
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");  // Para Windows
#else
    system("clear");  // Para Linux/Unix
#endif
}

int main() {
    //**************************************************************Variables****************************************************************************
    int op;
    double monto;
    string cuentaDestino;
    string cuentaOrigen;
    string caracter;

    //**************************************************************Crear cuentas*************************************************************************
    Cuentas c1("Juan Carlos", "1001", 2000, true, true, 0);
    Cuentas c2("Maria Lopez", "1002", 1500, true, true, 0);
    Cuentas c3("Pedro Ramirez", "1003", 3000, true, true, 0);
    Cuentas c4("Ana Gutierrez", "1004", 2500, true, true, 0);
    Cuentas c5("Carlos Mendez", "1005", 1800, true, false, 1);
    Cuentas c6("Laura Sánchez", "1006", 2200, true, true, 0);
    Cuentas c7("Luis Herrera", "1007", 1700, false, true, 0);
    Cuentas c8("Elena Castro", "1008", 2800, true, true, 0);
    Cuentas c9("Fernando Rojas", "1009", 3500, true, false, 2);
    Cuentas c10("Sofia Vargas", "1010", 4000, true, true, 0);
    Cuentas c11("Ricardo Morales", "1011", 3200, true, true, 0);
    Cuentas c12("Gabriela Pineda", "1012", 1900, true, true, 0);
    Cuentas c13("Pablo Cruz", "1013", 4100, true, false, 3);
    Cuentas c14("Andrea Castillo", "1014", 2750, false, true, 0);
    Cuentas c15("Raul Jimenez", "1015", 3050, true, true, 0);
    Cuentas c16("Diana Torres", "1016", 1500, true, false, 2);
    Cuentas c17("Javier Salazar", "1017", 3700, true, true, 0);
    Cuentas c18("Margarita Lopez", "1018", 2600, false, true, 0);
    Cuentas c19("Cesar Dominguez", "1019", 3900, true, true, 0);
    Cuentas c20("Veronica Flores", "1020", 4200, true, true, 0);
    Cuentas c21("Antonio Vargas", "1021", 1400, false, true, 0);
    Cuentas c22("Isabel Ortega", "1022", 3100, true, false, 1);
    Cuentas c23("Samuel Peralta", "1023", 2950, true, true, 0);
    Cuentas c24("Cristina Mendoza", "1024", 1750, true, true, 0);
    Cuentas c25("Hector Figueroa", "1025", 3600, true, true, 0);
    Cuentas c26("Paula Diaz", "1026", 3800, false, true, 0);
    Cuentas c27("Nelson Guzman", "1027", 2500, true, true, 0);
    Cuentas c28("Rebeca Alvarado", "1028", 3400, true, false, 2);
    Cuentas c29("Victor Suarez", "1029", 2900, true, true, 0);
    Cuentas c30("Teresa Miranda", "1030", 3300, true, true, 0);


//**************************************************Switch Funcion de opciones************************************************
    do {
        menu();
        cout << "Ingrese la opcion: ";
        cin >> op;
        cin.ignore(); // Evita problemas con getline después de cin
        cout << "************************************************" << endl;

        switch (op) {
        case 1: { // Retiros
            limpiarPantalla();
            cout << "Ingrese el numero de cuenta desde la cual desea retirar: ";
            getline(cin, cuentaOrigen);
            cout << "Ingrese la cantidad a retirar: " << endl;
            cin >> monto;
            if (cuentaOrigen == c1.getNumeroCuenta()) {
                c1.retiros(monto);
            }
            else if (cuentaOrigen == c2.getNumeroCuenta()) {
                c2.retiros(monto);
            }
            else if (cuentaOrigen == c3.getNumeroCuenta()) {
                c3.retiros(monto);
            }
            else if (cuentaOrigen == c4.getNumeroCuenta()) {
                c4.retiros(monto);
            }
            else if (cuentaOrigen == c5.getNumeroCuenta()) {
                c5.retiros(monto);
            }
            else if (cuentaOrigen == c6.getNumeroCuenta()) {
                c6.retiros(monto);
            }
            else if (cuentaOrigen == c7.getNumeroCuenta()) {
                c7.retiros(monto);
            }
            else if (cuentaOrigen == c8.getNumeroCuenta()) {
                c8.retiros(monto);
            }
            else if (cuentaOrigen == c9.getNumeroCuenta()) {
                c9.retiros(monto);
            }
            else if (cuentaOrigen == c10.getNumeroCuenta()) {
                c10.retiros(monto);
            }
            else if (cuentaOrigen == c11.getNumeroCuenta()) {
                c11.retiros(monto);
            }
            else if (cuentaOrigen == c12.getNumeroCuenta()) {
                c12.retiros(monto);
            }
            else if (cuentaOrigen == c13.getNumeroCuenta()) {
                c13.retiros(monto);
            }
            else if (cuentaOrigen == c14.getNumeroCuenta()) {
                c14.retiros(monto);
            }
            else if (cuentaOrigen == c15.getNumeroCuenta()) {
                c15.retiros(monto);
            }
            else if (cuentaOrigen == c16.getNumeroCuenta()) {
                c16.retiros(monto);
            }
            else if (cuentaOrigen == c17.getNumeroCuenta()) {
                c17.retiros(monto);
            }
            else if (cuentaOrigen == c18.getNumeroCuenta()) {
                c18.retiros(monto);
            }
            else if (cuentaOrigen == c19.getNumeroCuenta()) {
                c19.retiros(monto);
            }
            else if (cuentaOrigen == c20.getNumeroCuenta()) {
                c20.retiros(monto);
            }
            else if (cuentaOrigen == c21.getNumeroCuenta()) {
                c21.retiros(monto);
            }
            else if (cuentaOrigen == c22.getNumeroCuenta()) {
                c22.retiros(monto);
            }
            else if (cuentaOrigen == c23.getNumeroCuenta()) {
                c23.retiros(monto);
            }
            else if (cuentaOrigen == c24.getNumeroCuenta()) {
                c24.retiros(monto);
            }
            else if (cuentaOrigen == c25.getNumeroCuenta()) {
                c25.retiros(monto);
            }
            else if (cuentaOrigen == c26.getNumeroCuenta()) {
                c26.retiros(monto);
            }
            else if (cuentaOrigen == c27.getNumeroCuenta()) {
                c27.retiros(monto);
            }
            else if (cuentaOrigen == c28.getNumeroCuenta()) {
                c28.retiros(monto);
            }
            else if (cuentaOrigen == c29.getNumeroCuenta()) {
                c29.retiros(monto);
            }
            else if (cuentaOrigen == c30.getNumeroCuenta()) {
                c30.retiros(monto);
            }
            else {
                cout << "Cuenta de origen no encontrada!" << endl;
            }
            break;
            
        }
        case 2: { // Depositos
            limpiarPantalla();
            cout << "Ingrese el numero de cuenta donde desea depositar: ";
            getline(cin, cuentaDestino);
            cout << "Ingrese la cantidad a depositar: " << endl;
            cin >> monto;
            if (cuentaDestino == c1.getNumeroCuenta()) {
                c1.depositos(monto);
            }
            else if (cuentaDestino == c2.getNumeroCuenta()) {
                c2.depositos(monto);
            }
            else if (cuentaDestino == c3.getNumeroCuenta()) {
                c3.depositos(monto);
            }
            else if (cuentaDestino == c4.getNumeroCuenta()) {
                c4.depositos(monto);
            }
            else if (cuentaDestino == c5.getNumeroCuenta()) {
                c5.depositos(monto);
            }
            else if (cuentaDestino == c6.getNumeroCuenta()) {
                c6.depositos(monto);
            }
            else if (cuentaDestino == c7.getNumeroCuenta()) {
                c7.depositos(monto);
            }
            else if (cuentaDestino == c8.getNumeroCuenta()) {
                c8.depositos(monto);
            }
            else if (cuentaDestino == c9.getNumeroCuenta()) {
                c9.depositos(monto);
            }
            else if (cuentaDestino == c10.getNumeroCuenta()) {
                c10.depositos(monto);
            }
            else if (cuentaDestino == c11.getNumeroCuenta()) {
                c11.depositos(monto);
            }
            else if (cuentaDestino == c12.getNumeroCuenta()) {
                c12.depositos(monto);
            }
            else if (cuentaDestino == c13.getNumeroCuenta()) {
                c13.depositos(monto);
            }
            else if (cuentaDestino == c14.getNumeroCuenta()) {
                c14.depositos(monto);
            }
            else if (cuentaDestino == c15.getNumeroCuenta()) {
                c15.depositos(monto);
            }
            else if (cuentaDestino == c16.getNumeroCuenta()) {
                c16.depositos(monto);
            }
            else if (cuentaDestino == c17.getNumeroCuenta()) {
                c17.depositos(monto);
            }
            else if (cuentaDestino == c18.getNumeroCuenta()) {
                c18.depositos(monto);
            }
            else if (cuentaDestino == c19.getNumeroCuenta()) {
                c19.depositos(monto);
            }
            else if (cuentaDestino == c20.getNumeroCuenta()) {
                c20.depositos(monto);
            }
            else if (cuentaDestino == c21.getNumeroCuenta()) {
                c21.depositos(monto);
            }
            else if (cuentaDestino == c22.getNumeroCuenta()) {
                c22.depositos(monto);
            }
            else if (cuentaDestino == c23.getNumeroCuenta()) {
                c23.depositos(monto);
            }
            else if (cuentaDestino == c24.getNumeroCuenta()) {
                c24.depositos(monto);
            }
            else if (cuentaDestino == c25.getNumeroCuenta()) {
                c25.depositos(monto);
            }
            else if (cuentaDestino == c26.getNumeroCuenta()) {
                c26.depositos(monto);
            }
            else if (cuentaDestino == c27.getNumeroCuenta()) {
                c27.depositos(monto);
            }
            else if (cuentaDestino == c28.getNumeroCuenta()) {
                c28.depositos(monto);
            }
            else if (cuentaDestino == c29.getNumeroCuenta()) {
                c29.depositos(monto);
            }
            else if (cuentaDestino == c30.getNumeroCuenta()) {
                c30.depositos(monto);
            }
            else {
                cout << "Cuenta destino no encontrada!" << endl;
            }

            break;
        }
        case 3: {
            cout << "Ingrese la cuenta de origen para la transferencia: ";
            getline(cin, cuentaOrigen);
            cout << "Ingrese la cuenta de destino para la transferencia: ";
            getline(cin, cuentaDestino);
            cout << "Ingrese la cantidad a transferir: " << endl;
            cin >> monto;
            limpiarPantalla();
            cout << "Transfiriendo: " << monto << " desde la cuenta de: " << cuentaOrigen << endl;
            cout << " hacia la cuenta de: " << cuentaDestino << endl;
            break;
        }
        case 4: { // Mostrar cuentas existentes
            limpiarPantalla();
            c1.mostrarCuenta();
            c2.mostrarCuenta();
            c3.mostrarCuenta();
            c4.mostrarCuenta();
            c5.mostrarCuenta();
            c6.mostrarCuenta();
            c7.mostrarCuenta();
            c8.mostrarCuenta();
            c9.mostrarCuenta();
            c10.mostrarCuenta();
            c11.mostrarCuenta();
            c12.mostrarCuenta();
            c13.mostrarCuenta();
            c14.mostrarCuenta();
            c15.mostrarCuenta();
            c16.mostrarCuenta();
            c17.mostrarCuenta();
            c18.mostrarCuenta();
            c19.mostrarCuenta();
            c20.mostrarCuenta();
            c21.mostrarCuenta();
            c22.mostrarCuenta();
            c23.mostrarCuenta();
            c24.mostrarCuenta();
            c25.mostrarCuenta();
            c26.mostrarCuenta();
            c27.mostrarCuenta();
            c28.mostrarCuenta();
            c29.mostrarCuenta();
            c30.mostrarCuenta();

            break;
        }
        default:
            cout << "Opcion no valida." << endl;
        }

        cout << "Desea continuar? Si/No: ";
        cin >> caracter;
        limpiarPantalla();
    } while (caracter == "Si" || caracter == "si");

    return 0;
}
