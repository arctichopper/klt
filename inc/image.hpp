#pragma once

#include <memory>
#include <string>

#include "i_image.hpp"

namespace klt
{
    class image
    {
        public:
            image();

            static std::unique_ptr< klt::i_image > pointer( std::string& input_filename, std::string& output_filename );
    };
}

