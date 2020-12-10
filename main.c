#include <stdio.h>
#include <stdlib.h>

int main()
{

    int arr[]={1,3,5,7,9,11,13};
    int i=0;
    int check=0;
    int target=0;
    printf("Enter the target\n");
    scanf("%d",&target);
    for (i=(sizeof(arr)/sizeof(int))-1;i>=0;i--){
        if (target>arr[i]) break;
        if (target==arr[i]){
            check=1;
            printf("The target is found at %d",i+1);
            break;
        }
    }
    if (check ==0) printf("The target was not found!!!");
    return 0;
}
