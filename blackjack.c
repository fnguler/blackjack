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
	int bet;
	int aofc;
	int cardnum[15];
	int cardclass[15];
};
struct plca player[8];
			
int pitch[pit];
int mixed[pit] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int j=0, acekeeper=0;

void append ();
void mix ();
int makebet (int a);
void drawbeg ();
void output();
void addc (int z, int y);
void decision (int z);
void draw(int a);

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

int makebet (int a){
	printf ("Player %d, please make your bet. ", a);
	scanf ("%d", &player[a].bet);
}
void drawbeg (){ //deals the cards at the beginning.
	int i, k;
	for (k=0; k<2; k++){
		for (i=0; i<8; i++){
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
			player[z].cardnum[y ]=player[z].cards[y]%13;
			if (player[z].cardnum[y]==0){
				player[z].cardnum[y]=13;
			}
			player[z].cardclass[y]=(player[z].cards[y]/13)+1; //finds the card class.
		
			addc(z,y);	
			y++;
			
		}while (player[z].cards[y]!=NULL); //finds the card number until the element of the structure comes up with the value "NULL".
		
		player[z].aofc=y;
		
		printf ("Number %d's cards are ", z);
		for (q=0; q<y; q++){ //repeats everything for each card.
			
			//finds and prints the card number.
			if (player[z].cardnum[q]==1){
				printf ("A ");
			}
			else if (player[z].cardnum[q]==11){
				printf ("J ");
			}
			else if (player[z].cardnum[q]==12){
				printf ("Q ");
			}
			else if (player[z].cardnum[q]==13){
				printf ("K ");
			}
			else{
				printf ("%d ", player[z].cardnum[q]); 
			}
			
			
			//prints the card class.
			if (player[z].cardclass[q]==1){ 
				printf ("club");
			}
			else if (player[z].cardclass[q]==2){
				printf ("spade");
			}
			else if (player[z].cardclass[q]==3){
				printf ("diamond");
			}
			else if (player[z].cardclass[q]==4){
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
		if (acekeeper==0){
			printf ("\nThe total value of the cards is %d.\n", player[z].total);
		}
		else{
			printf ("\nBecause of the ace/s, the total values of the cards are calculated as %d and %d.\n", player[z].total, player[z].total+10);
		}
		
		decision(z);
			
		}
		
	}

}

void addc(int z, int y){ //adds the values of cards.
	int i;
	acekeeper=0;
	player[z].total=0;
	
	for (i=0; i<y; i++){
		if ((player[z].cardnum==10)||(player[z].cardnum==11)||(player[z].cardnum==12)||(player[z].cardnum==13)){ //if the card number is 10 or the card is a noble card, the card's value becomes 10.
			player[z].total+=10;
		}
		else if (player[z].cardnum!=1){ //if the card is not an ace, the card's value becomes its number.
			player[z].total+=cardnum;
		}
		else{ //if the card is an ace, acekeeper variable increases by one. ace value is taken as one.
			acekeeper++;
		}
	}
	player[z].total+=acekeeper;
}

void decision(int z){
	int decis, flag=0;
	dec:
	printf ("\nPlayer %d, make your decision.\n", z);
	printf ("\n1-Hit\n2-Stand\n3-Double Down\n4-Split Pair\n5-Insurance\n6-Surrender\n");
	scanf ("%d", &dec);
	switch (decis){
		case 1: draw(z);
				flag=1;
				goto dec;
		case 2: break;
		case 3: player[z].bet*=2;
				draw(z);
				flag=1;
				goto dec;
				break;
		case 4: printf ("Player %d, update your bet.\n", z);
				makebet(z);
				draw(z);
				draw(z);
				flag=1
				goto dec;
				break;		
		case 5: player[z].bet/=2;
				flag=1
				break;
		case 6: if (flag==0){
					printf ("Player %d surrendered.\n", z);
				}
				break;
		default: goto dec;
	}
	
}

void draw(int a){
	player[a].cards[ player[a].aofc ]=mixed[j];
	j++;
	player[a].aofc++;
}



