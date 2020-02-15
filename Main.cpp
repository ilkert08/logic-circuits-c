#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<time.h>
int sira;
char satir[10][10][300];
char satir2[15][15][50];
long tutucu[20];
char tutucuc[20];
int sinir;
int cv=0;
char giris[5][30];
char cikis[5][30];
char cikis1[5][30];
int k=0;
int dizi5[10];
char dizi6[10];
int giris_gecikme[5];
int cikis_gecikme[5];
char simule[10][10][100];
int xx=0;
int yy=0;
int tempns;
char komutlar[20][10][30];
FILE *komut_dosya;
FILE *log_komut;
FILE *dosya;
FILE *dosya2;
FILE *dosya3;
int sirak=NULL;
int komuty;
char include[10][10][100];
char diger_dosya[10][10][100];
void kapici()
{
    int l=0;
    int u=1;
    int p=1;
    for(int k=3; k<10; k++)
    {

        for(int i=5; i<5+atoi(satir[i][3]); i++)
        {
            for(int j=2; j<10; j++)
            {
                if(satir[k][i][0]==satir[1][j][0])
                {
                    strcpy(giris[u],satir[k][2]);

                    giris_gecikme[u]=atoi(satir[k][5+atoi(satir[k][3])]);
                    u++;
                    goto m;

                }
                if(satir[k][4][0]==satir[2][j][0])
                {
                    strcpy(cikis[p],satir[k][2]);
                    strcpy(cikis1[p],cikis[p]);
                    cikis_gecikme[p]=atoi(satir[k][5+atoi(satir[k][3])]);
                    p++;

                }

            }

        }
m:
        continue;
    }

    //printf("\n.%s %d",cikis1[1], cikis_gecikme[1]);
    //printf("%s. %d .%s. %d",giris[1],giris_gecikme[1],  giris[2], giris_gecikme[2]);
    int ilkcikisgecikme=cikis_gecikme[1];

    for(int ns=1; ns<10; ns++)
    {
        for(int i=1; i<=4; i++)
        {
            if(giris_gecikme[i]==ns)
            {

                if(strcmp(giris[i],"AND")==0)
                {
                    cikis_gecikme[1]=ilkcikisgecikme;
                    tempns=ns;
                    andoncesi();
                    cikis_gecikme[1]=cikis_gecikme[1]+giris_gecikme[i];
                }
                if(strcmp(giris[i],"NAND")==0)
                {
                    cikis_gecikme[1]=ilkcikisgecikme;
                    tempns=ns;
                    nandoncesi();
                    cikis_gecikme[1]=cikis_gecikme[1]+giris_gecikme[i];
                }
                if(strcmp(giris[i],"OR")==0)
                {
                    cikis_gecikme[1]=ilkcikisgecikme;
                    tempns=ns;
                    oroncesi();
                    cikis_gecikme[1]=cikis_gecikme[1]+giris_gecikme[i];
                }
                if(strcmp(giris[i],"NOR")==0)
                {
                    cikis_gecikme[1]=ilkcikisgecikme;
                    tempns=ns;
                    noroncesi();
                    cikis_gecikme[1]=cikis_gecikme[1]+giris_gecikme[i];
                }
                if(strcmp(giris[i],"XOR")==0)
                {
                    cikis_gecikme[1]=ilkcikisgecikme;
                    tempns=ns;
                    xoroncesi();
                    cikis_gecikme[1]=cikis_gecikme[1]+giris_gecikme[i];
                }
                if(strcmp(giris[i],"NOT")==0)
                {
                    cikis_gecikme[1]=ilkcikisgecikme;
                    tempns=ns;
                    notoncesi();
                    cikis_gecikme[1]=cikis_gecikme[1]+giris_gecikme[i];
                }



            }

        }
        if(cikis_gecikme[1]==ns)
        {
            if(strcmp(cikis1[1],"AND")==0)
            {
                tempns=ns;
                andoncesi();
            }
            if(strcmp(cikis1[1],"NAND")==0)
            {
                tempns=ns;
                nandoncesi();
            }
            if(strcmp(cikis1[1],"OR")==0)
            {
                tempns=ns;
                oroncesi();
            }
            if(strcmp(cikis1[1],"NOR")==0)
            {
                tempns=ns;
                noroncesi();
            }
            if(strcmp(cikis1[1],"XOR")==0)
            {
                tempns=ns;
                xoroncesi();
            }
            if(strcmp(cikis1[1],"NOT")==0)
            {
                tempns=ns;
                notoncesi();
            }



        }


    }
}
void oroncesi()
{
    for(int i=3; i<8; i++)
    {

        if(strcmp(satir[i][2],"OR")==0)
        {
            for(int j=5; j<5+atoi(satir[i][3]); j++)
            {
                dizi6[k]=satir[i][j][0];
                for(int t=1; t<=sinir; t++)
                {
                    if(dizi6[k]==tutucuc[t])
                    {
                        dizi5[k]=tutucu[t];
                    }

                }
                k++;
            }
            // printf("%c : %d  %c :  %d",dizi6[0],dizi5[0],dizi6[1],dizi5[1]);

            for(int u=1; u<=sinir; u++)
            {
                if(satir[i][4][0]==tutucuc[u])
                {
                    sprintf(simule[xx][yy],"%d.ns: ",tempns);
                    yy++;
                    simule[xx][yy][0]=tutucuc[u];
                    yy++;
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy++;
                    strcpy(simule[xx][yy],"->");
                    yy++;
                    tutucu[u]=orkapisi(dizi5,k);
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy=0;
                    xx++;
                    tempns=NULL;
                    // printf("\n%c : %d \n\n",tutucuc[u],tutucu[u]);
                }
            }

            k=0;
        }
    }
}

