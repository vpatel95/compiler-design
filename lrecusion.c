#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
char a[10],b[50][100]={""},d[50][100]={""},ch;
int i,n,c[10]={0},j,k,t,n1;
printf("\nEnter the non terminals having left recursion: ");
scanf("%s",a);
n=strlen(a);
for(i=0;i<n;i++)
{
printf("\nEnter the no of productions for %c : ",a[i]);
scanf("%d",&c[i]);
}
t=0;
for(i=0;i<n;i++)
{
printf("\nEnter the right productions for %c",a[i]);
for(j=0;j<c[i];j++)
{
printf("\n%c->",a[i]);
scanf("%s",b[t]);
t++;
}
t=t+4;
}
t=0;
for(i=0;i<n;i++)
{ for(j=0;j<c[i];j++)
{ if(a[i]==b[t][0])
{
n1=strlen(b[t]);
for(k=1;k<n1;k++)
{
d[t][k-1]=b[t][k];
}
} t++;
}
t=t+4;
}
t=0;
printf("\nAfter eliminating Left Recursion: \n");
for(i=0;i<n;i++)
{ for(j=0;j<c[i];j++)
{
if(a[i]!=b[t][0])
if(islower(b[t][0]))
printf("\n%c -> %s%c'",a[i],b[t],a[i]);
t++;
}
t=t+4;
}
t=0;
for(i=0;i<n;i++)
{
for(k=0;k<c[i];k++)
{ if(a[i]==b[t][0])
printf("\n%c' -> %s%c'/%c",a[i],d[t],a[i],(char)238);
else if(isupper(b[t][0]))
printf("\n%c -> %s",a[i],b[t+k]);
t++;
}
t=t+4;
}
return 0;
}
