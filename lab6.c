
#include "stdio.h"

int main()
{
	int i, j, n, a[50], frames[5], frame, k, available, count = 0,choice1,choice2,flag1=0,flag2=0,flag3,counter=0,time[10];
	int temp[10], pos, max,l;
	printf("-----Page Replacement algorithm------\n");
	printf("1. Default referenced sequence\n");
	printf("2. Manual input sequence\n");
	printf("-------------------------------------\n");
	scanf("%d",&choice1);
	switch(choice1)
	{
		case 1:
			printf("Chuoi tham chieu se la: 17520948\n");
			n=11;
			a[0]=1;
			a[1]=7;
			a[2]=5;
			a[3]=2;
			a[4]=0;
			a[5]=9;
			a[6]=4;
			a[7]=8;	
			a[8]=0;
			a[9]=0;
			a[10]=7;			
			break;
		case 2:
		{
			printf(" \nNhập số phần tử chuỗi tham chiếu: \n");
			scanf("%d",&n);
			printf(" \nNhập vào chuỗi tham chiếu: \n");
			for(i=0;i<n;i++)
			scanf("%d",&a[i]);
			break;
		}
	}
	printf("-----Page Replacement algorithm------\n");
	printf("1. FIFO algorithm\n");
	printf("2. OPT algorithm\n");
	printf("3. LRU algorithm\n");
	printf("-------------------------------------\n");
	scanf("%d",&choice2);
	switch(choice2)
	{
		case 1:
			printf("-------Page Replacement algorithm--------\n");
			printf("\nNhập vào số khung trang :");
			scanf("%d",&frame);
			for(i=0;i<frame;i++)
				frames[i]= -1; // Giả sử ban đầu các frame trống
			j=0;
			for(k=0;k<frame-1;k++)
				printf("\t");
			printf("\n");
			for(i=0;i<n;i++)
			{
				printf("\t| %d |\t",a[i]);
				available=0; // trang không có sẵn
			for(k=0;k<frame;k++)
			if(frames[k]==a[i]) // kiểm tra trang có sẵn
				available=1; // trang có sẵn
			if (available==0) // thay thế trang nếu không có sẵn
			{
				frames[j]=a[i];
				j=(j+1)%frame;
				count++;
				printf("|");
				for(k=0;k<frame;k++)
					printf("%d\t",frames[k]);
				printf("| *"); // Dấu hiệu nhận biết xảy ra lỗi trang
			}
			else
			{
				printf("|");
				for(k=0;k<frame;k++)
					printf("%d\t",frames[k]);
				printf("|");
			}
			printf("\n");
			}
			printf("Number of Page Fault: %d\n",count);
			break;
		case 2:
		 	printf("OPT algorithm\n");
		 	printf("-------Page Replacement algorithm--------\n");
			printf("\nNhập vào số khung trang :");
			scanf("%d",&frame);    
	    for(i = 0; i < frame; ++i){
	        frames[i] = -1;
	    }
	    
	    for(i = 0; i < n; ++i){
	        flag1 = flag2 = 0;
	        
	        for(j = 0; j < frame; ++j){
	            if(frames[j] == a[i]){
	                   flag1 = flag2 = 1;
	                   break;
	               }
	        }
	        
	        if(flag1 == 0){
	            for(j = 0; j < frame; ++j){
	                if(frames[j] == -1){
	                    count++;
	                    frames[j] = a[i];
	                    flag2 = 1;
	                    break;
	                }
	            }    
	        }
	        
	        if(flag2 == 0){
	         flag3 =0;
	        
	            for(j = 0; j < frame; ++j){
	             temp[j] = -1;
	            
	             for(k = i + 1; k < n; ++k){
	             if(frames[j] == a[k]){
	             temp[j] = k;
	             break;
	             }
	             }
	            }
	            
	            for(j = 0; j < frame; ++j){
	             if(temp[j] == -1){
	             pos = j;
	             flag3 = 1;
	             break;
	             }
	            }
	            
	            if(flag3 ==0){
	             max = temp[0];
	             pos = 0;
	            
	             for(j = 1; j < frame; ++j){
	             if(temp[j] > max){
	             max = temp[j];
	             pos = j;
	             }
	             }            
	            }
		frames[pos] = a[i];
		count++;
	        }
	        
	        printf("\n");
	        
	        for(j = 0; j < frame; ++j){
	            printf("%d\t", frames[j]);
	        }
	    }	    
	    printf("\nNumber of Page Fault: %d\n",count);
		break;
		case 3:
		printf("LRU algorithm\n");    
		printf("-------Page Replacement algorithm--------\n");
		printf("\nNhập vào số khung trang :");
		scanf("%d",&frame); 
      for(i = 0; i < frame; i++)
      {
            frames[i] = -1;
      }
      for(j = 0; j < n; j++)
      {
            flag1 = 0, flag2 = 0;
            for(i = 0; i < frame; i++)
            {
                  if(frames[i] == a[j])
                  {

                        flag1 = 1;
                        flag2 = 1;
                        break;
                  }
            }
            if(flag1 == 0)
            {
                  for(i = 0; i < frame; i++)
                  {
                        if(frames[i] == -1)
                        {
                        	  
                              frames[i] = a[j];
                              flag2 = 1;
                              break;
                        }
                  }
            }
            if(flag2 == 0)
            {
                  for(i = 0; i < frame; i++)
                  {
                        temp[i] = 0;
                  }
                  
                  for(k=j-1,l = 1; l <= frame - 1;l++, k--)
                  {
                  		
                        for(i = 0; i < frame; i++)
                        {
                              if(frames[i] == a[k])
                              {
                                    temp[i] = 1;
                              }
                        }
                  }
                  for(i = 0; i < frame; i++)
                  {
                        if(temp[i] == 0)
                        pos = i;
                  }
                  frames[pos] = a[j];
                  count++;
            }
            printf("\n");
            for(i = 0; i < frame; i++)
            {
                  printf("%d\t", frames[i]);
            }
      }
      printf("\nNumber of Page Fault: %d\n",count);
			
	}
}