void xoroncesi()
{
    for(int i=3; i<8; i++)
    {
        if(strcmp(satir[i][2],"XOR")==0)
        {
            for(int j=5; j<5+atoi(satir[i][3]); j++)
            {
                dizi6[k]=satir[i][j][0];
                for(int t=1; t<=sinir; t++)
                {
                    if(dizi6[k]==tutucuc[t])
                    {
                        dizi5[k]=tutucu[t];
                    }

                }
                k++;
            }
            //  printf("%c : %d  %c :  %d",dizi6[0],dizi5[0],dizi6[1],dizi5[1]);

            for(int u=1; u<=sinir; u++)
            {

                if(satir[i][4][0]==tutucuc[u])
                {

                    sprintf(simule[xx][yy],"%d.ns: ",tempns);
                    yy++;
                    simule[xx][yy][0]=tutucuc[u];
                    yy++;
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy++;
                    strcpy(simule[xx][yy],"->");
                    yy++;
                    tutucu[u]=xorkapisi(dizi5,k);
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy=0;
                    xx++;
                    tempns=NULL;
                    //   printf("\n%c : %d\n\n",tutucuc[u],tutucu[u]);

                }
            }

            k=0;
        }

    }
}

void andoncesi()
{
    for(int i=3; i<8; i++)
    {
        if(strcmp(satir[i][2],"AND")==0)
        {
            for(int j=5; j<5+atoi(satir[i][3]); j++)
            {
                dizi6[k]=satir[i][j][0];
                for(int t=1; t<=sinir; t++)
                {
                    if(dizi6[k]==tutucuc[t])
                    {
                        dizi5[k]=tutucu[t];
                    }

                }
                k++;
            }
            //  printf("%c : %d  %c :  %d",dizi6[0],dizi5[0],dizi6[1],dizi5[1]);
            for(int u=1; u<=sinir; u++)
            {
                if(satir[i][4][0]==tutucuc[u])
                {
                    sprintf(simule[xx][yy],"%d.ns: ",tempns);
                    yy++;
                    simule[xx][yy][0]=tutucuc[u];
                    yy++;
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy++;
                    strcpy(simule[xx][yy],"->");
                    yy++;
                    tutucu[u]=andkapisi(dizi5,k);
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy=0;
                    xx++;
                    tempns=NULL;

                    //  printf("\n%c : %d \n\n",tutucuc[u],tutucu[u]);
                }
            }

            k=0;
        }
    }
}


