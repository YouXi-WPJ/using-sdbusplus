#include <iostream>
#include <sdbusplus/bus.hpp>
#include <sdbusplus/server/manager.hpp>

#ifdef USE_BOOST
#include <boost/asio.hpp>
#include <sdbusplus/asio/connection.hpp>
#include <sdbusplus/asio/object_server.hpp>
#endif

#ifdef USE_YAML
#include "pdi.hpp"
#endif

#define BUSNAME "xyz.openbmc_project.sdbusplus.example"
#define ObjPath "/xyz/openbmc_project/sdbusplus"
#define Interface "xyz.openbmc_project.sdbusplus.example"

int main()
{
    /* code */
#ifdef USE_BOOST
    boost::asio::io_context io;
    int value = 0;
    auto systemBus = std::make_shared<sdbusplus::asio::connection>(io);
    systemBus->request_name(BUSNAME);
    sdbusplus::asio::object_server objServer(systemBus);
    std::shared_ptr<sdbusplus::asio::dbus_interface> sdbusplusIface =
        objServer.add_interface(ObjPath, Interface);
    
    // Register methods and properties
    sdbusplusIface->register_method("Get", [value]() { 
        return value; 
    });

    sdbusplusIface->register_method("Set", [&](const int newValue) {
        value = newValue;
        return; 
    });

    sdbusplusIface->register_property("value", value, 
        [](const int newValue,int& oldValue) {
            oldValue = newValue + 1;
            return true; 
        },
        [](int value) {
            return value;
        }
    );

    sdbusplusIface->initialize();
    
    io.run();
#endif

#ifdef USE_YAML
    sdbusplus::bus::bus bus = sdbusplus::bus::new_default();
    sdbusplus::server::manager_t objManager(bus, Interface);
    phosphor::pdi pdiObj(bus, Interface);
    bus.request_name(BUSNAME);
    bus.process_loop();
#endif

    return 0;
}
