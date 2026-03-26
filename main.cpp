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
        cout << "11. Problema 11\n";
        cout << "13. Problema 13\n";
        cout << "15. Problema 15\n";
        cout << "17. Problema 17\n";
        cout << "0. Salir\n";
        cout << "Seleccione opcion: ";
        op = leerEntero();

        switch(op) {

        case 1:
            billetes();
            break;

        case 3: {
            char a[100], b[100];
            cout << "Cadena 1: ";
            cin >> a;
            cout << "Cadena 2: ";
            cin >> b;
            if (compararCadenas(a, b))
                cout << "Son iguales\n";
            else
                cout << "Son diferentes\n";
            break;
        }

        case 5: {
            int num;
            char res[100];
            cout << "Numero: ";
            num = leerEntero();
            intToString(num, res);
            cout << "Cadena: " << res << endl;
            break;
        }

        case 7: {
            char str[100];
            cout << "Cadena: ";
            cin >> str;
            eliminarRepetidos(str);
            break;
        }

        case 9: {
            char str[100];
            int n;
            cout << "n: ";
            n = leerEntero();
            cout << "Cadena numerica: ";
            cin >> str;
            cout << "Suma: " << sumaPorBloques(str, n) << endl;
            break;
        }

        case 11:
            cine();
            break;

        case 13: {
            int matriz[6][8] = {
                {0,3,4,0,0,0,6,8},
                {5,13,6,0,0,0,2,3},
                {2,6,2,7,3,0,10,0},
                {0,0,4,15,4,1,6,0},
                {0,0,7,12,6,9,10,4},
                {5,0,6,10,6,4,8,0}
            };
            cout << "Estrellas: " << contarEstrellas(matriz) << endl;
            break;
        }

        case 15: {
            int A[4], B[4], C[4];

            cout << "Rectangulo A (x y w h): ";
            for (int i = 0; i < 4; i++)
                A[i] = leerEntero();

            cout << "Rectangulo B (x y w h): ";
            for (int i = 0; i < 4; i++)
                B[i] = leerEntero();

            interseccionRectangulos(A, B, C);

            cout << "Interseccion: ";
            for (int i = 0; i < 4; i++)
                cout << C[i] << " ";
            cout << endl;

            break;
        }

        case 17:
            sumaAmigables();
            break;
        }
    } while (op != 0);

    return 0;
}