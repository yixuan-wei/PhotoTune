#include "FileOperation.hpp"

/*
OpenCV version used is 4.1.1, https://docs.opencv.org/4.1.1/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56
C++ 17 is required
Author Yixuan Wei
Created August 31 2019
*/

//replace the suffix of a string path
std::string ReplaceSuffix( std::string& inputString, const char* suffix)
{
	size_t targetPos = inputString.rfind( "." )+1;
	return inputString.substr( 0, targetPos ) + suffix;
}

//find pictures path in wide char format
void FindAllPicturesWidePath( std::wstring& targetPath, std::vector<std::wstring>& result )
{
	for( auto& p: std::filesystem::directory_iterator( targetPath ) )
	{		
		if( std::filesystem::is_directory(p.path()) )//no extension, should be directory
		{
			std::wstring tempPath = p.path().wstring();
			FindAllPicturesWidePath(tempPath, result);
		}
		else{
			std::wstring suffix = p.path().extension().wstring();
			if( suffix==L".JPG" || suffix==L".PNG" || suffix==L".jpg" || suffix==L".png" ||
				suffix==L".bmp" || suffix==L".BMP" || suffix==L".JPEG" ) //TODO may added more format
			{
				result.push_back(p.path().wstring());
			}
		}
	}
}

//find picture path in char format
void FindAllPictures( std::string& targetPath, std::vector<std::string>& result )
{
	for( auto& p: std::filesystem::directory_iterator( targetPath ) )
	{
		if( std::filesystem::is_directory( p.path() ) )//no extension, should be directory
		{
			std::string tempPath = p.path().string();
			FindAllPictures( tempPath, result );
		}
		else {
			std::string suffix = p.path().extension().string();
			if( suffix==".JPG" || suffix==".PNG" || suffix==".jpg" || suffix==".png" ||
				suffix==".bmp" || suffix==".BMP" || suffix==".JPEG" ) //TODO may added more format
			{
				result.push_back( p.path().string() );
			}
		}
	}
}

//For testing fileoperation.hpp only
//int wmain(int argc, wchar_t* argv[])
//{
//	std::wstring targetPath = L"D:\\Programming\\PhotoTune\\PhotoTune";
//	std::vector<std::wstring> result;
//	FindAllPictures( targetPath, result );
//	std::cout<<"begin to print"<<std::endl;
//	for( auto r: result )
//	{
//		std::wcout<<r<<std::endl;
//	}
//	return 0;
//}