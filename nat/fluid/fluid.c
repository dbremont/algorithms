#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 36
#define L 10.0
#define DT 0.005
#define STEPS 100000

#define EPSILON 1.0
#define SIGMA 1.0
#define MASS 1.0

#define WINDOW_SIZE 600
#define PARTICLE_RADIUS 5

// Positions, velocities, forces (scaled for visualization)
double pos[N][2];
double vel[N][2];
double force[N][2];

double scale = WINDOW_SIZE / L;

// PBC minimum image convention
double pbc(double x) {
    if (x > 0.5 * L) x -= L;
    else if (x < -0.5 * L) x += L;
    return x;
}

void compute_forces() {
    int i, j;
    double dx, dy, r2, r6, f;

    for (i = 0; i < N; i++) {
        force[i][0] = 0.0;
        force[i][1] = 0.0;
    }

    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            dx = pos[i][0] - pos[j][0];
            dy = pos[i][1] - pos[j][1];
            dx = pbc(dx);
            dy = pbc(dy);
            r2 = dx*dx + dy*dy;
            if (r2 < 9.0) {
                r6 = pow(SIGMA*SIGMA / r2, 3);
                f = 24 * EPSILON / r2 * (2 * r6*r6 - r6);
                force[i][0] += f * dx;
                force[i][1] += f * dy;
                force[j][0] -= f * dx;
                force[j][1] -= f * dy;
            }
        }
    }
}

void init_positions() {
    int i, side = (int)sqrt(N);
    double spacing = L / side;
    int count = 0;
    for (i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (count < N) {
                pos[count][0] = (i + 0.5) * spacing;
                pos[count][1] = (j + 0.5) * spacing;
                count++;
            }
        }
    }
}

void init_velocities() {
    int i;
    double vx_sum = 0.0, vy_sum = 0.0;
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        vel[i][0] = ((double)rand() / RAND_MAX) - 0.5;
        vel[i][1] = ((double)rand() / RAND_MAX) - 0.5;
        vx_sum += vel[i][0];
        vy_sum += vel[i][1];
    }
    vx_sum /= N;
    vy_sum /= N;
    for (i = 0; i < N; i++) {
        vel[i][0] -= vx_sum;
        vel[i][1] -= vy_sum;
    }
}

void velocity_verlet() {
    int i;
    double half_dt = 0.5 * DT;

    for (i = 0; i < N; i++) {
        pos[i][0] += vel[i][0] * DT + half_dt * half_dt * force[i][0] / MASS;
        pos[i][1] += vel[i][1] * DT + half_dt * half_dt * force[i][1] / MASS;

        // wrap positions with periodic boundaries
        if (pos[i][0] < 0) pos[i][0] += L;
        else if (pos[i][0] >= L) pos[i][0] -= L;
        if (pos[i][1] < 0) pos[i][1] += L;
        else if (pos[i][1] >= L) pos[i][1] -= L;
    }

    double force_old[N][2];
    for (i = 0; i < N; i++) {
        force_old[i][0] = force[i][0];
        force_old[i][1] = force[i][1];
    }

    compute_forces();

    for (i = 0; i < N; i++) {
        vel[i][0] += half_dt * (force_old[i][0] + force[i][0]) / MASS;
        vel[i][1] += half_dt * (force_old[i][1] + force[i][1]) / MASS;
    }
}

void draw_circle(SDL_Renderer *renderer, int x, int y, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("MD Lennard-Jones Liquid Simulation",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       WINDOW_SIZE, WINDOW_SIZE, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    init_positions();
    init_velocities();
    compute_forces();

    int running = 1;
    SDL_Event event;

    while (running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) running = 0;
            if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) running = 0;
        }

        velocity_verlet();

        // Clear screen (black)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw particles (white)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 0; i < N; i++) {
            int x = (int)(pos[i][0] * scale);
            int y = (int)(pos[i][1] * scale);
            draw_circle(renderer, x, y, PARTICLE_RADIUS);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(10);  // ~100 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
