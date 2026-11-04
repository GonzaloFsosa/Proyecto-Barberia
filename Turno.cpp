#include "Turno.h"
#include <iostream>
#include <cstring>
using namespace std;

Turno::Turno() {
    setIdTurno(0); setIdCliente(0); setIdBarbero(0); setIdCorte(0);
    setFecha(Fecha()); // Fecha por defecto 1/1/2023
    setHora(""); setEstado(1); // Pendiente por defecto
}

int Turno::getIdTurno() { return _idTurno; }
int Turno::getIdCliente() { return _idCliente; }
int Turno::getIdBarbero() { return _idBarbero; }
int Turno::getIdCorte() { return _idCorte; }
Fecha Turno::getFecha() { return _fecha; }
const char* Turno::getHora() { return _hora; }
int Turno::getEstado() { return _estado; }

void Turno::setIdTurno(int id) { _idTurno = id; }
void Turno::setIdCliente(int id) { _idCliente = id; }
void Turno::setIdBarbero(int id) { _idBarbero = id; }
void Turno::setIdCorte(int id) { _idCorte = id; }
void Turno::setFecha(Fecha fecha) { _fecha = fecha; }
void Turno::setHora(const char* hora) { strcpy(_hora, hora); }
void Turno::setEstado(int estado) { _estado = estado; }

void Turno::mostrar() {
    cout << "ID Turno: " << _idTurno << " | Cliente: " << _idCliente
         << " | Barbero: " << _idBarbero << " | Corte: " << _idCorte
         << " | Fecha: " << _fecha.toString() << " " << _hora
         << " | Estado: " << _estado << endl;
}
