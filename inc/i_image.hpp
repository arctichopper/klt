#pragma once

#include <string>

#include <boost/gil/io/typedefs.hpp>

namespace klt
{
    class i_image
    {
        public:
            virtual void read_image() = 0;
            virtual void write_image() = 0;
    };
}

