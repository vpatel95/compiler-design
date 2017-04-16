 #include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
struct current{int first,last;}stat[15];
int l,j,change,n=0,i=0,state=1,x,y,start,final;
char store,*input1,input[15];
clrscr();
printf("\n\n****ENTER THE REGULAR EXPRESSION****\n\n");
scanf("%s",input1);/*ex inputs:1.(a*) 2.(a|b) 3.(a.b) 4.((a|b).(a*))*/
for(i=0;i<10;i++)
input[i]=NULL;
l=strlen(input1);
a:
for(i=0;input1[i]!=')';i++);
for(j=i;input1[j]!='(';j--);
for(x=j+1;x<i;x++)
if(isalpha(input1[x]))
input[n++]=input1[x];
else if(input1[x]!='0')
store=input1[x];
input[n++]=store;
for(x=j;x<=i;x++)
input1[x]='0';
if(input1[0]!='0')
goto a;
printf("\n\n\tFROM\tTO\tINPUT\n\n");
i=0;
while(input[i]!='\0')
{
if(isalpha(input[i]))
{
stat[i].first=state++;
stat[i].last=state++;
printf("\n\t%d\t%d\t%c",stat[i].first,stat[i].last,input[i]);
}
else
{
change=0;
switch(input[i])
{
case'|':
stat[i].first=state++;
stat[i].last=state++;
x=i-2;
y=i-1;
if(!isalpha(input[y]))
{
b:
switch(input[y])
{
case'*':if(!isalpha(input[y-1]))
{
y=y-1;
goto b;
}
else
x=y-2;
break;
case'|':x=y-3;
break;
case '.':x=y-3;break;
}
change=1;
}
if(!isalpha(input[y]&&change==0))
c:switch(input[x])
{
case '*':
if(!isalpha(input[x-1]))
{x=x-1;goto c;
}
else x=x-2;
break;
case'|':x=x-2;
break;
case '.':x=x-3;
break;
}
printf("\n\t%d\t%d\tE",stat[i].first,stat[x].first);
printf("\n\t%d\t%d\tE",stat[x].last,stat[i].last);
printf("\n\t%d\t%d\tE",stat[i].first,stat[i-1].first);
printf("\n\t%d\t%d\tE",stat[i-1].last,stat[i].last);
start=stat[i].first;
final=stat[i].last;
break;
case'.':
x=i-2;
y=i-1;
if(!isalpha(input[y]))
{
d:
switch(input[y])
{
case'*':if(!isalpha(input[y-1]))
{
y=y-1;
goto d;
}
else
x=y-2;
break;
case'|':x=y-3;
break;
case '.':x=y-3;
break;
}
change=1;
}
if(!isalpha(input[y]&&change==0))
e:switch(input[x])
{
case'*':
if(!isalpha(input[x-1]))
{
x=x-1;
goto e;
}
else x=x-2;
break;
case'|':x=x-3;
break;
case'.':x=x-3;
break;
}
stat[i].last=stat[y].last;
stat[i].first=stat[x].first;
printf("\n\t%d\t%d\tE",stat[x].last,stat[i-1].first);
start=stat[x].first;
final=stat[i-1].last;
break;
case'*':
stat[i].first=state++;
stat[i].last=state++;
printf("\n\t%d\t%d\tE",stat[i].first,stat[i-1].first);
printf("\n\t%d\t%d\tE",stat[i].first,stat[i].last);
printf("\n\t%d\t%d\tE",stat[i-1].last,stat[i-1].first);
printf("\n\t%d\t%d\tE",stat[i-1].last,stat[i].last);
start=stat[i].first;
final=stat[i].last;
break;
}}
i++;
}
printf("\n the starting state is %d",start);
printf("\n the final state is %d",final);
getch();
}