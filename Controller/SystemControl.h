#ifndef CONTROLLER_SYSTEMCONTROL_H
#define CONTROLLER_SYSTEMCONTROL_H

#include <CDPSystem/Base/CDPComponent.h>
#include <Signal/CDPSignal.h>
#include <CDPParameter/CDPParameter.h>
#include <CDPAlarm/CDPAlarm.h>
#include <CDPSystem/Base/CDPProperty.h>
#include <mutex>

namespace Controller {

class SystemControl : public CDPComponent
{
public:
    SystemControl();
    ~SystemControl() override;

    void Create(const char* fullName) override;
    void CreateModel() override;
    void Configure(const char* componentXML) override;
    void ProcessNull() override;
    void ProcessheatON();
    void ProcessheatOff();
    bool TransitionNullToheatON();
    bool TransitionheatONToheatOff();
    bool TransitionheatOffToheatON();
    bool TransitionNullToheatOff();
    int MessageResetDefault(void* message);

protected:
    void newReq(CDPPropertyBase* pProperty);
    void setNew(CDPPropertyBase* pProperty);
    CDPSignal<double> reqTemp;
    CDPSignal<bool> fan;
    CDPSignal<bool> hotPeltier;
    CDPSignal<bool> coldPeltier;
    CDPSignal<double> curTemp;
    CDPProperty<std::string> newValue;
    CDPProperty<double> newReqValue;
    CDPProperty<std::string> currState;
    using CDPComponent::requestedState;
    using CDPComponent::ts;
    using CDPComponent::fs;
    std::once_flag onceFlag;
};

} // namespace Controller

#endif
