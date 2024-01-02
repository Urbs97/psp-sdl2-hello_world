#include <pspctrl.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <string>

PSP_MODULE_INFO("Tutorial", 0, 1, 0);

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

auto main() -> int
{
    SetupCallbacks();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    struct SceCtrlData padData;
    std::string message = "Press X to continue...\n";
    pspDebugScreenPrintf(message.c_str());
    while (true)
    {
        sceCtrlReadBufferPositive(&padData, 1);

        if (padData.Buttons & PSP_CTRL_CROSS)
        {
            pspDebugScreenPrintf("X Pressed!\n");
        }
    }

    return 0;
}