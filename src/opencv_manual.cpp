#include <cv.hpp>
#include "bea.h"
#include "cvcheck.h"
#include "opencvjs.h"
#include "customTypes.h"
#include <cv.h>

using namespace cv;

namespace opencvjs {

	v8::Handle<v8::Value> JOpenCV::discardMats(const v8::Arguments& args) {
		METHOD_BEGIN(1);
		v8::HandleScope scope; 
		if (args[0]->IsArray()){

			v8::Local<v8::Array> ar = v8::Array::Cast(*args[0]);
			int len = ar->Length();
			for (int k = 0; k < len; k++){
				v8::Handle<v8::Value> val = ar->Get(k);
				if (bea::Convert<cv::Mat*>::Is(val)){
					v8::Handle<v8::Object> obj = val->ToObject();
					cv::Mat* ptr = bea::Convert<cv::Mat*>::FromJS(obj, 0); 
					v8::V8::AdjustAmountOfExternalAllocatedMemory(-(int)(ptr->dataend - ptr->datastart));
					delete ptr;
					obj->SetPointerInInternalField(0, NULL);
				}
			}
		} else {
			if (bea::Convert<cv::Mat*>::Is(args[0])){
				v8::Local<v8::Object> obj = args[0]->ToObject();
				cv::Mat* ptr = bea::Convert<cv::Mat*>::FromJS(obj, 0); 
				v8::V8::AdjustAmountOfExternalAllocatedMemory(-(int)(ptr->dataend - ptr->datastart));
				delete ptr;
				obj->SetPointerInInternalField(0, NULL); 
			}
		}
		return args.This();
		METHOD_END();
	}


	v8::Handle<v8::Value> JOpenCV::cvSmooth(const v8::Arguments& args) {
		METHOD_BEGIN(2);
		//void cvSmooth(const Mat& src, Mat& dst, int smoothtype=CV_GAUSSIAN, int param1=3, int param2=0, double param3=0, double param4=0)
		cv::Mat* src = bea::Convert<cv::Mat*>::FromJS(args[0], 0);
		cv::Mat* dst = bea::Convert<cv::Mat*>::FromJS(args[1], 1);
		int smoothtype = bea::Optional<int>::FromJS(args, 2, CV_GAUSSIAN);
		int param1 = bea::Optional<int>::FromJS(args, 3, 3);
		int param2 = bea::Optional<int>::FromJS(args, 4, 0);
		double param3 = bea::Optional<double>::FromJS(args, 5, 0);
		double param4 = bea::Optional<double>::FromJS(args, 6, 0);

		CvMat cvSrc = *src; 
		CvMat cvDst = *dst;
		
		::cvSmooth(&cvSrc, &cvDst, smoothtype, param1, param2, param3, param4);
		return args.This();
		METHOD_END();
	}

		
	v8::Handle<v8::Value> JOpenCV::fillPoly(const v8::Arguments& args) {
		METHOD_BEGIN(5);
		// void fillPoly(Mat& img, const Point** pts, const int* npts, int ncontours, const Scalar& color, int lineType=8, int shift=0, Point offset=Point())
		//TODO: Enter code here
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::getTextSize(const v8::Arguments& args) {
		METHOD_BEGIN(5);
		// Size getTextSize(const std::string& text, int fontFace, double fontScale, int thickness, int* baseLine)
		//TODO: Enter code here
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::polylines(const v8::Arguments& args) {
		METHOD_BEGIN(6);
		// void polylines(Mat& img, const Point** pts, const int* npts, int ncontours, bool isClosed, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
		//TODO: Enter code here
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::kmeans(const v8::Arguments& args) {
		METHOD_BEGIN(7);
		// double kmeans(const Mat& samples, int clusterCount, Mat& labels, TermCriteria termcrit, int attempts, int flags, Mat* centers)
		//TODO: Enter code here
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::calcHist(const v8::Arguments& args) {
		METHOD_BEGIN(8);
		// void calcHist(const Mat* arrays, int narrays, const int* channels, const Mat& mask, SparseMat& hist, int dims, const int* histSize, const float** ranges, bool uniform=true, bool accumulate=false)
		//TODO: Enter code here
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::calcBackProject(const v8::Arguments& args) {
		METHOD_BEGIN(6);
		// void calcBackProject(const Mat* arrays, int narrays, const int* channels, const SparseMat& hist, Mat& backProject, const float** ranges, double scale=1, bool uniform=true)
		//TODO: Enter code here
		return args.This();
		METHOD_END();
	}
	
	v8::Handle<v8::Value> JOpenCV::detectObject(const v8::Arguments& args) {
		METHOD_BEGIN(3);
		// std::vector<cv::Rect> detectObject(const std::string& cascadeName, int imageWidth, int imageHeight)
		//TODO: Enter code here
		return args.This();
		METHOD_END();
	}
	
}
