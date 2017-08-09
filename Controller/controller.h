/**
Controller header file. Include this file in the project to use the library.
*/
#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include "ControllerBuilder.h"

namespace Controller {

/** Instantiate the ControllerBuilder for this object */
ControllerBuilder gControllerBuilder("Controller", __TIMESTAMP__);

}

#endif // CONTROLLER_CONTROLLER_H
