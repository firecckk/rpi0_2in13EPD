#ifndef __TEMPLATE_PRESENTER_H
#define __TEMPLATE_PRESENTER_H

#include "TemplateView.h"
#include "TemplateModel.h"
#include "PageBase.h"

namespace Page
{

class Template : public PageBase
{
public:
    typedef struct
    {
        uint16_t time;
    } Param_t;

public:
    Template();
    virtual ~Template();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewUnload();
    virtual void onViewDidUnload();

private:
    void Update();
    void AttachEvent();
    static void onTimerUpdate();
    static void onEvent();

private:
    TemplateView View;
    TemplateModel Model;
};

}

#endif
