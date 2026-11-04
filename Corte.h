#ifndef CORTE_H
#define CORTE_H

class Corte {
private:
    int _idCorte;
    char _nombre[40];
    float _precio;
    int _duracion;
    bool _activo;

public:
    Corte();
    int getIdCorte();
    const char* getNombre();
    float getPrecio();
    int getDuracion();
    bool getActivo();

    void setIdCorte(int id);
    void setNombre(const char* nombre);
    void setPrecio(float precio);
    void setDuracion(int duracion);
    void setActivo(bool activo);

    void mostrar();
};
#endif
