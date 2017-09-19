# Trump Game

CLIでできるポーカーを作る

## Rule

[任天堂・ポーカーの遊び方](https://www.nintendo.co.jp/n09/trump_games/poker/)

## Command List

- root
  - exit: ゲームを終了させる
  - help: ヘルプメッセージを表示させる
  - show deck: デッキの順番を表示する
  - show [num]: プレイヤーの手札を表示する(未実装)
  - player [id]: プレイヤーにログインする(未実装)
- player
  - change [num] ... : 手札から指定のカードを捨てて、捨てた枚数ドローする。

## ToDo

### Handは列挙型ではなくclassでやるべき

- 同じ強さの時の優劣が必要
- coutで出力できた方が楽
ハートの8のノーペア等

### 役の判断アルゴリズム
```
func check()[
    isRoyelStra
    isFour
]
```
役ごとに判断関数を作成して、
強い順に比較して最後に得られたHandで確定

役の判断関数の返り値はHandのポインタ、役でないときはnullptrを返す。
