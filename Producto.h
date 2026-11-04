#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    int _idProducto;
    char _nombre[40];
    char _categoria[30];
    float _precio;
    int _stock;
    int _stockMinimo;
    bool _activo;

public:
    Producto();
    int getIdProducto();
    const char* getNombre();
    const char* getCategoria();
    float getPrecio();
    int getStock();
    int getStockMinimo();
    bool getActivo();

    void setIdProducto(int id);
    void setNombre(const char* nombre);
    void setCategoria(const char* categoria);
    void setPrecio(float precio);
    void setStock(int stock);
    void setStockMinimo(int stockMinimo);
    void setActivo(bool activo);

    void mostrar();
};
#endif
