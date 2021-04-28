#pragma once

#include <string>

#include <boost/gil/extension/io/bmp.hpp>

#include "i_image.hpp"

namespace klt
{
    class bmp_image : public i_image
    {
        public:
            bmp_image( std::string &input_filename, std::string &output_filename );
            virtual ~bmp_image();

            void read_image();
            void write_image();

        private:
            std::string m_input_filename;
            std::string m_output_filename;
    };
}

