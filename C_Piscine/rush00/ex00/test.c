#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    int i = 0;
    long long int x=0;
    long long int y=0;
    
    if (argc != 3)
        return 0;
    while (i<=10)
    {
		if (argv[1][i]=='\0')
			break;
		if (argv[1][i] > '9' || argv[1][i] < '0')
			return 0; //-음수 처리, .실수 처리, 
        if (i == 10) //21억 == 10자리
            return 0; //11자리 이상 즉 100억 이상인 오버플로우 처리
        x *= 10;
        x += argv[1][i]-'0';
        i++;
    }
    i = 0;
    while (i<=10)
    {
		if (argv[2][i]=='\0')
			break;
		if (argv[2][i] > '9' || argv[2][i] < '0')
			return 0;
        if (i == 10)
            return 0;
        y *= 10;
        y += argv[2][i]-'0';
        i++;
    }
    if (x > 2147483647)
        return 0;
    if (y > 2147483647)
        return 0;
    printf("%lld, %lld\n", x, y);
    //rush((int)x, (int)y);
}
