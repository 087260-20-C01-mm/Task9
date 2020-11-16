#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void swapLines(int i, int j, int m, float a[][m])
{
    int k ;float c;
    for(k=0;k<=m-1;k++)
        {
        c=a[i][k];
        a[i][k]=a[j][k];
        a[j][k]=c;
        }
}

int checkElement(int o,int k,int b[k]){
int i;
for(i=0;i<=k-1;i++){
    if(b[i]==o){return 1;}
}
return 0;
}

int str(int n, int m, float a[][m]) {
int i,j,count,F,b[m],k=0;
for(j=0;j<=m-1;j++){
    count=0;
    for(i=0;i<=n-1;i++){
        if(a[i][j]!=0){
            count++; F=i;
        }

    }
    if(count==0){return 0;}
    else if(count ==1){swapLines(j,F,m,a);b[k]=j;k++;}
}

i=0;j=0;
while(i<n-1){
    if(checkElement(i,k,b)){i++;continue;}
    j=i+1;
    if(a[i][i]==0){
        F=0;
        while(j<=n-1)
        {
        if(checkElement(j,k,b)){j++;continue;}
        if(a[j][i]!=0){F=j;}
        if(a[j][j]==0 && F==j){break;}
        j++;
        }
        if(j==n){
            if(F==0){return 0;}
            else{swapLines(F,i,m,a);}
        }
        else{swapLines(i,j,m,a);}
        }

    else{
        while(j<=n-1)
        {
        if(checkElement(j,k,b)){j++;continue;}
        if(a[j][j]==0 && F==j){break;}
        j++;
        }
        if(j!=n){swapLines(j,i,m,a);}
    }
    i++;
}
return 1;
}

void tri5( int n, int m, float a[n][m])
{ int i, j;
float c;
for(i=-(n-2);i<=0;i++){

     c=a[i][-(n-1)-1];
    for(j=-(n-1)-1;j<=0;j++){
        a[i][j]-=a[-(n-1)][j]*c/a[-(n-1)][-(n-1)-1];
        }

    }
   if(n-1>1){tri5(n-1,m,a) ;}
}

void tri7( int n, int m, float a[][m])
{ int i, j;
float c;
for(i=-(n-2);i<=0;i++){
    c=a[i][-(n-1)];
    for(j=-(n-1);j<=0;j++){
        a[i][j]-=a[-(n-1)][j]*c/a[-(n-1)][-(n-1)];
        }
    }
   if(n-1>1){tri7(n-1,m,a) ;}
}

void result(int n,int m, float a[n][m],float x[n])
{
float c=0;
int i;
for(i=m-2;i>n-1;i--){c+=x[i]*a[n-1][i];}
x[n-1]=(a[n-1][m-1]-c)/a[n-1][n-1];
if(n-1!=0) result(n-1,m,a, x);
}

float def(int n, float a[n][n]){
int i;
float sum=1;
for(i=0;i<=n-1;i++){sum*=a[i][i];}
return sum;
}

void task2()
{
    int n,m,i,k=1,n0=0,m0=0;
    printf("������� ������ n � ������ m ��� \"�������\"\n");
    scanf("%d %d",&n,&m);
    int a[n][m];
    printf("\n");

while(n0<=n/2 && m0<=m/2){
        for(i=m0;i<=m-1-m0 && k<=m*n;i++)
        {

            a[n0][i]=k;
            k++;
        }

        for(i=1+n0;i<=n-1-n0 && k<=m*n;i++)
        {

            a[i][m-1-m0]=k;
            k++;
        }
        for(i=m-2-m0;i>=m0 && k<=m*n;i--)
        {

            a[n-1-n0][i]=k;
            k++;
        }
        for(i=n-2-n0;i>=1+n0 && k<=m*n;i--)
        {

            a[i][m0]=k;
            k++;
        }
        if(k>m*n){break;}
m0++;n0++;
    }

    for(i=0;i<=m*n-1;i++) {
            if((i-1)/m<i/m){printf("\n");}
            printf("%4d ",a[i/m][i%m]);}

printf("\n\n\n");
printf("������� ������ n � ������ m ��� ������ ����� �������\n");
    scanf("%d %d",&n,&m);
    printf("\n");
int j;
int b[n][m];
for(i=0;i<=n-1;i++){
for(j=0;j<=m-1;j++)
{b[i][j]=abs(i-j)+1;}
}

for(i=0;i<=n*m-1;i++){if((i-1)/m<i/m){ printf("\n"); }; printf("%d ", b[i/m][i%m]); }

}

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

