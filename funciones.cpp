#include <iostream>
#include "funciones.h"
using namespace std;

// VALIDADOR DE ENTEROS
int leerEntero() {
    char entrada[100];
    while (true) {
        cin >> entrada;
        bool valido = true;
        int i = 0;
        while (entrada[i] != '\0') {
            if (entrada[i] < '0' || entrada[i] > '9') {
                valido = false;
                break;
            }
            i++;
        }
        if (valido) {
            int num = 0;
            for (int j = 0; entrada[j] != '\0'; j++) {
                num = num * 10 + (entrada[j] - '0');
            }
            return num;
        } else {
            cout << "Error: ingrese un numero valido: ";
        }
    }
}

// PROBLEMA 1
void billetes() {
    int dinero;
    cout << "Ingrese dinero: ";
    dinero = leerEntero();
    int denom[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};
    for (int i = 0; i < sizeof(denom)/sizeof(denom[0]); i++) {
        int cant = dinero / denom[i];
        dinero %= denom[i];
        cout << denom[i] << " : " << cant << endl;
    }
    cout << "Faltante: " << dinero << endl;
}

// PROBLEMA 3
bool compararCadenas(char a[], char b[]) {
    int i = 0, j = 0;
    while (a[i] != '\0' && b[j] != '\0') {
        while (a[i] == ' ') i++;
        while (b[j] == ' ') j++;
        if (a[i] != b[j]) return false;
        i++;
        j++;
    }
    while (a[i] == ' ') i++;
    while (b[j] == ' ') j++;
    return a[i] == '\0' && b[j] == '\0';
}

// PROBLEMA 5
void intToString(int &num, char resultado[]) {
    int i = 0, j;
    int temp = num;
    while (temp > 0) { temp /= 10; i++; }
    if (num == 0) { resultado[0] = '0'; resultado[1] = '\0'; return; }
    resultado[i] = '\0';
    for (j = i-1; j >= 0; j--) {
        resultado[j] = (num % 10) + '0';
        num /= 10;
    }
}

// PROBLEMA 7
void eliminarRepetidos(char str[]) {
    char resultado[100];
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        bool repetido = false;
        for (int j = 0; j < k; j++) {
            if (str[i] == resultado[j]) {
                repetido = true;
                break;
            }
        }
        if (!repetido) resultado[k++] = str[i];
    }
    resultado[k] = '\0';
    cout << "Original: " << str << endl;
    cout << "Sin repetidos: " << resultado << endl;
}

// PROBLEMA 9
int sumaPorBloques(char str[], int n) {
    int len = 0;
    while (str[len] != '\0') len++;
    int faltan = len % n;
    int total = 0;
    int i = 0;
    if (faltan != 0) {
        int ceros = n - faltan;
        int num = 0;
        for (int j = 0; j < ceros; j++) num = num * 10;
        for (int j = 0; j < faltan; j++) num = num * 10 + (str[j]-'0');
        total += num;
        i = faltan;
    }
    while (i < len) {
        int num = 0;
        for (int j = 0; j < n; j++) num = num * 10 + (str[i++] - '0');
        total += num;
    }
    return total;
}
// PROBLEMA 11 - Sistema de reservas de cine
void cine() {
    // Crear sala 15x20
    char sala[15][20];
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            sala[i][j] = '-'; // asiento libre
        }
    }

    int opcion;
    do {
        cout << "\n1. Mostrar sala\n";
        cout << "2. Reservar asiento\n";
        cout << "3. Cancelar reserva\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        opcion = leerEntero();

        // MOSTRAR SALA
        if (opcion == 1) {
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 20; j++) {
                    cout << sala[i][j] << " ";
                }
                cout << endl;
            }
        }

        // RESERVAR ASIENTO
        if (opcion == 2) {
            char fila;
            int asiento;

            // Validar fila
            while (true) {
                cout << "Fila (A-O): ";
                cin >> fila;
                if ((fila >= 'A' && fila <= 'O') || (fila >= 'a' && fila <= 'o'))
                    break;
                cout << "Fila invalida, intente otra vez.\n";
            }

            // Convertir minúscula a mayúscula
            if (fila >= 'a' && fila <= 'o') fila -= 32;

            // Validar asiento
            while (true) {
                cout << "Asiento (1-20): ";
                asiento = leerEntero();
                if (asiento >= 1 && asiento <= 20) break;
                cout << "Asiento invalido.\n";
            }

            int f = fila - 'A';  // convertir letra a índice (A=0, B=1...)
            int a = asiento - 1; // convertir asiento a índice (1 = 0)

            // Validar disponibilidad
            if (sala[f][a] == '+') {
                cout << "La silla ya está ocupada.\n";
            } else {
                sala[f][a] = '+';
                cout << "Reserva exitosa.\n";
            }
        }

        // CANCELAR RESERVA
        if (opcion == 3) {
            char fila;
            int asiento;

            // Validar fila
            while (true) {
                cout << "Fila (A-O): ";
                cin >> fila;
                if ((fila >= 'A' && fila <= 'O') || (fila >= 'a' && fila <= 'o'))
                    break;
                cout << "Fila invalida, intente otra vez.\n";
            }

            // Convertir minúscula a mayúscula
            if (fila >= 'a' && fila <= 'o') fila -= 32;

            // Validar asiento
            while (true) {
                cout << "Asiento (1-20): ";
                asiento = leerEntero();
                if (asiento >= 1 && asiento <= 20) break;
                cout << "Asiento invalido.\n";
            }

            int f = fila - 'A';
            int a = asiento - 1;

            // Validar si estaba reservada
            if (sala[f][a] == '+') {
                sala[f][a] = '-';
                cout << "Cancelación exitosa.\n";
            } else {
                cout << "La silla no estaba reservada.\n";
            }
        }

    } while (opcion != 0);
}

