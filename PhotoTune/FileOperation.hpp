#pragma once
#include <filesystem>
#include <vector>

/*
OpenCV version used is 4.1.1, https://docs.opencv.org/4.1.1/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56
C++ 17 is required
Author Yixuan Wei
Created August 31 2019
*/


std::string ReplaceSuffix( std::string& inputString, const char* suffix );

void FindAllPictures( std::string& targetPath, std::vector<std::string>& result );
void FindAllPicturesWidePath( std::wstring& targetPath, std::vector<std::wstring>& result );
