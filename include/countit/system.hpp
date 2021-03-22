
#pragma once
#ifdef _WIN32
#include <filesystem>
#include <stdio.h>
#include <Windows.h>
#else
#include <experimental/filesystem>
#endif    // _WIN32

namespace robertobernabe::countit
{
#ifdef _WIN32
    namespace stdfs = std::filesystem;
#else
    namespace stdfs = std::experimental::filesystem;
#endif

    class System
    {
    public:
        static std::string get_user_home_directory()
        {
#ifdef _WIN32
            // TODO: use getenv_s instead of getenv
            // But using this here is okay, because getenv is not called in a threaded
            // env here.
            auto path = std::string(std::getenv("HOMEDRIVE")) + std::string(std::getenv("HOMEPATH"));
#elif __linux
            auto path = std::string(std::getenv("HOME"));
#endif
            return path;
        }

        static void set_locale_utf8()
        {
#ifdef _WIN32
            setlocale(LC_ALL, "en_US.UTF-8");
#elif __linux

#endif
        }

        static stdfs::path create_and_get_tmp_dir_path(std::string prefix = "countit")
        {
            stdfs::path tmp_dir_path{ stdfs::temp_directory_path() /= prefix };
            tmp_dir_path = tmp_dir_path / std::tmpnam(nullptr);
            // Attempt to create the directory.
            stdfs::create_directories(tmp_dir_path);

            // If that failed an exception will have been thrown
            // so no need to check or throw your own

            // Directory successfully created.
            return tmp_dir_path;
        }
    };

}    // namespace robertobernabe::whour
