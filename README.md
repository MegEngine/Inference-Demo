Android Camera Inference Demo
===========================

介绍
------------

这是一个基于 [MegEngine](https://github.com/megengine/megengine) C++ 接口和 Android Camera API 开发的简单图像分类安卓应用，
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

- app 示例基于 Gradle 构建系统，如需要构建 apk，在 camera_app/Camera2Basic/ 中使用"gradlew build", 或者使用Android Studio的"Import Project"功能
- app 所依赖的 native 动态库，由 cmake 构建，可以通过 native/shufflenet_interface/ 中 build_inference.sh完成编译
