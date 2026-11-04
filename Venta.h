#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"

class Venta {
private:
    int _idVenta;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    Fecha _fecha;

public:
    Venta();
    int getIdVenta();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    Fecha getFecha();

    void setIdVenta(int id);
    void setIdProducto(int id);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precio);
    void setFecha(Fecha fecha);

    void mostrar();
};
#endif
