#include <iostream>
#include "snapp_ink.hh"

#define CROW_DISABLE_STATIC_DIR
#include "crow.h"
#include "utils.hh"
#include "session_manager.hh"


int main(int argc, char **argv)
{

    crow::SimpleApp app;

    SessionManager manager;

    CROW_ROUTE(app, "/")
    ([]()
     { return "Snapp-ink[STATUS]: Is Running..."; });

    CROW_ROUTE(app, "/register").methods(crow::HTTPMethod::POST)([&manager](const crow::request &req)
                                                                 { 
        
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr)
                return crow::response(crow::BAD_REQUEST,"id not found!");
            manager.update_session(id);

            // print req.headers
            // Print request headers
            std::cout << "Request Headers:" << std::endl;
            for (const auto &header : req.headers)
            {
                std::cout << header.first << ": " << header.second << std::endl;
            }

            std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";

            std::ofstream ofs(file_path, std::ios::binary);
            if (!ofs)
                return crow::response(500, "Failed to open file for writing");

            ofs.write(req.body.data(), req.body.size());
            ofs.close();
            return crow::response(200);
        }
        else return crow::response(crow::UNAUTHORIZED); });

    CROW_ROUTE(app, "/register/target").methods(crow::HTTPMethod::POST)([&manager](const crow::request &req)
                                                                        {
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr)
                return crow::response(crow::BAD_REQUEST, "id not found!");
            manager.update_session(id);

            std::string file_path = std::string("./workplace/") + std::string(id) + "_target.jpg";

            std::ofstream ofs(file_path, std::ios::binary);
            if (!ofs)
                return crow::response(500, "Failed to open file for writing");

            ofs.write(req.body.data(), req.body.size());
            ofs.close();

            return crow::response(200);
        }
        else return crow::response(crow::UNAUTHORIZED); });

    CROW_ROUTE(app, "/filters/grayscale")
    ([&manager](const crow::request &req, crow::response &res)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr){
                res.write("id not found!");
                res.code = crow::BAD_REQUEST;
            }
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";
                auto img = cv::imread(file_path);
                snapp::filters::color::GrayScale::get_filter().apply(img);
                cv::imwrite(file_path, img);
                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }
        else {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/popup/<string>")
    ([&manager](const crow::request &req, crow::response &res, const std::string &filter_name)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";

                auto img = cv::imread(file_path);
                snapp::filters::color::PopUp::get_filter().apply(img);
                cv::imwrite(file_path, img);

                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }
        else  {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/rembg")
    ([&manager](const crow::request &req, crow::response &res)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";

                cv::Mat dummy;
                std::string dummy_path = std::string("./workplace/") + std::string(id) + "_dummy.jpg";
                std::pair<std::string, std::string> src_dst = {file_path, dummy_path};
                snapp::filters::color::RemBG::get_filter().apply(dummy, (void *)&src_dst);
                std::string command = std::string{"mv "} + dummy_path + " " + file_path;
                std::system(command.c_str());

                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }
        else  {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/face-autmentation")
    ([&manager](const crow::request &req, crow::response &res)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {

            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";

                cv::Mat dummy;
                std::string dummy_path = std::string("./workplace/") + std::string(id) + "_dummy.jpg";
                std::pair<std::string, std::string> src_dst = {file_path, dummy_path};
                snapp::filters::ai::FaceAugmentation::get_filter().apply(dummy, (void *)&src_dst);
                std::string command = std::string{"mv "} + dummy_path + " " + file_path;
                std::system(command.c_str());

                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }
        else  {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/sepia")
    ([&manager](const crow::request &req, crow::response &res)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {

            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";

                auto img = cv::imread(file_path);
                snapp::filters::color::Sepia::get_filter().apply(img);
                cv::imwrite(file_path, img);

                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }
        else  {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/face-swap")
    ([&manager](const crow::request &req, crow::response &res)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {

            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string source_file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";
                std::string target_file_path = std::string("./workplace/") + std::string(id) + "_target.jpg";
                std::string processed = target_file_path.substr(0, target_file_path.find_last_of('.'));
                processed += "_processed" + target_file_path.substr(target_file_path.find_last_of('.'), target_file_path.size() - 1);

                std::cout << "processed->" << processed << "\n";

                cv::Mat dummy;
                std::string dummy_path = std::string("./workplace/") + std::string(id) + "_dummy.jpg";
                std::pair<std::string, std::string> src_dst = {source_file_path, target_file_path};
                snapp::filters::ai::FaceSwap::get_filter().apply(dummy, (void *)&src_dst);
                std::string command = std::string{"mv "} + processed + " " + source_file_path;
                std::system(command.c_str());
                std::system((std::string{"rm "} + target_file_path + " " + processed).c_str());

                res.set_static_file_info_unsafe(source_file_path);
            }
            res.end();
        }
        else  {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/colorisation/<string>")
    ([&manager](const crow::request &req, crow::response &res, const std::string &filter_name)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";
                std::string target_path = std::string("./workplace/") + std::string(id) + "_" + filter_name + ".jpg";

                auto img = cv::imread(file_path);
                snapp::filters::color::GrayScale::get_filter().apply(img);
                cv::imwrite(file_path, img);

                cv::Mat dummy;
                std::pair<std::string, std::string> src_dst = {file_path, id};
                snapp::filters::color::Colorisation::get_filter().apply(dummy, (void*)&src_dst);

                std::system((std::string{"mv "} + target_path + " " + file_path).c_str());
                std::system((std::string{"rm ./workplace/"} + id + "_cold.jpg" + " ./workplace/" + id + "_warm.jpg").c_str());
                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }
        else  {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/sketch/<string>")
    ([&manager](const crow::request &req, crow::response &res, const std::string &filter_name)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";

                auto img = cv::imread(file_path);
                snapp::filters::color::Sketch::get_filter().apply(img, (void *)std::atoi(filter_name.c_str()));
                cv::imwrite(file_path, img);

                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }
        else  {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    CROW_ROUTE(app, "/filters/vintage/<string>")
    ([&manager](const crow::request &req, crow::response &res, const std::string &filter_name)
     {
        SNAPP__IF_API_KEY_VALID(req)
        {
            auto id = req.url_params.get("id");
            if (id == nullptr)
                res.write("id not found!");
            else
            {
                manager.update_session(id);
                std::string file_path = std::string("./workplace/") + std::string(id) + "_source.jpg";

                auto img = cv::imread(file_path);
                snapp::filters::color::Mix::get_filter().apply(img, (void*)(std::string{"./assets/old_filters/"} + filter_name + ".jpg").c_str());
                cv::imwrite(file_path, img);

                res.set_static_file_info_unsafe(file_path);
            }
            res.end();
        }else
         {
            res.code = crow::UNAUTHORIZED;
            res.end();
        } });

    // CROW_ROUTE(app, "/terminate-session")
    // ([&manager](const crow::request &req, crow::response &res)
    //  {
    //     SNAPP__IF_API_KEY_VALID(req)
    //     {
    //         auto id = req.url_params.get("id");
    //         if (id == nullptr)
    //             res.write("id not found!");
    //         else
    //         {
    //             manager.update_session(id);
    //             std::string command{"rm"};
    //             command = command + " " + "./workplace/" + std::string{id} + "*";
    //             std::system(command.c_str());
    //         }
    //         res.end();
    //     }else
    //      {
    //         res.code = crow::UNAUTHORIZED;
    //         res.end();
    //     } });

    app.port(18080).multithreaded().run();
    return 0;
}