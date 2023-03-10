#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <SDL/SDL.h>
#include "./presentation/presentation.h"

#define VIDE        		0
#define DKJR       		1
#define CROCO       		2
#define CORBEAU     		3
#define CLE 			4

#define AUCUN_EVENEMENT    	0

#define LIBRE_BAS		1
#define LIANE_BAS		2
#define DOUBLE_LIANE_BAS	3
#define LIBRE_HAUT		4
#define LIANE_HAUT		5

void* FctThreadEvenements(void *);
void* FctThreadCle(void *);
void* FctThreadDK(void *);
void* FctThreadDKJr(void *);
void* FctThreadScore(void *);
void* FctThreadEnnemis(void *);
void* FctThreadCorbeau(void *);
void* FctThreadCroco(void *);

void initGrilleJeu();
void setGrilleJeu(int l, int c, int type = VIDE, pthread_t tid = 0);
void afficherGrilleJeu();

void HandlerSIGUSR1(int);
void HandlerSIGUSR2(int);
void HandlerSIGALRM(int);
void HandlerSIGINT(int);
void HandlerSIGQUIT(int);
void HandlerSIGCHLD(int);
void HandlerSIGHUP(int);

void DestructeurVS(void *p);

pthread_t threadCle;
pthread_t threadDK;
pthread_t threadDKJr;
pthread_t threadEvenements;
pthread_t threadScore;
pthread_t threadEnnemis;
pthread_t threadCorbeau;
pthread_t threadCroco;

pthread_cond_t condDK;
pthread_cond_t condScore;

pthread_mutex_t mutexGrilleJeu;
pthread_mutex_t mutexDK;
pthread_mutex_t mutexEvenement;
pthread_mutex_t mutexScore;

pthread_key_t keySpec;

bool MAJDK = false;
int  score = 0;
bool MAJScore = true;
int  delaiEnnemis = 4;
int  positionDKJr = 1;
int  evenement = AUCUN_EVENEMENT;
int etatDKJr;

typedef struct
{
  int type;
  pthread_t tid;
} S_CASE;

S_CASE grilleJeu[4][8];

typedef struct
{
  bool haut;
  int position;
} S_CROCO;

struct sigaction sigAct;

// ------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	sigset_t mask;
	sigemptyset(&sigAct.sa_mask);
	sigAct.sa_handler = HandlerSIGQUIT;
	sigAct.sa_flags = 0;
	sigaction(SIGQUIT, &sigAct, NULL);
	
	sigemptyset(&sigAct.sa_mask);
	sigAct.sa_handler = HandlerSIGALRM;
	sigAct.sa_flags = 0;
	sigaction(SIGALRM, &sigAct, NULL);

	sigemptyset(&sigAct.sa_mask);
	sigAct.sa_handler = HandlerSIGUSR1;
	sigAct.sa_flags = 0;
	sigaction(SIGUSR1, &sigAct, NULL);

	sigemptyset(&sigAct.sa_mask);
	sigAct.sa_handler = HandlerSIGINT;
	sigAct.sa_flags = 0;
	sigaction(SIGINT, &sigAct, NULL);

	sigaddset(&mask, SIGQUIT);
	sigaddset(&mask, SIGINT);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGALRM);
	sigprocmask(SIG_BLOCK, &mask, NULL);

	pthread_key_create(&keySpec,DestructeurVS);

	ouvrirFenetreGraphique();

	pthread_mutex_init(&mutexGrilleJeu, NULL);
	pthread_mutex_init(&mutexDK, NULL);
	pthread_mutex_init(&mutexEvenement, NULL);
	pthread_mutex_init(&mutexScore, NULL);

	pthread_create(&threadCle,NULL,FctThreadCle,NULL);		
	pthread_create(&threadEvenements,NULL,FctThreadEvenements,NULL);
	pthread_create(&threadDKJr,NULL,FctThreadDKJr,NULL);
	pthread_create(&threadDK,NULL,FctThreadDK,NULL);
	pthread_create(&threadScore,NULL,FctThreadScore,NULL);
	pthread_create(&threadEnnemis,NULL,FctThreadEnnemis,NULL);

	pthread_cond_init(&condDK, NULL);
	pthread_cond_init(&condScore, NULL);


	for(int i = 1;i<4;i++)
	{
		
		pthread_join(threadDKJr,NULL);
		printf("\nperte d'une vie\n");
		afficherEchec(i);	
		pthread_create(&threadDKJr,NULL,FctThreadDKJr,NULL);
	}
	pause();
	

	
}

