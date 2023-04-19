#include <stdio.h>
#include <math.h>
double f(double x,double y);
void writeExcel(double*,double*);

int main()
{
	int i,m,o;
	int b=0;
	double n,p; /*n表示将区间分成的份数*/
	double y0=2.71828;
	double Xn,Yn,Xn1,Yn1,Tn1;
	double h=0.001;
	double K1,K2,K3,K4;
	double arr1[100000];  //这两个数组用于后面将数据导入excel
	double arr2[100000];
/*	
	printf("Whether c is int or not?Yes input 1,no input 0.\n");
	scanf("%d",&m);
	
	if(m==1)
	{
	printf("Please enter the value of 'c':");
	scanf("%lf",&c);
	}
	else
	{
	printf("Then,please enter the value of 'c':");
    scanf("%d %lf", &o, &p);
    c=pow(o,p);
    printf("c=%.10lf\n",c);
	}
	
	printf("Please enter the value of 'y0':");
	scanf("%lf",&y0);
*/
	double c=pow(25,2.71828);
	n=(c-b)/h;
	Xn=b;
	Yn=y0;
/*欧拉法
	for(i=1;i<=n;i++)
	{
		Xn1=Xn+h;
		Yn1=Yn+h*f(Xn,Yn);
		printf("X%d=%lf,Y%d=%.10lf\n",i,Xn1,i,Yn1);
		arr1[i-1]=Xn1;
		arr2[i-1]=Yn1;
		Tn1=Yn-Yn1;
		if(Tn1<0.001*h)
		{
			printf("The final convergence state of the equation is:%.10lf\n",Yn1);
			break;
		}
		else
		{
		Xn=Xn1;
		Yn=Yn1;
		}
	}
*/

/*** 梯形法
	for(i=1;i<=n;i++)
	{
		Xn1=Xn+h;
		Yn1=Yn+h/2*(f(Xn,Yn)+f(Xn1,Yn1));
		printf("X%d=%lf,Y%d=%lf\n",i,Xn1,i,Yn1);
		arr1[i-1]=Xn1;
		arr2[i-1]=Yn1;
		Tn1=fabs(Yn1-Yn);
		if(Tn1<0.001*h)
		{
			printf("The final convergence state of the equation is:%.10lf\n",Yn1);
			break;
		}
		else
		{
		Xn=Xn1;
		Yn=Yn1;
		}
	}
*/

/*** 改进欧拉法
    for(i=1;i<=n;i++)
	{
		Xn1=Xn+h;
		Yn1=Yn+h/2*(f(Xn,Yn)+f(Xn1,Yn+h*f(Xn,Yn)));
		printf("X%d=%lf,Y%d=%lf\n",i,Xn1,i,Yn1);
		arr1[i-1]=Xn1;
		arr2[i-1]=Yn1;
		Tn1=fabs(Yn1-Yn);
		if(Tn1<0.001*h)
		{
			printf("The final convergence state of the equation is:%.10lf\n",Yn1);
			break;
		}
		else
		{
		Xn=Xn1;
		Yn=Yn1;
		}
	}
	
*/

/*四阶R-K法 */
	for(i=1;i<n;i++)
	{	
		Xn1=Xn+h;
		K1=f(Xn,Yn);
		K2=f(Xn+h/2,Yn+h*(K1)/2);
		K3=f(Xn+h/2,Yn+h*(K2)/2);
		K4=f(Xn+h,Yn+h*(K3));
		Yn1=Yn+h/6*(K1+2*K2+2*K3+K4);
		
		printf("X%d=%.10lf,Y%d=%.10lf\n",i,Xn1,i,Yn1);
		arr1[i-1]=Xn1;
		arr2[i-1]=Yn1;
		Tn1=fabs(Yn1-Yn);
		if(Tn1<0.001*h)
		{
			printf("The final convergence state of the equation is:%.10lf\n",Yn1);
			break;
		}
		else
		{
		Xn=Xn1;
		Yn=Yn1;
		}		
	}
	
	writeExcel(arr1,arr2);	
	return 0;
}

//微分方程的解
double f(double x,double y)
{
	return -y;
}

//将数据导入excel
void writeExcel(double *arr1,double*arr2)
{
	int i ;
	
	
	
	FILE *fp ;
	fp = fopen("C:\\Users\\lenovo\\Desktop\\新建 XLS 工作表.xls","w+") ;
	for (i=0 ;i<10000; i++)
		fprintf(fp,"%f\t%f\n",arr1[i],arr2[i] ) ;
	fclose(fp);
	printf("It had removed the value in excel.");
}
