#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


main()
{
    char b[16]={'1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0'};
    char c[5];
    int i=0;
    printf("String B : %s\n",b);
    Binary16ToChar(b,c);
    printf("int: %s",c);

}

void Binary16ToChar(char *charInput, char *charOutput)
{
	int i,aux=0,n=0;
	if(charInput[0]=='0')
	{
		strtol(charInput,charOutput,10);
	}else // tratamento para numeros negativo
	{
		i=15;
		aux=0;
		while(aux==0 && i!=0)
		{
			if(charInput[i]=='0')
			{
				charInput[i]='1';
			}else if(charInput[i]=='1')
			{
				charInput[i]='0';
				aux=1;
			}
			i--;
		}
		printf("String B : %s\n",charInput);
		for(i=0;i<16;i++)
		{
			if(charInput[i]=='0')
			{
				charInput[i]='1';
			}else if(charInput[i]=='1')
			{
				charInput[i]='0';
			}
		}
		aux=0;
		printf("String B : %s\n",charInput);
		for(i=15;i>=0;i--)
		{
            if(charInput[i]=='0')
            {
                n+=0*(2^aux);
            }else if(charInput[i]=='1')     // passa para inteiro;
            {
                n+=pow(2,aux);
            }
			aux++;
		}
		n=n*(-1);           //inverte o numero inteiro para negativo novamente

		itoa(n,charOutput,10); // converte o inteiro negativo em string
	}
}
