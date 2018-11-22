#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "entityBuilder.h"

static int isArray(char* definition,char* result);


int entity_buildStruct(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    *result = '\0';
    sprintf(result,"typedef struct\n{\n");
    for(i=0;i<qtyMembers;i++)
    {
        sprintf(auxString,"\t%s %s;\n", members[i].type,members[i].definition);
        strcat(result,auxString);
    }
    sprintf(auxString,"}%s;\n", entityName);
    strcat(result,auxString);
    return 0;
}



int entity_buildConstructorPrototype(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024]="";
    *result = '\0';

    char auxPrefix[1024];

    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));


    sprintf(result,"%s* %sconstructor(",entityName,auxPrefix);

    for(i=0;i<qtyMembers;i++)
    {
        if(isArray(members[i].definition,auxDefinition) == 1)
            sprintf(auxString,"%s* %s", members[i].type,auxDefinition);
        else
            sprintf(auxString,"%s %s", members[i].type,members[i].definition);

        strcat(result,auxString);
        if((i+1)<qtyMembers) strcat(result,",");
    }
    sprintf(auxString,");\n");
    strcat(result,auxString);
    return 0;
}


int entity_buildConstructor(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    sprintf(result,"%s* %sconstructor(",entityName,auxPrefix);

    for(i=0;i<qtyMembers;i++)
    {
        if(isArray(members[i].definition,auxDefinition) == 1)
            sprintf(auxString,"%s* %s", members[i].type,auxDefinition);
        else
            sprintf(auxString,"%s %s", members[i].type,members[i].definition);

        strcat(result,auxString);
        if((i+1)<qtyMembers) strcat(result,",");
    }
    sprintf(auxString,")\n{\n");
    strcat(result,auxString);

    sprintf(auxString,"\t%s* this = malloc(sizeof(%s));\n", entityName, entityName);
    strcat(result,auxString);

    sprintf(auxString,"\n\tif(this != NULL)\n\t{\n\t\tif(");
    strcat(result,auxString);

    for(i=0;i<qtyMembers;i++)
    {
        isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));

        sprintf(auxString,"\t!%sset%s(this,%s) &&\n\t\t", auxPrefix,auxDefinitionUp,auxDefinition);
        strcat(result,auxString);
    }
    sprintf(auxString,"\t)\n\t\t{\n\t\t\treturn this;\n\t\t}\n\t\telse\n\t\t{\n\t\t\t%sdestructor(this);\n\t\t\treturn NULL;\n\t\t}\n\t}\n}\n\n",auxPrefix);
    strcat(result,auxString);

    return 0;
}

int entity_buildDestructor(char* entityName,char* result)
{
    char auxPrefix[1024];
    *result = '\0';

    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    sprintf(result,"int %sdestructor(%s* this)\n{\n\tint retorno = -1;\n\tif(this != NULL)\n\t{\n\t\tfree(this);\n\t\tretorno = 0;\n\t}\n\treturn retorno;\n}\n\n",auxPrefix,entityName);

    return 0;
}

int entity_buildDestructorPrototype(char* entityName,char* result)
{
    char auxPrefix[1024];
    *result = '\0';

    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    sprintf(result,"int %sdelete(%s* this);\n",auxPrefix,entityName);

    return 0;
}


int entity_buildSetters(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));


        if(flagArray)
            sprintf(auxString,"int %sset%s(%s* this,%s* %s)\n{\n\tint retorno = -1;\n\tif(this != NULL && %s != NULL)\n\t{\n\t\tstrcpy(this->%s,%s);\n\t\tretorno = 0;\n\t}\n\treturn = retorno;\n}\n\n", auxPrefix,auxDefinitionUp,entityName,members[i].type,auxDefinition,auxDefinition,auxDefinition,auxDefinition);
        else
            sprintf(auxString,"int %sset%s(%s* this,%s %s)\n{\n\tint retorno = -1;\n\tif(this != NULL)\n\t{\n\t\tthis->%s = %s;\n\t\tretorno = 0;\n\t}\n\treturn = retorno;\n}\n\n", auxPrefix,auxDefinitionUp,entityName,members[i].type,auxDefinition,auxDefinition,auxDefinition);

        strcat(result,auxString);
    }


    return 0;
}

int entity_buildSettersPrototypes(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));


        if(flagArray)
            sprintf(auxString,"int %sset%s(%s* this,%s* %s);\n", auxPrefix,auxDefinitionUp,entityName,members[i].type,auxDefinition);
        else
            sprintf(auxString,"int %sset%s(%s* this,%s %s);\n", auxPrefix,auxDefinitionUp,entityName,members[i].type,auxDefinition);

        strcat(result,auxString);
    }


    return 0;
}
int entity_buildGetters(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));

        if(flagArray)
            sprintf(auxString,"%s* %sget%s(%s* this)\n{\n\tchar* retorno = NULL;\n\tif(this != NULL)\n\t{\n\t\tstrcpy(retorno,this->%s);\n\t}\n\treturn = retorno;\n}\n\n", members[i].type, auxPrefix,auxDefinitionUp,entityName,auxDefinition);
        else
           sprintf(auxString,"%s %sget%s(%s* this)\n{\n\tint retorno = -1;\n\tif(this != NULL)\n\t{\n\t\tretorno = this->%s;\n\t}\n\treturn = retorno;\n}\n\n", members[i].type, auxPrefix,auxDefinitionUp,entityName,auxDefinition);


        strcat(result,auxString);
    }

    return 0;
}

