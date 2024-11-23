#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    printf("MERHABALAR... \nOYUN KENARLARI SIFIRLAR ACIK SEKILDE BASLAR \nKAPALI OLANLAR = 9\nMAYIN ISARETLI OLANLAR = 8\nIYI EGLENCELERR...\n");
    int t =10,sayac9 = 0,maysay =0;
    int oyun [t][t];
    char tut[0];
    int mayin = 1;
    int x=0,y=0;
    int sifre[t][t];
    int str,stn,sayac=0;
    srand(time(NULL));
    
    for(int i = 0;i <=(t-1);i++){
        for(int j=0;j <=(t-1);j++){
          oyun[i][j] = 0;
          sifre[i][j] = 9;
        }
    }
    for(int i = 0;i <(t*3);i++){
    str = rand()% (t-2)+1;
    stn = rand()% (t-2)+1;
    oyun[str][stn] = 8;
    }
    for(int i = 0;i <=(t-1);i++){
        for(int j=0;j <=(t-1);j++){
            if(oyun[i][j] != 8){
                if(oyun[i+1][j]== 8 && i+1 <=t) sayac++;
                if(oyun[i+1][j+1]== 8 && j+1 <=t) sayac++;
                if(oyun[i][j+1]== 8 &&j+1 <=t) sayac++;
                if(oyun[i-1][j+1]== 8 &&j+1 <=t && i-1 >=0) sayac++;
                if(oyun[i-1][j]== 8 && i-1>=0) sayac++;
                if(oyun[i-1][j-1]== 8 && i-1 >= 0) sayac++;
                if(oyun[i][j-1]==8 && j-1 >= 0) sayac++;
                if(oyun[i+1][j-1]==8 && j-1 >= 0 && i+1 <=t) sayac++;
                
                oyun[i][j] = sayac;
                sayac = 0;
            }
        }
    }
    for(int i = 0;i <=(t-1);i++){
        if(oyun[i][0] == 0) sifre[i][0] = oyun[i][0];
        if(oyun[i][t-1] == 0) sifre[i][t-1] = oyun[i][t-1];
        if(oyun[0][i] == 0) sifre[0][i] = oyun[0][i]; 
        if(oyun[t-1][i] == 0) sifre[t-1][i] = oyun[t-1][i];
        
            
    }
    for(int i = 0;i <=(t-1);i++){
            for(int j=0;j <=(t-1);j++){
                if(sifre[i][j] == 0){
                    if(i+1 <= t) sifre[i+1][j] = oyun[i+1][j];
                    if(j+1 <= t) sifre[i][j+1] = oyun[i][j+1];
                    if(i-1 >= 0) sifre[i-1][j] = oyun[i-1][j];
                    if(j-1 >= 0) sifre[i][j-1] = oyun[i][j-1];
                    if(j-1 >= 0 && i-1 >=0) sifre[i-1][j-1] = oyun[i-1][j-1];
                    if(j+1 <= t && i+1 <=t) sifre[i+1][j+1] = oyun[i+1][j+1];
                    if(j-1 >= 0 && i+1 <=t) sifre[i+1][j-1] = oyun[i+1][j-1];
                    if(j+1 <= t && i-1 >=0) sifre[i-1][j+1] = oyun[i-1][j+1];
                }
            }
        }
    for(int i = 0;i <=(t-1);i++){
            for(int j=0;j <=(t-1);j++){
                printf("%d ",sifre[i][j]);
                if(oyun[i][j] == 8){
                    maysay ++;
                }
         }
         printf("\n");
    }
    printf("MAYIN SAYISI = %d\n",maysay);
    while(1){
        printf("SECTIGIN SATIR = ");
        scanf("%d",&x);
        printf("\nSECTIGIN SUTUN = ");
        scanf("%d",&y);
        printf("\nMAYIN ISE 1, BOS ISE 0 SECINIZ = ");
        scanf("%d",&mayin);
        if(oyun[x-1][y-1] == 8 && mayin == 0 && sifre[x-1][y-1] != 8){
            printf("MAYINA BASTINIZ\nTEKRAR DENEYINIZ...");
            break;
        }else if(mayin == 0 && sifre[x-1][y-1] != 8){ 
            sifre[x-1][y-1] = oyun[x-1][y-1];
        }else if(sifre[x-1][y-1] == 8 && mayin == 0) {
            sifre[x-1][y-1] = 9;
        }else if(mayin == 1){
            sifre[x-1][y-1] = 8;
        }
        for(int i = 0;i <=(t-1);i++){
            for(int j=0;j <=(t-1);j++){
                printf("%d ",sifre[i][j]);
                if(sifre[i][j] != 8 &&   sifre[i][j] != 9){
                    sayac9++;
                }
            }
            printf("\n");
        }
        if(sayac9 == (((t*t)-maysay))){
            printf("WAOOOWWW KAZANDIN...");
            break;
        }
        x=0;
        y=0;
        sayac9 = 0;
    }
    return 0;
}
