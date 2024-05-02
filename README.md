# CustomActorColoration プラグイン
![image](https://github.com/pafuhana1213/UE5_CustomActorColoration/assets/8957600/308764a6-e9a8-479e-82f1-4e0ba003b19c)

UE5.4にて改良されたActor Coloration機能を用いて、各Actor・PrimitiveComponentのプロパティが特定の条件を満たすか否かを可視化するプラグインです。
現在対応しているプロパティは以下の通りです。

This is a plugin that uses the improved Actor Coloration feature in UE5.4 to visualize whether the properties of each Actor and PrimitiveComponent meet certain conditions. The currently supported properties are as follows:

- CastShadow
- Capsule Direct/Indirect Shadow
- Physical Material
- Collision Preset

「プロジェクト設定->Plugins->CustomActorColoration」から各項目のONOFF・色設定を変更可能です。  
設定内容は Configs/DefaultCustomActorColoration.iniに保存されます。

You can change the ON/OFF and color settings for each item from "Project Settings->Plugins->CustomActorColoration".
The settings are saved in Configs/DefaultCustomActorColoration.ini.

![image](https://github.com/pafuhana1213/UE5_CustomActorColoration/assets/8957600/1538e057-4e27-4576-9e62-5ea206f84c73)

ActorColorationの項目を追加・編集したい場合は、CustomActorColorationRegister.cpp のコンストラクタの実装をご確認ください。

If you want to add or edit an ActorColoration item, please check the implementation of the constructor in CustomActorColorationRegister.cpp.

# Explanation
準備中
In preparation

# Engine Version
UE5.4

# Author
https://twitter.com/pafuhana1213
