#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
	//rastgele gemilerin yerlestirileceği dizi
	int amiral[8][8]={
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0}};
					
	//en sonda haritayi g�stermek i�in degerleri sakalyan "map" adl� dizi
	int map[8][8]={
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0}};
	
	//secilen gemilerin etraf�n� kapatma
	int saran[8][8]={
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0}};
	
	cout<<"Harita 8*8\'tur.";
	cout<<endl<<endl<<"Hadi tahmin et!";
	
	srand(time(0));
	
	int batan=0;
	int i=0, sat=0, sut=0;
	
	//bu while rastgele 8 degeri 1 yapar (gemileri yerlestirir)
	while(i < 8){
  	 	sat=rand()%8;
 		sut=rand()%8;
    
  		if(saran[sat][sut]==1) continue; //zaten doluysa ge�

    	amiral[sat][sut]=1;

   		//etraf�n� kapat
   		for(int dx=-1; dx<=1; dx++) {
        	for(int dy=-1; dy<=1; dy++) {
            	int nx=sat+dx;
            	int ny=sut+dy;
           		if (nx>=0 && nx<8 && ny>=0 && ny<8)
                	saran[nx][ny]=1;
        	}
   		}
    i++;
	}


	//8 gemiyi bulana kadar donguye devam et
	int deneme=0; // deneme hakk� sayac�
	while(batan!=8){
		int satir, sutun;
				
		//kullan�c� girisi
		cout<<endl<<"Satir: ";
		cin>>satir;
		cout<<"Sutun: ";
		cin>>sutun;
		
		//oyunu bitirmek i�in
		if(satir==0 && sutun==0)
			break;
		
		//girilen sayilari kontrol et
		if((satir<1 || satir>8) || (sutun<1 || sutun>8)){
			cout<<endl<<endl<<"Lutfen [1-8] sayilarindan birini giriniz!";
			continue;
		}
		
		//vurulan noktayi kontrol et
		if(map[satir-1][sutun-1]!=0){
			cout<<endl<<endl<<"Bu nokta daha once vuruldu!";
			continue;
		}
		
		//gemi vuruldu mu kontrol et (vurulduysa etraf�n� da vur (1 yap))
		if(!(amiral[satir-1][sutun-1]==1)) {
				cout<<endl<<"Bos vurdunuz!";
			map[satir-1][sutun-1]=-1;
			
		}else{
			cout<<endl<<"Amiral Batti!";
			++batan;
			
			for(int dx=-1; dx<=1; dx++) {
        		for(int dy=-1; dy<=1; dy++) {
            		int nx=satir-1+dx;
            		int ny=sutun-1+dy;
           			if (nx>=0 && nx<8 && ny>=0 && ny<8)
                		map[nx][ny]=-1;
        	}
   		}
			map[satir-1][sutun-1]=1;
			if(batan==8) break;
		}
		cout<<endl<<endl;
		cout<<"Batirdiginiz gemi sayisi: "<<batan<<endl<<endl;
		
		for(int i=0; i<8; i++){	
			if(i==0){
				cout<<"   1 2 3 4 5 6 7 8"<<endl<<endl;
			}
			for(int j=0; j<8; j++){
				if(j==0){
					cout<<i+1<<"  ";
				}
			
				if(map[i][j]==-1)
					cout<<"x ";
				else if(map[i][j]==0)
					cout<<"- ";
				else
					cout<<"o ";
			}
			cout<<endl;
		}
		cout<<endl;
		deneme++;
	}
	//sonuc
	if(batan==8){
		cout<<endl<<endl<<"Tebrikler:) Kazandizniz! 8 gemiyi de batirdiniz.";
		cout<<endl<<endl<<"Toplam "<<deneme<< " defa denediniz.";
	}
	cout<<endl<<endl;
	
	//vurulan noktaya "x", gemi olan noktaya "o" ve vurulmayan noktaya "-" koyma
	for(int i=0; i<8; i++){
		if(i==0){
			cout<<"   1 2 3 4 5 6 7 8"<<endl<<endl;
		}
		for(int j=0; j<8; j++){
			if(j==0){
				cout<<i+1<<"  ";
			}
		
			if(map[i][j]==-1)
				cout<<"x ";
			else if(map[i][j]==0)
				cout<<"- ";
			else
				cout<<"o ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	return 0;
}
