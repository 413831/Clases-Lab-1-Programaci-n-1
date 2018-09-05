/*
    printf( " tamaño : %d", sizeof(numeroIngresado));//Se le pasa el dato de cualquier variable, se muestra la CANTIDAD
    printf( " tamaño : %d", sizeof(listadoDeNotas));//Se muestra el tamaño de variable listadoDeNotas
    printf( " dirección : %d",&numeroIngresado);//Se muestra la dirección de memoria  de numeroIngresado
    printf( " dirección : %d",listadoDeNotas);//Se muestra la dirección de memoria de listadoDeNotas, donde comienza el array

    printf( " dirección : %d",numeroIngresado);//Se accede al valor de la variable
    printf( " dirección : %d",listadoDeNotas[0]);//Se accede al dato del array
*/

/*
    for(i=0;i<CANTIDAD;i++)
    {
        printf("\nLa nota es : %d",listadoDeNotas[i]);//Se muestran las notas cargadas
    }
    for(i=0;i<CANTIDAD;i++)
    {
        if(i == 0 || listadoDeNotas[i]>mayor)//Entra la primera vez por i ser 0 luego va comparando cual es el elemento mayor
        {
        mayor = listadoDeNotas[i];
        }
    }
    printf("\n\nEl mayor es el : %d",mayor);

    for(i=CANTIDAD;i>=0;i--)
    {
        if(i == 0 || listadoDeNotas[i]<menor)//Entra la primera vez por i ser 0 luego va comparando cual es el elemento menor
        {
        menor = listadoDeNotas[i];
        }
    }
    printf("\n\nEl menor es el : %d",menor);

    for(i=0;i<CANTIDAD;i++)
    {

        acumulador = acumulador + listadoDeNotas[i];

    }
    cargarListado(listadoDeNotas,CANTIDAD);
    total = retornarTotal(listadoDeNotas,CANTIDAD);
    promedio = promedioNotas(listadoDeNotas,CANTIDAD);
    printf("\nEl promedio es %d",promedio);
    printf("\nLa suma de las notas es: %d ",total);
*/

