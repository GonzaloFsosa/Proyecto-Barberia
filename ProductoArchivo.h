#ifndef PRODUCTOARCHIVO_H
#define PRODUCTOARCHIVO_H
#include "Producto.h"

class ProductoArchivo {
public:
    bool guardar(Producto reg);
    bool guardar(Producto reg, int pos);
    Producto leer(int pos);
    int contarRegistros();
    int buscar(int idProducto);
};
#endif