void* FctThreadCle(void * param)
{
	struct timespec cinqcentms = {0,500000000};
    int i=1;
	
    for (i=1;i<5;i++)
    {
        afficherCle(i);
        nanosleep(&cinqcentms,NULL);
        if(i==1)
		{
			pthread_mutex_lock(&mutexGrilleJeu);
			setGrilleJeu(0,1,CLE);
			pthread_mutex_unlock(&mutexGrilleJeu);
			effacerCarres(3,12,2,2);

		}  
        else
		{
			pthread_mutex_lock(&mutexGrilleJeu);
			setGrilleJeu(0,1);
			pthread_mutex_unlock(&mutexGrilleJeu);
			effacerCarres(3,13,2,2);
				
		}
        if(i==4)
		{
            for(i=4;i>0;i--)
            {
                afficherCle(i);
                
                if(i==1)
				{
					pthread_mutex_lock(&mutexGrilleJeu);
					setGrilleJeu(0,1,CLE);
					pthread_mutex_unlock(&mutexGrilleJeu);
					effacerCarres(3,12,2,2);
				} 
                else
				{
					if(i==4)
					{
						pthread_mutex_lock(&mutexGrilleJeu);
						setGrilleJeu(0,1);
						pthread_mutex_unlock(&mutexGrilleJeu);
						effacerCarres(3,13,2,2);
					}
					else
					{
						nanosleep(&cinqcentms,NULL);
						pthread_mutex_lock(&mutexGrilleJeu);
						setGrilleJeu(0,1);
						pthread_mutex_unlock(&mutexGrilleJeu);
						effacerCarres(3,13,2,2);
					}
					
				}
            }
		}
    }
    return 0;
}
void * FctThreadEvenements(void *p)
{
	int evt;
	struct timespec temps = { 0, 100000000 };
	while (1)
	{
		pthread_mutex_lock(&mutexEvenement);
		evt = AUCUN_EVENEMENT;
		evenement = AUCUN_EVENEMENT;
	    evt = lireEvenement();

	    switch (evt)
	    {
		case SDL_QUIT:
			evenement = SDL_QUIT;
			pthread_mutex_unlock(&mutexEvenement);
			exit(0);
		case SDLK_UP:
			printf("KEY_UP\n");
			evenement = SDLK_UP;
			pthread_mutex_unlock(&mutexEvenement);
			pthread_kill(threadDKJr,SIGQUIT); 
			nanosleep(&temps,NULL);
			
			break;
		case SDLK_DOWN:
			printf("KEY_DOWN\n");
			evenement = SDLK_DOWN;
			pthread_mutex_unlock(&mutexEvenement);
			pthread_kill(threadDKJr,SIGQUIT);
			nanosleep(&temps,NULL); 
			break;
		case SDLK_LEFT:
			printf("KEY_LEFT\n");
			evenement = SDLK_LEFT;
			pthread_mutex_unlock(&mutexEvenement);
			pthread_kill(threadDKJr,SIGQUIT);
			nanosleep(&temps,NULL);
			break;
		case SDLK_RIGHT:
			printf("KEY_RIGHT\n");
			evenement = SDLK_RIGHT;
			pthread_mutex_unlock(&mutexEvenement);
			pthread_kill(threadDKJr,SIGQUIT);
			nanosleep(&temps,NULL);
		default:
			evenement = AUCUN_EVENEMENT; 
	    }
	}
}
void * FctThreadDKJr(void *p)
{
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGQUIT);
	sigaddset(&mask, SIGINT);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);

	struct timespec temps = { 1, 400000000 };
	struct timespec cinqcentms = {0,500000000};
	pthread_mutex_lock(&mutexGrilleJeu);
	setGrilleJeu(3, 1, DKJR);
	afficherDKJr(11, 9, 1);
	etatDKJr = LIBRE_BAS;
	positionDKJr = 1;
	setGrilleJeu(3,positionDKJr,DKJR);
	afficherGrilleJeu();
	pthread_mutex_unlock(&mutexGrilleJeu);
	effacerCarres(11, 7, 2,2);
	while (1)
	{
		pause();
		pthread_mutex_lock(&mutexEvenement);
		pthread_mutex_lock(&mutexGrilleJeu);
		switch (etatDKJr)
		{
		case LIBRE_BAS:
			switch (evenement)
			{
			case SDLK_LEFT:
				if (positionDKJr > 1)
				{
				setGrilleJeu(3, positionDKJr);
				effacerCarres(11, (positionDKJr * 2) + 7, 2, 2);
				positionDKJr--;
				setGrilleJeu(3, positionDKJr, DKJR);
				
		afficherGrilleJeu();
				afficherDKJr(11, (positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
				}
				break;
			case SDLK_RIGHT:
				if(positionDKJr < 7)
				{
					setGrilleJeu(3, positionDKJr);
					effacerCarres(11, (positionDKJr * 2) + 7, 2, 2);
					positionDKJr++;
					setGrilleJeu(3, positionDKJr, DKJR);

		afficherGrilleJeu();
					afficherDKJr(11, (positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
				}
				break;
			case SDLK_UP:
			if((grilleJeu[2][positionDKJr].type)==CORBEAU)
			{
				setGrilleJeu(3, positionDKJr);	
				pthread_kill(grilleJeu[2][positionDKJr].tid,SIGUSR1);
				effacerCarres(11,(positionDKJr * 2) + 7, 2, 2);
				nanosleep(&cinqcentms,NULL);
				
				pthread_mutex_unlock(&mutexEvenement);
				pthread_mutex_unlock(&mutexGrilleJeu);
				pthread_exit(0);
			}
			if(positionDKJr==1 || positionDKJr == 5)
			{
				setGrilleJeu(3, positionDKJr);
				etatDKJr = LIANE_BAS;
				
				effacerCarres(11,(positionDKJr * 2) + 7, 2, 2);
				setGrilleJeu(2,positionDKJr,DKJR);

		afficherGrilleJeu();
				afficherDKJr(10, (positionDKJr * 2) + 7,7);
				
			}
			else
			{
				if(positionDKJr==7)
				{
					etatDKJr = DOUBLE_LIANE_BAS;
					setGrilleJeu(3,positionDKJr);
					effacerCarres(11,(positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(2, positionDKJr, DKJR);

		afficherGrilleJeu();
					afficherDKJr(10, (positionDKJr * 2) + 7,5);
				}
				else
				{
					setGrilleJeu(3,positionDKJr);
					
					effacerCarres(11, (positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(2,positionDKJr,DKJR);
					afficherDKJr(10, (positionDKJr * 2) + 7,8);
					pthread_mutex_unlock(&mutexGrilleJeu);
					nanosleep(&temps,NULL);
					afficherGrilleJeu();
					setGrilleJeu(2,positionDKJr);
					
		
					setGrilleJeu(3,positionDKJr,DKJR);
					afficherGrilleJeu();
					effacerCarres(10, (positionDKJr * 2) + 7, 2, 2);
					afficherDKJr(11,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
				}
			}

				break;
			}
			break;
		case LIANE_BAS:
				switch (evenement)
				{
				case SDLK_DOWN:
					etatDKJr = LIBRE_BAS;
					setGrilleJeu(2,positionDKJr);
					effacerCarres(10, (positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(3, positionDKJr, DKJR);
					afficherGrilleJeu();
					afficherDKJr(11,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					break;
				}
				break;
		case DOUBLE_LIANE_BAS:
				switch (evenement)
				{
				case SDLK_UP: 
					
						etatDKJr = LIBRE_HAUT;
						setGrilleJeu(2,positionDKJr);
						effacerCarres(9, (positionDKJr * 2) + 7, 3, 2);
						afficherDKJr(7,(positionDKJr * 2) + 7,6);
						setGrilleJeu(1,positionDKJr,DKJR);
						afficherGrilleJeu();
					
					break;
				case SDLK_DOWN: 
					etatDKJr = LIBRE_BAS;
					setGrilleJeu(2,positionDKJr);
					setGrilleJeu(3,positionDKJr);
					effacerCarres(9, (positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(3,positionDKJr,DKJR);
					afficherGrilleJeu();
					afficherDKJr(11,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					break;
				}
				break;
				
		case LIBRE_HAUT:
				switch (evenement)
				{
				case SDLK_LEFT:
					if(positionDKJr>3)
					{
						setGrilleJeu(1, positionDKJr);
						effacerCarres(7, (positionDKJr * 2) + 7, 2, 2);
						positionDKJr--;
						setGrilleJeu(1, positionDKJr, DKJR);
						afficherGrilleJeu();
						afficherDKJr(7,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					}
					else
					{
						setGrilleJeu(1, positionDKJr);
						effacerCarres(7, (positionDKJr * 2) + 7, 2, 2);
						positionDKJr--;
						afficherDKJr(7,(positionDKJr * 2) + 7,9);
						nanosleep(&cinqcentms,NULL);
						
							
							effacerCarres(5,12,3,2);
							if(grilleJeu[0][1].type == CLE)
							{
								afficherDKJr(5,(positionDKJr * 2) + 7,11);
								nanosleep(&cinqcentms,NULL);
								effacerCarres(6,((positionDKJr-1) * 2)+7, 2, 4);

								pthread_mutex_lock(&mutexDK);
								MAJDK = true;
								pthread_mutex_unlock(&mutexDK);
								pthread_cond_signal(&condDK);

								

								effacerCarres(6,((positionDKJr-1) * 2)+7, 2, 4);
								afficherDKJr(12,(positionDKJr * 2) + 7,13);
								nanosleep(&cinqcentms,NULL);
								effacerCarres(11, 7, 2,2);
								positionDKJr = 1;
								etatDKJr = LIBRE_BAS;
								afficherDKJr(11,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
							}
							else
							{
								afficherDKJr(9,(positionDKJr * 2) + 7,12);
								nanosleep(&cinqcentms,NULL);
								effacerCarres(6,((positionDKJr-1) * 2)+7, 2, 4);
								afficherDKJr(12,(positionDKJr * 2) + 7,13);
								nanosleep(&cinqcentms,NULL);
								pthread_mutex_unlock(&mutexEvenement);
								pthread_mutex_unlock(&mutexGrilleJeu);
								pthread_exit(0);
							}
							
							
	
					}
					break;
				case SDLK_RIGHT:
					if(positionDKJr < 7)
					{
						setGrilleJeu(1,positionDKJr);
						effacerCarres(7, (positionDKJr * 2) + 7, 2, 2);
						positionDKJr++;
						setGrilleJeu(1, positionDKJr, DKJR);
						afficherGrilleJeu();
						if(positionDKJr==7)
						{
							afficherDKJr(7, (positionDKJr * 2) + 7,6);
						}
						else
							afficherDKJr(7, (positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					}
					break;
				case SDLK_UP:
					if(positionDKJr==6)
					{
						etatDKJr = LIANE_HAUT;
						setGrilleJeu(1,positionDKJr);
						effacerCarres(7,(positionDKJr * 2) + 7, 2, 2);
						setGrilleJeu(0, positionDKJr, DKJR);
						afficherGrilleJeu();
						afficherDKJr(6, (positionDKJr * 2) + 7,7);
					}
					else
					{
						if(positionDKJr>=3&&positionDKJr<7)
						{

							setGrilleJeu(1,positionDKJr);
							effacerCarres(7, (positionDKJr * 2) + 7, 2, 2);
							afficherDKJr(6, (positionDKJr * 2) + 7,8);
							setGrilleJeu(0,positionDKJr,DKJR);
							afficherGrilleJeu();
							pthread_mutex_unlock(&mutexGrilleJeu);
							nanosleep(&temps,NULL);
							effacerCarres(6, (positionDKJr * 2) + 7, 2, 2);
							setGrilleJeu(0,positionDKJr);
							setGrilleJeu(1,positionDKJr,DKJR);
							afficherGrilleJeu();
							afficherDKJr(7,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
						}
						
					}
					break; 
				case SDLK_DOWN:
					if(positionDKJr==7)
					{
						etatDKJr = DOUBLE_LIANE_BAS;
						setGrilleJeu(1, positionDKJr);
						effacerCarres(7,(positionDKJr * 2) + 7, 2, 2);
						setGrilleJeu(2, positionDKJr, DKJR);
						afficherGrilleJeu();
						afficherDKJr(9, (positionDKJr * 2) + 7,7);
					}
				}
				break;
			case LIANE_HAUT:
				switch (evenement)
				{
				case SDLK_DOWN:
					etatDKJr = LIBRE_HAUT;
					setGrilleJeu(0,positionDKJr);
					effacerCarres(6, (positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(1, positionDKJr, DKJR);
					afficherGrilleJeu();
					afficherDKJr(7,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					break;
				}
				break;


		}
		pthread_mutex_unlock(&mutexEvenement);
		pthread_mutex_unlock(&mutexGrilleJeu);
	}
	pthread_exit(0);
}

void * FctThreadDK(void * p)
{
	struct timespec septcentms ={0,700000000};
	int i;
	
	while(1)
	{
		afficherCage(1);
		afficherCage(2);
		afficherCage(3);
		afficherCage(4);
		for(i=1;i<=4;i++)
		{
			pthread_mutex_lock(&mutexDK);
			while(MAJDK==false)
				pthread_cond_wait(&condDK,&mutexDK);
			MAJDK=false;
			pthread_mutex_unlock(&mutexDK);
			switch(i)
			{
			case 1: 
				effacerCarres(2,7,2,2);
				break;
			case 2:
				effacerCarres(2,9,2,2);
				break;
			case 3: 
				effacerCarres(4,7,2,2);
				break;
			case 4:
				effacerCarres(4,9,2,2);
				break;
			}
			pthread_mutex_lock(&mutexScore);
			score +=10;
			MAJScore = true;
			pthread_mutex_unlock(&mutexScore);
			pthread_cond_signal(&condScore);
		}
		afficherRireDK();
		pthread_mutex_lock(&mutexScore);
		score +=10;
		MAJScore = true;
		pthread_mutex_unlock(&mutexScore);
		pthread_cond_signal(&condScore);
		nanosleep(&septcentms,NULL);
		effacerCarres(3,8,2,2);
		
	}
	

}

void * FctThreadScore (void* p)
{
	while(1)
	{
		pthread_mutex_lock(&mutexScore);
		while(MAJScore==false)
			pthread_cond_wait(&condScore,&mutexScore);
		MAJScore=false;
		afficherScore(score);
		pthread_mutex_unlock(&mutexScore);

	}
}

void* FctThreadEnnemis(void* p)
{
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGALRM);
	sigprocmask(SIG_UNBLOCK, &mask, NULL);
	//int *ptr;
	int nombre = 0;
	int position = 0;
	while(1)
	{
		alarm(delaiEnnemis);
		pause();
		
		nombre = rand()%2;
		switch(nombre)
		{
			case 0: 
				pthread_create(&threadCroco,NULL,&FctThreadCroco,NULL);
				break;
			case 1:
				pthread_create(&threadCorbeau,NULL,&FctThreadCorbeau,NULL);
				break;
		}
	}
	pthread_exit(0);
}

void* FctThreadCroco(void * p)
{

	S_CROCO croco,*pt;
	struct timespec septcentms = {0,700000000};
	int val;
	
	pt = (S_CROCO*)malloc(sizeof(S_CROCO));
		croco.haut = true;
		for(int i = 2;i<8;i++)
		{
			croco.position = i;

			val = (croco.position*2)+7;  //useless peut le faire avec i
			*pt =croco;
			pthread_setspecific(keySpec,(void*)pt);
			pthread_mutex_lock(&mutexGrilleJeu);
			setGrilleJeu(1,i,CROCO,pthread_self());
			pthread_mutex_unlock(&mutexGrilleJeu);
			if(i%2==0)
				afficherCroco(val,2);
			else
				afficherCroco(val,1);
			nanosleep(&septcentms,NULL);
			setGrilleJeu(1,i);
			if(i%2==0)
				effacerCarres(8,val,1,1);
			else
				effacerCarres(8,val,1,1);
			
		}
		afficherCroco(8,3);
		nanosleep(&septcentms,NULL);
		effacerCarres(9,23,1,1);
		croco.haut = false;
		for(int i = 7;i>0;i--)
		{
			croco.position = i;

			val = (croco.position*2)+7;  //useless peut le faire avec i
			*pt =croco;
			pthread_setspecific(keySpec,(void*)pt);
			pthread_mutex_lock(&mutexGrilleJeu);
			setGrilleJeu(1,i,CROCO,pthread_self());
			pthread_mutex_unlock(&mutexGrilleJeu);
			if(i%2==0)
				afficherCroco(val,5);
			else
				afficherCroco(val,4);
			nanosleep(&septcentms,NULL);
			setGrilleJeu(1,i);
			if(i%2==0)
				effacerCarres(12,val,1,1);
			else
				effacerCarres(12,val,1,1);
		}

	
}

void* FctThreadCorbeau(void* p)
{
	struct timespec septcentms = {0,700000000};
	int * pt,val;
	pt = (int*)malloc(sizeof(int));
	
		for(int i = 0;i<8;i++)
		{
			afficherGrilleJeu();
			val = (i*2)+8;
			pthread_mutex_lock(&mutexGrilleJeu);
			if(grilleJeu[2][i].type==DKJR)
			{
				setGrilleJeu(2,i);
				pthread_kill(threadDKJr,SIGINT);
				pthread_mutex_unlock(&mutexGrilleJeu);
				pthread_exit(0);
			}
			
			else
			{
				setGrilleJeu(2,i,CORBEAU,pthread_self());
				pthread_mutex_unlock(&mutexGrilleJeu);
				*pt =i;
				pthread_setspecific(keySpec,(void*)pt);
				if(i%2==0)
					afficherCorbeau(val,1);
				else
					afficherCorbeau(val,2);
				nanosleep(&septcentms,NULL);

				pthread_mutex_lock(&mutexGrilleJeu);
				setGrilleJeu(2,i);
				pthread_mutex_unlock(&mutexGrilleJeu);
				if(i%2==0)
					effacerCarres(10,val,1,1);
				else
					effacerCarres(9,val,2,1);

			}
			
		}
		
	
}

void DestructeurVS(void* p)
{

}
// -------------------------------------

void initGrilleJeu()
{
  int i, j;   
  
  pthread_mutex_lock(&mutexGrilleJeu);

  for(i = 0; i < 4; i++)
    for(j = 0; j < 7; j++)
      setGrilleJeu(i, j);

  pthread_mutex_unlock(&mutexGrilleJeu);
}

// -------------------------------------

void setGrilleJeu(int l, int c, int type, pthread_t tid)
{
  grilleJeu[l][c].type = type;
  grilleJeu[l][c].tid = tid;
}

// -------------------------------------

void afficherGrilleJeu()
{   
   for(int j = 0; j < 4; j++)
   {
       for(int k = 0; k < 8; k++)
          printf("%d  ", grilleJeu[j][k].type);
       printf("\n");
   }

   printf("\n");   
}
void HandlerSIGQUIT(int sig)
{
}

void HandlerSIGALRM(int sig)
{
	alarm(15);
	if(delaiEnnemis>2.5)
	{
		delaiEnnemis -=0.25;
	}
}

void HandlerSIGUSR1(int sig)
{
	int val = *((int*)pthread_getspecific(keySpec));
	int val1 = (val*2)+8;
	if(val1%2==0)
		effacerCarres(10,val,1,1);
	else
		effacerCarres(9,val,2,1);
	pthread_kill(grilleJeu[2][val].tid,SIGKILL);

}

void HandlerSIGINT(int sig)
{
	pthread_mutex_unlock(&mutexEvenement);
	setGrilleJeu(2,positionDKJr);
	setGrilleJeu(3,positionDKJr);
	effacerCarres(10,(positionDKJr*2)+7,3,2);
	pthread_exit(0);
}
