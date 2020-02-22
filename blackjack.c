#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ksayi 52
int deste[ksayi] = {1,2,3,4,5,6,7,8,9,10,11,12,13,		//sinek
			14,15,16,17,18,19,20,21,22,23,24,25,26,		//maça
			27,28,29,30,31,32,33,34,35,36,37,38,39,		//karo
			40,41,42,43,44,45,46,47,48,49,50,51,52};	//kupa
int karisik[ksayi] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int toplam=0;
int numara;
int deger=0;

void karistir ();
void kartlari_yazdir(int birinci, int ikinci);
void kart(int kart_num);
void asiller (int num);
void sayilar (int num);
void total ();
void toplam_yazdir ();
void kart_sor();
void kart_cek();

int main(){
	int sayac;
	int birinci, ikinci;
	int toplam1, toplam11;
	
	karistir();
	birinci=karisik[0];
	ikinci=karisik[1];
	kartlari_yazdir(birinci, ikinci);
	topl:
	toplam_yazdir();
	
	if (toplam<21){
		kart_sor();
	}
	else if (toplam==21){
		printf ("Tebrikler!");
	}
	else{
		printf ("Kaybettiniz.");
	}
	system ("pause");
	return 0;
}
void karistir (){
	int i, random;
	srand(time(0));
	for (i=0; i<ksayi; i++){
		randgen:
		random=rand()%52;
		if (karisik[random]==0){
			karisik[random]=deste[i];
			continue;
		}
		else 
		goto randgen;
	}
}
void kartlari_yazdir(int birinci, int ikinci){
	printf ("Elinizdeki kartlar ");
	printf (" %d %d ", birinci, ikinci);
	kart (birinci);
	printf (" ve ");
	kart (ikinci);
	printf ("\b.\n");
}
void kart(int kart_num){
	int sinif;
	char isimbir[5]="sinek", isimiki[4]="maca", isimuc[4]="karo", isimdort[4]="kupa";
	numara=kart_num%13;
	sinif=kart_num/13+1;
	if ((numara==0)&&(sinif!=1)){
		sinif--;
	}
	else if (numara==0){
		numara=13;
	}
	
	
	if ((numara>1)&&(numara<11)){
		sayilar (numara);
	}
	else{
		asiller (numara);
	}	
		
		
	if (sinif==1){
		printf ("(%s) ", isimbir);
	}
	else if (sinif==2){
		printf ("(%s) ", isimiki);
	}
	else if (sinif==3){
		printf ("(%s) ", isimuc);
	}
	else{
		printf ("(%s) ", isimdort);
	}	
	
	total(numara);
}

void asiller (int num){
	if (num==1){
		printf ("A");
	}
	else if (num==11){
		printf ("J");
	}
	else if (num==12){
		printf ("Q");
	}
	else if ((num==0)||(num==13)){
		printf ("K");
	}
}

void sayilar (int num){
	printf ("%d", num);
}

void total(int numara){
	int toplam1, toplam11;
	if ((numara==0)||(numara==11)||(numara==12)||(numara==13)){
		toplam+=10;
	}
	else if (numara!=1){
		toplam+=numara;
	}
	else if (numara==1){
		toplam+=11;
		deger=1;
	}
}

void toplam_yazdir(){
	int toplam1, toplam11;
	if((deger==1)&&(toplam<21)){
		printf ("Elinizde as oldugu icin %d ve %d olmak uzere iki toplam elde edeceksiniz.", toplam-10, toplam);
	}
	else{
		printf ("Elinizdeki kartlarin toplami %d.\n", toplam);
	}
}
void kart_sor(){
	int sent;
	printf ("Kart cekmek istiyorsaniz -9'u tuslayiniz.");
	scanf ("%d", &sent);
}
