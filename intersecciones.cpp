#include <iostream>
using namespace std;

struct Punto {
    int x, y;
};

// Funcion para encontrar la orientacion del triplete (p, q, r).
int orientacion(Punto p, Punto q, Punto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colineales
    return (val > 0) ? 1 : 2; // en sentido horario o antihorario
}

// Funcion para verificar si el punto q está en el segmento pr.
bool enSegmento(Punto p, Punto q, Punto r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// Funcion para verificar si dos segmentos se intersectan.
int seIntersectan(Punto p1, Punto q1, Punto p2, Punto q2) {
    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return 1;

    if (o1 == 0 && enSegmento(p1, p2, q1)) return 1;
    if (o2 == 0 && enSegmento(p1, q2, q1)) return 1;
    if (o3 == 0 && enSegmento(p2, p1, q2)) return 1;
    if (o4 == 0 && enSegmento(p2, q1, q2)) return 1;

    return -1;
}

// Funcion para verificar si las lineas se cruzan, son paralelas o no se cruzan.
int verificarLineas(Punto p1, Punto q1, Punto p2, Punto q2) {
    if (seIntersectan(p1, q1, p2, q2) == 1) {
        return 1;
    } else if (orientacion(p1, q1, p2) == orientacion(p1, q1, q2)) {
        return 0;
    } else {
        return -1;
    }
}

// Funcion para verificar si las lineas son perpendiculares, paralelas o no se cruzan.
int verificarLineasPerpendiculares(Punto p1, Punto q1, Punto p2, Punto q2) {
    int dx1 = q1.x - p1.x;
    int dy1 = q1.y - p1.y;
    int dx2 = q2.x - p2.x;
    int dy2 = q2.y - p2.y;

    if (dx1 * dx2 + dy1 * dy2 == 0) {
        return 1;
    } else if (orientacion(p1, q1, p2) == orientacion(p1, q1, q2)) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    Punto puntos[4];
    for (int i = 0; i < 4; ++i) {
        cout << "Ingrese coordenadas para el punto " << i + 1 << " (x y): ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    int resultado = verificarLineas(puntos[0], puntos[1], puntos[2], puntos[3]);
    cout << "Resultado de interseccion: " << resultado << endl;

    int resultadoPerpendicular = verificarLineasPerpendiculares(puntos[0], puntos[1], puntos[2], puntos[3]);
    cout << "Resultado de perpendicularidad: " << resultadoPerpendicular << endl;

    return 0;
}