// Tecnológico de Monterrey
// MNA - Cómputo en la Nube
// Tarea 1 - Solución suma de arregloas paralela
// Diego Alvarado Marino - A01795687
// 26/01/2025

#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
	//---- Crear los arreglos y asignarles valores ---- //

	std::cout << "Sumando Arreglos en Paralelo!\n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++)
	{
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;
	}
	int pedazos = chunk;

	//---- Crear un for paralelo con OpenMP ----//

#pragma omp parallel for \
	shared(a,b,c,pedazos) private(i) \
	schedule(static, pedazos)

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	//---- Imprimiendo los arreglos ----//

	std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);

}

//---- Función para imprimir los arrelos ----//

void imprimeArreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}
