#pragma once

#include <string>

namespace klt
{
    class image_helper
    {
        public:
            enum type_code
            {
                klt_type_bmp,
                klt_type_png,
                klt_type_jpeg
            };

            image_helper( std::string& input_filename, std::string& output_filename );

            void set_input_filename( std::string& input_filename );
            std::string get_input_filename();

            void set_output_filename( std::string& output_filename );
            std::string get_output_filename();

            std::string get_file_extension();
            int get_file_type();

        private:
            std::string& m_input_filename;
            std::string  m_file_extension;
            int          m_file_type;
            std::string& m_output_filename;
    };
}
