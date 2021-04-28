#include "image_helper.hpp"

#include <iostream>
#include <stdexcept>

namespace klt
{
    image_helper::image_helper( std::string& input_filename, std::string& output_filename ) :
        m_input_filename( input_filename ),
        m_file_extension( "" ),
        m_file_type(),
        m_output_filename( output_filename )
    {
        try
        {
            m_file_extension = get_file_extension();
        }
        catch( std::exception& e )
        {
            std::cout << "Error reading extension: " << e.what() << std::endl;
        }
    }

    void image_helper::set_input_filename( std::string& input_filename )
    {
        m_input_filename = input_filename;
        m_file_extension = get_file_extension();
    }

    std::string image_helper::get_input_filename()
    {
        return m_input_filename;
    }

    void image_helper::set_output_filename( std::string& output_filename )
    {
        m_output_filename = output_filename;
    }

    std::string image_helper::get_output_filename()
    {
        return m_output_filename;
    }

    std::string image_helper::get_file_extension()
    {
        if( m_input_filename.empty() )
            return "";

        auto n = m_input_filename.rfind( '.' );
        if( n == std::string::npos )
            throw std::runtime_error( "No extension found." );
        else
            if( auto s = m_input_filename.substr( n + 1 );
                s.empty() )
                throw std::runtime_error( "Empty file extension." );
            else
                return s;
    }

    int image_helper::get_file_type()
    {
        if( m_file_extension.empty() )
            return m_file_type;

        if( m_file_extension == "bmp" )
            return klt_type_bmp;
        else if( m_file_extension == "png" )
            return klt_type_png;
        else if( m_file_extension == "jpeg" )
            return klt_type_jpeg;
    }
}