void nandoncesi()
{

    for(int i=3; i<8; i++)
    {
        if(strcmp(satir[i][2],"NAND")==0)
        {
            for(int j=5; j<5+atoi(satir[i][3]); j++)
            {
                dizi6[k]=satir[i][j][0];
                for(int t=1; t<=sinir; t++)
                {
                    if(dizi6[k]==tutucuc[t])
                    {
                        dizi5[k]=tutucu[t];
                    }

                }
                k++;
            }
            // printf("%c : %d  %c :  %d",dizi6[0],dizi5[0],dizi6[1],dizi5[1]);

            for(int u=1; u<=sinir; u++)
            {
                if(satir[i][4][0]==tutucuc[u])
                {
                    sprintf(simule[xx][yy],"%d.ns: ",tempns);
                    yy++;
                    simule[xx][yy][0]=tutucuc[u];
                    yy++;
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy++;
                    strcpy(simule[xx][yy],"->");
                    yy++;
                    tutucu[u]=nandkapisi(dizi5,k);
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy=0;
                    xx++;
                    tempns=NULL;
                    // printf("\n%c : %d\n\n",tutucuc[u],tutucu[u]);
                }
            }

            k=0;
        }

    }

}

void notoncesi()
{
    for(int i=3; i<8; i++)
    {
        if(strcmp(satir[i][2],"NOT")==0)
        {
            for(int j=5; j<5+atoi(satir[i][3]); j++)
            {
                dizi6[k]=satir[i][j][0];
                for(int t=1; t<=sinir; t++)
                {
                    if(dizi6[k]==tutucuc[t])
                    {
                        dizi5[k]=tutucu[t];
                    }

                }
                k++;
            }
            // printf("%c : %d",dizi6[0],dizi5[0]);

            for(int u=1; u<=sinir; u++)
            {
                if(satir[i][4][0]==tutucuc[u])
                {
                    sprintf(simule[xx][yy],"%d.ns: ",tempns);
                    yy++;
                    simule[xx][yy][0]=tutucuc[u];
                    yy++;
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy++;
                    strcpy(simule[xx][yy],"->");
                    yy++;
                    tutucu[u]=notkapisi(dizi5,k);
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy=0;
                    xx++;
                    tempns=NULL;
                    //     printf("\n%c : %d \n\n",tutucuc[u],tutucu[u]);
                }
            }

            k=0;
        }

    }
}

void noroncesi()
{
    for(int i=1; i<8; i++)
    {
        if(strcmp(satir[i][2],"NOR")==0)
        {
            for(int j=5; j<5+atoi(satir[i][3]); j++)
            {
                dizi6[k]=satir[i][j][0];
                for(int t=1; t<=sinir; t++)
                {
                    if(dizi6[k]==tutucuc[t])
                    {
                        dizi5[k]=tutucu[t];
                    }

                }
                k++;
            }
            // printf("%c : %d  %c :  %d ",dizi6[0],dizi5[0],dizi6[1],dizi5[1]);

            for(int u=1; u<=sinir; u++)
            {
                if(satir[i][4][0]==tutucuc[u])
                {
                    sprintf(simule[xx][yy],"%d.ns: ",tempns);
                    yy++;
                    simule[xx][yy][0]=tutucuc[u];
                    yy++;
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy++;
                    strcpy(simule[xx][yy],"->");
                    yy++;
                    tutucu[u]=norkapisi(dizi5,k);
                    sprintf(simule[xx][yy],"%d",tutucu[u]);
                    yy=0;
                    xx++;
                    tempns=NULL;
                    //printf("\n%c :%d\n\n",tutucuc[u],tutucu[u]);
                }
            }

            k=0;
        }

    }
}


int andkapisi(int dizi[], int boyut)
{
    int cevap=dizi[0];
    for(int i=1; i<boyut; i++)
    {
        cevap=cevap&dizi[i];

    }
    return cevap;
}

int nandkapisi(int dizi[], int boyut)
{
    int cevap=dizi[0];
    for(int i=1; i<boyut; i++)
    {
        cevap=cevap&dizi[i];
    }
    if(cevap==1)
    {
        return 0;
    }
    else if(cevap==0)
    {
        return 1;
    }

}

int orkapisi(int dizi[],int boyut)
{
    int cevap=dizi[0];
    for(int i=1; i<boyut; i++)
    {
        cevap=cevap|dizi[i];

    }
    return cevap;

}

int norkapisi(int dizi[],int boyut)
{
    int cevap=dizi[0];
    for(int i=1; i<boyut; i++)
    {
        cevap=cevap|dizi[i];
    }
    if(cevap==1)
    {
        return 0;
    }
    else if(cevap==0)
    {
        return 1;
    }


}


int notkapisi(int dizi[], int boyut)
{
    if(dizi[0]==1)
        return 0;
    else if(dizi[0]==0)
        return 1;

}


