#include "Venta.h"
#include <iostream>
using namespace std;

Venta::Venta() {
    setIdVenta(0); setIdProducto(0); setCantidad(0); setPrecioUnitario(0);
    setFecha(Fecha());
}

int Venta::getIdVenta() { return _idVenta; }
int Venta::getIdProducto() { return _idProducto; }
int Venta::getCantidad() { return _cantidad; }
float Venta::getPrecioUnitario() { return _precioUnitario; }
Fecha Venta::getFecha() { return _fecha; }

void Venta::setIdVenta(int id) { _idVenta = id; }
void Venta::setIdProducto(int id) { _idProducto = id; }
void Venta::setCantidad(int cantidad) { _cantidad = cantidad; }
void Venta::setPrecioUnitario(float precio) { _precioUnitario = precio; }
void Venta::setFecha(Fecha fecha) { _fecha = fecha; }

void Venta::mostrar() {
    cout << "ID Venta: " << _idVenta << " | Prod: " << _idProducto
         << " | Cant: " << _cantidad << " | Precio U: $" << _precioUnitario
         << " | Fecha: " << _fecha.toString() << endl;
}
