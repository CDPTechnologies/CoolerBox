/**
ControllerBuilder implementation.
*/

#include "SystemControl.h"
#include "ControllerBuilder.h"

using namespace Controller;

ControllerBuilder::ControllerBuilder(const char* libName, const char* timeStamp)
    : CDPBuilder(libName, timeStamp)
{
}

CDPComponent* ControllerBuilder::CreateNewComponent(const std::string& type)
{
    if (type=="Controller.SystemControl")
        return new SystemControl;
    
    return CDPBuilder::CreateNewComponent(type);
}

CDPBaseObject* ControllerBuilder::CreateNewCDPOperator(const std::string& modelName, const std::string& type, const CDPPropertyBase* inputProperty)
{
    return CDPBuilder::CreateNewCDPOperator(modelName, type, inputProperty);
}