int xorkapisi(int dizi[], int boyut)
{
    int cevap=dizi[0];
    for(int i=1; i<boyut; i++)
    {
        cevap=cevap^dizi[i];

    }
    return cevap;


}



void yukle()
{

    sira=1;
    int x=0;

    char c;
    long int len;
    while(1)
    {
        for(int j=1; j<10; j++)
        {
            fscanf(dosya,"%s",satir[sira][j]);
            printf("%s ",satir[sira][j]);
            if(strcmp(satir[sira][j],".son")==0)
            {
                x=1;
                break;
            }

            c = fgetc(dosya);
            len = ftell(dosya);
            if(c=='\n')
            {
                //fseek(dosya, len-1, SEEK_SET);
                printf("\n");
                break;
            }
        }
        if(x==1)
        {
            break;
        }
        sira++;
    }
    printf("\n");
    fseek(dosya, 0, SEEK_SET);
}


void yukle2()
{
    char c;
    sinir=0;
    int j,i;
    int x;
    long int len;
    for(j=1; j<20; j++)
    {

        fscanf(dosya2,"%s",satir2[1][j]);
        c = fgetc(dosya2);
        len = ftell(dosya2);
        //fseek(dosya2, len-1, SEEK_SET);
        if(c=='\0')
        {
            break;
        }
    }
    /*for(x=1;x<j;x++)
    {
        printf("%s",satir2[1][x]);

    }
    printf("\n");*/

    for(i=1; i<20; i++)
    {
        char *cevrilemeyen_kisim;
        // 10 -> onluk sayi tabanindan cevirdigimiz icin
        tutucu[i] = strtol(satir2[1][i], &cevrilemeyen_kisim, 10);
        tutucuc[i]=cevrilemeyen_kisim[0];
        if(tutucuc[i]==0)
        {
            sinir=i-1;
            break;

        }

        /*         printf("%ld\n", deger);
         *         printf("cevrilemeyen_kisim: %s\n", cevrilemeyen_kisim);
         */


    }
    //  printf("%d %c",tutucu[2],tutucuc[2]);
    for(i=1; i<=sinir; i++)
    {
        printf("%c : %d ",tutucuc[i],tutucu[i]);
    }
    printf("\n");
    fseek(dosya2, 0, SEEK_SET);
}



void Komut_Yukle()
{
    komut_dosya=fopen("komut.txt","r");
    sirak=1;
    int x=0;
    int j;
    char c;
    long int len;
    komuty=0;
    int ch = getc(komut_dosya);
    while(ch != EOF)
    {
        komuty++;
        for(j=1; j<10; j++)
        {

            if(j==1 && sirak==1)
                fseek(komut_dosya, 0, SEEK_SET);
            fscanf(komut_dosya,"%s",komutlar[sirak][j]);
            // printf("%s",komutlar[sirak][j]);
            if(strcmp(komutlar[sirak][j],"C")==0)
            {
                x=1;
                break;
            }


            c = fgetc(komut_dosya);
            len = ftell(komut_dosya);
            if(c=='\n')
            {
                fseek(komut_dosya, len-1, SEEK_SET);

                break;
            }
        }
        if(x==1)
            break;

        sirak++;
    }
    // komuty=j;
    for(int i=1; i<=sirak; i++)
    {
        for(int a=1; a<=komuty; a++)
        {
            //printf("%s  ",komutlar[i][a]);

        }
        //  printf("\n");
    }


}
void deger1()
{
    char ss[3];
    int sakal=0;
    int a=0;
    char harf;
    printf("Girmek istediginiz ucu giriniz, girisler bittiginde 0'i tuslayiniz.\n");
    while(1)
    {
tekrar:
        printf("1 yapmak istediginiz uc: ");
        a=0;
        scanf("%c",&harf);
        fflush(stdin);
        if(harf=='0')
        {
            break;
        }
        for(int i=2; i<20; i++)
        {
            if(harf==satir[1][i][0])
            {
                a=1;
                char gg[1];
                gg[0]=satir[1][i][0];
                ss[sakal]=satir[1][i][0];
                sakal++;
            }
        }
        if(a==0)
        {
            printf("Degeri degistiremezsiniz!!!\n");
            goto tekrar;
        }

        for(int i=1; i<=sinir; i++)
        {

            if(tutucuc[i]==harf)
            {

                yy++;
                strcpy(simule[xx][yy],"0.ns:");
                yy++;
                simule[xx][yy][0]=harf;
                yy++;
                sprintf(simule[xx][yy],"%d",tutucu[i]);
                yy++;
                strcpy(simule[xx][yy],"->");
                yy++;
                tutucu[i]=1;
                sprintf(simule[xx][yy],"%d",tutucu[i]);
                yy=0;
                xx++;



            }

        }

    }
    printf("\n");
    kapici();
    fwrite(ss, 1, sizeof(ss), log_komut);
    fwrite("\t", 1, sizeof("\t"), log_komut);
    fwrite(ss, 1, sizeof(ss), log_komut);
    fwrite(" girisi birlendi.",1, sizeof(" girisi birlendi."),log_komut);
}




