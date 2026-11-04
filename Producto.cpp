#include "Producto.h"
#include <iostream>
#include <cstring>
using namespace std;

Producto::Producto() {
    setIdProducto(0); setNombre(""); setCategoria(""); setPrecio(0);
    setStock(0); setStockMinimo(0); setActivo(true);
}

int Producto::getIdProducto() { return _idProducto; }
const char* Producto::getNombre() { return _nombre; }
const char* Producto::getCategoria() { return _categoria; }
float Producto::getPrecio() { return _precio; }
int Producto::getStock() { return _stock; }
int Producto::getStockMinimo() { return _stockMinimo; }
bool Producto::getActivo() { return _activo; }

void Producto::setIdProducto(int id) { _idProducto = id; }
void Producto::setNombre(const char* nombre) { strcpy(_nombre, nombre); }
void Producto::setCategoria(const char* categoria) { strcpy(_categoria, categoria); }
void Producto::setPrecio(float precio) { _precio = precio; }
void Producto::setStock(int stock) { _stock = stock; }
void Producto::setStockMinimo(int stockMinimo) { _stockMinimo = stockMinimo; }
void Producto::setActivo(bool activo) { _activo = activo; }

void Producto::mostrar() {
    cout << "ID: " << _idProducto << " | " << _nombre << " | Cat: " << _categoria
         << " | Precio: $" << _precio << " | Stock: " << _stock
         << " | Min: " << _stockMinimo << " | Estado: " << (_activo ? "Activo" : "Inactivo") << endl;
}
