#include <iostream>
#include <omp.h>

int a[10000];
int b[6];


/*
 * Un número es un número perfecto si es igual a la suma de sus divisores propios, es decir, la suma de sus divisores positivos excluyendo
 * el propio número. Escribe una función encontrar los numeros puros del x al y.
 *
 * Ejemplo
 * 15
 * Los divisores de 15 son 1, 3 y 5. La suma es 1+3+5=9 que es diferente de 15
 * por lo que 15 no es un numero puro
 *
 * 6
 * Los divisores de 6 son 1, 2 y 3. La suma de 1+2+3=6 que es igual a 6
 * por lo que 6 es un numero puro
 *
 * n = 10;
 */
void burbuja(){
    b[0]=3;
    b[1]=9;
    b[2]=2;
    b[3]=1;
    b[4]=8;
    b[5]=6;
    for(int i=0;i<6-1;i++){
        for(int j=0;j<6-1-i;j++){
            int aux=0;
            if(b[j]>b[j+1]){
                aux=b[j];
                b[j]=b[j+1];
                b[j+1]=aux;
            }
        }
    }
    for (int i=0;i<6;i++) {
        printf("arreglo ordenado %d\n",b[i]);

    }
}
void serialPuro(int x, int y){
    int numPerfecto[y];
    int i=0;
    int numero=x;
    for (int l=x;l<y;l++) {
        int suma=0;
        for(int j=1;j<numero;j++){
            if(numero%j==0){
                suma=suma+j;
            }
        }
        if(suma==numero){
            numPerfecto[i]=numero;
            i++;
        }
        numero++;
    }
    for (int k = 0; k < i; ++k) {
        printf("los numeros son: %d \n",numPerfecto[k] );

    }
}

void ompPuro(){
    int numero_hilos=0;
    #pragma omp parallel
    {
        #pragma opm master//le pone en hilo cero
        numero_hilos = omp_get_num_threads();

    }
    std::printf("num hilos: %d \n", numero_hilos);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        //printf("i %d \n",thread_id);
        for(int i=thread_id;i<10000;i+=numero_hilos){
           //int numero=a[i];
           // printf("i %d + %d\n",i,numero_hilos);
                int suma=0;
                for(int j=1;j<i;j++){
                    if(i%j==0){

                        suma=suma+j;
                    }
                }
                if(suma==i){
                    printf("es numero puro %d\n",i);
                }
            }
    }

}




int main() {
    std::cout << "Hello, World!" << std::endl;
    for(int i=1;i<=10000;i++){
        a[i]=i;
    }


    serialPuro(1,10000);
    ompPuro();
   // burbuja();
    return 0;
}