void deger0()
{
    char ss[3];
    int sakal=0;
    int a=0;
    char harf;
    printf("Girmek istediginiz ucu giriniz, girisler bittiginde 0'i tuslayiniz.\n");
    while(1)
    {
tekrar1:
        printf("0 yapmak istediginiz uc: ");
        a=0;
        scanf("%c",&harf);
        fflush(stdin);
        if(harf=='0')
        {
            break;
        }
        for(int i=2; i<20; i++)
        {
            if(harf==satir[1][i][0])
            {
                a=1;
                char gg[1];
                gg[0]=satir[1][i][0];
                ss[sakal]=satir[1][i][0];
                sakal++;
            }
        }
        if(a==0)
        {
            printf("Degeri degistiremezsiniz!!!\n");
            goto tekrar1;
        }
        for(int i=1; i<=sinir; i++)
        {

            if(tutucuc[i]==harf)
            {
                yy++;
                strcpy(simule[xx][yy],"0.ns:");
                yy++;
                simule[xx][yy][0]=harf;
                yy++;
                sprintf(simule[xx][yy],"%d",tutucu[i]);
                yy++;
                strcpy(simule[xx][yy],"->");
                yy++;
                tutucu[i]=0;
                sprintf(simule[xx][yy],"%d",tutucu[i]);
                yy=0;
                xx++;


            }

        }

    }
    //islem();
    kapici();
    fwrite(ss, 1, sizeof(ss), log_komut);
    fwrite("\t", 1, sizeof("\t"), log_komut);
    fwrite(ss, 1, sizeof(ss), log_komut);
    fwrite(" girisi sifirlandi.",1, sizeof(" girisi sifirlandi."),log_komut);
}


void tektekyazdirma()
{
    char harf;
    printf("Girmek istediginiz ucu giriniz, girisler bittiginde 0'i tuslayiniz.\n");
    while(1)
    {
        printf("Yazdirmak istediginiz uc: ");
        scanf("%c",&harf);
        fflush(stdin);
        if(harf=='0')
        {
            break;
        }
        for(int i=1; i<=sinir; i++)
        {

            if(tutucuc[i]==harf)
            {
                char gg[1];
                char ss[1];

                gg[0]=tutucuc[i];
                fwrite(gg, 1, sizeof(gg), log_komut);
                fwrite(":", 1, sizeof(char), log_komut);
                sprintf(ss,"%d", tutucu[i]);
                fwrite(ss, 1, sizeof(ss), log_komut );
                fwrite(" ", 1, sizeof(char), log_komut );
                printf("%d\n",tutucu[i]);


            }

        }

    }
    fwrite("\t\t", 1, sizeof("\t\t"), log_komut );
}


void topluyazdirma()
{
    for(int i=1; i<=sinir; i++)
    {
        printf("%c:%d ",tutucuc[i],tutucu[i]);
        char ss[2];
        ss[1]=NULL;
        char ss3[1];
        ss[0]=tutucuc[i];

        fwrite(ss,1,sizeof(ss),log_komut);
        fwrite(":",1, sizeof(char), log_komut);
        sprintf(ss3, "%d", tutucu[i]);
        fwrite(ss3,1,sizeof(char),log_komut);
        fwrite(" ",1,sizeof(" "),log_komut);

    }
    printf("\n");
}

