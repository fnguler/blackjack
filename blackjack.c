#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define cnumber 52
#define pit 104
int deck1[cnumber] = {1,2,3,4,5,6,7,8,9,10,11,12,13,	//club
			14,15,16,17,18,19,20,21,22,23,24,25,26,		//spade
			27,28,29,30,31,32,33,34,35,36,37,38,39,		//diamond
			40,41,42,43,44,45,46,47,48,49,50,51,52};	//heart

int deck2[cnumber] = {1,2,3,4,5,6,7,8,9,10,11,12,13,	//club
			14,15,16,17,18,19,20,21,22,23,24,25,26,		//spade
			27,28,29,30,31,32,33,34,35,36,37,38,39,		//diamond
			40,41,42,43,44,45,46,47,48,49,50,51,52};	//heart
			
struct plca{
	int cards[15];
	int total;
};
struct plca player[8];
			
int pitch[pit];
int mixed[pit] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int j=0, cardnum, cardclass;

void append ();
void mix ();
void drawbeg ();
void addc ();
void output();
void decision ();
void draw();

int main(){
	
}

void append(){
	int x;
	for (x=0; x<pit; x++){
		if (x<52){
			pitch[x]=deck1[x];
		}
		else{
			pitch[x]=deck2[x];
		}
	}
}

void mix (){
	int i, random;
	srand(time(0));
	for (i=0; i<pit; i++){
		randgen:
		random=rand()%104;
		if (mixed[random]==0){
			mixed[random]=pitch[i];
			continue;
		}
		else 
		goto randgen;
	}
}

void drawbeg (){
	int i, k;
	for (k=0; k<2; k++){
		for (i=0; i<16; i++){
			player[i].cards[k]=mixed[j];
			j++;
		}
	}
}

void addc (){
	int l, p;
	for (p=0; p<8; p++){
		for (l=0; l<15; l++){
			player[p].total=0;
			player[p].total+=player[p].cards[l];
		}	
	}
}

void output(){
	int q, y, z;
	for (z=0; z<8; z++){
		y=0;
		do{
			cardnum=player[z].cards[y]%13;
			if (cardnum==0){
				cardnum=13;
			}
			cardclass=(player[z].cards[y]/13)+1;
			y++;
		}while (player[z].cards[y]!=NULL);
		
		printf ("Number %d's cards are ", z);
		for (q=0; q<y; q++){
			if (cardnum==1){
				printf ("A ");
			}
			else if (cardnum==11){
				printf ("J ");
			}
			else if (cardnum==12){
				printf ("Q ");
			}
			else if (cardnum==13){
				printf ("K ");
			}
			else{
				printf ("%d ", cardnum);
			}
			
			if (cardclass==1){
				printf ("club");
			}
			else if (cardclass==2){
				printf ("spade");
			}
			else if (cardclass==3){
				printf ("diamond");
			}
			else if (cardclass==4){
				printf ("heart");
			}
			if ((y!=2)&&(q!=y-1)){
				printf (", ");
			}
			else if ((y==2)&&(q==y-2)){
				printf (" and ");
			}
		}
		
		
	}

}

void decision(){
	
}

