#include <iostream>
#include <sdbusplus/bus.hpp>
#include <sdbusplus/server/manager.hpp>

#ifdef USE_BOOST
#include <boost/asio.hpp>
#endif

#ifdef USE_PDI
#include "pdi.hpp"
#endif

#define BUSNAME "xyz.openbmc_project.sdbusplus.example"
#define Interface "/xyz/openbmc_project/sdbusplus"

int main()
{
    /* code */
    sdbusplus::bus::bus bus = sdbusplus::bus::new_default();
    // int counter = 0;
#ifdef USE_BOOST
    boost::asio::io_context io;
    auto systemBus = std::make_shared<sdbusplus::asio::connection>(io, bus);
    sdbusplus::asio::object_server objServer(systemBus);
    std::shared_ptr<sdbusplus::asio::dbus_interface> sdbusplusIface =
        objServer.add_interface(Interface, BUSNAME);
    
    // Register methods and properties
    sdbusplusIface->register_method("Get", [&]() { 
        return counter; 
    });

    sdbusplusIface->register_method("Set", [&](const int value) {
        counter = value;
        return; 
    });

    sdbusplus->register_property("Counter", counter);

    iface->initialize();
#endif

#ifdef USE_PDI
    sdbusplus::server::manager_t objManager(bus, Interface);
    phosphor::pdi pdiObj(bus, Interface);
#endif

    bus.request_name(BUSNAME);

#ifdef USE_BOOST
    io.run();
#else
    bus.process_loop();
#endif
    return 0;
}
