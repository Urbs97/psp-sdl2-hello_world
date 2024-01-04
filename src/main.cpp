#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <pspdebug.h>
#include <pspkernel.h>

PSP_MODULE_INFO("Tutorial", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

int exit_callback(int arg1, int arg2, void* common)
{
    sceKernelExitGame();
    return 0;
}

int CallbackThread(SceSize args, void* argp)
{
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB();

    return 0;
}

int SetupCallbacks(void)
{
    int thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
    if (thid >= 0)
    {
        sceKernelStartThread(thid, 0, 0);
    }
    return thid;
}

SDL_Texture* LoadSprite(const char* file, SDL_Renderer* renderer)
{
    SDL_Texture* texture = IMG_LoadTexture(renderer, file);
    if (texture == nullptr)
    {
        pspDebugScreenPrintf("Failed to create texture: %s\n", SDL_GetError());
        sceKernelDelayThread(3 * 1000 * 1000);
        return nullptr;
    }
    pspDebugScreenPrintf("Loaded image: %s\n", file);
    sceKernelDelayThread(3 * 1000 * 1000);
    return texture;
}

void RenderSprite(SDL_Texture* sprite, SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(sprite, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, sprite, NULL, &dest);
}

auto main() -> int
{
    SetupCallbacks();
    SDL_SetMainReady();
    pspDebugScreenInit();

    pspDebugScreenPrintf("Launching...\n");

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

    SDL_Window* window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 272, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Texture* sprite = LoadSprite("sprites/sprite.png", renderer);

    SDL_Event event;
    bool renderSprite = false;
    bool running = true;
    while (running)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_CONTROLLERDEVICEADDED:
                SDL_GameControllerOpen(event.cdevice.which);
                break;
            case SDL_CONTROLLERBUTTONDOWN:
                if (event.cbutton.button == SDL_CONTROLLER_BUTTON_START)
                    running = false;
                if (event.cbutton.button == SDL_CONTROLLER_BUTTON_A)
                    renderSprite = true;
                break;
            }
        }

        // Clear the screen
        SDL_RenderClear(renderer);

        // Draw everything on a dark blue background
        SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);

        // Draw sprite
        if (renderSprite && sprite != nullptr)
        {
            RenderSprite(sprite, renderer, 100, 100); // Render at position 100, 100
        }

        // Present changes
        SDL_RenderPresent(renderer);
    }

    return 0;
}