#include <stdio.h>

typedef struct Tempo
{
    int hora, minuto, segundo;
}Tempo;

Tempo seg2tadTempo(int s){
    Tempo tempo;
    tempo.minuto = 0;
    tempo.hora = 0;
	if(s > 60){
    	while(s > 60){
    		tempo.minuto +=1;
    		s = s - 60;
		}
	}
	if(tempo.minuto > 60){
		while(tempo.minuto > 60){
			tempo.hora += 1;
			tempo.minuto = tempo.minuto - 60;
		}
	}
    tempo.segundo = s;
    return tempo;
}
 
 
int main() {
    Tempo tempo;
    int s;
    scanf("%d",&s);
    tempo = seg2tadTempo(s);
    printf("%d:%d:%d\n",tempo.hora,tempo.minuto,tempo.segundo);
    
 
    return 0;
}