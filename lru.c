#include <stdio.h>
void main() {
	int str[20],flg[20],i,j,f,len,count[20],m[10],next=0,min,pf=0;
	printf("Enter the length of Reference String:");
	scanf("%d",&len);
	printf("Enter the Reference String");
	for(i=0;i<len;i++) {
		scanf("%d",&str[i]);
		flg[i]=0;
	}
	printf("Enter the no. of Frames:");
	scanf("%d",&f);
	for(i=0;i<f;i++) {
		count[i]=0;
		m[i]=-1;
	}
	printf("\nTHE PAGE REPLACEMENT PROCESS IS...\n");
	for(i=0;i<len;i++) {
		for(j=0;j<f;j++) 
			if(m[j]==str[i]) {
				flg[i]=1;
				count[j]=next++;
			}
		if(flg[i]==0) {
			if(i<f) {
				m[i]=str[i];
				count[i]=next++;
			}
			else {
				min=0;
				for(j=1;j<f;j++) 
					if(count[min]>count[j])
						min=j;
				m[min]=str[i];
				count[min]=next++;
			}
			pf++;
		}
		for(j=0;j<f;j++) 
			printf("%d\t",m[j]);
		if(flg[i]!=1)
			printf("Page Fault:%d\n",pf);
		else
			printf("HIT!\n");
	}
	printf("\nTotal Page Fault = %d\n",pf);
	printf("Total Hits = %d\n",len-pf);
}
