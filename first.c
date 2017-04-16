#include <stdio.h>
#include <ctype.h>


void First(char[],char );
void addToResult(char[],char );
int numofprod;
char prodset[10][10];

int main(){
	int i;
	char choice;
	char c;
	char result[20];
	printf("How many productions: ");
	scanf(" %d",&numofprod);
	printf("Enter all the productions:\n");
	for(i=0;i<numofprod;i++)
	{
		scanf(" %s",prodset[i]);
	}
	
	do{
		printf("Find the First of: ");
		scanf(" %c",&c);
		First(result,c);
		printf("\n First(%c) = { ",c);
		for(i=0;result[i] != '\0'; i++)
			printf(" %c",result[i]);
		printf("}\n");
		printf("Press y to continue: ");
		scanf(" %c",&choice);
	}while(choice == 'y' || choice == 'Y');
}

void First(char* Result, char c)
{
	int i,j,k;
	char subresult[20];
	int foundepsilon;
	subresult[0] = '\0';
	Result [0] = '\0';
	
	if(!isupper(c))
	{
		addToResult(Result,c);
		return;
	}
	
	for(i=0;i<numofprod;i++)
	{
		if(prodset[i][0] == c)
		{
			if(prodset[i][2] == '$')
				addToResult(Result,'$');
			
			else
			{
				j=2;
				while(prodset[i][j] != '\0')
				{
					foundepsilon = 0;
					First(subresult,prodset[i][j]);
					
					for(k=0;subresult[k]!='\0';k++)
						addToResult(Result,subresult[k]);
						
					for(k=0; subresult[k]!='\0' ; k++)
					{
						if(subresult[k] == '$'){
							foundepsilon = 1;
							break;
						}
					}
					
					if(!foundepsilon)
						break;
					
					j++;
				}
			}
		}
	}
}

void addToResult(char* Result, char val)
{
	int k;
	for(k=0;Result[k] != '\0' ; k++)
	{
		if(Result[k] == val)
			return;
	}
	
	Result[k] = val;
	Result[k+1] = '\0';
}
