#include "PageBase.h"
#include "PM_Log.h"

void PageBase::SetCustomCacheEnable(bool en)
{
    PM_LOG_INFO("Page(%s) %s = %d", _Name, __func__, en);
    SetCustomAutoCacheEnable(false);
    priv.ReqEnableCache = en;
}

void PageBase::SetCustomAutoCacheEnable(bool en)
{
    PM_LOG_INFO("Page(%s) %s = %d", _Name, __func__, en);
    priv.ReqDisableAutoCache = !en;
}

void PageBase::SetCustomLoadAnimType(
    uint8_t animType,
    uint16_t time
)
{
    priv.Anim.Attr.Type = animType;
    priv.Anim.Attr.Time = time;
}

bool PageBase::StashPop(void* ptr, uint32_t size)
{
    if (priv.Stash.ptr == nullptr)
    {
        PM_LOG_WARN("No Stash found");
        return false;
    }

    if (priv.Stash.size != size)
    {
        PM_LOG_WARN(
            "Stash[0x%p](%d) does not match the size(%d)",
            priv.Stash.ptr,
            priv.Stash.size,
            size
        );
        return false;
    }

    priv.Stash.ptr = nullptr;
    return false;
}