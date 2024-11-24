#include <iostream>

using namespace std;

int contadorLlamadas = 0;

int sumarNumeros(int a, int b) {
    contadorLlamadas++;
    return a + b;
}

int obtenerContadorLlamadas() {
    return contadorLlamadas;
}

int main() {
    int resultado1 = sumarNumeros(3, 4);
    int resultado2 = sumarNumeros(5, 6);
    int resultado3 = sumarNumeros(7, 8);
    
    cout << "sumarNumeros fue llamada " << obtenerContadorLlamadas() << " veces." << endl;
    cout << "Resultados: " << resultado1 << ", " << resultado2 << ", " << resultado3 << endl;

    return 0;
}