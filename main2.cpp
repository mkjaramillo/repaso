#include <iostream>
#include <omp.h>


/*
 * Conjetura de GoldBach
 * Todos los numeros pares mayores que 2 pueden ser escritos como la suma de dos numeros primos
 * Ejemplo:
 * 4 = 2+2
 * 12 = 7 + 5
 * Escribir una funcion que imprima la suma de dos numeros primos de los primeros 100 numeros pares
 */
bool  esPrimo(int numero){

    bool primo=true;
    for(int i=2;i<(numero/2+1);i++){
        if(numero%i==0){
           primo=false;
        }
    }
    //printf("%d, %d\n",primo,numero);

    return primo;
}
int a[100];
void conjeturGoldBach(){
  for(int i=0; i<100;i++){
      a[i]=i*2;
  }
  for(int i=0;i<100;i++){
      int numero= a[i];
      bool end=false;
      for(int l=2;l<numero;l++){
          bool isPrimo= esPrimo(l);
          if(isPrimo==true){
              for(int j=l;j<numero;j++){
                  bool isPrimo2= esPrimo(j);
                  int suma=0;
                  if(isPrimo2==true){
                      suma=l+j;
                      if(suma==numero){
                          printf("numero es : %d con suma %d +%d \n",numero,l,j);
                          end=true;
                          break;
                      }
                  }
              }
          }
          if(end){
              break;
          }

      }

  }

}
void ompConjetura() {
    int numero_hilos = 8;
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        for (int i = thread_id; i < 100; i += 8) {
            int numero = a[i];
            bool end = false;
            for (int l = 2; l < numero; l++) {
                bool isPrimo = esPrimo(l);
                if (isPrimo == true) {
                    for (int j = l; j < numero; j++) {
                        bool isPrimo2 = esPrimo(j);
                        int suma = 0;
                        if (isPrimo2 == true) {
                            suma = l + j;
                            if (suma == numero) {
                                printf("numero es : %d con suma %d +%d \n", numero, l, j);
                                end = true;
                                break;
                            }
                        }
                    }
                }
                if (end) {
                    break;
                }
            }
        }
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
   //conjeturGoldBach();
    for(int i=0; i<100;i++){
        a[i]=i*2;
    }
   //ompConjetura();

    //serialPuro(1,100);
    //ompPuro();
    char* arreglo = "Hola";

    std::printf(arreglo);


    return 0;
}