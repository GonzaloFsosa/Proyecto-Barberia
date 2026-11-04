#ifndef BARBERO_H
#define BARBERO_H

class Barbero {
private:
    int _idBarbero;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email[50];      // <-- NUEVO
    char _direccion[50];  // <-- NUEVO
    bool _activo;         // <-- NUEVO

public:
    Barbero();

    int getIdBarbero();
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    const char* getEmail();      // <-- NUEVO
    const char* getDireccion();  // <-- NUEVO
    bool getActivo();

    void setIdBarbero(int id);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);         // <-- NUEVO
    void setDireccion(const char* direccion); // <-- NUEVO
    void setActivo(bool activo);

    void mostrar();
};

#endif
