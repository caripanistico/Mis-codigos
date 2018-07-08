//https://github.com/Ps-Pencil/uva/blob/master/1047-Zones.cpp
#include<cstdio>
#include<cstring>
using namespace std;

int m,n,c;
int t[30],ca[20],inside_ca[20];
int current,Max=0,best;

int count(int a)
{
	int n = 0;
	while(a!=0)
	{
		n++;
		a-=(a&(-a));
	}
	return n;
}
int main()											//el programa busca las mejores posiciones dadas una secuencia de areas con sus respectivos pesos
{													//en el cual existen areas que son intersecciones de 2 ya existentes, que comparten cierto grado de peso
	int TC = 1;										//el objetivo es encontrar una determinada cantidad de areas, de las cuales sean las que mas peso tienen
	while(scanf("%d %d",&m,&n),m)					//abarcando la mayor cantidad de personas (que son representadas por el peso del area) posible.
	{
		Max = 0;
		memset(inside_ca,0,sizeof(inside_ca));
		for(int i=0;i<m;i++)
			scanf("%d",&t[i]);
		scanf("%d",&c);
		for(int i=0;i<c;i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=0;j<x;j++)
			{
				int p;
				scanf("%d",&p);
				inside_ca[i]|=1<<(p-1);
			}
			scanf("%d",&ca[i]);
		}
		
		for(int k=1;k<(1<<(m));k++)					//lo interesante de este codigo, es que utiliza el operador de shift sobre bits
		if(count(k)==n)								//lo anterior era solo el almacenamiento de los datos. aqui es donde los empieza a utilizar
		{
			//printf("%d\n",k);
			int sum = 0;
			for(int i=0;i<m;i++)
				if(k&(1<<i))
				{
					//printf("%d ",i);
					sum+=t[i];
				}
			for(int i=0;i<c;i++)
			{
				int tmp = inside_ca[i]&k;				//dependiendo de las areas elegidas arbitrariamente, se van calculando la cantidad de personas, quedandose con
				if(tmp>1)								//con la permutacion que posea la mayor cantidad de personas
				sum-=(count(tmp)-1)*ca[i];

			}
			//if(k==7) for(int i=0;i<c;i++)printf("%d ",area[i]);
			if(sum>Max)
			{
				Max = sum;
				best = k;
			}
		}
		printf("Case Number  %d\n",TC++);
		printf("Number of Customers: %d\n",Max);
		printf("Locations recommended:");
		for(int i=0;i<m;i++)
			if(best&(1<<i))
			printf(" %d",i+1);
		printf("\n\n");

	}
	return 0;
}