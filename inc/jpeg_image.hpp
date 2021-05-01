#pragma once

#include <string>

#include <boost/gil/extension/io/jpeg.hpp>

#include "i_image.hpp"

namespace klt
{
    // TODO: use any_image from https://www.boost.org/doc/libs/1_75_0/libs/gil/doc/html/io.html to read JPEG format correctly
    class jpeg_image : public i_image
    {
        public:
            jpeg_image( std::string &input_filename, std::string &output_filename );
            virtual ~jpeg_image();

            void read_image();
            void write_image();

        private:
            boost::gil::rgb8_image_t m_image;
            std::string& m_input_filename;
            std::string& m_output_filename;
    };
}

