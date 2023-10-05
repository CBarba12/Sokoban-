#include "Nodo.h"

Nodo::Nodo(char val) : valor(val), arriba(nullptr), abajo(nullptr), izquierda(nullptr), derecha(nullptr), esCaja(false), esObstaculo(false), pos_ganadora('L'), cuenta(0) {}
