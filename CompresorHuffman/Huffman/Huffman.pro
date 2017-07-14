
QT += widgets

HEADERS = droparea.h \
          dropsitewindow.h \
    huffman.h
SOURCES = droparea.cpp \
          dropsitewindow.cpp \
          main.cpp \
    huffman.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/draganddrop/dropsite
INSTALLS += target
