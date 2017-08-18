#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t,i;
    int orgX,orgY,x,y;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d %d",&orgX,&orgY);
        for(i=0;i<t;i++)
        {
            scanf("%d %d",&x,&y);
            if(x==orgX || y==orgY)  printf("%s","divisa\n");
            else if(x>orgX && y>orgY)   printf("%s","NE\n");
            else if(x>orgX && y<orgY)   printf("%s","SE\n");
            else if(x<orgX && y>orgY)   printf("%s","NO\n");
            else    printf("%s","SO\n");
        }
        scanf("%d",&t);
    }
    return 0;
}
