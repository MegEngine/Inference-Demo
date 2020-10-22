Android Camera Inference Demo
===========================

介绍
------------

这是一个基于 [MegEngine](https://github.com/megengine/megengine) C++ 接口和 Android Camera API 开发的简单图像分类安卓应用，
可以给大家展示如何在 Android 终端上基于相机预览实现实时图像分类。

最低配置
--------------

- Android SDK 27+
- Android NDK r17+
- Android Studio 3.5+
- gradle 5.6.4
- cmake 3.6


如何开始
---------------

- camera_app 示例基于 Gradle 构建系统，如需要构建 apk，可以在 camera_app/Camera2Basic/ 中使用"gradlew build", 或者使用 Android Studio 的"Import Project"功能导入工程，然后构建；
- 构建 app 需要先构建 app 依赖的 native 动态库(具体参考 camera_app 的 jniLibs 目录下的 libmegengine.so、libshufflenet_inference.so)
- libshufflenet_inference.so 由native/shufflenet_interface构建，可以通过 native/shufflenet_interface/ 中 build_inference.sh 完成编译；
- libmegengine.so 的编译请参考 [MegEngine](https://github.com/megengine/megengine) 官方文档
- 模型以资源文件打包到app， 更新模型参考 [MegEngine ModelHub](https://megengine.org.cn/model-hub/)
