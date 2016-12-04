/*Burak Kağan Özkan
  15253509
  */

#include<stdio.h>
void kesirSadelestir();//aslında bunlara gerek yoktu ama
void kesirGoster();   //fonksiyonları baya gezdirince sorun çıkarttılar diye ekledim.
struct kesir{
  int pay;
  int payda;
};
struct kesir Kesirler[100];   //Girilen kesirleri sabit olarak tutmak için oluşturulmuş dizi.
struct islemKesir{
  int pay;
  int payda;
};
struct islemKesir isKesirler[100];  // İşlem yapılacak sayıları karışmasınlar diye ayrı diziye aktarıldı.
int sonKesir=0;//eleman eklerken limit'i belirlemek için.
int kesirEkle(int elemanSayisi){
  if(sonKesir+elemanSayisi>=100)//Limiti belirliyoruz burada
  printf("Limit Dolmuş gibi daha az eleman sayısıyla tekrar deneyiniz\n");
  else{int i=0;
  do{

  for(;i<elemanSayisi;i++){
  printf("%d.Kesri giriniz :",sonKesir+1 );
  scanf("%d/%d",&Kesirler[sonKesir].pay,&Kesirler[sonKesir].payda);
  if(Kesirler[sonKesir].payda==0)
  Kesirler[sonKesir].payda=1;
  sonKesir++;
  }
}while(i!=elemanSayisi);
}
  for(int i=0;i<100;i++)
  {
    isKesirler[i].pay=Kesirler[i].pay;
    isKesirler[i].payda=Kesirler[i].payda;
  }
}
int obebKesir(int payObeb,int paydaObeb){ //çok sık obeb'e ihtiyaç duyuluyordu sadeleştirme kısmında.
    int obeb=1;
    int limit=payObeb;
    if (paydaObeb>payObeb)
    limit=paydaObeb;
    int bol=2;
    for(;bol<limit;){
      if(payObeb%bol==0&&paydaObeb%bol==0){
        payObeb=payObeb/bol;
        paydaObeb=paydaObeb/bol;
        obeb=obeb*bol;
    }
      else
       bol++;
  }
  return obeb;
}
void kesirGoster(){
  for(int k=0;k<sonKesir;k++)
  printf("%d.Kesir :%d / %d  =====>  %d / %d \n",k+1,Kesirler[k].pay,Kesirler[k].payda,isKesirler[k].pay,isKesirler[k].payda );
} //Ekstra puan inş. amin allam nolor:))))
void kesirSadelestir(){
  int kesirSay=0;
  int pay=1,payda=1;
  for(;kesirSay<sonKesir;kesirSay++){
      int kesir_obeb=obebKesir(Kesirler[kesirSay].pay,Kesirler[kesirSay].payda);
      isKesirler[kesirSay].pay=isKesirler[kesirSay].pay/kesir_obeb;
      isKesirler[kesirSay].payda=isKesirler[kesirSay].payda/kesir_obeb;
      pay=pay*isKesirler[kesirSay].pay;
      payda=payda*isKesirler[kesirSay].payda;
  }
  int sonuc_obeb=obebKesir(pay,payda);
  pay=pay/sonuc_obeb;
  payda=payda/sonuc_obeb;
  printf("Sonuç  ======>  %d / %d\n",pay,payda);
  // Aslında pointer'ları tam olarak anlamış olsaydım 2 değer döndürebilirdim

}

int main(){
  char secenek;
  do{
  printf("\t\nSayı Sadeleştirme\n------------------------------\n" );
  printf("1-)Kullanıcıdan Değer Alma\n2-)Sadeleştirme(Sadece Sonuç)\n");
  printf("3-)Ara İşlemler\n4-)Çıkış\n" );
  printf("Seçeneğiniz :");
  do{                                     //CagatayCebi'den gördüm bu yeri ve çok kullanışlı Sezarın hakkı sezara...<3
    scanf("%c",&secenek);
    if(secenek>='1' && secenek <= '4' || secenek == '\n')
    continue;
    else
    printf("Lütfen Seçenekler dışına çıkmayınız ! ! !\n" );

  }while(secenek=='\n');
  if (secenek=='1'){
    int elemanSayisi;
    printf("Eleman sayısı giriniz :");
    scanf("%d/",&elemanSayisi);
    kesirEkle(elemanSayisi);// Bu kısımda yanlışlıkla harf girildiğinde sonuç=0 oluyor bu hatayı gidermek için kaçış dizileri kullanılabilir
  }
  else if(secenek=='2'){kesirSadelestir();}
  else if (secenek=='3'){kesirGoster();}
printf("\nToplam Eleman Sayısı : === > %d\n",sonKesir );
}while(secenek!='4');

}