// PROBLEMA 13 - Matriz dinámica y conteo de estrellas
int contarEstrellas(int matrizOriginal[6][8]) {
    // Crear matriz dinámica 6x8
    int **matriz = new int*[6];
    for (int i = 0; i < 6; i++) {
        matriz[i] = new int[8];
        for (int j = 0; j < 8; j++) {
            matriz[i][j] = matrizOriginal[i][j];
        }
    }

    int estrellas = 0;

    // Recorrer matriz interna (no bordes)
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 7; j++) {
            int suma =
                matriz[i][j] +     // centro
                matriz[i][j-1] +   // izquierda
                matriz[i][j+1] +   // derecha
                matriz[i-1][j] +   // arriba
                matriz[i+1][j];    // abajo

            if (suma / 5 > 6)
                estrellas++;
        }
    }

    // Liberar memoria dinámica
    for (int i = 0; i < 6; i++)
        delete[] matriz[i];
    delete[] matriz;

    return estrellas;
}

// PROBLEMA 15 - Intersección de rectángulos usando punteros
void interseccionRectangulos(int *A, int *B, int *C) {

    // Acceder con punteros *(A+índice)
    int Ax = *(A + 0), Ay = *(A + 1), Aw = *(A + 2), Ah = *(A + 3);
    int Bx = *(B + 0), By = *(B + 1), Bw = *(B + 2), Bh = *(B + 3);

    int x1 = (Ax > Bx ? Ax : Bx);
    int y1 = (Ay > By ? Ay : By);

    int x2A = Ax + Aw;
    int y2A = Ay + Ah;
    int x2B = Bx + Bw;
    int y2B = By + Bh;

    int x2 = (x2A < x2B ? x2A : x2B);
    int y2 = (y2A < y2B ? y2A : y2B);

    // Si hay intersección
    if (x1 < x2 && y1 < y2) {
        *(C + 0) = x1;
        *(C + 1) = y1;
        *(C + 2) = x2 - x1;
        *(C + 3) = y2 - y1;
    } else {
        *(C + 0) = 0;
        *(C + 1) = 0;
        *(C + 2) = 0;
        *(C + 3) = 0;
    }
}

// PROBLEMA 17 - Números amigables con punteros
int sumaDivisores17(int n) {
    // suma dinámica
    int *suma = new int(1);

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            *suma += i;
    }

    int resultado = *suma;
    delete suma;
    return resultado;
}

void sumaAmigables() {
    int limite;
    cout << "Ingrese numero limite: ";
    limite = leerEntero();

    // total dinámico
    int *total = new int(0);

    for (int a = 2; a < limite; a++) {
        int b = sumaDivisores17(a);

        if (b != a && sumaDivisores17(b) == a && a < limite) {
            *total += a;
        }
    }

    cout << "El resultado de la suma es: " << *total << endl;

    delete total;
}