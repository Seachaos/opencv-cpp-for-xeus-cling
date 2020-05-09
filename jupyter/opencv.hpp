#ifndef JUPYTER_OPENCV_TOOL
#define JUPYTER_OPENCV_TOOL
#include <jupyter/jupyter_opencv_include.h>

#include <string>
#include <fstream>

#include <xcpp/xdisplay.hpp>
#include <opencv2/highgui.hpp>

#include "xtl/xbase64.hpp"
#include "nlohmann/json.hpp"

namespace im
{
    struct image
    {
        inline image(const std::string& filename)
        {
            std::ifstream fin(filename, std::ios::binary);
            m_buffer << fin.rdbuf();
        }
        inline image(const cv::Mat &image)
        {
            std::vector<uchar> buffer;
            cv::imencode(".png", image, buffer);

            std::string buf_as_str(buffer.begin(), buffer.end());
            m_buffer << buf_as_str;
        }

        std::stringstream m_buffer;
    };

    nlohmann::json mime_bundle_repr(const image& i)
    {
        auto bundle = nlohmann::json::object();
        bundle["image/png"] = xtl::base64encode(i.m_buffer.str());
        return bundle;
    }
    
    image mat_show(cv::Mat &img)
    {
        image i(img);
        xcpp::display(i);
        return i;
    }
}
namespace cv
{
    void imshow(std::string name, Mat &img) {
        im::mat_show(img);
    }
}

#endif