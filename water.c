#include<stdio.h>
void water(int arr[],int n)
{
    int i,k=0,sum,min=0,level=0,m,j,flag=0,p;

    while(arr[k]==0)
    {
        k=k+1;
    }

    for(i=k;i<n;i++)
    {

            min=arr[i+1];
            j=i+1;
            while(j<n)
            {
                if(arr[j]>=arr[i])
                {
                    min=arr[i];
                    flag=1;
                    break;
                }
                else if(arr[j]>=min)
                {
                    flag=0;
                    min=arr[j];
                }


                j=j+1;

            }

            if(flag==0)
            {

                for(j=j-1;j>i;j--)
                {
                    min=arr[j-1];
                    p=j-1;
                    while(p>=i)
                    {
                        if(arr[p]>=arr[j])
                        {
                            min=arr[j];
                            break;
                        }
                        else if(arr[p]>=min)
                        {
                            min=arr[p];
                        }
                        p=p-1;
                    }
                    for(m=j-1;m>p;m--)
                    {

                        level=level+(min-arr[m]);
                        //printf("level 1:%d\n",level);
                    }
                    j=p+1;
                }

               break;
            }
            for(m=i+1;m<j;m++)
            {

                level=level+(min-arr[m]);
                //printf("level 0:%d\n",level);
            }
            i=j-1;

    }
    printf("Water level trapped is:%d ",level);
}
void main()
{
    int arr[20],size,i;
    printf("Enter size: ");
    scanf("%d",&size);
    printf("Enter array: ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    water(arr,size);
}
