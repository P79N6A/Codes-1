//°ÑÇ°n(n<=10000)¸öÕûÊýË³´ÎÐ´ÔÚÒ»Æð££¬
//ÊýÒ»Êý0~9³öÏÖµÄ´ÎÊý
//£¨°ÑÔ­Ìâ¸ø¸ÄÁË¸Ä£¬Ã»ÓÐ°´×Ö·û´®ÊäÈë£©
//ÎÒÒ²ÊÇÐ´Íê²Å·¢ÏÖ£¬×íÁË¡£¡£¡£¡£¡£¡£
#include<stdio.h>

int main(void)
{
   int n;      
	while (scanf("%d", &n) == 1)
	{
		int z = 0, o = 0, t = 0, tr = 0, f = 0, fi = 0, s = 0, se = 0, e = 0, ni = 0,i;
		for (i = 1; i <= n; i++)
		{
			int temp=i;
			if(temp/10)
			{
				while(temp/10)
				{
					switch (temp%10){
			   	case 0:z++;temp/=10;printf("0"); break;
			   	case 1:o++;temp/=10; printf("1");break;
			   	case 2:t++;temp/=10; printf("2");break;
			   	case 3:tr++;temp/=10;printf("3"); break;
			   	case 4:f++;temp/=10;printf("4"); break;
			   	case 5:fi++;temp/=10;printf("5"); break;
			   	case 6:s++;temp/=10; printf("6");break;
			   	case 7:se++;temp/=10; printf("7");break;
			   	case 8:e++;temp/=10; printf("8");break;
			   	case 9:ni++;temp/=10;printf("9"); break;
			   	}
				}
				switch (temp){
				case 0:z++;printf("0"); break;
				case 1:o++; printf("1");break;
				case 2:t++;printf("2"); break;
				case 3:tr++;printf("3"); break;
				case 4:f++;printf("4"); break;
				case 5:fi++;printf("5"); break;
				case 6:s++;printf("6"); break;
				case 7:se++;printf("7"); break;
				case 8:e++;printf("8"); break;
				case 9:ni++;printf("9"); break;
				}
			}
			else{
				switch (temp){
				case 0:z++;printf("0"); break;
				case 1:o++; printf("1");break;
				case 2:t++;printf("2"); break;
				case 3:tr++;printf("3"); break;
				case 4:f++;printf("4"); break;
				case 5:fi++;printf("5"); break;
				case 6:s++;printf("6"); break;
				case 7:se++;printf("7"); break;
				case 8:e++;printf("8"); break;
				case 9:ni++;printf("9"); break;
				}
			}

		}
		printf("\n\n0: %d\n1: %d\n2: %d\n3: %d\n"
			"4: %d\n5: %d\n6: %d\n7: %d\n8: %d\n9: %d\n"
			 ,z, o, t, tr, f, fi, s, se, e, ni);
	}
	return 0;
}