void simuleyazdir()
{
    printf("\n");

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%s ",simule[i][j]);
            if(i==0&&j==1)
            {
                fwrite(simule[i][j], 1, sizeof(sizeof(char)*3), log_komut);
            }
            if(i==0&&j!=1)
            {
                fwrite(simule[i][j], 1, sizeof(sizeof(char)*2), log_komut);
            }
            /* if(i==0&&j==1)
             {
                  fwrite(simule[i][j], 1, sizeof(sizeof(char)*3), log_komut);
             }*/
            if(j==0)
            {
                fwrite(simule[i][j], 1, sizeof(sizeof(char)*3), log_komut);
            }
            else if(i!=0)
            {

                fwrite(simule[i][j], 1, sizeof(sizeof(char)*2), log_komut);
            }


        }
        printf("\n");
    }

    xx=0;
    yy=0;
}


void fkomut()
{
    char zaman[26];
    time_t simdiki_zaman ;
    Komut_Yukle();
    for(int i=1; i<=sirak; i++)
    {
        char gonderme[25];

        if(strcmp(komutlar[i][1],"Y")==0 || strcmp(komutlar[i][1],"y")==0)
        {
            simdiki_zaman = time (NULL);
            fwrite("Y\t", 1, sizeof("Y"), log_komut );
            fwrite("devre.txt yuklendi\t", 1, sizeof("devre.txt yuklendi"), log_komut );
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            fscanf(dosya,"%s",gonderme);
            //gonderme[0]=fgetc(dosya);
            fseek(dosya, 0, SEEK_SET);
            //printf("%c",gonderme[0]);
            if(strcmp(gonderme,".include")==0)
            {
                yukle_include();
            }
            else
                yukle();
        }
        if(strcmp(komutlar[i][1],"I")==0 || strcmp(komutlar[i][1],"i")==0)
        {
            simdiki_zaman = time (NULL);
            fwrite("I\t", 1, sizeof("I"), log_komut );
            fwrite("degerler atandi\t\t", 1, sizeof("degerler atandi\t"), log_komut );
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            yukle2();
        }
        if(strcmp(komutlar[i][1],"C")==0 || strcmp(komutlar[i][1],"c")==0 )
        {
            fwrite("C ", 1, sizeof("c "), log_komut );
            fwrite("\t", 1, sizeof("\t"), log_komut );
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            exit(1);
        }
        if(strcmp(komutlar[i][1],"G*")==0 || strcmp(komutlar[i][1],"g*")==0 )
        {
            fwrite("G*", 1, sizeof("G*"), log_komut );
            topluyazdirma();
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
        }
        if(strcmp(komutlar[i][1],"S")==0 || strcmp(komutlar[i][1],"s")==0 )
        {
            fwrite("S ", 1, sizeof("S "), log_komut );
            simuleyazdir();
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );

        }
        if(strcmp(komutlar[i][1],"g")==0 || strcmp(komutlar[i][1],"G")==0)
        {
            fwrite("G ", 1, sizeof("G "), log_komut );

            for(int k = 0; k<=5; k++)
            {

                for(int o=1; o<=sinir; o++)
                {

                    if(tutucuc[o]==komutlar[i][2][k])
                    {
                        char gg[1];
                        char ss[1];

                        gg[0]=tutucuc[o];
                        fwrite(gg, 1, sizeof(gg), log_komut);
                        fwrite(":", 1, sizeof(char), log_komut);
                        sprintf(ss,"%d", tutucu[o]);
                        fwrite(ss, 1, sizeof(ss), log_komut );
                        fwrite(" ", 1, sizeof(char), log_komut );
                        printf("%c:%d\n",tutucuc[o],tutucu[o]);


                    }

                }
            }

            fwrite("\t\t", 1, sizeof("\t\t"), log_komut );
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
        }


        if(strcmp(komutlar[i][1],"h")==0 || strcmp(komutlar[i][1],"H")==0)
        {
            fwrite("H ", 1, sizeof("H "), log_komut );

            char ss[3];
            int sakal=0;
            for(int k=0; k<=3; k++)
            {
                int a=0;
                for(int p=2; p<20; p++)
                {
                    if(komutlar[i][2][k]==satir[1][p][0])
                    {
                        a=1;
                        char gg[1];
                        gg[0]=satir[1][p][0];
                        ss[sakal]=satir[1][p][0];
                        sakal++;
                    }
                }
                if(a==0)
                {
                    printf("Degeri degistiremezsiniz!!!\n");
                }

                for(int p=1; p<=sinir; p++)
                {

                    if(tutucuc[p]==komutlar[i][2][k])
                    {
                        yy++;
                        strcpy(simule[xx][yy],"0.ns:");
                        yy++;
                        simule[xx][yy][0]=komutlar[i][2][k];
                        yy++;
                        sprintf(simule[xx][yy],"%d",tutucu[p]);
                        yy++;
                        strcpy(simule[xx][yy],"->");
                        yy++;
                        tutucu[p]=1;
                        sprintf(simule[xx][yy],"%d",tutucu[p]);
                        yy=0;
                        xx++;



                    }

                }

            }
            printf("\n");
            // kapilari_bulma(gonderme);
            //islem();
            kapici();
            fwrite(ss, 1, sizeof(ss), log_komut);

            fwrite("\t", 1, sizeof("\t"), log_komut);
            fwrite(ss, 1, sizeof(ss), log_komut);
            fwrite(" girisi birlendi.",1, sizeof(" girisi birlendi."),log_komut);
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
        }

        if(strcmp(komutlar[i][1],"l")==0 || strcmp(komutlar[i][1],"L")==0)
        {
            fwrite("L ", 1, sizeof("L "), log_komut );

            char ss[3];
            int sakal=0;
            for(int k=0; k<=3; k++)
            {
                int a=0;
                for(int o=2; o<20; o++)
                {
                    if(komutlar[i][2][k]==satir[1][o][0])
                    {
                        a=1;
                        char gg[1];
                        gg[0]=satir[1][o][0];
                        ss[sakal]=satir[1][o][0];
                        sakal++;
                    }
                }
                if(a==0)
                {
                    printf("Degeri degistiremezsiniz!!!\n");
                }
                for(int o=1; o<=sinir; o++)
                {

                    if(tutucuc[o]==komutlar[i][2][k])
                    {
                        int kk=0;
                        yy++;
                        strcpy(simule[xx][yy],"0.ns:");
                        yy++;
                        simule[xx][yy][0]=komutlar[i][2][k];
                        yy++;
                        sprintf(simule[xx][yy],"%d",tutucu[o]);
                        yy++;
                        strcpy(simule[xx][yy],"->");
                        yy++;
                        tutucu[o]=0;
                        sprintf(simule[xx][yy],"%d",tutucu[o]);
                        yy=0;
                        xx++;
                        printf("ooooorro");

                    }

                }
            }
            //islem();
            kapici();
            fwrite(ss, 1, sizeof(ss), log_komut);
            fwrite("\t", 1, sizeof("\t"), log_komut);
            fwrite(ss, 1, sizeof(ss), log_komut);
            fwrite(" girisi sifirlandi.",1, sizeof(" girisi sifirlandi."),log_komut);
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
        }
    }


}


