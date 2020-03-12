#include "opencv2/opencv.hpp"
#include <iostream>
#include "FileOperation.hpp"


int main( int argc, char* argv[] )
{
	if( argc!=2 )
	{
		std::cout<<"Illegal input format"<<std::endl;
		std::cout<<"Require one parameter: route towards the directory of targeted photos"<<std::endl;
		std::cout<<"To translate from any version to JPG"<<std::endl;
	}
	std::string path = argv[1];
	std::vector<std::string> imgList;
	FindAllPictures(path,imgList);
	for( auto img: imgList )
	{
		cv::Mat picture = cv::imread(img);
		if( !picture.empty() )
		{
			cv::imwrite(ReplaceSuffix(img,"jpg"),picture);
		}
		std::cout<<img<<" completed"<<std::endl;
	}
	return 0;
}