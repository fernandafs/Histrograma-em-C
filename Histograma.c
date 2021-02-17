#include <stdio.h>

#define N 20000

int main()
{

  int n = 0;
  int nmaior = 0;
  int i = 0;
  int valor = 0;
  int s = 0;
  double t[N];
  double med; 
  double min = 100;
  double max = -100;
  double soma = 0;
  double soma2 = 0;
  double media2;
  double x = 0;
  double auxiliar;
  double auxiliar2;

  while(n < N && scanf("%lf", &t[n]) > 0)
  {
    soma = soma + t[n];

    if(n == 0)
    {
      max = t[n];
      min = t[n];

    }

    if(t[n] > max)
    {
      max = t[n];
    }

    if(t[n] < min)
    {
      min = t[n];
    }

    n++;
  }

  med = soma / n;

  printf("med = %.3lf, min = %.3lf, max = %.3lf\n", med, min, max);

  for(n = 0;n < N; n++)
  {
    if(t[n] > med)
    {
      soma2 = soma2 + t[n];
      nmaior++;
    }
  }

  media2 = soma2/nmaior;

  printf("Média das temperaturas acima da média: %.3lf\n",media2);

  x = (max - min)/20;

  for (i = 0; i<20; i++)
  {
    for(n=0; n < N; n++)
    {
      auxiliar = min+i*x;
      auxiliar2 = min + (i + 1)*x;

      if(i != 19 && t[n] >= auxiliar && t[n] < auxiliar2)
      {
        valor = valor + 1;
      }

      if(i == 19 && t[n] >= auxiliar && t[n] <= auxiliar2)
      {
        valor = valor + 1;
      }
    }
    printf("aux[%d] = %d\n",i, valor);
    valor = 0;
  }

  for (i = 0; i<20; i++)
  {
    for(n=0; n < N; n++)
    {
      auxiliar = min+i*x;
      auxiliar2 = min + (i + 1)*x;

      if(i != 19 && t[n] >= auxiliar && t[n] < auxiliar2)
      {
        valor = valor + 1;
      }

      if(i == 19 && t[n] >= auxiliar && t[n] <= auxiliar2)
      {
        valor = valor + 1;
      }

    }

    if (valor/122 < 1)
    {
      printf("Temperaturas entre %06.3f e %06.3f: ",auxiliar, auxiliar2);
    }
    else
    {
      printf("Temperaturas entre %06.3f e %06.3f: ",auxiliar, auxiliar2);
    }

    for(s=0; s<valor/122; s++)
    {
      printf("*");
    }
    valor = 0;
    printf("\n");
  }

  return 0;
}
