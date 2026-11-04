#include "Cliente.h"
#include <iostream>
#include <cstring>
using namespace std;

Cliente::Cliente() {
    setIdCliente(0); setNombre(""); setApellido(""); setTelefono("");
    setEmail(""); setDireccion(""); setActivo(true);
}

int Cliente::getIdCliente() { return _idCliente; }
const char* Cliente::getNombre() { return _nombre; }
const char* Cliente::getApellido() { return _apellido; }
const char* Cliente::getTelefono() { return _telefono; }
const char* Cliente::getEmail() { return _email; }
const char* Cliente::getDireccion() { return _direccion; }
bool Cliente::getActivo() { return _activo; }

void Cliente::setIdCliente(int id) { _idCliente = id; }
void Cliente::setNombre(const char* nombre) { strcpy(_nombre, nombre); }
void Cliente::setApellido(const char* apellido) { strcpy(_apellido, apellido); }
void Cliente::setTelefono(const char* telefono) { strcpy(_telefono, telefono); }
void Cliente::setEmail(const char* email) { strcpy(_email, email); }
void Cliente::setDireccion(const char* direccion) { strcpy(_direccion, direccion); }
void Cliente::setActivo(bool activo) { _activo = activo; }

void Cliente::mostrar() {
    cout << "ID: " << _idCliente << " | " << _apellido << ", " << _nombre
         << " | Tel: " << _telefono << " | Email: " << _email
         << " | Estado: " << (_activo ? "Activo" : "Inactivo") << endl;
}
