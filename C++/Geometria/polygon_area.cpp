ll area = 0;

for(int i = 0; i < n - 1; ++i){
    area += pontos[i].x*pontos[i+1].y - pontos[i+1].x*pontos[i].y;
}
area += pontos[n-1].x*pontos[0].y - pontos[0].x*pontos[n-1].y;

area = abs(area);