
Android Camra Shufflenet Inference Demo
===========================

介绍
------------

这是一个基于MegEngine C++接口和Android Camera API开发的简单图像分类安卓应用，
可以给大家展示如何在Android终端上基于相机预览实现实时图像分类。

最低配置
--------------

- Android SDK 27+
- Android NDK r17+
- Android Studio 3.5+
- gradle 5.6.4
- cmake 3.6


如何开始
---------------

- app 示例基于Gradle构建系统，如需要构建apk，在camera_app/Camera2Basic/ 中使用"gradlew build", 或者使用Android Studio的"Import Project"功能
- app 所依赖的native 动态库，由cmake 构建，可以通过native/shufflenet_interface/ 中 build_inference.sh完成编译
