#pragma once

#include <string>

#include <boost/gil/extension/io/png.hpp>

#include "i_image.hpp"

namespace klt
{
    class png_image : public i_image
    {
        public:
            png_image( std::string &input_filename, std::string &output_filename );
            virtual ~png_image();

            void read_image();
            void write_image();

        private:
            std::string m_input_filename;
            std::string m_output_filename;
    };
}

