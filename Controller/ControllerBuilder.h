/**
ControllerBuilder header file.
*/

#ifndef CONTROLLER_CONTROLLERBUILDER_H
#define CONTROLLER_CONTROLLERBUILDER_H

#include <CDPSystem/Application/CDPBuilder.h>

namespace Controller {

class ControllerBuilder : public CDPBuilder
{
public:
    ControllerBuilder(const char* libName,const char* timeStamp);
    CDPComponent* CreateNewComponent(const std::string& type) override;
    CDPBaseObject* CreateNewCDPOperator(const std::string& modelName,const std::string& type,const CDPPropertyBase* inputProperty) override;
};

}

#endif // CONTROLLER_CONTROLLERBUILDER_H
