#include <stdio.h>

#define NUM_PUEBLOS 100
#define NUM_BEBIDAS 8

// Función para recoger y almacenar información
void recogerInformacion(int datos[NUM_PUEBLOS][NUM_BEBIDAS]) {
    for (int i = 0; i < NUM_PUEBLOS; i++) {
        printf("Introduce los litros consumidos para el pueblo %d:\n", i + 1);
        for (int j = 0; j < NUM_BEBIDAS; j++) {
            printf("Tipo de bebida %d: ", j);
            scanf("%d", &datos[i][j]);
        }
    }
}

// Función para determinar el tipo de bebida más consumida
int bebidaMasConsumida(int datos[NUM_PUEBLOS][NUM_BEBIDAS]) {
    int totalBebidas[NUM_BEBIDAS] = {0};

    // Sumar litros consumidos para cada tipo de bebida
    for (int i = 0; i < NUM_PUEBLOS; i++) {
        for (int j = 0; j < NUM_BEBIDAS; j++) {
            if (datos[i][j] != -1) { // Ignorar valores -1
                totalBebidas[j] += datos[i][j];
            }
        }
    }

    // Determinar el tipo de bebida más consumida
    int maxLitros = 0, tipoMasConsumido = 0;
    for (int j = 0; j < NUM_BEBIDAS; j++) {
        if (totalBebidas[j] > maxLitros) {
            maxLitros = totalBebidas[j];
            tipoMasConsumido = j;
        }
    }

    return tipoMasConsumido;
}

// Función para listar tipos de bebidas con alcohol
void listarBebidasConAlcohol(int tiposConAlcohol[], int tamano) {
    printf("Tipos de bebidas con alcohol:\n");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", tiposConAlcohol[i]);
    }
    printf("\n");
}

// Función principal
int main() {
    int datos[NUM_PUEBLOS][NUM_BEBIDAS];
    int tiposConAlcohol[] = {2, 3, 4, 5, 6, 7}; // Bebidas con alcohol
    int tamanoTiposConAlcohol = sizeof(tiposConAlcohol) / sizeof(tiposConAlcohol[0]);

    // Paso 1: Recoger y almacenar información
    recogerInformacion(datos);

    // Paso 2: Determinar el tipo de bebida más consumida
    int tipoMasConsumido = bebidaMasConsumida(datos);
    printf("El tipo de bebida más consumida es: %d\n", tipoMasConsumido);

    // Paso 3: Listar tipos de bebidas con alcohol
    listarBebidasConAlcohol(tiposConAlcohol, tamanoTiposConAlcohol);

    return 0;
}

