QT += charts
QT += sql

SOURCES += \
    main.cpp \
    linedistribution.cpp \
    exceladapter.cpp \
    paintwx.cpp \
    castinground.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
INSTALLS += target

HEADERS += \
    linedistribution.h \
    exceladapter.h \
    paintwx.h \
    castinground.h
