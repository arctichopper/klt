#include <fstream>

#include "png_image.hpp"

namespace klt
{
    png_image::png_image( std::string &input_filename, std::string &output_filename ) :
        m_input_filename( input_filename ),
        m_output_filename( output_filename )
    {
    }

    png_image::~png_image()
    {
    }

    image_t& png_image::get_image()
    {
        return m_image;
    }

    void png_image::read_image()
    {
        std::ifstream in( m_input_filename.c_str(), std::ios::binary );
        boost::gil::read_and_convert_image( in, m_image, boost::gil::png_tag() );
    }

    void png_image::write_image()
    {
        std::ofstream out( m_output_filename.c_str(), std::ios_base::binary );
        boost::gil::write_view( out, boost::gil::view( m_image ), boost::gil::png_tag() );
    }
}

