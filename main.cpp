#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int op;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Problema 1\n";
        cout << "3. Problema 3\n";
        cout << "5. Problema 5\n";
        cout << "7. Problema 7\n";
        cout << "9. Problema 9\n";
        cout << "0. Salir\n";
        cout << "Seleccione opcion: ";
        op = leerEntero();

        switch(op) {
        case 1: billetes(); break;
        case 3: {
            char a[100], b[100];
            cout << "Cadena 1: "; cin >> a;
            cout << "Cadena 2: "; cin >> b;
            if (compararCadenas(a,b)) cout << "Son iguales\n";
            else cout << "Son diferentes\n";
            break;
        }
        case 5: {
            int num; char res[100];
            cout << "Numero: "; num = leerEntero();
            intToString(num,res);
            cout << "Cadena: " << res << endl;
            break;
        }
        case 7: {
            char str[100];
            cout << "Cadena: "; cin >> str;
            eliminarRepetidos(str);
            break;
        }
        case 9: {
            char str[100]; int n;
            cout << "n: "; n = leerEntero();
            cout << "Cadena numerica: "; cin >> str;
            cout << "Suma: " << sumaPorBloques(str,n) << endl;
            break;
        }
        }
    } while(op != 0);
    return 0;
}