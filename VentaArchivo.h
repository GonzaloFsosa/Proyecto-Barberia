#ifndef VENTAARCHIVO_H
#define VENTAARCHIVO_H
#include "Venta.h"

class VentaArchivo {
public:
    bool guardar(Venta reg);
    bool guardar(Venta reg, int pos);
    Venta leer(int pos);
    int contarRegistros();
    int buscar(int idVenta);
};
#endif
