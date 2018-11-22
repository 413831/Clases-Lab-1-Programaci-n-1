#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entityBuilder.h"
/*

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    int estado;
}Socio;

./entityBuilder Socio int id char nombre[51] char apellido[51] char dni[51] int estado


*/



int main(int argc, char **argv)
{
    char entityName[256];
    char entityNameUp[256];
    char headerName[256];
    char cFileName[256];
    Member members[256];
    int qtyMembers;
    int i,j;
    char* result = malloc(sizeof(char)*50000);
    FILE* header;
    FILE* cFile;

 printf("%d",argc);
    if((argc >= 4) && (argc%2 != 1))
    {
        strcpy(headerName,*(argv+1));
        strcat(headerName,".h");
        strcpy(cFileName,*(argv+1));
        strcat(cFileName,".c");

        header = fopen(headerName,"w");
        cFile = fopen(cFileName,"w");
        qtyMembers = (argc - 2) / 2;
        //printf("ENTIDAD %s - CANTIDAD MIEMBROS: %d\n", *(argv+1),qtyMembers);
        strcpy(entityName,*(argv+1));
        j=0;
        for(i=2;i<argc;i=i+2)
        {
            //printf("TIPO %s - NOMBRE %s\n", *(argv+i),*(argv+i+1));
            strcpy(members[j].type,*(argv+i));
            strcpy(members[j].definition,*(argv+i+1));
            j++;
        }


    strToUpper(entityName,entityNameUp);
    fprintf(header,"\n\n********************* %s.h ************************\n\n",entityName);
    fprintf(header,"#include \"LinkedList.h\"\n\n#ifndef _%s_H\n#define _%s_H\n",entityNameUp,entityNameUp);  // _EMPLOYEE_H
    entity_buildStruct(entityName, members, qtyMembers, result);
    fprintf(header,"%s",result);
    fprintf(header,"#endif// _%s_H\n\n\n#define BUFFER 4000\n#define LEN_LL 6",entityNameUp);
    entity_buildConstructorPrototype(entityName, members, qtyMembers, result);
    fprintf(header,"%s",result);
    entity_buildDestructorPrototype(entityName,result);
    fprintf(header,"%s",result);
    entity_buildSettersPrototypes(entityName, members, qtyMembers, result);
    fprintf(header,"%s",result);
    entity_buildGettersPrototypes(entityName, members, qtyMembers, result);
    fprintf(header,"%s",result);
    entity_buildFindersPrototypes(entityName, members, qtyMembers, result);
    fprintf(header,"%s",result);
    entity_buildComparativeFunctionsPrototypes(entityName, members, qtyMembers, result);
    fprintf(header,"%s",result);
    entity_buildShowFunctionPrototype(entityName,result);
    fprintf(header,"%s",result);
    fprintf(header,"\n\n********************* %s.h ************************\n\n",entityName);

    fprintf(cFile,"\n\n********************* %s.c ************************\n\n",entityName);
    fprintf(cFile,"#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include \"LinkedList.h\"\n#include \"utn.h\"\n#include \"%s.h\"\n#include \"parser.h\"\n#include \"controller.h\"\n\n",entityName);  // _EMPLOYEE_H
    entity_buildConstructor(entityName, members, qtyMembers, result);
    fprintf(cFile,"%s",result);
    entity_buildDestructor(entityName,result);
    fprintf(cFile,"%s",result);
    entity_buildSetters(entityName, members, qtyMembers, result);
    fprintf(cFile,"%s",result);
    entity_buildGetters(entityName, members, qtyMembers, result);
    fprintf(cFile,"%s",result);
    entity_buildFinders(entityName, members, qtyMembers, result);
    fprintf(cFile,"%s",result);
    entity_buildComparativeFunctions(entityName, members, qtyMembers, result);
    fprintf(cFile,"%s",result);
    entity_buildShowFunction(entityName, members, qtyMembers, result);
    fprintf(cFile,"%s",result);
    fprintf(cFile,"\n\n********************* %s.c ************************\n\n",entityName);

    fclose(header);
    fclose(cFile);
    }
    else
    {
        printf("\n\nERROR DE FORMATO\n\n\n./entityBuilder Employee int id char name[51] char lastName[51] int age int type\n\n");
    }
    exit(EXIT_SUCCESS);

}

