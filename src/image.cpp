#include <iostream>

#include "bmp_image.hpp"
#include "image.hpp"
#include "image_helper.hpp"
#include "jpeg_image.hpp"
#include "png_image.hpp"

namespace klt
{
    image::image()
    {
    }

    std::unique_ptr< klt::i_image > image::pointer( std::string& input_filename, std::string& output_filename )
    {
        std::unique_ptr< klt::i_image > image;

        try
        {
            std::unique_ptr< klt::image_helper > image_helper = std::make_unique< klt::image_helper >( input_filename, output_filename );

            switch( image_helper->get_file_type() )
            {
                case image_helper::klt_type_bmp:
                    image = std::make_unique< klt::bmp_image >( input_filename, output_filename );
                    break;
                case image_helper::klt_type_png:
                    image = std::make_unique< klt::png_image >( input_filename, output_filename );
                    break;
                case image_helper::klt_type_jpeg:
                    image = std::make_unique< klt::jpeg_image >( input_filename, output_filename );
                    break;
                default:
                    break;
            }
            image->read_image();
        }
        catch( std::exception& e )
        {
            std::cout << "Error getting image pointer: " << e.what() << std::endl;
        }

        return image;
    }
}

