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
int  delaiEnnemis = 4000;
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
	sigaddset(&mask, SIGQUIT);
	sigprocmask(SIG_BLOCK, &mask, NULL);



	ouvrirFenetreGraphique();

	pthread_mutex_init(&mutexGrilleJeu, NULL);
	pthread_mutex_init(&mutexDK, NULL);
	pthread_mutex_init(&mutexEvenement, NULL);
	pthread_mutex_init(&mutexScore, NULL);

	pthread_create(&threadCle,NULL,FctThreadCle,NULL);		
	pthread_create(&threadEvenements,NULL,FctThreadEvenements,NULL);
	pthread_create(&threadDKJr,NULL,FctThreadDKJr,NULL);		

	
	while(1)
	{

	};
	// afficherCroco(11, 2);
	// afficherCroco(17, 1);
	// afficherCroco(0, 3);
	// afficherCroco(12, 5);
	// afficherCroco(18, 4);

	// afficherDKJr(11, 9, 1);
	// afficherDKJr(6, 19, 7);
	// afficherDKJr(0, 0, 9);
	
	// afficherCorbeau(10, 2);
	// afficherCorbeau(16, 1);
	
	// effacerCarres(9, 10, 2, 1);

	// afficherEchec(1);
	// afficherScore(1999);

	
}

