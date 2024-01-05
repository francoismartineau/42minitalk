#!/bin/bash

if [[ -z "$1" ]]; then
    echo "Execute the server and pass its PID as argument."
	exit
fi

for ((i = 0; i < 10; i++)); do
./client $1 "$(cat tester/lorem_ipsum.txt)"

./client $1 "
⁣☀       ☁
   ☁
            ☁


          🐬
🌊🌊⛵🌊🌊🌊🌊⁣🌊
    ｜
    ｜
    ｜ 🐠
    ｜     🐟
 🐳 ｜     
    ⚓
" &&

./client $1 "
⁣     🚿￣＼
     😓   ｜
    ⁣/|\💧 ｜
| 💧/ \   |
￣￣￣￣￣￣" &&

./client $1 "
⁣🍐🍌🍋🍋🍊🍊🍎🍎🍎
🍐🍏🍌🍋🍋🍊🍊🍎🍎
🍆🍐🍐🍌🍋🍋🍊🍊🍎
🍇🍇🍏      🍋🍊🍊
🍎🍆🍇  ⁣😎  🍋🍋🍊
🍒🍓🍇      🍌🍋🍋
🍊🍎🍉🍇🍆🍐🍐🍌🍋
🍊🍊🍓🍎🍇🍇🍏🍐🍌
🍋🍊🍊🍎🍓🍇🍇🍐🍏" 
done
