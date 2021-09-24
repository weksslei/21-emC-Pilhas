/*   JOGO 21 UTILIZANDO PILHA
Considerações:   
                 Jogadores: Usuario X Máquina;
                 Vence quem somar 21 pontos com cartas em maos primeiro;
                       criterio para jogada da máquina:
                                se a soma dos pontos for >=19 && <=21 a maquina para de comprar
                       criterio de desempate:
                                cada jogador recebe uma carta e a de maior valor vence.         
                                
                 A carta Az corresponde a 1 ponto;
                 As cartas figuras correspondem ao valor de 10 pontos;
                 As demais cartas correspondem ao valor impresso na própria carta;
Estratégias:
                 Embaralhar;
                 Distribuir duas cartas para cada jogador;
                 Soma as cartas em maos dos jogadores;
                 Decidir se compra mais uma carta da pilha ou nao;
                 Se comprar, somar a carta ao montante em maos e apresentar resultado;
                 
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void delay(int tempo_de_parada)
{
     _sleep(tempo_de_parada);
}

void cor(int cor_letra)
{
     HANDLE hOut;
     hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hOut, cor_letra);
}

void gotoxy(int x, int y) 
{
  COORD c;
  c.X = y - 1;
  c.Y = x - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//"	ALT+3 ? coracao
//"	ALT+4 ? ouro
//"	ALT+5 ? pinto
//"	ALT+6 ? espadas

void desenha_carta(int x,char naipe,int l,int c)
{
     gotoxy(l,c);
     if(x==1)
     {
     printf("%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,191);
     gotoxy(l+1,c);
     printf("%c%c%c    %c",179,65,naipe,179);
     gotoxy(l+2,c);
     printf("%c      %c",179,179);
     gotoxy(l+3,c);
     printf("%c  %c   %c",179,naipe,179);
     gotoxy(l+4,c);
     printf("%c      %c",179,179);
     gotoxy(l+5,c);
     printf("%c    %c%c%c",179,65,naipe,179);
     gotoxy(l+6,c);
     printf("%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,217);
     }
     if(x>1 && x<10)
     {
     printf("%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,191);
     gotoxy(l+1,c);
     printf("%c%d%c    %c",179,x,naipe,179);
     gotoxy(l+2,c);
     printf("%c      %c",179,179);
     gotoxy(l+3,c);
     printf("%c  %c   %c",179,naipe,179);
     gotoxy(l+4,c);
     printf("%c      %c",179,179);
     gotoxy(l+5,c);
     printf("%c    %d%c%c",179,x,naipe,179);
     gotoxy(l+6,c);
     printf("%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,217);
     }
     if(x==10)
     {
     printf("%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,191);
     gotoxy(l+1,c);
     printf("%c%d%c   %c",179,x,naipe,179);
     gotoxy(l+2,c);
     printf("%c      %c",179,179);
     gotoxy(l+3,c);
     printf("%c  %c   %c",179,naipe,179);
     gotoxy(l+4,c);
     printf("%c      %c",179,179);
     gotoxy(l+5,c);
     printf("%c   %d%c%c",179,x,naipe,179);
     gotoxy(l+6,c);
     printf("%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,217);
     }
     if(x==11)
     {
     printf("%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,191);
     gotoxy(l+1,c);
     printf("%c%c%c    %c",179,74,naipe,179);
     gotoxy(l+2,c);
     printf("%c      %c",179,179);
     gotoxy(l+3,c);
     printf("%c  %c   %c",179,naipe,179);
     gotoxy(l+4,c);
     printf("%c      %c",179,179);
     gotoxy(l+5,c);
     printf("%c    %c%c%c",179,74,naipe,179);
     gotoxy(l+6,c);
     printf("%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,217);
     }
     if(x==12)
     {
     printf("%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,191);
     gotoxy(l+1,c);
     printf("%c%c%c    %c",179,81,naipe,179);
     gotoxy(l+2,c);
     printf("%c      %c",179,179);
     gotoxy(l+3,c);
     printf("%c  %c   %c",179,naipe,179);
     gotoxy(l+4,c);
     printf("%c      %c",179,179);
     gotoxy(l+5,c);
     printf("%c    %c%c%c",179,81,naipe,179);
     gotoxy(l+6,c);
     printf("%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,217);
     }
     if(x==13)
     {
     printf("%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,191);
     gotoxy(l+1,c);
     printf("%c%c%c    %c",179,75,naipe,179);
     gotoxy(l+2,c);
     printf("%c      %c",179,179);
     gotoxy(l+3,c);
     printf("%c  %c   %c",179,naipe,179);
     gotoxy(l+4,c);
     printf("%c      %c",179,179);
     gotoxy(l+5,c);
     printf("%c    %c%c%c",179,75,naipe,179);
     gotoxy(l+6,c);
     printf("%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,217);
     }
}

typedef struct baralho
{
        int valor;
        int naipe;
}baralho;

typedef struct celula *indicador;

typedef struct celula
{
        baralho carta;
        indicador prox;
} celula;

typedef struct pilha
{
        indicador topo,fundo;
} pilha;
       
void fpvazia(pilha *p)
{
     p->topo = (indicador) malloc (sizeof(celula));
     p->fundo=p->topo;
     p->topo->prox=NULL;
}

int vazia(pilha p)
{
    return(p.topo==p.fundo);
}

void inserir(baralho c,pilha *p)  //empilhar itens
{
	indicador aux;
    aux=(indicador) malloc(sizeof(celula));
	p->topo->carta=c;
	aux->prox=p->topo;
	p->topo=aux;	
}

// funcao criar pilha com 52 cartas já inseridas
void criar_baralho(pilha *p)
{
     baralho b;
     for(int x=3;x<7;x++)  // seleçao naipe
          {
          for(int j=1;j<14;j++)  // cartas de A a K
                  {
                  b.valor=j;
                  b.naipe=x;
                  inserir(b,p);
                  }          
          }
}

void desempilha(pilha *p,baralho *item) // desempilha 1 carta do topo do baralho
{
     indicador aux;
     if(p->topo==p->fundo)
     {
          printf(" A pilha esta vazia. . .");
          return;
     }
     aux=p->topo;
     p->topo=aux->prox;
     *item=aux->prox->carta;
     free(aux);
}


void embaralha(pilha *p1,pilha *p2,pilha *p3,pilha *p4,pilha *p5,pilha *p6,pilha *p7)
{
     baralho ret1,ret2,ret3,ret4,ret5,ret6; // carta retirada
     while(p1->topo!=p1->fundo)
     {
         desempilha(p1,&ret1);
         inserir(ret1,p2);
         if((p1->topo!=p1->fundo))
         {
              desempilha(p1,&ret2);
              inserir(ret2,p3);
         }
         if((p1->topo!=p1->fundo))
         {
              desempilha(p1,&ret3);
              inserir(ret3,p4);
         }
         if((p1->topo!=p1->fundo))
         {
              desempilha(p1,&ret4);
              inserir(ret4,p5);
         }
         if((p1->topo!=p1->fundo))
         {
              desempilha(p1,&ret5);
              inserir(ret5,p6);
         }
         if((p1->topo!=p1->fundo))
         {
              desempilha(p1,&ret6);
              inserir(ret6,p7);
         }
     }
     baralho rt1,rt2,rt3,rt4,rt5,rt6;
     while(p7->topo!=p7->fundo) // insere itens de p7 em p1
     {
         desempilha(p7,&rt6);
         inserir(rt6,p1);
     }
     while(p4->topo!=p4->fundo) // insere itens de p4 em p1
     {
         desempilha(p4,&rt3);
         inserir(rt3,p1);
     }
     while(p2->topo!=p2->fundo) // insere itens de p2 em p1
     {
         desempilha(p2,&rt1);
         inserir(rt1,p1);
     }
     while(p5->topo!=p5->fundo) // insere itens de p5 em p1
     {
         desempilha(p5,&rt4);
         inserir(rt4,p1);
     }
     while(p3->topo!=p3->fundo) // insere itens de p3 em p1
     {
         desempilha(p3,&rt2);
         inserir(rt2,p1);
     }
     while(p6->topo!=p6->fundo) // insere itens de p6 em p1
     {
         desempilha(p6,&rt5);
         inserir(rt5,p1);
     }
}

void mostra_cartas_maquina(pilha maquina)
{
     int lm,cm;
     lm=5;
     cm=30;
     indicador aux;
     aux=maquina.topo->prox;
     while(aux!=NULL)
     {
          desenha_carta(aux->carta.valor,aux->carta.naipe,lm,cm);
          aux=aux->prox;
          cm=cm+8;
     }
     
}


void d_costas(int lm,int cm)
{
        gotoxy(lm,cm);
        printf("%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,191);
        gotoxy(lm+1,cm);
        printf("%c      %c",179,179);
        gotoxy(lm+2,cm);
        printf("%c      %c",179,179);
        gotoxy(lm+3,cm);
        printf("%c      %c",179,179);
        gotoxy(lm+4,cm);
        printf("%c      %c",179,179);
        gotoxy(lm+5,cm);
        printf("%c      %c",179,179);
        gotoxy(lm+6,cm);
        printf("%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,217);
        for(int z=lm+1;z<11;z++)
        { 
               for(int x=cm+1;x<cm+7;x++)
               {
                      gotoxy(z,x);
                      printf("%c",254);
               }
        }  
}


void distribuir(pilha *p1, pilha *maquina, pilha *jogador) // dar cartas aos jogadores
{
     baralho it; //it = carta retirada da pilha matriz para distribuir entre os jogadores
     int lm,cm;
     lm=5;
     cm=30;
     int lj,cj;
     lj=15;
     cj=30;
     for(int i=0;i<2;i++)
     {
          desempilha(p1,&it);
          inserir(it,maquina);
          gotoxy(8,18);
          printf("Maquina => ");
//          desenha_carta(maquina->topo->prox->carta.valor,maquina->topo->prox->carta.naipe,lm,cm);
          d_costas(lm,cm);  
          cm=cm+8;
          desempilha(p1,&it);
          inserir(it,jogador);
          gotoxy(18,18);
          printf("Jogador => ");
          desenha_carta(jogador->topo->prox->carta.valor,jogador->topo->prox->carta.naipe,lj,cj);   
          cj=cj+8;
     }     
}


int soma(pilha s )
{
    indicador aux;
    aux=s.topo->prox;
    int cont=0;
    while(aux!=NULL)
    {
         if(aux->carta.valor > 10)
              cont=cont+10;
            else
              cont=cont+aux->carta.valor;
         aux=aux->prox;
    }
    return cont;
}


void tela1()
{
     int l,c;
     c=3;
     for(l=22;l>12;l--)
     {
          gotoxy(l-6,c);            
          printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
          gotoxy(l-5,c);            
          printf("%c            %c",179,179);
          gotoxy(l-4,c);            
          printf("%c            %c",179,179);
          gotoxy(l-3,c);            
          printf("%c            %c",179,179);
          gotoxy(l-2,c);            
          printf("%c            %c",179,179);
          gotoxy(l-1,c);            
          printf("%c            %c",179,179);
          gotoxy(l,c);            
          printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
     }
     for(l=21;l>12;l--)
     { 
          gotoxy(l,c);
          printf("%c",195);
          gotoxy(l,c+13);
          printf("%c",180);
     }  
     for(l=12;l>7;l--)
     { 
          for(int col=c+1;col<c+13;col++)
          {
                gotoxy(l,col);
                printf("%c",254);
          }
     }  
}


void telao21(int p){

//system("cls");
int n;
for(int i=2;i>7;i++)
{
 

gotoxy(p,p);
printf("       %c%c%c                %c%c",n,n,n,n,n);
gotoxy(p+1,p);
printf("      %c%c%c%c%c             %c%c%c%c",n,n,n,n,n,n,n,n,n);
gotoxy(p+2,p);
printf("    %c%c    %c%c          %c%c%c %c%c",n,n,n,n,n,n,n,n,n);
gotoxy(p+3,p);
printf("   %c%c      %c%c        %c%c   %c%c",n,n,n,n,n,n,n,n);
gotoxy(p+4,p);
printf("   %c%c      %c%c       %c%c    %c%c",n,n,n,n,n,n,n,n);
gotoxy(p+5,p);
printf("           %c%c             %c%c",n,n,n,n);
gotoxy(p+6,p);
printf("          %c%c              %c%c",n,n,n,n);
gotoxy(p+7,p);
printf("        %c%c                %c%c",n,n,n,n);
gotoxy(p+8,p);
printf("       %c%c                 %c%c",n,n,n,n);
gotoxy(p+9,p);
printf("     %c%c                   %c%c",n,n,n,n);
gotoxy(p+10,p);
printf("   %c%c                     %c%c",n,n,n,n);
gotoxy(p+11,p);
printf("  %c%c%c%c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c",n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n);
gotoxy(p+12,p); 
printf("  %c%c%c%c%c%c%c%c%c%c%c          %c%c%c%c%c%c%c",n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n);
n=i;
delay(300);
}

}

void regras()
{ 
   cor(2);
   system ("cls");
   gotoxy(2,35);
   printf("Jogo 21 !!!");
   gotoxy(5,3);
   printf("O Objetivo do jogo %c fazer vinte e um pontos ou chegar o mais pr%cximo disso",130,162);
   gotoxy(6,3);
   printf("sem ultrapassar a soma de 21 pontos.");
   gotoxy(8,3);
   printf("Voc%c receber%c duas cartas e ter%c o direito de comprar o quanto achar neces-",136,160,160);
   gotoxy(9,3);
   printf("s%crio.",160);
   gotoxy(10,3);
   printf("A soma das suas cartas ser%co os seus pontos.",198);
   gotoxy(12,3);
   printf("Em caso de empate o sistema sortear%c uma carta para voc%c e uma para a m%cquina",160,136,160);
   gotoxy(14,3);
   printf("sendo que, quem retirar a carta de maior valor vence.");
   gotoxy(16,3);
   printf("As cartas J,Q e K valem dez pontos, as cartas A valem um ponto,");
   gotoxy(18,3);
   printf("e o restante dos pontos ser%co contados conforme sua numera%c%co.",198,135,198);
   gotoxy(21,3);
   printf("Preparado para jogar?");
   gotoxy(23,30);
   system ("pause");
}

pilha pi1;  // pilha matriz do baralho
pilha pi2,pi3,pi4,pi5,pi6,pi7;  // pilhas auxiliares utilizadas para embaralhar as cartas
pilha pm,pj; // pilha da maquina e do jogador
int tipo,K_cor=9;
int soma_m=0,soma_j=0;
int z,sorteio; //variavel para embaralhar
baralho c1,dm,dj;
char resp,resp2;
int pl_j=0;
int pl_m=0;
    
int main()
{
    for(z=1;z<15;z++)
    {
        cor(z);
        telao21(z);
        delay(300);
    }
    regras();
    do {
    system("cls");
    cor(K_cor);
    fpvazia(&pi1); fpvazia(&pi2); fpvazia(&pi3); fpvazia(&pi4); fpvazia(&pm); fpvazia(&pj);
    fpvazia(&pi5),fpvazia(&pi6),fpvazia(&pi7);
    criar_baralho(&pi1);  // pilha matriz
    srand( (unsigned)time(NULL) );
    sorteio = rand()%3 *(1 + ( rand() % 10 ));   // sorteia numero para embaralhar
    for(int j=0;j<sorteio;j++)
    { 
        embaralha(&pi1,&pi2,&pi3,&pi4,&pi5,&pi6,&pi7);
    }
    tela1();
    distribuir(&pi1, &pm, &pj);
    int quemjoga=1;
    int cj=46,cm=46;
    int lm=5;
    do {
		if ( quemjoga )
		{
            if ( soma(pj) > 21 )
                { break; }
            gotoxy(23,20);
            printf("Deseja retirar mais uma carta? <1> - SIM  <2> - NAO : ");
            fflush(stdin);
            scanf("%c",&resp);
            if(resp=='1')
            {
                 desempilha(&pi1,&c1);     //  tirar carta jogador
                 inserir(c1,&pj);
                 desenha_carta(pj.topo->prox->carta.valor,pj.topo->prox->carta.naipe,15,cj);   
                 cj=cj+8;
            }
    		quemjoga = 0;
        }
		else //if (!quemjoga)
		{
            if(soma(pm)<18)
            {
                  desempilha(&pi1,&c1);  // tirar mais uma carta para maquina
                  inserir(c1,&pm);
                  
                  d_costas(lm,cm);
                  cm=cm+8; 
            }
            quemjoga = 1;
        }
    } while(  (resp!='2') ); //&& (soma(pm)<18)
    soma_m=soma(pm);
    soma_j=soma(pj);
    gotoxy(23,20);
    if((soma_j>21) && (soma_m>21))// os 2 estorarem
    {
          printf("Nao houve ganhador !                                                ");
          mostra_cartas_maquina(pm);
    }
   else
    if((soma_j<22) && (soma_m>21))// maquina estorar
    {
          printf(" O jogador venceu!!!                                                   ");
          mostra_cartas_maquina(pm);
          pl_j++;
    }
   else
    if((soma_j>21 && soma_m<22))// jogador estorar
    {
          printf(" A Maquina venceu!!!                                                      ");
          mostra_cartas_maquina(pm);
          pl_m++;
    }
   else
    if(  (( soma_j<22) && (soma_m<22)) ) // menor que 22 para dos 2
    {
          if( soma_j > soma_m )
          {
              printf(" O jogador venceu!!!                                    ");
              mostra_cartas_maquina(pm);
              pl_j++;
          }
         else
          if( soma_j < soma_m )
          {
              printf(" A maquina venceu!!!                                    ");
              mostra_cartas_maquina(pm);
              pl_m++;
          }
         else
          {
              mostra_cartas_maquina(pm);
              gotoxy(23,15);
              printf(" O jogo esta empatado!!! Pressione <ENTER> para desenpatar. . .");
              getch();
              do{
                    srand( (unsigned)time(NULL) );
                    sorteio = rand()%3 *(1 + ( rand() % 10 ));   // sorteia numero para embaralhar
                    for(int j=0;j<sorteio;j++)
                    { 
                          embaralha(&pi1,&pi2,&pi3,&pi4,&pi5,&pi6,&pi7);
                    }
                    desempilha(&pi1,&dm);  // tirar mais uma carta para maquina
                    inserir(dm,&pm);
                    desenha_carta(pm.topo->prox->carta.valor,pm.topo->prox->carta.naipe,5,cm);
                    cm=cm+8;
                    desempilha(&pi1,&dj);     //  tirar carta jogador
                    inserir(dj,&pj);
                    desenha_carta(pj.topo->prox->carta.valor,pj.topo->prox->carta.naipe,15,cj);   
                    cj=cj+8;
              }while(dm.valor == dj.valor);
              gotoxy(23,15);
              if(dj.valor>dm.valor)
              {
                     printf("       O jogador venceu!!!                                                ");
                     pl_j++;
              }
             else
              {
                     printf("       A Maquina venceu!!!                                                ");
                     pl_m++;
              }
          }
    }
    getch();
    gotoxy(23,20);
    printf("Deseja jogar novamente? <1> - SIM  <ENTER> - NAO => ");
    fflush(stdin);
    scanf("%c",&resp2);
    K_cor++;
    if( K_cor == 15)
    {  K_cor= (15%2) ;  }
} while( resp2 == '1' );
     
     cor(55);
     for(z=10;z<21;z++)
     {
         for(int c=15;c<61;c++)
         {
             gotoxy(z,c);
             printf(" ");
         }
     }
     for(z=15;z<61;z++)
     {
         gotoxy(10,z);
         printf("%c",205);
         gotoxy(20,z);
         printf("%c",205);
     }
     for(z=10;z<21;z++)
     {
         gotoxy(z,15);
         printf("%c",186);
         gotoxy(z,60);
         printf("%c",186);
     }
     gotoxy(10,15);
     printf("%c",201);
     gotoxy(10,60);
     printf("%c",187);
     gotoxy(20,15);
     printf("%c",200);
     gotoxy(20,60);
     printf("%c",188);
     
     gotoxy(10,20);
     printf("<<   Placar do jogo:   >>");
     gotoxy(13,30);
     printf("Jogador => %d",pl_j);
     gotoxy(16,30);
     printf("Maquina => %d",pl_m);
     gotoxy(20,20);
     system("pause");
     
     for(z=1;z<13;z++)
     {
        cor(z);
        telao21(z);
        delay(300);
     }
     for(z=30;z>0;z--)
     {
        cor(z);
        telao21(z);
        delay(150);
     }
     
}
