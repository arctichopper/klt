#include <fstream>

#include "bmp_image.hpp"

namespace klt
{
    bmp_image::bmp_image( std::string &input_filename, std::string &output_filename ) :
        m_image(),
        m_input_filename( input_filename ),
        m_output_filename( output_filename )
    {
    }

    bmp_image::~bmp_image()
    {
    }

    void bmp_image::read_image()
    {
        std::ifstream in( m_input_filename.c_str(), std::ios::binary );
        boost::gil::read_image( in, m_image, boost::gil::bmp_tag() );
    }

    void bmp_image::write_image()
    {
        std::ofstream out( m_output_filename.c_str(), std::ios_base::binary );
        boost::gil::write_view( out, boost::gil::view( m_image ), boost::gil::bmp_tag() );
    }
}

