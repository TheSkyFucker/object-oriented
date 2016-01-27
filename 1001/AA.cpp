#include <cstdio>
int  a,b,l,ans[10];
int  main( )
{
	for (scanf("%d%d",&a,&b); a+b<0; printf("-")) a=-a,b=-b;
	for (a+=b,l=a==0; a; a/=1000) ans[++l]=a%1000;
	for (printf("%d",ans[l]); --l; ) printf(",%03d",ans[l]);
}
