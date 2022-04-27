QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += D:\boost\boost_1_79_0

#LIBS += D:\boost\boost_1_79_0\stage\lib -l boost_system-mgw11-mt-d-x64-1_79
SOURCES += \
    book.cpp \
    bookbase.cpp \
    database.cpp \
    dialogaddbook.cpp \
    dialogaddreader.cpp \
    dialogeditbook.cpp \
    dialogeditreader.cpp \
    dialogfinishrent.cpp \
    dialogrent.cpp \
    dialogshowbook.cpp \
    dialogshowreader.cpp \
    main.cpp \
    library.cpp \
    reader.cpp \
    readerbase.cpp \
    rent.cpp

HEADERS += \
    book.h \
    bookbase.h \
    database.h \
    dialogaddbook.h \
    dialogaddreader.h \
    dialogeditbook.h \
    dialogeditreader.h \
    dialogfinishrent.h \
    dialogrent.h \
    dialogshowbook.h \
    dialogshowreader.h \
    library.h \
    reader.h \
    readerbase.h \
    rent.h

FORMS += \
    dialogaddbook.ui \
    dialogaddreader.ui \
    dialogeditbook.ui \
    dialogeditreader.ui \
    dialogfinishrent.ui \
    dialogrent.ui \
    dialogshowbook.ui \
    dialogshowreader.ui \
    library.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
