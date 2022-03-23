#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>


SDL_bool InitProject(void);
void Update(float);
void Quit(void);
static inline void InitBall(void);
static inline void InitiateThePlayers(void);

static inline SDL_bool Random(void);
void RenderBall(void);
void UpdateBall(float);
void RenderPlayer(void);
void UpdatePlayer(float);

typedef struct Ball
{
	float x;
	float y;
	float xspeed;
	float yspeed;
} Ball;
typedef struct Player
{
	int score;
	float ypos;
}Player;

SDL_Window* Window = NULL;
SDL_Renderer* Render = NULL;
const int HEIGHT = 700;
const int WIDTH = 1280;
const int BALL_SIZE = 12;

const float SPEED = 290.0f;

const int PLAYER_HEIGHT = 85;
const int PLAYER_WIDTH = 20;
const int PLAYER_MARGIN = 15;

const float PLAYER_SPEED = 245.0f;

Ball ball;
Player player1, player2;
SDL_bool StartGame = SDL_FALSE;

int main(int argc, char** argv)
{
	atexit(Quit);

	if (!InitProject()) exit(EXIT_FAILURE);

	SDL_bool KeepWorking = SDL_TRUE;

	SDL_Event event;

	Uint32 lastTick = SDL_GetTicks();
	// Game Loop
	while (KeepWorking)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				KeepWorking = SDL_FALSE;
				goto Label_Out;
			default:
				break;
			}
		}
		Uint32 currTick = SDL_GetTicks();
		Uint32 diff = currTick - lastTick;
		float elapsed = diff / 1000.0f;
		Update(elapsed);
		lastTick = currTick;
	Label_Out:;
	}
	exit(EXIT_SUCCESS);
}
SDL_bool InitProject(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	Window = SDL_CreateWindow("PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
		, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	if (!Window)
	{
		SDL_Log(SDL_GetError());
		return SDL_FALSE;
	}
	Render = SDL_CreateRenderer(Window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!Render)
	{
		SDL_Log(SDL_GetError());
		return SDL_FALSE;
	}

	srand(SDL_GetTicks());
	InitBall();
	InitiateThePlayers();
	return SDL_TRUE;
}

void Quit(void)
{
	if (Render) SDL_DestroyRenderer(Render);
	if (Window) SDL_DestroyWindow(Window);
	SDL_Quit();
}


void Update(float elapsed)
{
	SDL_SetRenderDrawColor(Render, 0, 0, 0, 255);
	SDL_RenderClear(Render);
	UpdateBall(elapsed);
	RenderBall();
	UpdatePlayer(elapsed);
	RenderPlayer();
	SDL_RenderPresent(Render);
}

static inline SDL_bool Random(void)
{
	return (rand() & 1) == 0 ? SDL_TRUE : SDL_FALSE;
}

static inline void InitBall(void)
{
	ball.x = WIDTH / 2 - BALL_SIZE / 2;
	ball.y = HEIGHT / 2 - BALL_SIZE / 2;
	//(SPEED * ( (double)rand() / (double)RAND_MAX) + 2 ) * ( Random() == SDL_TRUE ? 1 : -1) ;
	ball.xspeed = SPEED * (Random() == SDL_TRUE ? 1 : -1);
	ball.yspeed = SPEED * (Random() == SDL_TRUE ? 1 : -1);
}

void RenderBall(void)
{
	SDL_SetRenderDrawColor(Render, 220, 220, 220, 255);
	SDL_Rect Ball = {
		ball.x - BALL_SIZE / 2,
		ball.y - BALL_SIZE / 2,
		BALL_SIZE,
		BALL_SIZE
	};
	SDL_RenderFillRect(Render, &Ball);
}

void UpdateBall(float elapsed)
{
	if (!StartGame) return; // ONLY UPDATE IF GAME IS STARTED !
	ball.x += ball.xspeed * elapsed;
	ball.y += ball.yspeed * elapsed;
	if (ball.x <= BALL_SIZE / 2)
	{
		ball.x = BALL_SIZE / 2;
		ball.xspeed *= -1;
	}
	else if (ball.x >= WIDTH - BALL_SIZE / 2)
	{
		ball.x = WIDTH - BALL_SIZE / 2;
		ball.xspeed *= -1;
	}
	if (ball.y <= BALL_SIZE / 2)
	{
		ball.y = BALL_SIZE / 2;
		ball.yspeed *= -1;
	}
	else if (ball.y >= HEIGHT - BALL_SIZE / 2)
	{
		ball.y = HEIGHT - BALL_SIZE / 2;
		ball.yspeed *= -1;
	}

}
static inline void InitiateThePlayers(void)
{
	player2.score = player1.score = 0;
	player2.ypos = player1.ypos = HEIGHT / 2 - PLAYER_HEIGHT / 2;
}
void RenderPlayer(void)
{
	SDL_SetRenderDrawColor(Render, 255, 0, 0, 255);
	SDL_Rect PlayerRect = {
		.x = PLAYER_MARGIN ,
		.y = player1.ypos - PLAYER_HEIGHT / 2  ,
		.w = PLAYER_WIDTH,
		.h = PLAYER_HEIGHT
	};
	SDL_RenderFillRect(Render, &PlayerRect);
	SDL_SetRenderDrawColor(Render, 0, 0, 255, 255);
	PlayerRect.x = WIDTH - PLAYER_WIDTH - PLAYER_MARGIN;
	PlayerRect.y = player2.ypos - PLAYER_HEIGHT / 2;
	SDL_RenderFillRect(Render, &PlayerRect);

}
void UpdatePlayer(float elapsed)
{
	const Uint8* KeyBoardState = SDL_GetKeyboardState(NULL);
	if (KeyBoardState[SDL_SCANCODE_SPACE])
	{
		StartGame = SDL_TRUE;

	}

	if (KeyBoardState[SDL_SCANCODE_W])
	{
		player1.ypos -= PLAYER_SPEED * elapsed;
		if (player1.ypos < PLAYER_HEIGHT / 2) player1.ypos = PLAYER_HEIGHT / 2; // You can add a sound effect on this 
	}
	else if (KeyBoardState[SDL_SCANCODE_S])
	{
		player1.ypos += PLAYER_SPEED * elapsed;
		if (player1.ypos > HEIGHT - PLAYER_HEIGHT / 2) player1.ypos = HEIGHT - PLAYER_HEIGHT / 2;
	}
	if (KeyBoardState[SDL_SCANCODE_UP])
	{
		player2.ypos -= PLAYER_SPEED * elapsed;
		if (player2.ypos < PLAYER_HEIGHT / 2) player2.ypos = PLAYER_HEIGHT / 2; // You can add a sound effect on this 
	}

	else if (KeyBoardState[SDL_SCANCODE_DOWN])
	{
		player2.ypos += PLAYER_SPEED * elapsed;
		if (player2.ypos > HEIGHT - PLAYER_HEIGHT / 2) player2.ypos = HEIGHT - PLAYER_HEIGHT / 2;
	}
}