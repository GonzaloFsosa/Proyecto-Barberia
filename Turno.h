#ifndef TURNO_H
#define TURNO_H
#include "Fecha.h" // Asegurate de tener Fecha.h en el proyecto

class Turno {
private:
    int _idTurno;
    int _idCliente;
    int _idBarbero;
    int _idCorte;
    Fecha _fecha; // Composición
    char _hora[6];
    int _estado; // 1: Pendiente, 2: Atendido, 3: Cancelado

public:
    Turno();
    int getIdTurno();
    int getIdCliente();
    int getIdBarbero();
    int getIdCorte();
    Fecha getFecha();
    const char* getHora();
    int getEstado();

    void setIdTurno(int id);
    void setIdCliente(int id);
    void setIdBarbero(int id);
    void setIdCorte(int id);
    void setFecha(Fecha fecha);
    void setHora(const char* hora);
    void setEstado(int estado);

    void mostrar();
};
#endif
