#RKMediaPlayer

|版本 |修订内容|作者|时间|
|----|-------|----|----|
|v1.0|初稿|贾斌|2017.7.20|
|


| Tables        | Are           | Cool  |
| ------------- |:-------------:| -----:|
| col 3 is      | right-aligned | $1600 |
| col 2 is      | centered      |   $12 |
| zebra stripes | are neat      |    $1 |


##简介

RKContext用于提供给开发者在一个skill应用里创建组件的sdk，包含RokidState和BackStage两种组件，具有生命周期。

##核心
###RKBaseTask
抽象类，每个应用有且只有一个类继承RKBaseTask，该类为该应用的入口，具有该应用的生命周期

|函数名 | 描述  |
|----- | -----|
|onCreate |该应用被创建启动 |
|onResume|该应用运行可执行状态 |
|onPause|该应用被其他应用打断处于暂停状态 |
|onDestory|该应该被销毁 |
|onNlpMessage|收到nlp消息 |
|……| |
|startState|启动一个state|
|finishState|结束一个state|
|inflate|创建view|
|startBackStage|启动一个backstage|
|stopBackStage|结束一个backstage|
|stopAllBackStage|结束所有backstage|

**\*注：RKBaseTask的函数可被override，但是不要去掉super方法。**

##组件
###RokidState
1. state的特性是可创建界面的前台组件，运行在主线程，分为两种类型:CutState，SceneState.
开发者应该继承这两种类型的state进行开发。
开发者要想使用state需要通过RokidStateFactory的registerRokidState方法注册自己的state。

2. 在RKBaseTask和state中都可以使用startState来启动一个state，启动同一个类型的state不会创建新的state对象，而是复用当前没有销毁的state对象，即不会调用onStateCreate，如果有数据参数只会调用onReceiveData

3. 创建一个state需要实现inflateContentView方法，可通过inflate函数创建view

4. 一个task中只能同时存在一个cut和一个scene，并且scene在cut的下面

>**举例**
>
>1)  cutA -> cutB
>
>>A会被销毁， A的onStateDestroy和B的onStateCreate会被调用，B调用finish的时候不能回到A
>
>2)  cutA -> sceneA
>>同1
>
>3)  sceneA -> sceneB
>>同1
>
>4)  sceneA -> cutA
>>sceneA不会销毁，sceneA的onStatePause和cutA的onStateCreate会被调用，cutA调用finish的时候可以回到sceneA，sceneA的onStateResume会被调用
>
>5） sceneA -> cutA -> sceneA
>>第一步同4，再从cutA起sceneA的时候，cutA执行onStateDestroy，sceneA执行onStateResume，和cutA调用finish效果一样
>
>6） sceneA -> cutA -> sceneB
>>第一步同4，再从cutA起sceneB的时候，cutA和sceneA都执行onStateDestroy，sceneB执行onStateCreate
>
>7） cutA -> cutA
>>如果startState参数带data，只会调用cutA的onReceiveData，其他的生命周期都不会被调用


|函数名 | 描述  |
|----- | -----|
|onStateCreate |该state被创建启动 |
|onStateResume|该state被恢复，只会出现在scene中 |
|onStatePause |该state被暂停，只会出现在scene中 |
|onStateDestroy|该state被销毁 |
|onReceiveData|收到其他组件传来的消息 |
|……| |
|startState| 启动一个state|
|startBackStage|启动一个backstage |
|finish| 结束自己|
|inflate| 创建view|

**\*注：state中可以复写onCreate、onResume、onPause、onDestory等函数来监测RKBaseTask的生命周期，复写onNlpMessage来收取nlp信息**

---
###BackStage
1. 该组件不参与state的活动，即，不受state启动和生命周期的影响，没有界面，用于做一些后台的逻辑，运行在主线程，BackStage的启动不会影响其他已启动的BackStage和state的生命周期，BackStage可同时存在多个。

2. 开发者继承BackStage进行开发。
开发者要想使用BackStage需要通过BackStageFactory的registerBackStage方法注册自己的BackStage。

3. 在RKBaseTask、state和BackStage中都可以使用startBackStage来启动一个BackStage，启动同一个类型的BackStage不会创建新的BackStage对象，而是复用当前没有销毁的BackStage对象，即不会调用onStateCreate，如果有数据参数只会调用onReceiveData

4. 可在BackStage调用stopSelf，或在RKBaseTask和state中调用stopBackStage来停止，此时onBackStageDestroy会被调用。如果RKBaseTask被销毁了，所有的活着的BackStage都会被调用onBackStageDestroy。


|函数名 | 描述  |
|----- | -----|
|onBackStageCreate |该BackStage被创建启动 |
|onBackStageDestroy|该BackStage被销毁 |
|onReceiveData|收到其他组件传来的消息 |
|……| |
|stopSelf| 结束自己|

**\*注：BackStage中可以复写onCreate、onResume、onPause、onDestory等函数来监测RKBaseTask的生命周期，复写onNlpMessage来收取nlp信息**