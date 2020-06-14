#include <stdio.h>
#include<windows.h>
enum state {INGAME = 0,MENU,SETTING,GAMEOVER,INFO} state;
int snake[1000];
int fruit = 12010;
int length;
int ct = 0;
int vx=-1, vy=0;
int score = 0;
int getX(int a){
	return (a - 10000)/100;
}
int Random(int a,int b){
	return a + rand()%(b-a+1);
}

void recreatFruit(){
	int bl = 0,i;
	for(;;){
		fruit = 10000 + Random(1,77)*100;
	    fruit += Random(1,26);
	    for(i=0;i<length;i++){
	    	if(fruit==snake[i]) bl = 1;
		}
		if(!bl) break ;
	}
}
void initgame(){
	length = 5;
	snake[0] = 12010;
	snake[1] = 12011;
	snake[2] = 12012;
	snake[3] = 12013;
	snake[4] = 12014;
}
int getY(int a){
	return a%100;
}
       void gotoxy(int x, int y){
       	static HANDLE h = NULL;
       	if(!h)
       	   h = GetStdHandle(STD_OUTPUT_HANDLE);
       	COORD c = {x,y};
       	SetConsoleCursorPosition(h,c);
	   }
void printScore(){
	int tg = score;
	int n = 0;
	int a[5];
	for(n;n<5;n++){
	a[n] =tg%10;
    tg /= 10;
}	
gotoxy(119,15);
printf("%d",a[0]);
gotoxy(119,14);
printf("%d",a[1]);
gotoxy(119,13);
printf("%d",a[2]);
gotoxy(119,12);
printf("%d",a[3]);
gotoxy(119,11);
printf("%d",a[4]);
}
        void printBox(){
        		int i =0;
			for(i;i<119;i++)printf("#");
	        i =0;
	        int j = 0;
	        for(j;j<28;j++){
	            printf("\n");
	        	i = 0;
	        	for(i;i<119;i++){
	        		printf((i==0||i==118)?"#":" ");
				}
		        }
		i = 0;
		printf("\n");
		for(i;i<119;i++)printf("#");
		gotoxy(119,5);
		printf("s");
		gotoxy(119,6);
		printf("c");
		gotoxy(119,7);
		printf("o");
		gotoxy(119,8);
		printf("r");
		gotoxy(119,9);
		printf("e");
		
		gotoxy(119,15);
printf("%d",0);
gotoxy(119,14);
printf("%d",0);
gotoxy(119,13);
printf("%d",0);
gotoxy(119,12);
printf("%d",0);
gotoxy(119,11);
printf("%d",0);
		}
        void menu(){
		    }
		void setting(){ printf("setting");}
		void ingame(){
			int key = 0;
			initgame();
		    printBox();
		    int j = 1;
		       gotoxy(getX(snake[0]),getY(snake[0]));
		       printf("o");
		    for(j;j<length-1;j++){
		       gotoxy(getX(snake[j]),getY(snake[j]));
		       printf("o");
			}
		    while (state==INGAME){
		    	if(kbhit()){
		    		key = getch();
		    		switch(key){
		    			// nut len 
		    			case 72 :
		    				if(vx!=0){
		    				vy = -1;
		    				vx = 0;
		    			}
		    			break;
		    			// nut xuong
		    			case 80 :
		    				if(vx!=0){
		    					vy = 1;
		    				    vx = 0;
							}
		    			break;
		    			// nut qua trai 
		    			case 75 :
		    				if(vy!=0){
		    					vx = -1;
		    				    vy = 0;
							}
		    			break;
		    			// nut qua phai
		    			case 77 :
		    				if(vy!=0){
		    					vy = 0;
		    				    vx = 1;
							}
		    			break;
					}
				}
				if((ct%1000)==0){
				gotoxy(getX(snake[length - 1]),getY(snake[length - 1]));
				printf(" ");
				int i = length - 1;
				for(i;i>0;i--){
					snake[i] = snake[i - 1];
				}
				snake[0] += vy;
				snake[0] += vx*100;
				if(getY(snake[0])==0) snake[0] += 28;
				if(getY(snake[0])==29) snake[0] -= 28;
				if(getX(snake[0])==0) snake[0] += 116* 100;
				if(getX(snake[0])==117) snake[0] -= 116* 100;
				if(snake[0]==fruit){
					gotoxy(getX(fruit),getY(fruit));
					printf(" ");
					length++;
					recreatFruit();
					score += 5;
					printScore();
				}
				gotoxy(getX(snake[0]),getY(snake[0]));
				printf("@");
				gotoxy(getX(snake[1]),getY(snake[1]));
				printf("*");
				gotoxy(getX(fruit),getY(fruit));
				printf("O");
				
				for(i=1;i<length;i++){
					if(snake[0]==snake[i])
					state = GAMEOVER;
				}
	        }
	        ct++;
			}
			}
		void gameover(){
			system("cls");
		    printf("gameover");
			}
		void info(){
		    printf("info");
			}   
int main(){
	while(1){
		switch(state){
			case MENU:
				menu();
				break;
			case SETTING:
				setting();
				break;
			case INGAME:
				ingame();
				break;
			case GAMEOVER:
				gameover();
				break;
			case INFO:
				info();
				break;			
	    }
	    }
	return 0;
    }
