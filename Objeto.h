//
// Created by rodri on 25/6/2019.
//

#ifndef AGREGACION_OBJETO_H
#define AGREGACION_OBJETO_H
#include <iostream>
#include "Tipos.h"
using namespace std;

class Objeto {
private:
    string        nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
public:
    Objeto();
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY);
    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    char getColor();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
};

#endif //AGREGACION_OBJETO_