#include <fstream>

#include "jpeg_image.hpp"

namespace klt
{
    jpeg_image::jpeg_image( std::string &input_filename, std::string &output_filename ) :
        m_input_filename( input_filename ),
        m_output_filename( output_filename )
    {
    }

    jpeg_image::~jpeg_image()
    {
    }

    void jpeg_image::read_image()
    {
        std::ifstream in( m_input_filename.c_str(), std::ios::binary );
        boost::gil::read_image( in, m_image, boost::gil::jpeg_tag() );
    }

    void jpeg_image::write_image()
    {
        std::ofstream out( m_output_filename.c_str(), std::ios_base::binary );
        boost::gil::write_view( out, boost::gil::view( m_image ), boost::gil::jpeg_tag() );
    }
}

