TYPE = application
PROJECTNAME = PeltierControl

DEPS += gpiopinio controller i2cio \
    cdplogger

HEADERS += Libraries.h
SOURCES += CDPMain.cpp

DISTFILES += \
    $$files(*.xml, true) \
    $$files(*.lic, true) \
    $$files(Application/www/*.*, true)

load(cdp)
