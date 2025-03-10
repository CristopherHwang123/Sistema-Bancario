#include <string>
#include <iostream>
using namespace std;

class Cuentas {
private: 
    string usuarioCuenta;
    double saldo;
    bool estatus; //inactiva o activa
    bool estado; //Desbloqueada o bloqueada
    int intentos;
public:
    Cuentas(string _usuarioCuenta, double _saldo, bool _estatus, bool _estado, int _intentos) {
        usuarioCuenta = _usuarioCuenta;
        saldo = _saldo;
        estatus = _estatus;
        estado = _estado;
        intentos = _intentos;
    }

    void retiros(double monto) {
        
        if (intentos < 3) {
            if (saldo >= monto && estado == true) {
                saldo = saldo - monto;
                cout << "El nuevo saldo es de: " << saldo << endl;
            }
            else{
                cout << "Fondos Insuficientes! " << endl;
                intentos = intentos + 1;
                cout << "Usted lleva: " << intentos << " Antes que se bloquee la cuenta" << endl;
            }
        }
        else {
            cout << "La cuenta ha sido bloqueada!" << endl;
            estado = false;
        }
        
    }

    void depositos(double monto ) {
        if (estatus == true && estado == true) {
            saldo = saldo + monto;
        }
        else {
            cout << "La cuenta se encuentra inactiva" << endl;
        }
        
    }

  

};

void menu() {
    cout << "Escoja las opciones en el menu: " << endl;
    cout << "1. Retiros" << endl;
    cout << "2. Depositos" << endl;
}

int main()
{ 
    int op;
    int monto; 
    string caracter;
    menu();

    Cuentas c1("Juan carlos", 2000, true, true, 0);
    cout << "Ingrese la opcion: " << endl;
    cin >> op;

    do {

        switch (op)
        {
        case 1: 
            cout << "Ingrese la cantidad a retirar: " << endl;
            cin >> monto;
            c1.retiros(monto);
            break;
        case 2:
            cout << "Ingrese la cantidad a depositar: " << endl;
            cin >> monto;
            c1.depositos(monto);
            break;
        }
        cout << "Desea continuar? Si/No: " << endl;
        cin >> caracter;
    } while (caracter == "Si" or  caracter == "si");
    
}
