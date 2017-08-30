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
