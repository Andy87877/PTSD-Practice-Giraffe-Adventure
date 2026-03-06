# 🦒 Giraffe Adventure — PTSD 框架練習專案

> 本專案為北科大（NTUT）物件導向程式設計實驗課（OOPL）的練習作業，使用 [PTSD（Practical Tools for Simple Design）](https://github.com/ntut-open-source-club/practical-tools-for-simple-design) 框架開發的小型 2D 遊戲。

---

## 📋 目錄

- [專案簡介](#專案簡介)
- [環境需求](#環境需求)
- [安裝與建置](#安裝與建置)
- [專案結構](#專案結構)
- [遊戲操作說明](#遊戲操作說明)
- [任務關卡說明](#任務關卡說明)
- [核心類別說明](#核心類別說明)
- [開發提示](#開發提示)
- [授權條款](#授權條款)

---

## 專案簡介

Giraffe Adventure 是一個包含 **6 個關卡（Phase）** 的互動練習遊戲。每個關卡都有一個對應的程式設計任務，需要你在程式碼中完成指定的功能。完成後按下 `Enter` 鍵進行驗證，通過後自動進入下一關。

---

## 環境需求

| 項目 | 版本要求 |
|---|---|
| **Git** | 任意版本 |
| **CMake** | ≥ 3.26 |
| **C++ 編譯器** | 支援 C++17（如 MSVC、GCC、Clang） |
| **OpenGL** | 系統需有 OpenGL 實現 |
| **Ninja Build**（選用） | 可加速編譯 |

### 支援的 IDE / 平台

|  | Windows | macOS | Linux |
|:---:|:---:|:---:|:---:|
| CLion | ✅ | ✅ | ✅ |
| VSCode | ✅ | ✅ | ✅ |
| Visual Studio | ⚠️ | ❌ | ❌ |
| 無 IDE（命令列） | ✅ | ✅ | ✅ |

---

## 安裝與建置

### 1. 複製專案

```bash
git clone https://github.com/ntut-open-source-club/PTSD-Practice-Giraffe-Adventure
cd PTSD-Practice-Giraffe-Adventure
```

### 2. 使用 CMake 建置

#### 命令列方式

```bash
# 產生建置檔案
cmake -B build

# 編譯專案
cmake --build build
```

> 💡 **提示**：若已安裝 Ninja Build，可使用以下命令加速編譯：
> ```bash
> cmake -B build -G Ninja
> cmake --build build
> ```

#### CLion

1. 以 CLion 開啟專案根目錄
2. CLion 會自動偵測 `CMakeLists.txt` 並完成設定
3. 點選 **Build > Build Project** 或按下 `Ctrl+F9` 進行編譯
4. 點選 **Run > Run 'GiraffeAdventure'** 或按下 `Shift+F10` 執行

#### VSCode

1. 安裝 **CMake Tools** 擴充套件
2. 以 VSCode 開啟專案根目錄
3. 按下 `Ctrl+Shift+P`，選擇 **CMake: Configure**
4. 按下 `Ctrl+Shift+P`，選擇 **CMake: Build**
5. 按下 `Ctrl+Shift+P`，選擇 **CMake: Run Without Debugging** 執行

#### Visual Studio

1. 以 Visual Studio 開啟專案根目錄（選擇「開啟本機資料夾」）
2. Visual Studio 會自動偵測 `CMakeLists.txt`
3. 選擇 **建置 > 全部建置** 進行編譯
4. 在方案總管中對 `GiraffeAdventure` 右鍵選擇 **設為啟動項目**，然後按下 `F5` 執行

### 3. 執行遊戲

建置完成後，執行檔位於 `build/` 目錄中（實際路徑依建置工具而異）：

```bash
# Windows (MSVC)
.\build\Debug\GiraffeAdventure.exe

# Windows (MinGW/Ninja)
.\build\GiraffeAdventure.exe

# macOS / Linux
./build/GiraffeAdventure
```

---

## 專案結構

```
PTSD-Practice-Giraffe-Adventure/
├── CMakeLists.txt              # CMake 建置設定檔
├── README.md                   # 本說明文件
├── LICENSE                     # MIT 授權條款
│
├── include/                    # 標頭檔（.hpp）
│   ├── App.hpp                 # 應用程式主類別（遊戲核心）
│   ├── AppUtil.hpp             # 工具函式（碰撞偵測輔助）
│   ├── Character.hpp           # 角色類別（靜態圖片角色）
│   ├── AnimatedCharacter.hpp   # 動畫角色類別（含動畫播放）
│   ├── BackgroundImage.hpp     # 背景圖片類別
│   ├── PhaseResourceManger.hpp # 關卡資源管理器
│   └── TaskText.hpp            # 任務提示文字類別
│
├── src/                        # 原始碼（.cpp）
│   ├── main.cpp                # 程式進入點
│   ├── AppStart.cpp            # 遊戲初始化邏輯
│   ├── AppUpdate.cpp           # 遊戲更新邏輯（✏️ 主要編輯區域）
│   ├── AppEnd.cpp              # 遊戲結束邏輯
│   ├── AppUtil.cpp             # 任務驗證邏輯（⚠️ 請勿修改）
│   ├── Character.cpp           # 角色類別實作
│   ├── AnimatedCharacter.cpp   # 動畫角色類別實作
│   └── PhaseManager.cpp        # 關卡資源管理器實作
│
├── Resources/                  # 遊戲資源
│   ├── Font/
│   │   └── Inkfree.ttf         # 顯示用字型
│   └── Image/
│       ├── Background/         # 各關卡背景圖片（phase0~6.png）
│       └── Character/          # 角色圖片
│           ├── giraffe.png     # 🦒 長頸鹿
│           ├── chest.png       # 📦 寶箱
│           ├── bee_1.png       # 🐝 蜜蜂 動畫幀 1
│           ├── bee_2.png       # 🐝 蜜蜂 動畫幀 2
│           ├── door_close.png  # 🚪 關閉的門
│           ├── door_open.png   # 🚪 開啟的門
│           ├── ball-1.png      # ⚽ 倒數球 幀 1
│           ├── ball-2.png      # ⚽ 倒數球 幀 2
│           ├── ball-3.png      # ⚽ 倒數球 幀 3
│           ├── ball-ok.png     # ✅ 倒數完成 OK
│           └── gray.png        # 灰色佔位圖
│
└── PTSD/                       # PTSD 框架（由 CMake 自動下載，已列入 .gitignore）
```

---

## 遊戲操作說明

| 按鍵 | 功能 |
|---|---|
| `↑` `↓` `←` `→` 或 `W` `A` `S` `D` | 移動角色（需自行實作） |
| `Enter` | 驗證當前關卡任務是否完成 |
| `ESC` | 退出遊戲 |

> ⚠️ **注意**：鍵盤移動功能需要你自行在 `AppUpdate.cpp` 中實作！

---

## 任務關卡說明

遊戲分為 6 個關卡，每個關卡有不同的任務目標。完成任務後按下 `Enter` 鍵驗證，通過後進入下一關。

### Phase 1：更換角色圖片 🖼️

**任務**：將 `m_Giraffe` 的圖片更換為 `Resources/Image/Character/giraffe.png`

**提示**：
- 查看 `Character` 類別中的 `SetImage()` 方法
- 在 `AppStart.cpp` 中檢查長頸鹿的初始化圖片路徑
- 驗證條件：`m_Giraffe->GetImagePath()` 需等於 `giraffe.png` 的完整資源路徑

---

### Phase 2：鍵盤控制移動 🎮

**任務**：讓長頸鹿能夠透過鍵盤移動至紅色區域內

**提示**：
- 在 `AppUpdate.cpp` 的 `TODO` 區域中撰寫鍵盤輸入與移動邏輯
- 使用 `Util::Input::IsKeyPressed(Util::Keycode::XXX)` 偵測按鍵
- 使用 `m_Giraffe->SetPosition()` 設定位置
- 紅色區域範圍：`x ∈ (50, 233)`、`y ∈ (-90, 93)`
- 驗證條件：長頸鹿的位置需落在紅色區域內

---

### Phase 3：碰撞偵測 💥

**任務**：當長頸鹿碰觸寶箱時，讓寶箱消失

**提示**：
- 在 `Character.hpp` 中實作 `IfCollides()` 方法（目前為 `TODO`，固定回傳 `false`）
- 當長頸鹿與寶箱碰撞時，呼叫 `m_Chest->SetVisible(false)` 隱藏寶箱
- 碰撞偵測需自行設計判定邏輯（例如：基於位置與圖片大小的矩形碰撞）
- 驗證條件：碰撞時寶箱為不可見狀態

---

### Phase 4：蜜蜂動畫 🐝

**任務**：為蜜蜂朋友加上動畫效果

**提示**：
- 查看 `AnimatedCharacter` 類別的方法
- 需要讓蜜蜂的動畫處於 **迴圈播放（Looping）** 且 **播放中（Playing）** 的狀態
- 使用 `SetLooping(true)` 開啟迴圈
- 動畫需要被啟動播放（`Play`）
- 驗證條件：`m_Bee->IsLooping() == true` 且 `m_Bee->IsPlaying() == true`

---

### Phase 5：開門機制 🚪

**任務**：當角色碰觸門時，將門打開

**提示**：
- 場景中有 3 扇門（`m_Doors` 向量）
- 需要偵測長頸鹿與每扇門的碰撞
- 碰撞時將門的圖片從 `door_close.png` 更換為 `door_open.png`
- 使用 `Character::SetImage()` 更換門的圖片
- 驗證條件：所有門的圖片路徑都為 `door_open.png`

---

### Phase 6：倒數計時 ⏳

**任務**：設計倒數計時程式，動畫結束後顯示 OK 並停止

**提示**：
- 在 `AppStart.cpp` 中初始化倒數球（參考 `TODO` 註解）
- 使用 `ball-1.png`、`ball-2.png`、`ball-3.png`、`ball-ok.png` 製作動畫
- 建立 `AnimatedCharacter` 物件作為倒數球 `m_Ball`
- 動畫播放完畢後需停止（非循環播放）
- 驗證條件：`m_Ball->IfAnimationEnds()` 回傳 `true`

---

## 核心類別說明

### `App`
遊戲主類別，管理遊戲生命週期（`Start` → `Update` → `End`）及關卡狀態切換。

### `Character`
靜態圖片角色類別，繼承自 `Util::GameObject`。
- `SetImage(path)` — 設定角色圖片
- `SetPosition(vec2)` — 設定角色位置
- `GetPosition()` — 取得角色位置
- `SetVisible(bool)` — 設定可見性
- `IfCollides(other)` — 碰撞偵測（**需自行實作**）

### `AnimatedCharacter`
動畫角色類別，繼承自 `Util::GameObject`。
- `SetLooping(bool)` — 設定是否迴圈播放
- `IsLooping()` — 查詢是否迴圈播放
- `IsPlaying()` — 查詢是否正在播放
- `IfAnimationEnds()` — 查詢動畫是否已播放完畢

### `PhaseResourceManger`
關卡資源管理器，負責切換背景圖片和任務提示文字。

### `TaskText`
顯示當前關卡的任務描述和驗證提示文字。

### `BackgroundImage`
根據當前關卡載入對應的背景圖片。

---

## 開發提示

1. **從 `TODO` 開始**：在程式碼中搜尋 `TODO` 關鍵字，找到需要你完成的部分
2. **主要編輯檔案**：
   - `src/AppUpdate.cpp` — 在此撰寫遊戲邏輯（鍵盤控制等）
   - `include/Character.hpp` — 在此實作碰撞偵測
   - `src/AppStart.cpp` — 在此初始化倒數球
3. **請勿修改的檔案**：
   - `src/AppUtil.cpp` — 任務驗證邏輯
   - `include/AppUtil.hpp` — 工具函式
4. **常用的 PTSD 框架 API**：
   - `Util::Input::IsKeyPressed(Util::Keycode::XXX)` — 偵測按鍵是否被按下
   - `Util::Input::IsKeyUp(Util::Keycode::XXX)` — 偵測按鍵是否放開
   - 按鍵常量：`Util::Keycode::UP`、`DOWN`、`LEFT`、`RIGHT`、`W`、`A`、`S`、`D` 等
5. **Debug Log**：使用 `LOG_DEBUG("message")` 輸出除錯訊息

---

## 授權條款

本專案採用 [MIT License](LICENSE) 授權。

Copyright © 2024 NTUT Open-Source Club
