#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

float G = 10.0;
float M = 1000;
float h = 0.001;
int n_puntos = (int) 1.01/h;
float x0_1 = 200;
float v0_1 = 50;

float f_prima(float x)
{ 
    float v = -1.0*G*M/(x*x);
    return v;
}
float f_prima2(float v)
{
   return v;
}

void *sol(float *x, float *v, float *t, float x0, float v0)
{
    // Condiciones iniciales
    t[0] = 0;
    x[0] = x0;
    v[0] = v0;
   
    // Se obtiene el siguiente valor de x,v a partir del anterior
    t[1] = t[0] + h;
    x[1] = x[0] + h*f_prima(x[0]);
    v[1] = v[0] + h*f_prima2(v[0]);
    
    for(int i=2;i<n_puntos;i++)
    {
        t[i] = t[i-2] + h;
        v[i] = v[i-2] + 2 * h * f_prima(x[i-1]);
        x[i] = x[i-2] + 2 * h * f_prima2(v[i-1]);
    }
}


int main()
{
    

    // Se crean arreglos de ceros para t,x,v
    float *t = (float*)malloc(n_puntos*sizeof(float)); 
    for (int i=0; i<n_puntos; i++)
        t[i] = 0;
    float *x = (float*)malloc(n_puntos*sizeof(float)); 
    for (int i=0; i<n_puntos; i++)
        x[i] = 0;
    float *v = (float*)malloc(n_puntos*sizeof(float)); 
    for (int i=0; i<n_puntos; i++)
        v[i] = 0;

    sol(x, v, t, x0_1, v0_1);
    
    
    for(int i=0; i<n_puntos; i++) 
    {
        printf("%f %f %f \n", t[i], x[i], v[i]);
    }

    
    return 0;
}

