#include <iostream>
using namespace std;

// VALIDADOR DE ENTEROS
int leerEntero() {
        char entrada[100];

        while (true) {
            cin >> entrada;

            bool valido = true;
            int i = 0;

            // validar que todos sean dígitos
            while (entrada[i] != '\0') {
                if (entrada[i] < '0' || entrada[i] > '9') {
                    valido = false;
                    break;
                }
                i++;
            }

            if (valido) {
                // convertir a entero
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

//PROBLEMA 1
void billetes() {
    int dinero;
    cout << "Ingrese dinero: ";
    dinero = leerEntero();

    int denom[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};

    for (int i = 0; i <  sizeof(denom)/sizeof(denom[0]); i++) {
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

    // Ignorar espacios al final
    while (a[i] == ' ') i++;
    while (b[j] == ' ') j++;

    return a[i] == '\0' && b[j] == '\0';
}

//PROBLEMA 5
void intToString(int num, char resultado[]) {
    int i = 0, j;
    int temp = num;

    while (temp > 0) {
        temp /= 10;
        i++;
    }

    if (num == 0) {
        resultado[0] = '0';
        resultado[1] = '\0';
        return;
    }

    resultado[i] = '\0';

    for (j = i - 1; j >= 0; j--) {
        resultado[j] = (num % 10) + '0';
        num /= 10;
    }
}

//  PROBLEMA 7
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

        if (!repetido) {
            resultado[k++] = str[i];
        }
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

        for (int j = 0; j < ceros; j++)
            num = num * 10;

        for (int j = 0; j < faltan; j++)
            num = num * 10 + (str[j] - '0');

        total += num;
        i = faltan;
    }

    while (i < len) {
        int num = 0;

        for (int j = 0; j < n; j++) {
            num = num * 10 + (str[i++] - '0');
        }

        total += num;
    }

    return total;
}

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

        // Validar opción
        if (op != 1 && op != 3 && op != 5 && op != 7 && op != 9 && op != 0) {
            cout << "Opcion invalida, intente de nuevo.\n";
            continue;
        }

        switch(op) {

        case 1:
            billetes();
            break;

        case 3: {
            char a[100], b[100];
            cout << "Cadena 1: "; cin >> a;
            cout << "Cadena 2: "; cin >> b;

            if (compararCadenas(a,b))
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

            intToString(num,res);
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

            cout << "Suma: " << sumaPorBloques(str,n) << endl;
            break;
        }

        }

    } while (op != 0);

    return 0;
}