void* FctThreadCle(void * param)
{

    int i=1;
	
    for (i=1;i<5;i++)
    {
        afficherCle(i);
        sleep(1);
        if(i==1)
		{
			pthread_mutex_lock(&mutexGrilleJeu);
			setGrilleJeu(0,1,CLE, pthread_self());
			pthread_mutex_unlock(&mutexGrilleJeu);
			effacerCarres(3,12,2,2);

		}  
        else
		{
			pthread_mutex_lock(&mutexGrilleJeu);
			setGrilleJeu(0,1, pthread_self());
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
					setGrilleJeu(0,1,CLE, pthread_self());
					pthread_mutex_unlock(&mutexGrilleJeu);
					effacerCarres(3,12,2,2);
				} 
                else
				{
					if(i==4)
					{
						pthread_mutex_lock(&mutexGrilleJeu);
						setGrilleJeu(0,1, pthread_self());
						pthread_mutex_unlock(&mutexGrilleJeu);
						effacerCarres(3,13,2,2);
					}
					else
					{
						sleep(1);
						pthread_mutex_lock(&mutexGrilleJeu);
						setGrilleJeu(0,1, pthread_self());
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
	sigprocmask(SIG_UNBLOCK, &mask, NULL);

	struct timespec temps = { 1, 400000000 };
	
	pthread_mutex_lock(&mutexGrilleJeu);
	setGrilleJeu(3, 1, DKJR);
	afficherDKJr(11, 9, 1);
	etatDKJr = LIBRE_BAS;
	positionDKJr = 1;
	pthread_mutex_unlock(&mutexGrilleJeu);

	while (1)
	{
		pause();
		printf("\nentre dans le while\n");
		pthread_mutex_lock(&mutexEvenement);
		pthread_mutex_lock(&mutexGrilleJeu);
		switch (etatDKJr)
		{
		case LIBRE_BAS:
			printf("\nentrez dans libre_bas\n");
			printf("\nevenement :%d \n",evenement);
			switch (evenement)
			{
			case SDLK_LEFT:
				printf("\nentre dans le left\n");
				if (positionDKJr > 1)
				{
				setGrilleJeu(3, positionDKJr);
				effacerCarres(11, (positionDKJr * 2) + 7, 2, 2);
				positionDKJr--;
				setGrilleJeu(3, positionDKJr, DKJR);
				afficherDKJr(11, (positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
				}
				break;
			case SDLK_RIGHT:
				printf("\nentre dans le right\n");
				if(positionDKJr < 7)
				{
					setGrilleJeu(3, positionDKJr);
					effacerCarres(11, (positionDKJr * 2) + 7, 2, 2);
					positionDKJr++;
					setGrilleJeu(3, positionDKJr, DKJR);
					afficherDKJr(11, (positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
				}
				break;
			case SDLK_UP:
			if(positionDKJr==1 || positionDKJr == 5)
			{
				etatDKJr = LIANE_BAS;
				setGrilleJeu(2,positionDKJr);
				effacerCarres(11,(positionDKJr * 2) + 7, 2, 2);
				setGrilleJeu(3, positionDKJr, DKJR);
				afficherDKJr(10, (positionDKJr * 2) + 7,7);
				
			}
			else
			{
				if(positionDKJr==7)
				{
					etatDKJr = DOUBLE_LIANE_BAS;
					setGrilleJeu(2,positionDKJr);
					effacerCarres(11,(positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(2, positionDKJr, DKJR);
					afficherDKJr(10, (positionDKJr * 2) + 7,7);
				}
				else
				{
					setGrilleJeu(2,positionDKJr);
					effacerCarres(11, (positionDKJr * 2) + 7, 2, 2);
					afficherDKJr(10, (positionDKJr * 2) + 7,8);
					pthread_mutex_unlock(&mutexGrilleJeu);
					nanosleep(&temps,NULL);
					setGrilleJeu(3,positionDKJr,DKJR);
					effacerCarres(10, (positionDKJr * 2) + 7, 2, 2);
					afficherDKJr(11,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
				}
			}

				break;
			}
			printf("sort du switch evenement\n");
			break;
		case LIANE_BAS:
				switch (evenement)
				{
				case SDLK_DOWN:
					etatDKJr = LIBRE_BAS;
					setGrilleJeu(3,positionDKJr);
					effacerCarres(10, (positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(3, positionDKJr, DKJR);
					afficherDKJr(11,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					break;
				}
				break;
		case DOUBLE_LIANE_BAS:
				switch (evenement)
				{
				case SDLK_UP: 
					if(grilleJeu[2][positionDKJr].type!=VIDE)
					{
						etatDKJr = LIBRE_HAUT;
						effacerCarres(9, (positionDKJr * 2) + 7, 3, 2);
						afficherDKJr(7,(positionDKJr * 2) + 7,6);
						setGrilleJeu(1,positionDKJr,DKJR);
					}
					
					break;
				case SDLK_DOWN: 
					etatDKJr = LIBRE_BAS;
					setGrilleJeu(3,positionDKJr);
					effacerCarres(9, (positionDKJr * 2) + 7, 2, 2);
					afficherDKJr(11,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					break;
				}
				break;
				
		case LIBRE_HAUT:
				printf("entre dans le libre_haut\n");
				
				switch (evenement)
				{
				case SDLK_LEFT:
					if(positionDKJr>3)
					{
						effacerCarres(7, (positionDKJr * 2) + 7, 2, 2);
						positionDKJr--;
						setGrilleJeu(1, positionDKJr, DKJR);
						afficherDKJr(7,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					}
					else
					{
						if(grilleJeu[0][1].type == CLE)
						{
							positionDKJr = 1;
							etatDKJr = LIBRE_BAS;
						}
					}
					break;
				case SDLK_RIGHT:
					printf("\nentre dans le right haut\n");
					if(positionDKJr < 7)
					{
						setGrilleJeu(1,positionDKJr);
						effacerCarres(7, (positionDKJr * 2) + 7, 2, 2);
						positionDKJr++;
						setGrilleJeu(1, positionDKJr, DKJR);
						if(positionDKJr==7)
						{
							printf("la position de dkjr : %d",positionDKJr);
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
						setGrilleJeu(0,positionDKJr);
						effacerCarres(7,(positionDKJr * 2) + 7, 2, 2);
						setGrilleJeu(0, positionDKJr, DKJR);
						afficherDKJr(6, (positionDKJr * 2) + 7,7);
					}
					else
					{
						if(positionDKJr>=3&&positionDKJr<7)
						{
							setGrilleJeu(3,positionDKJr);
						effacerCarres(7, (positionDKJr * 2) + 7, 2, 2);
						afficherDKJr(6, (positionDKJr * 2) + 7,8);
						pthread_mutex_unlock(&mutexGrilleJeu);
						nanosleep(&temps,NULL);
						effacerCarres(6, (positionDKJr * 2) + 7, 2, 2);
						afficherDKJr(7,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
						}
						
					}
					break; 
				case SDLK_DOWN:
					if(positionDKJr==7)
					{
						etatDKJr = DOUBLE_LIANE_BAS;
						effacerCarres(7,(positionDKJr * 2) + 7, 2, 2);
						setGrilleJeu(2, positionDKJr, DKJR);
						afficherDKJr(9, (positionDKJr * 2) + 7,7);
					}
				}
				break;
			case LIANE_HAUT:
				switch (evenement)
				{
				case SDLK_DOWN:
					etatDKJr = LIBRE_HAUT;
					setGrilleJeu(1,positionDKJr);
					effacerCarres(6, (positionDKJr * 2) + 7, 2, 2);
					setGrilleJeu(1, positionDKJr, DKJR);
					afficherDKJr(7,(positionDKJr * 2) + 7,((positionDKJr - 1) % 4) + 1);
					break;
				}
				break;


		}
		pthread_mutex_unlock(&mutexEvenement);
		pthread_mutex_unlock(&mutexGrilleJeu);
		printf("\nsort du switch etatDKJr\n");
	}
	pthread_exit(0);
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
printf("SIGQUIT reçu par le thread (%u)\n", (unsigned int)pthread_self());
fflush(stdout);
}