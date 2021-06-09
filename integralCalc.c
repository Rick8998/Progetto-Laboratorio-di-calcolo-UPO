#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float);

float seno(float x)
{
  return sin(x);
}

float coseno(float x)
{
  return cos(x);
}

float logaritmoNat(float x){
	return log(x);
}

float tanIperb(float x){
	return tanh(x);
}

int main()
{
  int correctValues = 0;
  int correctMax = 0;
  float a, b, M;
  float x, y;
  float functionArea;
  int nf=0;
  int functionType;
  unsigned int rnd;
  unsigned int seed=12345;
  int j, nmax;

  printf("Programma per la valutazione dell'area di un integrale con il metodo MonteCarlo\n");

  do{
  	printf("----------------------------------------------------");
    printf("\nQuale funzione vuoi utilizzare'?'\n");
    printf("- Seno-->Scrivi '1'\n- Coseno-->Scrivi '2'\n- Logaritmo Naturale-->Scrivi '3'\n- Tangente Iperbolica-->Scrivi 4\n");
    printf("Inserisci il numero corrispondente alla funzione: ");
    scanf("%d", &functionType);
    printf("----------------------------------------------------\n");
  }while(functionType != 1 && functionType != 2 && functionType != 3 && functionType != 4);

  printf("\n");
  switch(functionType){
      case 1:
      	printf("HAI SCELTO LA FUNZIONE SENO\n");
	      printf("ALCUNE INFORMAZIONI:\n");
	      printf("-NB: Usare l'intervallo in cui la funzione è positiva ([0 - 3,14159265358])\n");
	      printf("-Il valore massimo del seno è 1, e lo assume in 1.5\n");
	      printf("-Il seno è positivo nell'intervallo 0 e 3,14159265358\n");
	      printf("----------------------------------------------------\n");
      	  break;
      case 2:
        printf("HAI SCELTO LA FUNZIONE COSENO\n");
	      printf("ALCUNE INFORMAZIONI:\n");
	      printf("-NB: Usare l'intervallo in cui la funzione è positiva ([-1.57079632679 - 1.57079632679])\n");
	      printf("-Il valore massimo del coseno è 1, e lo assume in 0\n");
	      printf("-Il coseno è positivo nell'intervallo -1.57079632679 e 1.57079632679\n");
	      printf("----------------------------------------------------\n");
      	  break;
      case 3:
      	  printf("HAI SCELTO LA FUNZIONE LOGARITMO NATURALE\n");
      	  printf("ALCUNE INFORMAZIONI:\n");
      	  printf("-La funzione ln(x) è positiva per valori > 1\n");
      	  printf("-ln(10) vale 2.30258509299\n");
      	  printf("----------------------------------------------------\n");
      	  break;
      case 4:
      	  printf("HAI SCELTO LA FUNZIONE TANGENTE IPERBOLICA\n");
      	  printf("ALCUNE INFORMAZIONI:\n");
      	  printf("-La funzione TANH è positiva per valori > 0\n");
      	  printf("-Il massimo assunto dalla funzione tanh è 1\n");
      	  printf("-TANH(10) vale 0.99999999587 \n");
      	  printf("----------------------------------------------------\n");
      	  break;
    }

  do{
    printf("\nInserisci il numero di punti da generare (Consiglio:per una maggiore accuratezza metterne più di 1000): ");
    scanf("%d",&nmax);
  }while(nmax < 0);
  

  do{
  	printf("\nInserisci l'intervallo [a,b] di integrazione <Numero1 Numero2>: ");
    scanf("%f %f",&a,&b);
  	switch(functionType){
  		case 1:
	  		if(a >= 0 && b <= 3.14159265358 && a <= b) correctValues = 1;
	  		else printf("Intervallo non corretto\n");
	  		break;
  		case 2:
	  		if (a >= -1.57079632679 && b <= 1.57079632679 && a <= b) correctValues = 1;
	  		else printf("Intervallo non corretto\n");
	  		break;
  		case 3:
	  		if(a >= 1 && b <= 10 && a <= b) correctValues = 1;
	  		else printf("Intervallo non corretto\n");
	  		break;
	  		
  		case 4:
	  		if(a >= 0 && b <= 10 && a <= b) correctValues = 1;
	  		else printf("Intervallo non corretto\n");
	  		break;
  	}
    
  }while(correctValues != 1);

  do{
  printf("\nInserisci il massimo M della funzione: ");
  scanf("%f",&M);
  switch(functionType){
  		case 1:
	  		if(M >= 0 && M <= 1.1) correctMax = 1;
	  		else printf("Il massimo valore assunto dalla funzione quando è positiva è 1 (il minimo è 0)\n");
	  		break;
  		case 2:
	  		if(M >= 0 && M <= 1.1) correctMax = 1;
	  		else printf("Il massimo valore assunto dalla funzione quando è positiva è 1 (il minimo è 0)\n");
	  		break;
	  	case 3:
	  		if(M >= 0 && M <=2.30258509299) correctMax = 1;
	  		else printf("Il massimo valore assunto dalla funzione, in 10, quando è positiva è 2.30258509299 (il minimo, in 1, è 0)\n");
	  		break;	  		
  		case 4:
	  		if(M >= 0 && M <= 1.1) correctMax = 1;
	  		else printf("Il massimo valore assunto dalla funzione quando è positiva è 1 (il minimo è 0)\n");
	  		break;
  	}
  }while(correctMax != 1);

  srand(seed);
  for (j=0; j<nmax; j++) {
    rnd = rand();
    x = a + ((double)rnd/(RAND_MAX))*(b - a);
    rnd = rand();
    y = ((double)rnd/(RAND_MAX))*M;

    switch(functionType){
      case 1:
      if ( y <= seno(x) ) {
        nf++;
      }
      break;
      case 2:
      if ( y <= coseno(x) ) {
        nf++;
      }
      break;
      case 3:
      if ( y <= logaritmoNat(x) ){
        nf++;
      }
      break;
      case 4:
      if ( y <= tanIperb(x) ) {
        nf++;
      }
      break;
    }
    //if ( y <= f(x) ) nf++;
  }

  functionArea = (M*(b-a)*nf)/nmax;
  printf("\n**************************************************");
  printf("\nIl valore dell'area con %d punti, nell'intervallo [%f, %f], vale: %f\n",nmax,a,b,functionArea);
  printf("**************************************************\n");

  return 0;
}