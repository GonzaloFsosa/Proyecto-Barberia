#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
private:
    int _idCliente;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email[50];
    char _direccion[50];
    bool _activo;

public:
    Cliente();
    int getIdCliente();
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    const char* getEmail();
    const char* getDireccion();
    bool getActivo();

    void setIdCliente(int id);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* telefono);
    void setEmail(const char* email);
    void setDireccion(const char* direccion);
    void setActivo(bool activo);

    void mostrar();
};

#endif