void yukle_include()
{
    dosya3 = fopen("baska_dosya.txt","r");
    int y1;
    int diger_y;
    int no1=1;
    int no2=1;
    int x=0;
    int x2=0;
    char c;
    char c2;
    long int len;
    long int len2;
    while(1)
    {
        for(int j=1; j<10; j++)
        {
            fscanf(dosya,"%s",include[no1][j]);
            if(strcmp(include[no1][j],".son")==0)
            {
                x=1;
                break;
            }

            c = fgetc(dosya);
            len = ftell(dosya);

            if(c=='\n')
            {
                if(no1==2)
                    y1=j;
                //fseek(dosya, len-1, SEEK_SET);
                break;
            }
        }
        if(x==1)
        {

            break;
        }
        no1++;

    }

    while(1)
    {
        for(int j=1; j<10; j++)
        {
            fscanf(dosya3,"%s",diger_dosya[no2][j]);
            // printf("%s",diger_dosya[no2][j]);
            if(strcmp(diger_dosya[no2][j],".son")==0)
            {
                x2=1;
                break;
            }

            c2 = fgetc(dosya3);
            len2 = ftell(dosya3);

            if(c2=='\n')
            {
                if(no2==1)
                    diger_y=j;
                //fseek(dosya, len-1, SEEK_SET);
                break;
            }
        }
        if(x2==1)
        {
            break;
        }
        no2++;

    }
    for(int i=2; i<=no1-1; i++)
    {
        for(int j=1; j<=10; j++)
        {
            strcpy(satir[i][j],include[i][j]);
            // printf("%s ",satir[i][j]);
        }
        //printf("\n");
    }
    for(int i=2; i<=no1-1; i++)
    {
        for(int j=1; j<=10; j++)
        {
            strcpy(satir[i-1][j],satir[i][j]);

        }
        // printf("\n");
    }

    int kontrol=0;
    // printf("\n");
    //printf("\n");
    for(int i=1; i<=no2; i++)
    {
        for(int j=1; j<=10; j++)
        {
            //strcpy(satir2[i][j],diger_dosya[i][j]);
            // printf("%s ",diger_dosya[i][j]);
        }
        //  printf("\n");
        kontrol++;
    }
    fseek(dosya, 0, SEEK_SET);
    fseek(dosya2, 0, SEEK_SET);

    for(int i=1; i<=5; i++)
    {
        if(strcmp(diger_dosya[i][1],".kapi")==0)
        {
            for(int j=1; j<8; j++)
            {
                strcpy(satir[kontrol+1][j],diger_dosya[i][j]);
            }
        }
    }

    int t=y1+1;
    for(int j=2; j<diger_y; j++)
    {
        strcpy(satir[1][t],diger_dosya[1][j]);
        t++;
    }
    for(int i=2; i<y1+diger_y; i++)
    {
        for(int j=2; j<y1+diger_y; j++)
        {
            if(i==j)
                continue;
            if(strcmp(satir[1][i],satir[1][j])==0)
            {
                strcpy(satir[1][j],satir[1][j+1]);
            }

        }

    }

    // printf("\n\n");
    for(int i=1; i<10; i++)
    {
        for(int j=1; j<10; j++)
        {

            printf("%s  ",satir[i][j]);
        }
        printf("\n");
    }




//fclose(dosya);
// dosya= fopen("devre.txt","w");

}

