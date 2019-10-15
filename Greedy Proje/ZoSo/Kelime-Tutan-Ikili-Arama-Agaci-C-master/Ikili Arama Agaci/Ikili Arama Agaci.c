#include <stdio.h>
#include <stdlib.h>                                     /* Blueshifty */
#include <string.h>
#include <process.h>

struct n{
	char kelime[5];
	int s;
	struct n *sol;                                                     /*Ikili Arama Agacinin Struct Yapisi*/
	struct n *sag;
};
int s;
void menu_fonk();
char kelimes[5];
typedef struct n node;

int karsilastir(char k1[5],char k2[5]){
	int a = k1[0];
	int b = k2[0];
	if(a == b){
		a = k1[1];
		b = k2[1];
		if(a == b){
			a = k1[2];
			b = k2[2];
			if(a == b){
				a = k1[3];
				b = k2[3];
				if(a > b){
					return 1;
				}
				else{                                      /* Iki Kelimeyi Alfabetik Karsilastiriyor.*/      
					return 0;                             /*Agaca Eleman Yerlestirirken Bu Fonksiyona Gore*/
				}                                        /*Saga veya Sola Yerlestirdim.*/
			}                                            /*4 Harfede Bakiyor*/
			if(a > b){
				return 1;
			}                           
			else{
				return 0;
			}
		}
		if(a>b){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(a > b){
		return 1;
	}
else{
	return 0;
}
}

node * ekleme_fonk(node *agac,char k[5]){
	if(agac == NULL){
		node *root= (node *)malloc(sizeof(node));
		root->sol = NULL;
		root->sag = NULL;
		strcpy(root->kelime,k);
		root->s = 1;
		return root;
	}
	if(strcmp(agac->kelime,k)==0){
		agac->s++;
		return agac;
	}                                                                      /*Ekleme Fonk.*/
	if(karsilastir(agac->kelime,k)==0){                    /*Karsilastirma Fonksiyonuma Gore Kelimeyi Saga Veya Sola Ekliyor*/
		agac->sag = ekleme_fonk(agac->sag,k);
		return agac;
	}
	agac->sol = ekleme_fonk(agac->sol,k);
	return agac;
}

void dolas(node *agac){
	if(agac==NULL){
		return;
	}
	dolas(agac->sol);                                                    /* dolas1 Alfabetik Sekilde Kelimeleri Yazdiran Fonk.*/
	printf("%s\t%d Kez \n",agac->kelime,agac->s);
	dolas(agac->sag);
}

void dolas2(node *agac){
	if(agac==NULL){
		return;
	}
	dolas(agac->sag);                                                    /* dolas2 Alfabetik Olmadan Kelimeleri Yazdiran Fonk.*/
	printf("\n%s\t%d Kez \n",agac->kelime,agac->s);
	dolas(agac->sol);
}


 node * agac_olustur(node * agac){
   agac = NULL;
   int c=0,x=0;
   char okunan_kelime[5];
   FILE *dosya;
   dosya = fopen("C:\\Users\\Win 7\\Desktop\\kelimeler.txt","r");                       /*Dosyadan Okuyup Agaca Ekleyen Fonk*/
   while(c != EOF){
   c = fscanf(dosya,"%s",okunan_kelime);
   agac = ekleme_fonk(agac,okunan_kelime);                                                      
   x++;
   }
   printf("%d Tane Kelime Okundu, Ikili Arama Agacina Eklendi.",x-1);          /*x-1 Koyma Sebebim Son Kelimeyi Bir Kez Daha Okumasý*/
   return agac;                                                          /*Buyuk Ihtimal c'yi EOF'a Esitlemesinde Bir Sýkýntý Cýkýyor*/
   }      

void arama(node*agac,char k[5],int d){
 if(strcmp(agac->kelime,k)==0){
 printf("\n%s\t%d. Derinlikte\t%d Kez",agac->kelime,d,agac->s);
 return;
 }
if(karsilastir(agac->kelime,k)==0){
 d++;
 if(agac->sag == NULL){
   printf("\nAradiginiz Kelime Bulunamadi");
}
else{
	return arama(agac->sag,k,d);
}
}                                                                           /*Arama Fonk*/
else{                                                                   /*'d' Degisgenim Derinligi Temsil Ediyor.*/
 d++;                                            
 if(agac->sol==NULL){
 printf("\nAradiginiz Kelime Bulunamadi");
}
else{
	return arama(agac->sol,k,d);
}
}
}

void fonk1(node* agac){
   	dolas2(agac);
   	printf("\nMenuye Donmek Icin Bir Tusa Basin");
    getch();                                                     /*Fonk1 Dolas2'yi Cagiriyor*/
    system("cls");
    return menu_fonk(agac);
}

void fonk2(node* agac){
	dolas(agac);
	printf("\nMenuye Donmek Icin Bir Tusa Basin");
    getch();                                                         /*Fonk2 Dolas1''i Cagiriyor*/      
    system("cls");
    return menu_fonk(agac);
}

void fonk3(node* agac,char k[5]){
	arama(agac,k,0);
	printf("\nMenuye Donmek Icin Bir Tusa Basin");
	getch();                                                                 /*Fonk 3 Arama Fonk.'nu Cagiriyor*/
	system("cls");
	return menu_fonk(agac);
}

void menu_fonk(node*agac){
printf("\t\t***** MENU *****\n\n");
printf("   1 -- Agactaki Kelimeleri Yazdirir.\n");
printf("   2 -- Agactaki Kelimeleri Alfabetik Siraya Gore Yazdirir.\n");
printf("   3 -- Agacta Arama Yapmanizi Saglar.\n");
printf("   4 -- CIKIS.\n\n");
printf("Yapmak Istediginiz Islemin Numarasini Girin(1-2-3)\n");
scanf("%d",&s);
 switch(s)                                                
 {
  case 1: fonk1(agac); break;
  case 2: fonk2(agac); break;
  case 3: printf("Aramak Istediginiz Kelimeyi Girin\n");scanf("%s",&kelimes);fonk3(agac,kelimes); break;  
  case 4: exit(0);
  default :printf("Islem Numarasi Girmeliydiniz.... Menuye Donmek Icin Bir Tusa Basin"); getch(); system("cls"); menu_fonk(agac); break;
}    
}
               
int main(){
	printf("\t\t**********UYARI**********\n");
	printf("Kodun 103. Satirina Kelime Dosyasinin Yolunu Girebilirsiniz.\n");
	printf("\nKoda Kucuk Notlar Biraktim. Kolayca Inceliyebilirsiniz. :)\n");
	printf("Kolay Gelsin :)\n");
	printf("Menudeyken 1-2-3 Rakamlarini Kullanmaya Dikkat Edin, Sikinti Cikartabiliyor.");
	printf("\n\n\nKelimeleri Agaca Eklemek Icin Bir Tusa Basin\n");
	getch();
    node *agac = agac_olustur(agac);
    printf("\nMenuye Gecmek Icin Bir Tusa Basin\n");
    getch();
    system("cls");
    menu_fonk(agac);
}
