# easyPR_android_lib
easypr_1.6 Android lib.

easyPR v1.6 android lib。此程序依赖opencv 3.2.0 android lib。

1、android studio 编译需要NDK支持。
2、opencv依赖开发库的配置，easyPR_android_lib\opencv-android-sdk下配置OpenCV-android-sdk，同名目录文件直接替换。
3、程序运行需要的相关资源文件，在另外一个工程当中 easyPR_android\..\assets中，这些文件是由EasyPR生成的识别特征文件，具体参见EasyPR。
4、easyPR 不支持新能源车牌和特殊牌照，一般只能识别单排字牌照。
