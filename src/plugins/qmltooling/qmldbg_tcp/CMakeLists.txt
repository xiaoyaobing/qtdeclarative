# Generated from qmldbg_tcp.pro.

#####################################################################
## QTcpServerConnectionFactory Plugin:
#####################################################################

qt_internal_add_plugin(QTcpServerConnectionFactory
    OUTPUT_NAME qmldbg_tcp
    TYPE qmltooling
    SOURCES
        qtcpserverconnection.cpp
        qtcpserverconnectionfactory.h
    PUBLIC_LIBRARIES
        Qt::Network
        Qt::QmlPrivate
)

#### Keys ignored in scope 1:.:.:qmldbg_tcp.pro:<TRUE>:
# OTHER_FILES = "$$PWD/qtcpserverconnection.json"
