#include "Corte.h"
#include <iostream>
#include <cstring>
using namespace std;

Corte::Corte() {
    setIdCorte(0); setNombre(""); setPrecio(0); setDuracion(0); setActivo(true);
}

int Corte::getIdCorte() { return _idCorte; }
const char* Corte::getNombre() { return _nombre; }
float Corte::getPrecio() { return _precio; }
int Corte::getDuracion() { return _duracion; }
bool Corte::getActivo() { return _activo; }

void Corte::setIdCorte(int id) { _idCorte = id; }
void Corte::setNombre(const char* nombre) { strcpy(_nombre, nombre); }
void Corte::setPrecio(float precio) { _precio = precio; }
void Corte::setDuracion(int duracion) { _duracion = duracion; }
void Corte::setActivo(bool activo) { _activo = activo; }

void Corte::mostrar() {
    cout << "ID: " << _idCorte << " | " << _nombre
         << " | Precio: $" << _precio << " | Dur: " << _duracion << "min"
         << " | Estado: " << (_activo ? "Activo" : "Inactivo") << endl;
}
