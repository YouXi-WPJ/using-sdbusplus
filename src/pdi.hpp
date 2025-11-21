#pragma once

#include <sdbusplus/bus.hpp>
#include <sdbusplus/server/object.hpp>
#include <xyz/pdi/server.hpp>

using CreateIface = sdbusplus::server::xyz::Pdi;
using Ifaces = sdbusplus::server::object_t<CreateIface>;

namespace phosphor
{
    class pdi : public Ifaces
    {
    private:
        /* data */

    public:
        pdi() = delete;
        pdi(const pdi&) = delete;
        pdi& operator=(const pdi&) = delete;
        pdi(pdi&&) = delete;
        pdi& operator=(pdi&&) = delete;
        virtual ~pdi() = default;

        pdi(sdbusplus::bus_t& bus, const std::string& path);
        
        int32_t getValue() override;
        void setValue(int32_t value) override;

    };
}