int entity_buildGettersPrototypes(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));

        if(flagArray)
            sprintf(auxString,"%s* %sget%s(%s* this);\n", members[i].type, auxPrefix,auxDefinitionUp,entityName);
        else
           sprintf(auxString,"%s %sget%s(%s* this);\n", members[i].type, auxPrefix,auxDefinitionUp,entityName);


        strcat(result,auxString);
    }

    return 0;
}



int entity_buildFinders(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));

//"
        if(flagArray)
            sprintf(auxString,"%s* %sgetBy%s(LinkedList* pArray,%s* %s)\n{\n\tint i;\n\t%s* aux;\n\t%s* retorno=NULL;\n\tfor(i=0;i<ll_len(pArray);i++)\n\t{\n\t\taux = ll_get(pArray,i);\n\t\tif(strcmp(%s,%sget%s(aux))==0)\n\t\t{\n\t\t\tretorno = aux;\n\t\t\tbreak;\n\t\t}\n\t}\n\treturn retorno;\n}\n\n",
                        entityName,auxPrefix,auxDefinitionUp,members[i].type,auxDefinition,
                        entityName,entityName,
                        auxDefinition,auxPrefix,auxDefinitionUp);
        else
            sprintf(auxString,"%s* %sgetBy%s(LinkedList* pArray,%s %s)\n{\n\tint i;\n\t%s* aux;\n\t%s* retorno=NULL;\n\tfor(i=0;i<ll_len(pArray);i++)\n\t{\n\t\taux = ll_get(pArray,i);\n\t\tif(%s == %sget%s(aux))\n\t\t{\n\t\t\tretorno = aux;\n\t\t\tbreak;\n\t\t}\n\t}\n\treturn retorno;\n}\n\n",
                        entityName,auxPrefix,auxDefinitionUp,members[i].type,auxDefinition,
                        entityName,entityName,
                        auxDefinition,auxPrefix,auxDefinitionUp);

        strcat(result,auxString);
    }


    return 0;
}

int entity_buildFindersPrototypes(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));

//"
        if(flagArray)
            sprintf(auxString,"%s* %sgetBy%s(LinkedList* pArray,%s* %s);\n",
                        entityName,auxPrefix,auxDefinitionUp,members[i].type,auxDefinition);
        else
            sprintf(auxString,"%s* %sgetBy%s(LinkedList* pArray,%s %s);\n",
                        entityName,auxPrefix,auxDefinitionUp,members[i].type,auxDefinition);

        strcat(result,auxString);
    }


    return 0;
}



int entity_buildComparativeFunctions(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));

//"
        if(flagArray)
            sprintf(auxString,"int %scompareBy%s(%s* thisA ,%s* thisB)\n{\n\tint retorno = 0;\n\n\tif(thisA != NULL && thisB != NULL)\n\t{\n\t\tretorno = strcmp(%sget%s(thisA),%sget%s(thisB));\n\t}\n\treturn retorno;\n}\n\n",

                        auxPrefix,auxDefinitionUp,"void","void",
                        auxPrefix,auxDefinitionUp,auxPrefix,auxDefinitionUp);
        else
            sprintf(auxString,"int %scompareBy%s(%s* thisA ,%s* thisB)\n{\n\tint retorno = 0;\n\n\tif(thisA != NULL && thisB != NULL)\n\t{\n\t\tif(%sget%s(thisA) > %sget%s(thisB))\n\t\t{\n\t\t\t\tretorno = 1;\n\t\t}\n\t\telse if(%sget%s(thisA) < %sget%s(thisB))\n\t\t{\n\t\t\tretorno = -1;\n\t\t}\n\t}\n\treturn retorno;\n}\n\n",

                        auxPrefix,auxDefinitionUp,"void","void",
                        auxPrefix,auxDefinitionUp,auxPrefix,auxDefinitionUp,
                        auxPrefix,auxDefinitionUp,auxPrefix,auxDefinitionUp);

        strcat(result,auxString);
    }


    return 0;
}

int entity_buildComparativeFunctionsPrototypes(char* entityName, Member* members,int qtyMembers, char* result)
{
    int i;
    char auxString[1024];
    char auxDefinition[1024];
    char auxDefinitionUp[1024];
    int flagArray;
    *result = '\0';
    char auxPrefix[1024];
    if(strlen(entityName) > 1)
        sprintf(auxPrefix,"%c%s_",tolower(entityName[0]),entityName+1);
    else
        sprintf(auxPrefix,"%c_",tolower(entityName[0]));

    for(i=0;i<qtyMembers;i++)
    {
        flagArray = isArray(members[i].definition,auxDefinition);
        if(strlen(auxDefinition) > 1)
            sprintf(auxDefinitionUp,"%c%s",toupper(auxDefinition[0]),auxDefinition+1);
        else
            sprintf(auxDefinitionUp,"%c",toupper(auxDefinition[0]));

//"
        if(flagArray)
            sprintf(auxString,"int %scompareBy%s(%s* thisA ,%s* thisB);\n",

                        auxPrefix,auxDefinitionUp,"void","void");
        else
            sprintf(auxString,"int %scompareBy%s(%s* thisA ,%s* thisB);\n",

                        auxPrefix,auxDefinitionUp,"void","void");

        strcat(result,auxString);
    }


    return 0;
}




static int isArray(char* definition,char* result)
{
    int i;
    int retorno = 0;
    *result = '\0';
    for(i=0; i < strlen(definition); i++)
    {

        if(*(definition+i)== '[')
        {
            retorno = 1;
            *(result+i) = '\0';
            break;
        }
        *(result+i) = *(definition+i);
    }
    *(result+i) = '\0';
    return retorno;
}


void strToUpper(char *str,char *strUp)
{
  while(*str != '\0')
  {
    *strUp = toupper(*str);
    str++;
    strUp++;
  }
}
