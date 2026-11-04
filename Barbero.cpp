#include "Barbero.h"
#include <iostream>
#include <cstring>
using namespace std;

Barbero::Barbero() {
    setIdBarbero(0);
    setNombre("");
    setApellido("");
    setTelefono("");
    setEmail("");
    setDireccion("");
    setActivo(true);
}

// Getters
int Barbero::getIdBarbero() { return _idBarbero; }
const char* Barbero::getNombre() { return _nombre; }
const char* Barbero::getApellido() { return _apellido; }
const char* Barbero::getTelefono() { return _telefono; }
bool Barbero::getActivo() { return _activo; }
const char* Barbero::getEmail() { return _email; }
const char* Barbero::getDireccion() { return _direccion; }

// Setters
void Barbero::setEmail(const char* email) { strcpy(_email, email); }
void Barbero::setDireccion(const char* direccion) { strcpy(_direccion, direccion); }
void Barbero::setIdBarbero(int id) { _idBarbero = id; }
void Barbero::setNombre(const char* nombre) { strcpy(_nombre, nombre); }
void Barbero::setApellido(const char* apellido) { strcpy(_apellido, apellido); }
void Barbero::setTelefono(const char* telefono) { strcpy(_telefono, telefono); }
void Barbero::setActivo(bool activo) { _activo = activo; }

// Mostrar actualizado
void Barbero::mostrar() {
    cout << "ID: " << _idBarbero << " | " << _apellido << ", " << _nombre
         << " | Tel: " << _telefono << " | Email: " << _email
         << " | Dir: " << _direccion
         << " | Estado: " << (_activo ? "Activo" : "Inactivo") << endl;
}
