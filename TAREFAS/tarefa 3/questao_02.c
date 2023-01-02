#include <stdio.h>
#include <math.h>

float calcDistancia(float x1, float y1, float x2, float y2){
    return sqrt(pow((y2-y1),2)+pow((x2-x1),2));
}

void main(){
    float x1,y1,x2,y2, dist;
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
    dist = calcDistancia(x1,y1,x2,y2);
    printf("%.2f",dist);
}