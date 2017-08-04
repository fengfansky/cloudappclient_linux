#RKAudioPlayer

|版本 |修订内容|作者|时间|
|----|-------|----|----|
|v1.0|初稿|冯帆|2017.7.24|

##简介

RKAudioPlayer 是针对Falcon系统进行开发的音视频播放器，目前只支持音频播放，可以播放本地和网络媒体文件。


###函数定义

|函数 |   |
|----- | -----|
|setDataSource(string url)|设置媒体数据|
|setDataSource(string localPath)|本地媒体路径|
|start |开始播放|
|pause|暂停播放|
|resume|继续播放|
|stop|停止播放|
|release|释放播放器对象 |
|reset|重置播放器状态 |
|getDuration|获取音频总时长|
|getCurrentPosition|获取当前播放的位置|
|seekTo(int postion)|跳到指定位置 |

###回调函数
>
