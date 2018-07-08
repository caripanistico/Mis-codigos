//https://github.com/morris821028/UVa/blob/master/volume103/10340%20-%20All%20in%20All.cpp
#include<stdio.h>
#define maxL 10000000
char S[maxL], T[maxL];
int main() {
	while(scanf("%s %s", &S, &T) == 2)	{						//dado 2 strings, se debe ver si el primer string es una subsequencia del segundos string
		int i, j = 0;											//esto se puede demostrar si se encuentras los mismos caracteres (tomando en cuenta que mayusculas y minisculas si importan)
		for(i = 0; S[i]; i++) {									//en el mismo orden que aparecen en el primer string, en el segundo
			for(; T[j]; j++)
				if(S[i] == T[j])								//que es lo que basicamente este programa hace, toda el primer string y lo utiliza como plantilla comparando si sus caracteres
					{break;}									//estan en el segundo string, EN EL MISMO ORDEN, en su mismo codigo ASCII, esto es, mayusculas con mayusculas y minusculas con minusculas
			if(T[j] == '\0')	break;
			j++;
		}
		if(S[i] == '\0')	puts("Yes");						//si se encuentra, se imprime 'yes', de otra forma, se imprime 'no'
		else				puts("No");
	}
    return 0;
}
