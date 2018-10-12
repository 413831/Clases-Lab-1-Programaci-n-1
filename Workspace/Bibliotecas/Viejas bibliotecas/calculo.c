#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"


/**
 * \brief Recibe el radio y calcula el área del círculo
 * \param Radio correspondiente al radio del círculo
 * \return Retorna el resultado del calculo área del círculo
 */
float calculo_AreaCirculo(float radio)
{
    float resultado;
    resultado = 3.14 * radio * radio;
    return resultado;
}
