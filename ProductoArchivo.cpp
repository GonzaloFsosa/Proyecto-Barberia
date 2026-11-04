#include "ProductoArchivo.h"
#include <cstdio>

bool ProductoArchivo::guardar(Producto reg) {
    FILE *p = fopen("productos.dat", "ab");
    if (p == NULL) return false;
    bool ok = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}

bool ProductoArchivo::guardar(Producto reg, int pos) {
    FILE *p = fopen("productos.dat", "rb+");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return ok;
}

Producto ProductoArchivo::leer(int pos) {
    Producto reg;
    FILE *p = fopen("productos.dat", "rb");
    if (p == NULL) return reg;
    fseek(p, pos * sizeof(Producto), SEEK_SET);
    fread(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return reg;
}

int ProductoArchivo::contarRegistros() {
    FILE *p = fopen("productos.dat", "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Producto);
}

int ProductoArchivo::buscar(int idProducto) {
    int cant = contarRegistros();
    for (int i = 0; i < cant; i++) {
        Producto aux = leer(i);
        if (aux.getIdProducto() == idProducto) return i;
    }
    return -1;
}
