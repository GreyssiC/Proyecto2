//
// Created by rodri on 25/6/2019.
//

#ifndef AGREGACION_TIERRA_H
#define AGREGACION_TIERRA_H
#include <iostream>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"
#include <SFML/Graphics.hpp>
using namespace std;
// Valores constantes
const TipoEntero ALTURA = 21;
const TipoEntero ANCHO  = 21;
const TipoCaracter COLOR ='.';

class Tierra {
private:
    sf::RenderWindow* plano;
    vector<Objeto*> objetos;
public:
    Tierra();
    Tierra(TipoEntero altura, TipoEntero ancho);
    virtual ~Tierra();
    void adicionarObjeto(Objeto* objeto);
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjectos();
    void dibujarTierra();
    void actualizarTierra();
};

#endif //AGREGACION_TIERRA_Htierra.h