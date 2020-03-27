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
int j=0, cardnum, cardclass, flag;

void append ();
void mix ();
void drawbeg ();
void output();
void addc (int z, int y);
void decision ();
void draw();

int main(){
	
}

void append(){ //appends two decks for pitch game.
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

void mix (){ //mixes the deck.
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

void drawbeg (){ //deals the cards at the beginning.
	int i, k;
	for (k=0; k<2; k++){
		for (i=0; i<16; i++){
			player[i].cards[k]=mixed[j];
			j++;
		}
	}
}

void output(){
	int q, y, z;
	for (z=0; z<8; z++){ //repeats everything for 7 players and the dealer.
		y=0;
		do{
			cardnum=player[z].cards[y]%13;
			if (cardnum==0){
				cardnum=13;
			}
			cardclass=(player[z].cards[y]/13)+1; //finds the card class.
			y++;
			
			addc(z,y);
			
		}while (player[z].cards[y]!=NULL); //finds the card number until the element of the structure comes up with the value "NULL".
		
		printf ("Number %d's cards are ", z);
		for (q=0; q<y; q++){ //repeats everything for each card.
			
			//finds and prints the card number.
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
			
			
			//prints the card class.
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
			
			
			//helps printing the cards with the right sentence structure.
			if ((y!=2)&&(q!=y-1)){ 
				printf (", ");
			}
			else if ((y==2)&&(q==0)){
				printf (" and ");
			}
			else if ((y!=2)&&(q==y-1)){
				printf (" and ");
			}
			
		}
		

			
		}
		
	}

}

void addc(int z, int y){ //adds the values of cards.
	int i;
	flag=0;
	player[z].total=0;
	for (i=0; i<y; i++){
		if ((cardnum==10)||(cardnum==11)||(cardnum==12)||(cardnum==13)){ //if the card number is 10 or the card is a noble card, the card's value becomes 10.
			player[z].total+=10;
		}
		else if ((cardnum!=1)||((cardnum==1)&&(player[z].total>10))){ //if the card is not an ace OR is an ace and total value of the cards are greater than 10, the card's value becomes its number.
			player[z].total+=cardnum;
		}
		else{ //if the card is an ace and the total value is less than 11, the card's value becomes 11.
			player[z].total+=11;
			flag=1;
		}
	}
}

void decision(){
	
}

