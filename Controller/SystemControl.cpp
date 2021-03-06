#include "SystemControl.h"

using namespace Controller;

SystemControl::SystemControl()
{
}

SystemControl::~SystemControl()
{
}

void SystemControl::Create(const char* fullName)
{
    CDPComponent::Create(fullName);
    reqTemp.Create("reqTemp",this);
    fan.Create("fan",this);
    hotPeltier.Create("hotPeltier",this);
    coldPeltier.Create("coldPeltier",this);
    curTemp.Create("curTemp",this);
    newValue.Create("newValue",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)&SystemControl::setNew,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    newReqValue.Create("newReqValue",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)&SystemControl::newReq,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
    currState.Create("currState",this,CDPPropertyBase::e_Element,(CDPOBJECT_SETPROPERTY_HANDLER)nullptr,(CDPOBJECT_VALIDATEPROPERTY_HANDLER)nullptr);
}

void SystemControl::CreateModel()
{
    CDPComponent::CreateModel();

    RegisterStateProcess("Null", (CDPCOMPONENT_STATEPROCESS)&SystemControl::ProcessNull, "Initial Null state");
    RegisterStateProcess("heatON",(CDPCOMPONENT_STATEPROCESS)&SystemControl::ProcessheatON,"");
    RegisterStateProcess("heatOff",(CDPCOMPONENT_STATEPROCESS)&SystemControl::ProcessheatOff,"");
    RegisterStateTransitionHandler("Null","heatON",(CDPCOMPONENT_STATETRANSITIONHANDLER)&SystemControl::TransitionNullToheatON,"");
    RegisterStateTransitionHandler("heatON","heatOff",(CDPCOMPONENT_STATETRANSITIONHANDLER)&SystemControl::TransitionheatONToheatOff,"");
    RegisterStateTransitionHandler("heatOff","heatON",(CDPCOMPONENT_STATETRANSITIONHANDLER)&SystemControl::TransitionheatOffToheatON,"");
    RegisterStateTransitionHandler("Null","heatOff",(CDPCOMPONENT_STATETRANSITIONHANDLER)&SystemControl::TransitionNullToheatOff,"");
    RegisterMessage(CM_TEXTCOMMAND,"ResetDefault","Resets settings to Default",(CDPOBJECT_MESSAGEHANDLER)&SystemControl::MessageResetDefault);
}

void SystemControl::Configure(const char* componentXML)
{
    CDPComponent::Configure(componentXML);
}


void SystemControl::ProcessNull()
{
    requestedState = (curTemp >= reqTemp) ? "heatOff" : "heatON";
}



void SystemControl::ProcessheatON()
{
    currState.SetValue("Heating");
    hotPeltier = true;
    coldPeltier = false;
    fan = false;
    requestedState = (curTemp >= reqTemp) ? "heatOff" : "heatON";
}



void SystemControl::ProcessheatOff()
{
    currState.SetValue("Cooling");
    hotPeltier = false;
    coldPeltier =  true;
    fan = true;
    requestedState = (curTemp >= reqTemp) ? "heatOff" : "heatON";
}



bool SystemControl::TransitionNullToheatON()
{
    if(requestedState=="heatON")
        return true;
    else
        return false;
}



bool SystemControl::TransitionheatONToheatOff()
{
    if(requestedState=="heatOff")
        return true;
    else
        return false;
}



bool SystemControl::TransitionheatOffToheatON()
{
    if(requestedState=="heatON")
        return true;
    else
        return false;
}



bool SystemControl::TransitionNullToheatOff()
{
    if(requestedState=="heatOff")
        return true;
    else
        return false;
}



int SystemControl::MessageResetDefault(void* message)
{
    requestedState = "Null";
    return 1;

}

void SystemControl::newReq(CDPPropertyBase* pProperty)
{
    reqTemp = std::atof(pProperty->GetValue().c_str());
    newValue.SetValue("Custom");
}

void SystemControl::setNew(CDPPropertyBase* pProperty)
{
    if(pProperty->GetValue() == "Beer")
    {
        reqTemp = 6.0;
    }
    else if(pProperty->GetValue() == "Wine")
    {
        reqTemp = 7.0;
    }
    else if(pProperty->GetValue() == "Tomato")
    {
        reqTemp = 21.0;
    }
    else if(pProperty->GetValue() == "Custom")
    {
        reqTemp = (double)newReqValue;
    }
}
