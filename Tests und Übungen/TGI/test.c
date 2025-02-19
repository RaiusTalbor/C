//Test

#include <stdio.h>
#include <math.h>

int main(void)
{	
	char text1[25], text2[25];			//Text Variable
	char *p_t1= text1, *p_t2=text2;	//zeiger
	
	printf("Wort eingeben: ");
	scanf("%s", text1);
	
	while(*p_t2++=*p_t1)
		;				
	//Kopie der Texte
	
	printf("%s", text);
	
	return 0;
}
