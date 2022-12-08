#include "Pages/AppFactory.h"

#define ACCOUNT_SEND_CMD(ACT, CMD) \
do{ \
    DataProc::ACT##_Info_t info; \
    DATA_PROC_INIT_STRUCT(info); \
    info.cmd = DataProc::CMD; \
    DataProc::Center()->AccountMain.Notify(#ACT, &info, sizeof(info)); \
}while(0)

void App_Init()
{
    static AppFactory factory;
    static PageManager manager(&factory);

    /* Initialize status bar */
    //Page::StatusBar_Create(lv_layer_top());

    /* Initialize pages */
    /*manager.Install("Template",    "Pages/_Template");
    manager.Install("LiveMap",     "Pages/LiveMap");
    manager.Install("Dialplate",   "Pages/Dialplate");
    manager.Install("SystemInfos", "Pages/SystemInfos");
    manager.Install("Startup",     "Pages/Startup");

    manager.SetGlobalLoadAnimType(PageManager::LOAD_ANIM_OVER_TOP);

    manager.Push("Pages/Startup");*/
}

void App_Uninit()
{
    //ACCOUNT_SEND_CMD(SysConfig, SYSCONFIG_CMD_SAVE);
    //ACCOUNT_SEND_CMD(Storage,   STORAGE_CMD_SAVE);
    //ACCOUNT_SEND_CMD(Recorder,  RECORDER_CMD_STOP);
}
