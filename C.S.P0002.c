#include <stdio.h>
#include <string.h>
#define MAXN 1000000000
char* printHundreds(long long int num, char str[]) {
    char digit[21][11] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven",
                          " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", 
                          " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen",
                          " Nineteen"};
    char tens[11][10] = { "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", 
                         " Seventy", " Eighty", " Ninety"};
//    char str[1000] = {0};
    int prev=0, div=1000;
//    strcpy(str, "");
    
    while(div) {

        if ((num / div) % 10 > 0 || (div == 10 && (num % 100) > 0)) { 

            if (prev) {
                strcat(str, " and");
                prev = 0;
            }

            switch(div) {
            case 1000:
                strcat(str, digit[(num / div) % 10]);     
                strcat(str, " Thousand");
                prev = 1;
                break;
            case 100:
                strcat(str, digit[(num / div) % 10]);     
                strcat(str, " Hundred");
                prev = 1;
                break;
            case 10:
                if ( (num % 100) >= 10 && (num % 100) <= 19)
                    strcat(str, digit[num % 100]);
                else {
                    strcat(str, tens[(num % 100) / 10]);
                    strcat(str, digit[num % 10]);
                }
                break;
            }
        }

        div /= 10;
    }
}

int convert(long long int num) {
	long long int D[10] = {0};
	int i = 0;
	
	while(num != 0) {
		D[i++] = num % 10;
		num /= 10;
	}
	
	int a;
	for(a = i; a >= 0; a--) {
		printf("%lld ", D[a]);
	}
	
	long long int tempNumber;
	char str[1000] = {0};
	strcpy(str, "");
	
	printHundreds(D[9], str);
	if(D[9] > 1) strcat(str, " Billions");
	else if (D[9] > 0) strcat(str, " Billion");
	
	tempNumber = D[8] * 100 + D[7] * 10 + D[6];
	printHundreds(tempNumber, str);
	if(D[6] > 1) strcat(str, " Millions");
	else if(tempNumber > 0) strcat(str, " Million");
	
	tempNumber = D[5] * 100 + D[4] * 10 + D[3];
	printHundreds(tempNumber, str);
	if(D[3] > 1) strcat(str, " Thousands");
	else if (tempNumber > 0) strcat(str, " Thousand");
	
	tempNumber = D[2] * 100 + D[1] * 10 + D[0];
	printHundreds(tempNumber, str);
	
	// Print result to Screen
	printf("\nString: %s\n", str);
}

int main() {
	long long int num;
	
	//get number from user
	printf("Enter a number: ");
	scanf("%lld", &num);
//	printf("num = %lld", num);
	
	convert(num);
	
	getchar();
	return 0;
}