void task4()
{
int n,m,i,j, k, c, A=0, B=0;


printf("������� ������ n � ������ m\n");
scanf("%d %d",&n,&m);
int a[n][m];
for(i=0;i<=n-1;i++){
    for(j=0;j<=m-1;j++){
        printf("������� a[%d][%d]\n",i,j);
        scanf("%d",&a[i][j]);
    }
}

for(i=0;i<=n*m-1;i++){if((i-1)/m<i/m){ printf("\n"); }; printf("%d ", a[i/m][i%m]); }
printf("\n\n");

for(i=0;i<m-1; i++) {
for(j=0;j<m-1-i;j++){
for(k=0;k<=n-1;k++){
A+=a[k][j];
B+=a[k][j+1];
}
if(A>B){
    for(k=0;k<=n-1;k++){
    c = a[k][j];
    a[k][j] = a[k][j+1] ;
    a[k][j+1] = c;
    }
}
A=0;B=0;}}

for(i=0;i<=n*m-1;i++){if((i-1)/m<i/m){ printf("\n"); }; printf("%d ", a[i/m][i%m]); }
}

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

void task5()
{
int n,m,i,j, k, c;
printf("������� ���������� �����������\n");
scanf("%d",&n);
m=n+1;
float a[n][m];
for(i=0;i<=n-1;i++){
    for(j=0;j<=m-1;j++){
        printf("������� a[%d][%d]\n",i,j);
        scanf("%f",&a[i][j]);
    }
}
printf("�������:\n");
  for(i=0;i<=m*n-1;i++) {if((i-1)/m<i/m){printf("\n");}printf("%g ",a[i/m][i%m]);}
  printf("\n\n");
if(str(n, m, a)==0){ printf("ERROR");return 100; }
printf("������� � ����:\n");
  for(i=0;i<=m*n-1;i++) {if((i-1)/m<i/m){printf("\n");}printf("%g ",a[i/m][i%m]);}
printf("\n\n");
float x[n];
tri5(n,m, &a[n-1][m-1]);
printf("�������� � ������������ ����:\n");
  for(i=0;i<=m*n-1;i++) {if((i-1)/m<i/m){printf("\n");}printf("%g ",a[i/m][i%m]);}
printf("\n\n");
result(n, m, a, x);
printf("�����:\n");
for(i=0;i<=n-1;i++){ printf("x%d = %g | ",i+1 ,x[i]); }
}

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW

void task7()
{
int i,j,n,m;
    printf("������� ����������� ������� n\n");
    scanf("%d",&n);
    m=n;
    float a[n][m];
    for(i=0;i<=n-1;i++){
        for(j=0;j<=m-1;j++){
            printf("������� a[%d][%d]\n",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    printf("�������:\n");
    for(i=0;i<=m*n-1;i++) {if((i-1)/m<i/m){printf("\n");}printf("%g ",a[i/m][i%m]);}
    printf("\n\n");
    if(str(n, m, a)==0){ printf("ERROR");return 100; }
    printf("������� � ����:\n");
    for(i=0;i<=m*n-1;i++) {if((i-1)/m<i/m){printf("\n");}printf("%g ",a[i/m][i%m]);}
    printf("\n\n");
    tri7(n,m, &a[n-1][m-1]);
    printf("�������� � ������������ ����:\n");
    for(i=0;i<=n*n-1;i++){if((i-1)/n<i/n){ printf("\n"); };printf("%g ", a[i/n][i%n]);}
    printf("\n\n\n������������ ����� %g", def(n, a) );
}

int main()
{
    int i;
    setlocale(LC_ALL,"Rus");
    printf("Task9\n\n������� 2, 4, 5 ��� 7, ����� ������� ������� 2, 4, 5 ��� 7 ��������������.\n");
    scanf("%d",&i);
    switch(i){
    case 2: printf("\n\n������� 2\n\n"); task2();break;
    case 4: printf("\n\n������� 4 - ���������� �� ����� � ��������\n\n");task4();break;
    case 5: printf("\n\n������� 5\n\n");task5();break;
    case 7: printf("\n\n������� 7\n\n");task7();break;
    }
    return 0;
}
