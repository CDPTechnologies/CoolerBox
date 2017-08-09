CDPVERSION = 4.2
TYPE = library
PROJECTNAME = Controller

DEPS += \

HEADERS += \
    controller.h \
    ControllerBuilder.h \
    SystemControl.h

SOURCES += \
    ControllerBuilder.cpp \
    SystemControl.cpp

DISTFILES += $$files(*.xml, true) \
    Templates/Models/Controller.SystemControl.xml

load(cdp)
