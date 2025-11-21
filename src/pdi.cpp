#include "pdi.hpp"

namespace phosphor
{
    pdi::pdi(sdbusplus::bus_t &bus, const std::string &path) 
        : Ifaces(bus, path.c_str(), Ifaces::action::defer_emit)
    {
        this->emit_object_added();
    }

    int32_t pdi::getValue()
    {
        return this->value();
    }

    void pdi::setValue(int32_t value)
    {
        this->value(value);
    }
}