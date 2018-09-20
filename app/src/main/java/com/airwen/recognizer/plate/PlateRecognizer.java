package com.airwen.recognizer.plate;

/**
 * Created by ares on 6/19/16.
 */
public class PlateRecognizer {

    /**
     * JNI Functions
     * 加载车牌识别库
     */
    static {
        try {
            System.loadLibrary("opencv_java3");
            System.loadLibrary("EasyPR");
        } catch (UnsatisfiedLinkError ule) {
            System.err.println("WARNING: Could not load EasyPR library!");
            ule.printStackTrace();
        }
    }

    public static native String stringFromJNI();
//    public static native long initPR(String svmpath, String annpath);
//    public static native long uninitPR(long recognizerPtr);
//    public static native byte[] plateRecognize(long recognizerPtr, String imgpath);
    public static native byte[] plateRecognize(String imgpath);

}