int main()
{
    char gonderme[5];

    time_t simdiki_zaman ;
    char sistek[15];
    char istek;
    dosya = fopen("devre.txt","r");
    dosya2 = fopen("deger.txt","r");
    log_komut=fopen("log_komut.txt","w");
    char zaman[26];
    while(1)
    {
        printf(">");
        scanf("%s",sistek);
        fflush(stdin);
        istek=sistek[0];
        switch(istek)
        {

        case('y'):
        case('Y'):
            simdiki_zaman = time (NULL);
            fwrite("Y\t", 1, sizeof("Y"), log_komut );
            fwrite("devre.txt yuklendi\t", 1, sizeof("devre.txt yuklendi"), log_komut );
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            fscanf(dosya,"%s",gonderme);
            //gonderme[0]=fgetc(dosya);
            fseek(dosya, 0, SEEK_SET);
            //printf("%c",gonderme[0]);
            if(strcmp(gonderme,".include")==0)
            {
                yukle_include();
            }
            else
                yukle();
            break;

        case('I'):
        case('i'):
            simdiki_zaman = time (NULL);
            fwrite("I\t", 1, sizeof("I"), log_komut );
            fwrite("degerler atandi\t\t", 1, sizeof("degerler atandi\t"), log_komut );
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            yukle2();
            break;

        case('h'):
        case('H'):
            fwrite("H ", 1, sizeof("H "), log_komut );
            deger1();
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            break;

        case('l'):
        case('L'):
            fwrite("L ", 1, sizeof("L "), log_komut );
            deger0();
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            break;

        case('s'):
        case('S'):
            fwrite("S ", 1, sizeof("S "), log_komut );
            simuleyazdir();
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );

            break;

        case ('k'):
        case ('K'):
            fkomut();

            break;

        case ('c'):
        case ('C'):
            fwrite("C ", 1, sizeof("c "), log_komut );
            fwrite("\t", 1, sizeof("\t"), log_komut );
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
            exit(1);
            break;



        }
        if(strcmp(sistek,"g")==0 || strcmp(sistek,"G")==0)
        {
            fwrite("G ", 1, sizeof("G "), log_komut );
            fwrite("\t", 1, sizeof("\t"), log_komut );
            tektekyazdirma();
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );

        }
        if(strcmp(sistek,"g*")==0 || strcmp(sistek,"G*")==0)
        {
            fwrite("G*", 1, sizeof("G*"), log_komut );
            topluyazdirma();
            simdiki_zaman = time (NULL);
            strcpy(zaman,ctime(&simdiki_zaman ));
            fwrite(zaman, 1, sizeof(zaman), log_komut );
            fwrite("\n", 1, sizeof(char), log_komut );
        }

    }

}
