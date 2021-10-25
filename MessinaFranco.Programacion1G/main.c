#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define AUMENTO 5
#define TAM 10
/*
Crear una función llamada aplicarAumento
 que reciba como parámetro el precio de un producto y
 devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main.


 * Crear una función que se llame reemplazarCaracteres que reciba una cadena de
   caracteres como primer parámetro, un carácter como segundo y otro carácter como tercero,
    la misma deberá reemplazar cada ocurrencia del segundo parámetro por el tercero y devolver
     la cantidad de veces que se reemplazo ese carácter en la cadena *

     3. Dada la siguiente estructura generar una función que permita ordenar un array
      de dicha estructura por tipo.
      Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear
       datos y mostrarlos desde el main. *
*/
typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;
float aplicarAumento(float precio);
int reemplazarCaracteres(char mensaje[],char caracterARemplazar, char caracterParaRemplazar);
int ordenarTipoYEfectividad(eVacuna lista[], int tam);
int main()
{
    float precio;
    float importeFinal;
    int contadorReemplazos;
    char mensaje[50];
    char caracterARemplazar;
    char caracterParaRemplazar;
    eVacuna lista[TAM] =
    {
        {2000,"Franco",'f', 80},
        {2001,"Cristian",'m',80.5},
        {2002,"Jose",'m',50},
        {2004,"Jose",'x',10.5},
        {2005,"David",'f',100},
        {2006,"Leonel",'m',50},
        {2007,"Carlos",'x',30},
        {2008,"Roberto",'x',40.5},
        {2009,"Martin",'f',100},
        {2010,"Mariano",'m',100}


    };
    printf("Ingresa el precio del producto para aplicar el 5%% de Aumento: ");
    scanf("%f",&precio);
    if(precio > 0 )
    {
        importeFinal = aplicarAumento(precio);
        printf("El importe final es : %.2f\n",importeFinal);
    }
    else
    {
        printf("El numero no es valido \n");
    }
    system("Pause");


    printf("Ingres Palabra: ");
    fflush(stdin);
    gets(mensaje);
    printf("Ingresa caracter a reemplazar : ");
    fflush(stdin);
    scanf("%c",&caracterARemplazar);
    printf("Ingresa caracter para reemplazar al caracter ingresado anteriormente : ");
    fflush(stdin);
    scanf("%c",&caracterParaRemplazar);
    contadorReemplazos = reemplazarCaracteres(mensaje,caracterARemplazar, caracterParaRemplazar);
    printf("En el mensaje %s : se remplazo %d veces el caracter %c  por el caracter %c\n",mensaje,contadorReemplazos,caracterARemplazar,caracterParaRemplazar);
    system("Pause");

    printf("\n*********************************LISTA SIN ORDENAR******************************************\n");
    printf("ID      NOMBRE          TIPO           EFECTIVIDAD       \n");
    printf("\n******************************************************************************************\n");
    for(int i = 0; i < TAM; i++)
    {
        printf("%d       %-5s        %-8c        %.2f\n",
           lista[i].id,
           lista[i].nombre,
           lista[i].tipo,
           lista[i].efectividad

           );
    }

    printf("\n*********************************LISTA ORDENADA ******************************************\n");
    printf("ID      NOMBRE          TIPO           EFECTIVIDAD       \n");
    printf("\n******************************************************************************************\n");
    if(!ordenarTipoYEfectividad(lista,TAM))
    {
        printf("Error \n");
    }

for(int i = 0; i < TAM; i++)
    {
        printf("%d       %-5s        %-8c        %.2f\n",
           lista[i].id,
           lista[i].nombre,
           lista[i].tipo,
           lista[i].efectividad
           );
    }

    return 0;
}
//Primer Funcion
float aplicarAumento(float precio)
{
    int aumento = AUMENTO;
    float aumentoCalculado;
    float importeFinal;

    aumentoCalculado  = precio * aumento / 100;
    importeFinal = precio + aumentoCalculado;

    return importeFinal;
}
//Segunda Funcion
int reemplazarCaracteres(char mensaje[],char caracterARemplazar, char caracterParaRemplazar)
{
    int contador = 0;
    int i = 0;
    caracterARemplazar = tolower(caracterARemplazar);
    strlwr(mensaje);
    while(mensaje[i] != '\0')
    {
        if(mensaje[i] == caracterARemplazar)
        {
            mensaje[i]  = caracterParaRemplazar;
            contador++;
        }
        i++;
    }
    return contador;
}
//Tercera funcion
int ordenarTipoYEfectividad(eVacuna lista[], int tam)
{
    int todoOk = 0;
    eVacuna auxVacuna;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam - 1 ; i++ )
        {
            for(int j = i + 1;  j < tam ; j++)
            {
                if(lista[i].tipo > lista[j].tipo ||
                        (lista[i].tipo == lista[j].tipo && lista[i].efectividad > lista[j].efectividad))
                {
                    auxVacuna = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxVacuna;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
