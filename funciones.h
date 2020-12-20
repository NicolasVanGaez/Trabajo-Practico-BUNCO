#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int AnalisisDados(int v[], int tam, int Ronda,int Puntosjugada);

int calcularBunco(int v[], int tam, int Ronda);

int calcularRepetidos(int v[],int tam);

int calcularSumadivisible5(int v[],int tam);

int calcularEscalera(int v[],int tam);

int calcularCoincidenciaconRonda(int v[], int tam, int Ronda);

void mostrarVector(int v[], int tam);

void cargarDados(int v[], int tam);

int contarNumerosRepetidos(int v[], int tam , int numero);///cuenta la cantidad de veces que se repite un //número en el vector

int maximoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el máximo en el vector

int minimoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el mínimo en el vector

void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

int ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector

int sumarVector(int v[], int tam ); /// suma los valores contenidos en el vector

void copiarVector(int v[], int v2[],int tam ); ///copia el vector v en v2

bool compararVectores(int v[], int v2[],int tam );// compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false

float calcularPromedio(int v[], int tam);


/// Desarrollo de funciones / Definiciones
int posicionNumeroEnVector(int v[],int tam, int numero){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==numero) return i;
        }
    return -1;
}

int minimoVector(int v[], int tam){
    int i, posMin=0;
    for(i=1;i<tam;i++){
        if(v[i]<v[posMin]) {
                posMin=i;
        }
    }
    return posMin;
}

int ordenarVector(int v[], int tam ){
    int i,j, posmin, aux,cant=0;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
    if(v[0] != v[1]){
    if(v[0] == v[1]-1)cant++;
        }
    if(v[1] != v[2]){
    if(v[1] == v[2]-1)cant++;
        }
    return cant;
}

int maximoVector(int puntos[], int tam){
    int i, pos=0;
    for(i=1;i<tam;i++){
        if(puntos[i]>puntos[pos]) {
                pos=i;
        }
    }
    return pos;
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\n";
    }
    cout<<endl;
}

int contarNumerosRepetidos(int v[], int tam, int Ronda){
    int i, bunco=0;
    for(i=0;i<tam;i++){
        if(v[i]==Ronda) bunco++;
        }
    return bunco;
}

void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}

int sumarVector(int v[], int tam){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    if(suma%5==0)return 3;
    return 0;
}

void copiarVector(int v[], int v2[],int tam ){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam ){
   int i;
    for(i=0;i<tam;i++){
        if(v2[i]!=v[i]) return false;
    }
    return true;
}

void cargarDados(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"INGRESE VALOR DEL DADO: "<<endl;
        cin>>v[i];
    }
}

float calcularPromedio(int v[], int tam){
    int suma;
    float prom;
    suma=sumarVector(v,tam);
    prom=(float)suma/tam;
    return prom;
}

int AnalisisDados(int v[], int tam, int Ronda,int Puntosjugada){
   int puntos[5]={0}, pos;

    puntos[0]=calcularBunco(v,tam,Ronda);
    puntos[1]=calcularRepetidos(v,tam);
    puntos[2]=calcularSumadivisible5(v,tam);
    puntos[3]=calcularEscalera(v,tam);
    puntos[4]=calcularCoincidenciaconRonda(v,tam,Ronda);
    pos=maximoVector(puntos,5);
    Puntosjugada=puntos[pos];
    return Puntosjugada;
}

int calcularBunco(int v[], int tam, int Ronda){
 int bunco=contarNumerosRepetidos(v,tam,Ronda);
 if(bunco==3)return 21;
 return 0;
}

int calcularRepetidos(int v[],int tam){
   if(v[0]==v[1] && v[0]==v[2]) return 5;
   return 0;
}

int calcularSumadivisible5(int v[],int tam){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    if(suma%5==0)return 3;
    return 0;
 }

int calcularEscalera(int v[],int tam){
  int cant=ordenarVector(v,tam);
  if(cant==2)return 2;
  return 0;
 }

 int calcularCoincidenciaconRonda(int v[],int tam,int Ronda){
     int i,cant=0;
     for(i=0;i<tam;i++){
     if(v[i]==Ronda)cant++;
 }
 if(cant==1)return 1;
 if(cant==2)return 2;
 if(cant==3)return 3;
 return 0;
 }





#endif // FUNCIONES_H_INCLUDED

