#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int index;
    char bufferId[1000];
    char bufferName[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[1000];
    int auxHorasTrabajadas;
    int auxSueldo;
    int auxId;
    int flagOnce = 1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce == 1)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
                flagOnce = 0;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
            index = parser_searchEmpty(pArrayListEmployee,4000);
            pArrayListEmployee[index] = Employee_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,bufferSueldo);
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
