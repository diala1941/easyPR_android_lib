#include <jni.h>
#include <opencv2/opencv.hpp>
#include <android/log.h>
#include <string>
#include <vector>
#include <sstream>
#include "fstream"
#include "util.h"
#include "easypr.h"
#include "easypr/util/switch.hpp"

#include "main.h"

using namespace std;
using namespace cv;
using namespace easypr;
#include <android/log.h>

#define LOG_TAG "System.out"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_airwen_recognizer_plate_PlateRecognizer_stringFromJNI(JNIEnv *env, jclass instance) {
    return env->NewStringUTF("Hello from JNI !  Compiled with ABI.");
}

char* jstring2str(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;

	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("utf-8"); // "GB2312"
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char *)malloc(alen + 1);
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	return rtn;
}

JNIEXPORT jbyteArray JNICALL Java_com_airwen_recognizer_plate_PlateRecognizer_plateRecognize(JNIEnv *env, jclass instance, jstring imgpath) {
        LOGI("plateRecognition entering");
        CPlateRecognize *pr = new CPlateRecognize();
        pr->setDebug(false);
        pr->setLifemode(true);
        pr->setMaxPlates(4);
        pr->setResultShow(false);
        pr->setDetectType(PR_DETECT_CMSER);

        //	const string *img = (*env)->GetStringUTFChars(env, imgpath, 0);
        char* img = jstring2str(env, imgpath);
        Mat src = imread(img);
        std::vector<std::string> plateVec;
        int count = pr->plateRecognize(src, plateVec);
        std::string str = "0";
        if(! plateVec.empty() && count == 0) {
            str = plateVec[0];
        }
        char *result = new char[str.length() + 1];
        strcpy(result, str.c_str());
        jbyte *by = (jbyte*) result;
        jbyteArray jarray = env->NewByteArray(strlen(result));
        env->SetByteArrayRegion(jarray, 0, strlen(result), by);

        delete pr;

	    return jarray;
}
