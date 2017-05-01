#pragma once
#include"Player.h"
#include "Button.h"
#include "Map.h"

namespace game_framework {
    class UI {
    public:
        UI();
        CMovingBitmap house[4][4][40]; // 4 users 4 levels 40 houses
        void LoadBitmap();
        void OnShow();
        void OnMove();
        void SetXY(int playerX, int playerY, int speed);
        int GetSx();
        int GetSy();
        int GetPlayerRun();
        int GetAmount();
        void RollDice();
        int GetState();
        void SetAmount(int a);
        void SetState(int n);
        void SetButton(int s);
        void OnMouseMove(UINT nFlags, CPoint point);
        void OnLClick(CPoint point);
        void OnRClick(CPoint point);
        int GetPickedProp();
        int GetYesOrNoBuy();
        bool GetCardDisplay();
        void SetMyGame(CGameStateRun *mygame);
        void OnShowMessage();
        void SetMessage(int type, int Money);
        void SetDisplay(bool displayMessage);
		void SetDiceValue(int d1, int d2);
        void initFollowMouse();
        void RandomEvent();
        int GetEvent();
        int GetNowUseProp();
        int GetFollowMouse();
        void InitEvent();
        void UseProp(int prop);
        void UseRemoteDice(CPoint point);
        
    protected:
        CGameStateRun *myGame;              // 讀mygme資訊
        CMovingBitmap status_background;    // 狀態欄
        CMovingBitmap miniMap;              // 小地圖
        CMovingBitmap messageFrame;         // 訊息框架
        CMovingBitmap cardFrame;            // 道具欄
        CMovingBitmap props[15];            // 道具
        CMovingBitmap event[10];            // 事件
        int sx, sy;                         // 螢幕座標
        Dice dice[2];
        Dice remoteDice[6];
        Number number[2];
        Button *yesButton = new Button(), *noButton = new Button();
		Button *cardButton = new Button(1);
        int amount;
        int state = 0;                      // 0 開始 > 1擲骰 > 2骰停傳值 > 3人物移動中 > 可以買地跳4做 可以升級跳5 延遲6 事件7 使用道具8
        int messageType;                    // 訊息類型 1 買地 2 升級
        int money;                          // 金額訊息
        bool displayMessage;
        bool displayCardFrame;
        bool displayRemoteDice;
        int followMouse;
        int followX, followY;
        char *propName[15];
        void ShowPropFields();
        void ShowPropText();
        void ShowProp();
        void ShowMiniMap();
        int enevtIndex = 4;
        int showEvent = 99;
        int tempX = 0, tempY = 0;           // 抓道具座標
        int prop;                           // 所選取的座標
    };
}